
# Fix for Right Half Right Column Bonked
Column is now connected to PF5 instead of PF6.
Adapt qmk_firmware\keyboards\lily58\rev1\keyboard.json:
matrix_pins -> cols -> change F6 to F5

Useful links:

ATmega32U4 (controller of pro micro) data sheet w/ pinout: https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7766-8-bit-AVR-ATmega16U4-32U4_Datasheet.pdf
Promicro Pinout: https://imgur.com/wMNx2u6