# Python-office

```python
"""
【程序功能】：将 Office（Word、Excel、PPT 批量转为 PDF 文件，支持 GUI 和子文件夹等功能。
【作者】：evgo（evgo2017.com）
【生成的 pdf 名称】：原始名称+.pdf
"""
import os
import win32com.client
import gc
import tkinter as tk
from tkinter import filedialog, StringVar, IntVar, ttk
import queue
import time
import sys
import threading
import pythoncom

pythoncom.CoInitialize()

window = tk.Tk()
logQueue = queue.Queue()

fromRootFolderPathVar = tk.StringVar()
toRootFolderPathVar = tk.StringVar()
isCovertChildrenFolderVar = tk.IntVar()
isKeepFolderStructureVar = tk.IntVar()
isCovertWordVar = tk.IntVar()
isCovertPPTVar = tk.IntVar()
isCovertExcelVar = tk.IntVar()
isCovertAllTypeVar = tk.IntVar()

# 赋默认值
fromRootFolderPathVar.set(os.getcwd())
toRootFolderPathVar.set(os.getcwd())
isCovertWordVar.set(1)
isKeepFolderStructureVar.set(1)
isCovertPPTVar.set(1)
isCovertExcelVar.set(1)
isCovertAllTypeVar.set(1)
isCovertChildrenFolderVar.set(1)


def setAllTypeCheckVar():
    isCovertAllTypeVar.set(isCovertWordVar.get() + isCovertPPTVar.get() + isCovertExcelVar.get() == 3)


def formatPath(path):
    return os.path.normpath(path)


def insertLog(log):
    logQueue.put(log)


def startConvert():
    T = threading.Thread(target=convert, args=(fromRootFolderPathVar.get(), toRootFolderPathVar.get()))
    T.daemon = True
    T.start()


def changeSufix2Pdf(file):
    return file[:file.rfind('.')] + ".pdf"


def addWorksheetsOrder(file, i):
    return file[:file.rfind('.')] + "_" + str(i) + file[file.rfind('.'):]


# Word
def word2Pdf(fromRootFolderPath, toRootFolderPath, words):
    # 如果没有文件则提示后直接退出
    if (len(words) < 1):
        insertLog("\n【无 Word 文件】\n")
        return
    # 开始转换
    insertLog("\n【 Word -> PDF 转换】")
    fromRootFolderPath = formatPath(fromRootFolderPath)
    toRootFolderPath = formatPath(toRootFolderPath)
    try:
        insertLog("\n打开 Word 进程中...")
        word = win32com.client.Dispatch("Word.Application")
        word.Visible = 0
        word.DisplayAlerts = False
        doc = None
        for i in range(len(words)):
            insertLog("\n" + str(i))
            fromFilePath = formatPath(words[i])
            fromFileName = os.path.basename(fromFilePath)
            insertLog("原始文件：" + fromFilePath)
            if (isKeepFolderStructureVar.get() == 1):
                subPath = fromFilePath[len(fromRootFolderPath) + 1: len(fromFilePath) - len(fromFileName)]
            else:
                subPath = ""
            toSubFolderPath = os.path.join(toRootFolderPath, subPath)
            # 子文件夹创建
            if not os.path.exists(toSubFolderPath):
                os.makedirs(toSubFolderPath)
            toFileName = changeSufix2Pdf(fromFileName)
            toFilePath = os.path.join(toSubFolderPath, toFileName)
            # 某文件出错不影响其他文件打印
            try:
                doc = word.Documents.Open(fromFilePath)
                doc.SaveAs(toFilePath, 17)  # 生成的所有 PDF 都会在 PDF 文件夹中
                insertLog("生成文件：" + toFilePath)
            except Exception as e:
                insertLog(str(e))
            # 关闭 Word 进程
        insertLog("\n所有 Word 文件已转换完毕\n")
        insertLog("结束 Word 进程中...")
        doc.Close()
        doc = None
        word.Quit()
        word = None
        insertLog("已结束 Word 进程\n")
    except Exception as e:
        insertLog(str(e))
    finally:
        gc.collect()


# Excel
def excel2Pdf(fromRootFolderPath, toRootFolderPath, excels):
    # 如果没有文件则提示后直接退出
    if (len(excels) < 1):
        insertLog("\n【无 Excel 文件】\n")
        return
    # 开始转换
    insertLog("\n【 Excel -> PDF 转换】")
    fromRootFolderPath = formatPath(fromRootFolderPath)
    toRootFolderPath = formatPath(toRootFolderPath)
    try:
        insertLog("\n打开 Excel 进程中...")
        excel = win32com.client.Dispatch("Excel.Application")
        excel.Visible = 0
        excel.DisplayAlerts = False
        wb = None
        ws = None
        for i in range(len(excels)):
            insertLog("\n" + str(i))
            fromFilePath = formatPath(excels[i])
            fromFileName = os.path.basename(fromFilePath)
            insertLog("原始文件：" + fromFilePath)
            if (isKeepFolderStructureVar.get() == 1):
                subPath = fromFilePath[len(fromRootFolderPath) + 1: len(fromFilePath) - len(fromFileName)]
            else:
                subPath = ""
            toSubFolderPath = os.path.join(toRootFolderPath, subPath)
            # 子文件夹创建
            if not os.path.exists(toSubFolderPath):
                os.makedirs(toSubFolderPath)
            # 某文件出错不影响其他文件打印
            try:
                wb = excel.Workbooks.Open(fromFilePath)
                count = wb.Worksheets.Count
                insertLog("此 Excel 一共有" + str(count) + "张表：")
                for j in range(count):  # 工作表数量，一个工作簿可能有多张工作表
                    insertLog("\n转换第" + str(j + 1) + "张表中...")
                    if (count == 1):
                        toFileName = changeSufix2Pdf(fromFileName)  # 生成的文件名称
                    else:
                        toFileName = changeSufix2Pdf(addWorksheetsOrder(fromFileName, j + 1))  # 仅多张表时加序号
                    toFilePath = os.path.join(toSubFolderPath, toFileName)  # 生成的文件地址
                    insertLog("生成文件：" + toFilePath)
                    ws = wb.Worksheets(j + 1)  # 若为[0]则打包后会提示越界
                    ws.ExportAsFixedFormat(0, toFilePath)  # 每一张都需要打印
            except Exception as e:
                insertLog(str(e))
        # 关闭 Excel 进程
        insertLog("\n所有 Excel 文件已转换完毕\n")
        insertLog("结束 Excel 进程中...")
        ws = None
        wb.Close()
        wb = None
        excel.Quit()
        excel = None
        insertLog("已结束 Excel 进程\n")
    except Exception as e:
        insertLog(str(e))
    finally:
        gc.collect()


# PPT
def ppt2Pdf(fromRootFolderPath, toRootFolderPath, ppts):
    # 如果没有文件则提示后直接退出
    if (len(ppts) < 1):
        insertLog("\n【无 PPT 文件】\n")
        return
    # 开始转换
    insertLog("\n【 PPT -> PDF 转换】")
    fromRootFolderPath = formatPath(fromRootFolderPath)
    toRootFolderPath = formatPath(toRootFolderPath)
    try:
        insertLog("\n打开 PowerPoint 进程中...")
        powerpoint = win32com.client.Dispatch("PowerPoint.Application")
        ppt = None
        # 某文件出错不影响其他文件打印

        for i in range(len(ppts)):
            insertLog("\n" + str(i))
            fromFilePath = formatPath(ppts[i])
            fromFileName = os.path.basename(fromFilePath)
            insertLog("原始文件：" + fromFilePath)
            if (isKeepFolderStructureVar.get() == 1):
                subPath = fromFilePath[len(fromRootFolderPath) + 1: len(fromFilePath) - len(fromFileName)]
            else:
                subPath = ""
            toSubFolderPath = os.path.join(toRootFolderPath, subPath)
            # 子文件夹创建
            if not os.path.exists(toSubFolderPath):
                os.makedirs(toSubFolderPath)
            toFileName = changeSufix2Pdf(fromFileName)
            toFilePath = os.path.join(toSubFolderPath, toFileName)  # 生成的文件地址
            try:
                ppt = powerpoint.Presentations.Open(fromFilePath, WithWindow=False)
                if ppt.Slides.Count > 0:
                    ppt.SaveAs(toFilePath, 32)  # 如果为空则会跳出提示框（暂时没有找到消除办法）
                    insertLog("生成文件：" + toFilePath)
                else:
                    insertLog("生成文件：（错误，发生意外：此文件为空，跳过此文件）")
            except Exception as e:
                insertLog(str(e))
        # 关闭 PPT 进程
        insertLog("\n所有 PPT 文件已转换完毕\n")
        insertLog("结束 PowerPoint 进程中...")
        insertLog("若耗时较久（超过30秒），建议再前往任务管理器手动关闭该进程。")
        ppt.Close()
        ppt = None
        powerpoint.Quit()
        powerpoint = None
        insertLog("已结束 PowerPoint 进程\n")
    except Exception as e:
        insertLog(str(e))
    finally:
        gc.collect()


# 核心转换
def convert(fromRootFolderPath, toRootFolderPath):
    # TODO：是否遍历子目录
    # 将目标文件夹所有文件归类，转换时只打开一个进程
    words = []
    ppts = []
    excels = []

    for folderPath, dirs, fileNames in os.walk(fromRootFolderPath):
        for fileName in fileNames:
            fromFilePath = formatPath(os.path.join(folderPath, fileName))
            if fileName.endswith(('.doc', 'docx')):
                words.append(fromFilePath)
            elif fileName.endswith(('.ppt', 'pptx')):
                ppts.append(fromFilePath)
            elif fileName.endswith(('.xls', 'xlsx')):
                excels.append(fromFilePath)
        if isCovertChildrenFolderVar.get() == 0:
            break

    insertLog("\n====================开始转换====================")

    if (isCovertWordVar.get() == 1):
        word2Pdf(fromRootFolderPath, toRootFolderPath, words)
    if (isCovertExcelVar.get() == 1):
        excel2Pdf(fromRootFolderPath, toRootFolderPath, excels)
    if (isCovertPPTVar.get() == 1):
        ppt2Pdf(fromRootFolderPath, toRootFolderPath, ppts)

    insertLog("====================转换结束====================")


class GUI():
    def __init__(self, window, windowHeight=530, windowWidth=520):
        self.window = window
        self.windowHeight = windowHeight
        self.windowWidth = windowWidth

        # 数据有交互的变量
        self.logListText = None
        self.fromFolderEntry = None
        self.toFolderEntry = None

        self.initGui()

        # 启动 after 方法
        self.window.after(100, self.showLog)
        # 进入消息循环
        self.window.mainloop()

    def initGui(self):
        # window
        self.window.title("Office2PDF")

        windowWidth = self.windowWidth
        windowHeight = self.windowHeight
        screenwidth = self.window.winfo_screenwidth()
        screenheight = self.window.winfo_screenheight()

        window.geometry('%dx%d+%d+%d' % (
        windowWidth, windowHeight, (screenwidth - windowWidth) / 2, (screenheight - windowHeight) / 2))

        frame = tk.Frame(window)
        frame.pack(fill=tk.BOTH, expand=tk.YES, padx=10, pady=10)

        # frame
        infoLabelFrame = ttk.LabelFrame(frame, text="基本信息")
        folerLabelFrame = ttk.LabelFrame(frame, text="文件夹")
        configFrame = tk.Frame(frame)
        startFrame = tk.Frame(frame)
        logListFrame = tk.Frame(frame)

        infoLabelFrame.pack(fill=tk.X, expand=tk.YES, pady=4)
        folerLabelFrame.pack(fill=tk.X, expand=tk.YES, pady=4, ipady=4)
        configFrame.pack(fill=tk.X)
        startFrame.pack(fill=tk.X, expand=tk.YES, pady=4)
        logListFrame.pack(fill=tk.BOTH, expand=tk.YES, pady=4)

        # infoLableFrame
        fnFrame = tk.Frame(infoLabelFrame)
        authorFrame = tk.Frame(infoLabelFrame)

        fnFrame.pack(fill=tk.X, expand=tk.YES, padx=2)
        authorFrame.pack(fill=tk.X, expand=tk.YES, padx=2)

        # fnFrame
        tk.Label(fnFrame, text="将文件夹内的 Word、Excel 或 PPT 生成对应的 PDF 文件。").grid(sticky=tk.W)
        tk.Label(fnFrame, text="需已安装 Office 2007 及以上，或 Microsoft Save as PDF 加载项。").grid(sticky=tk.W)

        # authorFrame
        # TODO：复制功能
        authorLabel = tk.Label(authorFrame, text="作者：evgo（evgo2017.com）")

        authorLabel.pack(side=tk.RIGHT)

        # folderLableFrame
        fromFolderFrame = tk.Frame(folerLabelFrame)
        toFolderFrame = tk.Frame(folerLabelFrame)

        fromFolderFrame.pack(fill=tk.X, padx=3)
        toFolderFrame.pack(fill=tk.X, padx=3)

        # fromFolderFrame
        fromFolderLabel = tk.Label(fromFolderFrame, text="来源")
        fromFolderEntry = ttk.Entry(fromFolderFrame, textvariable=fromRootFolderPathVar)
        self.fromFolderEntry = fromFolderEntry
        fromFolderButton = ttk.Button(fromFolderFrame, text="选择", command=self.setFromFolderPath)

        fromFolderLabel.pack(side=tk.LEFT)
        fromFolderEntry.pack(side=tk.LEFT, fill=tk.X, expand=tk.YES, padx=6)
        fromFolderButton.pack(side=tk.LEFT)

        # toFolderFrame
        toFolderLabel = tk.Label(toFolderFrame, text="目标")
        toFolderEntry = ttk.Entry(toFolderFrame, textvariable=toRootFolderPathVar)
        self.toFolderEntry = toFolderEntry
        toFolderButton = ttk.Button(toFolderFrame, text="选择", command=self.setToFolderPath)

        toFolderLabel.pack(side=tk.LEFT)
        toFolderEntry.pack(side=tk.LEFT, fill=tk.X, expand=tk.YES, padx=6)
        toFolderButton.pack(side=tk.LEFT)

        # configFrame
        convertTypeLabelFrame = tk.LabelFrame(configFrame, text="转换类型")
        convertChildrenFolderLabelFrame = tk.LabelFrame(configFrame, text="子文件夹")
        convertTypeLabelFrame.pack(side=tk.LEFT, padx=1)
        convertChildrenFolderLabelFrame.pack(side=tk.LEFT)

        wordCheckbutton = tk.Checkbutton(convertTypeLabelFrame, text='Word', variable=isCovertWordVar,
                                         command=setAllTypeCheckVar)
        pptCheckbutton = tk.Checkbutton(convertTypeLabelFrame, text='PPT', variable=isCovertPPTVar,
                                        command=setAllTypeCheckVar)
        excelCheckbutton = tk.Checkbutton(convertTypeLabelFrame, text='Excel', variable=isCovertExcelVar,
                                          command=setAllTypeCheckVar)
        allTypeCheckbutton = tk.Checkbutton(convertTypeLabelFrame, text="全选/全不选", variable=isCovertAllTypeVar,
                                            command=self.toggleConvertAllType)

        yesConvertChildrenFolderRadiobutton = tk.Radiobutton(convertChildrenFolderLabelFrame, text="转换",
                                                             variable=isCovertChildrenFolderVar, value=1)
        noConvertChildrenFolderRadiobutton = tk.Radiobutton(convertChildrenFolderLabelFrame, text="不转换",
                                                            variable=isCovertChildrenFolderVar, value=0)
        yesKeepFolderStructureRadiobutton = tk.Radiobutton(convertChildrenFolderLabelFrame, text="结构",
                                                           variable=isKeepFolderStructureVar, value=1)
        noKeepFolderStructureRadiobutton = tk.Radiobutton(convertChildrenFolderLabelFrame, text="平铺",
                                                          variable=isKeepFolderStructureVar, value=0)

        wordCheckbutton.pack(side=tk.LEFT)
        pptCheckbutton.pack(side=tk.LEFT)
        excelCheckbutton.pack(side=tk.LEFT)
        allTypeCheckbutton.pack(side=tk.LEFT)
        yesConvertChildrenFolderRadiobutton.pack(side=tk.LEFT)
        noConvertChildrenFolderRadiobutton.pack(side=tk.LEFT)
        ttk.Separator(convertChildrenFolderLabelFrame, orient=tk.VERTICAL).pack(side=tk.LEFT, fill=tk.Y, padx=4, pady=4)
        yesKeepFolderStructureRadiobutton.pack(side=tk.LEFT)
        noKeepFolderStructureRadiobutton.pack(side=tk.LEFT)

        # startFrame
        startButton = ttk.Button(startFrame, text='开始', command=startConvert)
        startButton.pack(side=tk.LEFT, fill=tk.X, expand=tk.YES, ipady=1.5)

        # logListFrame
        scrollBar = tk.Scrollbar(logListFrame)
        logListText = tk.Text(logListFrame, height=100, yscrollcommand=scrollBar.set)
        self.logListText = logListText
        scrollBar.config(command=logListText.yview)

        scrollBar.pack(side=tk.RIGHT, fill=tk.Y)
        logListText.pack(side=tk.LEFT, fill=tk.BOTH, expand=tk.YES)

    def showLog(self):
        while not logQueue.empty():
            content = logQueue.get()
            self.logListText.insert(tk.END, content + "\n")
            self.logListText.yview_moveto(1)
        self.window.after(100, self.showLog)

    def chooseFolderPath(self):
        return tk.filedialog.askdirectory(initialdir=os.getcwd(), title="Select file")

    def setFromFolderPath(self):
        folderPath = self.chooseFolderPath()
        if len(folderPath) > 0:
            self.fromFolderEntry.delete(0, tk.END)
            self.fromFolderEntry.insert(0, formatPath(folderPath))

    def setToFolderPath(self):
        folderPath = self.chooseFolderPath()
        if len(folderPath) > 0:
            self.toFolderEntry.delete(0, tk.END)
            self.toFolderEntry.insert(0, formatPath(folderPath))

    def toggleConvertAllType(self):
        flag = isCovertAllTypeVar.get() == 1
        isCovertWordVar.set(flag)
        isCovertPPTVar.set(flag)
        isCovertExcelVar.set(flag)


if __name__ == "__main__":
    insertLog("注意事项：")
    insertLog("1）若文件为空，PPT 报错跳过转换，Excel 对应 PDF 不能正确打开。")
    insertLog("2）若转换 PPT 时间过长，请查看是否有弹出窗口等待确认。")
    insertLog("3）在关闭 PPT 进程时，常等待20秒左右，建议先等待，若超过30秒，再前往任务管理器手动关闭该进程。")

    GUI(window)
```

