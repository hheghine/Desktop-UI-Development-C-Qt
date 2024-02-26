#ifndef DOODLEAREA_H
#define DOODLEAREA_H

#include <QWidget>
#include <QImage>
#include <QColor>
#include <QPoint>

class DoodleArea : public QWidget
{
    Q_OBJECT

public:
    DoodleArea(QWidget *parent = nullptr);

    void    setPenColor(const QColor &color);
    QColor  getPenColor() const { return penColor; }
    void    setPenWidth(int width);
    int     getPenWidth() const { return penWidth; }

public slots:
    void    changePenColor();
    void    clearDrawing();

protected:
    void    mousePressEvent(QMouseEvent *event) override;
    void    mouseMoveEvent(QMouseEvent *event) override;
    void    paintEvent(QPaintEvent *event) override;
    void    resizeEvent(QResizeEvent *event) override;

private:
    void    drawLineTo(const QPoint &endPoint);
    void    resizeImage(QImage *image, const QSize &newSize);

private:
    QColor  penColor;
    int     penWidth;
    QImage  image;
    QPoint  lastPoint;
};

#endif // DOODLEAREA_H
