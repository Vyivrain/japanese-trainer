#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    hiraAlph = new Alphabet();

    randNum = qrand() % hiraAlph->getHiraganaAlphabetLength();
    character = new QLabel(hiraAlph->getHiraganaAlphabetChar(randNum), this);
    message = new QLabel("Press S to show pronunciation");
    pronunciationCharacter = new QLabel(hiraAlph->getHiraganaPronunciationChar(randNum));
    character->hide();
    pronunciationCharacter->hide();



    SetLabelFont(character, 40);
    SetLabelFont(message, 15);
    SetLabelFont(pronunciationCharacter, 40);
    setMyPalette();

    restart = new QPushButton("Another one?");
    restart->hide();
    this->setAutoFillBackground(true);
    this->setPalette(*palette);

    alph_pron = new QPushButton("Alphabet to pronunciation");
    pron_alph = new QPushButton("Pronunciation to alphabet");

    qvb = new QVBoxLayout(this);
    qvb->addWidget(alph_pron);
    qvb->addWidget(pron_alph);

    connect(alph_pron, SIGNAL(clicked()), this, SLOT(SetCharToPron()));
    connect(pron_alph, SIGNAL(clicked()), this, SLOT(SetPronToChar()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::SetLabelFont(QLabel* l, int size)
{
    QFont font = l->font();
    font.setPointSize(size);
    font.setBold(true);
    l->setFont(font);
}

void Widget::setMyPalette()
{
    palette = new QPalette();
    palette->setColor(QPalette::Background, Qt::white);
}

void Widget::restartAlphToPron()
{
    randNum = qrand() % hiraAlph->getHiraganaAlphabetLength();
    character->setText(hiraAlph->getHiraganaAlphabetChar(randNum));
    pronunciationCharacter->setText(hiraAlph->getHiraganaPronunciationChar(randNum));
    pronunciationCharacter->hide();
    disconnect(restart, SIGNAL(clicked()), this, SLOT(restartApp()));
    restart->hide();
}

void Widget::restartPronToAlph()
{
    randNum = qrand() % hiraAlph->getHiraganaAlphabetLength();
    character->setText(hiraAlph->getHiraganaAlphabetChar(randNum));
    character->hide();
    pronunciationCharacter->setText(hiraAlph->getHiraganaPronunciationChar(randNum));
    disconnect(restart, SIGNAL(clicked()), this, SLOT(restartApp()));
    restart->hide();
}

void Widget::SetCharToPron()
{
    pronunciationCharacter->hide();
    character->show();
    alph_pron->hide();
    pron_alph->hide();
    qvb->addWidget(character, 0, Qt::AlignHCenter);
    qvb->addWidget(message, 0, Qt::AlignHCenter);
    qvb->addWidget(pronunciationCharacter, 0, Qt::AlignHCenter);
    qvb->addWidget(restart, 0, Qt::AlignHCenter);
    disconnect(alph_pron, SIGNAL(clicked()), this, SLOT(SetCharToPron()));
    disconnect(pron_alph, SIGNAL(clicked()), this, SLOT(SetPronToChar()));
    mode = true;
}

void Widget::SetPronToChar()
{
    character->hide();
    pronunciationCharacter->show();
    alph_pron->hide();
    pron_alph->hide();
    qvb->addWidget(pronunciationCharacter, 0, Qt::AlignHCenter);
    qvb->addWidget(message, 0, Qt::AlignHCenter);
    qvb->addWidget(character, 0, Qt::AlignHCenter);
    qvb->addWidget(restart, 0, Qt::AlignHCenter);
    disconnect(alph_pron, SIGNAL(clicked()), this, SLOT(SetCharToPron()));
    disconnect(pron_alph, SIGNAL(clicked()), this, SLOT(SetPronToChar()));
    mode = false;
}

void Widget::keyReleaseEvent(QKeyEvent *key_event)
{

}

void Widget::restartApp()
{
    if(mode)
    {
        restartAlphToPron();
    }
    else
    {
       restartPronToAlph();
    }
}

void Widget::keyPressEvent(QKeyEvent *key_event)
{
    if(key_event->key() == Qt::Key_S)
    {
        if( mode )
            pronunciationCharacter->show();
        else
            character->show();
        restart->show();
        connect(restart, SIGNAL(clicked()), this, SLOT(restartApp()));
    }
}


