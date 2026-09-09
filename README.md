# Food Quality Prediction System

## 📌 Overview

The **Food Quality Prediction System** is an IoT-based embedded system designed to monitor important parameters related to food quality and freshness.

The system uses an **ESP32 microcontroller** along with multiple sensors to monitor moisture, gas concentration, temperature, and pH-related data. The collected sensor information is processed by the ESP32 and transmitted through wireless communication for monitoring and analysis.

When abnormal conditions indicating possible food contamination are detected, the system provides an alert using a buzzer and visual indication.

---

## 🎯 Objectives

The main objectives of this project are:

* Monitor important food quality parameters in real time.
* Measure moisture levels.
* Monitor temperature.
* Detect gases associated with possible food spoilage.
* Monitor pH-related data.
* Process sensor readings using an ESP32.
* Transmit sensor data wirelessly.
* Provide visual indication using NeoPixel LEDs.
* Provide an audible warning using a buzzer.
* Support remote monitoring of food quality information.

---

## ✨ Features

* ESP32-based embedded system
* Real-time sensor monitoring
* Moisture measurement
* Gas detection
* Temperature measurement
* pH data monitoring
* Bluetooth communication
* NeoPixel LED status indication
* Buzzer-based warning alert
* Serial communication
* Low-cost hardware implementation
* Suitable for IoT and embedded-system applications

---

## 🛠️ Hardware Components

| Component              | Purpose                      |
| ---------------------- | ---------------------------- |
| ESP32                  | Main microcontroller         |
| Moisture Sensor        | Measures moisture level      |
| MQ2 Gas Sensor         | Detects gases/smoke          |
| pH Sensor              | Measures pH-related data     |
| DS18B20                | Measures temperature         |
| NeoPixel LED           | Provides visual indication   |
| Buzzer                 | Provides audible warning     |
| 7805 Voltage Regulator | Provides regulated 5V supply |
| Power Supply           | Powers the system            |

---

## 💻 Software & Technologies

* Arduino IDE
* Embedded C/C++
* ESP32
* Bluetooth
* Serial Communication
* OneWire Library
* DallasTemperature Library
* Adafruit NeoPixel Library
* Proteus for circuit design/simulation

---

## 🔌 ESP32 Pin Configuration

The following pin configuration is used in the project code:

| Component                  | ESP32 GPIO |
| -------------------------- | ---------: |
| Moisture Sensor            |    GPIO 32 |
| MQ2 Gas Sensor             |    GPIO 35 |
| DS18B20 Temperature Sensor |    GPIO 14 |
| Buzzer                     |    GPIO 25 |
| Connection LED             |    GPIO 26 |
| NeoPixel LED               |    GPIO 27 |
| Serial RX                  |    GPIO 16 |
| Serial TX                  |    GPIO 17 |

---

## 🧩 System Components

### ESP32

The ESP32 acts as the main controller of the system. It reads sensor data, processes the readings, controls the indicators and communicates wirelessly.

### Moisture Sensor

The moisture sensor is used to monitor the moisture level associated with the food being tested.

### MQ2 Gas Sensor

The MQ2 gas sensor is used to detect gases and smoke. The sensor provides an analog output that can be read by the ESP32.

### DS18B20 Temperature Sensor

The DS18B20 is a digital temperature sensor using the 1-Wire communication protocol. It is used to measure the temperature associated with the food monitoring system.

### pH Sensor

The pH sensor provides pH-related information through the sensor interface and serial communication.

### NeoPixel LED

The NeoPixel LED provides visual status indication.

* Green indication → acceptable condition
* Red indication → abnormal condition
* White indication → warning/reset state

### Buzzer

The buzzer provides an audible warning when the system receives a contamination/warning condition.

---

## ⚙️ Working Principle

The system continuously monitors the food quality parameters using multiple sensors.

The ESP32 reads:

1. Moisture sensor data
2. Gas sensor data
3. Temperature data
4. pH-related data

The sensor information is processed by the ESP32.

The system then transmits the collected information through Bluetooth.

Based on the received status:

* `G` → NeoPixel displays green
* `B` → NeoPixel displays red
* `T` → NeoPixel returns to white and the buzzer is activated

The sensor data is periodically transmitted through Bluetooth for monitoring.

---

## 🔄 System Algorithm

1. Start the system.
2. Initialize the ESP32 pins.
3. Initialize Bluetooth communication.
4. Initialize the temperature sensor.
5. Initialize the NeoPixel LED.
6. Read the moisture sensor value.
7. Read the gas sensor value.
8. Read the temperature value.
9. Receive pH-related sensor data through serial communication.
10. Process the received sensor values.
11. Check for Bluetooth commands.
12. If `G` is received, display green using the NeoPixel.
13. If `B` is received, display red using the NeoPixel.
14. If `T` is received, display white and activate the buzzer.
15. Prepare the sensor data.
16. Transmit the data through Bluetooth.
17. Repeat the process continuously.

