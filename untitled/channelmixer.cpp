#include "channelmixer.h"
#include <QImage>
#include <QDebug>
#include <cmath>

ChannelMixer::ChannelMixer(const QImage &image) : sourceImage(image), colorsCoeficients({0,0,0})
{

}

QImage* ChannelMixer::addRed(int num)
{
    QImage *imageToReturn{new QImage(sourceImage)};
    colorsCoeficients.red = num;
    return setColorsCoeficients(imageToReturn);
}

QImage* ChannelMixer::addGreen(int num)
{
    QImage *imageToReturn{new QImage(sourceImage)};
    colorsCoeficients.green = num;
    return setColorsCoeficients(imageToReturn);
}

QImage* ChannelMixer::addBlue(int num)
{
    QImage *imageToReturn{new QImage(sourceImage)};
    colorsCoeficients.blue = num;
    return setColorsCoeficients(imageToReturn);
}

QImage* ChannelMixer::setColorsCoeficients(QImage *image)
{
    for(int w{0}; w < image->width(); w++)
    {
        for(int h{0}; h < image->height(); h++)
        {
            QColor color = image->pixel(w, h);
            if(colorsCoeficients.red > 0)
                color.setRed(std::min(color.red() + colorsCoeficients.red, 255));
            else
                color.setRed(std::max(color.red() + colorsCoeficients.red, 0));

            if(colorsCoeficients.green > 0)
                color.setGreen(std::min(color.green() + colorsCoeficients.green, 255));
            else
                color.setGreen(std::max(color.green() + colorsCoeficients.green, 0));

            if(colorsCoeficients.blue > 0)
                color.setBlue(std::min(color.blue() + colorsCoeficients.blue, 255));
            else
                color.setBlue(std::max(color.blue() + colorsCoeficients.blue , 0));

            image->setPixelColor(w, h, color);
        }
    }
    return image;
}
