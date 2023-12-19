# ESP32-蓝牙的库

# ESP32-蓝牙的库

这些指令是多媒体键盘（或多媒体遥控器）的通用控制命令，通常用于控制音频和视频播放、浏览器操作以及其他多媒体相关功能。以下是每个命令的简要解释：

1.  `KEY_MEDIA_NEXT_TRACK`: 播放下一曲目。
2.  `KEY_MEDIA_PREVIOUS_TRACK`: 播放上一曲目。
3.  `KEY_MEDIA_STOP`: 停止当前的媒体播放。
4.  `KEY_MEDIA_PLAY_PAUSE`: 播放或暂停媒体。
5.  `KEY_MEDIA_MUTE`: 静音音量。
6.  `KEY_MEDIA_VOLUME_UP`: 增加音量。
7.  `KEY_MEDIA_VOLUME_DOWN`: 降低音量。
8.  `KEY_MEDIA_WWW_HOME`: 打开浏览器主页。
9.  `KEY_MEDIA_LOCAL_MACHINE_BROWSER`: 在Windows上打开“我的电脑”或资源管理器。
10. `KEY_MEDIA_CALCULATOR`: 打开计算器应用。
11. `KEY_MEDIA_WWW_BOOKMARKS`: 打开浏览器的书签。
12. `KEY_MEDIA_WWW_SEARCH`: 打开浏览器的搜索功能。
13. `KEY_MEDIA_WWW_STOP`: 停止当前的网络浏览。
14. `KEY_MEDIA_WWW_BACK`: 在浏览器中返回到上一页。
15. `KEY_MEDIA_CONSUMER_CONTROL_CONFIGURATION`: 控制媒体选择或配置。
16. `KEY_MEDIA_EMAIL_READER`: 打开电子邮件阅读器应用。

这些命令通常用于多媒体遥控器或键盘上，以便用户可以方便地控制音乐、视频、浏览器和其他多媒体应用的功能，而无需使用鼠标或触摸屏。具体的实现和支持取决于操作系统和应用程序，但这些是通用的多媒体键盘命令。

[ESP32蓝牙模拟键盘（工作笔记）-腾讯云开发者社区-腾讯云 (tencent.com)](https://cloud.tencent.com/developer/article/1891221 "ESP32蓝牙模拟键盘（工作笔记）-腾讯云开发者社区-腾讯云 (tencent.com)")

```c
BleKeyboard bleKeyboard;

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop()
{Hello world

  if (bleKeyboard.isConnected())
{
    Serial.println("Sending 'Hello world'...");
    bleKeyboard.print("Hello world");

    delay(1000);

    Serial.println("Sending Enter key...");
    bleKeyboard.write(KEY_RETURN);

    delay(1000);

    Serial.println("Sending Play/Pause media key...");
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

    delay(1000);

    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
  }

  Serial.println("Waiting 5 seconds...");
  delay(5000);
}

```
