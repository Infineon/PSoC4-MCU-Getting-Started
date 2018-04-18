-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-041-41xx kit.
-- =============================================================================

-- === I2C ===
attribute port_location of \I2C:scl(0)\ : label is "PORT(3,0)";
attribute port_location of \I2C:sda(0)\ : label is "PORT(3,1)";

-- === LCD_RST ===
attribute port_location of LCD_RST(0) : label is "PORT(1,2)";