#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define trig_pin 8
#define echo_pin 7
Servo upper_servo;
Servo lover_servo;
float x=0,y=0,z=0;
int pway=0;
int nway=0;
long duration;
LiquidCrystal_I2C lcd(0x20,16,2);
// tanımlamaları yaptık kodlama kısmına geçeceğiz
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.display();
  lcd.setCursor(1,0);
  lcd.print("Measuring is");
  lcd.setCursor(1,1);
  lcd.print("in progress");
  //lcd ekrana yakıt değerinin hesaplandığını belirttik
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  upper_servo.attach(10);
  lover_servo.attach(9);
  length();
  width();
  height();
  delay(100);
  //en boy yükseklik fonksiyonlarıyla ölçümü yapacağız her çalıştırdığımızda
  float fuel_value =(50*250*60)/(x*y*z);
  //yakıt değerinde ölçümleri yapacağız ve doluluk oranını hesaplayacağız
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Fuel Level =");
  lcd.setCursor(7,1);
  lcd.print(fuel_value);
  lcd.setCursor(2,1);
  lcd.print("cm^3");
}
void loop()
{
}
void length()
{
  take_value();
  pway=duration / 58.2;
  delay(600);
  //üst kısımda sensör durduğu esnada gelen sese göre mesafe ölçtük
  //ölçtüğümüz değeri pway olarak kaydettik
  lover_servo.write(0);
  upper_servo.write(180);
  take_value();
  nway=duration / 58.2;
  delay(600);
  x=((pway+nway));//burada sensör için kullandığımız malzemenin de
  // cm cinsinden değerini + a gibi eklememiz gerek
  //üst kısımda sensör durduğu esnada gelen sese göre mesafe ölçtük
  //ölçtüğümüz değeri nway olarak kaydettik
}
void width()
{
  lover_servo.write(90);
  upper_servo.write(180);
  take_value();
  pway=duration / 58.2;
  delay(600);
  //üst kısımda sensör durduğu esnada gelen sese göre mesafe ölçtük
  //ölçtüğümüz değeri pway olarak kaydettik
  take_value();
  nway=duration / 58.2;
  delay(600);
  y=((pway+nway));
  //burada sensör için kullandığımız malzemenin de
  // cm cinsinden değerini + a gibi eklememiz gerek
  //üst kısımda sensör durduğu esnada gelen sese göre mesafe ölçtük
  //ölçtüğümüz değeri nway olarak kaydettik
}
void height()
{
  lover_servo.write(90);
  upper_servo.write(90);
  take_value();
  nway=duration / 58.2;
  delay(600);
  z=((nway));
  //burada sensör için kullandığımız malzemenin de
  // cm cinsinden değerini + a gibi eklememiz gerek
  //üst kısımda sensör durduğu esnada gelen sese göre mesafe ölçtük
  //ölçtüğümüz değeri nway olarak kaydettik
}
void take_value()
{
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  duration=pulseIn(echo_pin,HIGH);
}
