# Hardware: carrier PCB (KiCad)

| File | Content |
|---|---|
| `kicad/ATMega-platform.kicad_pro` | KiCad project |
| `kicad/ATMega-platform.kicad_sch` | Schematic |
| `kicad/ATMega-platform.kicad_pcb` | Two-layer PCB layout (1.6 mm) |
| `bom.csv` | Bill of materials |

Gerber and drill files are generated from the `.kicad_pcb` with KiCad's *Fabrication Outputs* (File → Fabrication Outputs → Gerbers / Drill Files).

## Revision notes

- **LED series resistors R2–R5 are 220 Ω.** The first prototype boards used 10 kΩ, which made the LEDs very dim.
- **C3 (1 µF) couples the DTR line of the CP2102 adapter to RESET.** The Arduino IDE / PlatformIO therefore resets the MCU automatically before an upload.
- **The switches SW2–SW4 connect D5–D7 to GND.** Use `INPUT_PULLUP` in firmware (pressed/closed = LOW).
- **No dedicated VCC/AVCC decoupling capacitor is fitted.** Adding 100 nF ceramic capacitors at pins 7/8 and 20/22 is recommended for the next revision.
- **The LED symbols for D2–D4 (D9–D11) are drawn with the cathode to the MCU pin.** Insert the LEDs so that the anode faces the MCU pin and the cathode faces the resistor to GND. The symbols will be corrected in the next revision.
