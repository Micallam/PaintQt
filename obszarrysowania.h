#ifndef OBSZARRYSOWANIA_H
#define OBSZARRYSOWANIA_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QImage>
#include <QPainter>
#include <QPen>
#include <QPoint>

class ObszarRysowania : public QWidget
{
    Q_OBJECT
public:
    explicit ObszarRysowania(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *zdarzenie);
    void mouseMoveEvent(QMouseEvent *zdarzenie);
    void mouseReleaseEvent(QMouseEvent *zdarzenie);
    void paintEvent(QPaintEvent *zdarzenie);
    void resizeEvent(QResizeEvent *zdarzenie);

private:
    bool mRysowanie;
    QImage mRysunek;
    QImage mRysunek2;
    QColor mKolor;
    QPoint mousePos;

signals:

public slots:
    void zmienKolorRed();
    void zmienKolorYellow();
    void zmienKolorBlue();
    void zmienKolorGreen();
    void kasujRysunek();
    bool zapiszRysunek(QString& name);
};

#endif // OBSZARRYSOWANIA_H
