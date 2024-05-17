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



void app_main(void)
{

}
