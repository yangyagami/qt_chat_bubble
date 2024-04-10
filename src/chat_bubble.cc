#include "chat_bubble.h"

#include <QWidget>
#include <QString>
#include <QColor>
#include <QPaintEvent>
#include <QPainter>
#include <QSizePolicy>
#include <QPropertyAnimation>

ChatBubble::ChatBubble(const QString &text, QWidget *parent)
    : QLabel(parent),
      kText_(text),
      backgroundcolor_(Qt::green),
      fontcolor_(Qt::black) {
}

ChatBubble::~ChatBubble() {
}

void ChatBubble::Init(Qt::Alignment align) {
  setText(kText_);
  setMargin(10);
  setWordWrap(true);
  setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
  setStyleSheet(QString("color: %1").arg(fontcolor_.name()));
  
  adjustSize();

  qDebug() << pos();

  QPropertyAnimation *anim = new QPropertyAnimation(this);
  anim->setTargetObject(this);
  anim->setPropertyName("size");
  anim->setStartValue(QSize(0, 0));
  anim->setEndValue(size());
  anim->setDuration(1500);
  anim->setEasingCurve(QEasingCurve::OutElastic);
  anim->start();
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
