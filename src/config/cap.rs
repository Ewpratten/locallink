use embedded_hal::digital::v2::OutputPin;
use void::Void;

pub enum RadioTransmitter<'a> {
    Ook {
        data_pin: &'a dyn OutputPin<Error = Void>,
        status_led_pin: &'a dyn OutputPin<Error = Void>,
    },
}

pub enum RadioReceiver {}

pub struct DeviceCapabilities<'a> {
    // Radio
    pub transmitter: Option<RadioTransmitter<'a>>,
    pub receiver: Option<RadioReceiver>,
}
