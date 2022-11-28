/*
  Blink SOS

programming socks on!! 

*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait 
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait
  digitalWrite(LED_BUILTIN, HIGH);  // same as above
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);   // LED off
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);  // LED on
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);   // LED off
  delay(100);                       // morse code "S"

  delay(500);                       //wait

  digitalWrite(LED_BUILTIN, HIGH);  // LED on  
  delay(1000);                      // 
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);  // LED on  
  delay(1000);                      // 
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);  // LED on  
  delay(1000);                      // 
  digitalWrite(LED_BUILTIN, LOW);   // LED off
  delay(100);                       // morse code "O"

  delay(500);                       //wait

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait 
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait
  digitalWrite(LED_BUILTIN, HIGH);  // same as above
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);   // LED off
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);  // LED on
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);   // LED off
  delay(100);                       // morse code "S"

  delay(25000);                      // wait 25 sec 
}
