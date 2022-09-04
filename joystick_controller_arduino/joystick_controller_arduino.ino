//www.elegoo.com
//2016.12.9

#include "IRremote.h"

int receiver = 13; // Signal Pin of IR receiver to Arduino Digital Pin 11
int remote_output;

IRrecv irrecv(receiver);
decode_results* results;




void translateIR()
{
  switch((*results).value)
  {
     
    default: 
      Serial.println(" other button   ");
  }
  delay(500); // Do not get immediate repeat
}


void setup()
{
  Serial.begin(115200);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn();

}


void loop()
{
  if (irrecv.decode(results))
  {
    // Get value
    (*results).value;
    irrecv.resume();
  }  
}
