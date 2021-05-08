#include <Arduino.h>
#include <config.hh>
#include <radio/tx.hh>
#include <hardware/ook_radio.hh>

void tx::send_beacon_packet(float temperature_f)
{

    // Build the packet string
    String packet = String(SETTING_DEVICE_CALLSIGN ">APRS");

    // Path
    packet.concat(",OOKSUB-");
    packet.concat(SETTING_TX_MAX_HOPS);

    // EOH
    packet.concat(":!");

#if SETTING_POSITIONING_ENABLED
    packet.concat(SETTING_POSITIONING_RAW_DDM);
#endif

    // Temperature
#if SETTING_TEMP_SENSOR_ENABLED
    packet.concat('t');
    packet.concat(min(999, temperature_f));
#endif

    // Message
    packet.concat(SETTING_PACKET_MESSAGE);

    // Send the packet
    tx::send_raw_packet(packet.c_str());
}

void tx::send_raw_packet(const char *data)
{

    // Set the TX light
    TXLED1;

    // Write to Serial
#if SETTING_SERIAL_ENABLED
    Serial.println(data + '\0');
#endif

// Write to radio
#if SETTING_TX_ENABLED
    ook::send_data(data + '\0');
#endif

    // Un-set the TX light
    TXLED0;
}