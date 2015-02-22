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

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void InitAlphabet();
    void SetLabelFont(QLabel* l, int size);
    void setMyPalette();
    void InitTranslation();
protected:
    void keyPressEvent(QKeyEvent *key_event);
    void keyReleaseEvent(QKeyEvent *key_event);
private slots:
    void restartApp();
private:
    Ui::Widget *ui;
    QLabel* character;
    QLabel* message;
    QLabel* translationCharacter;
    QVBoxLayout* qvb;
    QString alphabet;
    QPalette* palette;
    QVector<const char*> translation;
    QPushButton* restart;
    int randNum;
};

#endif // WIDGET_H
