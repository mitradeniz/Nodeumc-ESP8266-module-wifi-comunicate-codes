/*
  Project Description:
  This code is part of a project that involves interfacing an ESP8266 module with a PIR motion sensor to detect motion. The ESP8266 connects to a Wi-Fi network and communicates with a server to transmit motion data. This code establishes a connection to the server using Wi-Fi, reads data from the PIR sensor, and sends motion information to the server.

  Libraries Used:
  - ESP8266WiFi: Used to handle Wi-Fi connectivity and communication.
  
  Hardware Setup:
  - Connect the PIR motion sensor to the digital pin D0 of the ESP8266.
  
  Notes:
  - Replace "--SSID--" and "*********" with your Wi-Fi network SSID and password.
  - Modify "serverIP" with the IP address of the server where motion data will be sent.
  - The server should be listening on port 8080 for incoming connections.
  - When motion is detected, the LED connected to pin D0 is turned on, and the code sends '1' to the server.
  - When no motion is detected, the LED is turned off, and the code sends '0' to the server.
  - Responses from the server are displayed on the serial monitor.

  Author: [Your Name]
  GitHub Repository: [Provide the GitHub repository URL]
*/

#include <ESP8266WiFi.h>

const char* ssid = "--SSID--";
const char* password = "*********";
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
    Serial.println("Waiting for Wi-Fi connection...");
  
  }
  Serial.println("Wifi connected.");

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
