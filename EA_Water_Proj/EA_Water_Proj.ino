#include <PS2X_lib.h>  //for v1.6
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "Servo.h"

PS2X ps2x; // create PS2 Controller Class

//right now, the library does NOT support hot pluggable controllers, meaning
//you must always either restart your Arduino after you conect the controller,
//or call config_gamepad(pins) again after connecting the controller.
int error = 0;
byte type = 0;
byte vibrate = 0;

// Create the motor shield object with the default I2C address
//Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
//Adafruit_DCMotor *left = AFMS.getMotor(3);
//Adafruit_DCMotor *right = AFMS.getMotor(4);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

// DFRobotDFPlayerMini object
SoftwareSerial mySoftwareSerial(2, 4); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

byte musicIndex = 1;
byte LEDIndex = 1;
bool musicPlayState = true;
bool ledUpState = true;
int servoDir = 90;
Servo cannonServo;
byte PWMApin = 5;
byte PWMBpin = 6;
byte LMApin = A0;
byte LMBpin = A1;
byte RMApin = A2;
byte RMBpin = A3;

//==========================Pin Definition==============================
int redPin = 1;
int greenPin = 0;
int bluePin = 8;
int cannonTurnPin = 3;
int cannonShootPin = 7;
//======================================================================

// ======================Prototype functions===========================

void move_boat(void);
void motor_move(byte, byte, byte, byte, byte, byte); // PWMA, LMA, LMB, RMA, RMB, PWMB
void front_cannon (void);
void song_selection(void);
void led_pattern(void);
void setColor(int, int, int);
void setLEDStrip(void);

// ====================================================================

void setup() {
  //Serial.begin(9600);
  mySoftwareSerial.begin(9600);

  cannonServo.attach(cannonTurnPin);
  //CHANGES for v1.6 HERE!!! **************PAY ATTENTION*************

  error = ps2x.config_gamepad(13, 11, 10, 12, false, false); //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error

  if (error == 0) {
    //Serial.println("Found Controller, configured successful");
    //Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    //Serial.println("holding L1 or R1 will print out the analog stick values.");
    //Serial.println("Go to www.billporter.info for updates and to report bugs.");
  }

  else if (error == 1);
    //Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");

  else if (error == 2);
    //Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if (error == 3);
    //Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

  //Serial.print(ps2x.Analog(1), HEX);

  type = ps2x.readType();
  switch (type) {
    case 0:
      //Serial.println("Unknown Controller type");
      break;
    case 1:
      //Serial.println("DualShock Controller Found");
      break;
    case 2:
      //Serial.println("GuitarHero Controller Found");
      break;
  }

  //AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  delay(1000);

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    //Serial.println(F("Unable to begin:"));
    //Serial.println(F("1.Please recheck the connection!"));
    //Serial.println(F("2.Please insert the SD card!"));
  }

  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  myDFPlayer.loop(musicIndex);  //Play the first mp3
  //Serial.print("Playing the song Index: ");
  //Serial.println(musicIndex);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(cannonShootPin, OUTPUT);
  pinMode(LMApin,OUTPUT);
  pinMode(LMBpin,OUTPUT);
  pinMode(RMApin,OUTPUT);
  pinMode(RMBpin,OUTPUT);
  pinMode(PWMApin,OUTPUT);
  pinMode(PWMBpin,OUTPUT);

  setLEDStrip();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ps2x.ButtonPressed(PSB_BLUE)) {
    //Serial.println("X is pressed!");
    musicPlayState = !musicPlayState;
    if (!musicPlayState)myDFPlayer.pause();
    else if (musicPlayState)myDFPlayer.start();
  }
  if (ps2x.ButtonPressed(PSB_RED)) {
    ledUpState = !ledUpState;
    if (ledUpState)setColor(0, 0, 0);
    else if (!ledUpState)setLEDStrip();
  }
  move_boat();
  front_cannon();
  song_selection();
  led_pattern();
}

