/*******************************************************************************
* File Name: main.c
*
* Version: 2.0
*
* Description:
*  Series of horizontal bar graphs are drawn, left to right. First, row 0 is 
*  filled followed by a clear display. Bars move towards right, becoming 
*  shorter and shorter. The same happens on row 1. Finally a text on the 
*  display indicates completion of the demo. 
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

#define LCD_ROWS 2u
#define LCD_COLUMNS 16u
extern uint8 const CYCODE LCD_customFonts[];


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  The main program does the following
*  1. Initialiazes the LCD.
*  2. Load the custom fonts. This step is required to create a bar graph.
*  3. Prints start of demo string on LCD.
*  4. For each row, displays a bar graph from left to right with initial position 
*     moving towards right. After each graph the displayis cleared.
*  5. Displays completion of demo.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void main()
{
    uint8 height;
    uint8 width;
    uint8 row;
    
    /* Start LCD */
    LCD_Start();
    
    /* To load the custom Fonts */
    LCD_LoadCustomFonts(LCD_customFonts);
    
    /* Set position for string output to row - 0 column - 0 */
    LCD_Position(0u, 0u);
    
    /* Output demo start message */
    LCD_PrintString("Horizontal BG");
    LCD_Position(1u, 0u);
    LCD_PrintString("Demo started");
    CyDelay(1000u);

    /* Clear the LCD display */
    LCD_ClearDisplay();
    
    /* Displays a bar graph from left to right with initial position 
    * moving towards right. 
    */
    for(row = 0u; row < LCD_ROWS; row++)
    {
        for(width = 0u; width < LCD_COLUMNS; width++)
        {
            for(height = 0u; height < (5u * (LCD_COLUMNS - LCD_ROWS)); height++)
            {
                LCD_DrawHorizontalBG(row, width, (LCD_COLUMNS - LCD_ROWS), height);
                CyDelay(10u);
            }
            
            /* Clear the display */
            LCD_ClearDisplay();
        }
    }
    
    /* Wait for some time */
    CyDelay(500u);
    
    /* Output demo completion message */
    LCD_Position(0u, 0u);
    LCD_PrintString("Horizontal BG");
    LCD_Position(1u, 0u);
    LCD_PrintString("Demo complete");
    for(;;)
    {
    
    }
}


/* [] END OF FILE */
