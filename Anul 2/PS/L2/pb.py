import matplotlib
matplotlib.use('TkAgg')

from itertools import product
from random import randint
from matplotlib.pyplot import plot, grid, xticks, yticks, title, show

sum_counts={total : 0 for total in range(3,19)}
for roll in product(range(1,7),repeat=3):
    sum_counts[sum(roll)] += 1

plot(sum_counts.keys(),sum_counts.values(),'o')
show()

sum_rand={total : 0 for total in range(3,19)}

for i in range(1,100001):
    sum = 0
    sum += randint(1,6)
    sum += randint(1,6)
    sum += randint(1,6)
    sum_rand[sum] += 1

plot(sum_rand.keys(),sum_rand.values(),'o')
show()
