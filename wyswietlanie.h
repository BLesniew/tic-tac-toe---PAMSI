#ifndef WYSWIETLANIE_H
#define WYSWIETLANIE_H

#include <iostream>

enum Znak {blank,X,O};                              //mozliwe wartosci w kazdym polu planszy

void wyswietlKiK(int N,Znak **plansza);             //funkcja wyswietlajaca obecny stan gry


#endif // WYSWIETLANIE_H
