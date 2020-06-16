void setup() {
 Serial.begin(9600);
 pinMode(A8, INPUT_PULLUP);
 pinMode(A9, INPUT_PULLUP);
  
 pinMode(42, OUTPUT);
 pinMode(43, OUTPUT);
 pinMode(44, OUTPUT);
 pinMode(45, OUTPUT);
 pinMode(46, OUTPUT);
 pinMode(47, OUTPUT);
 pinMode(48, OUTPUT);
 pinMode(49, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    char inByte = Serial.read();
      if(inByte == 1) {
       int leftLED = 49;
       int rigthLED = 42;
        while(rigthLED != 46 && leftLED != 45) {
         digitalWrite(leftLED, 1);
         delay(500);
         digitalWrite(leftLED, 0);
         
         digitalWrite(rigthLED, 1);
         delay(500);
         digitalWrite(rigthLED, 0);
         leftLED = leftLED - 1;
         rigthLED = rigthLED + 1;
        }
      }
 
      if(inByte == 2) {
        int leftLED = 49;
        while(leftLED != 41 ) {
        digitalWrite(leftLED, 1);
        delay(500);
        digitalWrite(leftLED, 0);

        leftLED = leftLED - 2;
        }
        int rigthLED = 48;
        while(rigthLED != 40) {
        digitalWrite(rigthLED, 1);
        delay(500);
        digitalWrite(rigthLED, 0);
         rigthLED = rigthLED - 2;
        }
      } 
}

  
  if(!digitalRead(A8)==1){
    Serial.write(1);
    delay(200);
  }

  if(!digitalRead(A9)==1){
    Serial.write(2);
    delay(200);
  }
}
