//------------------------------------------------------------------------------------------
// TEA-LICIOUS
// A Project for MakeHarvard 2018
// Copyright 2018 by Madeleine Haworth and Maura Hennessey

//------------------------------------------------------------------------------------------

// Example codes used:
/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
// Arduino tutorials: Blink and Button


//------------------------------------------------------------------------------------------

#include <Servo.h>

// buttons
const int button1 = 8;
const int button2 =  2;
const int button3 = 3;
const int button4 = 4;
const int button5 = 5;
const int button6 = 6;
const int onoff = 7;

const int red = 10;
const int yellow = 11;
const int green = 12;

const int servoRotation = 130;
const int done = 5000;

// TEA TIMES
const int timeBlack = 450; // 45 sec
const int timeGreen = 6000; // 6 min
const int timeOolong = 4000; // 4 min
const int timeRooibos = 1000; // 1 min
const int timePuerh = 1000; // 1 min
const int timeHerbal = 300; // 30 sec
const int nBlack = 5;
const int nGreen = 3;
const int nOolong = 3;
const int nRooibos = 5;
const int nPuerh = 4;
const int nHerbal = 5;
const int minute = 1000; // 1 minute

// button states
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int onoffState = 0;

// variable to control on or off state
int machine = 0;

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() { //------------------------------------------------------------------------------
  // attach the servo on pin 9 to the servo object
  myservo.attach(9);
  myservo.write(servoRotation);
  // initialize buttons as input:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(onoff, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  
  // set up serial communication
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial.println("Connected!");
  
  // check if the on-off button is pressed. If it is, the buttonState is HIGH.
  onoffState = digitalRead(onoff);
  //Serial.println("On/Off Button: ");
  //Serial.print(onoffState);

  while(onoffState == LOW){
    // do nothing
    onoffState = digitalRead(onoff);
    //Serial.println(onoffState);
    delay(10);
  }
  // will loop until the button is pressed, which will then move the code to below:
  
  // turn machine on
  machine = 1;
  Serial.println("Hello! Welcome to Tealicious!");
  // LEDs YELLOW
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW); 
  
}

void loop() { //----------------------------------------------------------------------------------
  while (machine == 1) {
    delay(500);
    
    buttonState1 = digitalRead(button1);
    buttonState2 = digitalRead(button2);
    buttonState3 = digitalRead(button3);
    buttonState4 = digitalRead(button4);
    buttonState5 = digitalRead(button5);
    buttonState6 = digitalRead(button6);
    onoffState = digitalRead(onoff);
 
    Serial.println("Please insert your cup, attach tea bag, and select type of tea. ");
    // LEDs GREEN
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);

    while(buttonState1 == LOW and buttonState2 == LOW and buttonState3 == LOW and buttonState4 == LOW and buttonState5 == LOW and buttonState6 == LOW and onoffState == LOW) {
      // keep reading
      buttonState1 = digitalRead(button1);
      buttonState2 = digitalRead(button2);
      buttonState3 = digitalRead(button3);
      buttonState4 = digitalRead(button4);
      buttonState5 = digitalRead(button5);
      buttonState6 = digitalRead(button6);
      onoffState = digitalRead(onoff);
    }

    if (onoffState == HIGH) {
      // person decides not to make tea, wants to turn machine off
      // LEDs OFF
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      machine = 0;
      delay(1000);
    }
    
    else if (buttonState1 == HIGH) {
      // black tea
      // LEDs RED------
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      // brew------
      Serial.println("Now brewing black tea...");
      // wait to reach temp
      delay(timeBlack);

      // dunk n times 
      for (int i=0; i < nBlack; i++){
        dunk();
        delay(minute);
        undunk();
      }
      // LEDs GREEN------
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      machine = 0;
      delay(done);
    }
  
    else if (buttonState2 == HIGH) {
      // green tea
      // LEDs RED------
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      // brew------
      Serial.println("Now brewing green tea...");
      // wait to reach temp
      delay(timeGreen);

      // dunk n times 
      for (int i=0; i < nGreen; i++){
        dunk();
        delay(minute);
        undunk();
      }
      // LEDs GREEN------
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      machine = 0;
      delay(done);
    }
  
    else if (buttonState3 == HIGH) {
      // oolong tea
      // LEDs RED------
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      // brew------
      Serial.println("Now brewing oolong tea...");
      
      // wait to reach temp
      delay(timeOolong);

      // dunk n times 
      for (int i=0; i < nOolong; i++){
        dunk();
        delay(minute);
        undunk();
      }
           
      // LEDs GREEN------
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      machine = 0;
      // delay(done);
    }
  
    else if (buttonState4 == HIGH) {
      // rooibos tea
      // LEDs RED------
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      // brew------
      Serial.println("Now brewing rooibos tea...");
      // wait to reach temp
      delay(timeRooibos);

      // dunk n times 
      for (int i=0; i < nRooibos; i++){
        dunk();
        delay(minute);
        undunk();
      }
      // LEDs GREEN------
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      machine = 0;
      delay(done);
    }
  
    else if (buttonState5 == HIGH) {
      // pu'erh tea
      // LEDs RED------
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      // brew------
      Serial.println("Now brewing pu'erh tea...");
      // wait to reach temp
      delay(timePuerh);

      // dunk n times 
      for (int i=0; i < nPuerh; i++){
        dunk();
        delay(minute);
        undunk();
      }
      // LEDs GREEN------
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      machine = 0;
      delay(done);
    }
  
    else if (buttonState6 == HIGH) {
      // herbal tea
      // LEDs RED------
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      // brew------
      Serial.println("Now brewing herbal tea...");
      // wait to reach temp
      delay(timeHerbal);

      // dunk n times 
      for (int i=0; i < nHerbal; i++){
        dunk();
        delay(minute);
        undunk();
      }
      // LEDs GREEN------
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      machine = 0;
      delay(done);
    }
    
  } // end of while loop

  Serial.println("Thank you for using Tealicious! Goodbye!");
  Serial.println("~~~");
  // LEDs OFF
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);

  // check if the on-off button is pressed. If it is, the buttonState is HIGH.
  onoffState = digitalRead(onoff);
  //Serial.println("On/Off Button: ");
  //Serial.print(onoffState);

  while(onoffState == LOW){
    // do nothing
    onoffState = digitalRead(onoff);//
  }
  // will loop until the button is pressed, which will then move the code to below:
  
  // turn machine on
  machine = 1;
  Serial.println("Hello again! Welcome to Tealicious!");
  // LEDs YELLOW
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW); 

  
} // end of loop

void undunk() { //-----------------------------------------------------------------------------------
  for (pos = 0; pos <= servoRotation; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void dunk() { //----------------------------------------------------------------------------------
  for (pos = servoRotation; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

