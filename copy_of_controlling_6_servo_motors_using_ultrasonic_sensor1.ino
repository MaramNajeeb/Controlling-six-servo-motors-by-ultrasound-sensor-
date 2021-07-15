#include <LiquidCrystal.h>
#include <Servo.h>


//define ultrasonic sensor pins
#define TrigPin 8 
#define EchoPin 9 


//define variables
int duration;
int distance;

//creat six servo motor objects
Servo moto1;
Servo moto2;
Servo moto3;
Servo moto4;
Servo moto5;
Servo moto6;

//define LCD pins
LiquidCrystal lcd(12, 11 ,5 ,4 ,3 ,2);


void setup()
{
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(9600);
  
  //servo motors pins
  moto1.attach(14);
  moto2.attach(15);
  moto3.attach(6);
  moto4.attach(7);
  moto5.attach(10);
  moto6.attach(13);
  
   lcd.begin(16, 2);
  
    moto1.write(0); //initial position at zero
    moto2.write(0);
    moto3.write(0);
    moto4.write(0);
    moto5.write(0);
    moto6.write(0);  

 
}

void loop()
{
  // display the distance on LCD
  
  lcd.setCursor(0,0);
  lcd.print("distance is ");
  lcd.print(discalc());
  
  
  while(discalc()> 20) {} //if distance is >20cm, do nothing
 int startTime=millis(); //count time when the program starts 
  
  while(discalc() <= 20){ // if the dis is <=20 cm, move the motors by 90 deg
    int currentTime=millis(); //count time when <=20 is achieved
    if(currentTime-startTime >3000) //if time taken in front of ultrasonic is 3 sec, move the motors
    {
    moto1.write(90);
    moto2.write(90);
    moto3.write(90);
    moto4.write(90);
    moto5.write(90);
    moto6.write(90); 
    lcd.setCursor(0,1);
    lcd.print(" Hello Customor ");
      break;
    }
   
  }
 /* else if(discalc() > 20) // if the dis is >20 cm, move the motors by 180 deg
  {
    moto1.write(180);
    moto2.write(180);
    moto3.write(180);
    moto4.write(180);
    moto5.write(180);
    moto6.write(180); 
    delay(1000);
    lcd.setCursor(2,1);
    lcd.print(" Welcome ");
  }
 else {
    moto1.write(0);
    moto2.write(0);
    moto3.write(0);
    moto4.write(0);
    moto5.write(0);
    moto6.write(0);
    lcd.setCursor(2,1);
    lcd.print(" ______ ");
  }*/
  
  
  
} //End of void loop

  
//creating a function to calculate the distance
int discalc(){
  
    digitalWrite(TrigPin,LOW); //trig pin is initally off
    delayMicroseconds(2);
    digitalWrite(TrigPin,HIGH); //trig pin in on for 10 ms
    delayMicroseconds(10);
    digitalWrite(TrigPin,LOW); //trig pin is again off
    
     // Read the echo pin, and returns the sound wave travel time
    duration=pulseIn(EchoPin,HIGH); 
    distance=duration*0.034/2; //multiply time by sound speed divided by 2(two paths)
    return distance;
  }    