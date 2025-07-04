//pedaldan gelen verıyı alıp esc`e ıleterek motora verılecek guc sevıyesı ayarlamak ıcın 
const int potPin = 35;  
const int throttle = 26;   // PWM çıkışı(ESC throttle girişi)  

void setup() {
  Serial.begin(115200);
  pinMode(throttle, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);  
  int power = map(potValue, 0, 4095, 0, 255);/* bu kısımda degerlerı kendımıze gore degıstırebılırız duruma gore 
  duruma gore belirli sevıyelere bloklar seklınde ayaralanabılır ama bu halı max ve min sekli icin */

  
  analogWrite(throttle,power);  



  delay(20);
}
