#include "OpenVideo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OpenVideo w;
	w.show();
	return a.exec();
}
