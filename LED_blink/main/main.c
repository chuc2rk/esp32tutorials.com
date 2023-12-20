#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static TaskHandle_t receiver_handler = NULL;

void sender(void* params)
{
    while (true)
    {
        xTaskNotifyGive(receiver_handler);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
    
}

void receiver(void* params)
{
    while (true)
    {
        ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
        printf("received notification\n");
    }
    
}

void app_main(void)
{
    xTaskCreate(&receiver, "sender", 2048, NULL, 2, &receiver_handler);
    xTaskCreate(&sender, "receiver", 2048, NULL, 2, NULL);    
}
