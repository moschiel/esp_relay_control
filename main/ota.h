#ifndef MAIN_OTA_H_
#define MAIN_OTA_H_


#include "esp_http_server.h"

void start_ota(char* url);
void send_ws_ota_status(char* msg, bool done, bool isError, uint8_t percent);

#endif /* MAIN_OTA_H_ */
