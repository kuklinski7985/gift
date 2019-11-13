//#define DOOR_PIN 3 // D3
//#define LED_PIN  2 // D2

#define BUTTON_PIN 8
#define LED_PIN 7

static int interrupted;

//ISR(PCINT0_vect) { interrupted = true; }
ISR(INT0_vect)
{
  interrupted = true;
}

void handleInterrupt() {
  //Turn on LED for 2 seconds when an interrupt is caught
  digitalWrite(LED_PIN, HIGH);
 
  delay(2000);
 
  digitalWrite(LED_PIN, LOW);
}

void setup() {
  interrupted = false;
 
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  MCUCR |= _BV(ISC01);   //sets the external interrupt INT0 and falling edge
  GIMSK |= _BV(INT0);   // Enable Pin Change Interrupts
  //PCMSK0 |= _BV(PCINT0); // Use PA7 as interrupt pin
 
  sei(); //Enable interrupts
}

void loop() {
  if(interrupted) {
    handleInterrupt();
    interrupted = false;
  }
}
