#include <iostream>

struct TblPtr {
    int identifier;                 
};

struct Parent {
    TblPtr* tablePtr;               
};

struct Child {
    TblPtr* tablePtr;               
    int value;                     
};

TblPtr parent_table = { 1 };        

TblPtr child_table = { 2 };         

Child* custom_cast(Parent* p) {

    if (p == nullptr)
        return nullptr;            

    if (p->tablePtr == &child_table) 
        return (Child*)p;         
    return nullptr;             
}
int main() {
    Child c;
    c.tablePtr = &child_table;
    c.value = 10;

    Parent* p = (Parent*)&c;        
    Child* result = custom_cast(p);
    if (result)
        std::cout << result->value; 
    else
        std::cout << "nullptr"; 
}
