#include "wyswietlanie.h"

void wyswietlKiK(int N,Znak **plansza)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(plansza[i][j]==X)
            {
                std::cout<<'X';
            }
            else if(plansza[i][j]==O)
            {
                std::cout<<'O';
            }
            else
            {
                std::cout<<' ';
            }
            if(j<N-1)
            {
                std::cout<<"|";
            }
        }
        if(i<N-1)
        {
            std::cout<<"\n";
            for(int j=0;j<N;j++)
                std::cout<<"--";
        }

        std::cout<<"\n";
    }
    std::cout<<"\n\n";
}
