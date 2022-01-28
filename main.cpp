#include<iostream>
#include "wyswietlanie.h"
#include "minmaxKiK.h"



int main()
{
    Znak **plansza;
    char wybor,wybor3;
    int wybor2,wybor4;
    ruch najlepszyRuch;
    bool czyX=true;
    int N,ileWygrywa;


    do
    {
        czyX=true;
        std::cout<<"Choose gamemode:\n";
        std::cout<<"c - AI vs AI, watch the battle\n";
        std::cout<<"p - YOU vs AI, try not to lose\n";
        std::cout<<"v - player1 vs player2, compete with your friend\n";
        std::cout<<"q - quit\n";
        std::cin>>wybor;
        switch(wybor)
        {
            case 'p':
            std::cout<<"How many rows and columns should the game have?\n";
            std::cin>>N;
            std::cout<<"How many in a line should win?\n";
            std::cin>>ileWygrywa;
            plansza = new Znak *[N];
            for(int i=0;i<N;i++)
            {
                plansza[i] = new Znak[N];
                for(int j=0;j<N;j++)
                    plansza[i][j]=blank;
            }
            wyswietlKiK(N,plansza);
            std::cout<<"Who should start? (m - me, a - AI)\n";
            std::cin>>wybor3;
            if(wybor3=='m')
            {
                while(czyRuch(N,&plansza)&&ewaluacja(N,&plansza,ileWygrywa)==0)
                {
                    std::cout<<"Select row:";
                    std::cin>>wybor2;
                    std::cout<<"Select column:";
                    std::cin>>wybor4;
                    if(wybor2>N||wybor4>N||wybor2<0||wybor4<0||plansza[wybor2-1][wybor4-1]!=blank)
                        std::cout<<"Error - wrong choice\n";
                    else
                    {
                        plansza[wybor2-1][wybor4-1]=X;
                        wyswietlKiK(N,plansza);

                        if(czyRuch(N,&plansza)&&ewaluacja(N,&plansza,ileWygrywa)==0)
                        {
                            najlepszyRuch = znajdzNajlepszyRuch(N,ileWygrywa,&plansza,!czyX);
                            plansza[najlepszyRuch.rzad][najlepszyRuch.kolumna]=O;
                            wyswietlKiK(N,plansza);
                        }

                    }
                }
                if(ewaluacja(N,&plansza,ileWygrywa)>0)
                    std::cout<<"X wins!\n";
                else if(ewaluacja(N,&plansza,ileWygrywa)<0)
                    std::cout<<"O wins!\n";
                else
                    std::cout<<"Draw!\n";
            }
            else if(wybor3=='a')
            {
                while(czyRuch(N,&plansza)&&ewaluacja(N,&plansza,ileWygrywa)==0)
                {
                    najlepszyRuch = znajdzNajlepszyRuch(N,ileWygrywa,&plansza,czyX);
                    plansza[najlepszyRuch.rzad][najlepszyRuch.kolumna]=X;
                    wyswietlKiK(N,plansza);

                    if(czyRuch(N,&plansza)&&ewaluacja(N,&plansza,ileWygrywa)==0)
                    {
                        std::cout<<"Select row:";
                        std::cin>>wybor2;
                        std::cout<<"Select column:";
                        std::cin>>wybor4;
                        if(wybor2>N||wybor4>N||wybor2<0||wybor4<0||plansza[wybor2-1][wybor4-1]!=blank)
                            std::cout<<"Error - wrong choice\n";
                        else
                        {
                            plansza[wybor2-1][wybor4-1]=O;
                            wyswietlKiK(N,plansza);
                        }
                    }
                }
                if(ewaluacja(N,&plansza,ileWygrywa)>0)
                    std::cout<<"X wins!\n";
                else if(ewaluacja(N,&plansza,ileWygrywa)<0)
                    std::cout<<"O wins!\n";
                else
                    std::cout<<"Draw!\n";
            }
            else
            {
                std::cout<<"Choice not recognized\n";
            }
            break;

            case 'c':
            std::cout<<"How many rows and columns should the game have?\n";
            std::cin>>N;
            std::cout<<"How many in a line should win?\n";
            std::cin>>ileWygrywa;
            plansza = new Znak *[N];
            for(int i=0;i<N;i++)
            {
                plansza[i] = new Znak[N];
                for(int j=0;j<N;j++)
                    plansza[i][j]=blank;
            }
            wyswietlKiK(N,plansza);
            while(czyRuch(N,&plansza)&&ewaluacja(N,&plansza,ileWygrywa)==0)
            {
                najlepszyRuch = znajdzNajlepszyRuch(N,ileWygrywa,&plansza,czyX);
                if(czyX)
                    plansza[najlepszyRuch.rzad][najlepszyRuch.kolumna]=X;
                else
                    plansza[najlepszyRuch.rzad][najlepszyRuch.kolumna]=O;
                wyswietlKiK(N,plansza);
                czyX=!czyX;
            }
            if(ewaluacja(N,&plansza,ileWygrywa)>0)
                std::cout<<"X wins!\n";
            else if(ewaluacja(N,&plansza,ileWygrywa)<0)
                std::cout<<"O wins!\n";
            else
                std::cout<<"Draw!\n";
            break;


            case 'v':
            std::cout<<"How many rows and columns should the game have?\n";
            std::cin>>N;
            std::cout<<"How many in a line should win?\n";
            std::cin>>ileWygrywa;
            plansza = new Znak *[N];
            for(int i=0;i<N;i++)
            {
                plansza[i] = new Znak[N];
                for(int j=0;j<N;j++)
                    plansza[i][j]=blank;
            }
            wyswietlKiK(N,plansza);
            while(czyRuch(N,&plansza)&&ewaluacja(N,&plansza,ileWygrywa)==0)
            {
                std::cout<<"Player X: Select row:";
                std::cin>>wybor2;
                std::cout<<"Player X:Select column:";
                std::cin>>wybor4;
                if(wybor2>N||wybor4>N||wybor2<0||wybor4<0||plansza[wybor2-1][wybor4-1]!=blank)
                        std::cout<<"Error - wrong choice\n";
                else
                {
                    plansza[wybor2-1][wybor4-1]=X;
                    wyswietlKiK(N,plansza);

                    if(czyRuch(N,&plansza)&&ewaluacja(N,&plansza,ileWygrywa)==0)
                    {
                        std::cout<<"Player O: Select row:";
                        std::cin>>wybor2;
                        std::cout<<"Player O:Select column:";
                        std::cin>>wybor4;
                        if(wybor2>N||wybor4>N||wybor2<0||wybor4<0||plansza[wybor2-1][wybor4-1]!=blank)
                            std::cout<<"Error - wrong choice\n";
                        else
                        {
                            plansza[wybor2-1][wybor4-1]=O;
                            wyswietlKiK(N,plansza);
                        }
                    }
                }

            }
            if(ewaluacja(N,&plansza,ileWygrywa)>0)
                std::cout<<"X wins!\n";
            else if(ewaluacja(N,&plansza,ileWygrywa)<0)
                std::cout<<"O wins!\n";
            else
                std::cout<<"Draw!\n";
            break;

            case 'q':
            break;

            default:
            std::cout<<"Choice not recognized, try again!";
            break;
        }
    }while(wybor!='q');
return 0;
}
