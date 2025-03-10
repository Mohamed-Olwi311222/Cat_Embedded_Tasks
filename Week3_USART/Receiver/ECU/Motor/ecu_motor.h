/* 
 * File:   ecu_motor.h
 * Author: Mohamed olwi
 *
 * Created: 04/3/2025 11:00:00 AM
 */
#ifndef MOTOR_H
#define	MOTOR_H
/*----------------------------Header Files------------------------------------*/
#include "../../std_types.h"
#include "../../MCAL/GPIO/mcal_gpio.h"
/*----------------------------Macros Declarations-----------------------------*/
#define DC_MOTOR_MAX_PINS       0x02U
#define DC_MOTOR_PIN1           0x00U
#define DC_MOTOR_PIN2           0x01U
/*----------------------------DataTypes---------------------------------------*/

/**
 * struct dc_motor_t - a struct defining the 2 motor pins
 * @dc_motor_pins: the pins of the dc_motor
 */
typedef struct
{
    pin_config_t dc_motor_pins[DC_MOTOR_MAX_PINS];
}dc_motor_t;
/*----------------------------Function Prototypes-----------------------------*/
/**
 * @brief initialize the dc_motor 
 * @param dc_motor the pointer to the dc_motor config @ref dc_motor_t
 * @return E_OK if success otherwise E_NOT_OK 
 */
Std_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor);

/**
 * @brief make the motor turns
 * @param dc_motor the pointer to the dc_motor config @ref dc_motor_t
 * @return E_OK if success otherwise E_NOT_OK
 */
Std_ReturnType dc_motor_run(const dc_motor_t *dc_motor);
/**
 * @brief make the motor stop
 * @param dc_motor the pointer to the dc_motor config @ref dc_motor_t
 * @return E_OK if success otherwise E_NOT_OK
 */
Std_ReturnType dc_motor_stop(const dc_motor_t *dc_motor);
#endif	/* ecu_motor.h */
