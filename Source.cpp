#include "Decoracion.h"

char defRelacion(int x, int y) {
    char op;
    do {
        Console::SetCursorPosition(x, y);
        cout << "Desea ingresar los valores de la relacion de forma manual [M] o automatica [A]?: ";
        cin >> op;
        op = toupper(op);
    } while (op != 'M' && op != 'A');

    return op;
}

struct pares {
    int x;
    int y;
};

void setSizeA(short& size_a, int x, int y) {
    // verifica que el valor del conjunto esté dentro del rango
    do {
        Console::SetCursorPosition(x,y);
        cout << "Ingrese el tamaño de elementos del conjunto (entre 4 y 7): ";
        cin >> size_a;
    } while (size_a < 4 || size_a > 7);
}

short valuesOfSetA(char& verify, short& size_a, int* setA, int x, int y) {
    short pos;
    // verifica que se seleccione una opción válida A/M
    do {
        Console::SetCursorPosition(x, y);
        cout << "Desea generar los datos de forma aleatoria [A] o ingresarlos manualmente [M]?: ";
        cin >> verify;
        verify = toupper(verify);
    } while (verify != 'A' && verify != 'M');

    // realiza la opción dependiendo del valor ingresado anteriormente
    if (verify != 'M') {
        pos = 3;
        for (short i = 0; i < size_a; i++) {
            // se le asigna valores del 1 al 12 al conjunto A
            setA[i] = 1 + rand() % (12 + 1 - 1);
            // verificación de número repetido
            for (short j = 0; j < i; j++) {
                if (setA[i] == setA[j]) {
                    setA[i] = 1 + rand() % (12 + 1 - 1);
                    j = -1;
                }
            }
        }
    }
    else {
        pos = 5;
        for (short i = 0; i < size_a; i++) {
            float check_int;
            Console::SetCursorPosition(x, y+2);
            cout << "Ingrese los datos del conjunto A - posicion [" << i + 1 << "]: ";
            cin >> check_int;
            if (check_int - int(check_int) != 0) {
                Console::SetCursorPosition(x, y + 3);
                cout << "!!Numero decimal, ingresa otro!!          ";
                i--;
            }
            else {
                setA[i] = check_int;
            }
            for (int j = 0; j < i; j++) {
                if (setA[i] == setA[j]) {
                    Console::SetCursorPosition(x, y + 3);
                    cout << "!!Numero repetido, vuelve a intentar!!";
                    i--;
                }
            }
            if (i < size_a - 1) {
                Console::SetCursorPosition(x, y + 2);
                cout << "                                                                  ";
            }
        }
    }
    int aux;
    for (int i = 0; i < size_a; i++) {
        for (int j = 0; j < size_a - 1; j++) {
            if (setA[i] < setA[j]) {
                aux = setA[i];
                setA[i]=setA[j];
                setA[j] = aux;
            }
        }
    }
    Console::SetCursorPosition(x, y + 3);
    cout << "                                              ";


    // mostrar datos
    Console::SetCursorPosition(x, y + pos-1);
    cout << "------------------------------------------------------------------";
    Console::SetCursorPosition(x, y + pos);
    cout << "Conjunto A = { ";
    for (short i = 0; i < size_a; i++) {
        if (i > 0)cout << " ";
        cout << setA[i];
        if(i!=size_a-1)cout<< ",";
    }
    cout << " }";

    return pos;
}
//

bool veritifacionSetA(short& size_a, int* setA, int numero) {
    bool existe = false;
    for (int i = 0; i < size_a; i++) {
        if (setA[i] == numero) {
            existe = true; break;
        }
    }
    return existe;
}

bool veritifacionSetR(short& size_R, pares* setR, int num1, int num2) {
    bool existe=false;
    for (int i = 0; i < size_R; i++) {
        if (num1 == setR[i].x && num2 == setR[i].y) {
            existe = true; break;
        }
    }

    return existe;
}

