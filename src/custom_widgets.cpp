#include "custom_widgets.h"

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QLayout>
#include <QSplitter>
#include <QRegularExpression>
#include <QRegExp>

widget_unit::widget_unit(QWidget *parent)
    :QWidget(parent)
{

}

widget_filepath::widget_filepath(QWidget *parent, QString str_label, QString dir, QString str_suffix)
    :widget_unit(parent)
{
    m_label = new QLabel(str_label, this);
    m_button = new QPushButton("search", this);
    m_lineedit = new QLineEdit(this);
    m_suffix = str_suffix;
    m_dir = dir;

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    QHBoxLayout* hlayout = new QHBoxLayout(this);

    vlayout->setContentsMargins(5, 1, 5, 1);

    hlayout->addWidget(m_lineedit);
    hlayout->addWidget(m_button);
    hlayout->setSpacing(5);

    vlayout->addWidget(m_label);
    vlayout->addLayout(hlayout);

    connect(m_button, &QPushButton::clicked, this, [&](){

        QString str = QFileDialog::getOpenFileName(this, "search file", m_dir, m_suffix);
        if(str != ""){
            m_lineedit->setText(str);
            m_lineedit->setToolTip(str);
        }
    });
}

widget_filepath_save::widget_filepath_save(QWidget *parent, QString str_label, QString dir, QString str_suffix)
    :widget_unit(parent)
{
    m_label = new QLabel(str_label, this);
    m_button = new QPushButton("search", this);
    m_lineedit = new QLineEdit(this);
    m_suffix = str_suffix;
    m_dir = dir;

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    QHBoxLayout* hlayout = new QHBoxLayout(this);

    vlayout->setContentsMargins(5, 1, 5, 1);

    hlayout->addWidget(m_lineedit);
    hlayout->addWidget(m_button);
    hlayout->setSpacing(5);

    vlayout->addWidget(m_label);
    vlayout->addLayout(hlayout);

    connect(m_button, &QPushButton::clicked, this, [&](){

        QString str = QFileDialog::getSaveFileName(this, "search file", m_dir, m_suffix);
        if(str != ""){
            m_lineedit->setText(str);
            m_lineedit->setToolTip(str);
        }
    });
}


widget_folderpath::widget_folderpath(QWidget *parent, QString str_label, QString dir)
    :widget_unit(parent)
{
    m_label = new QLabel(str_label, this);
    m_button = new QPushButton("search", this);
    m_lineedit = new QLineEdit(this);
    m_dir = dir;

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    QHBoxLayout* hlayout = new QHBoxLayout(this);

    vlayout->setContentsMargins(5, 1, 5, 1);

    hlayout->addWidget(m_lineedit);
    hlayout->addWidget(m_button);
    hlayout->setSpacing(5);

    vlayout->addWidget(m_label);
    vlayout->addLayout(hlayout);

    connect(m_button, &QPushButton::clicked, this, [&](){

        QString str = QFileDialog::getExistingDirectory(this, "set dirtory", m_dir);
        if(str != ""){
            m_lineedit->setText(str);
            m_lineedit->setToolTip(str);
        }
    });
}

widget_checkbox::widget_checkbox(QWidget *parent, QString str_label, QString str_chekcbox, bool flag)
    :widget_unit(parent)
{
    m_label = new QLabel(str_label, this);
    m_checkbox = new QCheckBox(str_chekcbox, this);

    m_checkbox->setChecked(flag);

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->setContentsMargins(5, 1, 5, 1);

    vlayout->addWidget(m_label);
    vlayout->addWidget(m_checkbox);
}

widget_combobox::widget_combobox(QWidget *parent, QString str_label, QStringList combobox_list, int init_idx)
    :widget_unit(parent)
{
    m_label = new QLabel(str_label, this);
    m_combobox = new QComboBox(this);
    for(auto str : combobox_list){
        m_combobox->addItem(str);
    }

    m_combobox->setCurrentIndex(init_idx);

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->setContentsMargins(5, 1, 5, 1);

    vlayout->addWidget(m_label);
    vlayout->addWidget(m_combobox);
}

widget_lineedit::widget_lineedit(QWidget *parent, QString str_label, QString regex)
    :widget_unit(parent)
{
    m_label = new QLabel(str_label, this);
    m_lineedit = new QLineEdit(this);

    QRegularExpression regex_(regex);
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex_, m_lineedit);
    m_lineedit->setValidator(validator);

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->setContentsMargins(5, 1, 5, 1);

    vlayout->addWidget(m_label);
    vlayout->addWidget(m_lineedit);
}


