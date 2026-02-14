# NES Emulator with Raspberry Pi Pico

This project is a NES emulator for PC with Raspberry Pi Pico support for handling inputs.

## Project Structure

```
nes-emulator-pico/
├── pc_emulator/          # NES emulator for PC (C++)
│   ├── src/              # Source files
│   └── CMakeLists.txt    # CMake configuration for PC
├── pico_firmware/        # Firmware for Raspberry Pi Pico (C)
│   ├── src/              # Source files
│   └── CMakeLists.txt    # CMake configuration for Pico
└── README.md             # Project instructions
```

## Setup

### PC Emulator
1. Install SDL2.
2. Clone this repository.
3. Create a build directory and run CMake:
    ```sh
    mkdir build && cd build
    cmake ..
    make
    ```
4. Run the emulator:
    ```sh
    ./nes_emulator
    ```

### Pico Firmware
1. Install the Pico SDK.
2. Navigate to the `pico_firmware` directory.
3. Create a build directory and run CMake:
    ```sh
    mkdir build && cd build
    cmake ..
    make
    ```
4. Flash the firmware to your Pico:
    ```sh
    picotool load -x pico_firmware.uf2
    ```

## License

This project is licensed under the MIT License.