#define trig_pin 6 
// trig sinyal gönderme
#define echo_pin 7
// echo sinyal alma
int distance;
int time;
void setup()
{
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  //buraya kadar sensörümüzden sinyal gönderdik
  time=pulseIn(echo_pin,HIGH);
  //veriyi aldık (süre olarak)
  distance=time/58.2;
  delay(50);
  //süreyi mesafeye çevirdik (cm cinsinden)
  Serial.print("Result =");
  Serial.println(distance);
  delay(500);
  //sonucu seri monitörümüze yazdırdık
}

https://www.tinkercad.com/things/ejh7meMe7T3-mesafe-olcme/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits
