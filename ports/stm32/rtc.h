/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef MICROPY_INCLUDED_STM32_RTC_H
#define MICROPY_INCLUDED_STM32_RTC_H

extern RTC_HandleTypeDef RTCHandle;
extern const mp_obj_type_t pyb_rtc_type;

void rtc_init_start(bool force_init);
void rtc_init_finalise(void);

mp_obj_t pyb_rtc_wakeup(size_t n_args, const mp_obj_t *args);


/*--------------------------------*/
/*----Add to support stm32f1------*/
/*--------------------------------*/
#if defined(STM32F1)
typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;
typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef struct 
{
	vu8 hour;
	vu8 min;
	vu8 sec;			
	//公歷日月年周
	vu16 w_year;
	vu8  w_month;
	vu8  w_date;
	vu8  week;	
}_calendar_obj;			


extern _calendar_obj calendar;//時鐘結構體 
u8 RTC_Get(void);
u8 RTC_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
#endif

#endif // MICROPY_INCLUDED_STM32_RTC_H
