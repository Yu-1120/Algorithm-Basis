# Python-MySQL

```python
import MySQLdb

# 打开数据库连接
con = MySQLdb.connect(
    host='localhost',
    user='root',
    passwd='',
    db='数据库名',
    charset='utf8'
)

# 使用cursor()方法创建一个游标对象
c = con.cursor()

# 使用 execute() 方法执行 SQL，如果表存在则删除
c.execute("DROP TABLE IF EXISTS EMPLOYEE")

# sql语句创建表
sql = '''create table 表名(     # 根据自己的需要添加字段
        observation_type varchar(20),
        observation_point varchar(40),
        observation_time datetime,
        average_value float,
        max_value float,
        min_value float,
        momentary_value float,
        temperature float)
'''
c.execute(sql)

# 关闭数据库连接
con.close()

###################################################

import pandas as pd

filePath = 'data.xlsx'
data = pd.read_excel('data.xlsx')

# 打开数据库连接
con = MySQLdb.connect(
    host='localhost',
    user='root',
    passwd='',
    db='数据库名',   # 数据库的名
    charset='utf8'
)

# 使用cursor()方法创建一个游标对象
c = con.cursor()

# 插入数据
query = "insert into 表名 values(%s,%s,%s,%s,%s,%s,%s,%s)"
for r in range(0, len(data)):
    observation_type = data.iloc[r, 0]
    observation_point = data.iloc[r, 1]
    observation_time = data.iloc[r, 2]
    average_value = data.iloc[r, 3]
    max_value = data.iloc[r, 4]
    min_value = data.iloc[r, 5]
    momentary_value = data.iloc[r, 6]
    temperature = data.iloc[r, 7]

    values = (observation_type, observation_point, observation_time, average_value, max_value, min_value, momentary_value, temperature)
    c.execute(query, values)

# 提交数据
con.commit()

# 关闭数据库连接
con.close()


```

# exec2mysql.py

exec的数据插入数据库

```python
import MySQLdb
import pandas as pd

# 定义文件路径
filePath = 'fake2excel.xlsx'

# 读取Excel文件
data = pd.read_excel('fake2excel.xlsx')

# 连接MySQL数据库
con = MySQLdb.connect(
    host='localhost',
    user='root',
    passwd='mysql',
    db='test',
    charset='utf8'
)

# 创建游标对象
c = con.cursor()

# 定义SQL语句
query = "insert into test1 values(%s)"

# 遍历Excel文件中的每一行
for r in range(0, len(data)):
    # 获取姓名
    name = data.iloc[r, 0]

    # 定义参数
    values = (name,)

    # 执行SQL语句
    c.execute(query, values)

# 提交事务
con.commit()

# 关闭连接
con.close()


```
