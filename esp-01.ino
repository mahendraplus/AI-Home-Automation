#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

// Wi-Fi configuration
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Firebase configuration
#define FIREBASE_HOST "FIREBASE_HOST"
#define FIREBASE_AUTH "DATABASE_SECRETS_KEY"

FirebaseData firebaseData;
FirebaseData streamData;

unsigned long lastPingTime = 0;
const unsigned long pingInterval = 5000; 

void streamCallback(StreamData data);
void streamTimeoutCallback(bool timeout);

void setup() {

  Serial.begin(115200);
  Serial1.begin(115200);  

  connectToWiFi();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

delay(15000); 
  if (!Firebase.beginStream(streamData, "/ai-home-esp/pins")) {
    Serial.println("Could not begin stream");
    Serial.println("REASON: " + streamData.errorReason());
  }

  Firebase.setStreamCallback(streamData, streamCallback, streamTimeoutCallback);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectToWiFi();
  }

  delay(10); 
  
}

void connectToWiFi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("Connecting...");
  }

  Serial.println("Connected to WiFi");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
}

void streamCallback(StreamData data) {
  Serial.println(data.jsonString());
 Serial1.println(data.jsonString());
  
}

void streamTimeoutCallback(bool timeout) {
  if (timeout) {
    Serial.println("Stream timeout, resuming...");
    if (!Firebase.beginStream(streamData, "/ai-home-esp/pins")) {
      Serial.println("Could not resume stream");
      Serial.println("REASON: " + streamData.errorReason());
    }
  }
}
