# Bravo18

## Hello world!

This is a test paragraph. If you see it please enter your names below.
You can add your names by either:
```
git clone https://github.com/SpdPnd98/EAWebSite.git
git pull origin master
cd ~/EAWebSite
sudo nano index.md
```
or:

download the file as ZIP, edit 'index.md' from your preferred text editors:

  * Atom
  * Vim
  * Sublime text
  * Vscode
  * etc...

Update the files via one of the following methods:

```
git add .
git commit
git push origin master
```
or:

go to [this](https://github.com/SpdPnd98/EAWebSite) repository and simply find index.md and edit it straight away, adding your names below.

----

### Seen:

1. Bryan Tee Pak Hong
2. Chung Teik Lim
3. Chua Wen jie Felix
4. Daichi Tan



# Water Projects Suggestions:
Bryan: [DizzMe](https://spdpnd98.github.io/), A hackathon project with Team Sudo Coders under the guidance of Mr. Teo Shin Jen.

Daichi: A musical instrument invented by the japanese, called "Suikinkutsu". Tuned and Automated to create a soothing tune.

# Week 2 Assignment:

  * Look through the AVR and ADC slide:
    * which ports are used?
    * What is the command used to read the ADC?
    * What is the resolution?
    * How is voltage accuracy achieved?
    * How fast are the ADC ports?
  * Is a better ADC required? How fast does it need to be?
  * A table for all specifications of the sensors.

# Week 3 Assignment:

 * Choose our final project using the selection below:
   * holding drinks boat
   * water instrument
   * water trainer
   * deployable life boat

# Week 4 Assignment:

This week, we start to design a boat and find at what angle the boat topples

Electronic-wise, we identified the electronic component required for our project:

## Boat:

* Servo Motor (SG90): 2
  * [link](https://www.aliexpress.com/item/5-10pcs-lot-100-NEW-Wholesale-SG90-9G-Micro-Servo-Motor-For-Robot-6CH-RC-Helicopter/32864783539.html?spm=2114.search0104.3.8.36011930EVYvdC&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_319_317_5728815_10696_10084_453_454_10083_10618_10307_537_536_5733215_5733315_328_10059_10884_10887_5733115_100031_5733415_321_322_10103_5733515_5733615,searchweb201603_55,ppcSwitch_0&algo_expid=72bf6552-53fa-44b0-88a2-f9297a3cf35b-1&algo_pvid=72bf6552-53fa-44b0-88a2-f9297a3cf35b)

* DC Motor : 1 or 2
  [link](https://www.aliexpress.com/item/25mm-12V-DC-5RPM-Powerful-High-Torque-Gear-Box-Motor-ZGA25RP/32684701655.html?spm=2114.search0104.3.1.1fba1dbd4jnxGE&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_319_317_5728815_10696_10084_453_454_10083_10618_10307_537_536_5733215_5733315_328_10059_10884_10887_5733115_100031_5733415_321_322_10103_5733515_5733615,searchweb201603_55,ppcSwitch_0&algo_expid=04295e54-814d-479a-a19c-6d22723de4c2-0&algo_pvid=04295e54-814d-479a-a19c-6d22723de4c2)

* Motor driver: 1
  * L298N module

* IR sensor module: 3

* RFID reader & tag set: 1
  * [link](https://www.aliexpress.com/item/MCIGICM-MFRC-522-RC522-mfrc-522-RFID-RF-IC-card-inductive-module-S50-Fudan-card-key/32905192359.html?spm=2114.search0104.3.8.6c1d27a2o5hl6X&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_319_317_5728815_10696_10084_453_454_10083_10618_10307_537_536_5733215_5733315_328_10059_10884_10887_5733115_100031_5733415_321_322_10103_5733515_5733615,searchweb201603_55,ppcSwitch_0&algo_expid=a639cae7-0974-4bdc-b506-98a00a27fb45-1&algo_pvid=a639cae7-0974-4bdc-b506-98a00a27fb45)

* Arduino Uno: 1

* GPS module: 1
  * [link](https://www.aliexpress.com/item/WAVGAT-GY-NEO6MV2-New-NEO-6M-GPS-Module-NEO6MV2-with-Flight-Control-EEPROM-MWC-APM2-5/32836015224.html?spm=2114.search0104.3.1.55e87b9dW1Iznn&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_319_317_5728815_10696_10084_453_454_10083_10618_10307_537_536_5733215_5733315_328_10059_10884_10887_5733115_100031_5733415_321_322_10103_5733515_5733615-5733315,searchweb201603_55,ppcSwitch_0&algo_expid=8e8a4636-71c0-4185-a85f-2f220ab737e5-0&algo_pvid=8e8a4636-71c0-4185-a85f-2f220ab737e5)

* Accelerometer 3-axis: 1
  * [link](https://www.aliexpress.com/item/GY-521-MPU-6050-MPU6050-Module-3-Axis-analog-gyro-sensors-3-Axis-Accelerometer-Module/32340949017.html?spm=2114.search0104.3.1.38a045446UYtjW&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_319_317_5728815_10696_10084_453_454_10083_10618_10307_537_536_5733215_5733315_328_10059_10884_10887_5733115_100031_5733415_321_322_10103_5733515_5733615-5733315,searchweb201603_55,ppcSwitch_0&algo_expid=e34183f5-5181-4fad-8f4e-577380d66b74-0&algo_pvid=e34183f5-5181-4fad-8f4e-577380d66b74)

* Piezo Buzzer: 1

* RGB LED strip: 1 roll
  * [link](https://www.aliexpress.com/item/RGB-LED-Strip-Waterproof-5050-5M-Lot-DC12V-Fita-LED-Light-Strip-LED-Ribbon-Tape-RGBWW/32933069691.html?spm=2114.search0104.3.15.4c3325a91VjNZh&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_319_317_5728815_10696_10084_453_454_10083_10618_10307_537_536_5733215_5733315_328_10059_10884_10887_5733115_100031_5733415_321_322_10103_5733515_5733615-5733115,searchweb201603_55,ppcSwitch_0&algo_expid=c541d460-730f-48fc-b45a-385593136086-2&algo_pvid=c541d460-730f-48fc-b45a-385593136086)



## Kiosk/Checkpoint:

* OLED/Touchscreen/2x16LCD: 1
  * [link](https://www.aliexpress.com/item/2-4inch-TFT-Touch-Screen-Shield-for-Arduino-UNO-R3-LCD-Modules-Display-Modules/32778794737.html?spm=2114.search0104.3.15.523029fa05Hv9i&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_319_317_5728815_10696_10084_453_454_10083_10618_10307_537_536_5733215_5733315_328_10059_10884_10887_5733115_100031_5733415_321_322_10103_5733515_5733615,searchweb201603_55,ppcSwitch_0&algo_expid=b6f7f744-b60d-4d08-a7bd-9daa7503f427-2&algo_pvid=b6f7f744-b60d-4d08-a7bd-9daa7503f427)

* push buttons: 3

* Raspberry pi/Arduino Mega: 1

## Week 5


## Week 6


## Week 7
Serial communication:
When you see CTS, DTR RTS etc, the chip can be "programmed" with AT command sets

Cheat sheet found: http://pressplay.pbworks.com/w/page/47221855/AT%20Command%20Cheat%20Sheet

Mr. Rodney will be bringing about 20 ESP32 for us to use MicroPython

Task for today: we need to select a communication method (WiFi, Bluetooth, Serial), then display the "results" (a display to see the conditions of the boat)

Thingspeak demo: takes away the tedium of writing a data presentation method

We are also tasked to watch the video on power.

We must give torque, speed, power rating etc of the parts. This includes battery specifications etc. (Lipo batterries must have a charging unit built-in)

Today's task: BOM



## Term break
### 12/12/2018
Bryan Tee Pak Hong:

### 21/12/2018
Daichi Tan: Team Bravo has Started on the Characterisation and calculation of a surface vessel's stability. We had finished it in the start of the term but we needed to make our boat more streamline. So we have decided to redo the boat.
<img src="BoatSketch.jpg">

### 31/01/2019
Team Bravo has finished the Google Slides on the buoyancy experiment

Links to the slides: https://docs.google.com/presentation/d/1vKs533fTxYvJOHl-CTRWlWQtzYydDGWarJUBO-LknRk/edit#slide=id.g278d73b18e10d00_47


### 08/02/2019
Team Bravo has finished the cricuitry of the Music and the Lights (image of circuit). As we were testing the servo of the cannon we realised that everytime the servo moved, the lights would flicker and the music will repeat itself. We did some testing and we realised the servo was causing a voltage drop due to the heavy load. This phenomenon is called "Brown Out", where the arduino will reset itself and hence the music and lights reset causing the observation. We planned to solve this by seperating the power supply of the servo and microcontroller.

