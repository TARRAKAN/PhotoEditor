#include "channelmixer.h"
#include <QImage>
#include <QDebug>
#include <cmath>

ChannelMixer::ChannelMixer(const QImage *const image, int r, int g, int b, QObject *parent /* = nullptr */) :
    QObject(parent),
    incRed(r),
    incGreen(g),
    incBlue(b),
    sourceImage(image)
{

}

QImage* ChannelMixer::changeRed(int num)
{
    incRed = num;
    QImage *imageToReturn{new QImage(*sourceImage)};
    changeColors(imageToReturn);
    return imageToReturn;
}

QImage* ChannelMixer::changeGreen(int num)
{
    incGreen = num;
    QImage *imageToReturn{new QImage(*sourceImage)};
    changeColors(imageToReturn);
    return imageToReturn;
}

QImage* ChannelMixer::changeBlue(int num)
{
    incBlue = num;
    QImage *imageToReturn{new QImage(*sourceImage)};
    changeColors(imageToReturn);
    return imageToReturn;
}

QImage* ChannelMixer::changeColors(QImage *const image)
{
    qDebug() << "Red:" << incRed;
    qDebug() << "Green:" << incGreen;
    qDebug() << "Blue:" << incBlue;

    for(int w{0}; w < sourceImage->width(); w++)
    {
        for(int h{0}; h < sourceImage->height(); h++)
        {
            QColor color = sourceImage->pixel(w, h);
            if(incRed > 0)
                color.setRed(std::min(color.red() + incRed, 255));
            else
                color.setRed(std::max(color.red() + incRed, 0));

            if(incGreen > 0)
                color.setGreen(std::min(color.green() + incGreen, 255));
            else
                color.setGreen(std::max(color.green() + incGreen, 0));

            if(incBlue > 0)
                color.setBlue(std::min(color.blue() + incBlue, 255));
            else
                color.setBlue(std::max(color.blue() + incBlue, 0));

            image->setPixel(w, h, color.rgb());
        }
    }
    return image;
}
