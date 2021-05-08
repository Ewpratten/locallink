#if !defined(__CONFIG_HH)
#define __CONFIG_HH

#include <Arduino.h>

/* -------- CONFIGURATION CONSTANTS -------- */
#define CONF_CONST_RADIO_TYPE_NONE 0
#define CONF_CONST_RADIO_TYPE_OOK 1
#define CONF_CONST_RADIO_TYPE_LORA 2

/* -------- CONFIGURATION -------- */

// Callsign
#define SETTING_DEVICE_CALLSIGN "VA3ZZA-1"

// Message for all transmissions
#define SETTING_PACKET_MESSAGE "Experimental OOK Transmitter"

// Positioning
#define SETTING_POSITIONING_ENABLED 1
#define SETTING_POSITIONING_RAW_DDM "4259.59N/08114.43W"

// Beaconing
#define SETTING_BEACON_ENABLED 1
#define SETTING_BEACON_INTERVAL_MS 30000

// Radio transmitter settings
#define SETTING_TX_ENABLED 1                      // Can transmit
#define SETTING_TX_TYPE CONF_CONST_RADIO_TYPE_OOK // Radio type
#define SETTING_TX_PIN 2                          // Data pin
#define SETTING_TX_BAUD 600                       // Data baud

// Radio receiver settings
#define SETTING_RX_ENABLED 0                       // Can receive
#define SETTING_RX_TYPE CONF_CONST_RADIO_TYPE_NONE // Radio type
#define SETTING_RX_PIN -1                          // Data pin
#define SETTING_RX_BAUD SETTING_TX_BAUD            // Data baud

// Serial settings
#define SETTING_SERIAL_ENABLED 1 // Can this device send a copy of all data to serial
#define SETTING_SERIAL_BAUD 9600 // Serial BAUD

// Repeater settings
#define SETTING_REPEATER_ENABLED 1 && (SETTING_TX_ENABLED && SETTING_RX_ENABLED) // Is the repeater enabled (changes based on above settings)
#define SETTING_REPEATER_DELAY_MS 1000

// Sensor settings
#define SETTING_TEMP_SENSOR_ENABLED 1
#define SETTING_TEMP_SENSOR_PIN A0

#endif // __CONFIG_HH
