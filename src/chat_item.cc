#include "chat_item.h"

#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QFontMetrics>
#include <QFont>
#include <QPainterPath>

ChatItem::ChatItem(const QString &text, QWidget* parent, bool recv)
    : QWidget(parent),
      text_(text),
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
  QSize bs(ts.width() + margin * 2, ts.height() + margin * 2);
  return bs;
}

QSize ChatItem::GetTextSize() {
  return GetSpecTextSize(text_);
}

QSize ChatItem::GetSpecTextSize(const QString &text) {
  QFontMetrics metrics(font());
  QRect text_rect = metrics.boundingRect(
      QRect(0, 0, parentWidget()->width() * 0.6, 0),
      Qt::AlignCenter | Qt::TextWordWrap,
      text_);

  return text_rect.size();
}

void ChatItem::paintEvent(QPaintEvent *event) {
  QWidget::paintEvent(event);

  Draw();
}

void ChatItem::Draw() {
  QSize bs = GetBubbleSize();
  QSize ts = GetTextSize();

  int margin = 10;
  int hx = 0;
  int radius = 20;
  int hy = 0;
  if (recv_) {
    hx = 0 + margin; 
    hy = 0 + margin; 
  } else {
    hx = parentWidget()->width() - margin - radius * 2;
    hy = 0 + margin;
  }
  QRect head_rect(hx, hy, radius * 2, radius * 2);
  DrawHead(head_rect);

  if (recv_) {
    DrawTriangle(QPoint(hx + radius * 2 + 3, hy + radius));
  } else {
    DrawTriangle(QPoint(hx - 3, hy + radius));
  }

  int bx = hx;
  int by = hy;
  int pw = parentWidget()->width();

  if (recv_) {
    bx = 0 + margin + head_rect.width() + margin;
    by = 0 + margin;
  } else {
    bx = pw - margin - bs.width() - head_rect.width() - margin;
    by = 0 + margin;
  }
  QRect bubble_rect = QRect(bx, by, bs.width(), bs.height());
  DrawBubble(bubble_rect);
  DrawText(bubble_rect);
}

void ChatItem::DrawTriangle(QPoint pos) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setBrush(bubble_background_color_);
  painter.setPen(bubble_background_color_);

  QPoint a;
  QPoint b;
  if (recv_) {
    a = QPoint(pos.x() + 10, pos.y() + 5);
    b = QPoint(pos.x() + 10, pos.y() - 5);
  } else {
    a = QPoint(pos.x() - 10, pos.y() - 5);
    b = QPoint(pos.x() - 10, pos.y() + 5);
  }
  QPolygon triangle;
  triangle << a << b << pos;
  painter.drawPolygon(triangle);
}

void ChatItem::DrawHead(QRect rect) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  QPainterPath circle_path;
  circle_path.addEllipse(rect);

  painter.setClipPath(circle_path);

  painter.drawImage(rect, head_img_);
}

void ChatItem::DrawBubble(QRect rect) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

  painter.setBrush(bubble_background_color_);
  painter.setPen(bubble_background_color_);

  painter.drawRoundedRect(rect, 8, 8);
}

void ChatItem::DrawText(QRect rect) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

  painter.setBrush(bubble_font_color_);
  painter.setPen(bubble_font_color_);

  painter.drawText(rect, Qt::AlignCenter | Qt::TextWordWrap, text_);
}
