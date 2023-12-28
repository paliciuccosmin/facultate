s=tf('s');
%H=1/(s*(s+4)*(s+2));
%t=0:1e-3:20;
%x=5*cos(t)
%lsim(x,H,t);

H=5*(s+1)/(s*(s+10));
bode(H)
