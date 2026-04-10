#include <Arduino_BuiltIn.h>

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;
int LED6 = 8;
int LED7 = 7;
int soundPin = A0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);
pinMode(LED6, OUTPUT);
pinMode(LED7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long sum = 0;
//instead of parenthesis () put angle bracket as YouTube description does not allow angle bracket
for(int i=0; i < 100; i++) // taking 100 sample of sound
{
sum += analogRead(soundPin);
}

sum = sum/100; // average the sample of sound

if (sum >= 100) digitalWrite(LED1, HIGH); else digitalWrite(LED1, LOW);
if (sum >= 200) digitalWrite(LED2, HIGH); else digitalWrite(LED2, LOW);
if (sum >= 300) digitalWrite(LED3, HIGH); else digitalWrite(LED3, LOW);
if (sum >= 350) digitalWrite(LED4, HIGH); else digitalWrite(LED4, LOW);
if (sum >= 400) digitalWrite(LED5, HIGH); else digitalWrite(LED5, LOW);
if (sum >= 450) digitalWrite(LED6, HIGH); else digitalWrite(LED6, LOW);
if (sum >= 500) digitalWrite(LED7, HIGH); else digitalWrite(LED7, LOW);

delay(10); 
Serial.println(sum);

}
