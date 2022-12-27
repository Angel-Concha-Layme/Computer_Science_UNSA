import numpy as np
from math import sqrt

resultado_analitico_1 = 1.4557
def f1(x):
    e = np.exp(1)
    f_x = e **(x**2)
    return f_x

resultado_analitico_2 = 9.4016
def f2(x):
    e = np.exp(1)
    f_x = 4*e**x
    return f_x

resultado_analitico_3 = 0.572249j
def f3(x):
    e = 2.718281828459045
    f_x = complex(0,sqrt(e**(x**2)-1))
    return f_x

resultado_analitico_4 = 0.5
def f4(x):
    e = np.exp(1)
    f_x = x/((1+x**2)**2)
    return f_x

resultado_analitico_5 = 2.7399
def f5(x):
    e = np.exp(1)
    f_x = e**(x+x**2)
    return f_x

resultado_analitico_6 = 1
def f6(x):
    e = np.exp(1) 
    f_x = e **(-x)
    return f_x


def monte_carlo(f,a,b, resultado_analitico, n_iter=10**7):
    tam = b-a
    temp = 0
    samples = np.random.uniform(a,b,n_iter)
    for i in range(n_iter):
        temp += f(samples[i])
    resultado = (tam/n_iter)*temp 

    print("Iteraciones: ", n_iter)
    print("Resultado analítico: ", resultado_analitico)
    print("Resultado Monte Carlo: ", resultado)
    print("Error: ", abs(resultado_analitico - resultado))



#monte_carlo(f1,0,1,resultado_analitico_1)
#monte_carlo(f2,-1,1,resultado_analitico_2)
#monte_carlo(f3,0,1,resultado_analitico_3)
#monte_carlo(f4,0,1,resultado_analitico_4)
#monte_carlo(f5,0,1,resultado_analitico_5)
#monte_carlo(f6,0,10**4,resultado_analitico_6,5*10**6)