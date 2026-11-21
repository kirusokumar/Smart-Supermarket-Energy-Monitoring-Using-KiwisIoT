#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define CURRENT_PIN A0

const float VOLTAGE = 230.0;

// Example ACS712-5A sensitivity: 0.185 V/A
const float SENSITIVITY = 0.185;

// Calibrate this value using your sensor at zero current
float zeroVoltage = 2.50;

void setup() {
  Serial.begin(115200);

  Serial.println("Smart Supermarket Energy Monitoring");

  kiwisiot.begin();
}

void loop() {
  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {
    lastSend = millis();

    int rawValue = analogRead(CURRENT_PIN);

    // ESP8266 A0 input voltage range depends on board design.
    // Ensure the sensor output is compatible with your board.
    float adcVoltage = rawValue * (1.0 / 1023.0);

    float current = abs((adcVoltage - zeroVoltage) / SENSITIVITY);

    float power = VOLTAGE * current;

    Serial.println("---------------------------");

    Serial.print("ADC Value: ");
    Serial.println(rawValue);

    Serial.print("Estimated Current: ");
    Serial.print(current, 2);
    Serial.println(" A");

    Serial.print("Estimated Power: ");
    Serial.print(power, 2);
    Serial.println(" W");

    kiwisiot.send("0", String(current, 2));
    kiwisiot.send("1", String(power, 2));
  }
}