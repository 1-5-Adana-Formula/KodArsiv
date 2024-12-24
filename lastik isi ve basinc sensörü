#include <OneWire.h>
#include <DallasTemperature.h>
#define basinc A0
#define isi 2
// ısı sensorunu baslatma
OneWire oneWire(isi);
DallasTemperature sensors(&oneWire);



int ilk_isi;//ilk ısı degerı
int son_isi;//son ısı degerı
int ilk_basinc;//ilk basınc degerı
int son_basinc;//son basınc degerı


void setup() {
 Serial.begin(9600);
  sensors.begin(); 
  sensors.requestTemperatures(); 
  ilk_isi=sensors.getTempCByIndex(0);//ilk ısı degerını atıyoruz
  ilk_basinc=analogRead(basinc);// son ısı degerını atıyoruz

}

void loop() {
  sensors.requestTemperatures(); 
  son_isi=sensors.getTempCByIndex(0);//son ısı degerını alıyoruz
  if(son_isi!=ilk_isi){//sadece ısı degerlerı bırınden farklıysa yazdırıyoruz
  Serial.print("sicaklik degeri:");
  Serial.print(son_isi);
  Serial.println("C");
  }
  ilk_isi=son_isi;//son ısı degerıni ilk ısı degerıne aktarıyoruz
  son_basinc=analogRead(basinc);// son basınc degerını atıyoruz
  
  if(ilk_basinc!=son_basinc){//sadece ilk ve son basınc degerı farklıysa yazdırıyoruz
    float basinc_degeri = (son_basinc * 700.0) / 1023.0;// basınc degerını 0 ve 700 arasına cevırıyoruz
    Serial.print("basınc degeri:");
    Serial.println(basinc_degeri);

  } 
  ilk_basinc=son_basinc; //son basınc degerını ılk basınc degerube atıyoruz


}//https://wokwi.com/projects/418155574855660545
