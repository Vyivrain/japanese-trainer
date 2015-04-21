#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QPainter>
#include <QStaticText>
#include <iostream>
#include <QString>
#include <QLabel>
#include <QTime>
#include <QDebug>
#include <QVBoxLayout>
#include <QFont>
#include <QPalette>
#include <QVector>
#include <QKeyEvent>
#include <QPushButton>

#include "alphabet.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void SetLabelFont(QLabel* l, int size);
    void setMyPalette();
    void InitLabels();
    void restartAlphToPron();
    void restartPronToAlph();
protected:
    void keyPressEvent(QKeyEvent *key_event);
    void keyReleaseEvent(QKeyEvent *key_event);
private slots:
    void restartApp();
    void SetCharToPron();
    void SetPronToChar();
private:
    Ui::Widget *ui;

    QLabel* character;
    QLabel* message;
    QLabel* pronunciationCharacter;

    QVBoxLayout* qvb;

    QPalette* palette;
    QPushButton* restart;
    int randNum;

    bool mode;
    QPushButton* alph_pron;
    QPushButton* pron_alph;

    Alphabet* hiraAlph;
};

#endif // WIDGET_H
