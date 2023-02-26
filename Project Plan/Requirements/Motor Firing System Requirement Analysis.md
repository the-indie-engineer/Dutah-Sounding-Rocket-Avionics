<div align="center">
<h1 style="font-size:10vw">Motor Firing System Requirement Analysis</h1>

<div align="left">
  
**Subsystem:** Motor Firing System
  
**Last revision date:** 14-02-2023
  
**Document status:** Draft
  
**Author(s):** Thiruvarulselvan K

**Abbreviations:**
  
CPM - Central Processing Module
  
MFS - Motor Firing System

**Revision history:**
  
_1. First draft completion- 01/02/2023_
  
_2. Changed the requirements (onboard power supply cannot power the igniter), Addition of human interaction and indication requirements - Thiruvarulselvan K - 12/02/2023_

_3. Update the requirements and system model, two individual units in MFS - Thiruvarulselvan K - 14/02/2023_


**Purpose of the subsystem:**
  
MFS - Fires the motor on launch command from the ground control station.

  | Type  | Requirement | Priority |
| ------------- | ------------- | ------------- |
Functional|	Fire the motor on launch command from the user using the onboard high voltage power source|	Core|
Functional|	Effectively handle any failure of the firing system beforehand and update the system status to the ground|	Core|
Functional|	Shall have safety features for handling any accidental launch or short circuit events |	Desired|
Operational|	The MFS onboard unit should sense the status of the motor firing element and high power source|	Desired|
Operational	|The MFS ground unit should interact with the user to receive launch commands|	Core|
Operational|	The MFS onboard unit should fire the motor when remotely commanded by the MFS ground unit. |	Core|
Operational|	Indicate the onboard system status to the ground unit wirelessly via RF link.|	Essential|
Operational|	The ground unit shall have various indication elements to ease the process of user understanding of the system status|	Desired|
Technical|	The MFS should be able to handle the high power flow to the igniter and should be galvanically isolated from the high voltage system	|Essential|
Technical|	The microcontroller should be powered by the same power source as the igniter	|Desired|

**Subsystem model:**
  ![MFS Model](https://user-images.githubusercontent.com/109530150/221415160-4cafba07-4404-4737-9a56-9905f5c77f1e.png)
<div align="center">
<h1 style="font-size:1vw">Figure 1. MFS Model</h1>
