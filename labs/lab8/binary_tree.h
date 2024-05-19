// Copyright [2024] <Luan da Silva Moraes>

#include "array_list.h"


namespace structures {

template<typename T>
class BinaryTree {
public:
    BinaryTree();

    ~BinaryTree();

    void insert(const T& data);

    void remove(const T& data);

    bool contains(const T& data) const;

    bool empty() const;

    std::size_t size() const;

    ArrayList<T> pre_order() const;

    ArrayList<T> in_order() const;

    ArrayList<T> post_order() const;

private:
    struct Node {
        explicit Node(const T& data_) {
            data = data_;
            left = nullptr;
            right = nullptr;
        }

        T data;
        Node* left;
        Node* right;

        void insert(const T& data_) {
            if (data_ < data) {
                if (left != nullptr) {
                    left->insert(data_);
                } else {
                    left = new Node(data_);
                }
            } else {  // data_ >= data
                if (right != nullptr) {
                    right->insert(data_);
                } else {
                    right = new Node(data_);
                }
            }
        }

        Node* remove(const T& data_, Node** root) {
            if (data_ == data) {
                if (left == nullptr && right == nullptr) {
                    delete this;
                    return nullptr;
                } else if (left == nullptr) {
                    Node* toReturn = right;
                    delete this;
                    return toReturn;
                } else if (right == nullptr) {
                    Node* toReturn = left;
                    delete this;
                    return toReturn;
                } else {
                    Node* toReturn = right;
                    while (toReturn->left != nullptr) {
                        toReturn = toReturn->left;
                    }
                    data = toReturn->data;
                    right = right->remove(data, &right);
                    return this;
                }
            } else if (data_ < data) {
                if (left != nullptr) {
                    left = left->remove(data_, &left);
                }
                return this;
            } else {  // data_ > data
                if (right != nullptr) {
                    right = right->remove(data_, &right);
                }
                return this;
            }
        }

        bool contains(const T& data_) const {
            if (data_ == data) {
                return true;
            } else if (data_ < data) {
                if (left != nullptr) {
                    return left->contains(data_);
                } else {
                    return false;
                }
            } else {  // data_ > data
                if (right != nullptr) {
                    return right->contains(data_);
                } else {
                    return false;
                }
            }
        }

        void pre_order(ArrayList<T>& v) const {
            v.push_back(data);
            if (left != nullptr) {
                left->pre_order(v);
            }
            if (right != nullptr) {
                right->pre_order(v);
            }
        }

        void in_order(ArrayList<T>& v) const {
            if (left != nullptr) {
                left->in_order(v);
            }
            v.push_back(data);
            if (right != nullptr) {
                right->in_order(v);
            }
        }

        void post_order(ArrayList<T>& v) const {
            if (left != nullptr) {
                left->post_order(v);
            }
            if (right != nullptr) {
                right->post_order(v);
            }
            v.push_back(data);
        }
    };

    void destroy_recursively(Node* root);

    Node* root;
    std::size_t size_;
};

}  // namespace structures

//-------------------------------------

template<typename T>
structures::BinaryTree<T>::BinaryTree() {
    root = nullptr;
    size_ = 0;
}

template<typename T>
void structures::BinaryTree<T>::destroy_recursively(Node* root) {
    if (root == nullptr) {
        return;
    }

    destroy_recursively(root->left);
    destroy_recursively(root->right);

    delete root;
}

template<typename T>
structures::BinaryTree<T>::~BinaryTree() {
    destroy_recursively(root);
}

template<typename T>
void structures::BinaryTree<T>::insert(const T& data) {
    size_++;

    if (root == nullptr) {
        root = new Node(data);
        return;
    }

    root->insert(data);
}

template<typename T>
void structures::BinaryTree<T>::remove(const T& data) {
    if (empty() || root == nullptr) {
        throw std::runtime_error("Trying to remove from empty tree");
    }

    if (root->remove(data, &root) != nullptr) {
        size_--;
    }
}

template<typename T>
bool structures::BinaryTree<T>::contains(const T& data) const {
    if (root != nullptr) {
        return root->contains(data);
    } else {
        return false;
    }
}

template<typename T>
bool structures::BinaryTree<T>::empty() const {
    return size() == 0;
}

template<typename T>
std::size_t structures::BinaryTree<T>::size() const {
    return size_;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::pre_order() const {
    structures::ArrayList<T> toReturn;
	if (root != nullptr) {
		root->pre_order(toReturn);
	}
	return toReturn;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::in_order() const {
    structures::ArrayList<T> toReturn(size());
    if (root != nullptr) {
        root->in_order(toReturn);
    }
    return toReturn;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::post_order() const {
    structures::ArrayList<T> toReturn(size());
    if (root != nullptr) {
        root->post_order(toReturn);
    }
    return toReturn;
}

