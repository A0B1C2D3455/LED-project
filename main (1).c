#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sra_board.h"

void app_main() {
    // Enable the bar graph GPIOs
    ESP_ERROR_CHECK(enable_bar_graph());

    // Defining two patterns:- even-position LEDs ON, odd OFF which continues indefinitely.
    uint8_t even_pattern = 0b01010101; // LED7 to LED0: 0 1 0 1 0 1 0 1 (even positions ON)
    uint8_t odd_pattern  = 0b10101010; // LED7 to LED0: 1 0 1 0 1 0 1 0 (odd positions ON)

    
    while (1) //pattern continues indefinitely.
        
        {

        // Set even-position LEDs ON
        ESP_ERROR_CHECK(set_bar_graph(even_pattern));
        vTaskDelay(500 / portTICK_PERIOD_MS);  // 500ms delay

        // Set odd-position LEDs ON
        ESP_ERROR_CHECK(set_bar_graph(odd_pattern));
        vTaskDelay(500 / portTICK_PERIOD_MS);  // 500ms delay

    }
}