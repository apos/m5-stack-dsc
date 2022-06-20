# M5-Stack DSC (fork of CN - KISS)

This is a fork of https://www.cloudynights.com/topic/621456-m5-dsc-simple-plug-n-play-digital-setting-circles/ . 
Please refer to the thread for connecting to SkySafari. 

First of all thanks for sharing the code. I personally think, it would be much better, to use GitHub for sharing an documentation, than a Google Drive - but thats only my two cents ... and I do it hereby. Similary code you'll find across a lot of procects, since it is basically how encoder driven programming on arduino & friends works :-). So I think it is OK to fork the code. 

But much, much important - this is not critisism to the thread starter - I am very greatful instead.


I made important changes to the code (Keep It Simple and Stupid - KISS):

- I don't like the idea to use a MAC adress as password. IThis is no security device and starparties are no hacker spaces :-), so just use a simple password (min. 8 digits).
- Also the name of the SSID should be simple and unique to your setup / telescope.
- Using the button is not a good idea, because it may interrupt or cause problems with the code cycle. You can find a lot of thread for dealing with this problem. Therefore I eliminated it ([1.] has no need for a button or dsiplay any more - shut it off).
- Display not used (my M5Stack has a broken display) - it is anyway not of any use in the case. Settings are basic and one can write them down.
- The given ports 26/36 in the original code for azimuth cause severe problems. I find through testing port 21 and 22 work fine. 

Coding and uploading with arduino is much better. The problem was, that it was absolutely not possible to compile and upload the code with the given information in the README.


You can download, comment or send issues to the code here.

Cheers
Axel

# M5Stack
All important informations for the ports you get here at M-BUS
- https://docs.m5stack.com/en/core/gray

I also tested on the actual version (V26 black) of M5stack (https://docs.m5stack.com/en/core/basic_v2.6)

# Upload and compile

## Arduino.cc IDE download

Use the Arduino download an _NOT_ the windows store (if using win). Linux is working best. I am working with version 1.8.19 (as of June 2022).

If using Windows, exclude the directory c:\Users\YOURUSERNAME\AppData\Local\Arduino15 from windows defender or other antivirus programs. This is VERY important, because under windows compilation takes forever, if you do not do that (this is a well known issue!). Turning on debugging in preferences can help you determing the exact location of your directory. 

NEVER EVER PUT ARDUINO SOURCE FOLDER IN PREFERENCES IN A CLOUD DRIVE (ondrive, google, nextdrive, ...). The directory will probably be a few gigabytes (!) big.  

![grafik](https://user-images.githubusercontent.com/456034/174564593-ce873ca5-5060-4e15-873f-1bef69d00442.png)


## Configure Arduino IDE

### Preferences
You need the following lines in the preferences file for external packages:

https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json
https://dl.espressif.com/dl/package_esp32_index.json

### Board:

Then install ESP32 (from espressif) and M5Stack (from m5stack!) ***boards***. Use the most revcent versions.

![grafik](https://user-images.githubusercontent.com/456034/174559278-c58caa20-28f7-49e4-ac05-6e56de4a9c5d.png)

![grafik](https://user-images.githubusercontent.com/456034/174559474-f3787985-860d-4d7b-9457-855f63dda3e2.png)

![grafik](https://user-images.githubusercontent.com/456034/174559736-f885cca2-0035-4cb2-a1f6-a416c8c4e61a.png)


### Libraries

Then install ESP32 (from espressif) and M5Stack (from m5stack!) ***libraries***. You also need the encoder library from Paul Steffhagen. 

Use the most revcent versions. Please install ALL additional packages, if asked. 

![grafik](https://user-images.githubusercontent.com/456034/174561301-64f5e578-6e6b-4f7b-8442-d4fb64039881.png)

![grafik](https://user-images.githubusercontent.com/456034/174561845-c6a98db0-c2b7-420d-b6f2-b8f3c36ac201.png)

![grafik](https://user-images.githubusercontent.com/456034/174562207-e27ee45a-de90-4be2-9048-dd3d5c30fe62.png)

![grafik](https://user-images.githubusercontent.com/456034/174562394-18938b4e-a25a-4940-858a-d04d4cdf8d77.png)



### Compilation and Upload (ESP32)
Do NOT use M5Stack, but ESP32 as board.
Set the appropriate COM port (please google, how the get the port for various operation systems).

![grafik](https://user-images.githubusercontent.com/456034/174558643-39a14898-9a33-44a1-a6c4-a70a994b4221.png)

Use the following settings:

![grafik](https://user-images.githubusercontent.com/456034/174562941-4f69c490-f526-4d45-b619-8e785456c81f.png)

### Troubleshooting on compilation
Since there could occur a lot of problems depending on your setup, the could be compiling errors. Please read them carefully (duplicate libraries, missing libraries, code error in line ...) and Google. You will find a solution :-)


# SkySafari Setup
First make sure you are ***connected*** to the WLAN of the M5Stack accesspoint (SSID in the code, Password in the code).
Also see https://skysafariastronomy.com/support/manual/scope_setup.shtml


- Basic Encoder
- IP 192.168.4.1
- Port 8888
- Alt-AZ Push to
- Encoder: depends on you setup. CUI AMT 102/3: +/- 8192. Plus and minus depend on your setup / orientation of the encoder. 


Important: 

- scope should be leveled (not necessarily very acurate)
- be aware, the the scope MUST be pointed to the horizon facing north when you plugin M5Stack
- Aligning only works, when the stars you select fare from each other. Sky Safary can handly max. 10 Stars. 


Have fun
Axel





