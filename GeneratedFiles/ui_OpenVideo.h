/********************************************************************************
** Form generated from reading UI file 'OpenVideo.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENVIDEO_H
#define UI_OPENVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenVideoClass
{
public:
    QPushButton *pushButton;
    QLabel *labelOpenVideo;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *labelScreenShot;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *buttonDetectionAndAlignment;
    QLabel *label;
    QLabel *InputImageLabel;
    QLabel *OutputImageLabel;
    QPushButton *pushButton_8;
    QPushButton *buttonFaceRecognition;
    QLabel *SimilarityLabel;
    QLabel *labelGif;
    QLabel *labelDateTime;
    QLabel *labelFaceNum;
    QPushButton *CloseButton;

    void setupUi(QWidget *OpenVideoClass)
    {
        if (OpenVideoClass->objectName().isEmpty())
            OpenVideoClass->setObjectName(QStringLiteral("OpenVideoClass"));
        OpenVideoClass->setWindowModality(Qt::NonModal);
        OpenVideoClass->setEnabled(true);
        OpenVideoClass->resize(1125, 511);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OpenVideoClass->sizePolicy().hasHeightForWidth());
        OpenVideoClass->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral("UiFile/eye_128px_1204362_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        OpenVideoClass->setWindowIcon(icon);
        pushButton = new QPushButton(OpenVideoClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 470, 75, 35));
        pushButton->setMinimumSize(QSize(0, 35));
        labelOpenVideo = new QLabel(OpenVideoClass);
        labelOpenVideo->setObjectName(QStringLiteral("labelOpenVideo"));
        labelOpenVideo->setEnabled(true);
        labelOpenVideo->setGeometry(QRect(0, 0, 881, 421));
        sizePolicy.setHeightForWidth(labelOpenVideo->sizePolicy().hasHeightForWidth());
        labelOpenVideo->setSizePolicy(sizePolicy);
        labelOpenVideo->setMaximumSize(QSize(16777215, 16777213));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        labelOpenVideo->setFont(font);
        pushButton_2 = new QPushButton(OpenVideoClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 470, 75, 35));
        pushButton_2->setMinimumSize(QSize(0, 35));
        pushButton_2->setMaximumSize(QSize(16777215, 16777214));
        pushButton_3 = new QPushButton(OpenVideoClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(630, 470, 101, 35));
        pushButton_3->setMinimumSize(QSize(0, 35));
        pushButton_4 = new QPushButton(OpenVideoClass);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(210, 470, 75, 35));
        pushButton_4->setMinimumSize(QSize(0, 35));
        labelScreenShot = new QLabel(OpenVideoClass);
        labelScreenShot->setObjectName(QStringLiteral("labelScreenShot"));
        labelScreenShot->setGeometry(QRect(710, 400, 201, 101));
        pushButton_5 = new QPushButton(OpenVideoClass);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(300, 470, 75, 35));
        pushButton_5->setMinimumSize(QSize(0, 35));
        pushButton_6 = new QPushButton(OpenVideoClass);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setEnabled(true);
        pushButton_6->setGeometry(QRect(540, 470, 75, 35));
        pushButton_6->setMinimumSize(QSize(0, 35));
        buttonDetectionAndAlignment = new QPushButton(OpenVideoClass);
        buttonDetectionAndAlignment->setObjectName(QStringLiteral("buttonDetectionAndAlignment"));
        buttonDetectionAndAlignment->setGeometry(QRect(390, 470, 101, 35));
        buttonDetectionAndAlignment->setMinimumSize(QSize(0, 35));
        label = new QLabel(OpenVideoClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 50, 91, 31));
        InputImageLabel = new QLabel(OpenVideoClass);
        InputImageLabel->setObjectName(QStringLiteral("InputImageLabel"));
        InputImageLabel->setGeometry(QRect(880, 0, 251, 171));
        OutputImageLabel = new QLabel(OpenVideoClass);
        OutputImageLabel->setObjectName(QStringLiteral("OutputImageLabel"));
        OutputImageLabel->setGeometry(QRect(880, 200, 261, 171));
        pushButton_8 = new QPushButton(OpenVideoClass);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(910, 470, 101, 35));
        pushButton_8->setMinimumSize(QSize(0, 35));
        pushButton_8->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    color:white;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(0 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(80, 200, 59);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("UiFile/picture_128px_1201195_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon1);
        pushButton_8->setIconSize(QSize(45, 30));
        pushButton_8->setCheckable(false);
        pushButton_8->setAutoRepeat(false);
        pushButton_8->setAutoExclusive(false);
        pushButton_8->setAutoDefault(false);
        pushButton_8->setFlat(true);
        buttonFaceRecognition = new QPushButton(OpenVideoClass);
        buttonFaceRecognition->setObjectName(QStringLiteral("buttonFaceRecognition"));
        buttonFaceRecognition->setGeometry(QRect(1030, 470, 101, 35));
        buttonFaceRecognition->setMinimumSize(QSize(0, 35));
        buttonFaceRecognition->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    color:white;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(0 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(80, 200, 59);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("UiFile/Button_circle_person_128px_1198024_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        buttonFaceRecognition->setIcon(icon2);
        buttonFaceRecognition->setIconSize(QSize(45, 30));
        buttonFaceRecognition->setAutoDefault(false);
        buttonFaceRecognition->setFlat(true);
        SimilarityLabel = new QLabel(OpenVideoClass);
        SimilarityLabel->setObjectName(QStringLiteral("SimilarityLabel"));
        SimilarityLabel->setGeometry(QRect(880, 380, 241, 41));
        SimilarityLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 12pt \"\351\232\266\344\271\246\";"));
        labelGif = new QLabel(OpenVideoClass);
        labelGif->setObjectName(QStringLiteral("labelGif"));
        labelGif->setGeometry(QRect(0, 420, 1141, 41));
        labelDateTime = new QLabel(OpenVideoClass);
        labelDateTime->setObjectName(QStringLiteral("labelDateTime"));
        labelDateTime->setGeometry(QRect(890, 170, 241, 31));
        labelDateTime->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\232\266\344\271\246\";\n"
"color: rgb(255, 255, 255);"));
        labelDateTime->setScaledContents(true);
        labelFaceNum = new QLabel(OpenVideoClass);
        labelFaceNum->setObjectName(QStringLiteral("labelFaceNum"));
        labelFaceNum->setGeometry(QRect(640, 10, 231, 31));
        labelFaceNum->setStyleSheet(QString::fromUtf8("color: rgb(103, 5, 200);\n"
"font: 14pt \"\351\232\266\344\271\246\";"));
        CloseButton = new QPushButton(OpenVideoClass);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(1075, -1, 51, 31));
        CloseButton->setAutoFillBackground(false);
        CloseButton->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral("UiFile/closeWhite.png"), QSize(), QIcon::Normal, QIcon::Off);
        CloseButton->setIcon(icon3);
        CloseButton->setIconSize(QSize(18, 18));
        CloseButton->setAutoDefault(false);
        CloseButton->setFlat(false);
        labelGif->raise();
        labelOpenVideo->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        labelScreenShot->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        buttonDetectionAndAlignment->raise();
        label->raise();
        InputImageLabel->raise();
        OutputImageLabel->raise();
        pushButton_8->raise();
        buttonFaceRecognition->raise();
        SimilarityLabel->raise();
        pushButton->raise();
        pushButton_2->raise();
        labelDateTime->raise();
        labelFaceNum->raise();
        CloseButton->raise();

        retranslateUi(OpenVideoClass);
        QObject::connect(pushButton, SIGNAL(clicked()), OpenVideoClass, SLOT(OpenVideoFile()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), OpenVideoClass, SLOT(OpenCamera()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), OpenVideoClass, SLOT(CloseCamera()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), OpenVideoClass, SLOT(ScreenShot()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), OpenVideoClass, SLOT(REC()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), OpenVideoClass, SLOT(EndREC()));
        QObject::connect(buttonDetectionAndAlignment, SIGNAL(clicked()), OpenVideoClass, SLOT(FaceDetectionAlignment()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), OpenVideoClass, SLOT(InputImage()));
        QObject::connect(buttonFaceRecognition, SIGNAL(clicked()), OpenVideoClass, SLOT(FaceRecognition()));
        QObject::connect(CloseButton, SIGNAL(clicked()), OpenVideoClass, SLOT(CloseWindow()));

        pushButton_8->setDefault(false);
        buttonFaceRecognition->setDefault(false);


        QMetaObject::connectSlotsByName(OpenVideoClass);
    } // setupUi

    void retranslateUi(QWidget *OpenVideoClass)
    {
        OpenVideoClass->setWindowTitle(QApplication::translate("OpenVideoClass", "OpenVideo", nullptr));
        pushButton->setText(QApplication::translate("OpenVideoClass", "\346\211\223\345\274\200\350\247\206\351\242\221", nullptr));
        labelOpenVideo->setText(QApplication::translate("OpenVideoClass", "                            \347\247\257\350\267\254\346\255\245\357\274\214\350\207\263\345\215\203\351\207\214", nullptr));
        pushButton_2->setText(QApplication::translate("OpenVideoClass", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
        pushButton_3->setText(QApplication::translate("OpenVideoClass", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264/\350\247\206\351\242\221", nullptr));
        pushButton_4->setText(QApplication::translate("OpenVideoClass", "\346\213\215\347\205\247/\346\210\252\345\233\276", nullptr));
        labelScreenShot->setText(QString());
        pushButton_5->setText(QApplication::translate("OpenVideoClass", "\345\275\225\345\210\266\350\247\206\351\242\221", nullptr));
        pushButton_6->setText(QApplication::translate("OpenVideoClass", "\347\273\223\346\235\237\345\275\225\345\210\266", nullptr));
        buttonDetectionAndAlignment->setText(QApplication::translate("OpenVideoClass", "\344\272\272\350\204\270\346\243\200\346\265\213\344\270\216\345\257\271\351\275\220", nullptr));
        label->setText(QString());
        InputImageLabel->setText(QString());
        OutputImageLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QApplication::translate("OpenVideoClass", "<html><head/><body><p><span style=\" color:#070707;\">\346\217\220\344\276\233\344\270\200\345\274\240\345\233\276\347\211\207</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_8->setText(QApplication::translate("OpenVideoClass", "\350\276\223\345\205\245\345\233\276\347\211\207", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonFaceRecognition->setToolTip(QApplication::translate("OpenVideoClass", "<html><head/><body><p><span style=\" color:#030303;\">\350\277\233\350\241\214\344\272\272\350\204\270\350\257\206\345\210\253</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonFaceRecognition->setWhatsThis(QApplication::translate("OpenVideoClass", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        buttonFaceRecognition->setText(QApplication::translate("OpenVideoClass", "\344\272\272\350\204\270\350\257\206\345\210\253", nullptr));
        SimilarityLabel->setText(QString());
        labelGif->setText(QString());
        labelDateTime->setText(QString());
        labelFaceNum->setText(QString());
#ifndef QT_NO_TOOLTIP
        CloseButton->setToolTip(QApplication::translate("OpenVideoClass", "<html><head/><body><p>\345\205\263\351\227\255</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        CloseButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OpenVideoClass: public Ui_OpenVideoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENVIDEO_H
