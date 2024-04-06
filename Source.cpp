#include<iostream>
#include<conio.h>

using namespace std;
using namespace System;

struct pares {
	int x;
	int y;
};

void setSizeA(short& size_a) {

	// verifica que el valor del conjunto este dentro del rango 
	do {
		cout << "\n Ingrese el tama o de elementos del conjunto (entre 4 y 7): ";
		cin >> size_a;
	} while (size_a < 4 || size_a>7);

}

void valuesOfSetA(char& verify, short& size_a, int* setA) {

	// verifica que se seleccione una opcion valida A/M
	do {
		cout << "\n Desea usar datos aleatoreos [A] o ingresarlos manulamente [M]: ";
		cin >> verify;
		verify = toupper(verify);

	} while (verify != 65 && verify != 77);

	// realiza la opcion dependiendo del valor ingresado anteriormente 
	if (verify != 'M') {

		for (short i = 0; i < size_a; i++) {

			// se le asigna valores del 1 al 12 al conjunto A
			setA[i] = 1 + rand() % (12 + 1 - 1);

			// verificacion de numero repetido
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

			Console::ForegroundColor = ConsoleColor::White;
			cout << "\n Ingrese los datos del conjunto A - posicion [" << i + 1 << "]: ";
			cin >> check_int;

			if (check_int - int(check_int) != 0) {
				Console::ForegroundColor = ConsoleColor::Red;
				cout << "\n\n!!NUMERO DECIMAL, INGRESA OTRO!!\n"; i--;
			}

			else { setA[i] = check_int; }

			for (int j = 0; j < i; j++) {

				if (setA[i] == setA[j]) {
					// cout << "Ya usaste este numero, gil, prueba otro: ";  cin >> setA[i];
					Console::ForegroundColor = ConsoleColor::Red;
					cout << "\n\n!!NUMERO REPETIDO, VUELVE A INTENTAR!!\n\n";

					Console::ForegroundColor = ConsoleColor::White;
					cout << "Ingrese los datos del conjunto A - posicion [" << i + 1 << "]: "; cin >> setA[i];

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
	for (short i = 0; i < size_a; i++) {
		for (short j = 0; j < size_a; j++) {
			cout << "(A" << i + 1 << ",A" << j + 1 << "): " << setA[i]+ setA[j];
			if (j < size_a - 1)cout << "  ";
		}
		cout << endl;
	}

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
}

int main() {
		srand(time(NULL)); // semilla de tiempo

		// declara las variables
		short size_a = 0; // tamaño del conjunto A
		char verify = ' '; // almacena A / M  

		// se obtiene el tamanio del conjunto A
		setSizeA(size_a);
		int* setA = new int[size_a]; // se crea el conjunto A
		pares* setR = new pares[size_a * size_a]; // se crea el conjunto R

		int** setAA = new int* [size_a]; // se crea la matriz dinamica 
		for (short i = 0; i < size_a; i++) { setAA[i] = new int[size_a]; } // se declara las columnas de la matriz

		// declara operaciones
		valuesOfSetA(verify, size_a, setA);
		operationSetA(size_a, setA, setAA, setR);


		// se libera la memoria

		for (int i = 0; i < size_a; i++) { delete[] setAA[i]; }
		delete[] setAA, setA, setR;


		_getch();
	return 0;
}
