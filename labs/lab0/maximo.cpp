int posicao(int vet[], int n) {
    int indice = 0;
    int maior = vet[indice];
    for (int i = 1; i < n; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
            indice = i;
        }
    }

    return indice;
}

struct maxpos {
    int max;
    int pos;
};

maxpos maximo_posicao(int vet[], int n) {
    maxpos resultado = {0, vet[0]};
    for (int i = 1; i < n; i++) {
        if (vet[i] > resultado.max) {
            resultado.max = vet[i];
            resultado.pos = i;
        }
    }

    return resultado;
}

void maximo_vetores(int vet1[], int vet2[], int n) {
    for (int i = 0; i < n; i++) {
        vet1[i] = vet1[i] > vet2[i] ? vet1[i] : vet2[i];
    }
}

void inversao(int vet[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int tmp = vet[i];
        vet[i] = vet[n - 1 - i];
        vet[n - 1 - i] = tmp;
    }
}
