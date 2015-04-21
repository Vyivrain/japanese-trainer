#ifndef ALPHABET_H
#define ALPHABET_H

#include <QString>
#include <QVector>


class Alphabet
{
public:
    Alphabet();
    QString getHiraganaAlphabetChar(int pos);
    const char* getHiraganaPronunciationChar(int pos);
    int getHiraganaAlphabetLength();
private:
    void InitHiraganaAlphabet();
    void InitHiraganaPronunciation();
private:
   QString hiragana_alphabet;
   QVector<const char*> hiragana_pronunciation;
};

#endif // Alphabet_H
