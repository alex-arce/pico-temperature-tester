#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "pico/binary_info.h" 

const uint LED_PIN = 25; 

int main() {

    bi_decl(bi_program_description("Temperature Tester project"));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"))

    stdio_init_all();
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
        
    while(1){
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        gpio_put(LED_PIN, 1);
	
	uint32_t result = adc_read();
        const float conversion_factor = 3.3f / (1 << 12);
	float converted_result = result * conversion_factor;
	float result_temp = 27.0f - (converted_result - 0.706) / 0.001721;
        printf("Temperature: %f C\n", result, result_temp);
                
        sleep_ms(500);
    }
}
