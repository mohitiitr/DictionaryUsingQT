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


