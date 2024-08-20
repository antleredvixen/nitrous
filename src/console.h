// console.h
#ifndef CONSOLE_H
#define CONSOLE_H

#include <QTextEdit>
#include <QScrollBar>

class Console : public QTextEdit
{
    Q_OBJECT

public:
    explicit Console(QWidget *parent = nullptr);

public slots:
    void appendText(const QString &text);

private:
    bool isScrollBarAtBottom() const;
};

#endif // CONSOLE_H
