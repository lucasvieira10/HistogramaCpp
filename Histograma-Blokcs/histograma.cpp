#include <iostream>
#include <iomanip>
#include <string.h>
#include "histograma.h"
#define TAM_MAX 100

using namespace std;

/*autor: Lucas Lima Vieira*/

Histograma::Histograma(int bins, int maximo, int minimo, double* array_valores) {

	this->numero_bins = bins;
	this->maximo_permitido = maximo;
	this->minimo_permitido = minimo;
	this->valores = array_valores;
	double histograma_nao_normalizado[TAM_MAX];
	double histograma_normalizado[TAM_MAX];
	inicializa_array_histograma();
}

void Histograma::inicializa_array_histograma() {

	memset(histograma_nao_normalizado, 0, sizeof(histograma_nao_normalizado));
	memset(histograma_normalizado, 0, sizeof(histograma_normalizado));
}

double* Histograma::calcula_frequencia() {

	int amplitude = maximo_permitido - minimo_permitido;
	double intervalo = amplitude / numero_bins;
	static double frequencia[TAM_MAX];

	for (int i = 0; i < numero_bins; i++) {
		frequencia[i] = (i+1) * intervalo;
	}
	return frequencia;
}

void Histograma::histograma_sem_norma(int total_valores) {

	for (int i = 0; i < total_valores; i++) {
		for (int j = 0; j < total_valores; j++) {
			if (*(valores + i) <= *(calcula_frequencia() + j)) {
					histograma_nao_normalizado[j]++;
					break;
			}
		}
	}
}

double Histograma::soma_valores_histograma() {

    double soma_valores = 0;
    for (int i = 0; i < numero_bins; i++) {
        soma_valores += histograma_nao_normalizado[i];
    }
    return soma_valores;
}

void Histograma::histograma_com_norma() {

	for (int i = 0; i < numero_bins; i++) {
		histograma_normalizado[i] = histograma_nao_normalizado[i] / soma_valores_histograma();
	}
}

void Histograma::get_histogramas() {

	cout.precision(3);
	cout << "\n- Histograma Sem Normalizacao: ";
	for (int i = 0; i < numero_bins; i++) {
		cout << histograma_nao_normalizado[i] << " ";
	}

	cout << "\n- Histograma Com Normalizacao: ";
	for (int i = 0; i < numero_bins; i++) {
        cout << histograma_normalizado[i] << " ";
	}
	cout << endl;
}
