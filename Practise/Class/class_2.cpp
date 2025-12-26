#include <iostream>
class Print {
private:
	int A;

public:
	int PrintA(int AA) {
		A = AA;
		return A;
			}
	};

int main() {
	Print x; 

	int result = x.PrintA(1);

	std::cout << "Result: " << result << std::endl;

	return 0;
}
