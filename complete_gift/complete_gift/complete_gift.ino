int led1 = 8; //PORTAB2, RED
int led2 = 7; //PORTA7, GREEN
int led3 = 3; //PORTA3, RED
int led4 = 2; //PORTA2, RED
int led5 = 1; //PORTA1, GREEN

int buzzerPin = 9;

bool timer_flag_blinky = true;
bool buzzer_interrupt_flag = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {

  while(timer_flag_blinky == true)
  {
   blink_leds(); 
  }

}

void blink_leds(){
   for(int i=0; i<3; i++)
    {
      check_for_jingle_bells();
      PORTB |= (1<<PORTB2); 
      PORTA |= ((1<<PORTA3) | (1<<PORTA2));
      PORTA &= ~((1<<PORTA7) | (1<<PORTA1));
      delay(500);
      PORTB &= ~(1<<PORTB2);
      PORTA &= ~((1<<PORTA3) | (1<<PORTA2));
      PORTA |= ((1<<PORTA7) | (1<<PORTA1));
      delay(500);
    }

    for(int j=0; j<10; j++)
    {
      check_for_jingle_bells();
      int sequence_delay = 100;
      PORTB |= (1<<PORTB2);
      PORTA &= ~((1<<PORTA7) | (1<<PORTA1));
      delay(sequence_delay);
      PORTB &= ~(1<<PORTB2);
      PORTA |= (1<<PORTA7);
      delay(sequence_delay);
      PORTA &= ~(1<<PORTA7);
      PORTA |= (1<<PORTA3);
      delay(sequence_delay);
      PORTA &= ~(1<<PORTA3);
      PORTA |= (1<<PORTA2);
      delay(sequence_delay);
      PORTA &= ~(1<<PORTA2);
      PORTA |= (1<<PORTA1);
      delay(sequence_delay);
    }

    for(int k = 0; k<4; k++)
    {
      check_for_jingle_bells();
      PORTB |= (1<<PORTB2);
      PORTA |= ((1<<PORTA7) | (1<<PORTA3) | (1<<PORTA2) | (1<<PORTA1));
      delay(500);
      PORTB &= ~(1<<PORTB2);
      PORTA &= ~((1<<PORTA7) | (1<<PORTA3) | (1<<PORTA2) | (1<<PORTA1));
      delay(500);
    }
}

void check_for_jingle_bells(){
  if(buzzer_interrupt_flag)
  {
    play_jingle_bells(buzzerPin);
  }
}
