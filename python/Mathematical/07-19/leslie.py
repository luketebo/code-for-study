# 莱斯利Leslie种群模型
import numpy as np
import sympy as sp

X0 = np.array([500, 1000, 500])
L = np.array([[0, 4, 3], [0.5, 0, 0], [0, 0.25, 0]])
X1 = L @ X0
X2 = L @ X1
X3 = L @ X2
Ls = sp.Matrix([[0, 4, 3], [sp.Rational(1, 2), 0, 0], [0, sp.Rational(1, 4), 0]])  # 符号矩阵
lamda = sp.var('lamda')
p = Ls.charpoly(lamda)  # 计算特征多项式  #re-A的行列式
# w11 = Ls.eigenvals()
# w22 = Ls.eigenvects()
w1 = sp.roots(p)  # 特征值
w2 = Ls.eigenvals()  # 直接计算特征值
v = Ls.eigenvects()
# print("特征值", w2)

# print(w1)
# print('特征向量', v)
P, D = Ls.diagonalize()  # 相似对角化
Pinv = P.inv()  # 求逆矩阵
Pinv = sp.simplify(Pinv)
cc = Pinv @ X0
# print(P)
# print(cc[0])
# print(w1)
# print(v)
k = sp.var('k', positive=True, integer=True)
xk = P @ (D ** k) @ Pinv @ sp.Matrix(X0)
# print(xk)
# print(xk[0])
s = sp.simplify(xk[0])
print(s.subs(k, 2).n())  # # 计算第k个时期的种群数量

