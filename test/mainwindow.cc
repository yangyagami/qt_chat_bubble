#include "mainwindow.h"

#include <QPushButton>
#include <QListWidgetItem>
#include <QTimer>

#include "ui_mainwindow.h"
#include "chat_item.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      ui_(new Ui::MainWindow) {
  ui_->setupUi(this);

  connect(ui_->send_button, &QPushButton::clicked, this, [=](){
    ChatItem *send_chat_item = new ChatItem(ui_->textEdit->toPlainText(), this);
    send_chat_item->set_bubble_background_color(Qt::blue);
    send_chat_item->set_bubble_font_color(Qt::white);
    send_chat_item->set_head_img(QImage("head_example.png"));
    QListWidgetItem *send_item = new QListWidgetItem(ui_->talk_area);
    send_item->setSizeHint(send_chat_item->GetActualSize());
    ui_->talk_area->setItemWidget(send_item, send_chat_item);
    ui_->textEdit->clear();

    QTimer::singleShot(1300, this, [=](){
      send_chat_item->set_text("在上面的代码中，我们首先定义了一个包含三个顶点的 QPolygonF 对象，这些顶点定义了三角形的形状。然后，我们设置了绘制的填充颜色为蓝色，并使用 drawPolygon() 方法绘制三角形。您可以根据需要调整三角形的顶点位置和填充颜色，以及在绘图中绘制更复杂的形状。希望这个示例能帮助您开始在 Qt 中绘制三角形。");
      send_item->setSizeHint(send_chat_item->GetActualSize());
      ChatItem *recv_chat_item = new ChatItem("This is a simple reply", this, true);
      recv_chat_item->set_head_img(QImage("head_example.png"));
      QListWidgetItem *recv_item = new QListWidgetItem(ui_->talk_area);
      recv_item->setSizeHint(recv_chat_item->GetActualSize());
      ui_->talk_area->setItemWidget(recv_item, recv_chat_item);
    });
  });
}

MainWindow::~MainWindow() {
  delete ui_;
}
