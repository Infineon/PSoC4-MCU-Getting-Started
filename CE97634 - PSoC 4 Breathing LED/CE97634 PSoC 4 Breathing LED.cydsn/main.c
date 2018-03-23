/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is the source code for the CE97634 PSoC 4 Breathing LED code example.
*
* Hardware Supported:
*  CY8CKIT-043 PSoC 4 M-Series Prototyping Kit
*  CY8CKIT-044 PSoC 4 M-Series Pioneer Kit
*  CY8CKIT-042 PSoC 4 Pioneer Kit
*  CY8CKIT-042-BLE PSoC 4 BLE Pioneer Kit
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include <project.h>

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Main function.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
int main()
{
    /* Start the PWMs */
	PWM_1_Start();
	PWM_2_Start();
	
	/* Start the PWM clock after starting and enabling the PWMs
	The Clock is stopped in design wide resources and restarted here to make sure 
	both the PWM outputs are synchronized */
	PWM_Clock_Start();

    for(;;)
    {
        /* Put CPU to Sleep as CPU is not involved the operation */
		CySysPmSleep();
    }
}

/* [] END OF FILE */
