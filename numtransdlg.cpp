#include "numtransdlg.h"

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>


NumTransdlg::NumTransdlg(QWidget *parent)
    : QDialog(parent)
{
    QBoxLayout* mainLayout = new QVBoxLayout(this);
    QGridLayout* editLayout = new QGridLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    QLabel* decLabel = new QLabel("十進位");
    QLabel* hexLabel = new QLabel("十六進位");
    QLabel* binLabel = new QLabel("二進位");

    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    editLayout->addWidget(decLabel, 0, 0);
    editLayout->addWidget(decEdit, 0, 1);
    editLayout->addWidget(hexLabel, 1, 0);
    editLayout->addWidget(hexEdit, 1, 1);
    editLayout->addWidget(binLabel, 2, 0);
    editLayout->addWidget(binEdit, 2, 1);

    QPushButton* exitButton = new QPushButton("結束");
    buttonLayout->addStretch();
    buttonLayout->addWidget(exitButton);

    connect(exitButton, SIGNAL(clicked()), SLOT(accept())); //結束信號
    connect(decEdit, SIGNAL(textChanged(const QString&)), this, SLOT(decChanged(const QString&)));
    connect(hexEdit, SIGNAL(textChanged(const QString&)), this, SLOT(hexChanged(const QString&)));
    connect(binEdit, SIGNAL(textChanged(const QString&)), this, SLOT(binChanged(const QString&)));
}

NumTransdlg::~NumTransdlg() = default;


void NumTransdlg::decChanged(const QString& newValue) {
    bool ok; //具路轉換是否成功
    int num = newValue.toInt(&ok, 10);
    if (ok) {
        hexEdit->setText(QString::number(num,16));
        binEdit->setText(QString::number(num,2));
    } else {
        hexEdit->setText("");
        binEdit->setText("");
    }
    qDebug() << decEdit->text();

}
void NumTransdlg::hexChanged(const QString& newValue) {
    bool ok; //具路轉換是否成功
    int num = newValue.toInt(&ok, 16);
    if (ok) {
        decEdit->setText(QString::number(num,10));
        binEdit->setText(QString::number(num,2));
    } else {
        decEdit->setText("");
        binEdit->setText("");
    }

}
void NumTransdlg::binChanged(const QString& newValue) {
    bool ok; //具路轉換是否成功
    int num = newValue.toInt(&ok, 2);
    if (ok) {
        hexEdit->setText(QString::number(num,16));
        decEdit->setText(QString::number(num,10));
    } else {
        hexEdit->setText("");
        decEdit->setText("");
    }

}
