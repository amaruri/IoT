#include "DHT.h"

DHT dht;
#define redLed 11
#define yellowLed 10
#define orangeLed 9
#define greenLed 8

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)");

  dht.setup(2); // data pin 2

  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print('\n');

  if(temperature <= 24){
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(orangeLed, LOW);
    digitalWrite(greenLed, HIGH);
  }

  if(temperature > 24 && temperature <= 26){
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(orangeLed, HIGH);
    digitalWrite(greenLed, LOW);
  }

  if(temperature > 26 && temperature <= 28){
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(orangeLed, LOW);
    digitalWrite(greenLed, LOW);
  }

  if(temperature > 28){
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(orangeLed, LOW);
    digitalWrite(greenLed, LOW);
  }
  
}

