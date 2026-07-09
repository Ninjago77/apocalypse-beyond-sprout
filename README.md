# Apocalypse Beyond - SPROUT

A plant/bamboo caregiver with a custom oc on a display & numerous temperature sensors to make caring for your greenery easier!

## Gallery

<img width="300" alt="20260706_140346" src="https://github.com/user-attachments/assets/957d34e4-bc98-4a0e-8219-e29f1e0a0a96" />
<img width="300" alt="20260709_095628" src="https://github.com/user-attachments/assets/ba22d533-0135-485f-beab-718ac0a99ac7" />
<img width="300" alt="20260709_095631" src="https://github.com/user-attachments/assets/d97eec81-8cd6-4e0f-89e7-52885d1e1a7a" />
<img width="300" alt="20260709_095634" src="https://github.com/user-attachments/assets/3696fda6-019b-40d1-a22f-c2fb77716c76" />
<img width="300" alt="20260709_095640" src="https://github.com/user-attachments/assets/a0ff1ba7-10f9-441a-854e-b24b00d7122e" />
<img width="300" alt="20260709_095700" src="https://github.com/user-attachments/assets/c617be11-af0c-4193-ad91-8978f6b6d05c" />
<img width="300" alt="20260709_095718" src="https://github.com/user-attachments/assets/504757ef-403b-49f3-8bc3-10df240c5f68" />
<img width="300" alt="20260709_095743" src="https://github.com/user-attachments/assets/8cb6c77a-2271-4e48-aec9-4f16676887e4" />
<img width="300" alt="20260709_095747" src="https://github.com/user-attachments/assets/8b94655e-58c5-489a-826f-8372fd6aba13" />
<img width="300" alt="20260709_101420" src="https://github.com/user-attachments/assets/00aacd41-db0e-4ab6-bd7f-1a6a4a2bef80" />
<img width="300" alt="20260709_101424" src="https://github.com/user-attachments/assets/25317f73-7dea-495f-a689-8ba37a017993" />
<img width="300" alt="20260709_101431" src="https://github.com/user-attachments/assets/7a77eac6-2644-45b1-9176-5925560fea9a" />
<img width="300" alt="20260709_101439" src="https://github.com/user-attachments/assets/6f16a3b6-038a-4e4a-97d4-db978815341a" />
<img width="300" alt="20260709_101442" src="https://github.com/user-attachments/assets/35a020f0-f5b9-45a4-9182-06898f79ecc6" />
<img width="300" alt="20260709_101445" src="https://github.com/user-attachments/assets/b573ab68-9dc9-42c6-8440-1bdb117e42b7" />
<img width="300" alt="20260709_101458" src="https://github.com/user-attachments/assets/9eb48d2b-db32-41b8-b24c-034275c30f22" />
<img width="300" alt="20260709_101506" src="https://github.com/user-attachments/assets/c4c197bc-32c1-4735-816b-7b44942745f5" />

## Why?

Have you ever killed a plant by not caring for it properly?
Well, this little caretaker will give you all the info you need to take good care of your plant/bamboo!

## What?

It can identify whether your plant is ideally cared for, too dry, too cold, too wet or too hot using temperature & humidity sensors. It also has an OC indicating each of the different states your plant could be in, along with raw information from the sensors.

## List of Materials

| Component Name | Quantity | Required | Additional Notes |
| --- | --- | --- | --- |
| Raspberry Pi Pico | 1x | Yes | Main microcontroller unit for handling sensors and display. |
| Pushbutton | 2x | No (If you don't want input) | Configured as UP (GP17) and DOWN (GP15) navigation buttons, or to trigger sleep. |
| AMT1001 Temp & Humidity Sensor | 1x | No (but at least 1 Temp & 1 Humidity Sensor) | Only utilized for ambient humidity tracking outside the plant carer environment. |
| DHT11 Sensor | 1x | No (but at least 1 Temp & 1 Humidity Sensor) | Installed inside the plant carer enclosure, positioned safely above the water level. |
| Generic Thermistor | 1x | No (but atleast 1 Temp Sensor) | Submerged inside the water reservoir to track liquid temperature. |
| ST7735 1.8" RGB TFT Display | 1x | Yes | 128*160 resolution screen used for the user interface and data readouts. |
| NeoPixels | 4x | No | Addressable LED strip/array connected to GP23 for status indicators or lighting. |
| 10K Ohms Resistor | 2x | Yes | 1x used as a pull-up to 3V3 for the AMT1001, 1x used as a pull-down to GND for the thermistor. |
| Glass Bottle | 1x | Yes | Any bottle big enough should be fine, so long as the supports attach to it (You can modify the supports!) |

## AI Usage
AI used for Research into sensors & fusion troubles, as well as bitmap loading code.


