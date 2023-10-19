import math
import numpy as np
def multiplication(L,U):
  n = L.shape[0]
  m = U.shape[1]
  X = np.zeros(shape=(n, m),dtype=int)
  for i in range(n):
    for j in range(m):
      for k in range(L.shape[1]):
        X[i, j] += L[i, k] * U[k, j]
  print(X)

L=np.array([[1, 0, 0],
            [3, 4, 0],
            [5, 6, 5]])
U=np.array([[1, 2, 3],
            [0, 4, 4],
            [0, 0, 5]])
multiplication(L,U)
print(np.dot(L,U))