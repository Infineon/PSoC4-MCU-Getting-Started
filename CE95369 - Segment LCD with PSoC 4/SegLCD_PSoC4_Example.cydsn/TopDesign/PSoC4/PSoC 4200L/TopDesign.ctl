-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-046 kit.
-- =============================================================================

-- === UART ===
attribute port_location of \UART:rx(0)\ : label is "PORT(3,0)";
attribute port_location of \UART:tx(0)\ : label is "PORT(3,1)";

-- === I2C ===
attribute port_location of \I2C:scl(0)\ : label is "PORT(4,0)";
attribute port_location of \I2C:sda(0)\ : label is "PORT(4,1)";

-- === RGB LED ===
attribute port_location of LowPowerOut_pin(0) : label is "PORT(5,2)"; -- RED LED
attribute port_location of REPLACE_WITH_ACTUAL_PIN_NAME(0) : label is "PORT(5,3)"; -- GREEN LED
attribute port_location of REPLACE_WITH_ACTUAL_PIN_NAME(0) : label is "PORT(5,4)"; -- BLUE LED

-- === USER SWITCH ===
attribute port_location of Wakeup_pin(0) : label is "PORT(0,7)";