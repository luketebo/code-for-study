# _*_ coding:utf-8 _*_
import csv
from random import random

from sklearn.feature_extraction import DictVectorizer
from sklearn import preprocessing
from sklearn import tree
import pydotplus

film_data = open('qianJia_copy.csv', 'rt', encoding='UTF-8')
reader = csv.reader(film_data)

# 表头信息
headers = next(reader)
print(headers)

feature_list = []
result_list = []

for row in reader:
    result_list.append(row[0])
    # 去掉首位列，
    feature_list.append(dict(zip(headers[1:-1], row[1:-1])))
print(result_list)
print(feature_list)

vec = DictVectorizer()  # 将数据类型转换成numpy array
dummyX = vec.fit_transform(feature_list).toarray()
dummyY = preprocessing.LabelBinarizer().fit_transform(result_list)
# humidity、outlook、temperature、windy
# high,normal;overcast、Rainy、sunny;cool,hot,mild;false,true;
print(dummyX)
print(dummyY)

clf = tree.DecisionTreeClassifier(criterion='gini', random_state=None)
clf = clf.fit(dummyX, dummyY)
print("clf:" + str(clf))

dot_data = tree.export_graphviz(clf,
                                feature_names=vec.get_feature_names(),
                                filled=True, rounded=True,
                                special_characters=True,
                                out_file=None)
graph = pydotplus.graph_from_dot_data(dot_data)
graph.write_pdf("qianJia_copy.pdf")

# 开始预测
#
# A = ([[1, 0, 0, 1, 0, 0, 0, 1, 1, 0]])
# predict_result = clf.predict(A)
# if predict_result == 1:
#     print("预测结果：高钾")
# else:
#     print("预测结果：铅钡")
