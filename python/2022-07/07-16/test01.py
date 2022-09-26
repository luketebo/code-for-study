import numpy as np
from scipy import optimize

c = [-2, -3, 5]
a = [[-2, 5, -1], [1, 3, 1]]
b = [-10, 12]
aeq = [[1, 1, 1]]
beq = [7]
bounds = [[0, None], [0, None], [0, None]]
result = optimize.linprog(c, a, b, aeq, beq, bounds)
print(result)