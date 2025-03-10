/* 
* File:   main.c
* Author: Mohamed olwi
*
* Created: 07/3/2025 8:15:00 AM
*/
#include "main.h"


/**
 * @brief Main function
 */
int main(void)
{
    Std_ReturnType ret_val = E_OK;
    uint16 adc_res = 0;
    usart_t usart_obj = {
        .usart_baudrate = 9600,
        .usart_parity = USART_PARITY_DISABLED,
        .usart_mode = ASYNC_USART,
        .usart_char_size = USART_8_BIT_CHAR_SIZE,
        .usart_transmitter_enable = _USART_TRANSMITTER_ENABLE,
        .usart_transmitter_clk_polarity = _USART_TRANSMIT_POLARITY_RISING_EDGE,
        .usart_transmiter_stop_bits_number = _USART_TRANSMITTER_STOP_BITS_1_BIT,
        .usart_transmitter_transmission_speed = _USART_TRANSMIT_NORMAL_SPEED_MODE
    };

    ret_val |= usart_init(&usart_obj);
    adc_init(ADC_REF_AVCC);
    adc_enable_channel(ADC0);
    adc_pin_select(ADC0);
    sei(); //enable interrupts for adc conversion
	while(1)
    {
        adc_convert(&adc_res);
        adc_res = ((adc_res * VREF) / (MAX_ADC)) / MV_PER_DEGREE;
        usart_write_data(adc_res);
        _delay_ms(100);
    }
    return (ret_val);
}
