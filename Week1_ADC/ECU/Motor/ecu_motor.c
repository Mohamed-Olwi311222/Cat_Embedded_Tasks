/* 
 * File:   ecu_motor.c
 * Author: Mohamed olwi
 *
 * Created: 04/3/2025 11:00:00 AM
 */
#include "ecu_motor.h"

/**
 * @brief initialize the dc_motor 
 * @param dc_motor the pointer to the dc_motor config @ref dc_motor_t
 * @return E_OK if success otherwise E_NOT_OK 
 */
Std_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;

    if (NULL == dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_direction_initialize(&(dc_motor->dc_motor_pins[DC_MOTOR_PIN1]));
        gpio_pin_direction_initialize(&(dc_motor->dc_motor_pins[DC_MOTOR_PIN2]));
    }
    return (ret);
}

/**
 * @brief make the motor turns
 * @param dc_motor the pointer to the dc_motor config @ref dc_motor_t
 * @return E_OK if success otherwise E_NOT_OK
 */
Std_ReturnType dc_motor_run(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;

    if (NULL == dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_write_logic(&(dc_motor->dc_motor_pins[DC_MOTOR_PIN1]), GPIO_HIGH);
        gpio_pin_write_logic(&(dc_motor->dc_motor_pins[DC_MOTOR_PIN2]), GPIO_LOW);
    }
    return (ret);
}
/**
 * @brief make the motor stop
 * @param dc_motor the pointer to the dc_motor config @ref dc_motor_t
 * @return E_OK if success otherwise E_NOT_OK
 */
Std_ReturnType dc_motor_stop(const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;

    if (NULL == dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_write_logic(&(dc_motor->dc_motor_pins[DC_MOTOR_PIN1]), GPIO_LOW);
        gpio_pin_write_logic(&(dc_motor->dc_motor_pins[DC_MOTOR_PIN2]), GPIO_LOW);
    }
    return (ret);
}