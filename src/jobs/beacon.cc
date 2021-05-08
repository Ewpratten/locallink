#include <Arduino.h>
#include <jobs/beacon.hh>
#include <radio/tx.hh>
#include <config.hh>

// The last time that a beacon was sent
long last_beacon_time = 0;

void jobs::send_beacon()
{
    // Get the system time
    long time_now = millis();

    // Only run if past the interval
    if (time_now - last_beacon_time >= SETTING_BEACON_INTERVAL_MS || last_beacon_time == 0)
    {

        // Get the temperature
        float temperature_f = 0;

#if SETTING_TEMP_SENSOR_ENABLED
        temperature_f = (((analogRead(SETTING_TEMP_SENSOR_PIN) * 500) / 1023) * 1.8) + 32;
#endif

        // Send data
        tx::send_beacon_packet(temperature_f);

        // Set the last beacon time
        last_beacon_time = time_now;
    }
}