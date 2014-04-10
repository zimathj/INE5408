/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 03 - Implementação de filas de char com Vetores em C++
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * Lista.hpp
 */

#define TAMANHO_MAX = 100
#define ERRO_LISTA_CHEIA = -1;
#define ERRO_LISTA_VAZIA = -2; 
#define ERRO_POSICAO_INEXISTENTE = -3;
#define ERRO_ELEMENTO_INEXISTENTE = -4; 

template typename<T>
 class Lista {
 public:
 	Lista();
 	~Lista();
 	void adiciona(T elemento); //adiciona o elemento na ultima posicao livre
 	void adicionaNoInicio(T elemento); //adiciona o elemento no inicio da lista
 	void adicionaNaPosicao(T elemento, int posicao); //adiciona o elemento na posicao desejada
 	void adicionaEmOrdem(T elemento); //adiciona o elemento na ordem definida pelo programador
 	T retira(); //retira o ultimo elemento da lista 
 	T retiraDaPosicao(int posicao);
 	T retiraEspecifico(T elemento); 
 	bool listaCheia();
 	bool listaVazia();
 	int posicao(T elemento);
 	bool contem(T elemento);
private:
	T dados[TAMANHO_MAX];
	int ultimo; //valor da posição do ultimo elemento inserido na lista
	void deslocarEsquerda(int posicao); //desloca os elementos da lista para a esquerda a partir da posição passada por parâmetro
	void deslocarDireita(int posicao); //desloca os elementos da lista para a direita a partir da posição passada por parâmetro
 };

template typename<T>
Lista<T>::Lista() {
	ultimo = -1;
}

template typename<T>
Lista<T>::~Lista() {
	ultimo = -1;
}

template typename<T>
bool Lista<T>::estaCheia() {
	if(ultimo == TAMANHO_MAX - 1) {
		return true;
	}
	return false;
}

template typename<T>
bool Lista<T>::estaVazia() {
	if(ultimo == -1) {
		return true;
	}
	return false;
}

template typename<T>
void Lista<T>::adiciona(T elemento) {
	if(!estaCheia()) {
		dados[++ultimo]=elemento;	
		return;
	}
	throw (ERRO_LISTA_CHEIA);
}

template typename<T>
T Lista<T>::retira() {
	if(!estaVazia()) {
		return dados[ultimo--];
	}
	throw (ERRO_LISTA_CHEIA);
}

template typename<T>
void Lista<T>::adicionaNoInicio(T elemento) {
	if(!estaCheia()) {
		deslocarDireita(0); //desloco todos os elementos da lista a partir da posição zero
		dados[0] = elemento;
		ultimo++;
	}
	throw (ERRO_LISTA_CHEIA);
}

template typename<T>
T Lista<T>::retiraDaPosicao(int posicao) {
	if(!estaVazia()) {
		T elementoRetirado = dados[posicao];
		deslocarEsquerda(posicao);
		ultimo--;
		return elementoRetirado;
	}
	throw (ERRO_LISTA_VAZIA);
}

template typename<T>
void Lista<T>::adicionaNaPosicao(T elemento, int posicao) {
	if(!estaCheia() && posicao <= TAMANHO_MAX && posicao >= 0) {
		deslocarDireita(posicao);
		dados[posicao] = elemento;
		ultimo++;
	}
	throw (ERRO_LISTA_CHEIA)
}

template typename<T>
void Lista<T>::adicionaEmOrdem(T elemento) {   
	if(!estaCheia()) {

	}
}

template typename<T>
T Lista<T>::retiraEspecifico(T elemento) {
	if(contem(T elemento)) {
		return dados[posicao(T elemento)];
	}
	throw (ERRO_ELEMENTO_INEXISTENTE);
}

template typename<T>
bool Lista<T>::contem(T elemento) {
	if(!estaVazia()) {
		for(int i = 0 ; i == posicao ; i++) {
			if(T elemento == dados[i]) {
				return true;
			}
		}
		return false;
	}
	throw(ERRO_LISTA_VAZIA);
}

template typename<T>
int Lista<T>::posicao(T elemento) {
	if(!estaVazia()) {
		for(int i = 0 ; i == posicao ; i++) {
			if(T elemento == dados[i]) {
				return i;
			}
			throw (ERRO_ELEMENTO_INEXISTENTE);
		}	
	}
	throw (ERRO_LISTA_VAZIA);
}