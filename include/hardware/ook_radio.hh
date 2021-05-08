#if !defined(__HARDWARE_OOK_RADIO_HH)
#define __HARDWARE_OOK_RADIO_HH

#include <stdint.h>

namespace ook
{
    
    void init_tx(uint8_t pin, uint16_t baud);
    void init_rx(uint8_t pin, uint16_t baud);

    void send_data(char* data);

} // namespace ook

#endif // __HARDWARE_OOK_RADIO_HH
