// Simple button-monitor including debounce and multiple actions based on time.
#define skippin 2

unsigned long starttijd;
unsigned long wachttijd;
boolean opletten;

void setup() {
  Serial.begin(115200);
  pinMode(skippin, INPUT_PULLUP);
}

void loop() {
  if (opletten == LOW) {
    if (digitalRead(skippin) == 0) {
      starttijd = millis();
      opletten = HIGH;
    }
  } else {
    if (digitalRead(skippin) == 1) {
      opletten = LOW;
    } else {
      wachttijd = millis() - starttijd ;
    }
  }

  if (wachttijd > 3000) {
    Serial.println("Randomize!");
    wachttijd = 0;
    opletten = LOW;
    delay(500);
  }

  if (opletten == LOW && wachttijd > 25) {
    Serial.print("Skip! ");
    Serial.print(wachttijd);
    Serial.println(" ms");
    wachttijd = 0;
  }

}
