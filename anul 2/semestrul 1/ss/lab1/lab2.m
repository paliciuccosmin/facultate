close all
clear all
Ts     = 1e-3;%Perioada esantionare
N      = 15;%Orizont timp
t      = -N:Ts:N;%suport timp semnale intrare
a      = -3;
b      = 3;
u      = double(t>=a & t<=b);%semnal dreptunghiular
h      = (b-abs(t)).*u;%semnal triunghiular
y      = Ts * conv(u,h);%semnal iesire obtinut
t_conv = -2*N:Ts:2*N;%suport timp semnal iesire
lgt    = length(t_conv);

for ii = -1 : 0.5 : 11
    u = double((-t - N *(1- 2*ii/10) ) >=a & (-t - N * (1- 2*ii/10) <=b));
    figure
    subplot(2,1,1);
    plot(t, u)
    grid on
    hold on
    plot(t,h)
    legend('semnal de intrare u','functie pondere h')

    subplot(2,1,2)
    idx = t_conv <=  - N *(1 - 2*ii/10);
    plot(t_conv(idx),y(idx))
    grid on
    legend('semnal de iesire y')
    axis([-N N 0 b^2])
    input('Press enter to contiue...');
    
    if ii~=11
        close
    end
end