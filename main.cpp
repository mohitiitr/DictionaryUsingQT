
/**
*@file main.cpp
*@brief this cpp file contains mainwindow code for the ui part of the applicatio
*
*@author MOhit KUmar
*
*@date 03/09/19
*/

#include "mainwindow.h"
#include <QApplication>

/**
*This method will be used when application will be loaded to be run this will be first function called
*@author MOHIT KUMAR
*@date 03/09/19
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
