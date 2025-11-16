##
## EPITECH PROJECT, 2025
## Projet [WSL: Ubuntu-24.04]
## File description:
## flags.py
##

import sys
import math

def h_flag():
    print("USAGE")
    print("    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg21 [arg22]] ...\n")
    print("DESCRIPTION")
    print("    x  abscissa of the original point")
    print("    y  ordinate of the original point")
    print("    transfo arg1 [arg2]")
    print("    -t i j  translation along vector (i, j)")
    print("    -z m n  scaling by factors m (x-axis) and n (y-axis)")
    print("    -r d  rotation centered in O by a d degree angle")
    print("    -s d  reflection over the axis passing through O with an inclination angle of d degrees")
    sys.exit(0)

class Architect:
    def __init__(self, x, y, i, j, m, n, d_rotate, d_reflection):
        self.x = float(x)
        self.y = float(y)
        self.i = float(i)
        self.j = float(j)
        self.m = float(m)
        self.n = float(n)
        self.d_rotate = int(d_rotate)
        self.d_reflection = int(d_reflection)
        self.matrix_xy = [self.x, self.y, 1]
        self.identity_matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]

    def print_result(self):
        result = self.matrix_multiplier()
        print(f"{self.identity_matrix[0][0]:.2f} {self.identity_matrix[0][1]:.2f} {self.identity_matrix[0][2]:.2f}")
        print(f"{self.identity_matrix[1][0]:.2f} {self.identity_matrix[1][1]:.2f} {self.identity_matrix[1][2]:.2f}")
        print(f"{self.identity_matrix[2][0]:.2f} {self.identity_matrix[2][1]:.2f} {self.identity_matrix[2][2]:.2f}")
        print(f"({self.matrix_xy[0]:.2f}, {self.matrix_xy[1]:.2f} => {result[0]:.2f}, {result[1]:.2f})")

    def matrix_multiplier(self):
        return [self.identity_matrix[0][0] * self.matrix_xy[0] + self.identity_matrix[0][1] * self.matrix_xy[1] + self.identity_matrix[0][2] * self.matrix_xy[2],
        self.identity_matrix[1][0] * self.matrix_xy[0] + self.identity_matrix[1][1] * self.matrix_xy[1] + self.identity_matrix[1][2] * self.matrix_xy[2],
        self.identity_matrix[2][0] * self.matrix_xy[0] + self.identity_matrix[2][1] * self.matrix_xy[1] + self.identity_matrix[2][2] * self.matrix_xy[2]]

    def translation(self):
        self.identity_matrix[0][2] = self.i
        self.identity_matrix[1][2] = self.j
        print(f"Translation along vector ({self.i:.0f}, {self.j:.0f})")


    def scaling(self):
        self.identity_matrix[0][0] = self.m
        self.identity_matrix[1][1] = self.n
        print(f"Scaling by factors {self.m:.0f} and {self.n:.0f}")


    def rotate(self):
        self.identity_matrix[0][0] = math.cos((math.radians(self.d_rotate)))
        self.identity_matrix[0][1] = -math.sin(math.radians(self.d_rotate))
        self.identity_matrix[1][0] = math.sin(math.radians(self.d_rotate))
        self.identity_matrix[1][1] = math.cos(math.radians(self.d_rotate))
        print(f"Rotation by a {self.d_rotate} degree angle")

    def reflection(self):
        self.identity_matrix[0][0] = math.cos((math.radians(2 * self.d_reflection)))
        self.identity_matrix[0][1] = math.sin(math.radians(2 * self.d_reflection))
        self.identity_matrix[1][0] = math.sin(math.radians(2 * self.d_reflection))
        self.identity_matrix[1][1] = -math.cos(math.radians(2 * self.d_reflection))
        print(f"Reflection over an axis with an inclination angle of {self.d_reflection} degrees")

def t_flag(args, archi, last_flag):
    archi.translation()
    if last_flag == "-t":
        archi.print_result()

def z_flag(args, archi, last_flag):
    archi.scaling()
    if last_flag == "-z" :
        archi.print_result()

def r_flag(args, archi, last_flag):
    archi.rotate()
    if last_flag == "-r":
        archi.print_result()

def s_flag(args, archi, last_flag):
    archi.reflection()
    if last_flag == "-s":
        archi.print_result()