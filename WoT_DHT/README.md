# Web Of Things

## Introduction
The Web of Things is a refinement of the Internet of Things by integrating smart things not only into the Internet (network), but into the Web Architecture (application).
* [Introduction to Web of Things](https://code.swecha.org/sriharshamvs/iot_curriculum/blob/master/Presentations/Intro_to_WebOfThings.pdf)
## Prerequisites
* Knowledge on Arduino Programming
* Hardware Components
	* NodeMCU
	* Raspberry Pi 3 Model B+
	* DHT Sensor
	* LED
	* Connecting Wires
	* Breadboard

## Preparing Gateway
* We will be using [Mozilla WebThings Gateway](https://iot.mozilla.org/) for this demo
* Follow this [Demo](https://iot.mozilla.org/docs/gateway-getting-started-guide.html) and setup the Gateway

## Installing PlatformIO
* First Install an open source IDE like [Atom](https://atom.io/)
* Then to install PlatformIO follow this [link](https://platformio.org/install)
* Once it is setup test the Environment by following this [blog](https://www.losant.com/blog/getting-started-with-platformio-esp8266-nodemcu)

## Testing the Code
* Install __webthing-arduino__ with latest version and __ArduinoJson__ with version *5.13.x* (Since there are compatible issues) for Web of Things libraries
* Install __SimpleDHT__ for DHT libraries
* There are two projects in this repo
	* WoT_Blink
	* WoT_DHT
* Navigate to *src/main.cpp* in __WoT_Blink__ and __WoT_DHT__
* Change the *ssid* and *password* to connect the NodeMCU to the same network that the *Gateway* is connected
* Upload Individual Project and check for the device in the Gateway
* For WoT_Blink Toggle the LED in from the __Things Dashboard__
* For WoT_DHT Check the Temperature and Humidity values in __Things Dashboard__

#### Voila we have just implemented Web of Things :smiley:
