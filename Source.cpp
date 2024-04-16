#include<iostream>
#include<conio.h>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace std;

struct pares {
    int x;
    int y;
};

void setSizeA(short& size_a) {
    // verifica que el valor del conjunto esté dentro del rango
    do {
        cout << "\n Ingrese el tamaño de elementos del conjunto (entre 4 y 7): ";
        cin >> size_a;
    } while (size_a < 4 || size_a > 7);
}

void valuesOfSetA(char& verify, short& size_a, int* setA) {
    // verifica que se seleccione una opción válida A/M
    do {
        cout << "\n Desea usar datos aleatorios [A] o ingresarlos manualmente [M]: ";
        cin >> verify;
        verify = toupper(verify);
    } while (verify != 'A' && verify != 'M');

    // realiza la opción dependiendo del valor ingresado anteriormente
    if (verify != 'M') {
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
        for (short i = 0; i < size_a; i++) {
            float check_int;
            cout << "\n Ingrese los datos del conjunto A - posición [" << i + 1 << "]: ";
            cin >> check_int;
            if (check_int - int(check_int) != 0) {
                cout << "\n\n!!Número decimal, ingresa otro!!\n";
                i--;
            }
            else {
                setA[i] = check_int;
            }
            for (int j = 0; j < i; j++) {
                if (setA[i] == setA[j]) {
                    cout << "\n\n!!Número repetido, vuelve a intentar!!\n\n";
                    cout << "Ingrese los datos del conjunto A - posición [" << i + 1 << "]: ";
                    cin >> setA[i];
                    j = -1;
                }
            }
        }
    }

    // mostrar datos
    cout << "\n Conjunto A = { ";
    for (short i = 0; i < size_a; i++) {
        cout << setA[i] << " ";
    }
    cout << "} \n\n\n";
}

void operationSetA(short& size_a, int* setA, int** setAA, pares* setR) {
    int valueR = 0;
    // realiza la suma del conjunto A
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

    // mostrar datos
    cout << "\n Mostrar matriz:\n\n";
    for (short i = 0; i < size_a; i++) {
        for (short j = 0; j < size_a; j++) {
            cout << "[" << setAA[i][j] << "]";
        }
        cout << endl;
    }

    cout << "\n\n Conjunto R1: { ";
    for (short i = 0; i < valueR; i++) {
        cout << "(" << setR[i].x << "," << setR[i].y << ")";
        if (i < valueR - 1)cout << ",";
    }
    cout << "}";

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

    if (reflexiva) cout << "\n\n La relacion es reflexiva.";
    else cout << "\n\n La relacion no es reflexiva.";

    if (simetrica) cout << "\n La relacion es simetrica.";
    else cout << "\n La relacion no es simetrica.";

    if (transitiva) cout << "\n La relacion es transitiva.";
    else cout << "\n La relacion no es transitiva.";

    if (reflexiva && simetrica && transitiva) {
        cout << "\n\n Es una relacion de equivalencia.\n";
        // Presentar la clase de equivalencia de cada elemento
        cout << "\n Clases de equivalencia:\n";
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
            cout << " Clase " << i + 1 << ": { ";
            for (int j = 0; j < clases_equivalencia[i].size(); j++) {
                cout << clases_equivalencia[i][j] << " ";
            }
            cout << "}\n";
        }

        delete[] visitado;
    }
    else {
        cout << "\n\n No es una relacion de equivalencia.\n";
    }
}

int main() {
    srand(time(NULL)); // semilla de tiempo

    // declara las variables
    short size_a = 0; // tamaño del conjunto A
    char verify = ' '; // almacena A / M  

    // se obtiene el tamaño del conjunto A
    setSizeA(size_a);
    int* setA = new int[size_a]; // se crea el conjunto A

    int** setAA = new int* [size_a]; // se crea la matriz dinámica
    for (short i = 0; i < size_a; i++) { setAA[i] = new int[size_a]; } // se declaran las columnas de la matriz

    pares* setR = new pares[size_a * size_a]; // se crea el conjunto R

    // declara operaciones
    valuesOfSetA(verify, size_a, setA);
    operationSetA(size_a, setA, setAA, setR);

    // libera la memoria
    for (int i = 0; i < size_a; i++) { delete[] setAA[i]; }
    delete[] setAA, setA, setR;

    _getch();
    return 0;
}
