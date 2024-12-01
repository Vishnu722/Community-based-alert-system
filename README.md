## **Community based notification alert system using SIM900A-GSM modeule**

## **Overview**
  This project is a Community-Based Notification Alert System designed to send automated SMS alerts for environmental and safety monitoring. It integrates temperature monitoring, earthquake detection, and GSM-based SMS notifications. The prototype is intended for deployment in public places such as hospitals, schools, colleges, and government offices for early warnings and emergency alerts.
  
## **Features:**
1. Temperature Monitoring:
   . Continuously measures ambient temperature using a DS18B20 sensor.
   . Sends an SMS alert if the temperature exceeds a defined threshold (e.g., 32°C).
2. Earthquake Detection: Detects seismic activity using an MPU6050 sensor and sends immediate alerts.
3. Automated SMS Notifications: Utilizes a SIM900A GSM module to send SMS alerts to a predefined phone number.
4. Community Safety: Provides real-time warnings for environmental hazards to improve public safety.

## **Hardware Components:**
1. SIM900A GSM Module
2. DS18B20 Temperature Sensor
3. MPU6050 Accelerometer and Gyroscope Sensor
4. Arduino Uno or similar microcontroller
5. Power supply
6. Connecting wires and breadboard

## Software Requirements
1. Arduino IDE (v1.8.0 or later)
2. Libraries:
   . OneWire (for DS18B20 sensor)
   . DallasTemperature (for temperature readings)
   . MPU6050_tockn (for MPU6050 sensor)
   . SoftwareSerial (for GSM communication)

## **Usage**
1. Deploy the system in a public area.
2. Power up the hardware and ensure GSM connectivity.
3. Monitor the system for SMS alerts in case of:
    . High temperatures exceeding the threshold.
    . Seismic activity indicative of an earthquake.

**Applications**
  1. Hospitals: Early warnings for temperature and seismic activity.
  2. Government Schools: Enhancing safety for children and staff.
  3. Colleges: Creating awareness and ensuring timely evacuation.
  4. Public Spaces: Alerting large gatherings to emergencies.

## **Future Enhancements**
1. Integrate gas or smoke detection for fire safety.
2. Add location tracking to SMS alerts for pinpointing incidents.
3. Enhance scalability by integrating LoRa or Wi-Fi for large-scale deployments.
4. Develop a mobile application for real-time monitoring.
