/**
  SWITCH_S2 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    switch_s2.h

  @Summary
    This is the generated header file for the SWITCH_S2 driver using Board Support Library

  @Description
    This header file provides APIs for driver for SWITCH_S2.
    Generation Information :
        Product Revision  :  Board Support Library - CQ1-2020
        Device            :  PIC24FJ128GL306
        Driver Version    :  0.95
    The generated drivers are tested against the following:
        Compiler          :  1.41
        MPLAB 	          :  MPLAB X v5.25
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef SWITCH_S2_H
#define SWITCH_S2_H

#include <stdbool.h>
#include <xc.h>

static inline bool SWITCH_S2_IsPressed() {return (_RD0 == false);}

#endif	/* SWITCH_S2_H */