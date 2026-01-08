# Overview
This program is used to analyze the data structure sent by a lens with an A‑Mount.
With modifications it can be used to analyze any synchronous serial transmissions.

# Hardware
Any Arduino‑compatible board is required.

# Operation
The microcontroller sends a clock signal to the lens. The lens sends serial data, which the microcontroller receives.
Each time the lens transmits a new frame, the microcontroller prints its contents to the serial terminal.
