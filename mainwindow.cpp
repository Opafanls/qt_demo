#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QtWidgets>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QMediaPlayer>

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
    //menu
    create_menu();
    //video
    auto main_widget = ui->centralwidget;
    auto main_layout = new QVBoxLayout;
    auto text_layout = new QHBoxLayout;
    auto video_layout = new QHBoxLayout;
    main_layout->addLayout(video_layout);
    main_layout->addLayout(text_layout);
    //video layout
    auto player = new QMediaPlayer;
    player->setSource(QUrl("https://aiot-gateway.zijieapi.com/media_record/v1/file/get?ObjKey=pbmv8ylxuo9eofa7.push.bfcdnbf.com/8501520c-67d0-45e7-a0b6-028b08e2ac90/m3u8/1659460608072_1659461204067.m3u8&X-JWT-Token=ZXlKaGJHY2lPaUpJVXpJMU5pSXNJblI1Y0NJNklrcFhWQ0o5LmV5SkJZMk52ZFc1MFNVUWlPakl4TURBd05UTXhORE1zSW1WNGNDSTZNVFkyTURFMU1EVXlNeXdpYVhOeklqb2lZV2x2ZEY5elpYSjJaWElpTENKRmVIUnlZU0k2ZXlKUFltcExaWGtpT2lKd1ltMTJPSGxzZUhWdk9XVnZabUUzTG5CMWMyZ3VZbVpqWkc1aVppNWpiMjB2T0RVd01UVXlNR010Tmpka01DMDBOV1UzTFdFd1lqWXRNREk0WWpBNFpUSmhZemt3TDIwemRUZ3ZNVFkxT1RRMk1EWXdPREEzTWw4eE5qVTVORFl4TWpBME1EWTNMbTB6ZFRnaUxDSlFaWEp0YVhOemFXOXVJam9pTVNKOWZRLk5fVVdURjBPMmd0MUdrUkV0enYxd1FyanVVS0ctUDRUeng4WC1uTndOaWs="));
    auto video_widget = new QVideoWidget;
    player->setVideoOutput(video_widget);
    player->play();
    video_widget->show();
    video_layout->addWidget(video_widget);
    //text layout
    main_text = new QTextEdit;
    main_text->setMaximumHeight(200);
    auto submit_btn = new QPushButton("&submit");
    //receiver: 接受click事件的obj,监听click,并传递到receiver的on_btn_click函数
    connect(submit_btn, SIGNAL(clicked(bool)), this, SLOT(on_btn_click()));
    text_layout->addWidget(main_text);
    text_layout->addWidget(submit_btn);
    main_widget->setLayout(main_layout);

    QString message = tr("this is the menu bar");
    statusBar()->showMessage(message);
}


void MainWindow::on_btn_click() {
    this->main_text->setText("hello world");
}

void MainWindow::create_menu() {
    //create actions
    auto* newAct = new QAction(tr("&New"), this);
    newAct->setToolTip("&Create new file");
    newAct->setShortcuts(QKeySequence::New);    //增加快捷键,ctrl+N

    auto* close = new QAction(tr("Quit"), this);    //will not show @mac if quit/exit
    close->setToolTip("&Quit new program"); //auto*而不是auto
    close->setShortcuts(QKeySequence::Close);    //增加快捷键,ctrl+N

    //creat menus
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(close);
    fileMenu->addSeparator();

    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    connect(close, &QAction::triggered, this, &MainWindow::quit);
}

void MainWindow::newFile() {

}

void MainWindow::quit() {
    exit(0);
}


#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

