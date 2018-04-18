/*******************************************************************************
* File: main.c
*
* Version : 1.0
*
* Description:
*  This is a source code for an example project of PSoC4 Segment LCD component.
*
********************************************************************************
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>

volatile uint32 timer = 0u;
volatile uint32 state = 0u;


/*******************************************************************************
* Function Name: CY_ISR(isr_Button)
********************************************************************************
*
* Summary:
*  This function performs the following functions:
*   1. Sets a state variable
*   2. Clears interrupts from the Button
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
CY_ISR(isr_Button)
{
    CyDelay(200u);
    state = 1u;
    Wakeup_pin_ClearInterrupt();
}


/*******************************************************************************
* Function Name: CY_ISR(isr_Timer)
********************************************************************************
*
* Summary:
*  This function performs the following functions:
*   1. Increases a timer value
*   2. Displays a current timer value on the Segment LCD glass
*   3. Clears interrupts from the Timer component
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
CY_ISR(isr_Timer)
{
    timer++;
    LCD_Seg_Write7SegNumber_0(timer, 0u, LCD_Seg_NO_LEADING_ZEROES);
    Timer_ClearInterrupt(Timer_INTR_MASK_TC);
}


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  The main function performs the following functions:
*   1. Enables global interrupts
*   2. Starts interrupt handlers
*   3. Starts the Timer component
*   4. Initializes the Segment LCD component
*   5. Puts the chip into Deep Sleep mode
*   6. Restores work after Deep Sleep
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
int main()
{
    volatile uint32 temp = 0u;

    /* Enable the global interrupts */
    CyGlobalIntEnable;

    /* Enable the Interrupt component connected to the Button interrupt */
    isr_Button_StartEx(isr_Button);
    /* Enable the Interrupt component connected to the Timer interrupt */
    isr_Timer_StartEx(isr_Timer);

    /* Start the Timer component */
    Timer_Start();

    /* Start the Segment LCD component */
    LCD_Seg_Start();

    for(;;)
    {
        if(0u == state)
        {
            /* Displaying the timer value */
        }
        else
        {
            if (0u == temp)
            {
                /* Prepare the Timer component to Sleep mode */
                Timer_Sleep();
                temp = 1u;
                
                /* Turn the LED connected to LowPowerOut_pin OFF to indicate low power mode */
                LowPowerOut_pin_Write(1u);
                
                /* Put the chip into Deep Sleep mode */
                CySysPmDeepSleep();
            }
            else
            {
                /* Turn the LED connected to LowPowerOut_pin ON to indicate active mode */
                LowPowerOut_pin_Write(0u);
                
                /* Restore the Timer component after Sleep */
                Timer_Wakeup();
                temp = 0u;
                state = 0u;
            }
        }
    }
}

/* [] END OF FILE */
