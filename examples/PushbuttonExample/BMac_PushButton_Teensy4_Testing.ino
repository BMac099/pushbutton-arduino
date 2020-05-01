  #include <Pushbutton.h>   

  Pushbutton JogXFwd(1,100);    // pushbutton library DI pin defined as 1
  Pushbutton JogXRev(2,300); // set debounce for 300 mS default is 50
  Pushbutton JogYFwd(3);
  Pushbutton JogYRev(4);

  String stringToSend,  stringLastSent;
  String strVariable , strSendThis ;
  bool JogXFwdPressed, JogXRevPressed;
  int led = 13;
  
void setup() {
    pinMode(led, OUTPUT);
}

void loop() {

if (JogXFwd.getSingleDebouncedPress()){
      Serial.println("JogXFwd was pressed");
       JogXFwdPressed = true;
}
if (JogXFwd.getSingleDebouncedRelease()){
      Serial.println("JogXFwd was Released");
      JogXFwdPressed = false;
}

if (JogXRev.getSingleDebouncedPress()){
      Serial.println("JogXRev was pressed");
         JogXRevPressed = true;
}
if (JogXRev.getSingleDebouncedRelease()){
      Serial.println("JogXRev was Released");
      JogXRevPressed = false;     
}

 digitalWrite(led, JogXFwdPressed  ^ JogXRevPressed); // exclusive OR
 // X_ManualControl();

}



void X_ManualControl(){     

 if (JogXFwd.getSingleDebouncedPress() && JogXRev.getSingleDebouncedPress())
  {
    // Both JogFwd and JogRev are pressed.
    SendToSerial("Both JogFwd and JogRev are pressed.");

  }
 else if (JogXFwd.getSingleDebouncedPress() )
  {
    SendToSerial("JogXFwd was pressed");
  }
 else if (JogXRev.getSingleDebouncedPress())
  {
    SendToSerial("JogXRev was pressed");
  }
 else
  {
    // Neither JogFwd nor JogRev are pressed. 
         SendToSerial("X Jog Buttons Released");
  }
  }   // ---------------               End of X_ManualControl           ------------------//


void SendToSerial(String strSend ){
  if (strSend !=   stringLastSent) {
    Serial.println(strSend);
    stringLastSent = strSend;
  }
}
