#include <Arduino.h>

#include <config.hh>
#include <hardware/ook_radio.hh>
#include <jobs/beacon.hh>

void setup()
{

    // Set up serial
#if SETTING_SERIAL_ENABLED
    Serial.begin(SETTING_SERIAL_BAUD);
    Serial.println("# Started Serial connection");
#endif

    // Set up transmitter
#if SETTING_TX_ENABLED
    ook::init_tx(SETTING_TX_PIN, SETTING_TX_BAUD);
#endif

    // Set up receiver
#if SETTING_RX_ENABLED
    ook::init_rx(SETTING_RX_PIN, SETTING_RX_BAUD);
#endif

    // Set up temperature sensor
#if SETTING_TEMP_SENSOR_ENABLED
    pinMode(SETTING_TEMP_SENSOR_PIN, INPUT);
#endif
}



void loop()
{

    // Handle any incoming message
    // TODO:

    // Handle beaconing if needed
#if SETTING_BEACON_ENABLED
    jobs::send_beacon();
#endif
}