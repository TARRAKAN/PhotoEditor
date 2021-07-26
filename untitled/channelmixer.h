#ifndef CHANNELMIXER_H
#define CHANNELMIXER_H

#include <QObject>

class QImage;

class ChannelMixer : public QObject
{
    Q_OBJECT
public:
    explicit ChannelMixer(const QImage *const image, int r, int g, int b, QObject *parent = nullptr);

    QImage* changeRed(int num);
    QImage* changeGreen(int num);
    QImage* changeBlue(int num);
private:
    int incRed;
    int incGreen;
    int incBlue;
    QImage* changeColors(QImage *const image);
    const QImage * sourceImage;

signals:

};

#endif // CHANNELMIXER_H
