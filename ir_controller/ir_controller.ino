
#include "IRremote.h"

int receiver = 13; // Signal Pin of IR receiver to Arduino Digital Pin 11
int ir_res_value;

IRrecv irrecv(receiver);
decode_results* results;

int translateIR() {
  ir_res_value = (*results).value;
  return (*results).value;
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
    translateIR(); 
    irrecv.resume();
  }  
}
