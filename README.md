# 74HC595 (16 LEDS)

This project was developed around 2020 during Technical Education (integrated with High School) as part of an evaluation. It uses the 74HC595 IC to control 16 LEDs through a serial-to-parallel shift register. The project implements various lighting effects on the LEDs, based on a control sequence sent to the IC.

## Components Used

- Arduino (or compatible microcontroller)
- IC 74HC595 (shift register)
- 16 LEDs - Resistors to limit the LED current
- Breadboard and jumpers for connections

## Connections

The Arduino pins are connected to the 74HC595 as follows:

- `clockPin` (pin 10): Controls the clock signal.
- `latchPin` (pin 9): Controls the latch (data latch) of the 74HC595.
- `dataPin` (pin 8): Sends the output data for the LEDs.

The LEDs are connected to the outputs of the 74HC595.

## Code

The Arduino code is responsible for controlling the LED lighting sequence. It uses a Boolean array to represent the state of each LED (on or off) and implements 16 different lighting effects, described below:

### Implemented Effects

1. **Effect 1**: Lights up one LED at a time from left to right.
2. **Effect 2**: Lights up one LED at a time from right to left.
3.  **Effect 3**: Lights up all LEDs sequentially from left to right.
4.  **Effect 4**: Lights up all LEDs sequentially from right to left.
5.  **Effect 5**: Combination of effects 1 and 4.
6.  **Effect 6**: Combination of effects 2 and 3.
7.  **Effect 7**: Lights up the LEDs from the outside to the inside.
8.  **Effect 8**: Lights up the LEDs from the inside to the outside.
9.  **Effect 9**: Inverse version of effect 5.
10. **Effect 10**: Inverse version of effect 6.
11. **Effect 11**: Lights up a random LED.
12. **Effect 12**: Lights up two random LEDs.
13. **Effect 13**: Lights up even and odd LEDs alternately.
14. **Effect 14**: Lights up LEDs in groups of 4.
15. **Effect 15**: LEDs go back and forth until the sequence is complete.
16. **Effect 16**: Sequence in alternating pairs.

## Functions

- `setup()`: Configures the Arduino pins as output and initializes the system.
- `update()`: Sends the current state of the LEDs to the IC 74HC595.
- `clear()`: Turns off all LEDs.
- `loop()`: Continuously executes all effects in sequence.

## How to Use

1. Connect the components according to the connection diagram.
2. Upload the code to Arduino.
3. The LEDs will begin to perform the effects sequentially.

## Future Improvements

- Add more lighting effects.
- Implement control via buttons to select different effects.

## License

This project was developed for educational purposes and can be freely modified and distributed.
