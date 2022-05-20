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

x = [0.0418, 0.6327, 0.815, 1.2518, 1.4598, 1.8996, 2.1772, 2.3054, 2.7506, 2.975, 3.2489, 3.8174, 4.1441, 4.4121, 4.6239, 4.8682, 5.1723, 5.5712, 5.9837, 6.2146, 6.5343, 6.7857, 7.1752, 7.5306, 7.984, 8.2338, 8.5284, 8.8482, 9.1138, 9.6343, 9.8086]
y = [4.661, 6.1473, 6.808, 4.5192, 4.6836, 4.2222, 3.9826, 2.5766, 4.2923, 3.7976, 3.7518, 4.0281, 4.5257, 3.7207, 3.9677, 2.1923, 4.006, 3.4383, 3.4455, 4.2771, 4.2954, 3.4797, 4.4112, 4.4942, 4.8796, 4.1307, 5.1542, 5.4461, 7.1061, 5.6429, 6.1134]
a0, a1, a2 = best_poly(x, y, 2)

print(f'{a0 = } , {a1 = }, {a2 = }')
