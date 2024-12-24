#define  potansiyon_metre A0
#define encoder_clk 2
#define encoder_dt  3

int enc_deger;
int ilk_v;//potansıyon metre ılk voltaj degeri
int son_v; // potansıyon metre son voltaj degeri
int clk_ilk;// encoder ıcın ılk clk degeri
int clk_anlik;// encoder ıcın son clk degeri


void setup() {
pinMode(encoder_clk, INPUT);
pinMode(encoder_dt, INPUT);  
Serial.begin(9600);
clk_ilk=digitalRead(encoder_clk);
ilk_v=analogRead(potansiyon_metre);
}

void loop() {
  clk_anlik=digitalRead(encoder_clk);
  if(clk_anlik!=clk_ilk){
    if(digitalRead(encoder_dt)!=clk_anlik)enc_deger++;
    else enc_deger--;

    if(enc_deger==-1)enc_deger=259;//acı degerının sadece 0 ve 360 arası olmasını saglıyoruz
    if(enc_deger==360)enc_deger=0;
  
    Serial.print("enkoder degeri:");
    Serial.println(enc_deger);
  }
  
  son_v=analogRead(potansiyon_metre);
  /*voltaj degerini surekli göstermesine negel olmak icin 
  sadece degisimleri gösteriyor*/
  
  if(ilk_v!=son_v){
    float v;//voltaj degeri
    v=son_v*5.0/1023.0;// voltaj sınırı 5 e ayarladık 
    Serial.print("voltaj degeri:");
    Serial.println(v);
  
  }
  ilk_v=son_v;// son voltaj degerını ılk voltaj degerıne aldık
  clk_ilk=clk_anlik;// son clk degerını ılk degere aldık


}
//https://wokwi.com/projects/418144514455562241
