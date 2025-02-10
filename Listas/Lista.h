#pragma once

#include <iostream>

namespace Listas {

    template <typename TL>
    class Lista {
    private:
        template <typename TE>
        class Elemento {
        public:
            TE pinfo;                // Armazena o valor do elemento
            Elemento<TE>* pProx;     // p proximo elem

            Elemento(TE info) : pinfo(info), pProx(nullptr) {}
            ~Elemento() {}
        };

        Elemento<TL>* pPrimeiro;   // p para o primeiro elem da lista
        Elemento<TL>* pUltimo;     // p para o último elem da lista

    public:

        // Classe iterador
        class iterator {
        private:
            Elemento<TL>* pAtual;  // Ponteiro para o elemento atual

        public:

            // Construtor
            iterator(Elemento<TL>* elemento) : pAtual(elemento) {}

            // Operador pré incremento (++it)
            iterator& operator++() {
                pAtual = pAtual->pProx;
                return *this;
            }

            // Operador pós-incremento (it++)
            iterator operator++(int) {
                iterator temp = *this;
                ++(*this);
                return temp;
            }

            // Operador igualdade (it == it)
            bool operator==(const iterator& other) const {
                return pAtual == other.pAtual;
            }

            // Operador desigualdade (it != it)
            bool operator!=(const iterator& other) const {
                return !(*this == other);
            }

            // Operador dereferência (*it)
            TL& operator*() const {
                return pAtual->pinfo;
            }

            // Permitir acesso à classe Lista
            friend class Lista;
        };

        // Método para obter o iterador do início da lista
        iterator begin() {
            return iterator(pPrimeiro);
        }

        // Método para obter o iterador do final da lista
        iterator end() {
            return iterator(nullptr);
        }

        // Construtor da lista
        Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {}

        // Destrói a lista e libera a memória
        ~Lista() {
            Elemento<TL>* atual = pPrimeiro;
            while (atual != nullptr) {
                Elemento<TL>* proximo = atual->pProx;
                delete atual;
                atual = proximo;
            }
        }

        // Adiciona um elemento no final da lista
        void adicionarElemento(TL info) {
            Elemento<TL>* novoElemento = new Elemento<TL>(info);
            if (pUltimo != nullptr) {
                pUltimo->pProx = novoElemento;
            }
            pUltimo = novoElemento;
            if (pPrimeiro == nullptr) {
                pPrimeiro = novoElemento;
            }
        }

        //remove elemento da lista
        void removerElemento(int pos) {
            if (pos < 0 || pPrimeiro == nullptr) {
                std::cout << "Posição inválida ou lista vazia." << std::endl;
                return;
            }

            Elemento<TL>* atual = pPrimeiro;
            Elemento<TL>* anterior = nullptr;

            // Se for o primeiro elemento
            if (pos == 0) {
                pPrimeiro = atual->pProx;
                if (pPrimeiro == nullptr) {  // Se a lista ficou vazia
                    pUltimo = nullptr;
                }
                delete atual;
                return;
            }

            // Encontrar o elemento na posição desejada
            for (int i = 0; i < pos; ++i) {
                anterior = atual;
                atual = atual->pProx;
                if (atual == nullptr) {
                    std::cout << "Posição inválida." << std::endl;
                    return;
                }
            }

            // Remover o elemento
            anterior->pProx = atual->pProx;

            // Se for o último elemento
            if (atual == pUltimo) {
                pUltimo = anterior;
            }

            delete atual;
        }

        // Retorna o tamanho da lista
        int tamanho() {
            int tam = 0;
            Elemento<TL>* atual = pPrimeiro;
            while (atual != nullptr) {
                ++tam;
                atual = atual->pProx;
            }
            return tam;
        }

        //retorna uma posicao de um dado elemento
        int posicao(TL info) {
            Elemento<TL>* atual = pPrimeiro;
            int pos = 0;
            while (atual != nullptr) {
                if (info == atual->pinfo) {
                    return pos;
                }
                pos++;
                atual = atual->pProx;
            }
            //falta um return aqui
        }

        // retorna elemento em uma posição informada
        TL& operator[](int pos) {
            Elemento<TL>* atual = pPrimeiro;
            for (int i = 0; i < pos; ++i) {
                if (atual == nullptr) {
                    throw std::out_of_range("Posição inválida.");
                }
                atual = atual->pProx;
            }
            if (atual == nullptr) {
                throw std::out_of_range("Posição inválida.");
            }
            return atual->pinfo;
        }


        // Remove um elemento da lista pelo valor
        void removerElemento(const TL& valor) {
            Elemento<TL>* atual = pPrimeiro;
            Elemento<TL>* anterior = nullptr;

            // Percorre a lista até encontrar o elemento com o valor desejado
            while (atual != nullptr && atual->pinfo != valor) {
                anterior = atual;
                atual = atual->pProx;
            }

            // Se o elemento foi encontrado
            if (atual != nullptr) {
                // Se for o primeiro elemento
                if (atual == pPrimeiro) {
                    pPrimeiro = atual->pProx;
                }
                // Se for o último elemento
                if (atual == pUltimo) {
                    pUltimo = anterior;
                }
                // Remove o elemento
                if (anterior != nullptr) {
                    anterior->pProx = atual->pProx;
                }
                delete atual;
            }
        }


        // Método para remover um elemento da lista e retornar o próximo iterador
        iterator removerElemento(iterator it) {
            if (it.pAtual == nullptr) return it;  // Se o iterador for nulo, retorne-o imediatamente

            Elemento<TL>* atual = it.pAtual;
            Elemento<TL>* anterior = nullptr;

            // Se o elemento a ser removido for o primeiro
            if (atual == pPrimeiro) {
                pPrimeiro = atual->pProx;
                if (pPrimeiro == nullptr) {  // Se a lista ficou vazia
                    pUltimo = nullptr;
                }
            }
            else {
                // Encontrar o elemento anterior
                anterior = pPrimeiro;
                while (anterior->pProx != atual) {
                    anterior = anterior->pProx;
                }
                anterior->pProx = atual->pProx;

                // Se o elemento a ser removido for o último
                if (atual == pUltimo) {
                    pUltimo = anterior;
                }
            }

            // Salve o próximo elemento antes de deletar o atual
            Elemento<TL>* proximo = atual->pProx;
            delete atual;

            // Retorne o iterador para o próximo elemento
            return iterator(proximo);
        }
    };
}