/*
void move_boat() {
  ps2x.read_gamepad(false, vibrate);
  float leftJoy = ps2x.Analog(PSS_LY);
  float rightJoy = ps2x.Analog(PSS_RX);
  //Serial.println(leftJoy);

  if (leftJoy < 110) {
    Serial.println("Forward");
    //leftJoy = map(leftJoy,140,255,0,1);
    left->run(FORWARD);
    right->run(FORWARD);
  }
  else if (leftJoy > 140) {
    Serial.println("Backwards");
    //leftJoy = map(leftJoy,0,110,1,0);
    left->run(BACKWARD);
    right->run(BACKWARD);
  }
  else {
     //Serial.println("Stop");
    left->run(RELEASE);
    right->run(RELEASE);
  }

  if (rightJoy > 140) {
    Serial.println("Right");
    float rightMapped = map(rightJoy, 170, 255, 0, 1000) / 1000.0 * 255;
    right->setSpeed(rightMapped);
    left->setSpeed(255);
  }
  else if (rightJoy < 110) {
    Serial.println("Left");
    float rightMapped = map(rightJoy, 30, 110, 0, 1000) / 1000.0 * 255;
    left->setSpeed(rightMapped);
    right->setSpeed(255);
  }
  else {
    //Serial.println("null");
    left->setSpeed(255);
    right->setSpeed(255);
  }
  delay(50);

  }
*/
void move_boat() {
  bool motorStateL[] = {0, 0};
  bool motorStateR[] = {0, 0};
  byte motorSpeedL = 0;
  byte motorSpeedR = 0;
  float rightMotorMapped, leftMotorMapped, PWMmultiplier;

  ps2x.read_gamepad(false, vibrate);
  float leftJoy = ps2x.Analog(PSS_LY);
  float rightJoy = ps2x.Analog(PSS_RX);
  //Serial.println(leftJoy);

  if (rightJoy > 129) {
    //Serial.println("Right");
    rightMotorMapped = map(rightJoy, 127, 255, 1, 0);
    leftMotorMapped = 1;
  }
  else if (rightJoy < 127   ) {
    //Serial.println("Left");
    leftMotorMapped = map(rightJoy, 128, 0, 1, 0);
    rightMotorMapped = 1;
  }
  else {
    //Serial.println("Full speed");
    rightMotorMapped = 1;
    leftMotorMapped = 1;
  }

  if (leftJoy < 110) {
    motorStateL[0] = 0;
    motorStateL[1] = 1;
    motorStateR[0] = 0;
    motorStateR[1] = 1;
    PWMmultiplier = map(leftJoy, 127, 0, 0, 1000)/1000.0;
  }
  else if (leftJoy > 140) {
    motorStateL[1] = 0;
    motorStateL[0] = 1;
    motorStateR[1] = 0;
    motorStateR[0] = 1;
    //Serial.println("Backwards");
    PWMmultiplier = map(leftJoy, 128, 255, 0, 1000)/1000.0;

  }
  else {

    motorStateL[1] = 0;
    motorStateL[0] = 0;
    motorStateR[1] = 0;
    motorStateR[0] = 0;
    //Serial.println("Stop!");
    PWMmultiplier = 0;
  }
  //Serial.print("PWMLeft");//Serial.println(PWMmultiplier * rightMotorMapped * 255);
  //Serial.print("PWMRight");//Serial.println(PWMmultiplier * leftMotorMapped * 255);
  motor_move(PWMmultiplier * rightMotorMapped * 255, motorStateL[0], motorStateL[1], motorStateR[0], motorStateR[1], PWMmultiplier * leftMotorMapped * 255);
  delay(50);
}



void front_cannon() {


  if (ps2x.Button(PSB_R1) && (servoDir >= 0)) {
    //Serial.print("Cannon turn left:");
    servoDir -= 8;
    if (servoDir < 0) {
      //Serial.println("Reset to 0");
      servoDir = 0;
    }
    cannonServo.write(servoDir);
    //Serial.println(servoDir);
    delay(50);
  }
  else if (ps2x.Button(PSB_L1) && (servoDir <= 180)) {
    //Serial.print("Cannon turn right: ");
    servoDir += 8;
    if (servoDir > 176) {
      //Serial.println("Reset to 180");
      servoDir = 170;
    }
    cannonServo.write(servoDir);
    //Serial.println(servoDir);
    delay(50);
  }
  if (ps2x.Button(PSB_PINK)) {
    //Serial.println("Cannon firing");
    digitalWrite(cannonShootPin, HIGH);
    delay(50);
  }
  else {
    digitalWrite(cannonShootPin, LOW);
  }
}

void song_selection() {
  if (musicPlayState) {
    if (ps2x.ButtonPressed(PSB_PAD_LEFT)) {
      //Serial.println("Previous Song");
      musicIndex--;
      if (musicIndex == 0) {
        musicIndex += 10;
      }
      myDFPlayer.loop(musicIndex);
    }
    else if (ps2x.ButtonPressed(PSB_PAD_RIGHT)) {
      //Serial.println("Next Song");
      musicIndex++;
      if (musicIndex > 10) {
        musicIndex -= 10;
      }
      myDFPlayer.loop(musicIndex);
    }
  }
}

void led_pattern() {
  if (ps2x.ButtonPressed(PSB_PAD_UP)) {
    //Serial.println("Next light pattern");
    LEDIndex++;
    setLEDStrip();
  }
  else if (ps2x.ButtonPressed(PSB_PAD_DOWN)) {
    //////Serial.println("Previous light pattern");
    LEDIndex--;
    setLEDStrip();
  }
}

void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setLEDStrip() {
  switch (LEDIndex) {
    case 1:
      setColor(255, 0, 0);  // red
      break;
    case 2:
      setColor(0, 255, 0);  // green
      break;
    case 3:
      setColor(0, 0, 255);  // blue
      break;
    case 4:
      setColor(255, 255, 0);  // yellow
      break;
    case 5:
      setColor(255, 0, 255);  // purple
      break;
    case 6:
      setColor(0, 255, 255);  // aqua
      break;
    case 0 :
      LEDIndex = 6;
      setLEDStrip();
      break;
    case 7:
      LEDIndex = 1;
      setLEDStrip();
      break;

  }
}

void motor_move(byte PWMA, byte LMA, byte LMB, byte RMA, byte RMB, byte PWMB) {

  digitalWrite(LMApin, LMA);
  digitalWrite(LMBpin, LMB);
  digitalWrite(RMApin, RMA);
  digitalWrite(RMBpin, RMB);
  analogWrite(PWMApin, PWMA);
  analogWrite(PWMBpin, PWMB);


}

