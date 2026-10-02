#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "NVS_Service.h"
#include "Bluetooth_Service.h"
#include "WIFI_Service.h"
#include "esp_log.h"
#include "esp_event.h"
#include "GPIO_Service.h"

void app_main(void)
{
    nvs_flash_init();
    bool isWifiDataExist = checkIfWiFiDataExists();
    if (!isWifiDataExist)
    {
        enable_bt();
    }
    if(isWifiDataExist)
    {
      WaterPump_Init();
      connect_to_wifi();
    }
}