#include <Wire.h>
#include <LiquidCrystal_I2C.h>
float value =0;
int led_pin=10;
int fsr_sensor=A0;
LiquidCrystal_I2C lcd(32,16,2);
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.display();
  lcd.setCursor(0,0);
  lcd.print("Measuring is");
  lcd.setCursor(1,1);
  lcd.print("in progress");
  pinMode(fsr_sensor, INPUT);
  pinMode(led_pin, OUTPUT);
  delay(2000);
  lcd.clear();
}

void loop()
{
  value = analogRead(fsr_sensor);
  if (value > 320) {
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }
  lcd.setCursor(0,0);
  lcd.print("Analog =");
  lcd.setCursor(10,0);
  lcd.print(value);
  float voltage= value*(5.0/1023.0);
  lcd.setCursor(0,1);
  lcd.print("Volt =");
  lcd.setCursor(8,1);
  lcd.print(voltage);
}
