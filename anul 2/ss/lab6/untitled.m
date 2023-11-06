s=tf('s');
omega=07;
zeta=0.5;
H=omega^2/(s^2+2*zeta*omega*s+omega^2);
impulse(H)