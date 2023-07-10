#include <ESP8266WiFi.h>

const char* ssid = "Zeynel";
const char* password = "mitradeniz63";
const char* serverIP = "192.168.1.15";
const int serverPort = 8080;

WiFiClient client;

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

  Serial.print("IP Adresi: ");
  Serial.println(WiFi.localIP());


  
}

void loop() {
    if (Serial.available()) { // hareket verisi var ise 
      if (client.connect(serverIP, serverPort)) { // wifi ip ve port bağlantısı sağlanıyorsa
        int data = Serial.read();   // pir sensorunden gelen veriyi oku
        if (data == '1') {
          digitalWrite(led, HIGH);
          client.println('1');      // '1' verisini 8080 portunda yayınla
          
        } else if (data == '0') {
          digitalWrite(led, LOW);
          client.println('0');
        }
      // Sunucu response varsa al
      while (client.available()) {
        String response = client.readStringUntil('\n');
        Serial.println("Sunucu yaniti: " + response);
      }
      
      // Soketi durdur
      client.stop();
    }
    
    delay(1000);
  }
}
