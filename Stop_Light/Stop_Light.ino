int greenledpin = 13;
int redledpin = 12;
int yellowledpin = 8;
int prpin = A0;

void setup() {
  // put your setup code here, to run once:
pinMode (greenledpin, OUTPUT);
pinMode (redledpin, OUTPUT);
pinMode (yellowledpin, OUTPUT);
pinMode (prpin, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println (analogRead (prpin));

if (analogRead (prpin) <300){
  delay (200);
  digitalWrite (greenledpin, HIGH);
  digitalWrite (yellowledpin, LOW);
  digitalWrite (redledpin, LOW);
  delay (6000);
  digitalWrite (greenledpin, LOW);
  digitalWrite (yellowledpin, HIGH);
  delay (2000);
  digitalWrite (yellowledpin, LOW);
  digitalWrite (redledpin, HIGH);
  delay (4000);
  
}
else {
  digitalWrite (greenledpin, LOW);
  digitalWrite (redledpin, LOW);
  digitalWrite (yellowledpin, HIGH);
  delay (3000);
  digitalWrite (redledpin, HIGH);
  digitalWrite (yellowledpin, LOW);
  delay (5000);
    
  
}
}
