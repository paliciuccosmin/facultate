#include <LiquidCrystal.h>

// initializarea librarei cu pinii conectati la arduino
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define relay 10
int LED = 3;
int LDR = A0;

void setup() {  
  pinMode(LED,OUTPUT);//setare ca pin de iesire
  pinMode(relay,OUTPUT);//setare ca pin de iesire
  pinMode(LDR,INPUT);//setare ca pin de intrare
  // setarea dimensiunilor display ului
   lcd.begin(16, 2);
}
void loop(){
  //colectarea valorii fotorezistentei
  int LDRValue=analogRead(LDR);
  //calculeaza procentul din range ul valorii masurate de la fotorezistor
  int lightIntensity = map(LDRValue, 0, 1023, 0, 100);
  lcd.clear();
  /*Acest bloc de cod verifica dacă valoarea citita de la senzorul LDR este mai 
  mica sau egala cu 700,ceea ce ar putea indica ca este noapte sau lumina redusa*/
  if(LDRValue<=700)
  {
    digitalWrite(LED,HIGH);
    digitalWrite(relay,HIGH);
    lcd.print("Night: Light ON");
  }
  else
  {
    digitalWrite(LED,LOW);
    digitalWrite(relay,LOW);
    lcd.print("Day: Light OFF");
  }
  //printeza procentul intensitatii luminii 
  lcd.setCursor(0, 1);
  lcd.print("Light inten: " + String(lightIntensity) + "%");

  delay(1000);

}