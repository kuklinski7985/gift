

//int led1 = 8; //PORTAB2, RED
int led2 = 7; //PORTA7, GREEN
int led3 = 3; //PORTA3, RED
int led4 = 2; //PORTA2, RED
int led5 = 1; //PORTA1, GREEN

int buzzerPin = 9;
int button_pin = 8;

bool timer_flag_blinky = true;
volatile int buzzer_interrupt_flag;

void setup() {
  //pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  buzzer_interrupt_flag = false;

  pinMode(button_pin, INPUT_PULLUP);
  
  MCUCR |= _BV(ISC01);   //sets the external interrupt INT0 and falling edge
  GIMSK |= _BV(INT0);   // Enable Pin Change Interrupts
 
  sei(); //Enable interrupts
  

}

void loop() {

  while(timer_flag_blinky == true)
  {
   blink_leds(); 
  }
}

void check_for_jingle_bells(){
  if(buzzer_interrupt_flag == true)
  {
    play_jingle_bells(buzzerPin);
    buzzer_interrupt_flag = false;
  }
}

ISR(INT0_vect){
  buzzer_interrupt_flag = true;
}
