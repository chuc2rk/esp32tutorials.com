#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN 3

void app_main(void)
{
    gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN; GPIO_MODE_OUTPUT);

    int toggle;
    while (true)
    {
        toggle = !toggle;
        gpio_set_level(LED_PIN, toggle);
        vTaskDelay(1000 / portTICK_RATE_MS)
    }
    
}
