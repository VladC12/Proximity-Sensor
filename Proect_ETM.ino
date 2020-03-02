#include <LiquidCrystal.h>

int Contrast = 75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int ledPinR = A0;
const int ledPinG = A1;
const int ledPinB = A2;

// defines variables
long duration;
int distance;


void setup() {
	//LCD
	analogWrite(6, Contrast);
	lcd.begin(16, 2);

	pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin, INPUT); // Sets the echoPin as an Input
	pinMode(ledPinR, OUTPUT);
	pinMode(ledPinG, OUTPUT);
	pinMode(ledPinB, OUTPUT);
	Serial.begin(9600); // Starts the serial communication
}


void loop() {
	
	// Clears the trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);


	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);

	// Calculating the distance
	distance = duration*0.034 / 2;

	if (distance > 40 && distance <= 50) {
		RGB_color(0, 0, 255); // Blue
		delay(50);
	}
	else {
		analogWrite(ledPinB, 0);
		delay(50);
	}

	if (distance > 30 && distance <= 40) {
		RGB_color(255, 0, 255); // Magenta
		delay(50);
	}
	else {
		RGB_color(0, 0, 0);
		delay(50);
	}

	if (distance > 20 && distance <= 30) {
		RGB_color(0, 255, 0); // Green
		delay(50);
	}
	else {
		analogWrite(ledPinG, 0);
		delay(50);
	}

	if (distance > 10 && distance <= 20) {
		RGB_color(0, 255, 255); // Cyan
		delay(50);
	}
	else {
		RGB_color(0, 0, 0);
		delay(50);
	}

	if (distance <= 10) {
		RGB_color(255, 0, 0); // Red
		delay(50);
	}
	else {
		analogWrite(ledPinR, 0);
		delay(50);
	}

	// Prints the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.println(distance);


	//LCD
	lcd.setCursor(0, 0);
	lcd.print("Distance: ");

	lcd.setCursor(0, 1);
	lcd.print(distance);
	lcd.print("    cm      ");
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
	analogWrite(ledPinR, red_light_value);
	analogWrite(ledPinG, green_light_value);
	analogWrite(ledPinB, blue_light_value);
}