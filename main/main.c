#include <stdio.h>

//incluir librerias gestión gpio
#include "driver/gpio.h"

//incluir libreria gestión de tiempos sincronos
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//datos control led
struct led
{
    int pin;
    int valorLed;
};

//declaramos led1
struct led led1 = {2, 0};

//funciones a utilizar
esp_err_t initLed(void);
esp_err_t blinkLed(void);


void app_main(void)
{
    initLed();
    while(true)
    {
        blinkLed();
        printf("estado led %d", led1.valorLed);
    }
}


esp_err_t initLed(void)
{
    gpio_set_direction(led1.pin, GPIO_MODE_OUTPUT);
    return ESP_OK;
}
esp_err_t blinkLed(void)
{
    vTaskDelay(500 / portTICK_PERIOD_MS);
    led1.valorLed = !led1.valorLed;
    gpio_set_level(led1.pin, led1.valorLed);
    return ESP_OK;

}