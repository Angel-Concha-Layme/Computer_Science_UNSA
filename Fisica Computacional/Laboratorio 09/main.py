from math import cos
from math import sin

def Biseccion(f,a,b,error,iter):
    tramo = b-a
    fa = f(a) 
    fb = f(b)
    while tramo>error and iter>0:
        mid = (a+b)/2
        fmid = f(mid)
        if(fa*fmid<0):
            b = c
            fb = fmid
        elif (fmid*fb<0):
            a = c 
            fa = fmid
        else:
            return "No converge"

        tramo = b-a
        iter = iter-1
    c = (a+b)/2
    return c


def Newton_Raphson(f,d_f, x_0, error, iter):
    tramo = abs(2*error)
    x_i = x_0
    while (tramo>error and iter>0):
        temp = x_i - f(x_i)/d_f(x_i)
        iter = iter-1
        tramo = abs(temp-x_i)
        x_i = temp
    return x_i


def Falsa_Posicion(f,a,b, error, iter):
    tramo = abs(b-a)
    while tramo>error and iter> 0:
        fa = f(a)
        fb = f(b)
        mid = b-fb*(b-a)/(fb-fa)
        fmid = f(mid)

        if(fa*fmid<0):
            tramo = abs(b-mid)
            b = mid
        elif (fmid*fb<0):
            tramo = abs(mid-a)
            a = mid
        else:
            return "No converge"
        iter = iter-1
    return fmid 

def Secante(f,a,b,error,iter):
    dx = 4*error
    tramo = dx
    while (tramo>=error and iter>0):
        fa = f(a) 
        fb = f(b) 
        c = a - fa*(b-a)/(fb-fa)
        tramo = abs(c-a)
        b = a 
        a = c
        iter = iter-1
    return c




def x1(x):
    e = 2.7182818284590452353602874713527
    return e**(-x)

#result1 = Biseccion(x1, 2, 1000, 0.0001, 100)
#print(result1)


def x2(x):
    e = 2.7182818284590452353602874713527
    return e**(x)-x

#result2 = Falsa_Posicion(x2, -3, 4, 0.0001, 100)
#print(result2)


def x3(x):
    e = 2.7182818284590452353602874713527
    return 10*e**(x/2)*cos(2*x)-4

#result3 = Falsa_Posicion(x3, 1, 2, 0.0001, 100)
#print(result3)



def x4(x):
    e = 2.7182818284590452353602874713527
    return x**2-2

def d_x4(x):
    return 2*x

#result4 = Newton_Raphson(x4, d_x4, 1, 0.0001, 100)
#print (result4)


def x5(x):
    return x**3 -2

#result5 = Secante(x5, 0, 2, 0.0001, 100)
#print (result5)


def x6(x,y=0):
    return x*cos(y) + y*sin(x) -2

#result6 = Secante(x6, 5, 2, 0.0001, 100)
#print (result6)


def x7(x,y=0):
    return x**3 + 4*x**2 -10

def d_x7(x):
    return 3*x**2 + 8*x

#result7 = Newton_Raphson(x7, d_x7, 1, 0.0001, 100)
#print (result7)



def all_test():
    e = 2.7182818284590452353602874713527
    assert Biseccion(x1, 2, 1000, 0.0001, 100) == 2.7182
    assert Falsa_Posicion(x2, -3, 4, 0.0001, 100) == 0.5671
    assert Falsa_Posicion(x3, 1, 2, 0.0001, 100) == 1.0986
    assert Newton_Raphson(x4, d_x4, 1, 0.0001, 100) == 1.4142
    assert Secante(x5, 0, 2, 0.0001, 100) == 1.2599
    assert Secante(x6, 5, 2, 0.0001, 100) == 3.1415
    assert Newton_Raphson(x7, d_x7, 1, 0.0001, 100) == 1.2599

all_test()
