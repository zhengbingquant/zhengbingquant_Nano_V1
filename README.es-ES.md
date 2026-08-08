

# zhengbingquant_Nano_V1

Enlace de YouTube: https://youtu.be/o9jtSHh7a54?si=MYGmc70yYvMOVar3

Enlace de Bilibili: https://www.bilibili.com/video/BV1T5aczyE8L/?vd_source=7e806c69a8d91200bb913d5da4bf505b

**Placa de desarrollo DIY ATmega328P (Compatible con Arduino Nano) con USB-C**

![Nano Board](3.%20Docs/photos/nano.PNG)

<br>

**Diagrama Esquemático**
![Schematic](3.%20Docs/photos/zhengbingquant_Nano_V1_schematic.png)

<br>

**Diseño de PCB**
![PCB Layout](3.%20Docs/photos/pcb_layout.png)

---

## Descripción General

**zhengbingquant_Nano_V1** es una placa de desarrollo completamente DIY diseñada alrededor del **microcontrolador ATmega328P**, pensada para principiantes interesados en el diseño de PCBs, microcontroladores y electrónica. Esta placa cuenta con un **conector USB-C moderno**, reguladores de voltaje integrados y es **compatible con sketchs y escudos de Arduino Nano**.

Esta es mi primera placa de circuito impreso (PCB) diseñada por mí como entusiasta de la electrónica de secundaria, con el objetivo de ayudar a los principiantes a aprender diseño de hardware mientras exploran proyectos con microcontroladores.

> ⚠️ **Aviso legal:** Esta placa es **compatible con Arduino Nano**, pero **no está fabricada, respaldada ni afiliada con Arduino**.

---

## Características y Especificaciones

| Característica | Especificación |
|-----------------|----------------|
| **Microcontrolador (MCU)** | ATmega328P |
| **Arquitectura** | 8-bit AVR RISC |
| **Velocidad del reloj** | 16 MHz |
| **Memoria Flash** | 32 KB (2 KB utilizados por el bootloader) |
| **SRAM** | 2 KB |
| **EEPROM** | 1 KB |
| **Pines de E/S Digital** | 14 (PWM: 6) |
| **Entradas Analógicas** | 6 |
| **USB a Serie** | CH340C (conector USB-C) |
| **Reguladores de Voltaje** | 5V & 3.3V |
| **Entrada VIN** | 7–12V recomendado |
| **Cabezales de Pines** | Macho estándar (compatible con protoboard) |
| **LED Integrado** | Pin 13 |
| **Tamaños de Paquetes SMD** | Principalmente 0806 (amigable para principiantes) |
| **Factor de Forma** | Compatible con Arduino Nano |

---

## Guía Paso a Paso

### 1. Soldar la Placa
- Comienza con los **componentes SMD** (resistencias, capacitores, circuitos integrados).  
- Usa la **herramienta de asistencia para soldar componentes SMD en EasyEDA Pro** para una colocación precisa.  
- Luego suelda los **componentes de paso (through-hole)** como los cabezales de pines macho.  
- Verifica dos veces los **componentes polarizados** (LEDs, diodos, ICs).  
![Soldering Assistant](3.%20Docs/photos/soldering_assistant_tool.png)

---

### 2. Grabar el Bootloader

**¿Por qué?:** La placa recién soldada no tiene bootloader y no puede ejecutar sketchs.

**Requisitos:** Arduino UNO, cable USB-C, Arduino IDE

#### 2.1 Abrir ejemplo ISP
- Arduino IDE → **File → Examples → 11.ArduinoISP → ArduinoISP**  
![ISP Program](3.%20Docs/photos/isp_program.png)

#### 2.2 Conectar UNO a la Placa (usando los pines impresos en el diseño de Nano)

| Pin UNO | Pin de la Placa |
|---------|-----------------|
| D10     | RESET           |
| D11     | D11             |
| D12     | D12             |
| D13     | D13             |
| 5V      | 5V              |
| GND     | GND             |

![Connection Diagram](3.%20Docs/photos/nano_connected_to_uno.png)

#### 2.3 Subir "Arduino as ISP" al UNO
- Selecciona la placa **Arduino UNO** y el puerto COM correcto.  
- Compila y sube el sketch **ArduinoISP**.

#### 2.4 Grabar Bootloader
- Mantén el UNO conectado a la placa y al PC.  
- Arduino IDE → Placa: **Arduino Nano**, Procesador: **ATmega328P (Old Bootloader)**  
- Haz clic en **Burn Bootloader**.  
![Burn Bootloader](3.%20Docs/photos/burn_bootloader.png)  
- Cuando la consola muestre `"avrdude done"`, el bootloader estará instalado.

---

### 3. Probar tu Placa
- Abre el ejemplo **Blink** en Arduino IDE.  
- Sube el código mediante el **cable USB-C**.  
- El LED integrado en el **pin 13** debería parpadear:

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

### 4. ¡Ya estás listo!

Tu **zhengbingquant_Nano_V1** ahora está completamente funcional. Con USB-C y compatibilidad con Arduino, está lista para tus experimentos, aprendizaje y proyectos.

---

## Propósito

Este proyecto sirve como un primer paso para que los principiantes se sumerjan en el diseño de PCBs y la programación de microcontroladores. Cierra la brecha entre el aprendizaje de la electrónica y su aplicación práctica, mientras también sirve como base para futuros proyectos de ingeniería mecánica que integren electrónica.
