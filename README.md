# ATmega328P socket-based teaching platform

Firmware examples and supporting material for the paper
*"Design and Implementation of a Jumper-Wire-Free, Socket-Based PCB Platform for Microcontroller Education"* (M. Novak, University of South Bohemia in České Budějovice).

The platform is a two-layer carrier PCB for the ATmega328P (DIP-28, 16 MHz, 5 V). All connections are fixed copper traces. Students insert the functional components into female socket headers: the MCU, crystal, load capacitors, reset network, LEDs, switches and thermistors. No jumper wires are needed.

## Board pin map

| Function | Pins |
|---|---|
| LEDs | D9, D10, D11 (100 Ω series resistors) |
| Switches | D5, D6, D7 |
| NTC thermistor dividers | A0, A1 (10 kΩ NTC, β = 3950, 10 kΩ fixed resistor, thermistor to GND) |
| I²C header | VCC, GND, SDA (A4), SCL (A5) |
| UART header | to CP2102 USB-to-TTL adapter (power, TX/RX, upload) |

## Repository structure

```
firmware/
  arduino/      Arduino IDE sketches (open the .ino in each folder)
  platformio/   PlatformIO project, one environment per example
docs/fritzing/  Fritzing wiring diagrams of the exercises (breadboard reference)
hardware/       KiCad design files of the carrier PCB (to be added)
data/           Anonymized questionnaire data (to be added)
```

## Programming

The ATmega328P carries an Arduino-compatible (Uno/Optiboot) bootloader. The board connects to the computer through a CP2102 USB-to-TTL adapter, which also powers it from USB.

**Arduino IDE:** select *Arduino Uno* as the board and the CP2102 serial port, then upload.

**PlatformIO / VS Code:**

```bash
cd firmware/platformio
pio run -e 01-led-test -t upload   # build and upload one example
pio device monitor                 # serial monitor, 9600 Bd
```

## Examples

| Topic | Arduino IDE (`firmware/arduino`) | PlatformIO env (`firmware/platformio`) |
|---|---|---|
| Board test, serial | `01-serial-test` | `01-led-test` |
| Digital output | `02-a-led`, `02-b-led-blink` | `01-led-test` |
| Digital input | `02-c-led-button` | `05-a-button-polling` |
| Logic functions | `02-d-logic-gate` | `02-e-logic-function` |
| Serial communication | `03-a-serial-sum`, `03-b-serial-led` | `03-a` … `03-f` |
| EEPROM | `04-eeprom-led` | `04-a-eeprom-led-state`, `04-b-eeprom-sos`, `04-c-eeprom-counter` |
| Interrupts, timers | — | `05-b-button-interrupt`, `05-c-timer-isr` |
| I²C | `06-i2c-vl53l0x` (needs Adafruit_VL53L0X library) | `06-a-i2c-bme280`, `06-b-i2c-scanner` |
| Analog input (NTC) | `07-analog-ntc` | `07-analog-ntc` |

Notes:

- `05-b-button-interrupt` uses external interrupt INT0 on D2, which is not routed to a board switch. Connect a button to D2 or adapt the pin.
- Some PlatformIO examples read the buttons as active-high (`INPUT`, external pull-down, breadboard wiring). The board sketches use `INPUT_PULLUP` (pressed = LOW).

## License

Firmware: MIT (see `LICENSE`).
