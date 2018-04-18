-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-044 kit.
-- =============================================================================

-- === I2C ===
attribute port_location of \I2C:scl(0)\ : label is "PORT(4,0)";
attribute port_location of \I2C:sda(0)\ : label is "PORT(4,1)";

-- === LCD_RST ===
attribute port_location of LCD_RST(0) : label is "PORT(6,2)";