import numpy as np


def poly(x,y):
    n = len(x)-1
    A =[]
    B =[]
    for xi in x:
        row = [1]
        for j in range(1, n+1):
            row.append(xi ** j)
        A.append(row)
    return np.linalg.solve(A, y)

def func_poly(x, coeffs):
    first=coeffs[0]
    return first + sum([ai * x ** j for j, ai in enumerate(coeffs[1:], 1)])

if __name__ == '__main__':
    #valores das listas
    #x=[0.401, 4.059, 6.575]
    #y=[4.385, 2.657, 2.847]
    
    x = [0.138, 1.7, 2.793, 3.145, 4.356, 5.805, 6.421]
    y = [4.137, 4.895, 4.082, 3.667, 2.43, 2.417, 2.763]

    coeffs = poly(x,y)
    
#imprime coeffs:
    for x in (coeffs):
        print("%.16f" %x)
        
    
