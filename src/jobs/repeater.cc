#include <Arduino.h>
#include <jobs/repeater.hh>
#include <radio/tx.hh>
#include <radio/rx.hh>
#include <config.hh>
#include <APRS-Decoder.h>

void jobs::try_repeat_packet()
{
    // Build a buffer
    uint8_t buffer[SETTING_REPEATER_MESSAGE_BUFFER_SIZE];
    memset(buffer, 0, sizeof(uint8_t) * SETTING_REPEATER_MESSAGE_BUFFER_SIZE);

    // Read a packet into the buffer
    int result = rx::get_incoming_data(buffer, SETTING_REPEATER_MESSAGE_BUFFER_SIZE);

    // Handle valid data
    if (result)
    {

        // Copy the result into a string
        String str_res = "";

        for (int i = 0; i < SETTING_REPEATER_MESSAGE_BUFFER_SIZE; i++)
        {
            str_res += (char)buffer[i];
        }

        // Pause a little bit
        delay(SETTING_REPEATER_DELAY_MS);

        // Parse the packet
        APRSMessage *message = new APRSMessage();
        if (!message->decode(str_res))
        {
#if SETTING_SERIAL_ENABLED
            Serial.println("# Could not parse message: " + str_res);
#endif
            return;
        }
        String old_path = message->getPath();

        // We only operate on OOKSUB repeats
        if (!old_path.startsWith("OOKSUB-"))
        {
#if SETTING_SERIAL_ENABLED
            Serial.println("# This repeater only accepts OOKSUB paths: " + str_res);
#endif
            return;
        }

        // Get the path counter
        int counter = (old_path.charAt(old_path.length() - 1)) - '0';
        if (counter <= 0)
        {
#if SETTING_SERIAL_ENABLED
            Serial.println("# Not repeating packet with counter <= 0: " + str_res);
#endif
            return;
        }

        // Reset the path
        counter -= 1;
        old_path.setCharAt(old_path.length() - 1, (char)(counter) + '0');
        message->setPath(old_path);

        // Re-send the packet
        tx::send_raw_packet(message->encode().c_str());
    }
}