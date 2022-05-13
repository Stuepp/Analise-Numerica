import numpy as np
import math 

def dif_div(x, y):
    Y = [yi for yi in y]
    coefs = [y[0]]
    for j in range(len(x)-1):
        for i in range(len(x)-1-j):
            number = Y[i+1]-Y[i]
            denom = x[i+1+j]-x[i]
            div = number/denom
            Y[i] = div
        coefs.append(Y[0])
    return coefs


def poly(t, x, coefs):
    val = 0
    for i in range(len(coefs)):
        prod = 1
        for j in range(i):
            prod *= (t-x[j])
        val += coefs[i]*prod
    return val


def build_func(x, coefs):
    def temp(t):
        return poly(t, x, coefs)
    return temp


if __name__ == '__main__':
    x = [1, 2, 3, 4]
    y = [0, 1, 5, 1]

    coefs = dif_div(x, y)
    p = build_func(x, coefs)
    print(coefs)
    print(p(1), p(2), p(3), p(4))