//
void operationSetA(short& size_a, int* setA, int** setAA, pares* setR, int x, int y, Deco*d) {
    int valueR = 0;
    short pos;
    char opcion = defRelacion(x,y);

   // cout << endl << endl;

    if (opcion == 'A') {
        pos = 0;
        for (short i = 0; i < size_a; i++) {
            for (short j = 0; j < size_a; j++) {
                if ((setA[i] + setA[j]) % 3 == 0 || (setA[i] + setA[j]) % 4 == 0 || (setA[i] + setA[j]) % 5 == 0 || (setA[i] + setA[j]) % 6 == 0) {
                    setAA[i][j] = 1;
                    setR[valueR].x = setA[i];
                    setR[valueR].y = setA[j];
                    valueR++;
                }
                else setAA[i][j] = 0;
            }
        }
    }
    else if (opcion == 'M') {
        pos = 4;
        short ParesOrdenados;
        do {
            Console::SetCursorPosition(x, y + 2);
            cout << "Cuantos pares ordenados tendra su relacion?: "; cin >> ParesOrdenados;
        } while (ParesOrdenados > size_a * size_a);

        for (short i = 0; i < ParesOrdenados; i++) {
            int a; int b;
            bool repetir = false;
            do {
                repetir = false;
                do {
                    Console::SetCursorPosition(x, y + 4);
                    cout << "Ingrese el elemento 'x' del par " << i << " :"; cin >> a;
                } while (!veritifacionSetA(size_a, setA, a));
                do {
                    Console::SetCursorPosition(x, y + 5);
                    cout << "Ingrese el elemento 'y' del par " << i << " :"; cin >> b;
                } while (!veritifacionSetA(size_a, setA, b));

                for (int j = 0; j < ParesOrdenados; j++) {
                    if (a == setR[j].x && b == setR[j].y) {
                        repetir = true;
                    }
                }
                if (!repetir) {
                    setR[valueR].x = a;
                    setR[valueR].y = b;
                    repetir = false;
                    valueR++;
                }

            } while (repetir);
            Console::SetCursorPosition(x, y + 4);
            cout << "                                            ";
            Console::SetCursorPosition(x, y + 5);
            cout << "                                            ";
        }

        for (short i = 0; i < size_a; i++) {
            for (int j = 0; j < size_a; j++) {
                if (veritifacionSetR(ParesOrdenados, setR, setA[i], setA[j])) setAA[i][j] = 1;
                else setAA[i][j] = 0;
            }
        }
    }

    d->matriz(size_a,x,y+3+pos, setAA, setA);

    Console::SetCursorPosition(x + 20, y + 6 + pos); 
        cout << "Conjunto R1: { ";

        if (valueR <= 8) {
            for (short i = 0; i < valueR; i++) {
                cout << "(" << setR[i].x << "," << setR[i].y << ")";
                if (i < valueR - 1)cout << ",";
            }
        }
        else {
            int final;
            for (int k = 0; k < (valueR / 8)+1; k++) {

                if (k == (valueR / 8))final = valueR;
                else final = 8*(k+1);

                Console::SetCursorPosition(x + 35, y + 6 + k + pos);
                for (short i = 8*k; i < final; i++) {
                    cout << "(" << setR[i].x << "," << setR[i].y << ")";
                    if (final!= valueR)cout << ",";
                }
                y++;
            }
        }
        cout << " }";

    getch();

    //Reinicio-----------

    system("cls");
    d->marco(116,30);
    x = 5; y = 2;

    //-------------------

    // Verificar si la relación es reflexiva, simétrica, transitiva y de equivalencia
    bool reflexiva = true, simetrica = true, transitiva = true;
    for (short i = 0; i < size_a; i++) {
        if (setAA[i][i] != 1) reflexiva = false;
        for (short j = 0; j < size_a; j++) {
            if (setAA[i][j] != setAA[j][i]) simetrica = false;
            for (short k = 0; k < size_a; k++) {
                if (setAA[i][j] && setAA[j][k] && !setAA[i][k]) transitiva = false;
            }
        }
    }

    Console::SetCursorPosition(x, y);
    if (reflexiva) cout << "- La relacion es reflexiva.";
    else cout << "- La relacion no es reflexiva.";

    Console::SetCursorPosition(x, y+2);
    if (simetrica) cout << "- La relacion es simetrica.";
    else cout << "- La relacion no es simetrica.";

    Console::SetCursorPosition(x, y+4);
    if (transitiva) cout << "- La relacion es transitiva.";
    else cout << "- La relacion no es transitiva.";

    if (reflexiva && simetrica && transitiva) {

        Console::SetCursorPosition(x, y+6);
        cout << " Es una relacion de equivalencia.";

        // Muestra las aplicaciones en el contexto real
        Console::SetCursorPosition(x, y+8);
        cout << "Aplicaciones de la relacion de equivalencia en el contexto real:";
        Console::SetCursorPosition(x, y + 9);
        cout << "1. Diseño de bases de datos relacionales." << endl;
        Console::SetCursorPosition(x, y + 10);
        cout << "2. Algoritmos de clasificación y búsqueda." << endl;
        Console::SetCursorPosition(x, y + 11);
        cout << "3. Optimización de recursos en redes de comunicación.\n";

        // Presentar la clase de equivalencia de cada elemento
        Console::SetCursorPosition(x, y + 13);
        cout << "Clases de equivalencia:\n";
        cout << endl;
        vector<vector<int>> clases_equivalencia;
        bool* visitado = new bool[size_a]();
        for (short i = 0; i < size_a; i++) {
            if (!visitado[i]) {
                vector<int> clase;
                clase.push_back(setA[i]);
                visitado[i] = true;
                for (short j = i + 1; j < size_a; j++) {
                    if (setAA[i][j]) {
                        clase.push_back(setA[j]);
                        visitado[j] = true;
                    }
                }
                sort(clase.begin(), clase.end());
                clases_equivalencia.push_back(clase);
            }
        }

        // Mostrar las clases de equivalencia
        for (int i = 0; i < clases_equivalencia.size(); i++) {
            Console::SetCursorPosition(x, y + 14+i);
            cout << " Clase " << i + 1 << ": { ";
            for (int j = 0; j < clases_equivalencia[i].size(); j++) {
                cout << clases_equivalencia[i][j] << " ";
            }
            cout << "}\n";
        }

        delete[] visitado;
    }
    else {
        Console::SetCursorPosition(x, y + 6);
        cout << " No es una relacion de equivalencia.";
    }
}

