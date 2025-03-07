#ifndef CUSTOM_DIALOG_H
#define CUSTOM_DIALOG_H

#include <QWidget>
#include <QDialog>

#include <QScrollArea>
#include <QTextEdit>


class custom_dialog : public QDialog
{
    Q_OBJECT
public:
    explicit custom_dialog(QString title, QWidget *parent = nullptr);

    QScrollArea* m_scrollarea = nullptr;
    QWidget* m_scrollwidget = nullptr;
    QTextEdit* m_textedit = nullptr;
    QPushButton* m_ok_button = nullptr;
    QPushButton* m_cancel_button = nullptr;

    // virtual void init() = 0;
    virtual void run() = 0;
signals:

public slots:
    void ok_button_clicked();
};

/// @brief 示例, 配准功能
class regist_dlg : public custom_dialog
{
    Q_OBJECT
public:
    regist_dlg(QString title, QWidget *parent = nullptr);
    void run();
};

// @brief 示例, 配准功能
class empty_dlg : public custom_dialog
{
    Q_OBJECT
public:
    empty_dlg(QString title, QWidget *parent = nullptr);
    void run();
};

#endif // CUSTOM_DIALOG_H
