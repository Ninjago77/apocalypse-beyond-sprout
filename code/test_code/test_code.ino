#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_NeoPixel.h>
#include <DHT.h>
#include <math.h>

// --- Pin Definitions ---
// TFT Display (ST7735)
#define TFT_SCLK  6  // Software SPI SCK
#define TFT_MOSI  7  // Software SPI TX/MOSI
#define TFT_RST   8  
#define TFT_DC    9  
#define TFT_CS    10 
#define TFT_BLK   11 

// NeoPixels
#define NEO_PIN   23 
#define NUM_PIXELS 4 

// Sensors
#define DHTPIN       14 // DHT11 Data Pin
#define DHTTYPE      DHT11 
#define PIN_THERM    26 // ADC0 - Generic Thermistor
#define PIN_AMT_TEMP 27 // ADC1 - AMT1001 White Wire
#define PIN_AMT_HUM  28 // ADC2 - AMT1001 Yellow Wire

// Initialize objects
Adafruit_NeoPixel pixels(NUM_PIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
DHT dht(DHTPIN, DHTTYPE);

// Variables
uint16_t currentHue = 0; 
unsigned long lastSensorRead = 0;

// Store sensor readings
float dhtTemp = 0, dhtHum = 0;
float amtTemp = 0, amtHum = 0;
float thermTemp = 0;

void setup() {
  Serial.begin(115200);

  // Set the Pico's ADC resolution to 12-bit (0-4095) for better accuracy
  analogReadResolution(12);

  // 1. Setup NeoPixels
  pixels.begin();
  pixels.setBrightness(50);
  pixels.show();

  // 2. Setup TFT Backlight
  pinMode(TFT_BLK, OUTPUT);
  digitalWrite(TFT_BLK, HIGH); 

  // 3. Initialize TFT Display
  tft.initR(INITR_BLACKTAB); 
  tft.setRotation(1); // Landscape mode
  tft.fillScreen(ST77XX_BLACK);

  // 4. Initialize DHT11
  dht.begin();
}

void loop() {
  // Read sensors every 2 seconds (The DHT11 is slow and requires 2s between reads)
  if (millis() - lastSensorRead >= 2000 || lastSensorRead == 0) {
    lastSensorRead = millis();

    // --- 1. Read DHT11 ---
    dhtTemp = dht.readTemperature();
    dhtHum = dht.readHumidity();

    // --- 2. Read Generic Thermistor (ADC0) ---
    // Wired: 3V3 -> NTC -> [ADC0] -> 10k -> GND
    float val0 = analogRead(PIN_THERM);
    if (val0 > 0 && val0 < 4095) {
      float rNtc0 = 10000.0 * (4095.0 / val0 - 1.0);
      // Steinhart-Hart calculation (Using standard B-value of 3950)
      thermTemp = (1.0 / (1.0 / 298.15 + (1.0 / 3950.0) * log(rNtc0 / 10000.0))) - 273.15;
    } else {
      thermTemp = NAN; // Error reading
    }

    // --- 3. Read AMT1001 Temperature (ADC1) ---
    float val1 = analogRead(PIN_AMT_TEMP);
    if (val1 > 10 && val1 < 4085) { 
      float rNtc1 = 10000.0 * val1 / (4095.0 - val1);
      amtTemp = (1.0 / (1.0 / 298.15 + (1.0 / 3435.0) * log(rNtc1 / 10000.0))) - 273.15;
    } else {
      // Instead of NAN, output the raw ADC value so we can see what the pin is doing!
      // If it says 4095 C on screen, the pin is stuck at 3.3V.
      // If it says 0 C on screen, the pin is shorted to Ground.
      amtTemp = val1; 
    }
    // --- 4. Read AMT1001 Humidity (ADC2) ---
    // AMT1001 outputs 0V to 3.0V linearly for 0% to 100% Humidity
    float val2 = analogRead(PIN_AMT_HUM);
    float vAdc2 = (val2 / 4095.0) * 3.3; // Convert digital 12-bit value back to voltage
    amtHum = vAdc2 / 0.03; // Datasheet formula: Humidity = Voltage / 0.03
  }

  // --- GENERATE RAINBOW COLORS ---
  uint32_t rgb32 = pixels.ColorHSV(currentHue, 255, 255);
  uint8_t r = (rgb32 >> 16) & 0xFF;
  uint8_t g = (rgb32 >>  8) & 0xFF;
  uint8_t b = rgb32 & 0xFF;

  // 1. UPDATE NEOPIXELS
  for(int i = 0; i < NUM_PIXELS; i++) {
    pixels.setPixelColor(i, rgb32);
  }
  pixels.show();

  // 2. UPDATE TFT DISPLAY
  uint16_t tftColor = tft.color565(r, g, b);
  tft.fillScreen(tftColor);

  uint16_t invColor = ~tftColor;
  // Passing the background color alongside the foreground prevents the text from tearing/flashing
  tft.setTextColor(invColor, tftColor); 
  tft.setTextSize(1);
  
  // Layout Variables (helps space the text cleanly)
  int y = 5;       // Starting Y position
  int dy = 15;     // Spacing between lines
  int dyGap = 5;   // Extra spacing between sensor sections
  
  tft.setCursor(5, y); tft.print("== DHT11 =="); y += dy;
  tft.setCursor(5, y); tft.print("Temp: "); tft.print(dhtTemp); tft.print(" C"); y += dy;
  tft.setCursor(5, y); tft.print("Hum : "); tft.print(dhtHum); tft.print(" %"); y += dy + dyGap;

  tft.setCursor(5, y); tft.print("== AMT1001 =="); y += dy;
  tft.setCursor(5, y); tft.print("Temp: "); tft.print(amtTemp); tft.print(" C"); y += dy;
  tft.setCursor(5, y); tft.print("Hum : "); tft.print(amtHum); tft.print(" %"); y += dy + dyGap;

  tft.setCursor(5, y); tft.print("== THERMISTOR =="); y += dy;
  tft.setCursor(5, y); tft.print("Temp: "); tft.print(thermTemp); tft.print(" C");

  // Increment hue to push the rainbow forward
  currentHue += 750; 
  delay(10);
}