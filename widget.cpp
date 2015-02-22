#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    InitAlphabet();
    InitTranslation();

    randNum = qrand() % alphabet.length();
    character = new QLabel(QString(alphabet[randNum]), this);
    message = new QLabel("Press space to show translation");
    translationCharacter = new QLabel(translation[randNum]);
    translationCharacter->hide();
    SetLabelFont(character, 40);
    SetLabelFont(message, 15);
    SetLabelFont(translationCharacter, 40);
    setMyPalette();

    restart = new QPushButton("Another one?");
    restart->hide();

    qvb = new QVBoxLayout(this);
    qvb->addWidget(character, 0, Qt::AlignHCenter);
    qvb->addWidget(message, 0, Qt::AlignHCenter);
    qvb->addWidget(translationCharacter, 0, Qt::AlignHCenter);
    qvb->addWidget(restart, 0, Qt::AlignHCenter);

    this->setAutoFillBackground(true);
    this->setPalette(*palette);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::InitAlphabet()
{
    alphabet = "あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわん";
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

void Widget::InitTranslation()
{
   translation = {
       "A",
       "I",
       "U",
       "E",
       "O",
       "KA",
       "KI",
       "KU",
       "KE",
       "KO",
       "SA",
       "SHI",
       "SU",
       "SE",
       "SO",
       "TA",
       "CHI",
       "TSU",
       "TE",
       "TO",
       "NA",
       "NI",
       "NU",
       "NE",
       "NO",
       "HA",
       "HI",
       "FU",
       "HE",
       "HO",
       "MA",
       "MI",
       "MU",
       "ME",
       "MO",
       "YA",
       "YU",
       "YO",
       "RA",
       "RI",
       "RU",
       "RE",
       "RO",
       "WA",
       "N"
   };
}

void Widget::keyReleaseEvent(QKeyEvent *key_event)
{
}

void Widget::restartApp()
{
    randNum = qrand() % alphabet.length();
    character->setText(QString(alphabet[randNum]));
    translationCharacter->setText(QString(translation[randNum]));
    translationCharacter->hide();
    disconnect(restart, SIGNAL(clicked()), this, SLOT(restartApp()));
    restart->hide();
}

void Widget::keyPressEvent(QKeyEvent *key_event)
{
    if(key_event->key() == Qt::Key_S)
    {
        translationCharacter->show();
        restart->show();
        connect(restart, SIGNAL(clicked()), this, SLOT(restartApp()));
    }
}
