import numpy as np
import cv2
# python\image\img\1.jpg
# D:\Code-repository\Visual Studio Code\python\image\img\1.jpg
im = cv2.imread("1.jpg")
try:
    im.shape
except:
    print("Can not read this image!")
imgray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(imgray, 127, 255, 0)
image, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
