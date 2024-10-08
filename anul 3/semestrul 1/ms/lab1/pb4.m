v0=250;
x0=3000;
theta=65*pi/180;
v_x=-35;
g=9.81;
v_0y=v0*cos(theta);
v_0z=v0*sin(theta);
t_hmax=v_0z/g;
t_tot=2*t_hmax;
t=linspace(0,t_tot,100);
z=v_0z*t-0.5*g*t.^2;
y=v_0y*t;
x=x0+v_x*t;
xnowind(1:length(y))=x0;
plot3(x,y,z,xnowind, y, z)
grid on
axis([0 6000 0 6000 0 3500])
xlabel('x')
ylabel('y')
zlabel('z')

