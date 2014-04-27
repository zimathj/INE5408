/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 05 - Trabalho de Sistema de Contabilidade Mafioso
 * com Lista Encadeada Simples
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * ListaContabil.h
 */

#ifndef __lista_contabil_h__
#define __lista_contabil_h__

#include "ListaEncadeada.hpp"
#include "Lancamento.h"

class ListaContabil: public ListaEncadeada<Lancamento> {
public:
    ListaContabil();
    ~ListaContabil();
    Lancamento * verTransacao(int posicao);
};

#endif
