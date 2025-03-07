#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBoxLayout>
#include <QSpacerItem>
#include <QPushButton>

#include "custom_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout* vlayout = new QVBoxLayout(ui->centralwidget);

    QPushButton* regist_button = new QPushButton("regist", this);
    vlayout->addWidget(regist_button);
    connect(regist_button, &QPushButton::clicked, this, [&](){
        regist_dlg* dlg = new regist_dlg("coreg");
        dlg->show();

    });

    QPushButton* empty_button = new QPushButton("empty", this);
    vlayout->addWidget(empty_button);
    connect(empty_button, &QPushButton::clicked, this, [&](){
        empty_dlg* dlg = new empty_dlg("empty");
        dlg->show();

    });

    QSpacerItem* spacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vlayout->addSpacerItem(spacer);
}

MainWindow::~MainWindow()
{
    delete ui;
}
