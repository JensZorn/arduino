// Ampel
int rot = 8;
int gelb = 9;
int gruen = 10;
int taster = 7;
int fussrot = 5;
int fussgruen = 6;
unsigned long start;
unsigned long ende;


void setup() {
//Ampel
pinMode(rot, OUTPUT);
pinMode(gelb, OUTPUT);
pinMode(gruen, OUTPUT);
pinMode(fussrot, OUTPUT);
pinMode(fussgruen, OUTPUT);
pinMode(taster, INPUT);
}


void loop() {
  // Ampelphasen
  if (digitalRead(taster)) {
    AmpelPhase(false);
  }else{
  AmpelPhase(true);
  }
}

void AmpelPhase(bool isloop) {
  if (isloop) {
    if (millis() >= ende){
    // Standard
    ChangeAmpelPhase(rot, false, gelb, false, gruen, true, fussrot, true, fussgruen, false);
    } else if ((start + 1000) <= millis() && millis() < (start + 2000)){
    // Auto grün auf gelb
    ChangeAmpelPhase(rot, false, gelb, true, gruen, false, fussrot, true, fussgruen, false);
    } else if ((start + 2000) <= millis() && millis() < (start + 3000)){
    //Auto gelb auf rot
    ChangeAmpelPhase(rot, true, gelb, false, gruen, false, fussrot, true, fussgruen, false);
    } else if ((start + 3000) <= millis() && millis() < (start + 4000)){
    //Auto rot, Fussgänger auf grün
    ChangeAmpelPhase(rot, true, gelb, false, gruen, false, fussrot, false, fussgruen, true);
    } else if ((start + 4000) <= millis() && millis() < (start + 5000)){
    //Auto rot, Fussgänger auf rot
    ChangeAmpelPhase(rot, true, gelb, false, gruen, false, fussrot, true, fussgruen, false);
    } else if ((start + 5000) <= millis() && millis() < ende){
    //Auto rot auf gelb
    ChangeAmpelPhase(rot, true, gelb, true, gruen, false, fussrot, true, fussgruen, false);
    }
  }else if (!isloop) {
      start = millis();
      ende = start + 6000;
      Serial.println(start);
  }
}

void ChangeAmpelPhase(int rot, bool rotb, int gelb, bool gelbb, int gruen, bool gruenb, int fussrot, bool fussrotb, int fussgruen, bool fussgruenb) {
  digitalWrite(rot, rotb);
  digitalWrite(gelb, gelbb);
  digitalWrite(gruen, gruenb);
  digitalWrite(fussrot, fussrotb);
  digitalWrite(fussgruen, fussgruenb);
}