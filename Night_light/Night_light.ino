int ledpinnumber = 13;
int prpinnumber = A0;

void setup() {
  // put your setup code here, to run once:
pinMode (ledpinnumber, OUTPUT);
pinMode (prpinnumber, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println (analogRead (prpinnumber));
if (analogRead (prpinnumber) <240){
  digitalWrite (ledpinnumber, HIGH);
}
else {
  digitalWrite (ledpinnumber, LOW);
}
}
