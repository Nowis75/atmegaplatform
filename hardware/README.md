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
- **The push buttons SW2–SW4 connect D5–D7 to GND.** Use `INPUT_PULLUP` in firmware (pressed = LOW).
- **No dedicated VCC/AVCC decoupling capacitor is fitted.** Adding 100 nF ceramic capacitors at pins 7/8 and 20/22 is recommended for the next revision.
- **The schematic is the current reference (rev. 1.1).** The LED circuits are drawn as MCU pin → 220 Ω → LED → GND. The tactile push buttons SW2–SW4 (6 × 6 mm, symbol `SW_Push`) switch D5–D7 to GND.
- **The `.kicad_pcb` is the layout of the manufactured boards (rev. 1.0).** There the LED sits between the pin and the resistor, the resistor goes to GND, and the silkscreen still shows 10 kΩ for R2–R5. Because all parts are socketed, the boards work with the rev. 1.1 values: insert the LED with its anode toward the MCU pin and use 220 Ω resistors. Run *Tools → Update PCB from Schematic* (F8) and re-route the LED nets before ordering new boards.
- **Board size:** 101 × 48 mm, two copper layers, 1.6 mm FR-4.
