/**
*Copyright (c) 2018 Young Fan.All Right Reserved.
*Filename:
*Author: Young Fan
*Date: 2018.5.29 - 7.5
*OpenCV version: 3.4.1
*IDE: Visual Studio 2017
*Description: Demo:Qt + Opecv + VS + SeetaFace(via VIPL)
*/

#include "OpenVideo.h"
#include <QFileDialog>
#include <QTimer>
#include <QMovie>
#include <QPainter>
#include <QDebug>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include <QMouseEvent>
//使用Qt多媒体，需要在附加依赖项里加Qt5Multimedia.lib(debug)/Qt5Multimediad.lib(release)
#include <QtMultimedia/QMediaPlayer> 



OpenVideo::OpenVideo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//设置窗口标题
	setWindowTitle("OpenVideo");

	//让图片自动适应label大小
	ui.labelOpenVideo->setScaledContents(true);
	ui.labelGif->setScaledContents(true);

	//-----【显示Gif动画】-------
	//创建动画
	QMovie *myMovie = new QMovie("./UiFile/2.gif");
	//设置动画
	ui.labelGif->setMovie(myMovie);
	//启动动画
	myMovie->start();

	//固定主窗口大小
	setFixedSize(1125, 511);

	//创建定时器
	timer = new QTimer(this);

	//-----------【不规则窗口】-------------
	//给窗口去掉边框，带上窗口的flags（标记）
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//把窗口背景设置为透明,这里不设置透明也可以，因为图片不透明
	setAttribute(Qt::WA_TranslucentBackground);

	//更改按钮样式表
	ui.CloseButton->setFlat(true); //把按钮设置为透明背景，此时只有按下的时候才有背景。
	ui.CloseButton->setStyleSheet("QPushButton{"
		//"background:rgb(176,0,0);"//按钮设置为透明背景，这里设置了设置了也不显示
		//但如果加上"border:2px outset green;"则可以在初始态，鼠标悬停态显示背景色，下面一样
		"}"
		"QPushButton:hover{"
		"border:1px;"//当按钮背景是透明的，则必须加边框宽度，才能有hover效果，这样写也行"border:1px outset red;"
		"background:rgb(255,96,96);"//按钮设置为透明背景，这里设置了设置了也不显示
									//"border-image:url(E:/C++/Demo/OpenVideo/UiFile/closeWhite.png);"
		"}"
		"QPushButton:pressed{"
		"background:rgb(255,77,77);"//此时只有按下的时候才有背景。
									//"border-image:url(E:/C++/Demo/OpenVideo/UiFile/closeWhite.png);"
		"}");

	//-----------------------------------------【多线程部分】--------------------------------------------------
	//自定义模块(类)对象，分配空间，不可以指定父对象，因为下面要移到子线程
	myT = new MyThread;
	//创建子线程,指定父对象
	thread = new QThread(this);
	//把自定义模块添加到子线程
	myT->moveToThread(thread);
	//启动子线程，但是并没有启动线程的处理函数,要用信号和槽启动线程的处理函数
	thread->start();

	//线程处理函数，必须通过signal-slot调用
	//这里使用的是按钮的信号来触发，也可以用按钮的转到槽函数，在里面去发射信号
	//，用信号去调用模块类中的处理函数
	connect(ui.buttonFaceRecognition,&QPushButton::pressed,myT,&MyThread::FaceRecognitionProcess);//人脸识别部分
	
	//一旦子模块类中的处理函数启动，就会发射UpdateProcess信号（线程代码里写的）
	connect(myT,&MyThread::UpdateRecognition,this,&OpenVideo::getRecognitionInformation);//人脸识别部分	
	connect(myT, &MyThread::NoFace, this, &OpenVideo::NoFace);

	//主线程给子线程通信
	connect(this, &OpenVideo::mainSignal, myT, &MyThread::getMainSignal);
	connect(this,&OpenVideo::VideoSignal,myT,&MyThread::getVideoSignal);

}
//--------------------------------------------【重写鼠标按下事件】--------------------------------------------
void OpenVideo::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) //event->button() 返回的是Buttons事件
	{
		//求坐标差值，窗口上鼠标点击当前点的坐标是相对于屏幕的
		//求差：当前点击坐标 - 窗口左上角坐标
		//相对于窗口的坐标用x，y，相对于屏幕用globalPos
		//frameGeometry，是带边框的,用它可以获取窗口左上角坐标（相对于屏幕的坐标）
		//移动窗口时是以左上角来移动的，要想点哪就从哪移动，则要求坐标差
		p = event->globalPos() - this->frameGeometry().topLeft();
	}
}

