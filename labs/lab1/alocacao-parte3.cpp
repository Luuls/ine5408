// Copyright [2024] <Luan da Silva Moraes>
#include <ulimit.h>

#include <string>


class Aluno {
 public:
    Aluno() {}  // construtor
    ~Aluno() {}  // destrutor
    std::string devolveNome() {
        return nome;
    }
    int devolveMatricula() {
        return matricula;
    }
    void escreveNome(std::string nome_) {
        nome = nome_;
    }
    void escreveMatricula(int matricula_) {
        matricula = matricula_;
    }

 private:
    std::string nome;
    int matricula;
};

int* turma_conta(Aluno t[], int N) {
    int* c = new int[26]();
    for (int i = 0; i < N; i++) {
        c[t[i].devolveNome()[0] - 'A']++;
    }

    return c;
}

Aluno **grupos_por_iniciais(Aluno t[], int N) {
    Aluno **g = new Aluno*[26];  // vetor de ponteiros;
                         // cada posição aponta para um vetor de alunos;
                         // tg[i] deve ser alocado com o seguinte:
                         //   tg[0] é um ponteiro para alunos com letra 'A'
                         //   tg[1] é um ponteiro para alunos com letra 'B'
                         //   ...
                         //   tg[25] é um ponteiro para alunos com letra 'Z'

    // DICA: utilize a função 'turma_conta' (implementada no execício 5) para
    //       definir o tamanho de cada um dos 26 vetores
    // int *c = turma_conta(t, N);

    // COLOQUE SEU CÓDIGO AQUI ...

    int* students_count = turma_conta(t, N);
    int* indexes = new int[26]();
    for (int i = 0; i < 26; i++) {
        g[i] = new Aluno[students_count[i]];
    }

    for (int i = 0; i < N; i++) {
        int letterIndex = t[i].devolveNome()[0] - 'A';
        g[letterIndex][indexes[letterIndex]] = t[i];
        indexes[letterIndex]++;
    }

    delete[] students_count;
    delete[] indexes;

    return g;
}



/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e
    já está implementada

*/

