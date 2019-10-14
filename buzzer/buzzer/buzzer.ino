int buzzer = 8;
double freqHz = 1000;

int periodMicro = (1/freqHz)*1000000; //int((1/freqHz)*1000000);
double halfPeriod = periodMicro/2;

void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
   digitalWrite(buzzer, HIGH);
   delay(halfPeriod);
   digitalWrite(buzzer, LOW);
   delay(halfPeriod);

}
