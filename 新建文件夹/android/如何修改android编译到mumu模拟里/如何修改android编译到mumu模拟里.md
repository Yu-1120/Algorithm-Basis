# 如何修改android编译到mumu模拟里

[Android Studio之连接MUMU模拟器 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/112957829 "Android Studio之连接MUMU模拟器 - 知乎 (zhihu.com)")

mumu网易出的，比其他模拟器好很多

[半颗糖要不要：Android Studio之连接MUMU模拟器](https://zhuanlan.zhihu.com/p/112957829 "半颗糖要不要：Android Studio之连接MUMU模拟器")

```text
夜神模拟器：adb connect 127.0.0.1:62001

逍遥安卓模拟器：adb connect 127.0.0.1:21503

天天模拟器：adb connect 127.0.0.1:6555

海马玩模拟器：adb connect 127.0.0.1:53001

原生模拟器：adb connect (你的IP地址)：5555
```

## 网易MUMU模拟器：

每一个的SDK可能不一样， 是要进入到platform-tools

例如：这里我的SDK位置在C:\Users\HP\AppData\Local\Android\Sdk

然后打开AS中的Terminal，输入cd C:\Users\HP\AppData\Local`Android\Sdk\platform-tools`

```text
adb connect 127.0.0.1:7555
```
