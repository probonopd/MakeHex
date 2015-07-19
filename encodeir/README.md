# encodeir for Arduino

The objective of this sketch is to generate raw infrared timings from [IRP notation](http://hifi-remote.com/wiki/index.php?title=IRP_Notation). I am running it on an [ESP8266](https://github.com/esp8266/Arduino). The generated raw timings could then be used to send the signal using an existing infrared sending library that supports raw timings.

## Issues

Can you help me fix the following? Pull requests welcome.

* Memory leak (where?)
* Apparently it is not using the correct device, subdevice, function yet
* Update to final [IRP notation](http://hifi-remote.com/wiki/index.php?title=IRP_Notation)
