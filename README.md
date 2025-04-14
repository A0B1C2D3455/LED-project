# 💡 Pattern Logic
The bar graph has 8 LEDs (LED0 to LED7), each connected to a GPIO pin on the ESP32.
Two patterns are alternated in a loop:

Pattern 1: 0b01010101

LEDs ON: 0, 2, 4, 6 (Even positions)

LEDs OFF: 1, 3, 5, 7

Pattern 2: 0b10101010

LEDs ON: 1, 3, 5, 7 (Odd positions)

LEDs OFF: 0, 2, 4, 6

These patterns toggle every 500 milliseconds and continues indefinitely.

# DEMO VIDEO
https://github.com/user-attachments/assets/0d55e947-5298-47b4-8547-6bb0d0d5560b



