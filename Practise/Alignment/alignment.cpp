#include <iostream>
class coo {
public:
	int a;
	int b;
	double c;
	char d;

    coo() {}
    ~coo() {}
};
int main()
{
    coo x;
    std::cout << sizeof(x) << std::endl;       //  * 24  * //
}
