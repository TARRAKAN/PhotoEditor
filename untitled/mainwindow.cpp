#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include "channelmixer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "~/Pictures/",
                                                    tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
    //if(image != nullptr) delete image;

    image = new QImage(filename);
    ui->label_4->setPixmap(QPixmap::fromImage(*image).scaled(ui->label_4->size()));
}


void MainWindow::on_redSlider_valueChanged(int value)
{
    ChannelMixer* channelMixer{new ChannelMixer(image, value, ui->greenSlider->value(), ui->blueSlider->value())};
    finalImage = channelMixer->changeRed(value);
    ui->label_4->setPixmap(QPixmap::fromImage(finalImage->scaled(ui->label_4->size())));
}


void MainWindow::on_greenSlider_valueChanged(int value)
{
    ChannelMixer* channelMixer{new ChannelMixer(image, ui->redSlider->value(), value, ui->blueSlider->value())};
    finalImage = channelMixer->changeGreen(value);
    ui->label_4->setPixmap(QPixmap::fromImage(finalImage->scaled(ui->label_4->size())));
}


void MainWindow::on_blueSlider_valueChanged(int value)
{
    ChannelMixer* channelMixer{new ChannelMixer(image, ui->redSlider->value(), ui->greenSlider->value(), value)};
    finalImage = channelMixer->changeBlue(value);
    ui->label_4->setPixmap(QPixmap::fromImage(finalImage->scaled(ui->label_4->size())));
}

