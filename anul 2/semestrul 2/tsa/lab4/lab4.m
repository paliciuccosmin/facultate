s = tf("s");
P = 1 / (s*(s+1));

w_perf = 1;
epsilon = 0.1;

W_T = 0.1*s / (0.05 * s + 1);

%% Determinam W_S
%FTJ ord 1
%k = 15;
%W_S = k / (s/w_perf + 1);

%FTJ ord 2
k = 21;
W_S = k / (s/w_perf + 1)^2;

%Butterworth
%W_S = 11 * tf(mkfilter(w_perf, 4, 'butterw'));

figure;
bode(W_S, tf(1/epsilon, 1));

%% Verificare conditie min{W_S, W_T} < 1
figure;
bode(W_S, W_T, tf(1/1))

%cel mai potrivit pentru satifacerea conditiei este W_S un FTJ de ord 2
%% Determinam pulsatia de inalta frecv

bode(W_T, tf(1/1));
%din bode:
w_rob = 11.6;

%% Regiunile de joasa si inalta frecventa
w_jf = logspace(-3, 0, 1e4);
w_if = logspace(log10(w_rob), 3, 1e4);
omega = logspace(-3, 3, 1e4);

%joasa frecventa
WS_jf = reshape(bode(W_S,w_jf), 1 ,numel(w_jf));
WT_jf = reshape(bode(W_T,w_jf), 1 ,numel(w_jf));

RJF = WS_jf ./ (1 - WT_jf);

%inalta frecventa
WS_if = reshape(bode(W_S,w_if), 1 ,numel(w_if));
WT_if = reshape(bode(W_T,w_if), 1 ,numel(w_if));

RIF= (1 - WS_if) ./ WT_if;

%% Proiectam L
L = (s/10^(-1.4) + 1) * (s/3 + 1) / (s * (s + 1)^2 * (s/100 + 1)^2);

amp_L = reshape(bode(L,omega),1,numel(omega));

figure;
semilogx(w_jf,mag2db(RJF),'m')
hold on
semilogx(w_if,mag2db(RIF),'g');
semilogx(omega,mag2db(amp_L),'k');
legend('|R_{jf}|','|R_{if}|','|L|')

figure;
margin(L);

%figure;
%nyquist(L);
%Closed loop stable: Yes

%reuzlta C
%C = (s/10^(-1.4) + 1) * (s/3 + 1) / ((s + 1) * (s/100 + 1)^2);

%%
S = feedback(1, L);
T = feedback(L, 1);
%grafic S si T sa fie sub 1/W_S, respectiv 1/W_T
figure;
bode(S, 1/W_S);
figure;
bode(T, 1/W_T);

%polii lui S si T
poli_T = pole(tf(ss(T,'min')));
poli_S = pole(tf(ss(S,'min')));

%conditii norme + margine vectoriala
norm_perf = norm(W_S*S, inf);
norm_rob = norm(W_T*T, inf);
MV = 1/norm(S, inf);

%conditie performanta robusta
perf = reshape(bode(W_S*S,omega),1,numel(omega));
robust = reshape(bode(W_T*T,omega),1,numel(omega));

perf_robust = max(perf + robust);

figure;
semilogx(omega,mag2db(perf + robust), 'k');
