#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/**
*@file mainwindow.h
*@brief this is header file for the mainwindow.cpp
*
*@author MOhit KUmar
*
*@date 03/09/19
*/


#include <QMainWindow>

#include "trie.h"


//declaring a namespace
namespace Ui {
class MainWindow;
}



/**
*structure of the Mainwindow class
*@author MOHIT KUMAR
*@date 03/09/19
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_clicked();

private:
    Ui::MainWindow *ui;
    Trie* dictionary;
};

#endif // MAINWINDOW_H
