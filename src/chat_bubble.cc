#include "chat_bubble.h"

#include <QWidget>
#include <QString>
#include <QColor>
#include <QPaintEvent>
#include <QPainter>
#include <QSizePolicy>
#include <QPropertyAnimation>
#include <QDebug>

ChatBubble::ChatBubble(QWidget *parent) {
  ChatBubble("", parent);
}

ChatBubble::ChatBubble(const QString &text, QWidget *parent)
<<<<<<< HEAD
    : QLabel(text, parent),
      backgroundcolor_(Qt::green),
      fontcolor_(Qt::black) {
  setVisible(true);
=======
    : QLabel(parent),
      kText_(text),
      backgroundcolor_(Qt::green),
      fontcolor_(Qt::black) {
}

ChatBubble::~ChatBubble() {
}

void ChatBubble::Init() {
  setText(kText_);
>>>>>>> 67f5ced3a360bed95b14dbba26aa8bed2ed8eec5
  setMargin(10);
  setWordWrap(true);
  setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
  setStyleSheet(QString("color: %1").arg(fontcolor_.name()));
  
  adjustSize();
<<<<<<< HEAD
=======

  qDebug() << pos();

  QPropertyAnimation *anim = new QPropertyAnimation(this);
  anim->setTargetObject(this);
  anim->setPropertyName("size");
  anim->setStartValue(QSize(0, 0));
  anim->setEndValue(size());
  anim->setDuration(1500);
  anim->setEasingCurve(QEasingCurve::OutElastic);
  anim->start();
>>>>>>> 67f5ced3a360bed95b14dbba26aa8bed2ed8eec5
}

void ChatBubble::set_backgroundcolor(const QColor &color) {
  backgroundcolor_ = color;
}

void ChatBubble::set_fontcolor(const QColor &color) {
  fontcolor_ = color;
}

void ChatBubble::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

  painter.setBrush(backgroundcolor_);
  painter.setPen(backgroundcolor_);
  painter.drawRoundedRect(rect(), 8, 8);

  QLabel::paintEvent(event);
}
