% raspunsul unui sistem de ordinul II la diferite intrari

clc; clear all; close all;

%% definim sistemul de ordinul II si suportul de timp

s=tf('s');
H2=(s+0.6267)/(s^2+1.65*s+1.889);
t=0:0.01:10;

%% exemple de raspuns al sistemului la diferite intrari (impuls, treapta, rampa, armonic) 

figure;
impulse(H2,10,'b'); % raspunsul sistemului la impuls (pe un interval de 10sec)
grid on;
title('Raspuns la impuls')

figure;
step(H2,10,'b'); % raspunsul sistemului la treapta (pe un interval de 10sec)
grid on;
title('Raspuns la intrare treapta')

figure;
ramp=t.*double(t>=0); % definire semnal de intrare de tip rampa
lsim(H2,ramp,t,'b'); % raspunsul sistemului la intrare rampa
grid on;
title('Raspuns la intrare rampa')

figure;
u=sin(t); % definire semnal de tip armonic (sinusoidal)
lsim(H2,u,t,'b'); % raspunsul sistemului la semnalul de intrare de tip armonic
grid on;
title('Raspuns la intrare de tip armonic')  