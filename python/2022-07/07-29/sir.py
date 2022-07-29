#   我们定义函数的名称为SIR
def SIR(y,t,beta,gamma):
    S,I,R = y
    dSdt = -S*(I/(S+I+R))*beta
    dIdt = beta*S*I/(S+I+R)-gamma*I
    dRdt = gamma*I
    return [dSdt,dIdt,dRdt]

    
# 设置人群总人数为N
N = 58000000
# 设置初始时的感染人数I0为239
I0 = 239
# 设置初始时的恢复人数R0为31
R0 = 31
# 所以，初始易感者人群人数 = 总人数 - 初始感染人数 - 初始治愈人数
S0 = N - I0 - R0
# 设置初始值
y0 = [S0, I0, R0]

import numpy as np

# 设置估计疫情的时间跨度为60天
t = np.linspace(1,60,60)

# 设置beta值等于0.125
beta = 0.125

# 设置gamma的值等于0.05
gamma = 0.05

from scipy.integrate import odeint

# 求解
solution = odeint(SIR, y0, t, args = (beta, gamma))

# 要求Python的所有输出不用科学计数法表示
np.set_printoptions(suppress=True)

# 输出结果的前四行进行查看
print(solution[0:4,0:3])

