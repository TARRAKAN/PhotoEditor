#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "~/",
                                                    tr("Image Files (*.png *.jpg *.bmp)"));
    if(image != Q_NULLPTR) delete image;
    image = new QImage(filename);
    ui->label_4->setPixmap(QPixmap::fromImage(*image).scaled(ui->label_4->size()));
}

void MainWindow::on_redSlider_actionTriggered(int action)
{
    for(size_t w{0}; w < image->width(); w++)
    {
        for(size_t h{0}; h < image->height(); h++)
        {
            QColor color = image->pixel(w, h);
            if((color.red() + action) <= 255) color.setRed(color.red() + action);
            image->setPixel(w, h, color.rgb());
        }

    }
    ui->label_4->setPixmap(QPixmap::fromImage(*image).scaled(ui->label_4->size()));
}

void MainWindow::on_greenSlider_actionTriggered(int action)
{
    for(size_t w{0}; w < image->width(); w++)
    {
        for(size_t h{0}; h < image->height(); h++)
        {
            QColor color = image->pixel(w, h);
            if((color.green() + action) <= 255) color.setGreen(color.green() + action);
            image->setPixel(w, h, color.rgb());
        }
    }
    ui->label_4->setPixmap(QPixmap::fromImage(*image).scaled(ui->label_4->size()));
}

void MainWindow::on_blueSlider_actionTriggered(int action)
{
    for(size_t w{0}; w < image->width(); w++)
    {
        for(size_t h{0}; h < image->height(); h++)
        {
            QColor color = image->pixel(w, h);
            if((color.blue() + action) <= 255) color.setBlue(color.blue() + action);
            image->setPixel(w, h, color.rgb());
        }
    }
    ui->label_4->setPixmap(QPixmap::fromImage(*image).scaled(ui->label_4->size()));
}
