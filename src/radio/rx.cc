#include <Arduino.h>
#include <config.hh>
#include <radio/rx.hh>
#include <hardware/ook_radio.hh>

int rx::get_incoming_data(uint8_t* buffer, uint8_t length) {
    return ook::read_data(buffer, length);
}