# PDFconvertPNG.py

```python
# 导入这个库：Python-office，简写为office
import office

# 一行代码，实现转换
office.pdf.pdf2imgs(
    pdf_path='E://GitHub//Python//Python-office//模拟电子技术10合一.pdf',
    out_dir='./输出文件夹'
)
# 参数说明：
# pdf_path = 你的PDF文件的地址
# out_dir = 转换后的图片存放地址，可以不填，默认是PDF的地址

```

# PythonAutowrite.py

```python
# 导入库：Python-office，简写为：office
import office
# pip install -i https://pypi.tuna.tsinghua.edu.cn/simple Python-office -U
# 1行代码实现，指定你的主题（theme）和行数（line_pip install pip -Unum）

print(office.excel.create_article(theme = '李白', line_num = 300))
# 你需要指定的内容：
# theme：你的作文主题
# line_num：你的作文行数

```

# word2PDF

```python

"""
【程序功能】：将 Office（Word、Excel、PPT 批量转为 PDF 文件，支持 GUI 和子文件夹等功能。
【作者】：evgo（evgo2017.com）
【生成的 pdf 名称】：原始名称+.pdf
"""
import os
import win32com.client
import gc
import tkinter as tk
from tkinter import filedialog, StringVar, IntVar, ttk
import queue
import time
import sys
import threading
import pythoncom

pythoncom.CoInitialize()

window = tk.Tk()
logQueue = queue.Queue()

fromRootFolderPathVar = tk.StringVar()
toRootFolderPathVar = tk.StringVar()
isCovertChildrenFolderVar = tk.IntVar()
isKeepFolderStructureVar = tk.IntVar()
isCovertWordVar = tk.IntVar()
isCovertPPTVar = tk.IntVar()
isCovertExcelVar = tk.IntVar()
isCovertAllTypeVar = tk.IntVar()

# 赋默认值
fromRootFolderPathVar.set(os.getcwd())
toRootFolderPathVar.set(os.getcwd())
isCovertWordVar.set(1)
isKeepFolderStructureVar.set(1)
isCovertPPTVar.set(1)
isCovertExcelVar.set(1)
isCovertAllTypeVar.set(1)
isCovertChildrenFolderVar.set(1)


def setAllTypeCheckVar():
    isCovertAllTypeVar.set(isCovertWordVar.get() + isCovertPPTVar.get() + isCovertExcelVar.get() == 3)


def formatPath(path):
    return os.path.normpath(path)


def insertLog(log):
    logQueue.put(log)


def startConvert():
    T = threading.Thread(target=convert, args=(fromRootFolderPathVar.get(), toRootFolderPathVar.get()))
    T.daemon = True
    T.start()


def changeSufix2Pdf(file):
    return file[:file.rfind('.')] + ".pdf"


def addWorksheetsOrder(file, i):
    return file[:file.rfind('.')] + "_" + str(i) + file[file.rfind('.'):]


# Word
def word2Pdf(fromRootFolderPath, toRootFolderPath, words):
    # 如果没有文件则提示后直接退出
    if (len(words) < 1):
        insertLog("\n【无 Word 文件】\n")
        return
    # 开始转换
    insertLog("\n【 Word -> PDF 转换】")
    fromRootFolderPath = formatPath(fromRootFolderPath)
    toRootFolderPath = formatPath(toRootFolderPath)
    try:
        insertLog("\n打开 Word 进程中...")
        word = win32com.client.Dispatch("Word.Application")
        word.Visible = 0
        word.DisplayAlerts = False
        doc = None
        for i in range(len(words)):
            insertLog("\n" + str(i))
            fromFilePath = formatPath(words[i])
            fromFileName = os.path.basename(fromFilePath)
            insertLog("原始文件：" + fromFilePath)
            if (isKeepFolderStructureVar.get() == 1):
                subPath = fromFilePath[len(fromRootFolderPath) + 1: len(fromFilePath) - len(fromFileName)]
            else:
                subPath = ""
            toSubFolderPath = os.path.join(toRootFolderPath, subPath)
            # 子文件夹创建
            if not os.path.exists(toSubFolderPath):
                os.makedirs(toSubFolderPath)
            toFileName = changeSufix2Pdf(fromFileName)
            toFilePath = os.path.join(toSubFolderPath, toFileName)
            # 某文件出错不影响其他文件打印
            try:
                doc = word.Documents.Open(fromFilePath)
                doc.SaveAs(toFilePath, 17)  # 生成的所有 PDF 都会在 PDF 文件夹中
                insertLog("生成文件：" + toFilePath)
            except Exception as e:
                insertLog(str(e))
            # 关闭 Word 进程
        insertLog("\n所有 Word 文件已转换完毕\n")
        insertLog("结束 Word 进程中...")
        doc.Close()
        doc = None
        word.Quit()
        word = None
        insertLog("已结束 Word 进程\n")
    except Exception as e:
        insertLog(str(e))
    finally:
        gc.collect()


# Excel
def excel2Pdf(fromRootFolderPath, toRootFolderPath, excels):
    # 如果没有文件则提示后直接退出
    if (len(excels) < 1):
        insertLog("\n【无 Excel 文件】\n")
        return
    # 开始转换
    insertLog("\n【 Excel -> PDF 转换】")
    fromRootFolderPath = formatPath(fromRootFolderPath)
    toRootFolderPath = formatPath(toRootFolderPath)
    try:
        insertLog("\n打开 Excel 进程中...")
        excel = win32com.client.Dispatch("Excel.Application")
        excel.Visible = 0
        excel.DisplayAlerts = False
        wb = None
        ws = None
        for i in range(len(excels)):
            insertLog("\n" + str(i))
            fromFilePath = formatPath(excels[i])
            fromFileName = os.path.basename(fromFilePath)
            insertLog("原始文件：" + fromFilePath)
            if (isKeepFolderStructureVar.get() == 1):
                subPath = fromFilePath[len(fromRootFolderPath) + 1: len(fromFilePath) - len(fromFileName)]
            else:
                subPath = ""
            toSubFolderPath = os.path.join(toRootFolderPath, subPath)
            # 子文件夹创建
            if not os.path.exists(toSubFolderPath):
                os.makedirs(toSubFolderPath)
            # 某文件出错不影响其他文件打印
            try:
                wb = excel.Workbooks.Open(fromFilePath)
                count = wb.Worksheets.Count
                insertLog("此 Excel 一共有" + str(count) + "张表：")
                for j in range(count):  # 工作表数量，一个工作簿可能有多张工作表
                    insertLog("\n转换第" + str(j + 1) + "张表中...")
                    if (count == 1):
                        toFileName = changeSufix2Pdf(fromFileName)  # 生成的文件名称
                    else:
                        toFileName = changeSufix2Pdf(addWorksheetsOrder(fromFileName, j + 1))  # 仅多张表时加序号
                    toFilePath = os.path.join(toSubFolderPath, toFileName)  # 生成的文件地址
                    insertLog("生成文件：" + toFilePath)
                    ws = wb.Worksheets(j + 1)  # 若为[0]则打包后会提示越界
                    ws.ExportAsFixedFormat(0, toFilePath)  # 每一张都需要打印
            except Exception as e:
                insertLog(str(e))
        # 关闭 Excel 进程
        insertLog("\n所有 Excel 文件已转换完毕\n")
        insertLog("结束 Excel 进程中...")
        ws = None
        wb.Close()
        wb = None
        excel.Quit()
        excel = None
        insertLog("已结束 Excel 进程\n")
    except Exception as e:
        insertLog(str(e))
    finally:
        gc.collect()


# PPT
def ppt2Pdf(fromRootFolderPath, toRootFolderPath, ppts):
    # 如果没有文件则提示后直接退出
    if (len(ppts) < 1):
        insertLog("\n【无 PPT 文件】\n")
        return
    # 开始转换
    insertLog("\n【 PPT -> PDF 转换】")
    fromRootFolderPath = formatPath(fromRootFolderPath)
    toRootFolderPath = formatPath(toRootFolderPath)
    try:
        insertLog("\n打开 PowerPoint 进程中...")
        powerpoint = win32com.client.Dispatch("PowerPoint.Application")
        ppt = None
        # 某文件出错不影响其他文件打印

        for i in range(len(ppts)):
            insertLog("\n" + str(i))
            fromFilePath = formatPath(ppts[i])
            fromFileName = os.path.basename(fromFilePath)
            insertLog("原始文件：" + fromFilePath)
            if (isKeepFolderStructureVar.get() == 1):
                subPath = fromFilePath[len(fromRootFolderPath) + 1: len(fromFilePath) - len(fromFileName)]
            else:
                subPath = ""
            toSubFolderPath = os.path.join(toRootFolderPath, subPath)
            # 子文件夹创建
            if not os.path.exists(toSubFolderPath):
                os.makedirs(toSubFolderPath)
            toFileName = changeSufix2Pdf(fromFileName)
            toFilePath = os.path.join(toSubFolderPath, toFileName)  # 生成的文件地址
            try:
                ppt = powerpoint.Presentations.Open(fromFilePath, WithWindow=False)
                if ppt.Slides.Count > 0:
                    ppt.SaveAs(toFilePath, 32)  # 如果为空则会跳出提示框（暂时没有找到消除办法）
                    insertLog("生成文件：" + toFilePath)
                else:
                    insertLog("生成文件：（错误，发生意外：此文件为空，跳过此文件）")
            except Exception as e:
                insertLog(str(e))
        # 关闭 PPT 进程
        insertLog("\n所有 PPT 文件已转换完毕\n")
        insertLog("结束 PowerPoint 进程中...")
        insertLog("若耗时较久（超过30秒），建议再前往任务管理器手动关闭该进程。")
        ppt.Close()
        ppt = None
        powerpoint.Quit()
        powerpoint = None
        insertLog("已结束 PowerPoint 进程\n")
    except Exception as e:
        insertLog(str(e))
    finally:
        gc.collect()


# 核心转换
def convert(fromRootFolderPath, toRootFolderPath):
    # TODO：是否遍历子目录
    # 将目标文件夹所有文件归类，转换时只打开一个进程
    words = []
    ppts = []
    excels = []

    for folderPath, dirs, fileNames in os.walk(fromRootFolderPath):
        for fileName in fileNames:
            fromFilePath = formatPath(os.path.join(folderPath, fileName))
            if fileName.endswith(('.doc', 'docx')):
                words.append(fromFilePath)
            elif fileName.endswith(('.ppt', 'pptx')):
                ppts.append(fromFilePath)
            elif fileName.endswith(('.xls', 'xlsx')):
                excels.append(fromFilePath)
        if isCovertChildrenFolderVar.get() == 0:
            break

    insertLog("\n====================开始转换====================")

    if (isCovertWordVar.get() == 1):
        word2Pdf(fromRootFolderPath, toRootFolderPath, words)
    if (isCovertExcelVar.get() == 1):
        excel2Pdf(fromRootFolderPath, toRootFolderPath, excels)
    if (isCovertPPTVar.get() == 1):
        ppt2Pdf(fromRootFolderPath, toRootFolderPath, ppts)

    insertLog("====================转换结束====================")


class GUI():
    def __init__(self, window, windowHeight=530, windowWidth=520):
        self.window = window
        self.windowHeight = windowHeight
        self.windowWidth = windowWidth

        # 数据有交互的变量
        self.logListText = None
        self.fromFolderEntry = None
        self.toFolderEntry = None

        self.initGui()

        # 启动 after 方法
        self.window.after(100, self.showLog)
        # 进入消息循环
        self.window.mainloop()

    def initGui(self):
        # window
        self.window.title("Office2PDF")

        windowWidth = self.windowWidth
        windowHeight = self.windowHeight
        screenwidth = self.window.winfo_screenwidth()
        screenheight = self.window.winfo_screenheight()

        window.geometry('%dx%d+%d+%d' % (
        windowWidth, windowHeight, (screenwidth - windowWidth) / 2, (screenheight - windowHeight) / 2))

        frame = tk.Frame(window)
        frame.pack(fill=tk.BOTH, expand=tk.YES, padx=10, pady=10)

        # frame
        infoLabelFrame = ttk.LabelFrame(frame, text="基本信息")
        folerLabelFrame = ttk.LabelFrame(frame, text="文件夹")
        configFrame = tk.Frame(frame)
        startFrame = tk.Frame(frame)
        logListFrame = tk.Frame(frame)

        infoLabelFrame.pack(fill=tk.X, expand=tk.YES, pady=4)
        folerLabelFrame.pack(fill=tk.X, expand=tk.YES, pady=4, ipady=4)
        configFrame.pack(fill=tk.X)
        startFrame.pack(fill=tk.X, expand=tk.YES, pady=4)
        logListFrame.pack(fill=tk.BOTH, expand=tk.YES, pady=4)

        # infoLableFrame
        fnFrame = tk.Frame(infoLabelFrame)
        authorFrame = tk.Frame(infoLabelFrame)

        fnFrame.pack(fill=tk.X, expand=tk.YES, padx=2)
        authorFrame.pack(fill=tk.X, expand=tk.YES, padx=2)

        # fnFrame
        tk.Label(fnFrame, text="将文件夹内的 Word、Excel 或 PPT 生成对应的 PDF 文件。").grid(sticky=tk.W)
        tk.Label(fnFrame, text="需已安装 Office 2007 及以上，或 Microsoft Save as PDF 加载项。").grid(sticky=tk.W)

        # authorFrame
        # TODO：复制功能
        authorLabel = tk.Label(authorFrame, text="作者：evgo（evgo2017.com）")

        authorLabel.pack(side=tk.RIGHT)

        # folderLableFrame
        fromFolderFrame = tk.Frame(folerLabelFrame)
        toFolderFrame = tk.Frame(folerLabelFrame)

        fromFolderFrame.pack(fill=tk.X, padx=3)
        toFolderFrame.pack(fill=tk.X, padx=3)

        # fromFolderFrame
        fromFolderLabel = tk.Label(fromFolderFrame, text="来源")
        fromFolderEntry = ttk.Entry(fromFolderFrame, textvariable=fromRootFolderPathVar)
        self.fromFolderEntry = fromFolderEntry
        fromFolderButton = ttk.Button(fromFolderFrame, text="选择", command=self.setFromFolderPath)

        fromFolderLabel.pack(side=tk.LEFT)
        fromFolderEntry.pack(side=tk.LEFT, fill=tk.X, expand=tk.YES, padx=6)
        fromFolderButton.pack(side=tk.LEFT)

        # toFolderFrame
        toFolderLabel = tk.Label(toFolderFrame, text="目标")
        toFolderEntry = ttk.Entry(toFolderFrame, textvariable=toRootFolderPathVar)
        self.toFolderEntry = toFolderEntry
        toFolderButton = ttk.Button(toFolderFrame, text="选择", command=self.setToFolderPath)

        toFolderLabel.pack(side=tk.LEFT)
        toFolderEntry.pack(side=tk.LEFT, fill=tk.X, expand=tk.YES, padx=6)
        toFolderButton.pack(side=tk.LEFT)

        # configFrame
        convertTypeLabelFrame = tk.LabelFrame(configFrame, text="转换类型")
        convertChildrenFolderLabelFrame = tk.LabelFrame(configFrame, text="子文件夹")
        convertTypeLabelFrame.pack(side=tk.LEFT, padx=1)
        convertChildrenFolderLabelFrame.pack(side=tk.LEFT)

        wordCheckbutton = tk.Checkbutton(convertTypeLabelFrame, text='Word', variable=isCovertWordVar,
                                         command=setAllTypeCheckVar)
        pptCheckbutton = tk.Checkbutton(convertTypeLabelFrame, text='PPT', variable=isCovertPPTVar,
                                        command=setAllTypeCheckVar)
        excelCheckbutton = tk.Checkbutton(convertTypeLabelFrame, text='Excel', variable=isCovertExcelVar,
                                          command=setAllTypeCheckVar)
        allTypeCheckbutton = tk.Checkbutton(convertTypeLabelFrame, text="全选/全不选", variable=isCovertAllTypeVar,
                                            command=self.toggleConvertAllType)

        yesConvertChildrenFolderRadiobutton = tk.Radiobutton(convertChildrenFolderLabelFrame, text="转换",
                                                             variable=isCovertChildrenFolderVar, value=1)
        noConvertChildrenFolderRadiobutton = tk.Radiobutton(convertChildrenFolderLabelFrame, text="不转换",
                                                            variable=isCovertChildrenFolderVar, value=0)
        yesKeepFolderStructureRadiobutton = tk.Radiobutton(convertChildrenFolderLabelFrame, text="结构",
                                                           variable=isKeepFolderStructureVar, value=1)
        noKeepFolderStructureRadiobutton = tk.Radiobutton(convertChildrenFolderLabelFrame, text="平铺",
                                                          variable=isKeepFolderStructureVar, value=0)

        wordCheckbutton.pack(side=tk.LEFT)
        pptCheckbutton.pack(side=tk.LEFT)
        excelCheckbutton.pack(side=tk.LEFT)
        allTypeCheckbutton.pack(side=tk.LEFT)
        yesConvertChildrenFolderRadiobutton.pack(side=tk.LEFT)
        noConvertChildrenFolderRadiobutton.pack(side=tk.LEFT)
        ttk.Separator(convertChildrenFolderLabelFrame, orient=tk.VERTICAL).pack(side=tk.LEFT, fill=tk.Y, padx=4, pady=4)
        yesKeepFolderStructureRadiobutton.pack(side=tk.LEFT)
        noKeepFolderStructureRadiobutton.pack(side=tk.LEFT)

        # startFrame
        startButton = ttk.Button(startFrame, text='开始', command=startConvert)
        startButton.pack(side=tk.LEFT, fill=tk.X, expand=tk.YES, ipady=1.5)

        # logListFrame
        scrollBar = tk.Scrollbar(logListFrame)
        logListText = tk.Text(logListFrame, height=100, yscrollcommand=scrollBar.set)
        self.logListText = logListText
        scrollBar.config(command=logListText.yview)

        scrollBar.pack(side=tk.RIGHT, fill=tk.Y)
        logListText.pack(side=tk.LEFT, fill=tk.BOTH, expand=tk.YES)

    def showLog(self):
        while not logQueue.empty():
            content = logQueue.get()
            self.logListText.insert(tk.END, content + "\n")
            self.logListText.yview_moveto(1)
        self.window.after(100, self.showLog)

    def chooseFolderPath(self):
        return tk.filedialog.askdirectory(initialdir=os.getcwd(), title="Select file")

    def setFromFolderPath(self):
        folderPath = self.chooseFolderPath()
        if len(folderPath) > 0:
            self.fromFolderEntry.delete(0, tk.END)
            self.fromFolderEntry.insert(0, formatPath(folderPath))

    def setToFolderPath(self):
        folderPath = self.chooseFolderPath()
        if len(folderPath) > 0:
            self.toFolderEntry.delete(0, tk.END)
            self.toFolderEntry.insert(0, formatPath(folderPath))

    def toggleConvertAllType(self):
        flag = isCovertAllTypeVar.get() == 1
        isCovertWordVar.set(flag)
        isCovertPPTVar.set(flag)
        isCovertExcelVar.set(flag)


if __name__ == "__main__":
    insertLog("注意事项：")
    insertLog("1）若文件为空，PPT 报错跳过转换，Excel 对应 PDF 不能正确打开。")
    insertLog("2）若转换 PPT 时间过长，请查看是否有弹出窗口等待确认。")
    insertLog("3）在关闭 PPT 进程时，常等待20秒左右，建议先等待，若超过30秒，再前往任务管理器手动关闭该进程。")

    GUI(window)

```

