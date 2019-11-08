/**
 * Simple server compliant with Mozilla's proposed WoT API
 * Originally based on the HelloServer example
 * Tested on ESP8266, ESP32, Arduino boards with WINC1500 modules (shields or
 * MKR1000)
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <Arduino.h>
#include "Thing.h"
#include "WebThingAdapter.h"
#include "SimpleDHT.h"

//TODO: Hardcode your wifi credentials here (and keep it private)
const char* ssid = "ssid";
const char* password = "password";


const int pinDHT11 = D2;  // manully configure LED pin
SimpleDHT11 dht11(pinDHT11);

WebThingAdapter* adapter;

const char* ledTypes[] = {"TemperatureProperty", "HumidityProperty",nullptr};
ThingDevice device("TempSensor", "Temperature Sensor", ledTypes);
ThingProperty property("TEMP", "Temperature", NUMBER, "TemperatureProperty");
ThingProperty property1("HUMID", "Humidity", NUMBER, "HumidityProperty");

bool lastOn = false;

void setup(void){
  pinMode(pinDHT11, INPUT);
 // digitalWrite(ledPin, HIGH);
  Serial.begin(115200);
  Serial.println("");
  Serial.print("Connecting to \"");
  Serial.print(ssid);
  Serial.println("\"");
#if defined(ESP8266) || defined(ESP32)
  WiFi.mode(WIFI_STA);
#endif
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  bool blink = true;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    //digitalWrite(ledPin, blink ? LOW : HIGH); // active low led
    blink = !blink;
  }
  //digitalWrite(ledPin, HIGH); // active low led

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  adapter = new WebThingAdapter("temp", WiFi.localIP());

  device.addProperty(&property);
  device.addProperty(&property1);
  adapter->addDevice(&device);
  adapter->begin();
  Serial.println("HTTP server started");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.print("/things/");
  Serial.println(device.id);
}

void loop(void){
  float temperature = 0;
  float humidity = 0;
  dht11.read2(&temperature, &humidity, NULL);

  Serial.print("Temperature: ");
  Serial.println((float)temperature);
  Serial.print("Humidity: ");
  Serial.println((float)humidity);

  ThingPropertyValue levelValue;
  levelValue.number = temperature;
  property.setValue(levelValue);
  adapter->update();

  ThingPropertyValue levelValue1;
  levelValue1.number = humidity;
  property1.setValue(levelValue1);
  adapter->update();

  delay(2500);
}
