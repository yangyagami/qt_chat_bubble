#ifndef CHAT_BUBBLE_CHAT_ITEM_H_
#define CHAT_BUBBLE_CHAT_ITEM_H_

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QPaintEvent>
#include <QRect>
#include <QImage>

class ChatItem : public QWidget {
  Q_OBJECT
 public:
  explicit ChatItem(const QString &text, QWidget* parent = nullptr,
		    bool recv = false);
  ~ChatItem();

  QSize GetActualSize();

  void set_text(const QString &text) {
    text_ = text;
  }
  void set_bubble_background_color(const QColor &color) {
    bubble_background_color_ = color;
  }
  void set_bubble_font_color(const QColor &color) {
    bubble_font_color_ = color;
  }
  void set_head_img(QImage img) {
    head_img_ = img;
  }
 protected:
  virtual void paintEvent(QPaintEvent *event) override;
 private:
  QSize GetTextSize();
  QSize GetSpecTextSize(const QString &text);
  QSize GetBubbleSize();

  void Draw();
  void DrawBubble(QRect rect);
  void DrawText(QRect rect);
  void DrawHead(QRect rect);
  void DrawTriangle(QPoint pos);
 private:
  QString text_;
  QColor bubble_background_color_;
  QColor bubble_font_color_;
  bool recv_;
  QImage head_img_;
};

#endif  // CHAT_BUBBLE_CHAT_ITEM_H_
