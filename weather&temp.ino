#include <DHT.h>
#include <DHT_U.h>

#include <SoftwareSerial.h>

//Pin 2 Transmisor
//Pin 3 Receptor
SoftwareSerial mySerial(2, 3);
DHT dht(4, DHT11);

float temperature = 0;
float humidity = 0;

void setup() {
  dht.begin();
  mySerial.begin(9600);
  Serial.begin(9600);

}

void loop() {
  delay(5000);
  
  mySerial.print(getWeather());
  
}


String getWeather(){
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  
  String myString = String(temperature, 2)+","+String(humidity, 2);
  return myString;
}
