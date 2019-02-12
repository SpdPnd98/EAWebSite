# FNM16P found on 06/02/2019

The MP3 module uses Digital Pins 10 and 11. 
Before the MP3 module starts. The Serial Monitor will print a status of the MP3 module. If the MP3 module is unable to begin playing the first song it will Print on the Serial Monitor "Unable to begin" and follow up with 2 prompts. The first is to check the connection between the Arduino and the MP3 Module and the second is to insert the SD card again.

If the connection is correct and the SD card is inserted properly it will initialize properly, playing the first song for 3 seconds before playing the next song. 

If there is an error while playing the song or the Initializing stage. The Serial Monitor will print the error. One possible error would be: 

1. Cannot Find File: This is due to the fact that the SD card even though it is put in properly there isn't any readable MP3 file format.      This could prompt you to upload an MP3 file or convert the existing file to MP3 format.
