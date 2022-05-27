import numpy as np

def best_poly(x, y, grau = 1):
    k = grau + 1
    A = [[0 for _ in range(k)] for _ in range(k)]
    B = [sum(y)]
    n = len(x)
    cache = {}
    for i in range(k):
        for j in range(k):
            p = i + j
            if (p == 0):
                A[0][0] = n
                continue
            if p not in cache:
                cache[p] = sum([xi ** p for xi in x])
            A[i][j] = cache[p]
        if i > 0:
            B.append(sum([yi * xi ** i for xi, yi in zip(x, y)]))
    return np.linalg.solve(A, B)

def poly(x, a, b):
    return a * 2 ** (b * x)

def build_func(a, b):
    def temp(x):
        return poly(x, a, b)
    return temp

if __name__ == '__main__':
    
    x = [0.0379, 0.0726, 0.1392, 0.1738, 0.255, 0.2928, 0.3462, 0.4362, 0.4982, 0.5507, 0.588, 0.642, 0.7125, 0.7316, 0.8008, 0.8556, 0.935, 0.9469, 1.0425, 1.0969, 1.1183, 1.2174, 1.2591, 1.2912, 1.3721, 1.4079, 1.4521, 1.5273, 1.5601, 1.6171, 1.7081, 1.7773, 1.8139, 1.885, 1.8951, 1.9834]
    y = [7.5224, 4.4047, 5.9654, 6.5313, 6.0728, 7.5339, 6.7795, 7.6707, 9.1041, 6.8059, 9.8151, 11.3915, 12.5555, 12.3296, 11.4496, 13.3053, 13.4136, 13.7677, 17.3919, 19.3391, 19.8833, 22.4702, 23.4803, 25.8601, 28.7464, 29.6213, 31.3797, 34.2454, 36.7304, 39.3126, 45.0555, 48.9025, 53.3028, 58.2707, 57.9401, 64.6443]
    y_ = np.log(y)
 
    grau = 1

    a0, a1 =  best_poly(x, y_, grau)

    print(f'{a0 = } e {a1 = }')

    a = np.exp(a0)
    b = a1/np.log(2)

    print(f'{a = } e {b = }')

    p = build_func(a, b)

    x_values = [0.8726, 1.2674, 1.7275, 1.865, 1.913]
    
    for xi_v in x_values:
        print(p(xi_v))
