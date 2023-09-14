// Code for NodeMCU

// GPIO Pins
int ledPin[] = {15, 13, 12, 14};
int surroundPin = 4;

int fadespeed = 5;
int timeTravelSpeed = 80;
int timeTravelLength = 25;
 
void setup() {
}
 
void loop(){
    runlights();
}

void runlights(){
  //Speed up loops
  for (int fadeIncrement=20; fadeIncrement<=100; fadeIncrement+=2){
    for (int i=0; i<=3; i++) {
      for (int fadeValue=0 ; fadeValue<=255; fadeValue+=fadeIncrement) {
        analogWrite(ledPin[i], fadeValue);             
        delay(fadespeed);                           
      } 
      for (int fadeValue=255; fadeValue>=0; fadeValue-=fadeIncrement) {
        analogWrite(ledPin[i], fadeValue);         
        delay(fadespeed);                               
      } 
      analogWrite(ledPin[i], 0);
    }
  }
  
  //time travel loops
  for (int timetravel=1; timetravel<=timeTravelLength; timetravel+=1){
    //turn on surround lights
    for (int fadeValue=0; fadeValue<=255; fadeValue+=15) {
      analogWrite(surroundPin, fadeValue);             
      delay(fadespeed);                           
    } 
 
    //Run time travel lights
    for (int i=0; i<=3; i++) {
      for (int fadeValue=0; fadeValue<=255; fadeValue+=timeTravelSpeed) {
        analogWrite(ledPin[i], fadeValue);             
        delay(fadespeed);                           
      } 
      for (int fadeValue=255; fadeValue>=0; fadeValue-=timeTravelSpeed) {
        analogWrite(ledPin[i], fadeValue);         
        delay(fadespeed);                               
      }
    }
   
   //fade out the surround lights
    for (int fadeValue=255; fadeValue>=0; fadeValue-=15) {
      analogWrite(surroundPin, fadeValue);             
      delay(fadespeed);                           
    } 
  }

  for (int i=0; i<=3; i++) {
    analogWrite(ledPin[i], 0);
  }
}
