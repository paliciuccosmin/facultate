t = -4:0.001:4;
u = (t+1).*(double(t>= 0)-double(t>1))+(2-t).*(double(t>1)-double(t>2));
plot(t, u,'b','LineWidth',2);
grid on;
xlim([-4 4]);
ylim([-1 5]);
y = (t+3).*double((t>=-2)- double(t>=-1)) +(3*t +7).* double(t==-1)+(t+4).*(double(t>-1)-double(t>0))+(2-2*t).*(double(t>0)-double(t>1));
hold on;
plot(t, y, 'b*', 'LineWidth', 2);