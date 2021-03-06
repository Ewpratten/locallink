#if !defined(__CONFIG_IGATE_HH)
#define __CONFIG_IGATE_HH

#include <Arduino.h>

/* -------- CONFIGURATION -------- */

// Beaconing
#define SETTING_BEACON_ENABLED 0
#define SETTING_BEACON_INTERVAL_MS 15000

// Radio transmitter settings
#define SETTING_TX_ENABLED 0                      // Can transmit
#define SETTING_TX_TYPE CONF_CONST_RADIO_TYPE_OOK // Radio type
#define SETTING_TX_PIN 2                          // Data pin
#define SETTING_TX_BAUD 600                       // Data baud
#define SETTING_TX_MAX_HOPS 2                     // Max number of repeaters allowed for all transmissions from this radio

// Radio receiver settings
#define SETTING_RX_ENABLED 1                       // Can receive
#define SETTING_RX_TYPE CONF_CONST_RADIO_TYPE_NONE // Radio type
#define SETTING_RX_PIN 3                          // Data pin
#define SETTING_RX_BAUD SETTING_TX_BAUD            // Data baud

// Serial settings
#define SETTING_SERIAL_ENABLED 1 // Can this device send a copy of all data to serial
#define SETTING_SERIAL_BAUD 9600 // Serial BAUD

// Repeater settings
#define SETTING_REPEATER_ENABLED 1 && (SETTING_TX_ENABLED && SETTING_RX_ENABLED) // Is the repeater enabled (changes based on above settings)
#define SETTING_REPEATER_DELAY_MS 1000
#define SETTING_REPEATER_MESSAGE_BUFFER_SIZE 255

// Sensor settings
#define SETTING_TEMP_SENSOR_ENABLED 1
#define SETTING_TEMP_SENSOR_PIN A0

#endif // __CONFIG_IGATE_HH
