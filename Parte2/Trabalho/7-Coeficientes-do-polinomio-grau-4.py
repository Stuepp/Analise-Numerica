import numpy as np
# import scipy as sp

def best_poly (x, y, k):
    n = len(x)
    if n <= k:
        raise ValueError('O número de pontos deve ser maior que k (o grau do polinônmio)')

    somas = {}
    somas[0] = n
    for n in range(1, 2*k + 1):
        somas[n] = sum(xi ** n for xi in x)
    A = []
    B = []
    for i in range (k + 1):
        row = []
        for j in range(k + 1):
            row.append(somas[i + j])
        A.append(row)
        if i == 0:
            B.append(sum(y))
        else:
            B.append(sum(xi ** i * yi for xi, yi in zip(x,y)))
    return np.linalg.solve(A, B)
x = [-4.3263, -4.0012, -3.7713, -3.4507, -3.2903, -3.1801, -2.8898, -2.4129, -2.3493, -1.9817, -1.828, -1.5009, -1.2846, -1.0452, -0.7572, -0.473, -0.0685, 0.0766, 0.3928, 0.752, 0.8586, 1.1502, 1.3303, 1.7243, 1.9833, 2.2646, 2.4675, 2.6726, 3.1203, 3.374, 3.6756, 3.8516, 4.0347, 4.4345, 4.5325, 4.8008]
y = [2.5655, 4.8951, 7.0349, 7.2969, 8.0001, 7.6666, 7.4539, 7.183, 7.0174, 6.6282, 7.4481, 5.5266, 5.2848, 5.1685, 4.5172, 4.4162, 3.7131, 4.0986, 4.3082, 4.7866, 4.6055, 5.2455, 4.7589, 8.0167, 7.4256, 8.7588, 8.2158, 8.6785, 10.5912, 10.5876, 10.2945, 10.0581, 10.012, 8.6367, 8.3587, 6.7519]

a0, a1, a2, a3, a4 = best_poly(x, y, 4)

print(f'{a0 = } , {a1 = }, {a2 = }, {a3 = }, {a4 =}')
