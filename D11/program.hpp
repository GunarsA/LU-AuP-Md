#ifndef CQUEUE_H
#define CQUEUE_H

class Cqueue
{
public:
    char rinda[5];
    int garums;
    int pozicija;

public:
    // konstruktors
    Cqueue();
    // destruktors, kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu (ja likvidēšanas brīdī rinda nav tukša)
    ~Cqueue();
    // "Ielikt" - enqueue, kas pievieno rindai elementu, ja tā nav pilna
    void Ielikt(char elements);
    // "Izņemt" - dequeue, kas izņem no rindas elementu un atgriež tā vērtību
    char Izņemt();
    //  "CikElementu" - count, kas atgriež elementu skaitu rindā
    int CikElementu();
    // "VaiTukša" - isEmpty, kas noskaidro, vai rinda ir tukša.
    bool VaiTukša();
};

#endif