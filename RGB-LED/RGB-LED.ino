
#include <Bounce2.h>

Bounce debouncer = Bounce();

int blueLED = 9;
int greenLED = 10;
int redLED = 11;
int ButtonPin = 7;

const int LEDModeOff = 0;
const int LEDModeRedOn = 1;
const int LEDModeGreenOn = 2;
const int LEDModeBlueOn = 3;
const int LEDModeAllOn = 4;

int ledMode = 0;

int buttonState = 0;
int lastButtonState = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  //pinMode(ledPin, OUTPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  Serial.begin(9600);


// After setting up the button, setup the Bounce instance :
  debouncer.attach(ButtonPin);
  debouncer.interval(5); // interval in ms

}

void loop() {

// Update the Bounce instance :
  debouncer.update();


  if (debouncer.rose()) {
    lastButtonState = buttonState;

    ledMode++;
    Serial.print(ledMode, DEC);
    Serial.print("\n");
    switch (ledMode % 5) {
    case LEDModeOff:
    {
      analogWrite(redLED, 0);
      analogWrite(greenLED, 0);
      analogWrite(blueLED, 0);
      break;
    }
    case LEDModeGreenOn:
    {
      analogWrite(redLED, 0);
      analogWrite(greenLED, 255);
      analogWrite(blueLED, 0);
      break;
    }
    case LEDModeRedOn:
    {
      analogWrite(redLED, 255);
      analogWrite(greenLED, 0);
      analogWrite(blueLED, 0);
      break;
    }

    case LEDModeBlueOn:
    {
      analogWrite(redLED, 0);
      analogWrite(greenLED, 0);
      analogWrite(blueLED, 255);
      break;
    }
    case LEDModeAllOn:
    {
      analogWrite(redLED, 255);
      analogWrite(greenLED, 255);
      analogWrite(blueLED, 255);
      break;
    }
    }

  }

  /*
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
  */
}
