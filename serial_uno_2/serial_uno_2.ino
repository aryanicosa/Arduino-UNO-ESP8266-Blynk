#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

String data;
char c;

const int led = 13;
int pot = A0;
int valPot;
int val;

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
  pinMode(led, OUTPUT);
  delay(10);
}

void loop() {

  while (mySerial.available() > 0) {
    delay(10);
    c = mySerial.read();
    data += c;
  }

  if (data.length() > 0) {
    Serial.println(data);
    if (data == "1") {
      digitalWrite(led, HIGH);
      Serial.println("led ON");
    }
    else if (data == "0") {
      digitalWrite(led, LOW);
      Serial.println("led OFF");
    }
    else if (data == "r") {
      valPot = analogRead(pot);
      mySerial.print(valPot);
      Serial.println(valPot);
    }

    data = "";

  }

}
