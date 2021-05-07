use sparkfun_pro_micro::hal::usart::{Usart, UsartOps};

use crate::config::base::BeaconConfig;

pub struct BeaconJob {}

impl BeaconJob {
    pub fn new(interval_loops: f32) -> Self {
        Self {}
    }

    pub fn should_run(&mut self) -> bool {
        return true;
    }

    pub fn execute<USART: UsartOps<RX, TX>, RX, TX, CLOCK>(
        &mut self,
        config: &BeaconConfig,
        serial: Usart<USART, RX, TX, CLOCK>,
    ) {

        // Allocate a buffer for an APRS packet
        

    }
}
