Fs = 1000;   % Sampling frequency
SecToMeasure = 60; % Seconds to measure
Ss = Fs*SecToMeasure;
%Fnyq = Fs/2; % Nyquist frequency is half the sampling frequency
%F0 = 50;   % Interference is at 60 Hz
%BW = 6;    % Choose a bandwidth factor of 6Hz
%[num1,den1] = designNotchPeakIIR(Response="notch",CenterFrequency=F0/Fnyq,Bandwidth=BW/Fnyq,FilterOrder=2);
a = zeros(1,Ss);
clear ard;
ard = arduino('COM3', 'Uno');
writeDigitalPin(ard, 'A1', 0);
for i = 1:10
    writeDigitalPin(ard, 'A1', 1);
    pause(0.5);
    writeDigitalPin(ard, 'A1', 0);
    pause(0.5);
end
for i = 1:Ss
    a(i) = readVoltage(ard, 'A0');
    pause(1/Fs)
end
first400 = zeros(1,400)
for i = 1:400
    first400(i) = a(i);
end
hold on
grid on
plot(first400);
plot(filter(filter_50hz,first400));
legend('Raw','Filtered');
ylim([0 1023])
hold off
writeDigitalPin(ard, 'A1', 1);