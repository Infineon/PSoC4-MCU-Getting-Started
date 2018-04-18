-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-042-BLE and CY8CKIT-042-BLE-A kits.
-- =============================================================================

-- === I2C ===
attribute port_location of \I2C:scl(0)\ : label is "PORT(3,5)";
attribute port_location of \I2C:sda(0)\ : label is "PORT(3,4)";

-- === LCD_RST ===
attribute port_location of LCD_RST(0) : label is "PORT(0,3)";