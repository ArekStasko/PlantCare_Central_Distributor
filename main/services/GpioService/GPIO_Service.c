#include "driver/gpio.h"

#define WATER_PUMP_GPIO GPIO_NUM_25

void WaterPump_Init(void)
{
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << WATER_PUMP_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    gpio_config(&io_conf);

    gpio_set_level(WATER_PUMP_GPIO, 0);
}

void Run_WaterPump(void)
{
    gpio_set_level(WATER_PUMP_GPIO, 1);
}

void Stop_WaterPump(void)
{
    gpio_set_level(WATER_PUMP_GPIO, 0);
}

