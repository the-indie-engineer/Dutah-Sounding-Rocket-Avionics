<div align="center">
<h1 style="font-size:10vw">Central Processing Module Requirement Analysis</h1>

<div align="left">
  
**Subsystem:** Central Processing Module
  
**Last date of revision:** 02-01-2023
  
**Document status:** Draft

**Revision history:**
  
_1. First draft completion - 02/02/2023_

**Abbreviations:**
  
PDS - Parachute Deployment Systems
  
CPM - Central Processing Module
  
ISU - Inertial Sensing Unit
  
DSM - Data Storage Module
  
MFS - Motor Firing System
  
RTC - Real Time Clock

**Purpose of the subsystem:**
  
Processing the ISU data, managing the data in the storage, and controlling the Parachute Deployment System (PDS) and Motor Firing System (MFS).

  | Type  | Requirement | Priority |
| ------------- | ------------- | ------------- |
|Functional	|Acquiring data from Inertial Sensing Unit (ISU)	|Core|
|Functional|	Store the ISU data in Data Storage Module (DSM) and retrieve back when needed |	Core|
|Functional	|Command the Parachute Deployment System(PDS) for chute ejection while falling back|	Core|
|Functional	|Command the Motor Firing System (MFS) to launch the rocket on ignition	Core|
|Functional|	Controller is in a compact size to fit inside a sounding rocket	|Core|
|Functional|	Have hardware compatibility with ISU, DSM, PDS, and MFS|	Desired|
|Functional|	Support future requirement updations|	Desired|
|Functional|	Minimum possible power consumption	|Desired|
|Operational|	Convert the analog signals from ISU to digital signals with required resolution|	Essential|
|Operational|	Supply necessary power to ISU, DSM, PES, and MFS	|Desired|
|Operational|	Support required communication protocols for data transfer	|Essential|
|Operational|	Generate driving signals for PDS	|Desired|
|Operational|	Contain enough memory for ROM and RAM access	|Essential|
|Operational|	Enabling and accessing the hardware in the hardware layer	|Core|
|Operational|	Actuate the PDS actuator/igniter when the projectile reaches the specific deceleration value|	Core|
|Operational|	Record the PDS feedback signals and send to DSM|	Desired|
|Operational|	Actuate the PDS actuator/igniter on emergency deploy command as an interrupt|	Essential|
|Operational|	Detect and process the status/fault of the PDS|	Desired|
|Operational|	Detect and process the status/fault of the PDS	|Desired|
|Operational|	Perform Pre-flight checks when pre launch command is given	|Essential|
|Operational|	Fire the igniter on launch command, after preflight checks|	Core|
|Operational|	Record the launch sequence data and send it to DSM	|Essential|
|Operational|	Enabling the hardware and acquire data from all the sensors in software layer|	Core|
|Operational|	Filter the noise in the sensor data before further processing|	Desired|
|Operational|	Perform basic data manipulations on the data for further processing, convert the data to specific standard range	|Desired|
|Operational|	Test for sensor fault in various levels and indicate it with error codes	|Desired|
|Operational|	Enable the storage hardware for reading and writing the data from ISU, PDS, and MFS	|Core|
|Operational|	Prepare the data in a structured format mapped along with time data	|Desired|
|Operational|	Enable and access the Real-time clock module to get time data	|Essential|
|Operational|	Store the data in a reliable and human-readable format	|Desired|
|Operational|	The reliable format should be compatible for later processing and sending to ground station|	Desired|
|Operational|	Check the available space for writing the data	|Desired|
|Operational|	Allow to set the time data in the RTC when commanded	|Desired|
|Operational|	Indicate any error in software or hardware level	|Desired|
|Technical	|Availability of n number of ADC channels with desired resolution for n number of analog sensors|	Core|
|Technical|	Should provide required clock pulse of desired frequency  to each sensor|	Core|
|Technical|	Should support required communication protocols|	Core|
|Technical|	Should generate actuator specific modulate signals for the operation	|Desired|
|Technical|	Should provide required different voltage level output supply	|Core|

**Subsystem model:**

![Dutah System Model Jan 2023](https://user-images.githubusercontent.com/109530150/219958351-f7c2749f-0156-410c-bc6f-26a42b6d559e.jpeg)
<div align="center">
<h1 style="font-size:10vw">Credits: Thiruvarulselvan K</h1>

