#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_COUNT 8

// Define GPIO pins for LEDs
const gpio_num_t led_pins[LED_COUNT] = {
    GPIO_NUM_0, GPIO_NUM_1, GPIO_NUM_2, GPIO_NUM_3,
    GPIO_NUM_4, GPIO_NUM_5, GPIO_NUM_6, GPIO_NUM_7
};

void app_main(void) {
    // Configure all LED pins as outputs
    for (int i = 0; i < LED_COUNT; i++) {
        gpio_pad_select_gpio(led_pins[i]);
        gpio_set_direction(led_pins[i], GPIO_MODE_OUTPUT);
    }

    while (1) {
        // Pattern 1: 0b01010101 (LEDs 0,2,4,6 ON)
        for (int i = 0; i < LED_COUNT; i++) {
            gpio_set_level(led_pins[i], (i % 2 == 0) ? 1 : 0);
        }
        vTaskDelay(pdMS_TO_TICKS(500));

        // Pattern 2: 0b10101010 (LEDs 1,3,5,7 ON)
        for (int i = 0; i < LED_COUNT; i++) {
            gpio_set_level(led_pins[i], (i % 2 == 1) ? 1 : 0);
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
