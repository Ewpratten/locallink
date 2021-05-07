#![no_std]
#![no_main]

mod config;
mod jobs;

extern crate panic_halt;
use sparkfun_pro_micro::prelude::*;

#[sparkfun_pro_micro::entry]
fn main() -> ! {
    let dp = sparkfun_pro_micro::Peripherals::take().unwrap();

    let mut pins = sparkfun_pro_micro::Pins::new(dp.PORTB, dp.PORTC, dp.PORTD, dp.PORTE, dp.PORTF);

    // Open a serial connection
    let mut serial = sparkfun_pro_micro::Serial::new(
        dp.USART1,
        pins.d0,
        pins.d1.into_output(&mut pins.ddr),
        57600.into_baudrate(),
    );

    // Build the device config
    let config = config::create_config(
        &pins.led_tx.into_output(&mut pins.ddr),
        &pins.d2.into_output(&mut pins.ddr),
    );

    loop {}

    // let mut led0 = pins.led_rx.into_output(&mut pins.ddr);
    // let mut led1 = pins.led_tx.into_output(&mut pins.ddr);

    // led0.set_high().void_unwrap();
    // led1.set_high().void_unwrap();

    // let mut time: u16 = 0;
    // loop {
    //     if time % 2 == 0 {
    //         led0.set_low().void_unwrap();
    //     } else {
    //         led0.set_high().void_unwrap();
    //     }

    //     if time % 3 == 0 {
    //         led1.set_low().void_unwrap();
    //     } else {
    //         led1.set_high().void_unwrap();
    //     }

    //     sparkfun_pro_micro::delay_ms(500);
    //     time = time.wrapping_add(1);
    // }
}
