use aprs_encode::aprs::position::AprsPosition;

use super::cap::DeviceCapabilities;

/// Device configuration
pub struct BeaconConfig<'a> {
    /// Device callsign
    pub callsign: &'a str,

    /// Beacon message
    pub message: &'a str,

    /// Device location
    pub location: Option<AprsPosition>,

    /// Capabilities
    pub capabilities: DeviceCapabilities<'a>,
}
