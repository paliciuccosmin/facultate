s=tf('s');
P=1/(100*s+1);
C=1;
k=60;
L=k*P;
bloc1=(s/100+1)/(s/10+1);
L=L*bloc1;
eps=0.1;
wperf=1;
mag2db(1/eps);
S=feedback(1,L);
T=1-S;

%functie de ordin 2
Ws=10/(s/wperf+1)^2;
Wt=(0.05*s^2)/(0.01*s+1)^2;

%conditia de performanta
bodemag(S,1/Ws)
figure;

%conditia de stabilitate robusta
bodemag(T,1/Wt)

omeg=logspace(-1,2,1e3);
omeg_jf=logspace(-1,0,1e3);
omeg_if=logspace(1,2,1e3);

%conditia de performanta robusta max(amp_Ws*S+amp_Wt*T)
figure('units', 'normalized', 'position', [.1 .1 .45 .6]);
mag1 = bode(Ws, omeg_jf);
mag1 = reshape(mag1, 1, 1e3);
mag2 = bode(Wt, omeg_jf);
mag2 = reshape(mag2, 1, 1e3);
mag3 = bode(Ws, omeg_if);
mag3 = reshape(mag3, 1, 1e3);
mag4 = bode(Wt, omeg_if);
mag4 = reshape(mag4, 1, 1e3);
mag5 = bode(L, omeg);
mag5 = reshape(mag5, 1, 1e3);
R_jf = (mag1)./(1 - mag2);
R_if = (1 - mag3) ./ (mag4);
semilogx(omeg_jf, 20*log10(R_jf), 'b', ...
         omeg_if, 20*log10(R_if), 'r', ...
         omeg, 20*log10(mag5), 'k');
xlabel('Pulsa\c t i e (rad/s)', 'Interpreter', 'latex', 'Fontsize', 16);
ylabel('Amplitudine (dB)', 'Interpreter', 'latex', 'Fontsize', 16);
legend('$\frac{|Ws|}{1-|Wt|}$', '$\frac{1-|Ws|}{|Wt|}$', '$| L |$', 'Interpreter', 'latex', 'Fontsize', 16);
set(legend, 'Interpreter', 'latex', 'Fontsize', 16);
set(findall(gcf, 'Type', 'Line', 'LineStyle', '-'), 'LineWidth', 2);
%ylim([-40 50]);
grid on;
T = ss(feedback(L, 1), 'min');
S = ss(feedback(1, L), 'min');
poli_T = pole(T);
[amp7, ~, ~] = bode(Ws * S, omeg);
[amp8, ~, ~] = bode(Wt * T, omeg);
amp = amp7 + amp8;
robperf_cost=max(amp)
figure()
margin(L)
figure
bodemag(S, 1/Ws)
figure
bodemag(T, 1/Wt)
