#include "mainwindow.h"

#include <QPushButton>
#include <QListWidgetItem>

#include "ui_mainwindow.h"
#include "chat_item.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      ui_(new Ui::MainWindow) {
  ui_->setupUi(this);

  connect(ui_->send_button, &QPushButton::clicked, this, [=](){
    ChatItem *chat_item = new ChatItem(ui_->textEdit->toPlainText(), this);
    QListWidgetItem *item = new QListWidgetItem(ui_->talk_area);
    item->setSizeHint(chat_item->GetActualSize());
    ui_->talk_area->setItemWidget(item, chat_item);
    // ui_->talk_area->addItem(item);
    ui_->textEdit->clear();
  });
}

MainWindow::~MainWindow() {
  delete ui_;
}
