#include "minmaxKiK.h"

bool czyRuch(int N,Znak ***plansza)
{
	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			if ((*plansza)[i][j]==blank)
				return true;
	return false;
}


int ewaluacja(int N,Znak ***plansza, int ileWygrywa)
{
    int licznik;
	for (int rzad = 0; rzad<N; rzad++)                                          //czy ktoras strona wygrala w rzedzie
	{
	    for(int i=0;i+ileWygrywa-1<N;i++)
        {
            licznik=1;
            for(int j=i+1;j<ileWygrywa+i;j++)
            {
                if((*plansza)[rzad][j]==(*plansza)[rzad][i])
                    licznik++;
            }
            if(licznik==ileWygrywa)
            {
                if((*plansza)[rzad][i]==X)
                    return N*N+1;
                else if((*plansza)[rzad][i]==O)
                    return -(N*N+1);
            }
        }
	}
	for (int kolumna = 0; kolumna<N; kolumna++)                                   //czy ktoras strona wygrala w kolumnie
	{
		for(int i=0;i+ileWygrywa-1<N;i++)
        {
            licznik=1;
            for(int j=i+1;j<ileWygrywa+i;j++)
            {
                if((*plansza)[j][kolumna]==(*plansza)[i][kolumna])
                    licznik++;
            }
            if(licznik==ileWygrywa)
            {
                if((*plansza)[i][kolumna]==X)
                    return N*N+1;
                else if((*plansza)[i][kolumna]==O)
                    return -(N*N+1);
            }
        }
	}
	for(int i=0;i+ileWygrywa-1<N;i++)                                           //czy ktoras strona wygrala na przekatnej schodzacej w prawo i w dol
    {
        for(int j=0;j+ileWygrywa-1<N;j++)
        {
            licznik=1;
            for(int k=1;k<ileWygrywa;k++)
            {
                if((*plansza)[i+k][j+k]==(*plansza)[i][j])
                    licznik++;
            }

            if(licznik==ileWygrywa)
            {
                if((*plansza)[i][j]==X)
                    return N*N+1;
                else if((*plansza)[i][j]==O)
                    return -(N*N+1);
            }
        }
    }

    for(int i=0;i+ileWygrywa-1<N;i++)                                          //czy ktoras strona wygrala na przekatnej schodzacej w prawo i w dol
    {
        for(int j=0;j+ileWygrywa-1<N;j++)
        {
            licznik=1;
            for(int k=1;k<ileWygrywa;k++)
            {
                if((*plansza)[i+ileWygrywa-1-k][j+k]==(*plansza)[i+ileWygrywa-1][j])
                    licznik++;
            }
            if(licznik==ileWygrywa)
            {
                if((*plansza)[i+ileWygrywa-1][j]==X)
                    return N*N+1;
                else if((*plansza)[i+ileWygrywa-1][j]==O)
                    return -(N*N+1);
            }
        }
    }
	return 0;
}

int minimax(int N,int ileWygrywa, Znak ***plansza, int glebokosc, bool czyRuchGracza,int wartoscWyzej)
{
	int punktacja = ewaluacja(N,plansza,ileWygrywa);

	if (punktacja == N*N+1)
		return punktacja-glebokosc;

	if (punktacja == -(N*N+1))
		return punktacja+glebokosc;

	if (czyRuch(N,plansza)==false||(MAX_GLEBOKOSC<=glebokosc&&MAX_GLEBOKOSC>0))
		return 0;

	if (czyRuchGracza)
	{
		int najlepszyWynik = -(N*N+2);

		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<N; j++)
			{
				if ((*plansza)[i][j]==blank)
				{
					(*plansza)[i][j] = X;                                                                           //wstawia znak X w dane pole, sprawdza wartosc tego ruchu i na koniec wraca do poprzedniego stanu planszy
                    int tmp = minimax(N,ileWygrywa,plansza, glebokosc+1, !czyRuchGracza,najlepszyWynik);
                    if(tmp>najlepszyWynik)
                    {
                        najlepszyWynik=tmp;
                        if(wartoscWyzej<=najlepszyWynik)                                                       //alfa-beta ciecia - jezeli nie ma sensu przeszukiwac pozostalych ruchow
                        {                                                                                      //zwracamy najlepszy dla X dotychczas
                            (*plansza)[i][j] = blank;
                            return najlepszyWynik;
                        }
                    }
					(*plansza)[i][j] = blank;
				}
			}
		}
		return najlepszyWynik;
	}
	else
	{
		int najgorszyWynik = N*N+2;         //najgorzy dla X wynik

		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<N; j++)
			{
				if ((*plansza)[i][j]==blank)
				{
					(*plansza)[i][j] = O;                                                                   //wstawia znak O w dane pole, sprawdza wartosc tego ruchu i na koniec wraca do poprzedniego stanu planszy
                    int tmp = minimax(N,ileWygrywa,plansza, glebokosc+1, !czyRuchGracza,najgorszyWynik);
                    if(tmp<najgorszyWynik)
                    {
                        najgorszyWynik=tmp;
                        if(wartoscWyzej>=najgorszyWynik)                                                    //alfa-beta ciecia - jezeli nie ma sensu przeszukiwac pozostalych ruchow
                        {                                                                                   //zwracamy najlepszy dla O dotychczas
                            (*plansza)[i][j] = blank;
                            return najgorszyWynik;
                        }
                    }
					(*plansza)[i][j] = blank;
				}
			}
		}
		return najgorszyWynik;
	}
}

ruch znajdzNajlepszyRuch(int N,int ileWygrywa,Znak ***plansza, bool czyRuchX)
{
    if(czyRuchX)
    {
        int najlepszaWartosc = -(N*N+2);
        ruch najlepszyRuch;
        najlepszyRuch.rzad = -1;
        najlepszyRuch.kolumna = -1;

        for (int i = 0; i<N; i++)
        {
            for (int j = 0; j<N; j++)
            {
                if ((*plansza)[i][j]==blank)
                {
                    (*plansza)[i][j] = X;
                    int wartoscRuchu = minimax(N,ileWygrywa,plansza, 1, false,-(N*N+2));

                    (*plansza)[i][j] = blank;

                    if (wartoscRuchu > najlepszaWartosc)
                    {
                        najlepszyRuch.rzad = i;
                        najlepszyRuch.kolumna = j;
                        najlepszaWartosc = wartoscRuchu;
                    }
                }
            }
        }
        return najlepszyRuch;                                                                 //zwraca najlepszy ruch dla X
    }
    else
    {
        int najlepszaWartosc = N*N+2;
        ruch najlepszyRuch;
        najlepszyRuch.kolumna=-1;
        najlepszyRuch.rzad=-1;
        for (int i = 0; i<N; i++)
        {
            for (int j = 0; j<N; j++)
            {
                if ((*plansza)[i][j]==blank)
                {
                    (*plansza)[i][j] = O;

                    int wartoscRuchu = minimax(N,ileWygrywa,plansza, 0, true,N*N+2);

                    (*plansza)[i][j] = blank;

                    if (wartoscRuchu < najlepszaWartosc)
                    {
                        najlepszyRuch.rzad = i;
                        najlepszyRuch.kolumna = j;
                        najlepszaWartosc = wartoscRuchu;
                    }
                }
            }
        }
        return najlepszyRuch;                                                               //zwraca najlepszy ruch dla O
    }

}
