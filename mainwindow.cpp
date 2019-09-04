
/**
*@file mainwindow.cpp
*@brief this cpp file contains mainwindow code for the ui part of the applicatio
*
*@author MOhit KUmar
*
*@date 03/09/19
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


/**
*This method will be used when main window is to be created
*@param    QWidget *parent)  QMainWindow(parent)            the mainwindow object
*@param    ui(new Ui::MainWindow)                           the ui to be shown in the mainwindow object
*@author MOHIT KUMAR
*@date 03/09/19
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    loadDataInTrie(dictionary);
    ui->setupUi(this);
}


/**
*This method will be used when main window is to be distructed
*@author MOHIT KUMAR
*@date 03/09/19
*/
MainWindow::~MainWindow()
{
    delete ui;
}



/**
*This method will be used when push button will be clicked to search in the dictionary and then to display the result
*@author MOHIT KUMAR
*@date 03/09/19
*/
void MainWindow::on_btn_clicked()
{
    QString word = ui->inputbox->text();

      if (word.isEmpty()) {
              QMessageBox::information(this, tr("NO INPUT PROVIDED"),
                      "You did't entered any data to be searched ,please enter and press again");
      } else {
                string str = word.toStdString();
                transform(str.begin(), str.end(), str.begin(), ::tolower);
                string meaning  = search(dictionary,str);
                QString meaning_toprint = QString::fromStdString(meaning);

                if (meaning_toprint == "")
                {
                    QMessageBox::information(this, tr("INVALID WORD"),
                                        "Unfortunately the word searched is not present in Dictionary");
                    ui->meaninglabel->setText("Unfortunately the word searched is not present in Dictionary");
                }
                else
                            ui->meaninglabel->setText(meaning_toprint);
      }
}













