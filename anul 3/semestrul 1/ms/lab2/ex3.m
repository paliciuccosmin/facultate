
close all;
F=1;
M_1=1;
M_2=1.5;
B=0.1;
K_1=0.2;
K_2=0.15;
Coef_1=[B/M_1 -B/M_1; -B/M_2 B/M_2];
Coef_2=[(K_1+K_2)/M_1 -K_1/M_1; -K_2/M_2 K_2/M_2];
y=[0.1;0.1];
dy=[0;0];
t=0;
tsim=1200;
dt=0.1;
n=round((tsim-t)/dt);
for i=1:n
    X_1(i,:)=[y' dy' t];
    ddy=[0;F/M_2]-Coef_1*dy-Coef_2*y;
    dy=dy+dt*ddy;
    y=y+dt*dy;
    t=t+dt;
end
plot(X_1(:,5),X_1(:,1:2))
xlabel("Timp(s)")
ylabel('Deplasari')
legend('y1','y2')
figure
plot(X_1(:,5),X_1(:,3:4))
xlabel("Timp(s)")
ylabel('Viteza')
legend('y1','y2')
clear X_1
