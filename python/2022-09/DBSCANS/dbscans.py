from sklearn.cluster import DBSCAN
import numpy as np
import matplotlib.pyplot as plt

samples = np.loadtxt("./DBSACNS/kmeansSamples.txt")
clustering = DBSCAN(eps=5, min_samples = 5).fit(samples)
x = clustering.labels_
print(x)
plt.scatter(samples[:, 0], samples[:, 1], c=clustering.labels_ + 1.5, linewidths=np.power(clustering.labels_ + 1.5, 2))
plt.show()