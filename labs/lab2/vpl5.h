// Copyright [2022] <Luan da Silva Moraes>
#include <string>
#include "./array_stack.h"

bool verificaChaves(std::string trecho_programa) {
    bool resposta = true;
    int tamanho = trecho_programa.length();
    structures::ArrayStack<char> pilha(500);

    for (int i = 0; i < tamanho; i++) {
        if (trecho_programa[i] == '{') {
            pilha.push(trecho_programa[i]);
        } else if (trecho_programa[i] == '}') {
            if (pilha.empty()) {
                resposta = false;
                break;
            } else if (pilha.top() == '{') {
                pilha.pop();
            } else {
                resposta = false;
                break;
            }
        }
    }

    return resposta;
}

