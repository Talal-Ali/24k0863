import numpy as np

def gauss_jordan(A, b):
    n = len(b)
    aug = np.hstack([A.astype(float), b.reshape(-1,1).astype(float)])
    for i in range(n):
        aug[i] = aug[i] / aug[i, i]
        for j in range(n):
            if i != j:
                aug[j] = aug[j] - aug[j, i] * aug[i]
    return aug[:, -1]

def inversion_method(A, b):
    A_inv = np.linalg.inv(A)
    return np.dot(A_inv, b)

A = np.array([[1, 1, 1],
              [2, 5, 1],
              [1, 0, 8]], dtype=float)

b = np.array([6, 3, 17], dtype=float)

sol_gj = gauss_jordan(A.copy(), b.copy())
print("Solution (Gauss-Jordan):", sol_gj)

sol_inv = inversion_method(A, b)
print("Solution (Inversion):", sol_inv)
