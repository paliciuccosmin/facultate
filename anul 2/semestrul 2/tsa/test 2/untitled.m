
%blocuri e^Jk
syms x
ilaplace(inv(x*eye(2)-[-1 1 ;0 -1 ]))

%ecuatii T
% syms v1_1 v1_2 v1_3
% eqn1 = -v1_1 -3*v1_2 - 2*v1_3 == 0;
% eqn2 = -v1_1 - v1_2 - v1_3 == 0;
% eqn3 = 2*v1_1 + 4*v1_2 + 3*v1_3 == 0;
% sol = solve([eqn1, eqn2, eqn3], [v1_1, v1_2, v1_3]);
% xSol = sol.v1_1
% ySol = sol.v1_2
% zSol = sol.v1_3

% Define the matrix A
A = [0 1 0; 0 0 1; 2 1 -2];

% Calculate the eigenvalues and eigenvectors
[V, D] = eig(A);

% Display the eigenvalues
disp('The eigenvalues of matrix A are:');
disp(diag(D));

% Display the eigenvectors
disp('The eigenvectors of matrix A are:');
disp(V);

