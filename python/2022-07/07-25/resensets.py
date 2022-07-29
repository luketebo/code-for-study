import pyrealsense2 as rs
import numpy as np
import cv2 as cv
import math, random

class DepthCamera:
    def __init__(self):
        # Configure depth and color streams
        self.pipeline = rs.pipeline()
        config = rs.config()

        # Get device product line for setting a supporting resolution
        pipeline_wrapper = rs.pipeline_wrapper(self.pipeline)
        pipeline_profile = config.resolve(pipeline_wrapper)
        device = pipeline_profile.get_device()
        device_product_line = str(device.get_info(rs.camera_info.product_line))

        # config.enable_stream(rs.stream.color, 960, 540, rs.format.bgr8, 30)

        # Start streaming
        self.pipeline.start(config)
        self.get_frame()
        self.__init_t__()

    def get_frame(self):
        frames = self.pipeline.wait_for_frames()
        depth_frame = frames.get_depth_frame()
        color_frame = frames.get_color_frame()

        depth_image = np.asanyarray(depth_frame.get_data())
        color_image = np.asanyarray(color_frame.get_data())
        if not depth_frame or not color_frame:
            return False, None, None        
        return True, depth_image, color_image

    def __init_t__(self) -> None:
        self.release()
        self.pipeline = rs.pipeline()
        config = rs.config()

        # Get device product line for setting a supporting resolution
        pipeline_wrapper = rs.pipeline_wrapper(self.pipeline)
        pipeline_profile = config.resolve(pipeline_wrapper)
        device = pipeline_profile.get_device()
        device_product_line = str(device.get_info(rs.camera_info.product_line))

        # config.enable_device_from_file(config, bagfile, repeat_playback=False)
        config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
        config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
        self.pipeline.start(config)

    def release(self):
        self.pipeline.stop()

def sZoom(num):
    return int((math.sqrt(num*100/255)*10)*255/100)


def numToColor(num):
    num = int(num)
    r = g = b = 0
    r = 255 - num
    g = num
    b = num if num < 125 else 255 - num
    r = sZoom(r)
    g = sZoom(g)
    b = sZoom(b)
    # r += b/2
    # g += b/2
    return (r, g, b)




def depPro(depth_image):
    img = np.ones((480,640,3))

    max_dis = 0

    for i in depth_image:
        for j in i:
            max_dis = max(max_dis, j)

    # print(len(img[0][0]))
    # print(max_dis)

    for i in range(640):
        for j in range(480):
            B, G, R = 0, 2, 1
            img[j][i] = numToColor(depth_image[j][i] * 100 /max_dis)
    return img

# hsvFrame = cv.cvtColor(image, cv.COLOR_BGR2HSV)
# img = cv.cvtColor(depth_image, cv.COLOR_GRAY2BGR)
def showP(img):
    while True:
        cv.imshow("image", img)
        if cv.waitkey(0): 
            dp.release()
            exit()

def detect(image):
    danger = 0
    pows = [1, 4, 2, 8, 32, 16]
    for p, m in enumerate([60, 260, 460]):
        cut = np.ones((90,120))
        for i in range(120):
            for j in range(90):
                cut[j][i] = image[210+j][m+i]

        sum = 0

        points = 30

        for i in range(points):
            x = random.randint(0,89)
            y = random.randint(0,119)
            # print(f"x:{x}, y:{y}, cut:{cut[x][y]}")
            sum += cut[x][y]
        # print(sum/10)
        if sum/points < 600:
            danger += pows[p+3]
            continue
        if sum/points < 1200:
            danger += pows[p]
    return danger

if __name__ == "__main__":
    dp = DepthCamera()

    for i in range(30):
        flag, depth_image, image = dp.get_frame() 
    while False:
        flag, depth_image, image = dp.get_frame()
        print(detect(depth_image))

    if True:
        cv.imwrite("image.jpg", image)
        cv.imwrite("dis_d.jpg", depPro(depth_image))
        
        cut = np.ones((90,120,3))
        for i in range(120):
            for j in range(90):
                cut[j][i] = image[210+j][260+i]

        cut = np.ones((480,320,3))
        cv.imwrite("cut.jpg", cut)
        for i in range(160,480):
            for j in range(480):
                cut[j][i-160] = image[j][i]
        cv.imwrite("cut.jpg",cut)


    x = 260
    y = 210
    w = 120
    h = 90

    image = cv.rectangle(image, (x, y), (x + w, y + h), 
                                        (0, 0, 255), 2)
    x = 60
    image = cv.rectangle(image, (x, y), (x + w, y + h), 
                                        (0, 0, 255), 2)
    x = 460
    image = cv.rectangle(image, (x, y), (x + w, y + h), 
                                        (0, 0, 255), 2)

    cv.imwrite("dis.jpg", image)
    # cv.imwrite("dis_d.jpg", depPro(depth_image))
    
    while True:
        flag, depth_image, image = dp.get_frame()
        cv.imshow("dis.jpg", image)
        k = cv.waitKey(5) & 0xFF
        if k == 27:
            break

    dp.release()

# 640 480
# 380 180
# (260, 210)
# (380, 300)