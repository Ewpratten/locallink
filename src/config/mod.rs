//! Device configuration data. Pretty much the only thing that needs to change between boards

use embedded_hal::digital::v2::OutputPin;
use sparkfun_pro_micro::{prelude::*, Pins};
use void::Void;

use self::{
    base::BeaconConfig,
    cap::{DeviceCapabilities, RadioTransmitter},
};

pub mod base;
pub mod cap;

pub fn create_config<'a>(tx_led: &'a dyn OutputPin<Error = Void>, radio_tx_pin: &'a dyn OutputPin<Error = Void>) -> BeaconConfig<'a> {
    BeaconConfig {
        callsign: "VA3ZZA-1",
        message: "Testing OOK Link",
        location: None,
        capabilities: DeviceCapabilities {
            transmitter: Some(RadioTransmitter::Ook {
                data_pin: tx_led,
                status_led_pin: radio_tx_pin,
            }),
            receiver: None,
        },
    }
}
