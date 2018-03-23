/*******************************************************************************
* File Name: main.c
*
* Version: 2.0
*
* Description:
*  The example project displays " CYPRESS" in custom font on a 2X16 LCD 
*  available with CY8CKIT-001.
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>

extern uint8 const CYCODE LCD_customFonts[];

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  The main program does the following
*  1. Initializes the LCD.
*  2. Loads custom fonts. 
*  3. Puts "CYPRESS" in custom available font in row 0 of the LCD.
*  4. Prints " Perform" in normal font in row 1 of the LCD.
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
  uint8 pos = 1u;
  uint8 row = 0u;
  
  LCD_Start();
  LCD_LoadCustomFonts(LCD_customFonts);    

  LCD_Position(row, pos);
  LCD_PutChar(LCD_CUSTOM_0);        /* Puts "C" at 2nd column in first row */
  pos += 2u;

  LCD_Position(row, pos);
  LCD_PutChar(LCD_CUSTOM_1);        /* Puts "Y" at 4th column in first row */
  pos += 2u;
        
  LCD_Position(row, pos);
  LCD_PutChar(LCD_CUSTOM_2);        /* Puts "P" at 6th column in first row */
  pos += 2u;

  LCD_Position(row, pos);
  LCD_PutChar(LCD_CUSTOM_3);        /* Puts "R" at 8th column in first row */
  pos += 2u;     
  
  LCD_Position(row, pos);
  LCD_PutChar(LCD_CUSTOM_4);        /* Puts "E" at 10th column in first row */
  pos += 2u;
        
  LCD_Position(row, pos);
  LCD_PutChar(LCD_CUSTOM_5);        /* Puts "S" at 12th column in first row */
  pos += 2u;
        
  LCD_Position(row, pos);
  LCD_PutChar(LCD_CUSTOM_6);        /* Puts "S" at 14th column in first row */
  pos += 2u;
    
  CyDelay(200u);
  LCD_Position(1u, 9u);
  LCD_PrintString("Perform");        /* Puts "Perform" from 8th column in second row */
           
  for(;;)
  {}
}


/* [] END OF FILE */
