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
    x=[0.76, 2.66, 4.491]
    y=[4.67, 4.227, 2.352]

    coeffs = poly(x,y)
    #print(coeffs)

#imprime coeffs:
    #for x in (coeffs):
        #print("%.16f" %x)
    
    #calcula valores de x
    def p(x):
        return func_poly(x,coeffs)
    # valores dos x:
    print(p(4.379))
        
    
