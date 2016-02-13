#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H
#define TAM_MAX 100

/*autor: Lucas Lima Vieira*/

class Histograma {
	private:
		int numero_bins;
		int maximo_permitido;
		int minimo_permitido;
		double* valores;
		double histograma_nao_normalizado[TAM_MAX];
		double histograma_normalizado[TAM_MAX];
		void inicializa_array_histograma();
		double* calcula_frequencia();
		double soma_valores_histograma();

	public:
		Histograma(int, int, int, double*);
		void histograma_sem_norma(int);
		void histograma_com_norma();
		void get_histogramas();
};

#endif
