# 生成二维码-Python

```python
根据文字生成二维码

快捷生成二维码
通过输入任何内容，然后点击hello生成可以扫描二维码

pip install PyQt-Fluent-Widgets

pip install PyQt5

pip install "PyQt-Fluent-Widgets[full]" -i https://pypi.org/simple/
```

```python
from tkinter import *
import qrcode
from PIL import Image,ImageTk

class Appwin(Frame):
    def __init__(self,master=None):
        Frame.__init__(self,master,width=300,height=400)
        self.pack()
        self.createWidgets()

    def createWidgets(self):
        self.nameInput = Entry(self)
        self.nameInput.pack()
        self.alertButton = Button(self,text="hello",command=self.genQrcode)
        self.alertButton.pack()
        self.label = Label(self)
        self.label.pack()

    def genQrcode(self):
        text = self.nameInput.get() or "没有输入"
        self.img = qrcode.make(text)
        self.tkImage = ImageTk.PhotoImage(image=self.img)
        self.label.config(image=self.tkImage)
        self.label.image=self.tkImage

root = Appwin()
root.master.title('二维码')
root.mainloop()

```

```python
# coding:utf-8
import sys
from qfluentwidgets import InfoBar,InfoBarPosition,ComboBox, LineEdit,FluentIcon
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget
from qfluentwidgets import  PushButton



class Demo(QWidget):

    def __init__(self):
        super().__init__()
        self.setWindowTitle('二维码生成器')
        self.resize(400,400)
        #
        self.name = PushButton('填入你需要的二维码扫出文字', self)
        self.name.move(80, 10)
        self.name.resize(250, 35)
        #
        self.UsernameLineEdit = LineEdit(self)  
        self.UsernameLineEdit.move(100, 100)
        self.UsernameLineEdit.resize(200, 350)
        self.UsernameLineEdit.setClearButtonEnabled(True)
        #
        self.buttonSuccess= PushButton('生成', self)
        self.buttonSuccess.clicked.connect(self.GenerateInfoBar)
        self.buttonSuccess.move(100, 250)
        self.buttonSuccess.resize(200, 33)


    def GenerateInfoBar(self): 
        username = self.UsernameLineEdit.text()
        print(username)
        # 执行SQL语句
        InfoBar.success(
            title='生成',
            content="生成",
            orient=Qt.Horizontal,
            isClosable=True,
            position=InfoBarPosition.TOP,
            duration=2000,
            parent=self
        )





if __name__ == '__main__':
    # enable dpi scale
    QApplication.setHighDpiScaleFactorRoundingPolicy(
        Qt.HighDpiScaleFactorRoundingPolicy.PassThrough)
    QApplication.setAttribute(Qt.AA_EnableHighDpiScaling)
    QApplication.setAttribute(Qt.AA_UseHighDpiPixmaps)

    app = QApplication(sys.argv)
    w = Demo()
    w.show()
    app.exec_()
```
