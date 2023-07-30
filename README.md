# gt
GT 

any code of this repo are not usable because we push something to this repo as backup of our storage labs

## repo desc

This repo is for my graduation thesis(GT). Main purpose of this GT research is to find how useful the prototype by our research. To evaluate our prototype, we made some small programs.

## main topic of research

evaluation of prototype electrode module for measuring ECG

We need simple and low-cost ECG measuring module that everyone can operate. The device for medical use measure ECH signal with high accuracy but they are difficult to operate and expensive. It is not suitable for measure signal in ordinary life.

## List

1. Make electrode module
2. signal measurement test
3. applying filter method for noise reduction
4. evaluate signal quality

## ToDo NOW

*out of progress - until 1 Sep*

to apply:

- FIR filter


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
