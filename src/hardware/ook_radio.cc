#include <hardware/ook_radio.hh>
#include <VirtualWire.h>

//https://www.instructables.com/Arduino-433mhz-Wireless-Transmitter-Receiver-SWITC/

void ook::init_tx(uint8_t pin, uint16_t baud)
{
    vw_set_tx_pin(pin);
    vw_setup(baud);
}

void ook::init_rx(uint8_t pin, uint16_t baud)
{
    vw_set_rx_pin(pin);
    vw_setup(baud);
    vw_rx_start();
}

void ook::send_data(const char *data)
{
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
}

int ook::read_data(uint8_t* buffer, uint8_t length) {
    return vw_get_message(buffer, &length);
}