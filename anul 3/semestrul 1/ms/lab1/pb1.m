v=10:2:20;
theta=50:10:80;
vt=transpose(v);
hmax=(vt.^2*sind(theta).^2)/(2*9.8);
A=[0,theta;
    vt,hmax]