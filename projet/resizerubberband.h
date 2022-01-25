#ifndef RESIZERUBBERBAND_H
#define RESIZERUBBERBAND_H

#include <QObject>
#include <QWidget>
#include <QRubberBand>
class ResizeRubberBand : public QWidget
{
    Q_OBJECT
public:
    explicit ResizeRubberBand(QWidget *parent = nullptr);
private:
    QRubberBand* rubberband;
    void resizeEvent(QResizeEvent *);

signals:

};

#endif // RESIZERUBBERBAND_H
