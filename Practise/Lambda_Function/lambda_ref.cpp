#include <iostream>

int main() {
	int a = 11;

	auto ref = [&a]() {
		a += 5;
		};

	ref();
	std::cout << a; //aranc & chenq karox popoxel
}
