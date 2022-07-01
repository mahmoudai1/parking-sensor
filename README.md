# Parking Sensor
Simulation to the parking sensors developed by C on Arduino UNO R3 ATMEGA328P.

## Components Used
• UNO R3 ATMEGA328P<br/>
• HC-SR04 Ultrasonic Sensor<br/>
• 4 Digital Tube<br/>
• Passive Buzzer<br/>

## Discussions
• For the Digital Tube, there are 10 pins used.

• For the Ultrasonic Sensor, two pins are used (Echo and Trig), with one GND and one 5V.

• For the Buzzer, only one pin and one GND are used.

• To calculate the distance from the ultrasonic sensor, the duration must be calculated first.

• Duration can be calculated by the following function: pulseIn(echoPin, HIGH).

• Distance is then calculated by the following equation: duration * 0.034 / 2.

• There are 5 conditions with different type of buzzer tones delay.

• The distance intervals are, [5, 10, 25, 50, else].

• To let the buzzer make sound, tone() function is used with the buzzer pin and the frequency in kHz as its parameters. noTone() is to stop the sound.

• To display something on the Digital Tube, a manually implemented functions called pre_print() and print() are called.

• pre_print() count the number of digits and iterate on each digit and pass it to print() to display it.

• Only 2 blocks of the 4 digital tube are used.

• Printing fluctuations are handled by avoid updating the digitalDistance every second. But for the buzzer, it has a separated distance variable that updating every second, to give the alert in the right time.
