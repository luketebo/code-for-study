import numpy as np
import torch
import matplotlib.pyplot as plt

#sigmoid函数
def g(x):
    return 1/(1+torch.exp(-x))

def tanh(x):
    return (torch.exp(x)-torch.exp(-x))/(torch.exp(x)+torch.exp(-x))

def relu(x):
    return (torch.abs(x) + x) / 2.0

x = torch.linspace(-5,5,100)
fig, axes = plt.subplots(1,3,figsize = (12,5))
axes[0].plot(x.numpy(),g(x).numpy(),'r-.',label = 'sigmoid')
axes[0].legend()
axes[1].plot(x.numpy(),tanh(x).numpy(),label='sigmoid')
axes[1].legend()
axes[2].plot(x.numpy(),relu(x).numpy(),label='sigmoid')
axes[2].legend()
plt.show()
