# Python数据可视化

```python
import openpyxl
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties
import numpy as np

# 打开Excel文件
workbook = openpyxl.load_workbook('example.xlsx')

# 选择第一个工作表
sheet = workbook.active
# 打开Excel文件
wb = openpyxl.load_workbook('example.xlsx')
ws = wb.active
sheet = workbook.active
data = []
for row in sheet.iter_rows(min_row=2, values_only=True):
    data.append(round(row[0], 3))
    print(round(row[0], 3))
second_data = []
for row in sheet.iter_rows(min_row=2, values_only=True):
    second_data.append(row[1])
x = np.linspace(0, 10, len(data))
y = np.array([data[i] for i in range(len(data))])  
z = np.array([second_data[i] for i in range(len(data))]) 
font = FontProperties(fname=r"c:\windows\fonts\simsun.ttc", size=14)

# 绘制折线图
plt.plot(x, y, label='A-PWN')
plt.plot(x, z, label='B-PWN')

plt.title('舵机占空比对比',fontproperties=font)
plt.xlabel('占空比',fontproperties=font)
plt.ylabel('舵机角度',fontproperties=font)
plt.savefig('diabetes_rate.png')
plt.legend()
# 显示图形
plt.show()
```

```python
import openpyxl
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties
import numpy as np

# 打开Excel文件
workbook = openpyxl.load_workbook('example.xlsx')

# 选择第一个工作表
sheet = workbook.active

# 获取第二列的所有单元格数据
data = []
for row in sheet.iter_rows(min_row=2, values_only=True):
    data.append(row[1])
# 获取第三列的所有单元格数据
third_data = []
for row in sheet.iter_rows(min_row=2, values_only=True):
    third_data.append(row[2])
# 获取第四列的所有单元格数据
four_data = []
for row in sheet.iter_rows(min_row=2, values_only=True):
    four_data.append(row[3])
# 将x和y数组的长度调整为相同
x = np.linspace(0, 20, len(data))
y = np.array([data[i] for i in range(len(data))])  # 或者使用 y = y[:len(data)] 或者 y = y[0]
z = np.array([third_data[i] for i in range(len(data))])  # 或者使用 z = z[:len(data)] 或者 z = z
q = np.array([four_data[i] for i in range(len(data))])

font = FontProperties(fname=r"c:\windows\fonts\simsun.ttc", size=14)

# 绘制折线图
plt.plot(x, y, label='set Number of jumps ')
plt.plot(x, z, label='Number of jumps ')
plt.plot(x, q,  label='Residual/%')
plt.legend()
plt.title('电机速度频率',fontproperties=font)
plt.xlabel('占空比/50',fontproperties=font)
plt.ylabel('反转速度',fontproperties=font)
plt.savefig('diabetes_rate.png')
# 显示图形
plt.show()


```

```python

import openpyxl

# 创建一个工作簿对象
workbook = openpyxl.Workbook()
# 设定转速，控制频率，实际转速，误差，这四个的那个表格能做出来吗
# 误差百分之2  每4圈出现百分之2
# 获取活动的工作表对象
sheet = workbook.active

# 在第一行添加标题
sheet['A1'] = 'A舵机'
sheet['B1'] = 'B舵机'
sheet['C1'] = 'A舵机驱动误差'
sheet['D1'] = 'D舵机'
sheet.append([10/0.95,10/0.425,2])
sheet.append([10/1.50,10/0.975,2,1])
sheet.append([10/2.02,10/1.52,1.6])
sheet.append([10/2.58,10/2.1,01.5])
sheet.append([10/3.13,10/2.63,2])
sheet.append([10/3.68,10/3.15,1])
sheet.append([10/4.25,10/3.75,6,1.6])
sheet.append([10/4.87,10/4.25,6,1.6])
sheet.append([10/5.25,10/4.75,6,1.6])
sheet.append([10/5.75,10/5.25,6,1.6])
sheet.append([10/6,10/5.12,6,1.6])
sheet.append([10/7.00,10/6.38,6,1.6])
sheet.append([10/7.80,10/6.88,6,1.6])
# 保存工作簿到指定路径
workbook.save('example.xlsx')
print("写入成功")

```
