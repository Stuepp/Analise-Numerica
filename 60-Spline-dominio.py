#algoritmo spline cúbico
import math
import numpy as np

def spline(x, y):
    n = len(x)
    a = {k: v for k, v in enumerate(y)}
    h = {k: x[k + 1] - x[k] for k in range(n - 1)}

    # Matriz dos coeficientes
    A = [[1] + [0] * (n - 1)]
    for i in range(1, n - 1):
        row = [0] * n
        row[i - 1] = h[i - 1]
        row[i] = 2 * (h[i - 1] + h[i])
        row[i + 1] = h[i]
        A.append(row)
    A.append([0] * (n - 1) + [1])

    # termos independentes
    B = [0]
    for k in range(1, n - 1):
        row = 3 * (a[k + 1] - a[k]) / h[k] - 3 * (a[k] - a[k - 1]) / h[k - 1]
        B.append(row)
    B.append(0)

    c = dict(zip(range(n), np.linalg.solve(A, B)))

    b = {}
    d = {}
    for k in range (n - 1):
        b[k] = (1/h[k]) * (a[k+1] - a[k]) - (h[k]/3) * (2 * c[k] + c[k+1])
        d[k] = (c[k+1] - c[k]) / (3 * h[k])

    s = {}
    for k in range(n - 1):
        eq = f'{a[k]}{b[k]:+}*(x-{x[k]}){c[k]:+}*(x-{x[k]})**2{d[k]:+}*(x-{x[k]})**3'
        s[k] = {'eq': eq, 'domain': [x[k + 1]]}

    return s

# (1,1), (2,4), (4,2), (5,3)
x = [-3.011, -0.523, 0.979, 3.205]
y = [4.482, 3.997, 3.544, 3.762]


eqs = spline(x,y)
print(eqs)

# olhar as funções, pegar a função na qual x pertence ao dominio, criar uma função com o x e a função adequada para calcular f(x). Exemplo para 0.89 a função correta é a 1:

x = 0.89
resposta = 3.997-0.3162321443762325*(x--0.523)-0.07312889050918671*(x--0.523)**2+0.055174489235705004*(x--0.523)**3 

print(resposta)
