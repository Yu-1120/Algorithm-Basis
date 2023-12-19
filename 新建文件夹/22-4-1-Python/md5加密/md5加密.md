# md5加密

```python
import uuid
import  hashlib

# 定义函数，生成唯一的32位token
def only_token():
    """
    使用md5加密uuid生成唯一的32位token
    :return: 加密后的字符串
    """
    md5 = hashlib.md5()  # 使用MD5加密模式
    md5.update(str(uuid.uuid1()).encode('utf-8')) # 将uuid转换为字符串并编码为utf-8格式，然后更新md5对象
    return md5.hexdigest() # 返回加密后的字符串

# 如果当前文件被作为主程序运行，则调用only_token函数
if __name__ == '__main__':
    only_token()


```
