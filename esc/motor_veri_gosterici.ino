#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <math.h>
// sh1107 ıcın ekran ayarları,sh1107 ıcın ozellıstırılmıs ama farklı bır ekran ıcın degısıklık olabılır 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C
//sh1107nın pın gırıslerı,sh1107 ıcın ozellıstırılmıs ama farklı bır ekran ıcın degısıklık olabılır 
#define I2C_SDA 0
#define I2C_SCL 4

Adafruit_SH1107 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// bu pınler esc yı temsıl edıyor escden gelecek olan degerlere gore degısıklık olabılır
#define POT_VOLT_PIN 34 // bu esc den gelecek voltaj degerlerının pını,eger can bus ıle verı gelırse pınler yerıne id leri yazacgız
#define POT_AMP_PIN 35 // bu esc den gelecek amper degerlerının pını,eger can bus ıle verı gelırse pınler yerıne id leri yazacagız
#define POT_RPM_PIN 32// bu esc den gelecek rpm degerlerının pını,eger can bus ıle verı gelırse pınler yerıne id leri yazacagız
#define TEMP_PIN 33// bu esc den gelecek sıcaklık degerlerının pını,eger can bus ıle verı gelırse pınler yerıne id leri yazacagız

// Uyarı çıkışı (LED/Buzzer)
#define Alert 2

// bu kısım escdekı sıcaklık sensorune gore degısebılır ya da kaldırılabılır
#define ADC_MAX 4095.0
#define VCC 3.3
#define R_REF 10000.0     // Referans direnç 10k Ohm
#define BETA 3950.0       // Beta katsayısı (NTC datasheet'ten al)
#define T0 298.15         // 25°C Kelvin (273.15 + 25)
#define R0 10000.0        // 25°C'deki direnç 10k Ohm


//sıcaklık ve akım ıcın kabuledılebılır max deger,bu degerler deneme ıcın konuldu duruma gore degısebılır
int t_max=70;
int c_max=20;

void setup() {
  Serial.begin(115200);
  pinMode(Alert, OUTPUT);

  Wire.begin(I2C_SDA, I2C_SCL);
  if (!display.begin(OLED_ADDRESS, true)) {
    Serial.println("OLED baslatilamadi");
    while (true);
  }

  display.clearDisplay();
  display.setRotation(0);
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
}

void loop() {
  // Analog değerleri oku
  int voltRaw = analogRead(POT_VOLT_PIN);
  int ampRaw = analogRead(POT_AMP_PIN);
  int rpmRaw = analogRead(POT_RPM_PIN);
  int tempRaw = analogRead(TEMP_PIN);

  // Voltaj, akım ve rpm dönüşümleri
  float volt = map(voltRaw, 0, 4095, 180, 260) / 10.0;   // 18.0V - 26.0V arası
  float current = map(ampRaw, 0, 4095, 0, 30);           // 0A - 30A arası
  int rpm = map(rpmRaw, 0, 4095, 1000, 10000);           // 1000 - 10000 rpm arası

  // NTC hesaplama
  float vOut = (tempRaw / ADC_MAX) * VCC;
  float rNTC = R_REF * (VCC / vOut - 1.0);
  float tempK = 1.0 / ( (1.0 / T0) + (1.0 / BETA) * log(rNTC / R0) );
  float tempC = tempK - 273.15;

  // Alarm eşikleri
  bool akimAsim = current > c_max;
  bool sicaklikAsim = tempC > t_max;

  // OLED gösterim
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("ESC Monitor");
  display.print("RPM: "); display.println(rpm);
  display.print("Volt: "); display.print(volt); display.println(" V");
  display.print("Akim: "); display.print(current); display.println(" A");
  display.print("Sicaklik: "); display.print(tempC, 1); display.println(" C");

  // Alarm durumu
  if (akimAsim || sicaklikAsim) {
    display.setTextColor(SH110X_BLACK, SH110X_WHITE);
    if (akimAsim) display.println("HATA: Akim Yuksek!");
    if (sicaklikAsim) display.println("HATA: Sicaklik Yuksek!");
    digitalWrite(Alert, HIGH);
  } else {
    digitalWrite(Alert, LOW);
    display.setTextColor(SH110X_WHITE);
  }

  display.display();
  delay(500);
}
