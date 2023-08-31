/*
 * TIMER.h
 *
 * Created: 8/25/2023 11:38:25 AM
 *  Author: Norhan Mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "STD_types.h"
#include "DIO_interface.h"
#include "ATMega32A_Registers.h"
#include <avr/interrupt.h>

#define FOC0   DIO_PIN7
#define TOIE0  DIO_PIN0
#define OCIE0  DIO_PIN1

	
#define TIMER_MAX_REG_VALUE 255
/*******************************************************************************
* Types Declaration                                   *
 *******************************************************************************/

typedef enum{
	NORMAL_MODE,COMPARE_MODE=1, FAST_PWM=9,PHASE_CONTROL=8
}TIMER_modeType;

typedef enum{
	NO_CLOCK_2,F_CPU_CLOCK_2,F_CPU_8_2,F_CPU_32_2,F_CPU_64_2,F_CPU_128_2,F_CPU_256_2,F_CPU_1024_2
}TIMER2_prescaler;

typedef enum{
	NORMAL_OV,TOGGLE,CLEAR,SET_
}TIMER_CompareModeType;

typedef enum{
	NO_MODE,RESERVED,NON_INVERTING,INVERTING
}TIMER_PwmModeType;

typedef enum{
	ErrorInMode, 
	ErrorInPrescaler,
	ErrorInCompareMode,
	ErrorInPwmMode,
	ErrorInCompareValue,
	ErrorInStartValue,
	ErrorInDuty
	}ErrorType;
	
typedef enum {
	SUCCESSFUL,
	UNSUCCESSFUL
	}bool;



typedef struct {
	TIMER_modeType mode;
	TIMER2_prescaler prescaler;
	u8 StartValue;
	u8 CompareValue;
	TIMER_CompareModeType CompareOutput; 
	TIMER_PwmModeType PwmOutput;
	
	}TIMER_ConfigType;
	


typedef enum
{
	TIMER_NO_PRESCALER = 1,
	TIMER_PRESCALER_8 = 2,
	TIMER_PRESCALER_64 = 3,
	TIMER_PRESCALER_256 = 4,
	TIMER_PRESCALER_1024 = 5,
	TIMER0_PRESCALER_TOTAL
} enu_timer0_prescaler_t_;

typedef enum
{
	NORMAL = 0,
	PWM_PHASE_CORRECT,
	CTC,
	PWM_FAST,
	TIMER0_MODES_TOTAL

} enu_timer0_mode_t_;

typedef enum
{
	DISCONNECT_OC0 = 0,
	TOGGLE_OC0,
	CLEAR_OC0,
	SET_OC0,
	TIMER0_OC0_TOTAL
} enu_timer0_oc0_t_;

typedef enum
{
	POLLING = 0,
	OVF_IE,
	CTC_IE,
	TIMER0_INT_EN_TOTAL
} enu_timer0_int_en_t_;

typedef enum
{
	ERROR_TIMER0_OK = 0,
	ERROR_TIMER0_NOK
} enu_timer0_error_status_t;

typedef struct
{
	enu_timer0_prescaler_t_ enu_timer0_prescaler;
	enu_timer0_mode_t_ enu_timer0_mode;
	enu_timer0_int_en_t_ enu_timer0_int_en;
	enu_timer0_oc0_t_ enu_timer0_oc0;
	u8 preload;
	u8 compare_val;
} st_timer0_config_t_;

enu_timer0_error_status_t TIMER0_Init(st_timer0_config_t_ *st_arg_timer0_config);
enu_timer0_error_status_t TIMER0_set_compare(u8 u8_arg_compare_value);
void TIMER0_Deinit(void);
bool TIMER2_Init(const TIMER_ConfigType * Config_ptr);
bool TIMER2_SetDuty(uint8_t duty);
void TIMER2_setCallBack(void (*a_ptr)(void));






#endif /* TIMER_H_ */