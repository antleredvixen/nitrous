#ifndef STEMPLAYERDETECTOR_H
#define STEMPLAYERDETECTOR_H

#include <QDateTime>
#include <QTextEdit>
#include <libusb.h>

class StemPlayerDetector
{
public:
    void checkStemPlayerConnection();
    void checkForStemPlayer(bool &stemPlayerConnected);
    void checkStemPlayerConnection(QTextEdit* consoleWindow);
    void checkForStemPlayer(bool &stemPlayerConnected, QTextEdit* consoleWindow);
};

#endif // STEMPLAYERDETECTOR_H
