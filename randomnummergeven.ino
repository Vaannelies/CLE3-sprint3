void setup() {
  randomSeed(analogRead(A0));
  
  Serial.begin(9600);
  for ( int i = 0; i < 5; i++ ) {
    Serial.print(random(1,101));
    Serial.print(" ");
  }
  Serial.println("");
}

void loop() {
  
}