# xlsx

```python
import openpyxl

# 读取 xlsx 文件
workbook = openpyxl.load_workbook('medicine_data.xlsx')
sheet = workbook.active

# 读取需要排序的列，例如第二列到第五列
data = []
for row in sheet.iter_rows(min_row=2, values_only=True):
    data.append(row[0:5])

# 对数据按照第四列进行降序排序
sorted_data = sorted(data, key=lambda x: x[2], reverse=True)

# 将排序后的数据写回 xlsx 文件
for idx, row in enumerate(sorted_data):
    for col_idx, val in enumerate(row):
        sheet.cell(row=idx+2, column=col_idx+1, value=val)

# 保存 xlsx 文件
workbook.save('medicine_data-0.xlsx')
print("操作成功")
# 在这个示例代码中，我们首先使用 openpyxl 打开指定的 xlsx 文件，
# 并从文件中读取数据，将其保存到一个名为 data 的列表中。我们指定了要读取的数据区域为第二行到最后一行，
# 并仅读取第二列到第五列的数据。接下来，我们使用 sorted() 函数对 data 列表进行排序，指定使用第四列的值进行降序排列。
# 排序后，我们再将数据写回到 xlsx 文件的相应位置，并将文件保存。
# 请根据实际情况修改 your_file.xlsx 和 your_sorted_file.xlsx 为您实际使用的文件名。
```

