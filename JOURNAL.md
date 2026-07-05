# MD Journal 
## June 2nd 2026 ~ 2 hours
I came up with the idea, when I was staring at a glass bottle on my desk & thinking about the Apocalypse hackathon in Toronto. So I did a little digging through my electronics to see whether I had sensors for anything related to plant growth, & I did.
<img width="1200" height="1600" alt="WhatsApp Image 2026-07-03 at 22 15 47 (2)" src="https://github.com/user-attachments/assets/960668b9-0c55-46cf-a36b-886d647ef017" />

So heres my idea, an A-tier project, about a plant monitoring system (because that's important during a Zombie Apocalypse), but why would that be A-tier with just a few sensors? Well, because there'll be a display with an animated plant character linked to the sensors themeselves!

## June 3rd 2026 Morning - 3 hours
I have a working display (st7735s) that I can use for this, along with a bunch of different types of sensors (later). This will be the main fragile part of the entire project:-
<img width="1200" height="1600" alt="WhatsApp Image 2026-07-03 at 22 15 47 (3)" src="https://github.com/user-attachments/assets/dc379643-23e1-4cc3-a842-1a557ee9a0e4" />

Next are the temperature & humidity sensors:-
<img width="1200" height="1600" alt="WhatsApp Image 2026-07-03 at 22 15 47 (1)" src="https://github.com/user-attachments/assets/695a5472-c928-4a6e-8a2b-2d333aad2a06" />
<img width="1200" height="1600" alt="WhatsApp Image 2026-07-03 at 22 15 47" src="https://github.com/user-attachments/assets/f309cd75-c563-409c-8877-12118979d471" />
<img width="1500" height="2000" alt="WhatsApp Image 2026-07-03 at 22 15 47 (4)" src="https://github.com/user-attachments/assets/a707ae76-fe09-441d-8a04-44affc4bdbcf" />
 - **AMT1001** (the black one) - is a very precise temp & humidity sensor, but its a little big, so I'll be using it for the outer environment
 - **DHT11** (the blue one) - is a cheap temp & humidity sensor, plus I have multiple of them, so I'll be using it inside the glass, so I can swap it if one gets fried.
 - **Thermistor** (the silver rod) - is a waterproof temperature sensor (if i use a voltage divider), so I'll dip it all the way into the water (bamboo) or soil (plants).

## June 3rd 2026 Evening - 2 hours
I have prepared a plan for the project. The circuitry will be composed of a pico & perfboards to keep things organized. I also cut and sanded an old half perfboard to get this arangement:-
 - <img width="1236" height="1648" alt="20260704_135828" src="https://github.com/user-attachments/assets/478723d1-c42a-4159-b7af-c58126139f55" />
 - <img width="1242" height="1656" alt="20260704_135836" src="https://github.com/user-attachments/assets/07206360-e5b0-45c4-aee3-e5253a637de0" />

 I also bent this header pin to make the display cold-swappable as its pretty fragile, and is prone to breaking:-
 - <img width="1618" height="2158" alt="20260704_140108" src="https://github.com/user-attachments/assets/742693af-dad7-4b18-b593-9d130a6697ae" />

## June 5th 2026 Morning
Now, that I have a plan in place, I need to get on Fusion & start working, so that's what I did, I modeled the bottle:-
  - <img width="637" height="763" alt="image" src="https://github.com/user-attachments/assets/0044899a-ff9e-478b-95c1-238e88350482" />
And made it an actual bottle:
 - <img width="736" height="857" alt="image" src="https://github.com/user-attachments/assets/4698d2cd-a471-486c-b708-fd8f06b00e1c" />
I don't have a 3d model for the perfboards, so I took a breadboard one I found:-
 - <img width="1022" height="854" alt="image" src="https://github.com/user-attachments/assets/cd47b58b-180d-4273-8f51-1ef7cd2ab48e" />
& made it into a perfboard shape:
 - <img width="1417" height="872" alt="image" src="https://github.com/user-attachments/assets/e66be393-8871-4707-8d59-25800ab79ccd" />

I also need to make a removable clip to attach the circuitry and sensors to the bottle & remove them when needed, so I made a test bottle bracket (slightly oval to allow for clipping):
 - <img width="931" height="695" alt="image" src="https://github.com/user-attachments/assets/8991ab4e-e514-43bd-8a47-949643d0faca" />
 
I'm also 3d printing this right away, so that I have a working (or theoretically) working clip.



