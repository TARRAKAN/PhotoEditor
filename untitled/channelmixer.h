#ifndef CHANNELMIXER_H
#define CHANNELMIXER_H

#include <QObject>

class QImage;

class ChannelMixer
{
public:
    explicit ChannelMixer(const QImage &image);

    QImage* addRed(int num);
    QImage* addGreen(int num);
    QImage* addBlue(int num);
private:
    QImage const &sourceImage;
    struct
    {
        int red;
        int green;
        int blue;
    }colorsCoeficients;

    QImage* setColorsCoeficients(QImage *image);
};

#endif // CHANNELMIXER_H
