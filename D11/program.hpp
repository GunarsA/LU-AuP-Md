#ifndef CQUEUE_H
#define CQUEUE_H

class Cqueue
{
private:
    char rinda[5];
    int garums;
    int pozicija;

public:
    // Cqueue();
    // Funkcija Cqueue() -
    // Konstruē Burtu virknes objektu.
    Cqueue();

    // ~Cqueue();
    // Funkcija ~Cqueue().
    // paziņo par objekta likvidēšanu un likvidēto elementu skaitu (ja
    // likvidēšanas brīdī rinda nav tukša)
    ~Cqueue();

    // void enqueue(char elements);
    // Funkcija enqueue(elements) -
    // pievieno rindai elementu (elements), ja tā nav pilna. Pretējā gadijuma
    // izvada paziņujumu, ka elements netika pievienots. Ja elements nav lielais
    // vai mazais latīņu alfabēta burts bez diaktrijas zīmēm, tas netiek
    // pievienots un tiek izvadīts paziņojums, ka elements netika pievienots.
    void enqueue(char elements);

    // char dequeue();
    // Funkcija dequeue() -
    // izņem no rindas elementu un atgriež tā vērtību. Ja rinda ir tukša izvada
    // paziņojumu, ka elements netika izņemts.
    char dequeue();

    // int count();
    // Funkcija count() -
    // atgriež elementu skaitu rindā.
    int count();

    // bool isEmpty();
    // Funkcija isEmpty() -
    // noskaidro, vai rinda ir tukša un atgriež bool vertību, kas ir patiesa,
    // ja rinda ir tukša.
    bool isEmpty();
};

#endif