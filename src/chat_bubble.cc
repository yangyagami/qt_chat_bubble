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
      backgroundcolor_(Qt::green),
      fontcolor_(Qt::black) {
  // All this stuff should not be in here :(
  setVisible(true);
  setText(text);
  setMargin(10);
  setAlignment(Qt::AlignCenter);
  setWordWrap(true);
  setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
  setStyleSheet(QString("color: %1").arg(fontcolor_.name()));
  
  adjustSize();

  qDebug() << pos();
  
  QPropertyAnimation *anim = new QPropertyAnimation(this);
  anim->setTargetObject(this);
  // anim->setPropertyName("size");
  // anim->setStartValue(QSize(0, 0));
  // anim->setEndValue(size()); // 结束大小
  anim->setPropertyName("geometry");
  anim->setStartValue(QRect(0 + width() / 2, 0, 0, 0));
  anim->setEndValue(QRect(x() + width() / 2, y() + height() / 2, width(), height())); // 结束大小
  anim->setDuration(1500); // 持续时间为200毫秒
  anim->setEasingCurve(QEasingCurve::OutElastic); // 缓动曲线
  anim->start();
}

ChatBubble::~ChatBubble() {

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
  painter.drawRoundedRect(rect(), 4, 4);

  QLabel::paintEvent(event);
}
