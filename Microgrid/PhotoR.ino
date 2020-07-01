
int photocellPin = 0; // сенсор и понижающий резистор 10 кОм подключены к a0

int photocellReading; // считываем аналоговые значения с делителя сенсора

void setup(void) {

Serial.begin(9600);

}

void loop(void) {

photocellReading = analogRead(photocellPin);

Serial.print("PhotoR = ");

Serial.println(photocellReading); // аналоговые значения с сенсора

delay(100);

}
