# Milk-V Duo

Milk-V Duo是一个基于CV1800B芯片的超紧凑嵌入式开发平台。它可以运行Linux和RTOS，为专业人士、工业ODM厂商、AIoT爱好者、DIY爱好者和创作者提供了一个可靠、低成本和高性能的平台。

<https://github.com/milkv-duo/duo-files>

开发资料：Docker

<https://hub.docker.com/repository/docker/dreamcmi/cv1800-docker/general>

# 四、代码获取

旧版git：[https://github.com/milk-v/duo-manifest](https://github.com/milk-v/duo-manifest "https://github.com/milk-v/duo-manifest")

不建议使用

<https://github.com/milk-v/duo-manifest>

最新版本：

<https://github.com/milkv-duo/duo-buildroot-sdk>

SDK

<https://developer.sophgo.com/thread/471.html>

Docs ！ 重要！

<https://milkv.io/docs/duo>

大家报告可以先发电子发烧友专栏：

<https://www.elecfans.com/d/>

<https://bbs.elecfans.com/riscvmcu>

CV181x/CV180x 相关资料。

-   HDK 开发文档汇总： [https://developer.sophgo.com/thread/472.html](https://developer.sophgo.com/thread/472.html "https://developer.sophgo.com/thread/472.html")
-   开源 MMF SDK： [https://github.com/sophgo/cvi\_mmf\_sdk](https://github.com/sophgo/cvi_mmf_sdk "https://github.com/sophgo/cvi_mmf_sdk")
-   TPU SDK 开发资料汇总：[https://developer.sophgo.com/thread/473.html](https://developer.sophgo.com/thread/473.html "https://developer.sophgo.com/thread/473.html")

<https://flowus.cn/09d476c4-5850-4b6f-8bf7-4b4dbc591803>

<https://bbs.elecfans.com/jishu_2369068_1_1.html>

<https://bbs.elecfans.com/jishu_2366551_1_1.html>

<https://milkv.io/zh/docs/duo/getting-started/setup>

```c
sudo apt install dialog python3-dev make git bc gcc flex bison ninja-build libssl-dev rsync pkg-config device-tree-compiler squashfs-tools parted dosfstools cpio unzip wget

```

> 我把国内源source.list文件重刷了一次就好

```c
sudo apt install dialog python3-dev make git bc gcc flex bison ninja-build libssl-dev rsync pkg-config device-tree-compiler squashfs-tools parted dosfstools cpio unzip wget --fix--missing 
```

安装后有两种方式进行编译

自己编译，需要下载源码

编译已经编译好的，需要下载源码包

<https://github.com/milkv-duo/duo-buildroot-sdk/releases/tag/20230616>

## 获取SDK

```c
git clone https://github.com/milkv-duo/duo-buildroot-sdk.git
```

<https://github.com/milkv-duo/duo-buildroot-sdk>

## 一键编译

-   执行一键编译脚本`build_milkv.sh`

```c
cd duo-buildroot-sdk/
./build_milkv.sh
```

balenaEtcher

balenaEtcher 怎么下载

<https://etcher-docs.balena.io/>
