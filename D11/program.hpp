#ifndef CQUEUE_H
#define CQUEUE_H

class Cqueue
{
private:
    char rinda[5];
    int garums;
    int pozicija;

public:
    Cqueue();
    ~Cqueue();
    void Ielikt(char elements);
    char Izņemt();
    int CikElementu();
    bool VaiTukša();
};

#endif