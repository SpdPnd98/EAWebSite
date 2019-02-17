### How to improve our Circuit and Electronics

1) For our circuit we used 7806 and 7809 as voltage regulators.
During our project review our lecturer pointed out that instead we should use Buck and Boost Converters instead of voltage regulators.
Buck Converters convert High DC Voltage to Low DC Voltage. It is also very cost effective and much more reliable than the Voltage Regulators. We could have used this for our boat as the LIPO battery supplies 11V but most of our electronics except the pump require lower voltages.
Boost Converters convert Low DC Voltage to High DC Voltage. We did not have a use for this as 11V was sufficient for our boat to run.

2) For our boat we also realised we did not add any Power ON or Power OFF Switch.
Our lecturers pointed out that this is very dangerous and inefficient if ever our boat is sold. 
The current function is for the customer to put in the batteries and the boat will automatically function.
So what we did instead is that we decided to add a switch at the start of the circuit at the positives and negatives of the LIPO Battery.

3) We did not have a proper Battery Indictator.
We made our own Battery indicator however due to the lack of digital pins, we decided to forgo the idea.
This was wrong for us to do as the custormer could not judge when he should remove the battery so as to charge it back up.
Also the LIPO Battery has a safety precaution to not let the voltage drop below 3.3Vs. As this will spoil the Battery.
We did some research and found a premaid Indicator that can be connected right to the battery without using any digital pins.
Link:(https://sea.banggood.com/3_7V7_4V-11_1V14_8V-Li-po-Battery-Indicator-Display-Board-Power-Storage-Monitor-p-1096280.html?rmmds=buy&ID=47892&cur_warehouse=CN)

