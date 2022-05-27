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
    return a * np.exp(b * x)

def build_func(a, b):
    def temp(x):
        return poly(x, a, b)
    return temp

if __name__ == '__main__':

    x = [0.1143, 0.2978, 0.383, 0.6087, 0.7355, 0.8348, 1.0448, 1.235, 1.4277, 1.6645, 1.7714, 1.8723]
    y = [5.9605, 6.8011, 9.8388, 14.4726, 18.37, 22.5543, 33.3628, 45.3153, 63.7989, 99.3051, 118.3698, 141.8039]
    y_ = np.log(y)

    grau = 1

    a0, a1 = best_poly(x, y_, grau)

    print(f'{a0 = } e {a1 = }')

    a = np.exp(a0)
    b = a1

    print(f'{a = } e {b = }')

    p = build_func(a, b)
    
    x_values = [0.8368, 1.1051, 1.6487]
    
    for xi_v in x_values:
        print(p(xi_v))
