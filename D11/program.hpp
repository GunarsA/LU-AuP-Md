#ifndef CQUEUE_H
#define CQUEUE_H

class Cqueue
{
private:
    char rinda[5];
    int garums;
    int pozicija;

public:
    // konstruktors
    Cqueue();
    // destruktors, kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu (ja likvidēšanas brīdī rinda nav tukša)
    ~Cqueue();
    // "Ielikt" - enqueue, kas pievieno rindai elementu, ja tā nav pilna
    void enqueue(char elements);
    // "Izņemt" - dequeue, kas izņem no rindas elementu un atgriež tā vērtību
    char dequeue();
    //  "CikElementu" - count, kas atgriež elementu skaitu rindā
    int count();
    // "VaiTukša" - isEmpty, kas noskaidro, vai rinda ir tukša.
    bool isEmpty();
};

#endif