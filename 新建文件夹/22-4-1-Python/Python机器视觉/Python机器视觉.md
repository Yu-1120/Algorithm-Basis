# Python机器视觉

```python
# pip install pystrich
from pystrich.code128 import Code128Encoder

encoder = Code128Encoder("9787020010059", options={
    # 条形码图片的放大倍数（精度）

    "ttf_fontsize": 50,

    "ttf_font": "simhei",

})

# bar_width -- 生成条形码的宽度，默认参数为3

encoder.save("条形码.png", bar_width=20)
```

# TiaoxingMa

```python
# coding=utf-8
# 导入python包
from imutils.video import VideoStream
import numpy as np
import imutils
import argparse
import time
import cv2

def detect(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    ddepth = cv2.cv.CV_32F if imutils.is_cv2() else cv2.CV_32F
    gradX = cv2.Sobel(gray, ddepth=ddepth, dx=1, dy=0, ksize=-1)
    gradY = cv2.Sobel(gray, ddepth=ddepth, dx=0, dy=1, ksize=-1)

    gradient = cv2.subtract(gradX, gradY)
    gradient = cv2.convertScaleAbs(gradient)

    blurred = cv2.blur(gradient, (9, 9))
    (_, thresh) = cv2.threshold(blurred, 225, 255, cv2.THRESH_BINARY)

    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (21, 7))
    closed = cv2.morphologyEx(thresh, cv2.MORPH_CLOSE, kernel)

    closed = cv2.erode(closed, None, iterations=4)
    closed = cv2.dilate(closed, None, iterations=4)

    cnts = cv2.findContours(closed.copy(), cv2.RETR_EXTERNAL,
                            cv2.CHAIN_APPROX_SIMPLE)
    cnts = imutils.grab_contours(cnts)

    if len(cnts) == 0:
        return None

    c = sorted(cnts, key=cv2.contourArea, reverse=True)[0]
    rect = cv2.minAreaRect(c)
    box = cv2.cv.BoxPoints(rect) if imutils.is_cv2() else cv2.boxPoints(rect)
    box = np.int0(box)

    return box


# 构建并解析参数
ap = argparse.ArgumentParser()
ap.add_argument("-v", "--video", help="path to the (optional) video file")
args = vars(ap.parse_args())

# 如果视频不存在则进行视频捕获
if not args.get("video", False):
    vs = VideoStream(src=0).start()
    time.sleep(2.0)
# 否则装载视频
else:
    vs = cv2.VideoCapture(args["video"])

# 循环处理每一帧
while True:
    # 获取当前帧
    frame = vs.read()
    frame = frame[1] if args.get("video", False) else frame

    # 判断是否达到视频的最后一帧
    if frame is None:
        break

    # 进行单张图片检测
    box = detect(frame)

    # 如果发现了条形码则绘制结果
    if box is not None:
        cv2.drawContours(frame, [box], -1, (0, 255, 0), 2)

    # 显示当前帧的结果
    cv2.imshow("Frame", frame)
    key = cv2.waitKey(1) & 0xFF

    # 当用户按下q键时退出整个循环
    if key == ord("q"):
        break

# 停止视频捕获
if not args.get("video", False):
    vs.stop()
# 否则释放内存
else:
    vs.release()

# 关闭所有的窗口
cv2.destroyAllWindows()

```

# camera-1.py

