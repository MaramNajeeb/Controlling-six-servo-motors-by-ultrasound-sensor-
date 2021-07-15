# Controlling-six-servo-motors-by-ultrasonic-sensor

The object of this task is to design a circuit that has six servo motors controlled by a bluetooth module. The motors are required to start moving when the person stands in front of  the screen for 3 seconds from about 0.5m distance ( in this code I used 20cm to be suitable). Ultrasonic sensor is used to notice the standing person. Once these two conditions are achieved, distance of 20cm and time taken is 3 sec, a signal should be sent by the bluetooth module to the motors. Since the bluetooth module is not available in Tinkercad, I used an LCD to display the distance and greet the customer. 

![COPY of Controlling 6 Servo motors using Ultrasonic sensor]( https://user-images.githubusercontent.com/85887579/125855114-cc8b58c4-595e-4187-98d1-8d3c635df9c9.png)


The code starts by including "servo" and "LCD" libraries. Then the trigpin and echopin of ultrasonic sensors when defined. The motors objects were created. Then the pins of lcd and motors were specified. In the void loop section, two cases were creating, the first when the distance is >20, no action will be done. The second case when the distance is <= 20 where the time of standing in front of the sensor will be checked first and then the motors will start moving. 

Following that, the function (discalc ) was created to calculate the distance by US sensor which operates by sending a sound wave to the object and receiving the coming signal. The sound wave travel will be calculated by using the simple law of speed=distance/time. The speed here is the speed of sound which is 343m/s or 0.034 cm/µs. 
Because the sound waves need to travel forward and bounce backward, we get the distance in cm by multiplyng the received travel time value from the echo pin by 0.034 and divide it by 2.

Tinkercad link: https://www.tinkercad.com/things/3i0YFBkUD8U-copy-of-controlling-6-servo-motors-using-ultrasonic-sensor/editel
