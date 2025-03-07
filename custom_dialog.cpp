#include "custom_dialog.h"

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QLayout>
#include <QSplitter>
#include <QMessageBox>

#include "regex.h"
#include "custom_widgets.h"

custom_dialog::custom_dialog(QString title, QWidget *parent)
    : QDialog{parent}
{
    this->setWindowTitle(title);
    this->setMinimumSize(QSize(400, 250));
    this->resize(QSize(600, 400));

    m_scrollarea = new QScrollArea(this);
    m_scrollarea->setWidgetResizable(true);

    m_scrollarea->setStyleSheet(QString::fromUtf8("QScrollArea{border:1px solid rgba(0,0,0,0.5)}"));

    m_scrollwidget = new QWidget();
    m_scrollarea->setWidget(m_scrollwidget);

    m_textedit = new QTextEdit("empty", this);
    m_textedit->setMinimumWidth(100);
    m_textedit->setMaximumWidth(300);
    m_textedit->setStyleSheet(QString::fromUtf8("QTextEdit{border:1px solid rgba(0,0,0,0.5)}"));

    m_ok_button = new QPushButton("OK", this);
    m_cancel_button = new QPushButton("Cancel", this);

    connect(m_ok_button, &QPushButton::clicked, this, &custom_dialog::ok_button_clicked);
    connect(m_cancel_button, &QPushButton::clicked, this, &QWidget::close);

    QHBoxLayout* btn_layout = new QHBoxLayout();
    QSpacerItem* spacer_btn_left = new QSpacerItem(20, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);
    btn_layout->addSpacerItem(spacer_btn_left);
    btn_layout->addWidget(m_ok_button);
    btn_layout->addWidget(m_cancel_button);

    QSplitter* upper_splitter = new QSplitter();
    upper_splitter->addWidget(m_scrollarea);
    upper_splitter->addWidget(m_textedit);

    upper_splitter->setStretchFactor(0,4);
    upper_splitter->setStretchFactor(1,1);

    QVBoxLayout* total_vlayout = new QVBoxLayout(this);
    total_vlayout->addWidget(upper_splitter);
    total_vlayout->addLayout(btn_layout);

    this->setLayout(total_vlayout);
}

void custom_dialog::ok_button_clicked()
{
    run();
}


regist_dlg::regist_dlg(QString title, QWidget *parent)
    :custom_dialog(title, parent)
{
    QVBoxLayout* vlayout = new QVBoxLayout(m_scrollwidget);
    vlayout->setSpacing(0);
    vlayout->setContentsMargins(0,2,0,2);

    QMap<QString, QString> file_suffix_map ={
      {"xml", "xml(*.xml);;all(*.*)"},
      {"tif", "tif(*.tif *.tiff);;all(*.*)"},
    };

    for(auto label : {"master xml", "master tif", "slave xml", "slave tif"})
    {
        QString suffix = file_suffix_map[QString(label).right(3)];
        widget_filepath* wgt1 = new widget_filepath(this, label, "", suffix);
        vlayout->addWidget(wgt1);
    }

    widget_lineedit* winsize = new widget_lineedit(this, "window size", regex_numer_n);
    vlayout->addWidget(winsize);

    widget_lineedit* winnum = new widget_lineedit(this, "window numbers", regex_numer_n);
    vlayout->addWidget(winnum);

    widget_lineedit* snr = new widget_lineedit(this, "snr", "[0-9]*");
    vlayout->addWidget(snr);

    widget_filepath_save* regis_xml = new widget_filepath_save(this, "output regist.xml", "", "xml(*.xml);;all(*.*)");
    vlayout->addWidget(regis_xml);

    QSpacerItem* spacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vlayout->addSpacerItem(spacer);
    m_scrollwidget->setLayout(vlayout);

    m_textedit->setText("there is a co-registration dialog");
}

void regist_dlg::run()
{
    // qDebug()<<"regist_widget::run";
    QMessageBox::information(this, "information", "regist_dlg::run() is run");
}


empty_dlg::empty_dlg(QString title, QWidget *parent)
    :custom_dialog(title, parent)
{
    m_textedit->setText("there is a empty dialog.");
}

void empty_dlg::run()
{
    // qDebug()<<"regist_widget::run";
    QMessageBox::information(this, "information", "regist_dlg::run() is run");
}
