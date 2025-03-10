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
    uint16 usart_received_data = 0;
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
    usart_t usart_obj = {
        .usart_baudrate = 9600,
        .usart_parity = USART_PARITY_DISABLED,
        .usart_mode = ASYNC_USART,
        .usart_char_size = USART_8_BIT_CHAR_SIZE,
        .usart_receiver_enable = _USART_RECEIVER_ENABLE,
        .usart_receiver_clk_polarity = _USART_RECEIVE_POLARITY_FALLING_EDGE,
        .usart_transmitter_enable = _USART_TRANSMITTER_DISABLE,
        .usart_transmitter_clk_polarity = _USART_TRANSMIT_POLARITY_RISING_EDGE,
        .usart_transmiter_stop_bits_number = _USART_TRANSMITTER_STOP_BITS_1_BIT,
        .usart_transmitter_transmission_speed = _USART_TRANSMIT_NORMAL_SPEED_MODE
    };

    ret_val |= dc_motor_initialize(&dc_motor_1);
    ret_val |= dc_motor_initialize(&dc_motor_2);
    ret_val |= usart_init(&usart_obj);
	while(1)
    {
        usart_read_data((uint8 *)&usart_received_data);
        if (usart_received_data > 40)
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