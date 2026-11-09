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
- **Schematic and PCB are not yet synchronized.** The schematic (Nov 2026) has the LED circuits redrawn as MCU pin → 220 Ω → LED anode, LED cathode → GND. The `.kicad_pcb` still holds the routing of the manufactured boards, where the LED sits between the pin and the resistor and the resistor goes to GND. Both are electrically equivalent once the LED is inserted with the anode toward the MCU pin. Run *Tools → Update PCB from Schematic* (F8) and re-route before ordering new boards.
- **SW2–SW4 use the `SW_DIP_x02` symbol on the tactile-switch footprint `SW_PUSH_6mm`.** Only pads 1 (GND) and 2 (D5–D7) exist on the PCB. Symbol pins 3 (GND) and 4 (VCC) are not routed. Replace the symbol with a two-pin switch so the schematic does not suggest a VCC–GND connection.
