function Hd = getFilter
%GETFILTER 離散時間フィルター オブジェクトを返します。

% MATLAB Code
% Generated by MATLAB(R) 9.14 and DSP System Toolbox 9.16.
% Generated on: 20-Jul-2023 02:19:57

Fstop1 = 0.35;  % First Stopband Frequency
Fpass1 = 0.45;  % First Passband Frequency
Fpass2 = 0.55;  % Second Passband Frequency
Fstop2 = 0.65;  % Second Stopband Frequency
Astop1 = 60;    % First Stopband Attenuation (dB)
Apass  = 1;     % Passband Ripple (dB)
Astop2 = 60;    % Second Stopband Attenuation (dB)zxxxsd
Fs     = 200;   % Sampling Frequency

h = fdesign.bandpass('fst1,fp1,fp2,fst2,ast1,ap,ast2', Fstop1, Fpass1, ...
    Fpass2, Fstop2, Astop1, Apass, Astop2, Fs);

Hd = design(h, 'kaiserwin', ...
    'MinOrder', 'any');


