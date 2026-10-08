#include "stack.h"

void Stack::push(int value) {
    elements.push_back(value);
}

int Stack::pop() {
    if (!elements.empty()) {
        int value = elements.back();
        elements.pop_back();
        return value;
    }
    else {
        throw std::out_of_range("Стек пуст!");
    }
}

int Stack::top() {
    if (!elements.empty()) {
        return elements.back();
    }
    else {
        throw std::out_of_range("Стек пуст!");
    }
}

bool Stack::isEmpty() const {
    return elements.empty();
}

void Stack::clear() {
    elements.clear();
}

void Stack::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int value : elements) {
            file << value << "\n";
        }
        file.close();
    }
    else {
        throw std::ios_base::failure("Не удалось открыть файл для сохранения!");
    }
}

void Stack::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        elements.clear();
        int value;
        while (file >> value) {
            elements.push_back(value);
        }
        file.close();
    }
    else {
        throw std::ios_base::failure("Не удалось открыть файл для загрузки!");
    }
}

bool Stack::hasElementInRange(int lower, int upper) const {
    for (int value : elements) {
        if (value >= lower && value <= upper) {
            return true;
        }
    }
    return false;
}
