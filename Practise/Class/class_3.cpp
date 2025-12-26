#include <iostream>
class coo {
private:
	int c;
public:
	coo(int a) {
		c = a;
	}
	Test(const coo& co) {   
		c = co.c;
	}
	int get() const { 
		return c;
	}
};

int main()
{
	coo co1(7);       
	coo co2 = co1;       
	std::cout << "co1=" << co1.get() << std::endl;
	std::cout << "co2=" << co2.get() << std::endl;
}
