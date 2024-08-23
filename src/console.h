// console.h
#ifndef CONSOLE_H
#define CONSOLE_H

#include <QTextEdit>
#include <QScrollBar>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class Console : public QWidget
{
    Q_OBJECT

public:
    explicit Console(QWidget *parent = nullptr);
    QTextEdit* getConsoleTextEdit() { return consoleTextEdit; } // Add this method

public slots:
    void appendText(const QString &text);

private:
    QTextEdit *consoleTextEdit;
    bool isScrollBarAtBottom() const;
};

#endif // CONSOLE_H
