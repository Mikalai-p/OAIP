#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>
#include <vector>

class Stack {
private:
    std::vector<int> elements;

public:
    void push(int value);
    int pop();
    int top();
    bool isEmpty() const;
    void clear();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    bool hasElementInRange(int lower, int upper) const;
};

#endif
