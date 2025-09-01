# zhengbingquant_Nano_V1

**DIY ATmega328P Development Board (Arduino Nano Compatible) with USB-C**

![Nano Board](3.%20Docs/photos/nano.PNG)

<br>

**Schematics**
![Schematic](3.%20Docs/photos/zhengbingquant_Nano_V1_schematic.png)

<br>

**PCB Layout**
![PCB Layout](3.%20Docs/photos/pcb_layout.png)

---

## Overview

**zhengbingquant_Nano_V1** is a fully DIY development board built around the **ATmega328P microcontroller**, designed for beginners interested in PCB design, microcontrollers, and electronics. This board features a **modern USB-C connector**, onboard voltage regulators, and is **compatible with Arduino Nano sketches and shields**.

This is my first self-designed PCB as a high school electronics enthusiast, intended to help beginners learn hardware design while exploring microcontroller projects.

> ⚠️ **Disclaimer:** This board is **Arduino Nano compatible** but is **not made, endorsed, or affiliated with Arduino**.

---

## Features & Specifications

| Feature                    | Specification |
|-----------------------------|---------------|
| **Microcontroller (MCU)**   | ATmega328P |
| **Architecture**            | 8-bit AVR RISC |
| **Clock Speed**             | 16 MHz |
| **Flash Memory**            | 32 KB (2 KB used by bootloader) |
| **SRAM**                    | 2 KB |
| **EEPROM**                  | 1 KB |
| **Digital I/O Pins**        | 14 (PWM: 6) |
| **Analog Inputs**           | 6 |
| **USB-to-Serial**           | CH340C (USB-C connector) |
| **Voltage Regulators**      | 5V & 3.3V |
| **VIN Input**               | 7–12V recommended |
| **Pin Headers**             | Standard male (breadboard-friendly) |
| **Built-in LED**            | Pin 13 |
| **SMD Package Sizes**       | Mostly 0806 (beginner-friendly) |
| **Form Factor**             | Arduino Nano compatible |

---

## Step-by-Step Guide

### 1. Solder the Board
- Begin with **SMD components** (resistors, capacitors, ICs).  
- Use the **SMD soldering assistant tool in EasyEDA Pro** for accurate placement.  
- Then solder **through-hole components** like male pin headers.  
- Double-check **polarized components** (LEDs, diodes, ICs).  
![Soldering Assistant](3.%20Docs/photos/soldering_assistant_tool.png)

---

### 2. Burn the Bootloader

**Why:** Freshly soldered board has no bootloader and cannot run sketches.

**Requirements:** Arduino UNO, USB-C cable, Arduino IDE

#### 2.1 Open ISP Example
- Arduino IDE → **File → Examples → 11.ArduinoISP → ArduinoISP**  
![ISP Program](3.%20Docs/photos/isp_program.png)

#### 2.2 Connect UNO to Board (using pins printed on the Nano layout)

| UNO Pin | Board Pin |
|---------|-----------|
| D10     | RESET     |
| D11     | D11       |
| D12     | D12       |
| D13     | D13       |
| 5V      | 5V        |
| GND     | GND       |

![Connection Diagram](3.%20Docs/photos/nano_connected_to_uno.png)

#### 2.3 Upload "Arduino as ISP" to UNO
- Select **Arduino UNO** board and correct COM port.  
- Compile and upload the **ArduinoISP** sketch.

#### 2.4 Burn Bootloader
- Keep UNO connected to the board and PC.  
- Arduino IDE → Board: **Arduino Nano**, Processor: **ATmega328P (Old Bootloader)**  
- Click **Burn Bootloader**.  
![Burn Bootloader](3.%20Docs/photos/burn_bootloader.png)  
- When console shows `"avrdude done"`, bootloader is installed.

---

### 3. Test Your Board
- Open the **Blink** example in Arduino IDE.  
- Upload via **USB-C cable**.  
- The built-in LED on **pin 13** should blink:

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```

---

### 4. You're Ready!

Your **zhengbingquant_Nano_V1** is now fully functional. With USB-C and Arduino compatibility, it's ready for your experiments, learning, and projects.

---

## Purpose

This project serves as a stepping stone for beginners to dive into PCB design and microcontroller programming. It bridges the gap between learning electronics and practical application, while also being a foundation for future mechanical engineering projects that integrate electronics.