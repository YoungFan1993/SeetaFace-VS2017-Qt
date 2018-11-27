#pragma once

#include <QtWidgets/QWidget>
#include "ui_OpenVideo.h"
#include <opencv2/opencv.hpp>
#include "MyThread.h" //自定义线程模板（类）
#include <QThread>  //线程头文件

//SeetaFace
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include "cv.h"
#include "highgui.h"
#include "face_detection.h"
#include "face_alignment.h"

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "face_identification.h"
#include "recognizer.h"
#include "face_detection.h"
#include "face_alignment.h"

#include "math_functions.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


class OpenVideo : public QWidget
{
	Q_OBJECT

public:
	OpenVideo(QWidget *parent = Q_NULLPTR);

protected:
	//重写绘图事件
	void paintEvent(QPaintEvent *event);
	//重写鼠标按下事件
	void mousePressEvent(QMouseEvent *event);
	//重写鼠标移动事件
	void mouseMoveEvent(QMouseEvent *event);


public slots: //槽函数
	void OpenVideoFile(); //打开视频文件
	void OpenCamera(); //打开摄像头
	void CloseCamera(); //关闭摄像头
	void ScreenShot(); //拍照/截图
	void REC();  // 录像
	void EndREC(); // 结束录像
	void FaceDetectionAlignment(); //人脸检测与对齐
	void InputImage(); //输入图片
	void FaceRecognitionProcess(); //人脸识别

	void nextFrame(); //获取下一帧图片
	void nextSeetaFaceProcessFrame(); //获取下一帧处理的图片
	void currentDateAndTime();  //动态显示当前日期和时间
	void CloseWindow(); //关闭窗口

	//获取子线程信号发来的信息
	//获取人脸检测与对齐信息
	//void getDetectionAndAlignmentInformation(int faceNum, QImage image);
	//获取人脸识别信息
	void getRecognitionInformation(int gallery_face_num, int probe_face_num,QImage image,float sim);
	void NoFace();

signals:

	void mainSignal(QString str);
	void VideoSignal(QImage image,bool flag);

private:
	Ui::OpenVideoClass ui;

	cv::Mat frame; //定义一个Mat变量，用于存储没一帧的图像
	cv::Mat temp; //临时变量
	cv::VideoCapture capture; //定义VideoCapture对象，获取摄像头
	cv::VideoWriter writer;  //定义VideoWriter对象，录制
	QTimer *timer;  //定时器
	QTimer *timer2;  //人脸识别定时器
	QString ImagePath; //定义输入图片的路径

	int x = 0;
	int y = 0;

	bool openREC;
	QPoint p; //定义的点

	MyThread *myT; //自定义线程模块(类)对象
	QThread *thread; //子线程

	//人脸检测与对齐
	int faceNum;
	QImage imageDetectionAndAlignment;

	//人脸识别
	int GalleryFaceNum;
	int ProbeFaceNum;
	QImage CropFace;
	float Sim;
	bool CameraVideoFlag; //标志位,true代表Camera，false代表Video
};
