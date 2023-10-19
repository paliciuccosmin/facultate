%% liniaritate

s=tf('s');
H1=-4.2721/(s + 5.6849); % liniile 3-4 -> transformam semnalul din domeniul timp in operational (polinoame rationale)
t=0:0.01:2; % suportul de timp finit
alpha1=2;
alpha2=3; % alpha1 & alpha2 - cei 2 scalari folositi pentru inmultirea cu semnalele de intrare
u1=double(t>=0);
u2=sin(t); % cele 2 intrari (treapta si sinusoidal)
y1=lsim(H1,u1,t);
y2=lsim(H1,u2,t); 
y=lsim(H1,alpha1*u1+alpha2*u2,t); % simularea raspunsurilor sistemului in timp pentru intrarile u1,u2 si u3=alpha1*u1+alpha2*u2
figure;
subplot(2,1,1)
plot(t,y,'b',t,alpha1*y1,'r',t,alpha2*y2,'g','LineWidth',1); grid;
legend('y(t)','\alpha_1 \times y_1(t)', '\alpha_2 \times y_2(t)'); % plotam semnalele de iesire alpha1*y1, alpha2*y2 si y=alpha1*y1+alpha2*y2
subplot(2,1,2)
plot(t,alpha1*y1+alpha2*y2,'b','LineWidth',1); grid; % plotam numai semnalul rezultat ca si combinatie liniara intre y1 si y2, i.e. y=alpha1*y1+alpha2*y2
legend('\alpha_1 \times y_1(t) + \alpha_2 \times y_2(t)');

%% invarianta in timp

t=-1:0.01:3; % suportul de timp finit
u1=double(t>=0 & t<1);
u2=double(t>=1 & t<2); % semnalul u1 si u2 dreptunghiulare (u2 este u1 translatat la dreapta)
y1=lsim(H1,u1,t);
y2=lsim(H1,u2,t); % simularea raspunsurilor sistemului in timp pentru intrarile u1 si u2
figure;
subplot(2,1,1);
plot(t,u1,'b',t,y1,'r','LineWidth',1); grid; % plot semnal de intrare u1 si semnal de iesire y1
ylim([-1.2 1.2]);
legend('u_1(t)','y_1(t)');
subplot(2,1,2);
plot(t,u2,'b',t,y2,'r','LineWidth',1); grid; % plot semnal de intrare u2 si semnal de iesire y2 (practic semnalele u1 si y1 translatate la dreapta)
ylim([-1.2 1.2]);
legend('u_2(t)','y_2(t)');

%% cauzalitate

t=-3:0.01:3; % suport de timp finit
h1=-4.2721 * exp(-5.6849 * t) .* double(t>=0); % functia pondere exprimata in domeniu timp
figure;
plot(t,h1,'b','LineWidth',1); grid; % plot functie pondere
legend('h_1(t)');
ylim([-4.5 1]);