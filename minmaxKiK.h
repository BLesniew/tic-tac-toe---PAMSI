#ifndef MINMAXKIK_H
#define MINMAXKIK_H

#include "wyswietlanie.h"
#define MAX_GLEBOKOSC -1                                                                                    //maksymalna glebokosc, dla liczb ujemnych liczy cala gre do konca

struct ruch                                                                                                //struktura pomocnicza
{
	int rzad, kolumna;
};


bool czyRuch(int N,Znak ***plansza);                                                                        //funkcja sprawdzajaca czy na planszy jest puste pole
int ewaluacja(int N,Znak ***plansza,int ileWygrywa);                                                        //zwraca liczbe dodatnia jezeli X wygrywa. ujemna jezeli O wygrywa (tym blizej zera
                                                                                                            //im wieksza glebokosc) oraz 0 dla remisu lub jezeli osiagnieto glebokosc_max
int minimax(int N, int ileWygrywa, Znak ***plansza, int glebokosc, bool czyRuchGracza,int wartoscWyzej);    //algorytm rekurencyjny badajacy wartosc wszystkich mozliwych ruchow
                                                                                                            //(zaimplementowano alfa-beta ciecia)
ruch znajdzNajlepszyRuch(int N,int ileWygrywa,Znak ***plansza,bool czyRuchX);                               //gdy czyRuchX to prawda szuka najlepszego ruchu dla X, w przeciwnym wypadku dla O


#endif // MINMAXKIK_H
