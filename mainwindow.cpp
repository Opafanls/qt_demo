#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_win() {
    auto main_widget = ui->centralwidget;
    auto main_layout = new QVBoxLayout;
    auto main_text = new QTextEdit;
    auto submit_btn = new QPushButton("&submit");
    main_layout->addWidget(main_text);
    main_layout->addWidget(submit_btn);
    main_widget->setLayout(main_layout);
}

