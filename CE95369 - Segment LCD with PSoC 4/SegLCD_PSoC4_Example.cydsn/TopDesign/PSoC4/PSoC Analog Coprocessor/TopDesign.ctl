-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-048 kit.
-- =============================================================================

-- === RGB LED ===
attribute port_location of LowPowerOut_pin(0) : label is "PORT(1,4)"; -- RED LED

-- === USER SWITCH ===
attribute port_location of Wakeup_pin(0) : label is "PORT(0,3)";