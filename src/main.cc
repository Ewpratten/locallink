#include <Arduino.h>

#include <config.hh>
#include <hardware/ook_radio.hh>

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

void send_beacon_data(float temperature_f)
{

    // Set the TX light
    TXLED1;

    // Build the packet string
    char *packet = SETTING_DEVICE_CALLSIGN ">APRS:!"
#if SETTING_POSITIONING_ENABLED
        SETTING_POSITIONING_RAW_DDM
#endif
            // String(min(999, uint8_t temperature_f))
            SETTING_PACKET_MESSAGE;

// Write to Serial
#if SETTING_SERIAL_ENABLED
    Serial.println(packet);
#endif

// Write to radio
#if SETTING_TX_ENABLED
    ook::send_data(packet);
#endif

    // Un-set the TX light
    TXLED0;
}

// The last time that a beacon was sent
long last_beacon_time = 0;

void loop()
{

    // Get the system time
    long time_now = millis();

    // Handle any incoming message
    // TODO:

    // Handle beaconing if needed
#if SETTING_BEACON_ENABLED
    if (time_now - last_beacon_time > SETTING_BEACON_INTERVAL_MS)
    {

        // Get the temperature
        float temperature_f = 0;

#if SETTING_TEMP_SENSOR_ENABLED
        temperature_f = (((analogRead(SETTING_TEMP_SENSOR_PIN) * 500) / 1023) * 1.8) + 32;
#endif

        // Send data
        send_beacon_data(temperature_f);

        // Set the last beacon time
        last_beacon_time = time_now;
    }
#endif
}