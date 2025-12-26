#include <iostream>

int main() {
	auto max = [](int a, int b) {
		if (a > b)
			return a;
		else
			return b;
		};

	std::cout << max(1,2);
}
