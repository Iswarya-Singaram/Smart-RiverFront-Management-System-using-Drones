/*
  Water Quality Monitor with ESP32 and Flask
  This code sends sensor data via an HTTP POST request to a local Flask server.

  HARDWARE CONNECTIONS:
  - DS18B20 Data Pin -> GPIO 4
  - TDS Sensor Analog Out -> GPIO 34
  - Turbidity Sensor Analog Out -> GPIO 35
*/

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h> // For creating the JSON payload

// Sensor Libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// --- IMPORTANT: USER CONFIGURATION ---
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

// The IP address of the computer running the Flask server.
// Find this using 'ipconfig' (Windows) or 'ifconfig'/'ip a' (Mac/Linux).
#define SERVER_IP "192.168.1.10" // <-- CHANGE THIS
#define SERVER_PORT 5000

// --- Pin Definitions ---
#define DS18B20_PIN 4
#define TDS_PIN 34
#define TURBIDITY_PIN 35

// --- Sensor Calibration ---
#define TDS_FACTOR 235.0

// --- Sensor Objects ---
OneWire oneWire(DS18B20_PIN);
DallasTemperature sensors(&oneWire);

unsigned long lastSendTime = 0;
const long sendInterval = 5000; // 5 seconds

void setup() {
  Serial.begin(115200);
  Serial.println("\nESP32 Water Quality Monitor (Flask Client)");

  // -- WiFi Connection --
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Target Server: http://");
  Serial.print(SERVER_IP);
  Serial.print(":");
  Serial.println(SERVER_PORT);
  
  // -- Sensor Initialization --
  sensors.begin();
  analogSetPinAttenuation(TDS_PIN, ADC_11db);
  analogSetPinAttenuation(TURBIDITY_PIN, ADC_11db);
  
  Serial.println("Initialization Complete. Starting sensor readings.");
}

void loop() {
  if (millis() - lastSendTime > sendInterval) {
    lastSendTime = millis();

    // --- Read Sensor Data ---
    float tempC = readTemperature();
    float tdsValue = readTDS(tempC);
    float turbidityValue = readTurbidity();
    float phValue = readPH();

    if (tempC == -127.0) {
        Serial.println("Failed to read temperature sensor. Skipping.");
        return;
    }

    // --- Create JSON Payload ---
    StaticJsonDocument<200> jsonDoc;
    jsonDoc["temperature"] = tempC;
    jsonDoc["tds"] = tdsValue;
    jsonDoc["turbidity"] = turbidityValue;
    jsonDoc["ph"] = phValue;

    String jsonString;
    serializeJson(jsonDoc, jsonString);

    // --- Send Data to Flask Server ---
    sendDataToServer(jsonString);
  }
}

void sendDataToServer(String jsonPayload) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String serverPath = "http://" + String(SERVER_IP) + ":" + String(SERVER_PORT) + "/data";
    
    http.begin(serverPath);
    http.addHeader("Content-Type", "application/json");

    Serial.print("Sending data: ");
    Serial.println(jsonPayload);
    
    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi Disconnected. Cannot send data.");
  }
}


// --- Sensor Reading Functions (copied from previous version) ---
float readTemperature() {
  sensors.requestTemperatures(); 
  float temp = sensors.getTempCByIndex(0);
  if(temp == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Could not read temperature data");
    return -127.0;
  }
  return temp;
}

float readVoltage(int pin){
  int raw = analogRead(pin);
  if (raw > 4095) raw = 4095;
  return raw * (3.3 / 4095.0);
}

float readTDS(float tempC) {
  float voltage = readVoltage(TDS_PIN);
  if (voltage < 0.1) return 0.0;
  float tdsRaw = voltage * TDS_FACTOR;
  float tdsCompensated = tdsRaw / (1.0 + 0.02 * (tempC - 25.0));
  return tdsCompensated > 0 ? tdsCompensated : 0;
}

float readTurbidity() {
  float voltage = readVoltage(TURBIDITY_PIN);
  float voltage_clean_water = 2.5;
  float ntu = -1000 * voltage + (1000 * voltage_clean_water);
  if (ntu < 0) ntu = 0;
  return ntu;
}

float readPH() {
  float simulatedPH = 5.0 + (float)random(0, 150) / 100.0;
  return simulatedPH;
}
