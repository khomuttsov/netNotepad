#include "texteditor.h"

textEditor::textEditor(QWidget *parent) : QPlainTextEdit(parent)
{

}

void textEditor::keyPressEvent(QKeyEvent *e)
{
    int archor = this->textCursor().anchor();
    if (archor == this->textCursor().position())
        archor = -1;
    if (QApplication::keyboardModifiers().testFlag(Qt::ControlModifier) == true && e->key() == Qt::Key_Z)
        return;
    emit keyPress(e, archor);
    QPlainTextEdit::keyPressEvent(e);
}

