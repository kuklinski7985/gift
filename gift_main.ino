/*
  Blink (modified slightly for ATTiny84/44 ICs
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */
#include <avr/sleep.h>

#define adc_disable() (ADCSRA &= ~(1<<ADEN)) // disable ADC (before power-off)
#define adc_enable()  (ADCSRA |=  (1<<ADEN)) // re-enable ADC

// ATTIny84 / 44 does not have Pin 13, so we use pin 7 instead.
// A current limiting resistor should be connected in line with the LED.
int led1 = 7;
int led2 = 6;
int led3 = 5;
int led4 = 4;
int led5 = 3;
int button_interr = 0;

/*static int button_press;

void enter_sleep(void)
{
  sleep_enable();
  sleep_cpu();
  
}

void init_PCINT0_inter()
{
  //GIMSK |= (1 << INT0);   //global pin change interrupts enable, general interrupt mask register
  //SREG |= (1 << 7);

  GIMSK |= _BV(INT0);
  PCMSK0 |= _BV(PCINT0);
  sei();                  //enable enterrupts
}

ISR(PCINT0_vect)
{
  button_press = true;
}
*/
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
/*  button_press = false;

  pinMode(button_interr, INPUT);

  adc_disable(); // ADC uses ~320uA
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  init_PCINT0_inter();*/
}


void loop() {
  /*int sleep_time = 1000;

  
  if(button_press)
  {
    digitalWrite(led1,HIGH);
    delay(5000);
    digitalWrite(led1,LOW);
    button_press = false;
  }
  else
  {
    do{*/
        digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(led5, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(500);               // wait for a second
        digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(led3, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(led4, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(led5, LOW);    // turn the LED off by making the voltage LOW
        delay(500);               // wait for a second
   // }while(millis() < sleep_time);
  //}

  //enter_sleep();
}

//http://www.technoblogy.com/show?KX0
