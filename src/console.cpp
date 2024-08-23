// console.cpp
#include "console.h"

Console::Console(QWidget *parent) : QWidget(parent)
{
    consoleTextEdit = new QTextEdit(this);
    consoleTextEdit->setReadOnly(true);
    consoleTextEdit->setFixedHeight(150); // adjust the height as needed

    QLabel *consoleLabel = new QLabel("<b>Console</b>", this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(consoleLabel);
    layout->addWidget(consoleTextEdit);

    setLayout(layout);
}

void Console::appendText(const QString &text)
{
    consoleTextEdit->append(text);
    consoleTextEdit->verticalScrollBar()->setValue(consoleTextEdit->verticalScrollBar()->maximum()); // Always scroll to the bottom
}

bool Console::isScrollBarAtBottom() const
{
    return consoleTextEdit->verticalScrollBar()->value() == consoleTextEdit->verticalScrollBar()->maximum();
}
