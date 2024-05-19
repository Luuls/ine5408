// Copyright [2019] <Luan da Silva Moraes>
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

namespace structures {

template<typename T>
//! CLASSE PILHA
class ArrayStack {
 public:
    //! construtor simples
    ArrayStack();
    //! construtor com parametro tamanho
    explicit ArrayStack(std::size_t max);
    //! destrutor
    ~ArrayStack();
    //! metodo empilha
    void push(const T& data);
    //! metodo desempilha
    T pop();
    //! metodo retorna o topo
    T& top();
    //! metodo limpa pilha
    void clear();
    //! metodo retorna tamanho
    std::size_t size();
    //! metodo retorna capacidade maxima
    std::size_t max_size();
    //! verifica se esta vazia
    bool empty();
    //! verifica se esta cheia
    bool full();

 private:
    T* m_contents;
    int m_top;
    std::size_t m_max_size;

    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif


template<typename T>
structures::ArrayStack<T>::ArrayStack() {
    m_max_size = DEFAULT_SIZE;
    m_contents = new T[m_max_size];
    m_top = -1;
}

template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max) {
    m_max_size = max;
    m_contents = new T[m_max_size];
    m_top = -1;
}

template<typename T>
structures::ArrayStack<T>::~ArrayStack() {
    delete[] m_contents;
}

template<typename T>
void structures::ArrayStack<T>::push(const T& data) {
    if (full()) {
        throw std::out_of_range("pilha cheia");
    } else {
        m_contents[++m_top] = data;
    }
}

template<typename T>
T structures::ArrayStack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("pilha vazia");
    } else {
        return m_contents[m_top--];
    }
}

template<typename T>
T& structures::ArrayStack<T>::top() {
    if (empty()) {
        throw std::out_of_range("pilha vazia");
    } else {
        return m_contents[m_top];
    }
}

template<typename T>
void structures::ArrayStack<T>::clear() {
    m_top = -1;
}

template<typename T>
std::size_t structures::ArrayStack<T>::size() {
    return m_top + 1;
}

template<typename T>
std::size_t structures::ArrayStack<T>::max_size() {
    return m_max_size;
}

template<typename T>
bool structures::ArrayStack<T>::empty() {
    return m_top == -1;
}

template<typename T>
bool structures::ArrayStack<T>::full() {
    return m_top == static_cast<int>(m_max_size) - 1;
}

