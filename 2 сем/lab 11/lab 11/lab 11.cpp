#include <iostream>
using namespace std;

// Структура узла бинарного дерева поиска
struct Node {
    int key;     // Ключ для упорядочивания
    int value;   // Значение, связанное с ключом

    Node* left;
    Node* right;

    Node(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

// Класс для управления деревом
class BSTree {
private:

    Node* root;

    // --- Приватные рекурсивные методы ---
    Node* insertRecursive(Node* current, int key, int value) {
        if (current == nullptr)
            return new Node(key, value);
        if (key < current->key)
            current->left = insertRecursive(current->left, key, value);
        else if (key > current->key)
            current->right = insertRecursive(current->right, key, value);
        return current;
    }

    bool searchRecursive(Node* current, int key) {
        if (current == nullptr) return false;
        if (current->key == key) return true;
        return key < current->key ?
            searchRecursive(current->left, key) :
            searchRecursive(current->right, key);
    }

    Node* deleteRecursive(Node* current, int key) {
        if (current == nullptr) return current;
        if (key < current->key)
            current->left = deleteRecursive(current->left, key);
        else if (key > current->key)
            current->right = deleteRecursive(current->right, key);
        else {
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }
            current->key = minValue(current->right)->key;
            current->value = minValue(current->right)->value;
            current->right = deleteRecursive(current->right, current->key);
        }
        return current;
    }

    Node* minValue(Node* current) {
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    int sumValuesRecursive(Node* current) {
        if (current == nullptr) return 0;
        return current->value + sumValuesRecursive(current->left) + sumValuesRecursive(current->right);
    }

    void visualizeNode(Node* current, const string& prefix, bool isTail) {

        if (current != nullptr) {
            cout << prefix << (isTail ? "\ " : "/ ")
                << "Key: " << current->key << " | Value: " << current->value << endl;

            if (current->left != nullptr) {
                visualizeNode(current->left, prefix + (isTail ? "    " : "│   "), current->right == nullptr);
            }

            if (current->right != nullptr) {
                visualizeNode(current->right, prefix + (isTail ? "    " : "│   "), true);
            }
        }
    }

    void destroyTree(Node* current) {
        if (current != nullptr) {
            destroyTree(current->left);
            destroyTree(current->right);
            delete current;
        }
    }

public:
    BSTree() : root(nullptr) {}

    ~BSTree() {
        destroyTree(root);
    }

    void insert(int key, int value) {
        root = insertRecursive(root, key, value);
    }

    bool search(int key) {
        return searchRecursive(root, key);
    }

    void remove(int key) {
        root = deleteRecursive(root, key);
    }

    void printSum() {
        cout << "Сумма значений всех вершин: " << sumValuesRecursive(root) << endl;
    }

    void visualize() {
        if (root == nullptr) {
            cout << "Дерево пустое." << endl;
            return;
        }
        cout << "Структура дерева:\n";
        cout << "Root: Key: " << root->key << " | Value: " << root->value << endl;

        if (root->left != nullptr)
            visualizeNode(root->left, "", root->right == nullptr);
        if (root->right != nullptr)
            visualizeNode(root->right, "", true);
    }
};

// --- Меню пользователя ---
void showMenu() {
    cout << "\n--- Меню ---\n";
    cout << "1. Добавить элемент (ключ и значение)\n";
    cout << "2. Удалить элемент\n";
    cout << "3. Найти ключ\n";
    cout << "4. Вывести сумму значений всех вершин\n";
    cout << "5. Наглядный вывод дерева\n";
    cout << "0. Выход\n";
    cout << "Выберите опцию: ";
}

int main() {
    system("chcp 65001"); // Переключает консоль на UTF-8
    setlocale(LC_ALL, "rus");
    BSTree tree;
    int choice, key, value;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите ключ: ";
            cin >> key;
            cout << "Введите значение: ";
            cin >> value;
            tree.insert(key, value);
            break;
        case 2:
            cout << "Введите ключ для удаления: ";
            cin >> key;
            tree.remove(key);
            break;
        case 3:
            cout << "Введите ключ для поиска: ";
            cin >> key;
            cout << (tree.search(key) ? "Ключ найден" : "Ключ не найден") << endl;
            break;
        case 4:
            tree.printSum();
            break;
        case 5:
            tree.visualize();
            break;
        case 0:
            cout << "Выход..." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}