#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit,SIGNAL(textEdited(QString)),this,SLOT(poisk()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_clicked(){
    QString open=QFileDialog::getOpenFileName(this, tr("Open File"), "","Text File (*.txt)");
    QFile file(open);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString str=stream.readAll();
        ui->textBrowser->setText(str);
        file.close();
    }
    ui->lineEdit->setText("");
}

void MainWindow::on_clear_clicked(){
    ui->textBrowser->clear();
}

void MainWindow::poisk(){
    QList<QTextEdit::ExtraSelection> select;
    ui->textBrowser->moveCursor(QTextCursor::Start);
    int i=0;
    QString str=ui->lineEdit->text();
    while(ui->textBrowser->find(str, NULL)){
             QTextEdit::ExtraSelection extra_sel;
             extra_sel.format.setBackground(QColor(Qt::green));
             extra_sel.cursor = ui->textBrowser->textCursor();
             select.append(extra_sel);
             i++;
         }
    ui->Sovpadeniya->setText("Найдено "+QString::number(i)+" совпадений.");
    ui->textBrowser->setExtraSelections(select);
    ui->textBrowser->moveCursor(QTextCursor::EndOfLine);
}
void MainWindow::closeEvent(QCloseEvent *event){
    event->ignore();
    if (QMessageBox::Yes==QMessageBox::question(this,"Выход", "Уверены?", QMessageBox::Yes|QMessageBox::No)){
        event->accept();
    }
}