---

## 📊 Data Format

The system prepares sensor data in the following format:

```text
*M<moisture>*G<gas>*T<temperature>*P<pH>*
```

Example:

```text
*M450*G320*T28.50*P6.50*
```

The exact values depend on the sensor readings.

---

## 📡 Bluetooth Communication

The ESP32 Bluetooth device is initialized with the name:

```text
FOOD-QUALITY
```

The system uses Bluetooth communication to transmit sensor information and receive control/status characters.

---

## 💡 LED Status

| Received Character | LED Status | Function                    |
| ------------------ | ---------- | --------------------------- |
| `G`                | Green      | Normal/acceptable condition |
| `B`                | Red        | Abnormal condition          |
| `T`                | White      | Warning/reset state         |

---

## 🔔 Buzzer Alert

When the system receives the `T` command, the NeoPixel LED changes to white and the buzzer is activated to provide an audible warning.

The buzzer is controlled by the ESP32.

---

## 📐 Circuit Diagram

The circuit diagram of the project is available in:

```text
circuit/circuit_diagram.png
```

---

## 📷 Project Images

Project photographs and hardware images are available in:

```text
images/
```

Recommended images:

* Prototype
* ESP32 board
* Sensors
* Final output

---

## 📁 Project Structure

```text
food-quality-prediction-system/
│
├── README.md
│
├── src/
│   └── food_quality_system.ino
│
├── circuit/
│   └── circuit_diagram.png
│
├── images/
│   ├── prototype.jpg
│   ├── esp32.jpg
│   ├── sensors.jpg
│   └── output.jpg
│
├── docs/
│   └── project_report.pdf
│
└── LICENSE
```

---

## 🚀 How to Run the Project

### 1. Install Arduino IDE

Install Arduino IDE on your computer and configure it for ESP32 development.

### 2. Install Required Libraries

The project requires:

```text
BluetoothSerial
Adafruit NeoPixel
OneWire
DallasTemperature
```

### 3. Open the Source Code

Open:

```text
src/food_quality_system.ino
```

in Arduino IDE.

### 4. Select ESP32 Board

Select the appropriate ESP32 development board from:

```text
Tools → Board
```

### 5. Select COM Port

Connect the ESP32 to the computer and select the correct COM port.

### 6. Upload

Compile and upload the program to the ESP32.

### 7. Test the System

Connect the sensors and power the system.

The Bluetooth device should appear as:

```text
FOOD-QUALITY
```

---

## 📈 Advantages

* Real-time monitoring
* Early spoilage detection
* Multiple sensor parameters
* Wireless communication
* Visual alerts
* Audible alerts
* Cost-effective implementation
* Suitable for household and food-related applications
* Reduces potential food wastage through early detection

---

## ⚠️ Limitations

The project has several limitations:

* Sensor accuracy can vary depending on environmental conditions.
* Sensors require calibration and maintenance.
* The system depends on predefined data/conditions for quality assessment.
* External gases or sudden temperature changes may cause false alerts.
* The system does not identify specific bacteria or toxins.
* Cloud-based/remote functionality depends on network availability.

---

## 🔮 Future Applications

Possible future applications include:

* Smart refrigerators
* Food supply-chain monitoring
* Supermarket food-quality monitoring
* Grocery-store monitoring
* Food processing industries
* Automated food freshness alerts
* AI-assisted food quality analysis
* IoT-based food monitoring systems

---

## 👥 Project Team

* **Marwan Faisal AV**
* **Ujwal K Nambiar**
* **Abhinav T V**
* **Amruth V**

### Project Guide

**Mr. Praveen D Nair**

Head of Department, Electronics

**Taliparamba Arts & Science College**

---

## 🎓 Academic Project

This project was developed as part of the requirements for the:

**B.Sc. Degree in Electronics**

**Kannur University**

**Taliparamba Arts & Science College**

**2022–2025**

---

## 📄 Project Report

The complete project report is available in:

```text
docs/project_report.pdf
```

---

## 👨‍💻 Author

### Marwan Faisal AV

**Embedded Firmware Engineer | Electronics Graduate**

Areas of interest:

* Embedded Systems
* Embedded Firmware
* ESP32
* STM32
* IoT
* Microcontrollers
* Sensor Integration
* Hardware-Software Integration

---

## ⭐ Project Status

```text
Completed Academic Project
```
