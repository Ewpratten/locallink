#if !defined(_TX_HH)
#define _TX_HH

namespace tx
{       
    void send_beacon_packet(float temperature_f);

    void send_raw_packet(const char* data);
} // namespace tx


#endif // _TX_HH
