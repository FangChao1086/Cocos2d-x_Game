# Cocos2d-x_Game
[cocos2d-x 文档](https://docs.cocos.com/cocos2d-x/manual/zh/)  

* [准备工作](#准备工作)
* [基础知识](#基础知识)
* [时钟游戏](#时钟游戏)


## 准备工作
安装环境、配置
* Anaconda
* python27
* python2运行`setup.py`

开始
* **激活python2环境**  python27是创建的python2环境名
```cmd
C:\Users\95143>actiavte python27
```
* 新建项目
```cmd
(python27) C:\Users\95143>cocos new helloworld -p com.game -l cpp -d E:/Projects/cocos_demo
```

## 基础知识
以下面的时钟游戏为例
* 导演（Director）
  * 控制整个游戏进行
* 场景（Scene）
  * 开始场景，时钟场景
* 精灵（Sprite）
  * 其中时针、分针、秒针、分别是一个精灵

## 时钟游戏
#### 文件介绍
* 主要C++代码文件：文件夹clockGame
* 可执行游戏（.exe文件）：见百度云（需要下载完整文件夹）
  * 链接：https://pan.baidu.com/s/1pfoL5yRops-S68moLlP9sA   
  * 提取码：udi2  

#### 场景控制器 `SceneManager`
* loadScene
* openScene
* clockScene
#### 场景跳转
<div align=center><img src="https://github.com/FangChao1086/Cocos2d-x_Game/blob/master/依赖文件/跳转.gif" width="600" height="500"></div> 

* `loadScene -> openScene`：定时跳转
  * load 中的计时器直接跳转到 openScene 
* `openScene -> clockScene`：按钮跳转（利用回调函数）
  * 开始 -> clockScene
  * 退出 -> 结束
#### 时钟逻辑
* 放置精灵（背景 + 时分秒针）
* 时间获取显示（静止时间，秒针不会行走）
* 时间动态显示（秒针动态改变）

