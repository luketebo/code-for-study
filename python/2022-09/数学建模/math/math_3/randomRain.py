from matplotlib import pyplot as plt
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
# 从我们的sklearn模块的数据集部分导入我们的红酒数据集
from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split, cross_val_score

# 2.简单查看数据集
wine = load_wine()
# 导入用于划分训练集和测试集的模块
# 在sklearn中，标签和特征必须分开导入进去

# 第一个参数我们的特征矩阵，第二个参数，我们的标签，第三个参数我们训练集和测试集划分的比例（0.3就是请用30%作为测试集，70%作为训练集）
Xtrain, Xtest, Ytrain, Ytest = train_test_split(wine.data, wine.target, test_size=0.3)
superpa = []
# 让随机森林在不同的n_estimators下跑了200次，也就是从1-200，
# 然后分别绘制十次交叉验证的准确率，追加到结果列表中
print('fuck')
for i in range(200):
    # 让树第一次建一棵，第二次建两棵，最后一直建到200棵
    # n_jobs指的是调用cpu的进程数量，比如n_jobs=8,会看到任务管理器中会有8个cpu进程，是为了加速运行。n_jobs=-1表示使用CPU所有的线程数进行运算，起到并行加速的作用
    rfc = RandomForestClassifier(n_estimators=i + 1, n_jobs=-1)
    # 得到十次交叉验证的平均值放入我们的结果列表中
    rfc_s = cross_val_score(rfc, wine.data, wine.target, cv=10).mean()
    superpa.append(rfc_s)
# 打印出最高的准确率和最高的准确率所在的位置
# list.index(object)  对象object在列表list当中的索引，下面的代码就是返回最大值和最大值所在的索引
print(max(superpa), superpa.index(max(superpa)))
plt.figure(figsize=[20, 5])
plt.plot(range(1, 201), superpa)
plt.show()
