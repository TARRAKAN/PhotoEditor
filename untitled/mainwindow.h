#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

class ChannelMixer;

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
    void on_redSlider_valueChanged(int value);
    void on_greenSlider_valueChanged(int value);
    void on_blueSlider_valueChanged(int value);
    void on_brightnessSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QSharedPointer<QImage> sourceImage;
    QSharedPointer<QImage> finalImage;
    QSharedPointer<ChannelMixer> channelMixer;

};

#endif // MAINWINDOW_H
