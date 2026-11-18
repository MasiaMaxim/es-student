#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"



const uint LED_PIN = 25;
const uint BUTTON_PIN = 15;
const uint DEBOUNCE_MS = 20;

bool get_button_debounce(uint pin)
{
    bool state = gpio_get(pin);
    sleep_ms(DEBOUNCE_MS);
    return state && gpio_get(pin);
}

int main()
{
    stdio_init_all();

    while (1)
    {
        printf("Hellow, world!\n");
        sleep_ms(1000);
    }
}