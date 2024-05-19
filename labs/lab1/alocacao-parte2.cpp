// Copyright [2022] <Luan da Silva Moraes>
#include <string>

class Aluno {
 public:
    Aluno() {}  // construtor
    ~Aluno() {}  // destrutor
    std::string devolveNome() { return nome; }
    int devolveMatricula() { return matricula; }
    void escreveNome(std::string nome_) { nome = nome_; }
    void escreveMatricula(int matricula_) { matricula = matricula_; }

 private:
    std::string nome;
    int matricula;
};

Aluno* turma_filtra(Aluno t[], int N, int menor_matr) {
    int size = 0;
    Aluno* buffer = new Aluno[N];
    for (int i = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            buffer[i] = t[i];
            size++;
        }
    }

    Aluno* tf = new Aluno[size];
    for (int i = 0, j = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            tf[j] = t[i];
            j++;
        }
    }

    return tf;
}

int* turma_conta(Aluno t[], int N) {
    int* c = new int[26]();
    for (int i = 0; i < N; i++) {
        c[t[i].devolveNome()[0] - 'A']++;
    }

    return c;
}

/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos
   testes e já está implementada

*/
