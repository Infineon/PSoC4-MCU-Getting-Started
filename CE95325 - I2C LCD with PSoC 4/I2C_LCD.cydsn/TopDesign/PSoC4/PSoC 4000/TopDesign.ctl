-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-040 kit.
-- =============================================================================

-- === I2C ===
attribute port_location of \I2C:scl(0)\ : label is "PORT(1,2)";
attribute port_location of \I2C:sda(0)\ : label is "PORT(1,3)";

-- === LCD_RST ===
attribute port_location of LCD_RST(0) : label is "PORT(1,7)";