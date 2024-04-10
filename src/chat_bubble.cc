#include "chat_bubble.h"

#include <QWidget>
#include <QString>
#include <QColor>
#include <QPaintEvent>
#include <QPainter>
#include <QSizePolicy>
#include <QPropertyAnimation>

ChatBubble::ChatBubble(QWidget *parent) {
  ChatBubble("", parent);
}

ChatBubble::ChatBubble(const QString &text, QWidget *parent)
    : QLabel(text, parent),
      backgroundcolor_(Qt::green),
      fontcolor_(Qt::black) {
  setVisible(true);
  setMargin(10);
  setAlignment(Qt::AlignCenter);
  setWordWrap(true);
  setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
  setStyleSheet(QString("color: %1").arg(fontcolor_.name()));
  
  adjustSize();
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
