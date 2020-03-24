# covid16_ventilatyor_vub

How to get this code on your system  
## instal sloeber

### download Sloeber  
goto http://eclipse.baeyens.it  
select install in the top menu  
select your os  
download the file  
unpack the file  
When there are problems see http://eclipse.baeyens.it/installAdvice.shtml for general and os specific info  
  
--windows--  
use 7zip to untar and unzip the file (this is 2 steps)  
Make sure sloeber is installed close to the root of the disk to avoid windows path limitations  
more windows specific info at   
  
--mac--  
read the mac section on
use gunzip -c V4.3.2_mac64.2019-10-07_08-26-30.tar.gz | tar xf - to unzip see https://github.com/Sloeber/arduino-eclipse-plugin/issues/1141#issuecomment-580783280 for more info  
http://eclipse.baeyens.it/installAdvice.shtml  
Do not unzip in the downloads folder  
You need xcode on your system  

### configure Sloeber  
In the sloeber folder: start sloeber-id.  
Sloeber will doanload the avr toolchain and configure it.  
Wait for it.  

### get code from github  
Goto the github repository you want to use (you need to know if you need to fork or not).   
Select the "clone and download" button.   
select the copy icon  
In sloeber select->file->import->git->projects from git->clone uri  
Eneter your github user name and password  
I advice to select "store in secure store"  
next->next->next->import existing eclipse projects->next  
select covid19_ventilator_vub  


### select the board  
In Sloeber right click the project->preferences->arduino  
This will give a error  
Enter the information like the image  

### modify the command line  
Click the verify button 
Compilation will fail with the comment  
  
```'Building file: ..\Logger.cpp'
'Start de C++ bouw'
"C:\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\cores\arduino" -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\variants\mega" -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\libraries\Wire\src" -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\libraries\SPI\src" -I"C:\Users\gast1\git\covid16_ventilatyor_vub\covid19_ventilator_vub\libs\Adafruit_BME280" -I"C:\Users\gast1\git\covid16_ventilatyor_vub\covid19_ventilator_vub\libs\adafruit_sensor" -I"C:\Users\gast1\git\covid16_ventilatyor_vub\covid19_ventilator_vub\libs\LiquidCrystal_I2C" -I"C:\Users\gast1\git\covid16_ventilatyor_vub\covid19_ventilator_vub\libs\Adafruit_MPL3115A2" -MMD -MP -MF"Logger.cpp.d" -MT"Logger.cpp.o" -D__IN_ECLIPSE__=1 -x c++ "..\Logger.cpp"  -o  "Logger.cpp.o"
..\Logger.cpp:12:2: error: #error you need to add the following define to the command line -DSERIAL_TX_BUFFER_SIZE=500
 #error you need to add the following define to the command line -DSERIAL_TX_BUFFER_SIZE=500 
 ````  
 right click the project->preferences->arduino->compile options and add -DSERIAL_TX_BUFFER_SIZE=500  to "C and C++"  
 
### tag files as "asume unchanged"    
goto windows->show view->other  
select git->git staging  
Tag .cproject and .project as "assume unchanged"

you are ready to run.

