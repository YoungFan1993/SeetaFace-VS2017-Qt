#ifndef MYTHREAD_H  //防止头文件被重复包含，这是C语言方式，C++是：#pragma once
#define MYTHREAD_H

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

#include <opencv2/opencv.hpp>
#include <QObject>
#include <QTimer> //定时器
#include <QImage> //QImage头文件

class MyThread : public QObject
{
	Q_OBJECT
public:
	explicit MyThread(QObject *parent = nullptr);
	
	//线程处理函数
	void FaceRecognitionProcess(); //人脸识别

	//获取主线程信号发来的数据
	void getMainSignal(QString str);
	void getVideoSignal(QImage image,bool flag);

	//标志位函数
	void setFlag(bool flag = true); //括号里定义了一个默认参数，不传参的时候就使用默认的

signals:
	void UpdateRecognition(int GalleryFaceNum,int ProbeFaceNum,QImage image,float sim);
	void NoFace();
	
private:
	cv::Mat frame; //定义一个Mat变量，用于存储每一帧的图像
	cv::Mat temp; //临时变量
	cv::Mat frameTemp;
	cv::VideoCapture capture; //定义VideoCapture对象，获取摄像头

	QImage image;

	//标志位
	bool isStop; 
	bool CameraVideoFlag;//标志位,true代表Camera，false代表Video

	QString path;
};

#endif // MYTHREAD_H
