#include <iostream>
#include "histograma.h"
#define TAM_MAX 100

using namespace std;

void mostra_histograma(Histograma histograma, int total_valores, int soma_valores);

int main() {

	int numero_bins, numero_maximo, numero_minimo, total_valores = 0;

	cout << "-- CALCULO DE HISTOGRAMA --\n\n# Numero de Bins: ";
	cin >> numero_bins;
	cout << "# Valor Maximo Permitido: ";
	cin >> numero_maximo;
	cout << "# Valor Minimo Permitido: ";
	cin >> numero_minimo;

	cout << endl;
	while (total_valores <= 0) {
		cout << "# Digite uma Quantidade de Valores Valida: ";
		cin >> total_valores;
	}

	cout << "\n# Valores: ";
	double array_valores[TAM_MAX];
	double valores, soma_valores = 0;

	for (int i = 0; i < total_valores; i++) {
		cin >> valores;
		soma_valores += valores;
		array_valores[i] = valores;
	}

	Histograma histograma(numero_bins, numero_maximo, numero_minimo, array_valores);
	mostra_histograma(histograma, total_valores, soma_valores);

	return 0;
}

void mostra_histograma(Histograma histograma, int total_valores, int soma_valores) {

	histograma.histograma_sem_norma(total_valores);
	histograma.histograma_com_norma(soma_valores);
	histograma.get_histograma();
}
