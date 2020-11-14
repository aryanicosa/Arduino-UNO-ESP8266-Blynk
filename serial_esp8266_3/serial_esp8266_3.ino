#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

String sensorValue; //menampung nilai potensiometer
char c;

char auth[] = "vw7kdG6tGDTF_HByk-XcEE-WIp-4UbJm"; //ganti tulisan dengan Auth Token yang masuk ke email
char ssid[] = "Redmi123"; //ganti tulisan dengan nama wifi
char pass[] = "aaaaqqqq"; //ganti tulisan dengan password wifi

BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // ketika button di blynk di klik/push, maka akan dikirim nilai ke esp8266
  Serial.print(pinValue); // hanya untuk debugging
}


void sendSensor() {
  Serial.print("r"); //meminta nilai sensor ke arduino dengan mengirim karakter "r"
  delay(100);
  
  while (Serial.available() > 0) {
    delay(10);
    c = Serial.read();
    sensorValue += c; //sensorValue + c
  }

  if (sensorValue.length() > 0) {
    Blynk.virtualWrite(V5, sensorValue);
    delay(10);
    sensorValue = "";
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
  timer.setInterval(3000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