```python
import openpyxl

# 读取 xlsx 文件

workbook = openpyxl.load_workbook('medicine_data.xlsx')

sheet = workbook.active

# 读取需要排序的列，例如第二列到第五列

data = []

for row in sheet.iter_rows(min_row=2, values_only=True):

  data.append(row[0:5])

# 对数据按照第四列进行降序排序

sorted_data = sorted(data, key=lambda x: x[3], reverse=True)

# 将排序后的数据写回 xlsx 文件

for idx, row in enumerate(sorted_data):

  for col_idx, val in enumerate(row):

    sheet.cell(row=idx+2, column=col_idx+1, value=val)

# 保存 xlsx 文件

workbook.save('medicine_data-1.xlsx')

print("操作成功")

# 在这个示例代码中，我们首先使用 openpyxl 打开指定的 xlsx 文件，

# 并从文件中读取数据，将其保存到一个名为 data 的列表中。我们指定了要读取的数据区域为第二行到最后一行，

# 并仅读取第二列到第五列的数据。接下来，我们使用 sorted() 函数对 data 列表进行排序，指定使用第四列的值进行降序排列。

# 排序后，我们再将数据写回到 xlsx 文件的相应位置，并将文件保存。

# 请根据实际情况修改 your_file.xlsx 和 your_sorted_file.xlsx 为您实际使用的文件名。
```

