<div align="center">
<h1 style="font-size:10vw">Data Storage Module Requirement Analysis</h1>

<div align="left">

**Subsystem:** Data Storage Module
	
**Last date of revision:** 09-02-2023
	
**Document status:** Draft
	
**Authors:** Thiruvarulselvan K, Srinivasan S
  
**Revision history:**
	
_1. First draft completion - Srinivasan S - 31/01/2023_
	
_2. Second draft - Included more requirements - Thiruvarulselvan K - 03/02/2023_
	
_3. Addition of Model diagram – Thiruvarulselvan K – 11/02/2023_


**Abbreviations**:
	
CPM - Central Processing Module
	
DSM - Data Storage Module
	
RTC - Real Time Clock

**Purpose of the subsystem:**
	
CPM processes the data acquired from the sensor and gives it as output. The output needs to be stored into the Data Storage Module so that it can be further analyzed, and reused. The history of stored data plays a vital role in analysing the performance of the subsystem.

  | Type  | Requirement | Priority |
| ------------- | ------------- | ------------- |
Functional|	Store the incoming data in the memory	|Core|
Functional|	We are having a database which is of size x, the size of memory can be 2x or more in order to avoid space scarcity issues in the future.|	Desired|
Functional|	Transfer the required data on request|	Core|
Operational|	Receive the data transmitted from the CPM via communication bus	|Core|
Operational|	The data should be retained in the case of power outage|	Essential|
Operational|	Read and transfer the data in a particular memory sector back to the CPM on command|	Essential|
Operational|	Should be powered by the CPM output power supply	|Desired|
Operational|	RTC should measure the time and communicate with the CPM|	Core|
Operational|	RTC should continue the measurement in the case of a power outage by using the backup battery	|Desired|
Operational|	Store the received data in the particular memory sector|	Essential|
Operational|	Detect the status or any faults in the DSM and report to the CPM|	Desired|
Operational|	Detect the status or any faults in the RTC and report to the CPM	|Desired|
Operational|	Receive time data and change the time settings when commanded by the CPM	|Desired|
Technical|	The DSM should support the communication protocol that the CPM will use	|Core|
Technical|	The RTC should support the communication protocol that the CPM will use	|Core|
Technical|	The RTC should be powered by the CPM power supply output	|Desired|


**Subsystem model:**
 ![DSM Model](https://user-images.githubusercontent.com/109530150/221361500-62d27cf0-c08d-4ce0-b47e-23442d690330.png)
<div align="center">
<h1 style="font-size:1vw">Figure 1. DSM Model</h1>
	



