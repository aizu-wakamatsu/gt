Fs = 1000;   % Sampling frequency
agp = a2023120709h45;
agp = agp(701:2700);
fcl = f2023120709h48;
fcl = fcl(701:2700);

t = (0:length(agp)-1)/Fs;
fn = designfilt('bandstopiir','FilterOrder',200, ...
               'HalfPowerFrequency1',49,'HalfPowerFrequency2',51, ...
               'DesignMethod','butter','SampleRate',Fs);


ylow = 250;
yhigh = 500;

hold off
hold on
grid on
subplot(2,3,1)
plot(t,fcl);
ylim([ylow yhigh])
ylabel('Value')
xlabel('Time (s)')
title1 = title('Fastclip - Raw');
title1.FontSize = 16;
grid on
subplot(2,3,2)
plot(t,filtfilt(Hd,fcl));
ylim([ylow yhigh])
ylabel('Value')
xlabel('Time (s)')
title2 = title('Fastclip - Filtered');
title2.FontSize = 16;
grid on
subplot(2,3,3)
plot(t,fcl,t,filtfilt(fir,fcl));
ylim([ylow yhigh])
ylabel('Value')
xlabel('Time (s)')
title3 = title('Fastclip - Raw/Filtered Combined plot');
title3.FontSize = 16;
grid on
subplot(2,3,4)
plot(t,agp);
ylim([ylow yhigh])
ylabel('Value')
xlabel('Time (s)')
title4 = title('AGPoss - Raw');
title4.FontSize = 16;
grid on
subplot(2,3,5)
plot(t,filtfilt(fn,agp));
ylim([ylow yhigh])
ylabel('Value')
xlabel('Time (s)')
title5 = title('AGPoss - Filtered');
title5.FontSize = 16;
grid on
subplot(2,3,6)
plot(t,agp,t,filtfilt(fn,agp));
ylim([ylow yhigh])
ylabel('Value')
xlabel('Time (s)')
title6 = title('AGPoss - Raw/Filtered Combined plot');
title6.FontSize = 16;
grid on

