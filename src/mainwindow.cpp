#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <iostream>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize() {
    this->connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));
    this->connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(onMessageChanged()));
    this->setWindowTitle("치즈는 치즈치즈해! > _<)");
    ui->statusBar->showMessage("Hello, World! ;)");
}

void MainWindow::onPushButtonClicked()
{
    auto message = ui->textEdit->toPlainText();
    auto result  = QMessageBox::information(
                      this,
                      tr("입력 확인"),
                      tr("입력하신 메시지는 %1 입니다").arg(message),
                      QMessageBox::Ok | QMessageBox::Cancel
                  );

    if (result == QMessageBox::Cancel) {
        this->makeAMess();
    }
}

void MainWindow::onMessageChanged()
{
    // TODO: 뭐 하지이..
}

void MainWindow::makeAMess()
{
    auto result = QMessageBox::critical(
                      this,
                      tr("우악! 이게 뭐야!"), tr("오류 났잖아요! 어떻게 해줄 거에요!"),
                      QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Help
                  );

    switch (result) {
        case QMessageBox::Abort:
            std::cerr << "흥입니다" << std::endl;
            std::abort();
        case QMessageBox::Retry:
            this->makeAMess();
            break;
        case QMessageBox::Help:
            QMessageBox::information(this, tr("알았어요"), tr("이번 한 번만 특별히 봐 줄게요.\n앞으로는 조심하도록 해요."));
            break;
        default:
            break;
    }
}
