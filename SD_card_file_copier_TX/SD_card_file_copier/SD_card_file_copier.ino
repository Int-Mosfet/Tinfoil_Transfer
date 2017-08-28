#include <SD.h>
#include "SD.h"
#include <SPI.h>

void setup() {

 Serial.begin(115200);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
  }
 if (!SD.begin(10)) {

Serial.println("begin failed");
return;
   }

File file = SD.open("DATA.CSV",FILE_READ);
//File endFile = SD.open("COPY.CSV",FILE_WRITE);
 Serial.flush();

char buf[64];
/*if(file) {  

            while(file.position() < file.size())
            {
                int bytesRead = file.readBytes(buf, sizeof(buf));
                //progress %
                //use an LED in future
                //Serial.println(((float)file.position()/(float)file.size())*100);

                // We have to specify the length! Otherwise it will stop when encountering a null byte...
                endFile.write(buf, bytesRead);

                delay(50); 
            }
         }
       file.close();
       endFile.close();
        */
        
        
        //File endFile2 = SD.open("COPY.CSV",FILE_READ);
        //File endFile2 = SD.open("IMG.JPG",FILE_READ); //jpg's don't work, compressed etc..
        File endFile2 = SD.open("DATA.CSV",FILE_READ);

        if(endFile2)
        {
          while(endFile2.position() < endFile2.size())
          {
            int serialBytes = endFile2.readBytes(buf, sizeof(buf));
            //progress %
            //use an LED in future
            //Serial.println(((float)endFile2.position()/(float)endFile2.size())*100);
            Serial.write(buf, serialBytes);
            delay(50);
          }
        }

       endFile2.close();

       //tell receiver to close file
       //Serial.write("done");
       //Serial.write("\n");
}


   void loop() { }
