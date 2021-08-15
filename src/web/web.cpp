#include "web.h"
#include "html.h"

#include <WiFi.h>
#include "display/display.h"

WebServer server(80);

IPAddress local_ip, gateway, subnet;
 

void WiFiStationConnected(WiFiEvent_t, WiFiEventInfo_t);
void WiFiStationDisconnected(WiFiEvent_t, WiFiEventInfo_t);
void handle_OnConnect();

void WiFi_begin(){
	local_ip.fromString(LOCAL_IP);
	gateway.fromString(GATEWAY);
	subnet.fromString(SUBNET);

	WiFi.softAP(SSID, PASSWORD);
	WiFi.softAPConfig(local_ip, gateway, subnet);

	WiFi.onEvent(WiFiStationConnected, SYSTEM_EVENT_AP_STACONNECTED);
  	WiFi.onEvent(WiFiStationDisconnected, SYSTEM_EVENT_AP_STADISCONNECTED);
	
	server.on("/", handle_OnConnect);
	server.begin();
}

void server_loop(){
	server.handleClient();
}


void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info) {

  	Serial.println("Connected:");
	display.clear();
  	display.println("Connected:");
  	// что-то делаем, например, вычисляем mac-адрес
  	for (int i = 0; i < 6; i++) {
		char octet[2]; 
		sprintf(octet, "%02X", info.sta_disconnected.mac[i]);
    	display.print(octet);
		Serial.print(octet);
    	if (i < 5) {
			Serial.print(":");
			display.print(":");
		}
	  }
  	Serial.println();
	Serial.print("open ");
	Serial.println(LOCAL_IP);
	Serial.println("\n------------------");
	display.println();
	display.print("open ");
	display.println(LOCAL_IP);
	display.drawLogBuffer(0, 0);
	display.display();
}


void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info) {
	Serial.println("Disconnected:");
	display.clear();
  	display.println("Disconnected:");
  	// что-то делаем, например, снова вычисляем mac-адрес
  	for (int i = 0; i < 6; i++) {
    	char octet[2]; 
		sprintf(octet, "%02X", info.sta_disconnected.mac[i]);
    	display.print(octet);
		Serial.print(octet);
    	if (i < 5) {
			Serial.print(":");
			display.print(":");
		}
  	}
	Serial.println("\n------------------");
	display.drawLogBuffer(0, 0);
	display.display();
}


void handle_OnConnect(){
	String html = FPSTR(HEAD_HTMLPAGE);
    html += FPSTR(BODY_SETTINGS_HTMLPAGE);
  	Serial.println(">set wifi page");
  	server.send(200, "text/html", html); 
}