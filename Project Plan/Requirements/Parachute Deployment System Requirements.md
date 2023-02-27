<div align="center">
<h1 style="font-size:10vw">Parachute Deployment System Requirement Analysis Document</h1>

<div align="left">
  
**Revision history:**
  
_1. First draft completion- 01/02/2023_

**Subsystem:** Parachute Deployment System
  
**Last date of revision:** 01-02-2023
  
**Document status:** Draft

**Abbreviations:**
  
PDS - Parachute Deployment Systems
  
CPM - Central Processing Module

**Purpose of the subsystem:**
  
PDS deploys the parachute while falling back after reaching the apogee.

| Type  | Requirement | Priority |
| ------------- | ------------- | ------------- |
Functional|	Deploy the onboard parachute to recover the rocket after reaches the apogee and during emergency failsafe deployment.	|Core|
Functional|	Effective actuation method to avoid deployment failure	|Core|
Functional|	Update the system status to the ground station	|Desired|
Operational|	Share the PDS status with CPM including any fault status|	Desired|
Operational|	Trigger the deployment actuator when commanded by CPM|	Core|
Technical|	The actuator/igniter should be powered by the onboard power system	|Core|
Technical|	A sensing unit inside the PDS should detect and communicate the deployment status to the CPM	|Desired|


**Subsystem model:**



