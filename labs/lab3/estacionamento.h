// Copyright [2023] <Luan da Silva Moraes>

/*
    *** Importante ***

    O código de fila em vetor está disponível internamente (não precisa de implementação aqui)

*/



void retira_veiculo(structures::ArrayQueue<int> *f, int k) {
    for (int i = 0; i < k - 1; i++) {
        f->enqueue(f->dequeue());
    }
    f->dequeue();
}


void mantenha_veiculo(structures::ArrayQueue<int> *f, int k) {
    int kElement;
    for (int i = 0; i < k; i++) {
        kElement = f->dequeue();
    }

    f->clear();
    f->enqueue(kElement);
}



/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/

