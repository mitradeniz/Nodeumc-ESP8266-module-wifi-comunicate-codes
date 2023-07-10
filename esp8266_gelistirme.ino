#include <ESP8266WiFi.h>

const char* ssid = "Zeynel";
const char* password = "mitradeniz63";

int led = D0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Wifi baglantisi bekleniyor...");
  
  }
  Serial.println("Wifi baglandii.");
}

void loop() {
    if (Serial.available()) {
      int data = Serial.read();
      if (data == '1') {
        digitalWrite(led, HIGH);
        Serial.println("Hareket algılandı!");
        
      } else if (data == '0') {
        digitalWrite(led, LOW);
        Serial.println("Hareket yok!");
      }
      delay(100);
  }
}
