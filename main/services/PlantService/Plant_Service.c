#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"
#include "Plant_Service.h"
#include "GPIO_Service.h"
#include "NVS_Service.h"

int perform_water_supply(int plantId)
{
    if (plantId == -1) return -1;

    Run_WaterPump();
    vTaskDelay(pdMS_TO_TICKS(10000));
    Stop_WaterPump();

    return 1;
}

void process_executed_water_supply(int status_id, int status_code)
{
    if(status_code == 200)
    {
        savePlantId("-1");
    }
    else
    {
        savePlantId((char)(status_id));
    }
}

bool verify_awaiting_water_supply(int status_id)
{
  char saved_status_id = getStatusId();
  if(saved_status_id == -1)
  {
    return false;
  }

  return status_id == saved_status_id;
}
