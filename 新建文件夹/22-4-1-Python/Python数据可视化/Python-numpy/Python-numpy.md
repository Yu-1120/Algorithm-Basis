# Python-numpy

<https://geek-docs.com/matplotlib/matplotlib-examples/t_how-to-plot-signal-in-matplotlib-in-python.html#:~:text=%E5%A6%82%E4%BD%95%E5%9C%A8Python%E7%9A%84Matplotlib%E4%B8%AD%E7%BB%98%E5%88%B6%E4%BF%A1%E5%8F%B7%E5%9B%BE%E5%BD%A2%3F%20%E8%A6%81%E8%8E%B7%E5%BE%97%E4%BF%A1%E5%8F%B7%E7%BB%98%E5%9B%BE%EF%BC%8C%E5%8F%AF%E4%BB%A5%E6%8C%89%E7%85%A7%E4%BB%A5%E4%B8%8B%E6%AD%A5%E9%AA%A4%E8%BF%9B%E8%A1%8C-%20%E8%AE%BE%E7%BD%AE%E5%9B%BE%E5%BD%A2%E5%A4%A7%E5%B0%8F%E5%B9%B6%E8%B0%83%E6%95%B4%E5%AD%90%E5%9B%BE%E4%B9%8B%E9%97%B4%E5%8F%8A%E5%91%A8%E5%9B%B4%E7%9A%84%E5%A1%AB%E5%85%85%E3%80%82%20%E8%8E%B7%E5%BE%97%E9%9A%8F%E6%9C%BA%E7%A7%8D%E5%AD%90%E5%80%BC%E3%80%82%20%E4%B8%BA%E9%87%87%E6%A0%B7%E9%97%B4%E9%9A%94%E5%88%9D%E5%A7%8B%E5%8C%96%20dt%20%E5%B9%B6%E6%89%BE%E5%88%B0%E9%87%87%E6%A0%B7%E9%A2%91%E7%8E%87%E3%80%82%20%E4%B8%BA,t%20%E5%88%9B%E5%BB%BA%E9%9A%8F%E6%9C%BA%E6%95%B0%E6%8D%AE%E7%82%B9%E3%80%82%20%E4%B8%BA%E4%BA%86%E4%BA%A7%E7%94%9F%E5%99%AA%E5%A3%B0%EF%BC%8C%20%E4%BD%BF%E7%94%A8numpy%E8%8E%B7%E5%8F%96nse%E3%80%81r%E3%80%81cnse%E5%92%8Cs%E3%80%82%20%E4%BD%BF%E7%94%A8%20subplots%20%28%29%20%E6%96%B9%E6%B3%95%E5%88%9B%E5%BB%BA%E4%B8%80%E4%B8%AA%E5%9B%BE%E5%BD%A2%E5%92%8C%E4%B8%80%E7%BB%84%E5%AD%90%E5%9B%BE%E3%80%82>

```python

import matplotlib.pyplot as plt
import numpy as np

plt.rcParams["figure.figsize"] = [7.50, 3.50]
plt.rcParams["figure.autolayout"] = True

np.random.seed(0)

dt = 0.01 # 采样间隔
Fs = 1 / dt # 采样频率
t = np.arange(0, 10, dt)

# 生成噪声：
nse = np.random.randn(len(t))
r = np.exp(-t / 0.05)
cnse = np.convolve(nse, r) * dt
cnse = cnse[:len(t)]
s = 0.1 * np.sin(4 * np.pi * t) + cnse
fig, axs = plt.subplots()
axs.set_title("Signal")
axs.plot(t, s, color='C0')
axs.set_xlabel("Time")
axs.set_ylabel("Amplitude")

plt.show()


```
