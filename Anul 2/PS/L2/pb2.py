import matplotlib
matplotlib.use('TkAgg')

from matplotlib.pyplot import axis, plot, show
from random import random
from math import dist
from math import pi


def cond():
    return (pow(dist(A,F),2) + pow(dist(B,F),2) < 1) + (pow(dist(C,F),2) + pow(dist(D,F),2) < 1) + (pow(dist(C,F),2) + pow(dist(A,F),2) < 1) +(pow(dist(D,F),2) + pow(dist(A,F),2) < 1) == 2


def problema(N,X):
    axis('square')
    axis((0, 1, 0, 1))
    F=[random(),random()]
    plot(F[0],F[1],'ro')
    nr_pct_bune = 0

    A,B,C,D,E = [0,0],[1,0],[1,1],[0,1],[0.5,0.5]

    match X:
        case 1:
            for i in range(N):
                F = [random(),random()]
                if dist(E,F) < 0.5:
                    nr_pct_bune += 1
                    plot(F[0],F[1],'ro')
                else:
                    plot(F[0],F[1],'bo')
            print(pi/4)
        case 2:
            for i in range(N):
                F = [random(),random()]
                if dist(E,F) < min(dist(A,F),dist(B,F),dist(C,F),dist(D,F)):
                    nr_pct_bune += 1
                    plot(F[0],F[1],'ro')
                else:
                    plot(F[0],F[1],'bo')
            print(1/2)
        case 3:
            for i in range(N):
                F = [random(),random()]
                if dist(E,F) < F[1]:
                    nr_pct_bune += 1
                    plot(F[0],F[1],'ro')
                else:
                    plot(F[0],F[1],'bo')
            print(2/3)
        case 4:
            for i in range(N):
                F = [random(),random()]
                if (pow(dist(A,F),2) + pow(dist(B,F),2) < 1) + (pow(dist(B,F),2) + pow(dist(C,F),2) < 1) + (pow(dist(C,F),2) + pow(dist(D,F),2) < 1) +(pow(dist(D,F),2) + pow(dist(A,F),2) < 1) == 2:
                    nr_pct_bune += 1
                    plot(F[0],F[1],'ro')
                else:
                    plot(F[0],F[1],'bo')
            print(pi/2 - 1)

    print(nr_pct_bune/N)
    show()

problema(2000,1)
problema(2000,2)
problema(2000,3)
problema(2000,4)