```python
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

# 读取 xlsx 文件中的数据，假设需要读取第三列数据
df = pd.read_excel('medicine_data-0.xlsx', usecols=[2])

# 设置字体为中文字体
font = FontProperties(fname=r"c:\windows\fonts\simsun.ttc", size=14)

# 绘制折线图
plt.plot(df.values)
plt.xlabel('各个国家标号', fontproperties=font)
plt.ylabel('糖尿病患病率（%）', fontproperties=font) # 使用中文字体
plt.title('糖尿病患病率', fontproperties=font) # 使用中文字体

# 保存生成的图像
plt.savefig('diabetes_rate-0.png')

# 显示图像
plt.show()

```

```python
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

# 设置字体为中文字体
font = FontProperties(fname=r"c:\windows\fonts\simsun.ttc", size=14)

# 读取 xlsx 文件中的数据，假设需要读取第三列数据
df = pd.read_excel('medicine_data-1.xlsx', usecols=[3])

# 绘制折线图
plt.plot(df.values)
plt.xlabel('各个国家标号',fontproperties=font)
plt.ylabel('糖尿病死亡率（每100,000人）', fontproperties=font) # 使用中文字体
plt.title('糖尿病死亡率', fontproperties=font) # 使用中文字体
plt.savefig('diabetes_rate-1.png')
plt.show()

```

