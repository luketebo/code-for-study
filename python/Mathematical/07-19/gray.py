# 首先引入包
import matplotlib.pyplot
import numpy as np
import matplotlib.pyplot as plt
import math as mt

# 原始序列
X0 = [89677, 99215, 109655, 120333, 135823, 159878, 182321, 209407, 246619, 300670]

# 计算轴向元素累加和
X1 = [89677]
add = X0[0] + X0[1]
X1.append(add)
i = 2
while i < len(X0):
    add = add + X0[i]
    X1.append(add)
    i += 1
print("X1", X1)
M = []
j = 1
while j < len(X1):
    num = (X1[j] + X1[j - 1]) / 2
    M.append(num)
    j = j + 1
print("M", M)

# 最小二乘法
Y = []
x_i = 0
while x_i < len(X0) - 1:
    x_i += 1
    Y.append(X0[x_i])
Y = np.mat(Y).T
Y.reshape(-1, 1)
print("Y", Y)
B = []
b = 0
while b < len(M):
    B.append(-M[b])
    b += 1
print("B:", B)
B = np.mat(B)
B.reshape(-1, 1)
B = B.T
c = np.ones((len(B), 1))
B = np.hstack((B, c))
print("c", c)
print("b", B)

# 设置参数
beta = np.linalg.inv(B.T.dot(B)).dot(B.T).dot(Y)
a = beta[0]
b = beta[1]
const = b / a
print(beta)
print(type(beta))

# 预测模型
F = [X0[0]]
k = 1
while k < len(X0) + 10:
    F.append((X0[0] - const) * mt.exp(-a * k) + const)
    k += 1
print("F", F)

# 得到预测序列
x_hat = [X0[0]]
g = 1
while g < len(X0) + 10:
    print(g)
    x_hat.append(F[g] - F[g - 1])
    g += 1
X0 = np.array(X0)
x_hat = np.array(x_hat)
print(x_hat)

# 设置时间序列
t1 = range(1999, 2009)
t2 = range(1999, 2019)

# 结果可视化
plt.plot(t1, X0, color='r', linestyle="--", label='true')
plt.plot(t2, x_hat, color='b', linestyle="--", label="predict")
plt.legend(loc='upper right')
plt.xlabel('year')
plt.ylabel('Profit')
plt.title('Profit prediction for company by Grey model')
plt.show()