#include <EEPROM.h>
#include <ArduinoJson.h>

// Define relay pins from 22 to 53
const int relayPins[] = {
  22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
  36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
  50, 51, 52, 53
};

#define EEPROM_ADDRESS_START 0

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

  // Initialize relay pins as outputs
  for (int i = 0; i < 32; i++) {
    pinMode(relayPins[i], OUTPUT);
  }

  // Read relay statuses from EEPROM and set relay states
  for (int i = 0; i < 32; i++) {
    int address = EEPROM_ADDRESS_START + i;
    int relayStatus = EEPROM.read(address);
    digitalWrite(relayPins[i], relayStatus);
  }

  // Clear any initial data from Serial1 buffer
  while (Serial1.available()) {
    String info = Serial1.readStringUntil('\n');
    Serial.println(info);
  }
}

void loop() {
  if (Serial1.available()) {
    String jsonStr = Serial1.readStringUntil('\n');
    Serial.println(jsonStr);

    DynamicJsonDocument doc(2048);
    deserializeJson(doc, jsonStr);

    // Iterate through the relays and update states based on JSON
    for (int i = 0; i < 32; i++) {
      String pinName = "p" + String(i + 1);
      if (doc.containsKey(pinName)) {
        int relayValue = doc[pinName];
        digitalWrite(relayPins[i], !relayValue); // Assuming active LOW relays

        int address = EEPROM_ADDRESS_START + i;
        EEPROM.write(address, !relayValue); // Save the relay state in EEPROM
      }
    }
  }
}
