# Nodeumc-ESP8266-module-wifi-comunicate-codes
# ESP8266 PIR Motion Sensor Communication

## Project Description
This repository contains the code and documentation for a project involving the ESP8266 Wi-Fi module and a PIR (Passive Infrared) motion sensor. The project aims to detect motion using the PIR sensor and communicate the motion data to a server over a Wi-Fi connection. The ESP8266 connects to the local Wi-Fi network and sends motion data to a designated server IP address and port.

## Hardware Setup
- Connect the PIR motion sensor to the digital pin D0 of the ESP8266.
- Ensure the ESP8266 module is properly powered and connected to the Wi-Fi network.

## Prerequisites
- Install the Arduino IDE and necessary libraries, including `ESP8266WiFi`.

## Usage
1. Open the `motion_sensor.ino` file in the Arduino IDE.
2. Replace `--SSID--` and `*********` with your Wi-Fi network SSID and password.
3. Modify `serverIP` with the IP address of the server where motion data will be sent.
4. Upload the code to the ESP8266 module.
5. Open the serial monitor to view the Wi-Fi connection status and server responses.
6. When motion is detected, the LED connected to pin D0 will turn on, and the code will send '1' to the server. When no motion is detected, the LED will turn off, and '0' will be sent.
7. Responses from the server will be displayed in the serial monitor.

## Author
[Your Name]

## License
This project is licensed under the [MIT License](LICENSE).

## Contact
For inquiries, please contact [your.email@example.com](mailto:your.email@example.com).

## Repository Structure
- `motion_sensor.ino`: The Arduino sketch file containing the code for motion detection and Wi-Fi communication.
- `LICENSE`: The license file for the project.
- `README.md`: This README file providing an overview of the project.

For more details, check the [GitHub repository](https://github.com/your-username/your-repo-name).

