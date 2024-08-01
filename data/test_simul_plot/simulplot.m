% 2秒分のプロットを比較
x = linspace(0,1000,1000);
y1 = testsimulboard1(1001:2000);
y2 = testsimulboard2(1001:2000);
% レベルの違いを吸収するために正規化
y1 = normalize(y1);
y2 = normalize(y2);
plot(x,y1,x,y2)
legend("BOARD1", "BOARD2")
corrcoef(y1,y2)