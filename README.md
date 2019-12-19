# Cocos2d-x_Game
[cocos2d-x 文档](https://docs.cocos.com/cocos2d-x/manual/zh/)  

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
## 时钟游戏
### 场景控制器 `SceneManager`
* loadScene
* openScene
* clockScene
### 场景跳转
<div align=center><img src="https://github.com/FangChao1086/Cocos2d-x_Game/blob/master/依赖文件/跳转.gif" width="600" height="500"></div>  

* `loadScene -> openScene`：定时跳转
  * load 中的计时器直接跳转到 openScene 
* `openScene -> clockScene`：按钮跳转（利用回调函数）
  * 开始 -> clockScene
  * 退出 -> 结束
