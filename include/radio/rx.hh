#if !defined(__RX_HH)
#define __RX_HH

#include <stdint.h>

namespace rx
{       
    int get_incoming_data(uint8_t* buffer, uint8_t length);

} // namespace rx


#endif // __RX_HH
