#ifndef WEB_H_
#define WEB_H_
#include <WebServer.h>




#define SSID "ESP32-AP"
#define PASSWORD ""

#define LOCAL_IP "192,168,1,1"
#define GATEWAY "192,168,1,1"
#define SUBNET "255,255,255,0"



void WiFi_begin(void);
void server_loop(void);

#endif