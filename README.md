# gt
GT 

any code of this repo are not usable because we push something to this repo as backup of our storage labs

## repo desc

This repo is for our graduation thesis(GT). Main purpose of this GT research is to find how useful the prototype by our research. To evaluate our prototype, we made some small programs.

## main topic of research

evaluation of prototype electrode module for measuring ECG

We conduct this research to measure performance of electrode using AGPoss® fibre on IoT ECG measuring device.


## List

1. Make electrode module
2. signal measurement test
3. applying filter method for noise reduction
4. evaluate signal quality

## Progress

- make prototype
- measure RAW signal
- FIR filter using Kaiser window ... in progress
- Obtain filtered signal
- evaluate

## system overview

|Layer|module|||
|:-:|:-:|:-:|:-:|
|3|ECG measuring shield|<---(cable)--->|Electrodes|
||\|\||||
|2|FaBo I/O shield|||
||\|\||||
|1|SD card shield|||
||\|\||||
|G|Arduino UNO or compatible board|||
