#include "doodlearea.h"
#include <QPainter>
#include <QMouseEvent>
#include <QColorDialog>


DoodleArea::DoodleArea(QWidget *parent)
    : QWidget(parent),
    penColor(Qt::black),
    penWidth(2),
    image(400, 400, QImage::Format_RGB32)
{
    image.fill(Qt::white);
}

void    DoodleArea::setPenColor(const QColor &color)
{
    penColor = color;
}

void    DoodleArea::setPenWidth(int width)
{
    penWidth = width;
}

void    DoodleArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        lastPoint = event->pos();
}

void    DoodleArea::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
        drawLineTo(event->pos());
}

void    DoodleArea::paintEvent(QPaintEvent *event)
{
    QPainter    painter(this);
    QRect       dirtyRect = event->rect();

    painter.drawImage(dirtyRect, image, dirtyRect);
}

void    DoodleArea::drawLineTo(const QPoint &endPoint)
{
    QPainter    painter(&image);

    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    lastPoint = endPoint;
    update();
}

void    DoodleArea::changePenColor()
{
    QColor  newColor = QColorDialog::getColor(penColor, this);

    if (newColor.isValid())
        setPenColor(newColor);
}

void    DoodleArea::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    /* create a new image with the new size and fill it with white color */
    QImage  newImage(newSize, QImage::Format_RGB32);
    newImage.fill(Qt::white);

    /* draw the existing image onto the new image */
    QPainter    painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void    DoodleArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height())
    {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());

        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void    DoodleArea::clearDrawing()
{
    image.fill(Qt::white);
    update();
}
