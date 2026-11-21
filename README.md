# Smart Supermarket Energy Monitoring Using KiwisIoT

A simple IoT project to monitor current and estimate power consumption using an ESP8266 NodeMCU, ACS712 current sensor, and KiwisIoT.

## About the Project

This project focuses on monitoring electrical current and estimating power consumption using IoT technology. The ESP8266 NodeMCU reads the analog output from an ACS712 current sensor, processes the readings, and sends current and estimated power values to the KiwisIoT dashboard through Wi-Fi.

The system provides a simple way to visualize electrical measurements remotely and demonstrates how IoT can be used for energy monitoring applications.

## Features

Real-time current monitoring, estimated power calculation, wireless data transmission, cloud dashboard visualization, and remote electrical monitoring.

## Hardware Components

ESP8266 NodeMCU, ACS712 current sensor, jumper wires, USB cable, and a suitable low-voltage power source and load for testing.

## Circuit Connections

The ACS712 sensor VCC is connected to the compatible supply voltage, GND is connected to the NodeMCU GND, and OUT is connected to A0.

The current-carrying conductor is connected through the sensor's current measurement terminals according to the module's specifications.

For this demonstration, use a properly rated low-voltage circuit. Mains electricity should only be monitored using appropriately rated, isolated equipment and professionally installed connections.

## KiwisIoT Dashboard

The project sends the following data to the KiwisIoT dashboard:

Channel 0 – Current (A)

Channel 1 – Estimated Power (W)

The dashboard can display the current and estimated power readings using suitable numerical widgets, gauges, or charts.

## Working Principle

The ACS712 current sensor measures the current flowing through the monitored circuit and produces an analog voltage corresponding to the current.

The ESP8266 reads the analog signal, calibrates the zero-current voltage, and calculates the current using the sensor's configured sensitivity.

The system then estimates power using the configured voltage and measured current. The calculated current and power values are transmitted to KiwisIoT through Wi-Fi for remote visualization.

## Software Used

Arduino IDE, ESP8266 Board Package, KiwisIoT Arduino Library, and KiwisIoT Dashboard.

## Project Tutorial

Explore the project implementation and tutorial here:

**Smart Supermarket Energy Monitoring**

## Explore KiwisIoT

I use KiwisIoT to connect ESP8266 hardware with a cloud dashboard and monitor project data remotely. It makes IoT projects easier to visualize and helps build connected monitoring applications.

Website: https://www.kiwisiot.in/

Arduino Library: https://github.com/Kiwistron/KiwisIoT

Example Projects: https://github.com/Kiwistron/KiwisIoT-Projects/

## About the Author

I enjoy building IoT projects, experimenting with sensors and microcontrollers, and exploring ways to connect hardware with cloud platforms. I share my projects to help others learn, experiment, and build their own IoT applications.

---

Built with curiosity, sensors, and IoT.
