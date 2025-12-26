#include <iostream>

struct heap_data {
    size_t length;       
    size_t cap;   
    char* ptr;    
};

union storage {
    heap_data large;       
    char    small[24]; 
};

class str {
private:
    storage buffer;       
    size_t sz;   

    bool is_short() const { 
        return sz <= 23;
    }

    char* get_ptr() {
        return is_short() ? buffer.small : buffer.large.ptr;
    }

    const char* get_ptr() const {
        return is_short() ? buffer.small : buffer.large.ptr;
    }

    void check_space(size_t required) {
        if (required <= 23) return;
               
        if (is_short()) {
            buffer.large.length = sz;
            buffer.large.cap = required;
            buffer.large.ptr = new char[required + 1];
            std::memcpy(buffer.large.ptr, buffer.small, sz);
            buffer.large.ptr[sz] = '\0';
            return;
        }

        if (required <= buffer.large.cap) return;

        char* temp = new char[required + 1];
        std::memcpy(temp, buffer.large.ptr, sz);
        temp[sz] = '\0';
        delete[] buffer.large.ptr;
        buffer.large.ptr = temp;
        buffer.large.cap = required;
        buffer.large.length = sz;
    }

public:
    str(const char* text) {
        sz = std::strlen(text);

        if (is_short()) {
            strcpy_s(buffer.small, sizeof(buffer.small), text); 
            buffer.large.ptr = nullptr;
        }
        else {
            buffer.large.length = sz;
            buffer.large.cap = sz;
            buffer.large.ptr = new char[sz + 1];
            strcpy_s(buffer.large.ptr, sz + 1, text);
        }
    }

    ~str() {
        if (!is_short() && buffer.large.ptr)
            delete[] buffer.large.ptr;
    }

    void print() const {
        if (is_short())
            std::cout << buffer.small << std::endl;
        else
            std::cout << buffer.large.ptr << std::endl;
    }

    void where() const {
        if (is_short())
            std::cout << "Saved in Stack (SSO)" << std::endl;
        else
            std::cout << "Saved in Heap" << std::endl;
    }

    size_t size() const {
        return sz;
    }

    size_t capacity() const {
        return is_short() ? 23 : buffer.large.cap;
    }

    const char* c_str() const {
        return get_ptr();
    }

    void clear() {
        if (is_short()) {
            buffer.small[0] = '\0';
        }
        else {
            buffer.large.ptr[0] = '\0';
            buffer.large.length = 0;
        }
        sz = 0;
    }

    char& operator[](size_t i) {
        return get_ptr()[i];
    }

    const char& operator[](size_t i) const {
        return get_ptr()[i];
    }

    void reserve(size_t new_cap) {
        if (new_cap <= capacity()) return;
        check_space(new_cap);
    }

    void push_back(char ch) {
        check_space(sz + 1);

        if (is_short()) {
            buffer.small[sz] = ch;
            sz++;
            buffer.small[sz] = '\0';
        }
        else {
            buffer.large.ptr[sz] = ch;
            sz++;
            buffer.large.ptr[sz] = '\0';
            buffer.large.length = sz;
        }
    }

    void append(const char* text) {
        if (!text) return;

        size_t add = std::strlen(text);
        if (add == 0) return;

        size_t new_sz = sz + add;
        check_space(new_sz);

        if (is_short()) {
            std::memcpy(buffer.small + sz, text, add);
            sz = new_sz;
            buffer.small[sz] = '\0';
        }
        else {
            std::memcpy(buffer.large.ptr + sz, text, add);
            sz = new_sz;
            buffer.large.ptr[sz] = '\0';
            buffer.large.length = sz;
        }
    }

    void append(const str& other) {
        append(other.c_str());
    }
};

int main() {
    char text[100];
    std::cout << "Enter Text: ";
    std::cin.getline(text, sizeof(text));

    str a(text);
    a.print();
    a.where();

    a.push_back('!');
    a.append(" HELLO");
    a.print();
    a.where();

    std::cout << "Size: " << a.size() << "\n";
    std::cout << "Capacity: " << a.capacity() << "\n";
    std::cout << "First char: " << a[0] << "\n";

    return 0;
}
