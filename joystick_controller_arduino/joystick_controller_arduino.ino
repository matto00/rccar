
#define BUFSIZ 1024


const int sw_pin = 2;  // digital joystick switch
const int x_pin = 0;  // analog
const int y_pin = 1;  // analog
const int dcm_pin = 9; // digital dc motor pin


char buffer[BUFSIZ];
int switch_state = 1;
int x_val = 511;
int y_val = 511;


void setup() {
  pinMode(sw_pin, INPUT);
  pinMode(dcm_pin, OUTPUT);
  digitalWrite(sw_pin, HIGH);
  Serial.begin(115200);
}

void loop() {
  switch_state = digitalRead(sw_pin);
  x_val = analogRead(x_pin);
  y_val = analogRead(y_pin);
  
  sprintf(buffer, "Switch: %d\tX-Axis: %d\tY-Axis: %d", switch_state, x_val, y_val);
  
  if (y_val > 511) digitalWrite(dcm_pin, HIGH);
  else digitalWrite(dcm_pin, LOW);
  
  Serial.println(buffer);
  delay(250);
}
