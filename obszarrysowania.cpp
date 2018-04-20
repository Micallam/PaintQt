#include "obszarrysowania.h"

ObszarRysowania::ObszarRysowania(QWidget *parent) : QWidget(parent)
{
    mRysunek=QImage(this->size(),QImage::Format_RGB32);

    mKolor=Qt::red;
}

void ObszarRysowania::zmienKolorRed()
{
    qDebug()<<"Zmieniam na czerwony";
    mKolor=Qt::red;
}

void ObszarRysowania::zmienKolorYellow()
{
    qDebug()<<"Zmieniam na żółty";
    mKolor=Qt::yellow;
}

void ObszarRysowania::zmienKolorBlue()
{
    qDebug()<<"Zmieniam na niebieski";
    mKolor=Qt::blue;
}

void ObszarRysowania::zmienKolorGreen()
{
    qDebug()<<"Zmieniam na zielony";
    mKolor=Qt::green;
}
void ObszarRysowania::kasujRysunek()
{
    qDebug()<<"Kasuję rysunek";
    QImage nowy=QImage(mRysunek.size(),mRysunek.format());

    nowy.fill(Qt::white);
    mRysunek=nowy;
    update();
}
bool ObszarRysowania::zapiszRysunek(QString &name)
{
    qDebug()<<"Zapisuję";

    mRysunek.save(name,"PNG");

    return true;
}

void ObszarRysowania::mousePressEvent(QMouseEvent *zdarzenie)
{
    qDebug()<<"mousePressEvent";

    if (zdarzenie->button()==Qt::LeftButton)
    {
        mRysowanie=true;
        mousePos=zdarzenie->pos();
    }
}

void ObszarRysowania::mouseMoveEvent(QMouseEvent *zdarzenie)
{
    qDebug()<<"mouseMoveEvent";

    if(mRysowanie)
    {
        QPainter rysownik(&mRysunek);
        QPen pioro(mKolor,2);

        rysownik.setPen(pioro);
        rysownik.drawLine(mousePos,zdarzenie->pos());
        mousePos=zdarzenie->pos();

        this->update();
    }
}

void  ObszarRysowania::mouseReleaseEvent(QMouseEvent *zdarzenie)
{
    qDebug()<<"mouseReleaseEvent";

    if (zdarzenie->button()==Qt::LeftButton)
    {
        mRysowanie=false;
    }
}

void ObszarRysowania::paintEvent(QPaintEvent *zdarzenie)
{
    qDebug()<<"paintEvent";

    QPainter rysownik(this);
    rysownik.drawImage(0,0,mRysunek);
}

void ObszarRysowania::resizeEvent(QResizeEvent *zdarzenie)
{
    qDebug()<<"resizeEvent";

    QImage nowy (zdarzenie->size(),QImage::Format_RGB32);
    nowy.fill(Qt::white);

    mRysunek=nowy;
    mRysowanie=false;
    this->update();
}
