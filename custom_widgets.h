#ifndef CUSTOM_WIDGETS_H
#define CUSTOM_WIDGETS_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>

/// @brief 组件基类
class widget_unit : public QWidget
{
    Q_OBJECT
public:
    explicit widget_unit(QWidget *parent);
};

/// @brief label + lineedit + button 组件, 获取(已存在的)文件地址
class widget_filepath : public widget_unit
{
    Q_OBJECT
public:
    explicit widget_filepath(QWidget *parent, QString label, QString dir, QString suffix);
    QString m_suffix;
    QString m_dir;

    QPushButton* m_button;
    QLabel* m_label;
    QLineEdit* m_lineedit;
};

/// @brief label + lineedit + button 组件, 选择要保存的文件地址
class widget_filepath_save : public widget_unit
{
    Q_OBJECT
public:
    explicit widget_filepath_save(QWidget *parent, QString label, QString dir, QString suffix);
    QString m_suffix;
    QString m_dir;

    QPushButton* m_button;
    QLabel* m_label;
    QLineEdit* m_lineedit;
};

/// @brief label + lineedit + button 组件, 获取(已存在的)文件夹地址
class widget_folderpath : public widget_unit
{
    Q_OBJECT
public:
    explicit widget_folderpath(QWidget *parent, QString label, QString dir);
    QString m_dir;

    QPushButton* m_button;
    QLabel* m_label;
    QLineEdit* m_lineedit;
};

/// @brief label + checkbox 组件,
class widget_checkbox : public widget_unit
{
    Q_OBJECT
public:
    explicit widget_checkbox(QWidget *parent, QString label, QString chekcbox, bool flag = false);

    QLabel* m_label;
    QCheckBox* m_checkbox;
};

/// @brief label + combobox 组件
class widget_combobox : public widget_unit
{
    Q_OBJECT
public:
    explicit widget_combobox(QWidget *parent, QString label, QStringList combobox_list, int init_idx = 0);

    QLabel* m_label;
    QComboBox* m_combobox;
};

/// @brief label + lineedit + 正则 组件
class widget_lineedit : public widget_unit
{
    Q_OBJECT
public:
    explicit widget_lineedit(QWidget *parent, QString label, QString regex);

    QLabel* m_label;
    QLineEdit* m_lineedit;
};



#endif // CUSTOM_WIDGETS_H
