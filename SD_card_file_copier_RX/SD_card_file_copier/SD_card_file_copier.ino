#include <SD.h>
#include "SD.h"
#include <SPI.h>

void setup() {

 Serial.begin(115200);
while (!Serial) {
; // wait for serial port to connect. Needed for nat ive USB port only
  }
 
 if (!SD.begin(10)) {

Serial.println("begin failed");
return;
   }

}

void loop() { 
    File OpenFile = SD.open("MYFILE.CSV", FILE_WRITE);

    if(OpenFile){
      while(Serial.available()){
        char cin = Serial.read();
        //delay(50);
        //OpenFile.println(Serial.read());
        OpenFile.print(cin);
      }
      OpenFile.close();
      }
  
  }

  

