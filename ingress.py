import aprslib
import serial
import argparse
import sys


def main() -> int:
    # Handle program arguments
    ap = argparse.ArgumentParser(prog='', description='')
    ap.add_argument("port", help="Serial port", default="/dev/ttyACM0")
    ap.add_argument("-b", "--baud-rate", help="Serial baud",
                    default=9600, type=int)
    ap.add_argument("-c", "--callsign", help="APRS callsign", required=True)
    args = ap.parse_args()

    # Open serial connection
    ser = serial.Serial(args.port, args.baud_rate, timeout=.1)

    # Open APRS-IS connection
    AIS = aprslib.IS(args.callsign, passwd=aprslib.passcode(
        args.callsign), port=14580)
    AIS.connect()

    # Handle incoming data
    try:
        while True:
            # Serial line
            line = str(ser.readline().decode().strip('\r\n'))
            if not line:
                continue

            # Ignore debug data
            if line[0] == "#":
                continue

            # Log
            print(line)

            # Send
            AIS.sendall(line)

    except KeyboardInterrupt as e:
        pass

    return 0


if __name__ == "__main__":
    sys.exit(main())
