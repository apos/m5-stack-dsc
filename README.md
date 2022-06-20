# M5-Stack DSC (fork of CN)

This is a fork of https://www.cloudynights.com/topic/621456-m5-dsc-simple-plug-n-play-digital-setting-circles/ . 

First of all thanks for sharing the code. I personally think, it would be much better, to use GitHub for sharing an documentation, than a Google Drive - but thats only my two cents ... and I do it hereby. Similary code you'll find across a lot of procects, since it is basically how encoder driven programming on arduino & friends works :-). So I think it is OK to fork the code. 

But much, much important - this is not critisism to the thread starter - I am very greatful instead.


I made important changes to the code (Keep It Simple and Stupid - KISS):

- I don't like the idea to use a MAC adress as password. IThis is no security device and starparties are no hacker spaces :-), so just use a simple password (min. 8 digits).
- Also the name of the SSID should be simple and unique to your setup / telescope.
- Using the button is not a good idea, because it may interrupt or cause problems with the code cycle. You can find a lot of thread for dealing with this problem. Therefore I eliminated it ([1.] has no need for
- The given ports 26/36 in the original code for azimuth cause severe problems. I find through testing port 3 and 1 work fine. 

Coding and uploading with arduino is much better. The problem was, that it was absolutely not possible to compile and upload the code with the given information in the README.


You can download, comment or send issues to the code here.

Cheers
Axel


# Upload and compile

You need the following lines in the preferences file for external packages:

https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json
https://dl.espressif.com/dl/package_esp32_index.json

Then install ESP32 (from espressif) and M5Stack (from m5stack!) libraries via "Libraries" and the board "via boards". Use the most revcent versions:

![grafik](https://user-images.githubusercontent.com/456034/174559278-c58caa20-28f7-49e4-ac05-6e56de4a9c5d.png)

![grafik](https://user-images.githubusercontent.com/456034/174559474-f3787985-860d-4d7b-9457-855f63dda3e2.png)


![grafik](https://user-images.githubusercontent.com/456034/174558643-39a14898-9a33-44a1-a6c4-a70a994b4221.png)


