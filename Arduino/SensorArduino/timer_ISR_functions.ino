/***************************************************************
     This function sets up the timer interrupt on the arduino
     and will go off at 1Hz (every second).
****************************************************************/

void setUpTimerISR(void) {

  cli();//stop interrupts

  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0

  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);

  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);

  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei();//allow interrupts
}

/***************************************************************
     When the timer interrupt occurs the following function will
     be run. It will queue the timer status code for the 
     Raspberry Pi to read (0x05) then send the notification
     signal to the raspberry pi to pull the status code. 
****************************************************************/

ISR(TIMER1_COMPA_vect) { //timer1 interrupt 1Hz toggles pin 13 (LED)
  //generates pulse wave of frequency 1Hz/2 = 0.5Hz (takes two cycles for full wave- toggle high then toggle low)
  Serial.println("Timer");
  dataQueued = 0x05;
  digitalWrite(PI_INTERRUPT, HIGH);
  digitalWrite(PI_INTERRUPT, LOW);
  sensorUpdateFlag = 0b1111;
}