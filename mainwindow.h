#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void poisk();

    void on_open_clicked();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
