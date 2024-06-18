# AI Home Project

**Developer:** Mahendra Mali, Gujarat

## Overview

The AI Home Project is a smart home automation system designed to control 32 relays using an Arduino Mega and an ESP-01 module. The system utilizes JSON data transmitted via serial communication to manage various appliances connected to the relays.

## Components

- **Arduino Mega**: The main microcontroller that controls the relays.
- **ESP-01 Module**: Used for wireless communication with the Arduino.
- **32 Relays**: Connected to the Arduino Mega to switch appliances on and off.
- **EEPROM**: Stores the state of each relay to maintain the settings across power cycles.

## Connections

- **Relays**: Connected to Arduino pins 22 through 53.
- **ESP-01 Connections**:
  - ESP-01 RX -> Arduino Mega TX1 (pin 18)
  - ESP-01 TX -> Arduino Mega RX1 (pin 19)

## Key Points

- **Relay Control**: The system controls 32 relays based on data received from the ESP-01.
- **EEPROM Usage**: The state of each relay is stored in EEPROM, allowing the system to remember the last state of each relay even after a power cycle.
- **Active LOW Relays**: The relays are assumed to be active LOW, meaning they turn on when the pin is set to `LOW`. Adjust the logic if your relays are active HIGH.
- **Serial Communication**: The ESP-01 module communicates with the Arduino Mega via the Serial1 interface, sending JSON formatted data to control the relays.

## Latest Update

**Date:** June 16, 2024

### AI Home Project Update: Enhanced Relay Control and System Stability

The latest update to the AI Home Project introduces improved relay control mechanisms and increased system stability. Users can now enjoy more reliable home automation with enhanced performance and better data retention across power cycles.

### New Textview Release

Experience the upgraded textview feature that provides clearer status updates and more intuitive control over your home automation system. This enhancement ensures seamless interaction and a better user experience.

## Android App for Controlling Relays

Control your home automation system conveniently using the newly released Android app. The app allows users to:

- **Monitor and control** all 32 relays from their mobile device.
- **Receive real-time updates** on the status of each relay.
- **Intuitive Interface**: Easy to use and navigate, providing a seamless user experience.

Download the app to enhance your smart home experience and manage your appliances effortlessly.
