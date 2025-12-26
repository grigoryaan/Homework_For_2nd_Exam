#include <iostream>

class Ptr {
private:
    int* ptr;

public:

    Ptr(int* value)
        : ptr(value) {}

    ~Ptr() {
        delete ptr;
    }

    int& operator*() {
        return *ptr;
    }

    int* operator->() {
        return ptr;
    }
};

int main() {
    Ptr p(new int(77));

    std::cout << *p << std::endl; // 77

    return 0;
}
