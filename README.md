# Data-Acquisition-and-Recovery-System-for-sounding-rockets-Dutah-

<h2>Repository is under creation</h2> Visit this Google drive to view the entire project: https://drive.google.com/drive/folders/1wfT9WuIFDmx0iOykMR6UksmvyKWEeXo3?usp=sharing

This repository presents the design and development of a comprehensive data acquisition and recovery system for model-sounding rockets using the STM32 microcontroller. The system includes various sensors such as pressure, humidity, atmospheric temperature, motor temperature, gyro, attitude, altitude, vibration, voltage, and current sensors to collect flight data. The collected data is stored on an SD card module and transmitted to the ground station using an RF link. Additionally, a GPS module is integrated into the system to track the rocket's position and altitude during flight. The system also includes an onboard ignition system and wireless launch sequence. The ground control system (GCS) enables users to remotely control the launch sequence and displays the motor firing system status. The GCS also provides a wireless interface for transmitting the launch sequence to the onboard ignition system. The parachute deployment system is activated based on the altitude sensor data to recover the rocket after landing. The system has been tested with multiple conditions, demonstrating accurate data collection and recovery capabilities. The presented system proposes a reliable and efficient solution for model-sounding rocket data acquisition, recovery, and launch control.

<h2>System Descriptions</h2>

<h2>Central Processing Module:</h2>

Processing the ISU data, managing the data in the storage, and controlling the Parachute Deployment System (PDS) and Motor Firing System (MFS).

<h2>Inertial Sensing Unit</h2>

Measure the essential parameters of the rocket and communicate with the CPM 

<h2>Data Storage Module</h2>

CPM processes the data acquired from the sensor and gives it as output. The output needs to be stored into the Data Storage Module so that it can be further analyzed, and reused. The history of stored data plays a vital role in analysing the performance of the subsystem.

<h2>Motor Firing System</h2>

MFS - Fires the motor on launch command from the ground control station.
