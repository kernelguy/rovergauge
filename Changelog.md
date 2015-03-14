### 0.7.2 ###
  * Fixed MIL display bug

### 0.7.1 ###
  * Fixed MAF CO trim display bug when in open loop mode

### 0.7.0 ###
  * Added display for injector pulse width / duty cycle
  * Added option to display more accurate "soft" fuel map cell highlight
  * Fixed fuel map multiplier display bug
  * Fixed 16-bit "Ident" value width
  * Changed to more efficient scheduler for updating sensor data

### 0.6.0 ###
  * Added display of MAF CO trim (only when open loop)
  * Added display for tune ident byte, as well as checksum fixer byte
  * Switched to "odd" / "even" terminology when referring to cylinder banks as this is unambiguous
  * Fixed minor bug with fuel pump run request
  * Fixed fault code descriptions for bank-specific faults
  * Switched to version 5 of Qt framework and to Windows 7 for Win32 builds
  * Incorporated several minor build process updates

### 0.5.1 ###
  * Added option to periodically refresh fuel map data

### 0.5.0 ###
  * Added RPM labels in header row for fuel map
  * Added Windows batch files to make building from source easier
  * Automatic resizing of fuel map display with main window
  * Now using libcomm14cux 1.0.0 back-end (written in pure C)

### 0.4.1 ###
  * Added 'idle' light, which will be lit when the ECU is working to maintain idle. Adjacent to this, the current target idle speed is displayed.
  * Added online help documentation.
  * Added Malfunction Indicator Lamp (MIL).
  * Updated code that reads the tune number; this is now done on the order of milliseconds and no longer requires reading the entire ROM image.
  * Removed setting for the maximum value on the speedometer gauge. The max value is now defaulted to 160 (for MPH) or 240 (for km/h and ft/s.)

### 0.4.0 ###
  * Added capability of disabling certain readings. This can result in a large speed increase when updating the readings that are left active.

### 0.3.5 ###
  * Fixed the polarity of the short-term lambda trim (which was inverted) and added labels to reduce ambiguity
  * Added a tune-detection feature that identifies the tune stored in the connected ECU -- note that I will need to collect more properly-labeled PROM images for this to be comprehensive!

### 0.3.4 ###
  * Added a switchable option for throttle position display (absolute versus corrected)

### 0.3.3 ###
  * Added a switchable display for lambda trim (short-term and long-term)
  * Added a switchable display for the MAF reading (direct and linearized)
  * Added support for several more fault codes, along with the numeric IDs for all of the faults
  * Miscellaneous bug fixes, including a default log filename that will work under Windows

### 0.3.2 ###
  * Added displays for left and right fuel trim based on lambda sensor feedback. This data is stored in a battery-backed portion of RAM and does not often change after it has been determined by the ECU.

### 0.3.1 ###
  * Under Windows, the user-settings file was being written with extra backslashes prefixing the COM port name. This version corrects that problem. The user should open the Settings dialog and re-select the correct COM port.

### 0.3.0 ###
  * Added a display for target idle speed.
  * Added two buttons for fuel-pump control: one to run the pump for a single timeout period (2-3 seconds), and one to run continuously (until the button is clicked again.) These have no effect when the pump is already running.
  * Added a feature (under the Options menu) to control the position of the idle air bypass valve. This may produce unpredictable behavior if used while the engine is running, so it is best tested with ignition on but the engine stopped.
  * Rewrote the logging function with better design.