void Menu(int x, int y, Deco* deco) {
    char tecla;
    while (1) {
        deco->titulo(x+65,y+3);
        deco->computadora(x,y);

        Console::SetCursorPosition(x + 70, y + 10);
        cout << "Claudia Belledonne... U202210259";
        Console::SetCursorPosition(x + 70, y + 11);
        cout << "Rogger Miranda....... U202319239";
        Console::SetCursorPosition(x + 70, y + 12);
        cout << "Raul Tasayco......... U202319415";
        Console::SetCursorPosition(x + 70, y + 13);
        cout << "Enzo Rabanal....... U20211A697I5";
        Console::SetCursorPosition(x + 70, y + 14);
        cout << "Dhilsen Mallqui...... U202319440";
        Console::SetCursorPosition(x + 65, y + 16);
        cout << "(Presione una tecla para ingresar a la aplicacion)";
        deco->numeros(x, y);

        tecla = getch();
        if (tecla)break;
    }
}

int main() {
    int op;
    short posi;
    Deco* deco = new Deco();

    Menu(0, 1, deco);

    Console::CursorVisible = true;

    system("cls");
    srand(time(NULL)); // semilla de tiempo

    // declara las variables
    short size_a = 0; // tamaño del conjunto A
    char verify = ' '; // almacena A / M  
    int* setA;
    int** setAA;
    pares* setR;
    short volver;
    // se obtiene el tamaño del conjunto A

    while (1) { //116 30
        deco->marco(116, 30);

             setSizeA(size_a, 5, 2);
             setA = new int[size_a]; // se crea el conjunto A

             setAA = new int* [size_a]; // se crea la matriz dinámica
             for (short i = 0; i < size_a; i++) { setAA[i] = new int[size_a]; } // se declaran las columnas de la matriz

             setR = new pares[size_a * size_a]; // se crea el conjunto R

             // declara operaciones
             posi=valuesOfSetA(verify, size_a, setA, 5, 4);
             operationSetA(size_a, setA, setAA, setR,5, 6+posi,deco);

             cout << "\n\n  "<<char(179)<<"  Desea volver al inicio? [1] SI  [2] NO: "; cin >> volver;
             if (volver == 2)break;
             system("cls");
         }

         // libera la memoria
         for (int i = 0; i < size_a; i++) { delete[] setAA[i]; }
         delete[] setAA, setA, setR;

    
    return 0;
}
