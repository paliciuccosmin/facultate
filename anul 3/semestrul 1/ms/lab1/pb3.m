x=[1.92,0.05,-2.43,-0.02,0.09,0.85,-0.06];
a=x(find(abs(x)>=0.1));
z=zeros(size(find(abs(x)<0.1)));
rez=[a,z]