```python

import cv2
from pyzbar import pyzbar

# 二维码动态识别
camera = cv2.VideoCapture(0)
camera.set(3, 1280)  # 设置分辨率
camera.set(4, 768)
while True:
    (grabbed, frame) = camera.read()
    # 获取画面中心点
    h1, w1 = frame.shape[0], frame.shape[1]

    # 纠正畸变（这里把相机标定的代码去除了，各位自行标定吧）
    dst = frame

    # 扫描二维码
    text = pyzbar.decode(dst)
    for texts in text:
        textdate = texts.data.decode('utf-8')
        print(textdate)
        (x, y, w, h) = texts.rect  # 获取二维码的外接矩形顶点坐标
        print('识别内容:' + textdate)

        # 二维码中心坐标
        cx = int(x + w / 2)
        cy = int(y + h / 2)
        cv2.circle(dst, (cx, cy), 2, (0, 255, 0), 8)  # 做出中心坐标
        print('中间点坐标：', cx, cy)
        coordinate = (cx, cy)
        # 在画面左上角写出二维码中心位置
        cv2.putText(dst, 'QRcode_location' + str(coordinate), (20, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
        # 画出画面中心与二维码中心的连接线
        cv2.line(dst, (cx, cy), (int(w1 / 2), int(h1 / 2)), (255, 0, 0), 2)
        # cv2.rectangle(dst, (x, y), (x + w, y + h), (0, 255, 255), 2)  # 做出外接矩形
        # 二维码最小矩形
        cv2.line(dst, texts.polygon[0], texts.polygon[1], (255, 0, 0), 2)
        cv2.line(dst, texts.polygon[1], texts.polygon[2], (255, 0, 0), 2)
        cv2.line(dst, texts.polygon[2], texts.polygon[3], (255, 0, 0), 2)
        cv2.line(dst, texts.polygon[3], texts.polygon[0], (255, 0, 0), 2)
        # 写出扫描内容
        txt = '(' + texts.type + ')  ' + textdate
        cv2.putText(dst, txt, (x - 10, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 50, 255), 2)

    cv2.imshow('dst', dst)
    if cv2.waitKey(1) == 27:         # 按下 Esc退出 (27是按键ESC对应的ASCII值)
        print("退出成功")
        break
    if cv2.waitKey(1) == ord("q"):    # 按q保存一张图片
        print("保存图片")
        cv2.imwrite("./frame.jpg", frame)  # 写入图片
        break
# 释放窗口
camera.release()
cv2.destroyAllWindows()

```

# camera-2.py

```python

import cv2 as cv

cap = cv.VideoCapture(0)
while True:
    # 获取一帧又一帧
    ret, frame = cap.read()
    cv.imshow("video", frame)

    # 方法一
    if cv.waitKey(1) == 27:         # 按下 Esc退出 (27是按键ESC对应的ASCII值)
        break
    # 方法二
    if cv.waitKey(1) == ord("e"):   # 按'e' 退出，也可以设置其他键
        break

cap.release()
cv.destroyAllWindows()

```

# demo-handCovera.py&#x20;

```python
#  Python实现AI视频识别——手势控制

# https://blog.csdn.net/weixin_50679163/article/details/124391674

# Coding BIGBOSSyifi
# Datatime:2022/4/24 21:41
# Filename:HandsDetector.py
# Toolby: PyCharm

import cv2
import mediapipe as mp
import time

cap = cv2.VideoCapture(0)  # OpenCV摄像头调用：0=内置摄像头（笔记本）   1=USB摄像头-1  2=USB摄像头-2

# 定义并引用mediapipe中的hands模块
mpHands = mp.solutions.hands
hands = mpHands.Hands()
mpDraw = mp.solutions.drawing_utils

# 帧率时间计算
pTime = 0
cTime = 0

while True:
    success, img = cap.read()
    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)  # cv2图像初始化
    results = hands.process(imgRGB)
    # print(results.multi_hand_landmarks)

    if results.multi_hand_landmarks:
        for handLms in results.multi_hand_landmarks:
            for id, lm in enumerate(handLms.landmark):
                # print(id, lm)
                h, w, c = img.shape
                cx, cy = int(lm.x * w), int(lm.y * h)
                print(id, cx, cy)
                # if id == 4:
                cv2.circle(img, (cx, cy), 15, (255, 0, 255), cv2.FILLED)

            # 绘制手部特征点：
            mpDraw.draw_landmarks(img, handLms, mpHands.HAND_CONNECTIONS)
    '''''
    视频FPS计算
       '''
    cTime = time.time()
    fps = 1 / (cTime - pTime)
    pTime = cTime

    cv2.putText(img, str(int(fps)), (10, 70), cv2.FONT_HERSHEY_PLAIN, 3,
                (255, 0, 255), 3)  # FPS的字号，颜色等设置

    cv2.imshow("HandsImage", img)  # CV2窗体
    cv2.waitKey(1)  # 关闭窗体

```

# OCR

