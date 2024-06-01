#include <DHT.h>

#define DHTPIN 2       
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

int ledPin = 9; 

void setup() {
  pinMode(ledPin, OUTPUT); 
  dht.begin(); 
  Serial.begin(9600); 
}

void loop() {
  float temperature = dht.readTemperature(); 

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print(" Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  int delayTime = map(temperature, 0, 50, 20, 1); 
  for (int a = 0; a <= 255; a++) { 
    analogWrite(ledPin, a);
    delay(delayTime); 
  }
  for (int a = 255; a >= 0; a--) { 
    analogWrite(ledPin, a);
    delay(delayTime); 
  }
  Serial.println(delayTime);
}