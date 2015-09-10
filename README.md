# arduino-mvg
Arduino-Code to display the time of arrival for the MVG (Münchner Verkehrsgesellschaft)

### Hardware
To run this code you need:
  - Arduino UNO
  - Adafruit NeoPixel Shield for Arduino
  - Arduino Ethernet Shield
 
### Install

 - Modify the network.ino file in the following way:
   - add your station to the field "$INSERTSTATIONNAME$" (e.g. "Westendstraße")
   - add the target of your line in the field "$INSERTDIRECTION$" (e.g. "Laimer Platz")
  - Compile the code by opening all files in the arduino ide
  
### Known Bugs / Limitation
 - This code is kept very simple but works for me, to enable umlauts it might require some modifcations
 - Also the idea was to have many states (mvg,weather,transitions with animation) but that was to much irritation.
   
  

