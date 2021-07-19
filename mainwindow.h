#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

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
    void on_pushButton_clicked();

    void on_redSlider_actionTriggered(int action);

    void on_greenSlider_actionTriggered(int action);

    void on_blueSlider_actionTriggered(int action);

private:
    Ui::MainWindow *ui;
    QImage *image;
};

#endif // MAINWINDOW_H
