#pragma once
#include<iostream>
#include<conio.h>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace System;
using namespace std;

class Deco
{
public:
	Deco(){}
    void computadora(int x, int y) {
        Console::SetCursorPosition(x, y);
        cout << "             ________________________________________________" << endl;
        Console::SetCursorPosition(x, y + 1);
        cout << "            /                                                \\" << endl;
        Console::SetCursorPosition(x, y + 2);
        cout << "           |    _________________________________________     |" << endl;
        Console::SetCursorPosition(x, y + 3);
        cout << "           |   |                                         |    |" << endl;
        Console::SetCursorPosition(x, y + 4);
        cout << "           |   |  C:\\> _ [Identificar Relacion]          |    |" << endl;
        Console::SetCursorPosition(x, y + 5);
        cout << "           |   |                                         |    |" << endl;
        Console::SetCursorPosition(x, y + 6);
        cout << "           |   |    R={. . .}                            |    |" << endl;
        Console::SetCursorPosition(x, y + 7);
        cout << "           |   |      __ __ __ __ __ __                  |    |" << endl;
        Console::SetCursorPosition(x, y + 8);
        cout << "           |   |     |__|__|__|__|__|__|                 |    |" << endl;
        Console::SetCursorPosition(x, y + 9);
        cout << "           |   |     |__|__|__|__|__|__|                 |    |" << endl;
        Console::SetCursorPosition(x, y + 10);
        cout << "           |   |     |__|__|__|__|__|__|                 |    |" << endl;
        Console::SetCursorPosition(x, y + 11);
        cout << "           |   |     |__|__|__|__|__|__|                 |    |" << endl;
        Console::SetCursorPosition(x, y + 12);
        cout << "           |   |     |__|__|__|__|__|__|                 |    |" << endl;
        Console::SetCursorPosition(x, y + 13);
        cout << "           |   |     |__|__|__|__|__|__|                 |    |" << endl;
        Console::SetCursorPosition(x, y + 14);
        cout << "           |   |                                         |    |" << endl;
        Console::SetCursorPosition(x, y + 15);
        cout << "           |   |                                         |    |" << endl;
        Console::SetCursorPosition(x, y + 16);
        cout << "           |   |_________________________________________|    |" << endl;
        Console::SetCursorPosition(x, y + 17);
        cout << "           |                                                  |" << endl;
        Console::SetCursorPosition(x, y + 18);
        cout << "            \\_________________________________________________/" << endl;
        Console::SetCursorPosition(x, y + 19);
        cout << "                   \\___________________________________/" << endl;
        Console::SetCursorPosition(x, y + 20);
        cout << "                ___________________________________________" << endl;
        Console::SetCursorPosition(x, y + 21);
        cout << "             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_" << endl;
        Console::SetCursorPosition(x, y + 22);
        cout << "          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_" << endl;
        Console::SetCursorPosition(x, y + 23);
        cout << "       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_" << endl;
        Console::SetCursorPosition(x, y + 24);
        cout << "    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_" << endl;
        Console::SetCursorPosition(x, y + 25);
        cout << " _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_" << endl;
        Console::SetCursorPosition(x, y + 26);
        cout << ":-------------------------------------------------------------------------:" << endl;
        Console::SetCursorPosition(x, y + 27);
        cout << "`---._.-------------------------------------------------------------._.---'" << endl;
    }
    void titulo(int x, int y) {
        Console::SetCursorPosition(x, y);
        cout << "  _____      _            _                       ";
        Console::SetCursorPosition(x, y + 1);
        cout << " |  __ \\    | |          (_)                      ";
        Console::SetCursorPosition(x, y + 2);
        cout << " | |__) |___| | __ _  ___ _  ___  _ __   ___  ___ ";
        Console::SetCursorPosition(x, y + 3);
        cout << " |  _  // _ \\ |/ _` |/ __| |/ _ \\| '_ \\ / _ \\/ __|";
        Console::SetCursorPosition(x, y + 4);
        cout << " | | \\ \\  __/ | (_| | (__| | (_) | | | |  __/\\__ \\";
        Console::SetCursorPosition(x, y + 5);
        cout << " |_|  \\_\\___|_|\\__,_|\\___|_|\\___/|_| |_|\\___||___/";
    }

    void numeros(int x, int y) {
        Console::CursorVisible = false;
        Random r;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                Console::SetCursorPosition(x + 22 + (j * 3), y + 8 + i);
                cout << r.Next(0, 2);
                _sleep(90);
            }
        }

        Console::SetCursorPosition(x + 21, y + 15);
        cout << "Cargando ";
        for (int i = 1; i < 4; i++) {
            _sleep(400);
            Console::SetCursorPosition(x + 30 + (i * 1), y +15);
            cout <<".";
        }
    }

    void marco(int width, int height) {

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 && j == 0)cout <<"  "<< char(218);
                else if (i == height - 1 && j == 0)cout << "  "<<char(192);
                else if (i == 0 && j == width - 1)cout << char(191);
                else if (i == height - 1 && j == width - 1)cout << char(217);
                else if (i == 0 || i == height - 1)cout <<char(196);
                else if (j == 0 || j == width - 1) { 
                    if (j == 0)cout << "  ";
                    cout << char(179); }
                else cout << " ";
            }
            if(i< height-1)cout << endl;
        }

    }

    void matriz(int width, int x, int y, int** setAA, int* setA){
        Console::SetCursorPosition(x, y);
        cout << "Mostrar matriz:";
        short size = width;
        short height = width + 2;
        width = width + (width - 1) + 4;

        Console::SetCursorPosition(x+3, y + 2);
        for (short i = 1; i < size+1; i++) {
            cout << setA[i-1]<<" ";
        }

        for (short i = 1; i < size+1; i++) {
            Console::SetCursorPosition(x-1, y + 3+i);
            cout << setA[i-1];
        }

        for (int i = 0; i < height; i++) {

            for (int j = 0; j < width; j++) {
                Console::SetCursorPosition(x + j+1, y+3 + i);
                if (i == 0 && j == 0) { cout << char(218); }

                else if (i == height - 1 && j == 0) { cout << char(192); }

                else if (i == 0 && j == width - 1) { cout << char(191); }

                else if (i == height - 1 && j == width - 1) { cout << char(217); }

                else if (j == 0 || j == width - 1) {
                    cout << char(179);
                }
                else { cout << " "; }
            }
        }

        for (short i = 0; i < size; i++) {
            for (short j = 0; j < size; j++) {
                Console::SetCursorPosition(x+3 + (2*j), y+4 + i);
                cout << setAA[i][j];
            }
        }

    }
	~Deco();

private:

};
