#include "dashboard.h"
#include "ui_dashboard.h"
#include <QScrollBar>
void Dashboard::auewordsInit(){
    position = 0;
    step = 2;

    // Настройка бегущего текста
    movingTextBrowser = new QTextBrowser(ui->AueWordsBox);
    movingTextBrowser->setHtml("<p style='font-family: \"Comfortaa\"; font-size: 24px; color: #000; white-space: nowrap; margin: 0;'>Если Вам холодно - встаньте в угол. Там 90°C</p>");
    movingTextBrowser->setFrameStyle(QFrame::NoFrame);
    movingTextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    movingTextBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // размеры
    movingTextBrowser->document()->setTextWidth(2000); //  ширина для текста в одну строку
    int textWidth = movingTextBrowser->document()->idealWidth();
    movingTextBrowser->setFixedSize(textWidth, 27);
    movingTextBrowser->move(0, 25);

    // таймер для анимации текста
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Dashboard::updateTextPosition);
    timer->start(30); // обновление каждые 30мс
}

void Dashboard::updateTextPosition()
{
    //  границы движения
    int rightBound = width();

    position += step;

    // сбрасываем позицию
    if (position > rightBound) {
        position = -movingTextBrowser->width();
    }

    movingTextBrowser->move(position, 25); // обновляем позицию
}


