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

    ui_->talk_area->scrollToBottom();
  });
}

MainWindow::~MainWindow() {
  delete ui_;
}