```python
from paddleocr import PaddleOCR, draw_ocr
import cv2
import numpy as np
import xlrd
from time import sleep
from threading import Thread
import queue
import Levenshtein
import datetime
from PIL import Image, ImageDraw, ImageFont
import os
import pyttsx3
import logging
logger = logging.getLogger("simple")
logger.setLevel(logging.DEBUG)
fh = logging.FileHandler("log.txt", encoding="utf-8")
fh.setLevel(logging.DEBUG)
formatter = logging.Formatter("[%(asctime)s][%(levelname)s]%(message)s", '%Y-%m-%d %H:%M:%S')
fh.setFormatter(formatter)
logger.addHandler(fh)

voice =  pyttsx3.init()
voice.setProperty("rate", 150)
def say_word(n,s):
    voice.say("题目 %s, 答案是 %s"%(n,s))
    voice.runAndWait()
os.environ['KMP_DUPLICATE_LIB_OK'] = 'True' # for fix libiomp5md.dll error

iq = queue.Queue(1)
ans = queue.Queue(1)
data = xlrd.open_workbook("data.xls")
table = data.sheets()[0]
def add_text(img, text, left, top, textColor=(255, 255, 0), textSize=30):
    img = Image.fromarray(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    # 创建一个可以在给定图像上绘图的对象
    draw = ImageDraw.Draw(img)
    # 字体的格式
    fontStyle = ImageFont.truetype(
    "font/simsun.ttc", textSize, encoding="utf-8")
    # 绘制文本
    draw.text((left, top), text, textColor, font=fontStyle)
    # 转换回OpenCV格式
    return cv2.cvtColor(np.asarray(img), cv2.COLOR_RGB2BGR)
def find_question(num, txt):
    mm = 0
    maxid = -1
    logger.info("QUESTIOIN:%d,%s",num, txt)
    for r in range(table.nrows):
        v = Levenshtein.ratio(txt, table.row_values(r)[1])
        if v > mm:
            mm = v
            maxid = r
    if maxid >= 0:
        ans.put((num, maxid,mm))
        if mm < 0.5:
            logger.info("NEW QUESTIOIN? %f, %s", mm,txt)
    return mm
def get_text(img):
    result = ocr.ocr(img, cls=True)
    res = ""
    for li in result:
        rr = li[1]
        if len(rr[0])>5 and rr[1] > 0.8:
            res += rr[0]
    l = res.find(".") #problem
    print(res)
    if len(res)<5:
        return
    if l==1 or l==2:
        num = res[:l]
        txt = res[l+1:]
    else:
        num = 0
        txt = res
    find_question(num, txt)
def work():
    while True:
        if not iq.empty():
            get_text(iq.get())
        sleep(0.5)
if __name__ == "__main__":
    logger.info("question system start.")
    cam=cv2.VideoCapture(0)
    if cam is None or not cam.isOpened():
        logger.error("camera open failed, exit.")
        exit(0)
    ocr = PaddleOCR(lang="ch")  # need to run only once to download and load model into memory
    t = Thread(target=work)
    t.setDaemon(True)
    t.start()
    SCREEN_WIDTH=800
    SCREEN_HEIGHT=600
    cam.set(cv2.CAP_PROP_FRAME_WIDTH,SCREEN_WIDTH)
    cam.set(cv2.CAP_PROP_FRAME_HEIGHT,SCREEN_HEIGHT)
    idx = 0
    say_ct = 0
    cv2.namedWindow("ans")
    cv2.moveWindow("ans", 800, 300)
    ansm = np.zeros((300,SCREEN_WIDTH, 3), np.uint8)
    last_ans = 0
    while True:
        preview = np.zeros((SCREEN_HEIGHT,SCREEN_WIDTH, 3), np.uint8)
        ret,img = cam.read()      #读取摄像头图片
        if not ret:
            continue
        idx +=1
        if idx % 10 == 0:
            iq.put(img)
        if not ans.empty():
            n,r,v = ans.get()
            logger.debug("%s,%f,%s", n, v, table.row_values(r)[1])
            if r == last_ans:
                say_ct +=1
            if r != last_ans:
                ansm = np.zeros((300,SCREEN_WIDTH, 3), np.uint8)
                last_ans = r
                say_ct = 0
                if v <0.7: # not in data
                    ansm = add_text(ansm,"注意，题库可能未找到！",50,50,textColor=(255, 0, 0))
            ansm = add_text(ansm,"匹配度：        ",200,0)
            ansm = add_text(ansm,"匹配度：%.2f"%v,200,0)
            a = str(table.row_values(r)[2])
            if say_ct > 0:
                say_word(n, a)
            ansm = add_text(ansm,"%s. %s"%(n,a),10,0)
            if a.find("A")>=0:
                ansm = add_text(ansm,str(table.row_values(r)[3]),10,100)
            if a.find("B")>=0:
                ansm = add_text(ansm,str(table.row_values(r)[4]),10,150)
            if a.find("C")>=0:
                ansm = add_text(ansm,str(table.row_values(r)[5]),10,200)
            if a.find("D")>=0:
                ansm = add_text(ansm,str(table.row_values(r)[6]),10,250)
            cv2.imshow("ans",ansm)
        temp = np.asarray(img)
        temp = temp.reshape((SCREEN_HEIGHT, SCREEN_WIDTH, 3))
        cv2.imshow("cam",img)
        if cv2.waitKey(200) == 27:
            break

```
