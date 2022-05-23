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

x = [-4.8627, -4.5849, -4.0821, -3.9027, -3.6337, -3.2626, -2.9981, -2.5763, -2.1504, -1.8871, -1.6332, -1.1919, -0.8098, -0.484, -0.4354, -0.0325, 0.4147, 0.8167, 1.135, 1.3777, 1.739, 1.7944, 2.4255, 2.6898, 2.9581, 3.3569, 3.4289, 3.9563, 4.1914, 4.4443, 5.0284, 5.1204, 5.3961, 5.8106]
y = [3.334, 3.4043, 4.6975, 5.1515, 5.3219, 6.1245, 6.3786, 6.2484, 6.5301, 6.2813, 6.5713, 5.8278, 5.9698, 5.5557, 5.7143, 4.9543, 4.5245, 4.5211, 5.688, 4.1275, 3.9584, 3.9562, 4.5139, 3.9196, 3.6111, 4.4185, 5.1445, 6.2118, 5.5198, 6.5166, 9.1543, 8.3878, 9.2922, 9.52]

a0, a1, a2, a3 = best_poly(x, y, 3)

print(f'{a0 = } , {a1 = }, {a2 = }, {a3 = }')
