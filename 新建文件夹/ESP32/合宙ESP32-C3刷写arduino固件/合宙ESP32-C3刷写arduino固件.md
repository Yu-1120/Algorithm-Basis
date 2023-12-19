# 合宙ESP32-C3刷写arduino固件

![](image/kg2pod8pqc_117II3KnV5_34GJ7iRkqs.png)

![](image/nsrjihtphi_St8ZaLxB87_2VhxJieMEC.png)

![](image/qtuit0oxpv_SJ4aLHV4ej_fYJK0l08O6.png)

![](image/d-nui2n8jr_ooStz_09UH_f9JXPjHEj0.png)

# arduino-IDE的配置

我用的版本：2.1.1（版本不对也多大没关系）

## 下载安

![](image/tf2c2xobsv_fAIR8wlb_P_xsDYdxMnzP.png)

选择 `ESP32C3 Dev Module`

![](image/vsn6g-_8lx_1mJP5Lh2i__bqWM2Z0H5K.png)

## 安装环境

![](image/5waeicvi73_5vgIUr4jKn_OTM82PT-TP.png)

## 配置环境：

```text
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
```

填入下面箭头的指向

![](image/87iosszj1f_5tzi7_1eFf_7Y7MVioJ2l.png)

# 测试代码

```c
//***************************************************************/
//
//           -------------------------------------------
//           board: ESP32C3 Dev Module
//           Flash Mode: "DIO"
//           -------------------------------------------
//
//***************************************************************/

#define     LED_D4     12
#define     LED_D5     13

void setup() {

  Serial.begin(115200);
  pinMode(LED_D4, OUTPUT);
  pinMode(LED_D5, OUTPUT);

}

void loop() {

  Serial.println("Hello world!");

  digitalWrite(LED_D4, LOW);
  digitalWrite(LED_D5, HIGH);
  delay(500);
  digitalWrite(LED_D4, HIGH);
  digitalWrite(LED_D5, LOW);
  delay(500);

}
```
