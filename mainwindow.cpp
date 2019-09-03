
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    loadDataInTrie(dictionary);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_btn_clicked()
{
    QString word = ui->inputbox->text();
      if (word.isEmpty()) {
              QMessageBox::information(this, tr("NO INPUT PROVIDED"),
                      "You did't entered any data to be searched ,please enter and press again");
      } else {
                string str = word.toStdString();
                string meaning  = search(dictionary,str);
                QString meaning_toprint = QString::fromStdString(meaning);

                if (meaning_toprint == "")
                    QMessageBox::information(this, tr("INVALID WORD"),
                                        "Unfortunately the word searched is not present in Dictionary");
                else
                            ui->meaniglabel->setText(meaning_toprint);
      }
}













