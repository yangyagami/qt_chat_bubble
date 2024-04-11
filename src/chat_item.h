#ifndef CHAT_BUBBLE_CHAT_ITEM_H_
#define CHAT_BUBBLE_CHAT_ITEM_H_

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QPaintEvent>

class ChatItem : public QWidget {
  Q_OBJECT
 public:
  explicit ChatItem(const QString &text, QWidget* parent = nullptr,
		    bool recv = false);
  ~ChatItem();

  QSize GetActualSize();
 protected:
  virtual void paintEvent(QPaintEvent *event) override;
 private:
  QSize GetTextSize();
  QSize GetBubbleSize();

  void DrawBubble();
  void DrawText(int x, int y);
 private:
  const QString kText_;
  QColor bubble_background_color_;
  QColor bubble_font_color_;
  bool recv_;
};

#endif  // CHAT_BUBBLE_CHAT_ITEM_H_
