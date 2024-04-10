#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPainter>
#include <QDebug>
#include <QTimer>

#include "chat_bubble.h"

class MainWindow : public QWidget {
 public:
  explicit MainWindow(QWidget *parent = nullptr)
      : QWidget(parent) {}
  virtual ~MainWindow() {}
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainWindow w;
  w.resize(800, 600);

  QVBoxLayout layout(&w);

  ChatBubble received_bubble("Hello! Super long long long ~~~~~~~~ word", &w);
  ChatBubble sent_bubble("Hi there Waaaaaaaaaaaaaaaaaaaaaaaaa!", &w);
  ChatBubble sent_bubble2("Hi there Waaaaaaaaaaaaaaaaaaaaaaaaa!", &w);

  layout.addWidget(&received_bubble, 0, Qt::AlignLeft);
  layout.addWidget(&sent_bubble, 0, Qt::AlignRight);
  layout.addWidget(&sent_bubble2, 0, Qt::AlignRight);

  w.show();

  received_bubble.Init(Qt::AlignLeft);
  sent_bubble.Init(Qt::AlignRight);
  sent_bubble2.Init(Qt::AlignRight);

  return app.exec();
}
