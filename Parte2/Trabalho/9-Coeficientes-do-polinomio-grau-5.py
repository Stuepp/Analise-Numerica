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

x = [-4.1379, -3.7962, -3.7, -3.5019, -3.2489, -2.9944, -2.643, -2.4649, -2.2223, -2.0333, -1.7554, -1.5881, -1.335, -1.2623, -0.8403, -0.7327, -0.3991, -0.2219, 0.0033, 0.1607, 0.5204, 0.6905, 0.9679, 1.0992, 1.3703, 1.5324, 1.7267, 2.0991, 2.3431, 2.5891, 2.7986, 2.9121, 3.2702, 3.5203, 3.5616, 3.9297, 4.2159]
y = [3.8768, 6.3681, 6.7841, 7.4497, 7.408, 7.0775, 6.1335, 6.0844, 5.3461, 4.694, 4.6783, 4.255, 4.0774, 4.1404, 3.9838, 4.3907, 4.6925, 3.5647, 5.8521, 5.0781, 3.8732, 5.9036, 6.8387, 6.06, 5.7154, 5.6308, 5.6543, 4.9704, 3.982, 3.3893, 3.2373, 2.9144, 2.6451, 2.8628, 2.8667, 5.3371, 6.5679]

a0, a1, a2, a3, a4, a5 = best_poly(x, y, 5)

print(f'{a0 = } , {a1 = }, {a2 = }, {a3 = }, {a4 =}, {a5 =}')
