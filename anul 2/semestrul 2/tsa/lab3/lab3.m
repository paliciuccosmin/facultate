s = tf('s');
P = 1/(s-2);
C = 45;
L = series(P, C);
S = feedback(1, L, -1);
T = 1-S;
Ws = tf(mkfilter(1/(2*pi), 3, 'butterw'));
Wt = 2*s/(3*s+3);

norm(S*Ws, inf) < 1;
norm(T*Wt, inf) < 1;
bodemag(S,Ws)