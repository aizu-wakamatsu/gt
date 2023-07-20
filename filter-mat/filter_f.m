f = fir
filtered = filter(f,data)
ln = plot(filtered)
title('Filtered signal')
ylim([0 1023])
xlim([3000 3500])
ln.LineWidth = 4;