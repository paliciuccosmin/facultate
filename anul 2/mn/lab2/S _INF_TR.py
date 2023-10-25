import numpy as np
n=7
rng=np.random.default_rng()
A=np.array(rng.random(size=(n,n)))
u=np.zeros((n,n))
for k in range(n):
    for i in range(k + 1, n):
        u[i, k] = A[i, k] / A[k, k]
        A[i, k] = u[i, k]
    for j in range(k + 1, n):
            A[i, j] -= u[i, k] * A[k, j]

print(A)