# gradle

# gradle是什么

[Gradle系列第一讲-什么是Gradle？ Gradle是做什么的？\_gradle是干嘛的-CSDN博客](https://blog.csdn.net/nightcurtis/article/details/77735484 "Gradle系列第一讲-什么是Gradle？ Gradle是做什么的？_gradle是干嘛的-CSDN博客")

1.  Gradle 是一个构建工具，也是一个开发框架，基于Groovy语言。 我们可以通过Groovy语言去写自己的Gradle插件，也可以去编写指定的脚本去改变构建规则。
2.  android studio中gradle之所以能够构建android工程，是因为有基于android的gradle插件。

[亲测可用，Android国内Maven仓库 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/205237800 "亲测可用，Android国内Maven仓库 - 知乎 (zhihu.com)")

```c
// Top-level build file where you can add configuration options common to all sub-projects/modules.  
  
buildscript {  
    repositories {  
        maven { url 'https://maven.aliyun.com/repository/public' }  
        maven { url 'https://maven.aliyun.com/repository/central' }  
        maven { url 'https://maven.aliyun.com/repository/google' }  
        maven { url 'https://maven.aliyun.com/repository/gradle-plugin' }  
        google()  
        jcenter()  
    }  
    dependencies {  
        classpath "com.android.tools.build:gradle:4.0.1"  
    }  
}  
  
  
plugins {  
    id 'com.android.application' version '8.1.2' apply false  
}

```
