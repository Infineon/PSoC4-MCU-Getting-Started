/******************************************************************************
* File Name: main.c
*
* Version 1.10
*
* Description: 
*  This code example demonstrates how to use the I2C LCD Component with 
*  the NXP PCF2119x compatible LCD modules. It also demonstrates the usage of 
*  address macros and custom commands.
*
* Related Document: 
*  CE195325_I2C_LCD_with_PSoC4.pdf
*
* Hardware Dependency: 
*  See CE195325_I2C_LCD_with_PSoC4.pdf
*
*******************************************************************************
* Copyright (2018), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress 
* reserves the right to make changes to the Software without notice. Cypress 
* does not assume any liability arising out of the application or use of the 
* Software or any product or circuit described in the Software. Cypress does 
* not authorize its products for use in any products where a malfunction or 
* failure of the Cypress product may reasonably be expected to result in 
* significant property damage, injury or death ("High Risk Product"). By 
* including Cypress’s product in a High Risk Product, the manufacturer of such 
* system or application assumes all risk of such use and in doing so agrees to 
* indemnify Cypress against all liability. 
*******************************************************************************/

#include <project.h>

#define CUSTOM_CHARS_NUM    (8u)
#define LCD_MODULE_ADDRESS  (0x74u)

#define ROW_ZERO            (0u)
#define ROW_ONE             (1u)
#define COLUMN_ZERO         (0u)

#define LCD_FLIP_DELAY      (2000u)


/******************************************************************************  
* The array with IDs of the custom characters defined by the 
* I2C_LCD Component customizer.
******************************************************************************/
char8 customString[CUSTOM_CHARS_NUM] = {I2C_LCD_CUSTOM_0, I2C_LCD_CUSTOM_1, 
                                        I2C_LCD_CUSTOM_2, I2C_LCD_CUSTOM_3, 
                                        I2C_LCD_CUSTOM_4, I2C_LCD_CUSTOM_5, 
                                        I2C_LCD_CUSTOM_6, I2C_LCD_CUSTOM_7};


/*******************************************************************************
* Function Name: main
********************************************************************************
* 
* Summary:
*  This function:
*  1. Initializes the I2C and I2C_LCD Components.
*  2. Prints two strings: first with custom characters and second with
*     characters from the LCDs internal character set.
*  3. Every two seconds, switches the row display mode: from normal to
*     flipped and vice versa.
*
*******************************************************************************/
int main(void)
{
    uint8 i = 0u;
    
    /* Enable the global interrupts */
    CyGlobalIntEnable;

    /* Start the I2C and I2C_LCD Components */
    I2C_Start();

    /* The LCD Module reset pulse */
    LCD_RST_Write(1u);
    CyDelay(1u);
    LCD_RST_Write(0u);
    
    I2C_LCD_Start();
    
    /* Set the position to the start of the first row and print the custom characters */
    I2C_LCD_Position(ROW_ZERO, COLUMN_ZERO);
    for(i = 0u; i < CUSTOM_CHARS_NUM; i++)
    {
        I2C_LCD_WriteData(customString[i]);
    }
    
    /* Set the position to the start of the second row and print the text string */
    I2C_LCD_Position(ROW_ONE, COLUMN_ZERO);
    I2C_LCD_PrintString("Cypress!");

    /* Select Basic + Extended instruction mode to use the extended functionality.
    * This function is defined in the Custom commands tab of the I2C_LCD Component.
    */
    I2C_LCD_AddrSelectExtendedFuncs(LCD_MODULE_ADDRESS);
    
    for(;;)
    {
        CyDelay(LCD_FLIP_DELAY);
        
        /* Set flipped row Display mode of the LCD.
        * This function is defined in the Custom commands tab of the I2C_LCD Component.
        */
        I2C_LCD_SetBottomToTop();
        
        CyDelay(LCD_FLIP_DELAY);
        
        /* Set the normal row Display mode of the LCD.
        * This function is defined in the Custom commands tab of the I2C_LCD Component.
        */
        I2C_LCD_SetTopToBottom();
    }
}


/* [] END OF FILE */
