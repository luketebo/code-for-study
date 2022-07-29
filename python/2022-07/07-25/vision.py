from pickletools import uint8
import time
import cv2 as cv
import numpy as np
import pyrealsense2 as rs
import socket, math, random
from resensets import *
from dataformat import dataformat as df

ip_remote = '192.168.123.161' # upboard IP
port_remote_color_x = 14514
port_remote_color_y = 14515
port_remote_color_w = 11451
port_remote_color_b = 11452
udp_socket_color_x = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 
udp_socket_color_y = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 
udp_socket_color_w = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_socket_color_b = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 

dp = DepthCamera()
max_center_x = 0
max_center_y = 0
max_x = 0
max_y = 0

ls_max, ls_min = df()
color_lower = np.array(ls_min, np.uint8) 
color_upper = np.array(ls_max, np.uint8)

while True:
    time_s = time.time()
    flag, depth_image, image = dp.get_frame()
    # print(mid)

    # Convert images to numpy arrays
    color_image = np.asanyarray(image)
    
    # cut = np.ones((480,320,3), dtype=np.uint8)

    # for i in range(160,480):
    #     for j in range(480):
    #         cut[j][i-160] = image[j][i]
    # color_image = np.asanyarray(cut)

    cut = image[:160,480]
    cut = np.asanyarray(color_image[:,160:480], dtype=np.uint8)
    # print(f"cost: {int(round(1000*(time.time()-time_s)))}ms")

    hsvFrame = cv.cvtColor(cut, cv.COLOR_BGR2HSV)

    # 61, 158, 145
    #color_lower = np.array([55, 150, 140], np.uint8) 
    #color_upper = np.array([65, 165, 155], np.uint8) 

    color_mask = cv.inRange(hsvFrame, color_lower, color_upper) 

    # Morphological Transform, Dilation 
    # for each color and bitwise_and operator 
    # between imageFrame and mask determines 
    # to detect only that particular color 
    kernal = np.ones((5, 5), "uint8") 

    color_mask = cv.dilate(color_mask, kernal) 
    # res = cv.bitwise_and(color_image, color_image, mask = color_mask)

    # Creating contour to track red color 
    _,contours,_ = cv.findContours(color_mask, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
    if not len(contours):
        udp_socket_color_x.sendto(bytes(str("0"), 'utf-8'), (ip_remote, port_remote_color_x))
        udp_socket_color_y.sendto(bytes(str("0"), 'utf-8'), (ip_remote, port_remote_color_y))
        cv.imshow("Color Detection in Real-Time", color_image)
        continue
    contour = contours[0]
    for i in contours:
        if cv.contourArea(i) > cv.contourArea(contour):
            contour = i
    # for pic, contour in enumerate(contours): 
    area = cv.contourArea(contour) 
    if(area > 600): 
        x, y, w, h = cv.boundingRect(contour)
        x += 160
        max_x = max(x, max_x)
        max_y = max(y, max_y)
        max_center_x = x + (int)(0.5 * w)
        max_center_y = y + (int)(0.5 * h)
        cv.circle(color_image,(x + (int)(0.5 * w), y + (int)(0.5 * h)), 1, (0,0,255), -1)
        color_image = cv.rectangle(color_image, (x, y), 
                                (x + w, y + h), 
                                (0, 0, 255), 2)	 

    # print(max_center)
    udp_socket_color_x.sendto(bytes(str(max_center_x), 'utf-8'), (ip_remote, port_remote_color_x))
    udp_socket_color_y.sendto(bytes(str(max_center_y), 'utf-8'), (ip_remote, port_remote_color_y))
    udp_socket_color_w.sendto(bytes(str(w), 'utf-8'), (ip_remote, port_remote_color_w))
    # print("x:{}".format(max_center_x))
    # print("y:{}".format(max_center_y))
    print(f"w:{w}\n")
    cv.imshow("Color Detection in Real-Time", color_image)
    k = cv.waitKey(5) & 0xFF
    if k == 27:
        break
