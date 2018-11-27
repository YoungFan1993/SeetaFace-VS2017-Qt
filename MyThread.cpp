#include "MyThread.h"

MyThread::MyThread(QObject *parent) : QObject(parent)
{
	//设置初始标志位
	isStop = false; 
	CameraVideoFlag = true;
}

void MyThread::setFlag(bool flag)
{
	isStop = flag;
}

//----------------------------------------------------【人脸识别】------------------------------------------------
void MyThread::FaceRecognitionProcess()
{
	using namespace seeta;

	std::string MODEL_DIR = "./model/";

	//用模型文件的路径实例化seeta::FaceDetection的对象
	seeta::FaceDetection detector("./model/seeta_fd_frontal_v1.0.bin");
	detector.SetMinFaceSize(40);//设置要检测的人脸的最小尺寸(默认值:20，不受限制),也能设置最大：face_detector.SetMaxFaceSize(size);
	detector.SetScoreThresh(2.f); //设置检测到的人脸的得分阈值(默认值:2.0)
	detector.SetImagePyramidScaleFactor(0.8f);//设置图像金字塔比例因子(0 <因子< 1，默认值:0.8)
	detector.SetWindowStep(4, 4);//设置滑动窗口的步长(默认:4),face_detector.SetWindowStep(step_x, step_y);

	//初始化的人脸对齐模型
	seeta::FaceAlignment point_detector("./model/seeta_fa_v1.1.bin");

	//初始化的人脸识别模型
	FaceIdentification face_recognizer((MODEL_DIR + "seeta_fr_v1.0.bin").c_str());

	//输入一张图片
	cv::Mat gallery_img_color = cv::imread(path.toStdString(), 1); 
	cv::Mat gallery_img_gray;
	cv::cvtColor(gallery_img_color, gallery_img_gray, CV_BGR2GRAY);

	cv::Mat probe_img_color;

	if (CameraVideoFlag)
	{
		capture.open(0);
	}

	while (!isStop)
	{
		//获取摄像头/视频的每一帧画面
		if (CameraVideoFlag)
		{
			capture >> probe_img_color;
		}
		else
		{
			//接收QImage的格式是RGB，要转成OpenCV中Mat的BGR格式
			cvtColor(frameTemp, frame, CV_RGB2BGR);
			probe_img_color = frame;
		}
		cv::Mat probe_img_gray;
		cv::cvtColor(probe_img_color, probe_img_gray, CV_BGR2GRAY);

		ImageData gallery_img_data_color(gallery_img_color.cols, gallery_img_color.rows, gallery_img_color.channels());
		gallery_img_data_color.data = gallery_img_color.data;//data  uchar型的指针。Mat类分为了两个部分:矩阵头和指向矩阵数据部分(所有矩阵值)的指针，data就是指向矩阵数据的指针。

		ImageData gallery_img_data_gray(gallery_img_gray.cols, gallery_img_gray.rows, gallery_img_gray.channels());
		gallery_img_data_gray.data = gallery_img_gray.data;

		ImageData probe_img_data_color(probe_img_color.cols, probe_img_color.rows, probe_img_color.channels());
		probe_img_data_color.data = probe_img_color.data;

		ImageData probe_img_data_gray(probe_img_gray.cols, probe_img_gray.rows, probe_img_gray.channels());
		probe_img_data_gray.data = probe_img_gray.data;

		// Detect faces
		std::vector<seeta::FaceInfo> gallery_faces = detector.Detect(gallery_img_data_gray);
		int32_t gallery_face_num = static_cast<int32_t>(gallery_faces.size());

		std::vector<seeta::FaceInfo> probe_faces = detector.Detect(probe_img_data_gray);
		int32_t probe_face_num = static_cast<int32_t>(probe_faces.size());

		if (gallery_face_num != 0 && probe_face_num != 0)
		{
			//检测5点面部标记
			seeta::FacialLandmark gallery_points[5];
			point_detector.PointDetectLandmarks(gallery_img_data_gray, gallery_faces[0], gallery_points);

			seeta::FacialLandmark probe_points[5];
			point_detector.PointDetectLandmarks(probe_img_data_gray, probe_faces[0], probe_points);

			for (int i = 0; i < 5; i++)
			{
				cv::circle(gallery_img_color, cv::Point(gallery_points[i].x, gallery_points[i].y), 2,
					CV_RGB(0, 255, 0));
				cv::circle(probe_img_color, cv::Point(probe_points[i].x, probe_points[i].y), 2,
					CV_RGB(0, 255, 0));
			}
			cv::imwrite("gallery_point_result.jpg", gallery_img_color);
			cv::imwrite("probe_point_result.jpg", probe_img_color);

			//提取面部特性特征
			float gallery_fea[2048];
			float probe_fea[2048];
			face_recognizer.ExtractFeatureWithCrop(gallery_img_data_color, gallery_points, gallery_fea);
			face_recognizer.ExtractFeatureWithCrop(probe_img_data_color, probe_points, probe_fea);

			//-------------------------------------------【裁剪脸部】----------------------------------------------------
			//创建一个图像来存储裁剪的脸部
			cv::Mat dst_img(face_recognizer.crop_height(),
				face_recognizer.crop_width(),
				CV_8UC(face_recognizer.crop_channels()));
			ImageData dst_img_data(dst_img.cols, dst_img.rows, dst_img.channels());
			dst_img_data.data = dst_img.data;

			//裁剪
			face_recognizer.CropFace(probe_img_data_color, probe_points, dst_img_data);
			//保存裁剪的脸部
			cv::imwrite("dst_img.jpg", dst_img);

			//图像在Qt显示前，必须将Mat型转化成QImage格式，将RGBA格式转化成RGB 
			cvtColor(dst_img, temp, CV_BGR2RGB);
			//转化成QImage格式
			QImage CropFace = QImage((const unsigned char *)(temp.data), temp.cols,
				temp.rows, QImage::Format_RGB888);

			//计算两张脸部的相似度
			float sim = face_recognizer.CalcSimilarity(gallery_fea, probe_fea);

			//Qt多线程的信号传参只能传基本数据类型
			//Mat 或者库里面的int_8 / int_32(自定义的数据类型) 什么的不能传
			//类型转换
			int GalleryFaceNum = gallery_face_num;
			int ProbeFaceNum = probe_face_num;
			//发射信号
			emit UpdateRecognition(GalleryFaceNum, ProbeFaceNum, CropFace, sim);
		}

		else
		{
			emit NoFace();
		}
	}
	
}

void MyThread::getMainSignal(QString str)
{
	//获取输入图片的路径
	path = str;
}

void MyThread::getVideoSignal(QImage image,bool flag)
{
	this->image = image;
	CameraVideoFlag = flag;
	frameTemp = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
	//不能放在这里转格式，会造成不能及时接收
	//故把格式转换放在处理函数里了
}

