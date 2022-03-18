//
//  Tree.h
//  BST
//
//  Created by Prashanti Pokharel on 10/11/21.
//

#ifndef Tree_h
#define Tree_h

#include<iostream>

template<class T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
};

template<class T>
class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void destroy();
    void insert(const T& item);
    void inOrder(std::ostream& os = std::cout)  const;
    void preOrder(std::ostream& os = std::cout) const;
    void postOrder(std::ostream& os = std::cout) const;
    void deleteNode(const T& item);
    T* search(const T& item) const;
    int height() const;
    int max(T a, T b) const;

private:
    Node<T>* root;
    void destroy(Node<T>*& r);
    void insert(Node<T>*& r, const T& item);
    void inOrder(Node<T>* r, std::ostream& os = std::cout)  const;
    void preOrder(Node<T>* r, std::ostream& os = std::cout) const;
    void postOrder(Node<T>* r, std::ostream& os = std::cout) const;
    T* search(Node<T>* r, const T& item) const;
    void searchD(const T& item, bool& found, Node<T>*& locptr, Node<T>*& parent) const;
    int height(Node<T>* r) const;


};


template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

template<class T>
inline
BinarySearchTree<T>::~BinarySearchTree() {
    destroy();
}

template<class T>
void BinarySearchTree<T>::destroy(Node<T>*& r) {
    if (r != nullptr)
    {
        destroy(r->left);
        destroy(r->right);
        delete r;
        r = nullptr;
    }
}


template<class T>
inline
void BinarySearchTree<T>::destroy() {
    destroy(root);
}

template<class T>
void BinarySearchTree<T>::insert(Node<T>*& r, const T& item) {
    if (r == nullptr)
    {
        r = new Node <T>;
        r->value = item;
        r->left = nullptr;
        r->right = nullptr;
    }
    else if (item < r->value)
    {
        insert(r->left, item);
    }
    else if (item > r->value)
    {
        insert(r->right, item);
    }
    else
    {
        std::cout << "Duplicate insertion. Please input new items.";
    }
}

template<class T>
inline
void BinarySearchTree<T>::insert(const T& item) {
    insert(root, item);
}


template<class T>
void BinarySearchTree<T>::preOrder(Node<T>* r, std::ostream& os) const {
    if (r != nullptr)
    {
        os << r->value << std::endl;
        preOrder(r->left, os);
        preOrder(r->right, os);
    }
}


template<class T>
inline
void BinarySearchTree<T>::preOrder(std::ostream& os) const {
    preOrder(root, os);
}

template<class T>
void BinarySearchTree<T>::inOrder(Node<T>* r, std::ostream& os) const {
    if (r != nullptr)
    {
        inOrder(r->left, os);
        os << r->value << std::endl;
        inOrder(r->right, os);
    }
}

template<class T>
inline
void BinarySearchTree<T>::inOrder(std::ostream& os) const {
    inOrder(root, os);
}

template<class T>
void BinarySearchTree<T>::postOrder(Node<T>* r, std::ostream& os) const {
    if (r != nullptr)
    {
        postOrder(r->left, os);
        postOrder(r->right, os);
        os << r->value << std::endl;
    }
}

template<class T>
inline
void BinarySearchTree<T>::postOrder(std::ostream& os) const {
    postOrder(root, os);
}

template<class T>
T* BinarySearchTree<T>::search(Node<T>* r, const T& item) const {
    T* result = nullptr;
    if (r == nullptr)
    {
        result = nullptr;
    }
    else if (item < r->value)
    {
        result = search(r->left, item);
    }
    else if (item > r->value)
    {
        result = search(r->right, item);
    }
    else
    {
        result = new T(r->value);
    }
    return result;
}

template<class T>
inline
T* BinarySearchTree<T>::search(const T& item) const {
    return search(root, item);
}

template<class T>
inline
int BinarySearchTree<T>::max(T a, T b) const {
    return (a > b) ? a : b;
}

template<class T>
int BinarySearchTree<T>::height(Node<T>* r) const {
    int result;
    if (r == nullptr)
    {
        result = 0;
    }
    else
    {
        result = 1 + max(height(r->left), height(r->right));
    }
    return result;
}

template<class T>
inline 
int BinarySearchTree<T>::height() const {
    return height(root);
}

template<class T>
void BinarySearchTree<T>::searchD(const T& item, bool& found, Node<T>*& locptr, Node<T>*& parent) const {
    locptr = root;
    parent = nullptr;
    found = false;
    while (!found && locptr != nullptr)
    {
        if (item < locptr->value)
        {
            parent = locptr;
            locptr = locptr->left;
        }
        else if (locptr->value < item)
        {
            parent = locptr;
            locptr = locptr->right;
        }
        else
        {
            found = true;
        }
    }
}


template<class T>
void BinarySearchTree<T>::deleteNode(const T& item) {
    using namespace std;
    bool found;
    Node<T>* current;
    Node<T>* parent;
    searchD(item, found, current, parent);
    if (!found)
    {
        cout << "Couldn't find the item in the tree.\n";
    }
    else
    {
        if ((current->left != nullptr) && (current->right != nullptr))
        {
            Node<T>* currentSucc = current->right;
            parent = current;
            while (currentSucc->left != nullptr)
            {
                parent = currentSucc;
                currentSucc = currentSucc->left;
            }
            current->value = currentSucc->value;
            current = currentSucc;
        }

        Node<T>* subTree = current->left;
        if (subTree == nullptr)
        {
            subTree = current->right;
        }

        if (parent == nullptr)
        {
            root = subTree;
        }
        
        else if (parent->left == current) {
            parent->left = subTree;
        }
        else
        {
            parent->right = subTree;
        }
        delete current;
    }
}



#endif 
