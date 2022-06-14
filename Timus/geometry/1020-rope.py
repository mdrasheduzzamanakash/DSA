from math import *

n, r = input().split(" ")
n = int(n)
r = float(r)

peri = 2 * r * 3.14159
dist = peri


def distance(x1, y1, x2, y2):
    dx = x1 - x2
    dy = y1 - y2
    return sqrt(dx ** 2 + dy ** 2)


a, b, p, q = 0, 0, 0, 0
for i in range(0, n):
    c, d = map(float, input().split(" "))
    if i == 0:
        p, q = c, d
    else:
        dist += distance(a, b, c, d)

    a, b = c, d

dist += distance(a, b, p, q)
print("{0:0.2f}".format(dist))
