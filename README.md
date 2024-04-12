# gt
graduation thesis

any code of this repo may not usable because we push something to this repo as backup of our storage labs

## repo description

This repo is for our graduation thesis(GT). most, not all, materials of our GT are in this repo. We will hold a presentation of this GT in August 2024.

- Included
  - Sample data to test program
  - Source code
  - 
- Not included
  - Thesis
  - Poster
  - Full measured data

## main topic of research

evaluation of prototype electrode module for measuring ECG

We conduct this research to measure performance of electrode using AGPoss® fibre on IoT ECG measuring device.

We compare the electrode to fastclip, which are used in medical diagnostics.

## Background

Medical-use device is expensive or difficult to operate (for people not friendly to technologies).

## Motivation

Medical device for everyone

- Medical-use system in simple mechanism and low cost (to buy, and operate)
- easy to wear, low allergic side-effects.

## Method

Make ECG measuring module using IoT prototyping pratform.

Daily-use device does not need high acculacy like that of medical-use device.

## Brief description of procedure

1. Make electrode module
2. signal measurement test
3. applying filter method for noise reduction
4. evaluate signal quality

## Task List - Entire

- make measuring module (not electrodes)
- signal measuring test (with fastclip)
- make prototype electrode module 
- signal measuring test (with that prototype)
- analyse RAW signal to obtain noise effects not related to device
- construct optimal experiment environment
- analyse filtered signal
- ???
- ??? (after complete GT)
- We will not apply in this thesis
  - apply FIR filter using Kaiser window 

## Shinchoku

- Mid-term presentation ... done
- Measurement ECG of human body with two types of electrode


## Schedule

- 04/2022 Start research for writing thesis
- 09/2022 1st Mid-term presentation
- 04/2023 2nd Mid-term presentation
- 12/2023 Complete of writing thesis and all experiments
- 04/2024 3rd Mid-term presentation
- 08/2024 GT presentation

## Task list of writing thesis


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
