#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>

template<class T>
struct Node
{
    T data;
    Node* left;
    Node* right;
    
    Node(T value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

template<class T>
class BinaryTree
{
public:
    BinaryTree()
    {
        root = nullptr;
    }

    Node<T>* get_root()
    {
        return root;
    }

    void insert(int value)
    {
        if (root == nullptr)
            root = new Node<T>(value);
        else
            insertRecursive(root, value);
    }
    // Функция для создания сбалансированного бинарного дерева на основе отсортированного массива
    Node<T>* create_balanced_tree(T* sorted_array, const unsigned int start, const size_t end)
    {
        // Если начальный индекс больше конечного, значит диапазон пустой
        if (start > end || end == 0)
            return nullptr;

        // Находим середину диапазона и создаем узел с соответствующим значением
        unsigned int mid = (start + end) / 2;
        Node<T>* root = new Node<T>(sorted_array[mid]);
        if (mid == 0)
            return nullptr;
        // Рекурсивно создаем левое и правое поддерево
        root->left = create_balanced_tree(sorted_array, start, mid - 1);
        root->right = create_balanced_tree(sorted_array, mid + 1, end);

        return root;
    }
    void insertRecursive(Node<T>* currentNode, int value)
    {
        if (value < currentNode->data)
            if (currentNode->left == nullptr)
                currentNode->left = new Node<T>(value);
            else
                insertRecursive(currentNode->left, value);
        else
            if (currentNode->right == nullptr)
                currentNode->right = new Node<T>(value);
            else
                insertRecursive(currentNode->right, value);
    }
    // Оператор присваивания
    BinaryTree& operator=(const BinaryTree& other)
    {

        // Проверка на самоприсваивание
        if (this == &other)
            return *this;

        // Удаляем существующее дерево
        clear();

        // Копируем дерево из other
        root = cloneTree(other.root);

        return *this;
    }
    BinaryTree& operator=(Node<T>* otherRoot)
    {
        // Проверка на самоприсваивание
        if (root == otherRoot)
            return *this;

        // Удаляем существующее дерево
        clear();

        // Копируем дерево на основе указанного корня
        root = cloneTree(otherRoot);

        return *this;
    }
    void clear()
    {
        clearTree(root);
        root = nullptr;
    }
    // Приватный метод рекурсивного удаления дерева
    void clearTree(Node<T>* node)
    {
        if (node != nullptr)
        {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
    }
    bool search(int value)
    {
        return searchRecursive(root, value);
    }
    // Собрать значения из дерева в порядке ин-порядка (левое поддерево -> узел -> правое поддерево)
    void inorderTraversal(Node<T>* currentNode, std::vector<int>& values) {
        if (currentNode == nullptr) {
            return;
        }
        inorderTraversal(currentNode->left, values);
        values.push_back(currentNode->data);
        inorderTraversal(currentNode->right, values);
    }

    // Сортировка значений в узлах бинарного дерева
    void sortBinaryTree(Node<T>* root) {
        std::vector<int> values;
    
        // Собираем значения дерева в массиве в порядке ин-порядка
        inorderTraversal(root, values);
    
        // Сортируем значения
        std::sort(values.begin(), values.end());
    
        // Перезаписываем отсортированные значения обратно в узлы дерева
        size_t index = 0;
        inorderOverwrite(root, values, index);
    }

    // Перезаписать отсортированные значения обратно в узлы дерева
    void inorderOverwrite(Node<T>* currentNode, const std::vector<int>& values, size_t& index) {
        if (currentNode == nullptr) {
            return;
        }
    
        // Перезаписываем значения в левом поддереве
        inorderOverwrite(currentNode->left, values, index);
    
        // Записываем отсортированное значение обратно в узел
        currentNode->data = values[index++];
    
        // Перезаписываем значения в правом поддереве
        inorderOverwrite(currentNode->right, values, index);
    }

private:
    Node<T>* cloneTree(Node<T>* node)
    {
        if (node == nullptr)
            return nullptr;

        Node<T>* newNode = new Node(node->data);
        newNode->left = cloneTree(node->left);
        newNode->right = cloneTree(node->right);
        return newNode;
    }
    bool searchRecursive(Node<T>* currentNode, int value)
    {
        // Базовый случай: если текущий узел равен nullptr, возвращаем false
        if (currentNode == nullptr) {
            return false;
        }
    
        // Если значение узла совпадает с искомым значением, возвращаем true
        if (currentNode->data == value) {
            return true;
        }
    
        // Если искомое значение меньше значения текущего узла, рекурсивно ищем в левом поддереве
        if (value < currentNode->data) {
            return searchRecursive(currentNode->left, value);
        }
        // Иначе рекурсивно ищем в правом поддереве
        else {
            return searchRecursive(currentNode->right, value);
        }
    }
    Node<T>* root;
};
