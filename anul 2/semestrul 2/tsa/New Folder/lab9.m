s=tf('s');
A=[0 1;-2 -3];
B=[0;1];
C=[1 0];
D=[0];
[NUM,DEN]=ss2tf(A,B,C,D);
H=tf(NUM,DEN);
[A,B,C,D]=tf2ss(NUM,DEN);
Xl=[1 1;-1 -2]*[exp]