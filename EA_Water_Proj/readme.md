# Progress

## Iteration 1: January 2019
The first iteration was not documented. We first split the tasks into 3 parts,
- motor movement & shooting
- PS2 controller
- decorations

### Bridge of iteration:
We found out what library the board uses. The board was a clone of a normal wireless PS2 shield and an Adafruit Motor shield V2. We tested the PS2x.lib and the Adafruit Motor SHield V2 with satisfying results.
links to the libraries (here)[] and (here)[].

## Iteration 2: 12th February 2019
We compiled the LED code, music code, the PS2 controller code and the motor pump code here. The working video is linked (here) []

Below we also attach the image for a working prototype for the boat on the water.

<video width = "400" controls>
  <source src = "prototype_no_load.mp4"/>
</video>

<video width = "400" controls>
  <source src = "prototype_test.mp4"/>
</video>

Video courtesy of Bryan's phone and Daichi's voiceover

# Final iteration: 13th February 2019
Alas, the high load of the bilge pumps may have damage the H-bridges. (see here for details)[https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/overview]
We suspect that the limiter for the input of the H-bridges have worn out electronically (suspicion). At any rate, we decided to change to an L298N.
Although the L298N can only provide up to 2A (unachievable high discussed here)[https://www.rugged-circuits.com/the-motor-driver-myth/], it was the only backup solution we had.
the code we uploaded is the final version of the working boat (no load).
