# Frequently Asked Questions #

**Q: How do I connect my PC to the 14CUX ECU?**

**A:** There's a beige 5-pin "TTS" connector in the wiring harness, typically somewhere in the cabin of the vehicle. You'll need to build a cable with the matching connector, a USB-to-serial converter, and an attenuation resistor. Details are on the libcomm14cux wiki's [HardwareInterface](http://code.google.com/p/libcomm14cux/wiki/HardwareInterface) page.


---


**Q: Is this an alternative to OBD-II code readers or OBD-II diagnostic software?**

**A:** No. The 14CUX system doesn't conform to the OBD-II standard. This software uses a library that I wrote specifically to communicate with the 14CUX, using the ECU's unusual baud rate and proprietary software protocol. The details of all of this were discovered through reverse-engineering the code in the 14CUX PROM.

As far as I know, the library I wrote (named "[libcomm14cux](http://code.google.com/p/libcomm14cux)") is only useful for communicating with the Lucas 14CUX (and probably the earlier 14CU.) If you are aware of any other engine management system that uses the same software protocol, please let me know; it might be possible to expand the capability of the library to other systems.

I've heard that the engine management system used by Jaguar for their AJ6 inline-six engine (with distributor ignition) is related to the 14CUX. If you have more information about this, please contact me!


---


**Q: Can this software be used to modify the code or data in the ECU (such as the fuel maps)?**

**A:** Unfortunately, no. When the ECU is running, it reads fueling values from the PROM. Modifying the PROM requires removing and reprogramming the chip.


---


**Q: What does the MAF reading represent?**

**A:** It simply shows the MAF sensor voltage as a percentage of the highest possible measurement. A reading of 100% indicates that the system is measuring as much airflow as it can. The "Direct" reading is a voltage-based measurement (which changes non-linearly with respect to airflow), while the "Linearized" reading has been corrected to change linearly with airflow.


---


**Q: What does the idle-bypass reading represent?**

**A:** This shows the position of the idle bypass motor in the intake plenum. A reading of 100% is fully open (where the motor should be on startup) and 0% is fully closed (although the motor should generally not reach this position while running.)


---


**Q: Why are the fueling values in the fuel map fairly constant across the engine speed range?**

**A:** Those values represent a fueling quantity for a particular injector pulse; thus, they are independent of engine speed. In other words, when a given cylinder fires once, it will burn approximately the same amount of fuel regardless of the speed at which the engine is turning. Engine _load_, however, has a large effect on the fueling values. This can be seen by comparing values in the top row of the fuel map to values in the bottom row.