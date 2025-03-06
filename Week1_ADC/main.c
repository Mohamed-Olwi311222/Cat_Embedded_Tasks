/* 
 * File:   main.c
 * Author: Mohamed olwi
 *
 * Created: 04/3/2025 11:00:00 AM
 */ 
#include "main.h"


/**
 * @brief Main function
 * @return E_OK if success otherwise E_NOT_OK
 */
Std_ReturnType main(void)
{
    Std_ReturnType ret_val = E_OK;
    uint8 key = 0;
    uint8 i = 0;
    uint16 adc_res = 0;
    dc_motor_t  dc_motor_1 = {
        .dc_motor_pins[DC_MOTOR_PIN1].port = PORTB_INDEX,
        .dc_motor_pins[DC_MOTOR_PIN1].pin = GPIO_PIN0,
        .dc_motor_pins[DC_MOTOR_PIN1].direction = GPIO_DIRECTION_OUTPUT,
        .dc_motor_pins[DC_MOTOR_PIN2].port = PORTB_INDEX,
        .dc_motor_pins[DC_MOTOR_PIN2].pin = GPIO_PIN1,
        .dc_motor_pins[DC_MOTOR_PIN2].direction = GPIO_DIRECTION_OUTPUT
    };
    dc_motor_t  dc_motor_2 = {
        .dc_motor_pins[DC_MOTOR_PIN1].port = PORTB_INDEX,
        .dc_motor_pins[DC_MOTOR_PIN1].pin = GPIO_PIN2,
        .dc_motor_pins[DC_MOTOR_PIN1].direction = GPIO_DIRECTION_OUTPUT,
        .dc_motor_pins[DC_MOTOR_PIN2].port = PORTB_INDEX,
        .dc_motor_pins[DC_MOTOR_PIN2].pin = GPIO_PIN3,
        .dc_motor_pins[DC_MOTOR_PIN2].direction = GPIO_DIRECTION_OUTPUT
    };

    adc_init(ADC_REF_AVCC);
    adc_enable_channel(ADC0);
    adc_pin_select(ADC0);
    ret_val |= dc_motor_initialize(&dc_motor_1);
    ret_val |= dc_motor_initialize(&dc_motor_2);
    sei(); //enable interrupts for adc conversion
	while(1)
    {
        adc_convert(&adc_res);
        adc_res = ((adc_res * VREF) / (MAX_ADC)) / MV_PER_DEGREE;
        if (adc_res > 40)
        {
            dc_motor_run(&dc_motor_1);
            dc_motor_run(&dc_motor_2);

        }
        else
        {
            dc_motor_stop(&dc_motor_1);
            dc_motor_stop(&dc_motor_2);
        }
    }
    return (ret_val);
}
