# STM32F107 Microprocessor Labs

Seven laboratory exercises and a final project written in C with the STM32 HAL for the **STM32F107VCTx** (Cortex-M3, LQFP100, 72 MHz), done for the Microprocessors course at Erzurum Technical University. Each folder is a standalone STM32CubeIDE project with its CubeMX configuration (`.ioc`).

| Folder | Topic | What it does |
|---|---|---|
| [`lab1-gpio-exti`](lab1-gpio-exti) | GPIO and external interrupt | A button on `PC0` raises an EXTI interrupt; the handler steps a delay value (1000 ms down in 250 ms steps) and drives the LED on `PD4`. Outputs on `PD0–PD4`. |
| [`lab2-timer-interrupt`](lab2-timer-interrupt) | Timer interrupt | `TIM1` interrupt keeps millisecond, second, minute and hour counters; the main loop walks a lit LED across `PD3 → PD0`. |
| [`lab3-pwm-input-capture`](lab3-pwm-input-capture) | PWM and input capture | `TIM1` generates PWM on channel 4 (`PE14`); `TIM4` input capture on `PD15` measures the period and computes the frequency. |
| [`lab4-uart`](lab4-uart) | UART | Reads four digital inputs (`PD0–PD3`) and prints their states over `USART1` every 500 ms, using a small `USART.c/.h` helper. |
| [`lab5-adc-dac-uart`](lab5-adc-dac-uart) | ADC, DAC, UART | Polls ADC channel 3 (`PA3`), shows the level on LEDs, converts it to a voltage, prints it over `USART1` and writes a value to the DAC (`PA4`). |
| [`lab6-temperature-filtering`](lab6-temperature-filtering) | Internal temperature sensor | Samples the internal sensor from a 5 ms timer interrupt, converts to °C, applies a moving-average filter and a first-order IIR filter, and prints the results over `USART1`. |
| [`lab7-adc-dma`](lab7-adc-dma) | ADC with DMA | Reads four ADC channels (`PA3–PA6`) with DMA and prints all four values over `USART1`. |
| [`project-uart-packet-protocol`](project-uart-packet-protocol) | Final project | Builds and sends framed packets over `USART1`: start byte `0xAA`, type, length, data, a BCC (XOR) checksum and stop byte `0x55`. `USART2` receive interrupt is enabled. The payload and the checksum seed are derived from the student number. |

## Tools

- STM32CubeIDE / STM32CubeMX 6.12.1
- STM32Cube FW_F1 V1.8.7 (HAL)
- Debug and serial output over SWD and `USART1` at 115200 baud

## Opening a project

The generated `Drivers/` folder (HAL and CMSIS) is not committed. To open a lab:

1. In STM32CubeIDE choose **File → Open Projects from File System** and select the lab folder.
2. Open the `.ioc` file and click **Generate Code**. CubeMX restores `Drivers/` from the firmware package.
3. Build and flash.

Application code lives between the `USER CODE BEGIN/END` markers in `Core/Src/main.c`; everything else is CubeMX-generated.

## Notes

Comments in the code are partly in Turkish, as the course materials were. These are coursework projects, written to learn the peripherals, not production firmware.
