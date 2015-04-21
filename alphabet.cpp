#include "alphabet.h"

Alphabet::Alphabet()
{
    InitHiraganaAlphabet();
    InitHiraganaPronunciation();
}

QString Alphabet::getHiraganaAlphabetChar(int pos)
{
    return QString(hiragana_alphabet[pos]);
}

const char *Alphabet::getHiraganaPronunciationChar(int pos)
{
    return hiragana_pronunciation[pos];
}

int Alphabet::getHiraganaAlphabetLength()
{
    return hiragana_alphabet.length();
}

void Alphabet::InitHiraganaAlphabet()
{
    hiragana_alphabet = "あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわん";
}

void Alphabet::InitHiraganaPronunciation()
{
   hiragana_pronunciation = {
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