void OpenVideo::mouseMoveEvent(QMouseEvent *event)
{
	//这里因为是按住，故使用buttons(带‘s’的button）
	//左键按住移动窗口
	if (event->buttons() & Qt::LeftButton) //event->buttons()返回的是int位字段
	{
		//移动窗口时是以左上角来移动的，故要减去p(此时就相当于从该点开始移动)
		this->move(event->globalPos() - p);
	}
}

//----------------------------------------------【画背景图】--------------------------------------------------
void OpenVideo::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.drawPixmap(0, 0, width(), height(), QPixmap("./UiFile/background.png"));
}

//-----------------------------------------------【显示当前日期和时间】------------------------------------
void OpenVideo::currentDateAndTime()
{
	//还有其他的显示时间日期的方法，如C语言的宏__DATE__,__TIME__、再比如QTime里也有能显示时间与日期
	//用arg()也能显示，但都需要定时器
	ui.labelDateTime->setText(QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss.zzz A"));
}
//----------------------------------------------【关闭窗口】--------------------------------------------------
void OpenVideo::CloseWindow()
{
	//写程序要养成一种习惯，要做判断
	if (false == thread->isRunning()) //如果线程已停止，则按钮不在往下执行
	{
		return;
	}
	myT->setFlag(true); //跳出循环
	thread->quit(); //温柔地退出
	thread->wait(); //等待，回收资源
					//但如果模块（类）还在工作的话(如死循环while(1)，即不加这句myT->setFlag(true);)，
					//则线程并不会停止还是会在运行

	this->close(); //关闭窗口
	delete myT; //释放资源
}

//---------------------------------------------【打开视频文件】------------------------------------------------
void OpenVideo::OpenVideoFile()
{
	//初始化标志位
	CameraVideoFlag = false;
	myT->setFlag(false); //子线程处理函数循环

	//显示标签
	ui.labelOpenVideo->setVisible(true);
	ui.label->setVisible(true);

	//创建文件对话框并获取路径
	QString path = QFileDialog::getOpenFileName(this,
		"open", "../", "Video(*.mp4 *.flv *.mkv *.avi)");

	//读入视频
	capture.open(path.toLocal8Bit().data()); //也可以path.toStdString()   

	//判断定时器的激活状态
	if (false == timer->isActive())
	{
		//启动定时器
		timer->start(35);
	}

	//定时器连接,获取下一帧图片
	connect(timer, &QTimer::timeout, this, &OpenVideo::nextFrame);
	connect(timer, &QTimer::timeout,
			[=]()
			{
				ui.label->setText(QStringLiteral("视频播放中..."));
				ui.label->move(QPoint(x++, y++));
				if (x >511)
				{
					x = 0;
					y = 0;
				}
			}
			);
}

//----------------------------------------------【打开摄像头】---------------------------------------------
void OpenVideo::OpenCamera()
{
	//初始化标志位
	CameraVideoFlag = true;

	//显示标签
	ui.labelOpenVideo->setVisible(true);

	//读入摄像头
	capture.open(0);

	timer->start(35); //定时35ms

	//定时器连接,获取下一帧图片
	connect(timer, &QTimer::timeout, this, &OpenVideo::nextFrame);
}

//-----------------------------------【获取并显示下一帧图片】---------------------------------------
void OpenVideo::nextFrame()
{
	capture >> frame; //读取当前帧
	//图像在Qt显示前，必须将Mat型转化成QImage格式，将OpenCV中Mat的BGR格式转化成QImage的RGB格式 
	cvtColor(frame, temp, CV_BGR2RGB);
	//转化成QImage格式
	QImage image = QImage((const unsigned char *)(temp.data), temp.cols,
		temp.rows, QImage::Format_RGB888);
	ui.labelOpenVideo->setPixmap(QPixmap::fromImage(image));

	if (!CameraVideoFlag)
	{
		emit VideoSignal(image, CameraVideoFlag);
	}

}

//--------------------------------------【拍照/截图】------------------------------------------------
void OpenVideo::ScreenShot()
{
	//将Mat型temp转为Qt的QImage型
	QImage image = QImage((const unsigned char *)(temp.data), temp.cols,
		temp.rows, QImage::Format::Format_RGB888);
	ui.labelScreenShot->setPixmap(QPixmap::fromImage(image));
	//让图片自动适应label大小
	ui.labelScreenShot->setScaledContents(true);

	//截图保存
	const QPixmap *img = ui.labelScreenShot->pixmap();
	QString path = QFileDialog::getSaveFileName(this, "save", "../", "Image(*.png)");
	if (false == path.isEmpty()) //判断路径是否有效
	{
		bool isOk = img->save(path);
		if (true == isOk)
		{

			//#pragma execution_character_set("utf-8") 
			//设置为UTF-8格式，显示中文，不然会乱码,但是影响了vs的编码格式，不能摧毁中文名称窗口
			//故选择用QStringLiteral("中文")进行修饰。这样虽不能全局设置utf-8，但可以正常摧毁中文名称窗口
			QMessageBox::information(this, QStringLiteral("保存完成"), QStringLiteral("截图保存完成"));
		}
	}
	else
	{
		//保存文件路径出错
		return;
	}
}

//---------------------------------------【录制视频】-------------------------------------------
void OpenVideo::REC()
{
	double rate = 12.0;//保存视频的帧率，12这个帧率很合适，播放的时候不慢不快
	cv::Size videoSize(frame.cols, frame.rows);
	//录制 VideoWriter writer; 已在头文件中定义
	writer.open("../REC.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), rate, videoSize, true);
	openREC = true;
	while (openREC)
	{
		capture >> frame;
		writer.write(frame);// 或writer << frame;

							//加个窗口显示。不加的话，直接设置循环会卡住不动
		cv::namedWindow("录制视频");
		imshow("录制视频", frame);
		cv::waitKey(30);
	}
}

//-------------------------------------------------【结束录制】------------------------------------------
void OpenVideo::EndREC()
{
	cv::destroyWindow("录制视频");
	openREC = false;
	writer.release();//结束录制
}

//--------------------------------------------【人脸检测与对齐】-----------------------------------------------
void OpenVideo::FaceDetectionAlignment()
{
	//定时器连接,获取下一帧图片
	connect(timer, &QTimer::timeout, this, &OpenVideo::nextSeetaFaceProcessFrame);
	
}

//----------------------------------------------【获取下一帧SeetaFace处理的图片】----------------------------
void OpenVideo::nextSeetaFaceProcessFrame()
{

	std::string MODEL_DIR = "./model/";

	//-----------------------------------------【人脸检测与对齐】--------------------------------------
	////要检测图像上的人脸，首先应该用模型文件的路径实例化seeta::FaceDetection的对象。
	seeta::FaceDetection detector("./model/seeta_fd_frontal_v1.0.bin");
	detector.SetMinFaceSize(40);//设置要检测的人脸的最小尺寸(默认值:20，不受限制),也能设置最大：face_detector.SetMaxFaceSize(size);
	detector.SetScoreThresh(2.f);////设置检测到的人脸的得分阈值(默认值:2.0)
	detector.SetImagePyramidScaleFactor(0.8f);//设置图像金字塔比例因子(0 <因子< 1，默认值:0.8)
	detector.SetWindowStep(4, 4);//设置滑动窗口的步长(默认:4),face_detector.SetWindowStep(step_x, step_y);

		capture >> frame;//读入摄像头

		int pts_num = 5;
		cv::Mat img_gray;
		if (frame.channels() != 1)
			//非单通道的，转为灰度图
			cv::cvtColor(frame, img_gray, cv::COLOR_BGR2GRAY);
		else
		{
			img_gray = frame;
		}

		seeta::ImageData image_data;
		image_data.data = img_gray.data;
		image_data.width = img_gray.cols;
		image_data.height = img_gray.rows;
		image_data.num_channels = 1;

		//调用Detect()来检测人脸，它将作为seeta::FaceInfo的向量(容器)返回。
		std::vector<seeta::FaceInfo> faces = detector.Detect(image_data);
		int32_t face_num = static_cast<int32_t>(faces.size()); //获取人脸数量

		seeta::FacialLandmark points[5];//定义面部的5个标记点

		//首先应该实例化seeta:: faceAlignment的对象与模型文件的路径。
		seeta::FaceAlignment point_detector((MODEL_DIR + "seeta_fa_v1.1.bin").c_str());

		//检测5点面部标记
		for (int f = 0; f < face_num; f++) {
			point_detector.PointDetectLandmarks(image_data, faces[f], points);//检测出人脸标记
			//将人脸用矩形框出（矩形的范围由Detect()返回的faces给出）
			cv::rectangle(frame, cv::Point(faces[f].bbox.x, faces[f].bbox.y),//bbox是Rect类型的结构体
				cv::Point(faces[f].bbox.x + faces[f].bbox.width - 1, faces[f].bbox.y + faces[f].bbox.height - 1), CV_RGB(255, 0, 0));

			// Visualize the results(形象化结果，即把检测出的5点标记（由PointDetectLandmarks函数内部给出），用小圆环框出)
			for (int i = 0; i < pts_num; i++)
			{
				cv::circle(frame, cv::Point(points[i].x, points[i].y), 2, CV_RGB(0, 255, 0), -CV_FILLED);
				//cv::ellipse(frame, cv::Point(points[i].x, points[i].y),cv::Size(6,2),-45,0,360,cv::Scalar(255,129,0),1,8);
			}
		}

		//图像在Qt显示前，必须转化成QImage格式，将RGBA格式转化成RGB 
		cvtColor(frame, temp, CV_BGR2RGB);
		//转化成QImage格式
		QImage image = QImage((const unsigned char *)(temp.data), temp.cols,
			temp.rows, QImage::Format_RGB888);

		ui.labelFaceNum->setText(QStringLiteral("检测到的人脸个数：%1").arg(face_num));
		ui.labelOpenVideo->setPixmap(QPixmap::fromImage(image));

}


//----------------------------------------------【关闭摄像头】-------------------------------------------
void OpenVideo::CloseCamera()
{
	capture.release();
	timer->stop();

	//关闭摄像头后，对标签状态进行控制，下面有好几种方法
	//ui.labelOpenVideo->hide();  //控件隐藏,Widget类的方法
	//ui.labelOpenVideo->setVisible(false);//控件是否可见,Widget类的方法
	ui.labelOpenVideo->close();//控件关闭,Widget类的方法，可与与show()搭配使用;

	//关闭录制（按钮复用）
	cv::destroyWindow("录制视频");
	openREC = false;

	//去除“视频播放中”字样
	ui.label->close();

	//先停止子线程
	myT->setFlag(true); //跳出循环
}

//------------------------------------------------【输入图片】-------------------------------------------
void OpenVideo::InputImage()
{
	ImagePath = QFileDialog::getOpenFileName(this,
		QStringLiteral("打开图片"), "../", "Image(*.png *.jpg *.bmp)");

	emit mainSignal(ImagePath); //发出信号给子线程

	ui.InputImageLabel->setPixmap(QPixmap(ImagePath)); //其实直接放QString类型的也可以（即直接放ImagePath）
	//让图片自动适应label大小
	ui.InputImageLabel->setScaledContents(true);

	//动态显示当前日期和时间（定时器已在打开摄像头时激活）
	connect(timer, &QTimer::timeout, this, &OpenVideo::currentDateAndTime);
}

//----------------------------------------------【获取子线程信号发来的信息】------------------------------------
//获取人脸识别模块的信息
void OpenVideo::getRecognitionInformation(int gallery_face_num, int probe_face_num,QImage image,float sim)
{
	GalleryFaceNum = gallery_face_num;
	ProbeFaceNum = probe_face_num;
	CropFace = image;
	Sim = sim;
	
	//更新操作
	FaceRecognitionProcess(); 
}

//-------------------------------------------------【人脸识别】--------------------------------------------
//描述： 从视频中找出与输入图片对应的人脸
void OpenVideo::FaceRecognitionProcess()
{

	if (GalleryFaceNum != 0 && ProbeFaceNum != 0)
	{
		//显示相似度
		ui.SimilarityLabel->setText(QStringLiteral("相似度为：%1").arg(Sim));  //组包，用arg来显示float型

		if (Sim > 0.7)
		{
			ui.SimilarityLabel->setText(QStringLiteral(" 发现目标 | 相似度为：%1").arg(Sim));
			//printf("\a"); //转义响铃符，在Qt中无效，改用下面的Qt的方式

			//播放音频
			QMediaPlayer *player = new QMediaPlayer;
			//QUrl::fromLocalFile  该函数接受由斜线分隔(/)的路径以及该平台的本机分隔符。
			//此函数还接受具有双前导斜杠(反斜杠)(\\)的路径来指示远程文件
			player->setMedia(QUrl::fromLocalFile("./mp3/Recognition.mp3"));
			player->setVolume(80);
			player->play();

			//----------------------------------【将裁剪的脸部显示在界面标签上】------------------------------------------
			ui.OutputImageLabel->setPixmap(QPixmap::fromImage(CropFace));
			ui.OutputImageLabel->setScaledContents(true);
		}
	}

	
}

void OpenVideo::NoFace()
{
	ui.SimilarityLabel->setText(QStringLiteral("sorry！检测不到人脸"));
}
