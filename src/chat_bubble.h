#ifndef CHAT_BUBBLE_CHAT_BUBBLE_H_
#define CHAT_BUBBLE_CHAT_BUBBLE_H_

#include <QLabel>
#include <QString>
#include <QColor>
#include <QPaintEvent>

class ChatBubble : public QLabel {
  Q_OBJECT
 public:
  explicit ChatBubble(const QString &text, QWidget *parent = nullptr);
  virtual ~ChatBubble();

  void Init();

  void set_backgroundcolor(const QColor &color);
  void set_fontcolor(const QColor &color);
 protected:
  virtual void paintEvent(QPaintEvent *event) override;
 private:
  const QString kText_;
  QColor backgroundcolor_;
  QColor fontcolor_;
};

#endif  // CHAT_BUBBLE_CHAT_BUBBLE_H_
