// Copyright 2024 <Luan da Silva Moraes>

#include <cstddef>
#include <stdexcept>

namespace structures {

template <typename T>
/**
 * @brief A classe DoublyCircularList representa uma lista duplamente encadeada
 * circular.
 *
 * Essa classe fornece várias operações para manipular a lista, como inserir,
 * remover e acessar elementos. A lista é implementada usando uma estrutura de
 * lista duplamente encadeada, onde cada nó contém um elemento de dados e
 * ponteiros para os nós anteriores e próximos.
 */
class DoublyCircularList {
 public:
    /**
     * @brief Constrói um objeto DoublyCircularList vazio.
     */
    DoublyCircularList();

    /**
     * @brief Destrói o objeto DoublyCircularList e libera a memória.
     */
    ~DoublyCircularList();

    /**
     * @brief Remove todos os elementos da lista.
     */
    void clear();

    /**
     * @brief Insere um elemento no final da lista.
     *
     * @param data O dado a ser inserido.
     */
    void push_back(const T& data);

    /**
     * @brief Insere um elemento no início da lista.
     *
     * @param data O dado a ser inserido.
     */
    void push_front(const T& data);

    /**
     * @brief Insere um elemento na posição especificada na lista.
     *
     * @param data O dado a ser inserido.
     * @param index A posição em que o dado deve ser inserido.
     */
    void insert(const T& data, std::size_t index);

    /**
     * @brief Insere um elemento em ordem na lista.
     *
     * @param data O dado a ser inserido.
     */
    void insert_sorted(const T& data);

    /**
     * @brief Remove e retorna o elemento na posição especificada na lista.
     *
     * @param index A posição do elemento a ser removido.
     * @return O elemento removido.
     */
    T pop(std::size_t index);

    /**
     * @brief Remove e retorna o último elemento da lista.
     *
     * @return O elemento removido.
     */
    T pop_back();

    /**
     * @brief Remove e retorna o primeiro elemento da lista.
     *
     * @return O elemento removido.
     */
    T pop_front();

    /**
     * @brief Remove a primeira ocorrência do elemento especificado da lista.
     *
     * @param data O elemento a ser removido.
     */
    void remove(const T& data);

    /**
     * @brief Verifica se a lista está vazia.
     *
     * @return True se a lista estiver vazia, false caso contrário.
     */
    bool empty() const;

    /**
     * @brief Verifica se a lista contém o elemento especificado.
     *
     * @param data O elemento a ser verificado.
     * @return True se o elemento for encontrado, false caso contrário.
     */
    bool contains(const T& data) const;

    /**
     * @brief Acessa o elemento na posição especificada na lista.
     *
     * @param index A posição do elemento a ser acessado.
     * @return Uma referência ao elemento acessado.
     */
    T& at(std::size_t index);

    /**
     * @brief Acessa o elemento na posição especificada na lista (versão
     * constante).
     *
     * @param index A posição do elemento a ser acessado.
     * @return Uma referência constante ao elemento acessado.
     */
    const T& at(std::size_t index) const;

    /**
     * @brief Encontra a posição da primeira ocorrência do elemento especificado
     * na lista.
     *
     * @param data O elemento a ser encontrado.
     * @return A posição do elemento, ou size() se não encontrado.
     */
    std::size_t find(const T& data) const;

    /**
     * @brief Retorna o número de elementos na lista.
     *
     * @return O número de elementos na lista.
     */
    std::size_t size() const;

 private:
    /**
     * @brief A classe Node representa um nó na lista duplamente encadeada
     * circular.
     */
    class Node {
     public:
        /**
         * @brief Constrói um objeto Node com o dado especificado.
         *
         * @param data O dado a ser armazenado no nó.
         */
        explicit Node(const T& data);

        /**
         * @brief Constrói um objeto Node com o dado e o próximo nó
         * especificados.
         *
         * @param data O dado a ser armazenado no nó.
         * @param next O próximo nó na lista.
         */
        Node(const T& data, Node* next);

        /**
         * @brief Constrói um objeto Node com o dado, o nó anterior e o próximo
         * nó especificados.
         *
         * @param data O dado a ser armazenado no nó.
         * @param prev O nó anterior na lista.
         * @param next O próximo nó na lista.
         */
        Node(const T& data, Node* prev, Node* next);

        /**
         * @brief Retorna uma referência ao dado armazenado no nó.
         *
         * @return Uma referência ao dado armazenado no nó.
         */
        T& data();

        /**
         * @brief Retorna uma referência constante ao dado armazenado no nó.
         *
         * @return Uma referência constante ao dado armazenado no nó.
         */
        const T& data() const;

        /**
         * @brief Retorna um ponteiro para o nó anterior.
         *
         * @return Um ponteiro para o nó anterior.
         */
        Node* prev();

        /**
         * @brief Retorna um ponteiro constante para o nó anterior.
         *
         * @return Um ponteiro constante para o nó anterior.
         */
        const Node* prev() const;

        /**
         * @brief Define o nó anterior.
         *
         * @param node Um ponteiro para o nó anterior.
         */
        void prev(Node* node);

        /**
         * @brief Retorna um ponteiro para o próximo nó.
         *
         * @return Um ponteiro para o próximo nó.
         */
        Node* next();

        /**
         * @brief Retorna um ponteiro constante para o próximo nó.
         *
         * @return Um ponteiro constante para o próximo nó.
         */
        const Node* next() const;

        /**
         * @brief Define o próximo nó.
         *
         * @param node Um ponteiro para o próximo nó.
         */
        void next(Node* node);

