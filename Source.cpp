#include<iostream>
#include<conio.h>
using namespace std;
using namespace System;

void setSizeA(short& size_a) {
	do {
		cout << "\n Ingrese el tama o de elementos del conjunto (entre 4 y 7): ";
		cin >> size_a;
	} while (size_a < 4 || size_a>7);

}

void valuesOfSetA(char& verify, short& size_a, int* setA) {

	do {
		cout << "\n Desea usar datos aleatoreos [A] o ingresarlos manulamente [M]: ";
		cin >> verify;
		verify = toupper(verify);

	} while (verify != 65 && verify != 77);

	if (verify != 'M') {
		for (short i = 0; i < size_a; i++) {
			setA[i] = 1 + rand() % (12 + 1 - 1);
			for (short j = 0; j < i; j++) { //verificacion de numero repetido
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
			if (check_int - int(check_int) == 0)setA[i] = check_int;
			else {
				Console::ForegroundColor = ConsoleColor::Red;
				cout << "\n\n!!NUMERO DECIMAL, INGRESA OTRO!!\n"; i--;
			}

			for (int j = 0; j < i; j++) {
				if (setA[i] == setA[j]) {
					//cout << "Ya usaste este numero, gil, prueba otro: ";  cin >> setA[i];
					Console::ForegroundColor = ConsoleColor::Red;
					cout << "\n\n!!NUMERO REPETIDO, VUELVE A INTENTAR!!\n\n";
					Console::ForegroundColor = ConsoleColor::White;
					cout << "Ingrese los datos del conjunto A - posicion [" << i + 1 << "]: "; cin >> setA[i];
					j = -1;
				}
			}

		}
	}

	cout << "\n Conjunto A = { ";
	for (short i = 0; i < size_a; i++) {
		cout << setA[i] << " ";
	}
	cout << "} \n\n\n";
}

void operationSetA(short& size_a, int* setA, int** setAA) {
	for (short i = 0; i < size_a; i++) {
		for (short j = 0; j < size_a; j++) {
			setAA[i][j] = setA[i] + setA[j];
		}
	}

	for (short i = 0; i < size_a; i++) {
		for (short j = 0; j < size_a; j++) {
			cout << "(A" << i + 1 << ",A" << j + 1 << "): " << setAA[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "\n Mostrar matriz:\n\n ";
	for (short i = 0; i < size_a; i++) {
		for (short j = 0; j < size_a; j++) {
			cout << " [" << setAA[i][j] << "] ";
		}
		cout << endl;
	}
}

void validset(short& size_a, int** setAA, int* setR) {
	short setM[4] = { 3, 4, 5, 6 };
	short valueR = 0;

	for (short i = 0; i < size_a; i++) {
		for (short j = 0; j < size_a; j++) {
			for (short k = 0; k < 4; k++) {
				if (setAA[i][j] % setM[k] == 0) { setR[valueR] = setAA[i][j]; valueR++; break; }
			}
		}
	}
	for (short i = 0; i < valueR; i++) {
		for (short j = i + 1; j < valueR; j++) { //verificacion de numero repetido
			if (setR[i] == setR[j]) {
				for (short h = j; h < valueR; h++) {
					setR[h] = setR[h + 1];
				}
				valueR--;
				j = i;
			}
		}
	}

	cout << "\n\n Conjunto R: { ";
	for (short i = 0; i < valueR; i++) {
		cout << setR[i] << " ";
	}
	cout << "}";
}

int main() {
	srand(time(NULL));
	// declara las variables
	short size_a = 0;
	char verify = ' ';

	// se obtiene el tamanio del conjunto A
	setSizeA(size_a);
	int* setA = new int[size_a]; // se crea el conjunto A
	int* setR = new int[size_a * 2];

	int** setAA = new int* [size_a]; // se crea la matriz dinamica 
	for (short i = 0; i < size_a; i++) { setAA[i] = new int[size_a]; }
	
	// declara operaciones
	valuesOfSetA(verify, size_a, setA);
	operationSetA(size_a, setA, setAA);
	validset(size_a, setAA, setR);

	// se libera la memoria 
	for (int i = 0; i < size_a; i++) { delete[] setAA[i]; }
	delete[] setAA, setA;

	_getch();
	return 0;
}