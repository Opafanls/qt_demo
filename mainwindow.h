#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void init_win();
    ~MainWindow();
public slots:
    void on_btn_click();

private:
    Ui::MainWindow *ui;
    QTextEdit *main_text;
};
#endif // MAINWINDOW_H


