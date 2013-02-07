#ifndef HELPVIEWER_H
#define HELPVIEWER_H

#include <QDialog>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QTextDocument>

class HelpViewer : public QDialog
{
    Q_OBJECT
public:
    explicit HelpViewer(const QString title, QWidget *parent = 0);

private slots:
    void onCloseClicked();

private:
    QVBoxLayout *m_vbox;
    QTextBrowser *m_viewer;
    QPushButton *m_closeButton;

};

#endif // HELPVIEWER_H