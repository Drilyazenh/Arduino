
#include <DHT.h>      // подключаем библиотеку для датчика
#define DHTPIN 4 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

int photocellPin = 0; // сенсор и понижающий резистор 10 кОм подключены к a0

int photocellReading; // считываем аналоговые значения с делителя сенсора

void setup(void) {
  dht.begin();                // запускаем датчик DHT11

Serial.begin(9600);

}

void loop(void) {
  // считываем температуру (t) и влажность (h)
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   float hic = dht.computeHeatIndex(t, h, false);

photocellReading = analogRead(photocellPin);

Serial.print("PhotoR = ");

Serial.println(photocellReading); // аналоговые значения с сенсора
  // выводим температуру (t) и влажность (h) на монитор порта
   Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));

delay(2000);

}
