#define trig 3
#define echo 2


void setup() {
Serial.begin(9600); 
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
  

}

void loop() {
  Serial.print("mesafe: ");
  Serial.print(mesafe());
  Serial.println("cm");
  delay(1000);
  

}
long mesafe(){
  digitalWrite(trig, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  long sure=pulseIn(echo,HIGH);
  long uzaklik=sure*0.0344 / 2;
  return uzaklik;
}
https://wokwi.com/projects/418246290698147841
