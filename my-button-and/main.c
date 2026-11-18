#include "pico/stdlib.h"
#include "hardware/gpio.h"


const uint LED_PIN = 25;
const uint BUTTON_PIN1 = 15;
const uint BUTTON_PIN2 = 14;

int main()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN1);
    gpio_set_dir(BUTTON_PIN1, GPIO_IN);
    gpio_pull_up(BUTTON_PIN1);
    gpio_init(BUTTON_PIN2);
    gpio_set_dir(BUTTON_PIN2, GPIO_IN);
    gpio_pull_up(BUTTON_PIN2);

    bool led = false;
    bool previous1 = false;
    bool previous2 = false;
    bool current1 = gpio_get(BUTTON_PIN1);
    bool current2 = gpio_get(BUTTON_PIN2);


    while (1)
    {
        current1 = gpio_get(BUTTON_PIN1);
        current2 = gpio_get(BUTTON_PIN2);

        if (current1 != previous1 || current2 != previous2)
        {
            if (current1 == false && current2 == false)
            {
                led = true;
            } else {
                led = false;
            }
        }
        gpio_put(LED_PIN, led);
        previous1 = current1;
        previous2 = current2;
    }
}