```python
# 导入这个库：Python-office，简写为office
import office

#1行代码，提取mp3文件
office.video.video2mp3(path='.//2.mp4', mp3_name='《butter-fly》')

# 参数作用：
# path = 这里填写你本地的MV文件
# mp3_name = 这里填写你生成的mp3文件名，这里不用改
```

# [ppt2pdf.py](http://ppt2pdf.py "ppt2pdf.py")

```python
# 导入库：Python-office，简写为：office
import office

# 填入你的ppt目录
office.ppt.ppt2pdf(path='E:\\GitHub\\Python\\Python-office')
```

# 生成假数据

```python
# -U, --upgrade Upgrade all packages to the newest available version
# 因此，如果您已经安装了软件包，它将为您升级该软件包。如果没有-U开关，它将告诉您该软件包已安装并退出。
#   pip install -i https://pypi.tuna.tsinghua.edu.cn/simple Python-office -U

import office

office.excel.fake2excel(columns=['name',''], rows=2000)
#########################################################
# 参数说明
# columns:list，每列的数据名称，默认是名称
# rows：多少行，默认是1
# language：什么语言，可以填english，默认是中文
# path：输出excel的位置，有默认值
#########################################################
# 地理信息类
# city_suffix()：市，县
# country()：国家
# country_code()：国家编码
# district()：区
# geo_coordinate()：地理坐标
# latitude()：地理坐标(纬度)
# longitude()：地理坐标(经度)
# postcode()：邮编
# province()：省份
# address()：详细地址
# street_address()：街道地址
# street_name()：街道名
# street_suffix()：街、路
#########################################################
# 基础信息类
# ssn()：生成身份证号
# bs()：随机公司服务名
# company()：随机公司名（长）
# company_prefix()：随机公司名（短）
# company_suffix()：公司性质，如'信息有限公司'
# credit_card_expire()：随机信用卡到期日，如'03/30'
# credit_card_full()：生成完整信用卡信息
# credit_card_number()：信用卡号
# credit_card_provider()：信用卡类型
# credit_card_security_code()：信用卡安全码
# job()：随机职位
# first_name_female()：女性名
# first_name_male()：男性名
# name()：随机生成全名
# name_female()：男性全名
# name_male()：女性全名
# phone_number()：随机生成手机号
# phonenumber_prefix()：随机生成手机号段，如139
#########################################################
# 邮箱信息类
# ascii_company_email()：随机ASCII公司邮箱名
# ascii_email()：随机ASCII邮箱：
# company_email()：公司邮箱
# email()：普通邮箱
# safe_email()：安全邮箱
# #########################################################
# 网络基础信息类
# domain_name()：生成域名
# domain_word()：域词(即，不包含后缀)
# ipv4()：随机IP4地址
# ipv6()：随机IP6地址
# mac_address()：随机MAC地址
# tld()：网址域名后缀(.com,.net.cn,等等，不包括.)
# uri()：随机URI地址
# uri_extension()：网址文件后缀
# uri_page()：网址文件（不包含后缀）
# uri_path()：网址文件路径（不包含文件名）
# url()：随机URL地址
# user_name()：随机用户名
# image_url()：随机URL地址
# 3.5 浏览器信息类
# chrome()：随机生成Chrome的浏览器user_agent信息
# firefox()：随机生成FireFox的浏览器user_agent信息
# internet_explorer()：随机生成IE的浏览器user_agent信息
# opera()：随机生成Opera的浏览器user_agent信息
# safari()：随机生成Safari的浏览器user_agent信息
# linux_platform_token()：随机Linux信息
# user_agent()：随机user_agent信息
#########################################################
# 3.6 数字信息
# numerify()：三位随机数字
# random_digit()：0~9随机数
# random_digit_not_null()：1~9的随机数
# random_int()：随机数字，默认0~9999，可以通过设置min,max来设置
# random_number()：随机数字，参数digits设置生成的数字位数
# pyfloat()：随机Float数字
# pyint()：随机Int数字（参考random_int()参数）
# pydecimal()：随机Decimal数字（参考pyfloat参数）
#########################################################
# 3.7 文本加密类
# pystr()：随机字符串
# random_element()：随机字母
# random_letter()：随机字母
# paragraph()：随机生成一个段落
# paragraphs()：随机生成多个段落
# sentence()：随机生成一句话
# sentences()：随机生成多句话，与段落类似
# text()：随机生成一篇文章
# word()：随机生成词语
# words()：随机生成多个词语，用法与段落，句子，类似
# binary()：随机生成二进制编码
# boolean()：True/False
# language_code()：随机生成两位语言编码
# locale()：随机生成语言/国际 信息
# md5()：随机生成MD5
# null_boolean()：NULL/True/False
# password()：随机生成密码,可选参数：length：密码长度；special_chars：是否能使用特殊字符；digits：是否包含数字；upper_case：是否包含大写字母；lower_case：是否包含小写字母
# sha1()：随机SHA1
# sha256()：随机SHA256
# uuid4()：随机UUID

```

# 视频转MP3

```python
# 导入这个库
import office

# 这里填写你的视频位置
path = r'D:\download\baiduyun\2.mp4'
# path，是你的视频位置；mp3_name，是你的MP3结果文件的名称，可以不填
office.video.video2mp3(path=path, mp3_name='result')
```
