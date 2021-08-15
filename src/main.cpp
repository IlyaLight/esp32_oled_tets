#include <Arduino.h>
#include "display/display.h"
#include "web/web.h"


void setup(){
	setupDisplay();
	display.setTextAlignment(TEXT_ALIGN_CENTER);
	display.setFont(ArialMT_Plain_24);
  	display.drawString(DISPLAY_WIDE/2, 0, "Hello");
	display.setFont(ArialMT_Plain_10);
	display.drawString(DISPLAY_WIDE/2, 26, "connect to wifi");
	display.drawString(DISPLAY_WIDE/2, 38, String("name: ") + SSID);
	display.drawString(DISPLAY_WIDE/2, 48, String("pass: ") + PASSWORD);
	display.display();


	Serial.begin(115200);
  	Serial.println(SSID);

	delay(100);

	WiFi_begin();
  	Serial.println("HTTP server started");
  	delay(100); 
}   


void loop() {
	// demoLoop();
	server_loop();
}
