// console.cpp
#include "console.h"

Console::Console(QWidget *parent) : QTextEdit(parent)
{
    setReadOnly(true);
    setFixedHeight(150); // adjust the height as needed
}

void Console::appendText(const QString &text)
{
    append(text);
    verticalScrollBar()->setValue(verticalScrollBar()->maximum()); // Always scroll to the bottom
}

bool Console::isScrollBarAtBottom() const
{
    return verticalScrollBar()->value() == verticalScrollBar()->maximum();
}
