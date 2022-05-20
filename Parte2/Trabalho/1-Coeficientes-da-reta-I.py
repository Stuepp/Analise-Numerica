import numpy as np

def best_line(x, y):
    n = len(x)
    # soma das coordenadas x
    sum_x = sum(x)
    # soma das coordenadas x**2
    sum_x2 = sum(xi ** 2 for xi in x)
    # soma das coordenadas y
    sum_y = sum(y)
    #soma das coordenadas x*y
    sum_xy = sum(xi * yi for xi, yi in zip(x, y))

    # Matriz dos coeficientes
    A = [[n, sum_x], [sum_x, sum_x2]]
    # Matriz dos termos independentes
    B = [sum_y, sum_xy]

    return np.linalg.solve(A, B)

x = [0.1529, 0.3403, 0.6324, 0.9498, 1.4382, 1.7615, 2.1824, 2.3394, 2.7667, 2.894, 3.2022, 3.6072, 4.058, 4.1942, 4.4796, 4.9953, 5.0583, 5.3322, 5.8917, 5.9414, 6.2575, 6.7617, 6.9645, 7.1908, 7.5084, 7.9144, 8.3897, 8.5101, 9.0028, 9.2276, 9.437, 9.861]
y = [2.792, 2.9674, 3.5559, 4.2421, 5.2868, 5.2002, 5.8401, 6.1356, 6.796, 6.6782, 7.1121, 7.9298, 8.8285, 8.7583, 9.6511, 9.9168, 10.1552, 10.2217, 11.2282, 11.0571, 11.7451, 12.3525, 12.2457, 13.0258, 13.6102, 14.3977, 15.3137, 15.0053, 15.6632, 16.7179, 16.9523, 17.0512]

a0, a1 = best_line(x, y)

print(f'{a0 = } e {a1 = }')
