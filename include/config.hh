#if !defined(__CONFIG_HH)
#define __CONFIG_HH

#include <Arduino.h>

/* -------- CONFIGURATION CONSTANTS -------- */
#define CONF_CONST_RADIO_TYPE_NONE 0
#define CONF_CONST_RADIO_TYPE_OOK 1
#define CONF_CONST_RADIO_TYPE_LORA 2

#define CONF_CONST_PRESET_BEACON 0
#define CONF_CONST_PRESET_REPEATER 1
#define CONF_CONST_PRESET_IGATE 2

/* -------- CONFIGURATION -------- */

#define SETTING_DEVICE_PRESET CONF_CONST_PRESET_BEACON

// Callsign
#define SETTING_DEVICE_CALLSIGN "VA3ZZA-1"

// Message for all transmissions
#define SETTING_PACKET_MESSAGE "Experimental OOK Beacon"

// Positioning
#define SETTING_POSITIONING_ENABLED 1
#define SETTING_POSITIONING_RAW_DDM "4259.98N/08114.73W"

// Beaconing
#define SETTING_BEACON_ENABLED ((SETTING_DEVICE_PRESET == CONF_CONST_PRESET_BEACON) || \
                                (SETTING_DEVICE_PRESET == CONF_CONST_PRESET_REPEATER))
#define SETTING_BEACON_INTERVAL_MS 15000

// Radio transmitter settings
#define SETTING_TX_ENABLED ((SETTING_DEVICE_PRESET == CONF_CONST_PRESET_BEACON) || \
                            (SETTING_DEVICE_PRESET == CONF_CONST_PRESET_REPEATER)) // Can transmit
#define SETTING_TX_TYPE CONF_CONST_RADIO_TYPE_OOK                                  // Radio type
#define SETTING_TX_PIN 2                                                           // Data pin
#define SETTING_TX_BAUD 1000                                                       // Data baud
#define SETTING_TX_MAX_HOPS 2                                                      // Max number of repeaters allowed for all transmissions from this radio

// Radio receiver settings
#define SETTING_RX_ENABLED ((SETTING_DEVICE_PRESET == CONF_CONST_PRESET_IGATE) || \
                            (SETTING_DEVICE_PRESET == CONF_CONST_PRESET_REPEATER)) // Can receive
#define SETTING_RX_TYPE CONF_CONST_RADIO_TYPE_OOK                                  // Radio type
#define SETTING_RX_PIN 3                                                           // Data pin
#define SETTING_RX_BAUD SETTING_TX_BAUD                                            // Data baud

// Serial settings
#define SETTING_SERIAL_ENABLED 1 // Can this device send a copy of all data to serial
#define SETTING_SERIAL_BAUD 9600 // Serial BAUD

// Repeater settings
#define SETTING_REPEATER_DELAY_MS 1000
#define SETTING_REPEATER_MESSAGE_BUFFER_SIZE 255

// Sensor settings
#define SETTING_TEMP_SENSOR_ENABLED ((SETTING_DEVICE_PRESET == CONF_CONST_PRESET_BEACON) || \
                                     (SETTING_DEVICE_PRESET == CONF_CONST_PRESET_REPEATER))
#define SETTING_TEMP_SENSOR_PIN A0

#endif // __CONFIG_HH
