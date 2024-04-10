#include "chat_item.h"

#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QFontMetrics>
#include <QFont>

ChatItem::ChatItem(const QString &text, QWidget* parent, bool recv)
    : QWidget(parent),
      kText_(text),
      bubble_background_color_(Qt::green),
      bubble_font_color_(Qt::black),
      recv_(recv) {
}

ChatItem::~ChatItem() {
}

QSize ChatItem::GetActualSize() {
  QSize bs = GetBubbleSize();
  bs.setWidth(bs.width() + 20);
  bs.setHeight(bs.height() + 20);

  return bs;
}

QSize ChatItem::GetBubbleSize() {
  int margin = 10;
  QSize ts = GetTextSize();
  return QSize(ts.width() + margin * 2, ts.height() + margin * 2);
}

QSize ChatItem::GetTextSize() {
  QFontMetrics metrics(font());
  int tw = metrics.horizontalAdvance(kText_);
  int th = metrics.height();

  return QSize(tw, th);
}

void ChatItem::paintEvent(QPaintEvent *event) {
  QWidget::paintEvent(event);

  DrawBubble();
}

void ChatItem::DrawBubble() {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

  painter.setBrush(bubble_background_color_);
  painter.setPen(bubble_background_color_);

  QSize bs = GetBubbleSize();
  QSize ts = GetTextSize();
  int margin = 10;
  int tx = 0;
  int ty = 0;

  QRect r;
  if (recv_) {
    tx = 0 + margin;
    ty = 0 + margin;
  } else {
    tx = parentWidget()->width() - margin - bs.width();
    ty = 0 + margin;
  }
  r = QRect(tx, ty, bs.width(), bs.height());
  painter.drawRoundedRect(r, 4, 4);
  DrawText(tx + margin, ty);
}

void ChatItem::DrawText(int x, int y) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

  painter.setBrush(bubble_font_color_);
  painter.setPen(bubble_font_color_);

  painter.drawText(x, y, kText_);
}
