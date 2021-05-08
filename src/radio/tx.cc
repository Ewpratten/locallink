#include <Arduino.h>
#include <config.hh>
#include <radio/tx.hh>
#include <hardware/ook_radio.hh>

void tx::send_beacon_packet(float temperature_f)
{

    // Build the packet string
    String packet = String(SETTING_DEVICE_CALLSIGN ">APRS:!");

#if SETTING_POSITIONING_ENABLED
    packet.concat('t');
    packet.concat(SETTING_POSITIONING_RAW_DDM);
#endif

    packet.concat(min(999, temperature_f));
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
    Serial.println(data);
#endif

// Write to radio
#if SETTING_TX_ENABLED
    ook::send_data(data);
#endif

    // Un-set the TX light
    TXLED0;
}