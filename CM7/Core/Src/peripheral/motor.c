/*
 * ESC.c
 */

#include "main.h"
#include "ESC.h"

/**
 * @brief Sets the motor speed using PWM.
 *
 * This function adjusts the PWM pulse width based on the input speed value,
 * which should be between -1.0 (full reverse) and 1.0 (full forward).
 * It calculates the appropriate pulse width and updates the PWM duty cycle
 * for TIM_CHANNEL_1 of the timer, starting PWM signal generation.
 *
 * @param speed The desired motor speed (-1.0 to 1.0).
 */

void SetMotorSpeed(float speed)
{
    // Ensure speed is within the valid range

	if (speed < -1.0f || speed > 1.0f) {
        return;
    }

	// Calculate the pulse width based on the input speed

	float pulseWidth = NEUTRAL_PULSE_WIDTH_MS + (speed * (speed > 0.0f ? FORWARD_PULSE_WIDTH_RANGE : -REVERSE_PULSE_WIDTH_RANGE));

    // Get the current value of the auto-reload register for the timer

    uint32_t autoreload_register_value = __HAL_TIM_GET_AUTORELOAD(&htim14);

    // Calculate the compare value based on the pulse width and timer settings

    uint32_t value = (uint32_t)((pulseWidth / PWM_PERIOD_MS) * (autoreload_register_value + 1));

    // Set the PWM duty cycle for TIM_CHANNEL_1 of the timer

    __HAL_TIM_SET_COMPARE(&htim14, TIM_CHANNEL_1, value);

    // Start the PWM signal generation on TIM_CHANNEL_1 if not already started

    HAL_TIM_StateTypeDef pwmState = HAL_TIM_PWM_GetState(&htim14);

    if (pwmState != HAL_TIM_STATE_READY) {
        HAL_TIM_PWM_Start(&htim14, TIM_CHANNEL_1);
    }
}
