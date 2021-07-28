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

    sourceImage = QSharedPointer<QImage>(new QImage(filename));
    ui->label_4->setPixmap(QPixmap::fromImage(*sourceImage).scaled(ui->label_4->size()));
    channelMixer = QSharedPointer<ChannelMixer>(new ChannelMixer(*sourceImage));
}


void MainWindow::on_redSlider_valueChanged(int value)
{
    finalImage = QSharedPointer<QImage>(channelMixer->addRed(value));
    ui->label_4->setPixmap(QPixmap::fromImage(*finalImage).scaled(ui->label_4->size()));
}

void MainWindow::on_greenSlider_valueChanged(int value)
{
    finalImage = QSharedPointer<QImage>(channelMixer->addGreen(value));
    ui->label_4->setPixmap(QPixmap::fromImage(*finalImage).scaled(ui->label_4->size()));
}

void MainWindow::on_blueSlider_valueChanged(int value)
{
    finalImage = QSharedPointer<QImage>(channelMixer->addBlue(value));
    ui->label_4->setPixmap(QPixmap::fromImage(*finalImage).scaled(ui->label_4->size()));
}

void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    finalImage = QSharedPointer<QImage>(channelMixer->addBrightness(value));
    ui->label_4->setPixmap(QPixmap::fromImage(*finalImage).scaled(ui->label_4->size()));
}

