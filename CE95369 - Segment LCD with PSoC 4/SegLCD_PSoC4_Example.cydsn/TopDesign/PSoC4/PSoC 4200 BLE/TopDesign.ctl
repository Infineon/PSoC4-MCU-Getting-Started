-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-042-BLE kit.
-- =============================================================================

-- === UART ===
attribute port_location of \UART:rx(0)\ : label is "PORT(1,4)";
attribute port_location of \UART:tx(0)\ : label is "PORT(1,5)";

-- === I2C ===
attribute port_location of \I2C:scl(0)\ : label is "PORT(3,5)";
attribute port_location of \I2C:sda(0)\ : label is "PORT(3,4)";

-- === RGB LED ===
attribute port_location of LowPowerOut_pin(0) : label is "PORT(2,6)"; -- RED LED
attribute port_location of REPLACE_WITH_ACTUAL_PIN_NAME(0) : label is "PORT(3,6)"; -- GREEN LED
attribute port_location of REPLACE_WITH_ACTUAL_PIN_NAME(0) : label is "PORT(3,7)"; -- BLUE LED

-- === USER SWITCH ===
attribute port_location of Wakeup_pin(0) : label is "PORT(2,7)";
