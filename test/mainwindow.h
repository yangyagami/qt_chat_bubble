#ifndef CHAT_BUBBLE_MAINWINDOW_H_
#define CHAT_BUBBLE_MAINWINDOW_H_

#include <QWidget>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QWidget {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
 private:
  Ui::MainWindow *ui_;
};

#endif  // CHAT_BUBBLE_MAINWINDOW_H_
