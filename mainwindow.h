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
    void create_menu();
    ~MainWindow();
public slots:
    void on_btn_click();
    void newFile();
    void quit();
private:
    Ui::MainWindow *ui;
    QTextEdit *main_text;

    QMenu *fileMenu;
    QMenu *exitMenu;
    QMenu *formatMenu;
    QMenu *helpMenu;
protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
};
#endif // MAINWINDOW_H


