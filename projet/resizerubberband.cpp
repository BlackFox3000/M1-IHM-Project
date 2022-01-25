#include "resizerubberband.h"
#include "QHBoxLayout"
#include "QSizeGrip"
#include "QMouseEvent"
ResizeRubberBand::ResizeRubberBand(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::SubWindow);
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    QSizeGrip* grip1 = new QSizeGrip(this);
    QSizeGrip* grip2 = new QSizeGrip(this);
    layout->addWidget(grip1, 0, Qt::AlignLeft | Qt::AlignTop);
    layout->addWidget(grip2, 0, Qt::AlignRight | Qt::AlignBottom);
    rubberband = new QRubberBand(QRubberBand::Rectangle, this);
    rubberband->move(0, 0);
    rubberband->show();
    show();
}
void ResizeRubberBand::resizeEvent(QResizeEvent *) {
  rubberband->resize(size());
}
