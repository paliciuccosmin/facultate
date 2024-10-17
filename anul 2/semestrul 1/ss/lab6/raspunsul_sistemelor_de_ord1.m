% raspunsul unui sistem de ordinul I la diferite intrari

clc; clear all; close all;

%% definim sistemul de ordinul I si suportul de timp

s=tf('s');
H1=-4.2721/(s+5.6849);
t=0:0.01:10;

%% exemple de raspuns al sistemului la diferite intrari (impuls, treapta, rampa, armonic) 

figure;
impulse(H1,1.5,'b'); % raspunsul sistemului la impuls (pe un interval de 1.5sec)
grid on;
title('Raspuns la impuls')

figure;
step(H1,1.5,'b'); % raspunsul sistemului la treapta (pe un interval de 1.5sec)
grid on;
title('Raspuns la intrare treapta')

figure;
ramp=t.*double(t>=0); % definire semnal de intrare de tip rampa
lsim(H1,ramp,t,'b'); % raspunsul sistemului la intrare rampa
grid on;
title('Raspuns la intrare rampa')

figure;
u=sin(t); % definire semnal de tip armonic (sinusoidal)
lsim(H1,u,t,'b'); % raspunsul sistemului la semnalul de intrare de tip armonic
grid on;
title('Raspuns la intrare de tip armonic')