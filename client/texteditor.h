#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QApplication>
#include <QDebug>

class textEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit textEditor(QWidget *parent = 0);

signals:
    void keyPress(QKeyEvent *e, int as);
public slots:
    void keyPressEvent(QKeyEvent *e);
};

#endif // TEXTEDITOR_H
