char tabla[]={'-','-','-','-','-','-','-','-','-'};

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
}

void loop() {
  Serial.println("Salut!");
  Serial.println("Tu vei muta primul - esti cu X.");
  Serial.println("Tabla de joc are pozitiile numerotate de la 1 la 9.");
  Serial.println("1 2 3");
  Serial.println("4 5 6");
  Serial.println("7 8 9");
  do {
  mutareX();
  if (victorie()) break;
  mutare0();
  afisare();
  } while (!victorie());
  delay(5000);
  for (int i=0; i<100; i++) Serial.println();
  for (int i=0; i<9; i++) tabla[i]='-';
}

boolean victorie() {
    char winner = '-';
    if (winner=='-' && tabla[0]==tabla[1] && tabla[1]==tabla[2]) winner=tabla[0]; // linie 1
    if (winner=='-' && tabla[3]==tabla[4] && tabla[4]==tabla[5]) winner=tabla[3]; // linie 2
    if (winner=='-' && tabla[6]==tabla[7] && tabla[7]==tabla[8]) winner=tabla[6]; // linie 3
    if (winner=='-' && tabla[0]==tabla[3] && tabla[3]==tabla[6]) winner=tabla[0]; // coloana 1
    if (winner=='-' && tabla[1]==tabla[4] && tabla[4]==tabla[7]) winner=tabla[1]; // coloana 2
    if (winner=='-' && tabla[2]==tabla[5] && tabla[5]==tabla[8]) winner=tabla[2]; // coloana 3
    if (winner=='-' && tabla[0]==tabla[4] && tabla[4]==tabla[8]) winner=tabla[0]; // diagonala
    if (winner=='-' && tabla[2]==tabla[4] && tabla[4]==tabla[6]) winner=tabla[2]; // diagonala
    if (winner =='-') {
        winner = '*';
    for (int i=0; i<9; i++)
        if (tabla[i]=='-') winner='-'; }
        if (winner=='-') return false;
        else {
        if (winner == 'X') {
        digitalWrite(8,HIGH);
        afisare();
        Serial.println("Ati castigat! Felicitari!");
        }
    if (winner == '0') Serial.println("Arduino a castigat! Mai incercati!");
    if (winner == '*') Serial.println("Remiza! Plictisitor!");
    return true;
    }
}

void afisare() {
  for (int i=0; i<9; i++) {
    Serial.print(tabla[i]);
    Serial.print(" ");
    if (i==2 || i==5 || i==8) Serial.println();}
}

void mutareX() {
  boolean valid = false;
  int m0 = 0;

  while (!valid) {
    
    Serial.println("Alege o pozitie de la 1 la 9.");
    while (m0<'1' || m0>'9') {
      m0 = Serial.read();
      delay(1000);}
      m0 = m0 - 48;
      Serial.print("Ati ales pozitia: ");
      Serial.print(m0,DEC);
      Serial.println();
      if (tabla[m0-1]!='-')
        Serial.println("Pozitie eronata!");
      else {
      tabla[m0-1]='X';
      valid = true;}
 }
}
void mutare0() {
  int i=-1;
  while (i==-1) {
    i = random(0,9);
    if (tabla[i]=='-') {
      tabla[i]='0';
      Serial.print("Arduino a ales pozitia: ");
      Serial.print(i+1,DEC);
      Serial.println();
      break;
    }
    else i=-1;
 }
}

