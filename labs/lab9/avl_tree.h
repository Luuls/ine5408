// Copyright [2024] <Luan da Silva Moraes>

#include "array_list.h"


namespace structures {

template<typename T>
class AVLTree {
public:
    AVLTree();

    ~AVLTree();

    void insert(const T& data);

    void remove(const T& data);

    bool contains(const T& data) const;

    bool empty() const;

    std::size_t size() const;

    int height() const;

    ArrayList<T> pre_order() const;

    ArrayList<T> in_order() const;

    ArrayList<T> post_order() const;

private:
    struct Node {
        explicit Node(const T& data_) {
            data = data_;
            left = nullptr;
            right = nullptr;
            height_ = 1;
        }

        ~Node() {
            delete left;
            delete right;
        }

        T data;
        int height_;
        Node* left;
        Node* right;

        void insert(Node** parent, const T& data_) {
            if (data_ < data) {
                if (left == nullptr) {
                    left = new Node(data_);
                } else {
                    left->insert(&left, data_);
                }
            } else {
                if (right == nullptr) {
                    right = new Node(data_);
                } else {
                    right->insert(&right, data_);
                }
            }

            this->updateHeight();
            this->balance(parent);
        }

        bool remove(Node** parent, const T& data_) {
            if (data_ < this->data) {
                if (left != nullptr) {
                    if (left->remove(&left, data_)) {
                        updateHeight();
                        balance(parent);
                        return true;
                    }
                }
            } else if (data_ > this->data) {
                if (right != nullptr) {
                    if (right->remove(&right, data_)) {
                        updateHeight();
                        balance(parent);
                        return true;
                    }
                }
            } else {
                if (left != nullptr && right == nullptr) {
                    if (parent != nullptr) {
                        *parent = left;
                    }
                    delete this;
                } else if (left == nullptr && right != nullptr) {
                    if (parent != nullptr) {
                        *parent = right;
                    }
                    delete this;
                } else if (left != nullptr && right != nullptr) {
                    Node* child = right;
                    while (child->left != nullptr) {
                        child = child->left;
                    }
                    T childData = child->data;
                    right->remove(&right, childData);

                    data = childData;
                } else {
                    *parent = nullptr;
                    delete this;
                }
                return true;
            }
            return false;
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
            } else {
                if (right != nullptr) {
                    return right->contains(data_);
                } else {
                    return false;
                }
            }
        }

        void updateHeight() {
            int leftHeight = left != nullptr ? left->height_ : 0;
            int rightHeight = right != nullptr ? right->height_ : 0;

            height_ = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
        }

        int balanceFactor() {
            return this->leftHeight() - this->rightHeight();
        }

        int leftHeight() {
            if (left != nullptr) {
                return left->height_;
            } else {
                return 0;
            }
        }

        int rightHeight() {
            if (right != nullptr) {
                return right->height_;
            } else {
                return 0;
            }
        }

        void balance(Node** parent) {
            int selfBalance = balanceFactor();

            if (selfBalance > 1) {
                if (left->balanceFactor() > 0) {
                    *parent = simpleRight();
                } else {
                    *parent = doubleRight();
                }
            } else if (selfBalance < -1) {
                if (right->balanceFactor() < 0) {
                    *parent = simpleLeft();
                } else {
                    *parent = doubleLeft();
                }
            }
        }

        Node* simpleLeft() {
            Node* newRoot = right;
            Node* child = right->left;

            newRoot->left = this;
            this->right = child;

            this->updateHeight();
            newRoot->updateHeight();

            return newRoot;
        }

        Node* simpleRight() {
            Node* newRoot = left;
            Node* child = left->right;

            newRoot->right = this;
            this->left = child;

            this->updateHeight();
            newRoot->updateHeight();

            return newRoot;
        }

        Node* doubleLeft() {
            this->right = right->simpleRight();
            return this->simpleLeft();
        }

        Node* doubleRight() {
            this->left = left->simpleLeft();
            return this->simpleRight();
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

        int height() {
            return height_;
        }
    };

    Node* root;
    std::size_t size_;
};

}  // namespace structures

// -----

template<typename T>
structures::AVLTree<T>::AVLTree() {
    root = nullptr;
    size_ = 0;
}

template<typename T>
structures::AVLTree<T>::~AVLTree() {
    delete root;
}

template<typename T>
void structures::AVLTree<T>::insert(const T& data) {
    if (root == nullptr) {
        root = new Node(data);
    } else {
        root->insert(&root, data);
    }

    size_++;
}

template<typename T>
void structures::AVLTree<T>::remove(const T& data) {
    if (root->remove(nullptr, data)) {
        size_--;
    }
}

template<typename T>
bool structures::AVLTree<T>::contains(const T& data) const {
    if (root != nullptr) {
        return root->contains(data);
    } else {
        return false;
    }
}

template<typename T>
bool structures::AVLTree<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t structures::AVLTree<T>::size() const {
    return size_;
}

template<typename T>
int structures::AVLTree<T>::height() const {
    if (root == nullptr) {
        return 0;
    }

    return root->height() - 1;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::pre_order() const {
    structures::ArrayList<T> v;
	if (root != nullptr) {
		root->pre_order(v);
	}
	return v;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::in_order() const {
    structures::ArrayList<T> v;
    if (root != nullptr) {
        root->in_order(v);
    }
    return v;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::post_order() const {
    structures::ArrayList<T> v;
    if (root != nullptr) {
        root->post_order(v);
    }
    return v;
}
