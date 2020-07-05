#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
#include <DHT.h>      // подключаем библиотеку для датчика
#define DHTPIN 4 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

int photocellPin = 0; // сенсор и понижающий резистор 10 кОм подключены к a0

int photocellReading; // считываем аналоговые значения с делителя сенсора

void setup(void) {
  dht.begin();                // запускаем датчик DHT11

pinMode (13, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }

  uint32_t currentFrequency;
    
  Serial.println("R H T V I P" );
  
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  //ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  //ina219.setCalibration_16V_400mA();

  //Serial.println("Measuring voltage and current with INA219 ...");

}

void loop(void) {
  digitalWrite (13, HIGH);
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  // считываем температуру (t) и влажность (h)
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   //float hic = dht.computeHeatIndex(t, h, false);

photocellReading = analogRead(photocellPin);

//Serial.print("PhotoR = ");


  // выводим температуру (t) и влажность (h) на монитор порта
  // Serial.print(F("Humidity: "));Serial.print(h);
 // Serial.print(F("%  Temperature: "));Serial.print(t);
 // Serial.print(F("°C "));Serial.print(F("°F  Heat index: "));
 // Serial.print(hic);Serial.print(F("°C "));
//Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
 // Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
 // Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  //Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
 // Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");

 // Serial.println("");
Serial.print(photocellReading);
// аналоговые значения с сенсора
Serial.print(" ");
Serial.print(h);
Serial.print(" ");
Serial.print(t);
Serial.print(" ");
Serial.print(loadvoltage);
Serial.print(" ");
Serial.print(current_mA);
Serial.print(" ");
Serial.println(power_mW);
delay(2000);

}
