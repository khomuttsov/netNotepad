#include "texteditor.h"

textEditor::textEditor(QWidget *parent) : QPlainTextEdit(parent)
{

}

void textEditor::keyPressEvent(QKeyEvent *e)
{
    emit keyPress(e);
    QPlainTextEdit::keyPressEvent(e);
}

