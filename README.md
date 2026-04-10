# Arduino-VU-Meter

An interactive **7-Level VU Meter** (Volume Unit Meter) built with an Arduino. I used an UNO, but I guess you can make it work with whatever you have and adjust the code as necessary. And a High-Sensitivity Sound Sensor. This project visualizes ambient sound levels in real-time using a sequence of LEDs that react to volume intensity.

## 🛠 Project Overview
This project uses an analog microphone module to detect sound pressure. The Arduino samples the audio input, calculates the average intensity, and maps it to a 7-step LED display. It's perfect for adding a visual "music-reactive" element to your desk setup.

## 🔌 Hardware Setup
* **Microcontroller:** Arduino Uno (or compatible)
* **Sensor:** High-Sensitivity Microphone Sensor (LM393)
* **Visuals:** 7x LEDs with 220Ω Resistors

### Pinout Configuration
| Component | Arduino Pin | Function |
| :--- | :--- | :--- |
| **Sound Sensor** | `A0` | Analog Signal Input |
| **LED 1** | `13` | Level 1 (Low) |
| **LED 2** | `12` | Level 2 |
| **LED 3** | `11` | Level 3 |
| **LED 4** | `10` | Level 4 (Mid) |
| **LED 5** | `9` | Level 5 |
| **LED 6** | `8` | Level 6 |
| **LED 7** | `7` | Level 7 (Peak) |

## 🚀 How it Works
The code performs high-speed sampling to ensure the VU meter is responsive but stable:
1. **Sampling:** It takes 100 analog readings of the environment.
2. **Averaging:** It calculates the mean value to filter out minor electrical noise.
3. **Logic:** It compares the average against set thresholds (100, 200, 300, 350, 400, 450, 500).
4. **Output:** LEDs light up sequentially as the volume increases.

## ⚙️ Calibration
If the LEDs stay on or don't light up at all, use a small screwdriver to turn the **potentiometer** (the small brass screw on the blue component of the sensor). 
* **Clockwise:** Increases sensitivity.
* **Counter-clockwise:** Decreases sensitivity.

## 💻 Code Snippet
The logic uses a simple `if/else` structure to drive the VU display based on the `sum` of the averaged samples:

```cpp
sum = sum/100; // Average the sample of sound

if (sum >= 100) digitalWrite(LED1, HIGH); else digitalWrite(LED1, LOW);
// ... continues for all 7 LEDs
