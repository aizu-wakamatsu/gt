% 2秒分のプロットを比較
x = linspace(0,1000,1000);
% align two data
%y1 = sim060d(1001:2000);
%y2 = sim060f(1001:2000);
%y3 = sim060a(1169:2168);
y4 = sim100a2(1169:2168);
y5 = sim100a(1169:2168);
% レベルの違いを吸収するために正規化
%y1 = normalize(y1);
%y2 = normalize(y2);
%y3 = normalize(y3);
y4 = normalize(y4);
y5 = normalize(y5);
%plot(x,y1,x,y2,x,y3)
plot(x,y4, x, y5)
legend("60BPM DIRECT", "60BPM FASTCLIP", "60BPM AGPOSS")
corrcoef(y4,y5)