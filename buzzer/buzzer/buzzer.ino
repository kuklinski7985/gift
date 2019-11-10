int buzzerPin = 9;

double e_note = 329.628;
double g_note = 391.995;
double c_note = 261.626;
double d_note = 293.665;

int led1 = 8;
int led2 = 7;
int led3 = 3;
int led4 = 2;
int led5 = 1;

void setup() 
{
  pinMode(buzzerPin,OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  int tempo = 200;  //each beat gets x ms
  int quarter_note = tempo;
  int whole_note = tempo * 4;
  int half_note = tempo * 2;
  int dot_quarter_note = tempo * 1.5;
  int eight_note = tempo / 2;
  int pauseTimeMs = 25;//time to pause between each frequency in milliseconds

  int jingle_bells[11][2] = 
  {{e_note, quarter_note},
   {e_note, quarter_note},
   {e_note, half_note},
   {e_note, quarter_note},
   {e_note, quarter_note},
   {e_note, half_note},
   {e_note, quarter_note},
   {g_note, quarter_note},
   {c_note, dot_quarter_note},
   {d_note, eight_note},
   {e_note, whole_note}
  };

  for(int i = 0; i <= 10; i++)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    playFreq(buzzerPin, jingle_bells[i][0], jingle_bells[i][1]);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(pauseTimeMs);
  }
}
 
void playFreq(int buzzerPin, double freqHz, int durationMs)
{
    //Calculate the period in microseconds
    int periodMicro = int((1/freqHz)*1000000);
    int halfPeriod = periodMicro/2;
     
    //store start time
    int startTime = millis();
     
    //(millis() - startTime) is elapsed play time
    while ((millis() - startTime) < durationMs)    
    {
        digitalWrite(buzzerPin, HIGH);
        //PORTB |= (1 << PORTB3);
        delayMicroseconds(halfPeriod);
        digitalWrite(buzzerPin, LOW);
        //PORTB &= ~(1 << PORTB3);
        delayMicroseconds(halfPeriod);
    }
  
}
 
void loop() 
{
}