     private:
        T data_;      // O dado armazenado no nó
        Node* prev_;  // Um ponteiro para o nó anterior
        Node* next_;  // Um ponteiro para o próximo nó
    };

    Node* head;         // Um ponteiro para o nó cabeça
    std::size_t size_;  // O número de elementos na lista
};

}  // namespace structures

template <typename T>
structures::DoublyCircularList<T>::Node::Node(const T& data) {
    data_ = data;
    next_ = nullptr;
    prev_ = nullptr;
}

template <typename T>
structures::DoublyCircularList<T>::Node::Node(const T& data, Node* next) {
    data_ = data;
    next_ = next;
    prev_ = nullptr;
}

template <typename T>
structures::DoublyCircularList<T>::Node::Node(const T& data, Node* prev,
                                              Node* next) {
    data_ = data;
    next_ = next;
    prev_ = prev;
}

template <typename T> T& structures::DoublyCircularList<T>::Node::data() {
    return data_;
}

template <typename T>
const T& structures::DoublyCircularList<T>::Node::data() const {
    return data_;
}

template <typename T>
typename structures::DoublyCircularList<T>::Node*
structures::DoublyCircularList<T>::Node::prev() {
    return prev_;
}

template <typename T>
const typename structures::DoublyCircularList<T>::Node*
structures::DoublyCircularList<T>::Node::prev() const {
    return prev_;
}

template <typename T>
void structures::DoublyCircularList<T>::Node::prev(Node* node) {
    prev_ = node;
}

template <typename T>
typename structures::DoublyCircularList<T>::Node*
structures::DoublyCircularList<T>::Node::next() {
    return next_;
}

template <typename T>
const typename structures::DoublyCircularList<T>::Node*
structures::DoublyCircularList<T>::Node::next() const {
    return next_;
}

template <typename T>
void structures::DoublyCircularList<T>::Node::next(Node* node) {
    next_ = node;
}

template <typename T> structures::DoublyCircularList<T>::DoublyCircularList() {
    head = nullptr;
    size_ = 0;
}

template <typename T> structures::DoublyCircularList<T>::~DoublyCircularList() {
    clear();
}

template <typename T> void structures::DoublyCircularList<T>::clear() {
    while (size_ > 0) {
        pop_front();
    }
}

template <typename T>
void structures::DoublyCircularList<T>::push_back(const T& data) {
    insert(data, size_);
}

template <typename T>
void structures::DoublyCircularList<T>::push_front(const T& data) {
    Node* new_node;
    if (empty()) {
        new_node = new Node(data);
        new_node->next(new_node);
        new_node->prev(new_node);
        head = new_node;
    } else {
        new_node = new Node(data, head->prev(), head);
        head->prev()->next(new_node);
        head->prev(new_node);
        head = new_node;
    }
    size_++;
}

template <typename T>
void structures::DoublyCircularList<T>::insert(const T& data,
                                               std::size_t index) {
    if (index > size_) {
        throw std::out_of_range("Invalid index");
    } else if (index == 0) {
        push_front(data);
    } else {
        Node* new_node = new Node(data);
        Node* current = head;
        for (std::size_t i = 0; i < index - 1; i++) {
            current = current->next();
        }
        new_node->next(current->next());
        new_node->prev(current);
        current->next()->prev(new_node);
        current->next(new_node);
        size_++;
    }
}

template <typename T>
void structures::DoublyCircularList<T>::insert_sorted(const T& data) {
    Node* current = head;
    std::size_t index = 0;
    while (index < size_ && data > current->data()) {
        current = current->next();
        index++;
    }
    insert(data, index);
}

template <typename T>
T structures::DoublyCircularList<T>::pop(std::size_t index) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Invalid index");
    }

    if (empty()) {
        throw std::out_of_range("Empty list");
    }

    if (index == 0) {
        return pop_front();
    }

    Node* current = head;
    for (std::size_t i = 0; i < index; i++) {
        current = current->next();
    }
    T data = current->data();
    current->prev()->next(current->next());
    current->next()->prev(current->prev());
    delete current;
    size_--;
    return data;
}

template <typename T> T structures::DoublyCircularList<T>::pop_back() {
    return pop(size_ - 1);
}

template <typename T> T structures::DoublyCircularList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Empty list");
    }

    Node* current = head;
    T data = current->data();
    head = current->next();
    head->prev(current->prev());
    current->prev()->next(head);
    delete current;
    size_--;
    return data;
}

template <typename T>
void structures::DoublyCircularList<T>::remove(const T& data) {
    pop(find(data));
}

template <typename T> bool structures::DoublyCircularList<T>::empty() const {
    return size_ == 0;
}

template <typename T>
bool structures::DoublyCircularList<T>::contains(const T& data) const {
    return find(data) != size_;
}

template <typename T>
T& structures::DoublyCircularList<T>::at(std::size_t index) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Invalid index");
    }

    Node* current = head;
    for (std::size_t i = 0; i < index; i++) {
        current = current->next();
    }
    return current->data();
}

template <typename T>
const T& structures::DoublyCircularList<T>::at(std::size_t index) const {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Invalid index");
    }

    Node* current = head;
    for (std::size_t i = 0; i < index; i++) {
        current = current->next();
    }
    return current->data();
}

template <typename T>
std::size_t structures::DoublyCircularList<T>::find(const T& data) const {
    Node* current = head;
    std::size_t index = 0;
    while (index < size_ && current->data() != data) {
        current = current->next();
        index++;
    }
    return index;
}

template <typename T>
std::size_t structures::DoublyCircularList<T>::size() const {
    return size_;
}
