#include <iostream>

class stud {
public:
	int age;
	void ShowAge() {
		std::cout << "Mutqagreq dzer tariqy: ";
		std::cin >> age;
		std::cout << "Duq " << age << " tarekan eq" << std::endl;
	}
};

int main() {
	stud s;
	s.ShowAge();
}
