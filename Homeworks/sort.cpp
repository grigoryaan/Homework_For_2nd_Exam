#include <iostream>
#include <vector>
#include <algorithm>

int counter = 0;

bool comp(int x, int y) {
    counter++;
    if ((x % 2) != (y % 2))
        return x % 2 > y % 2;
    if (x % 2 == 1)
        return x > y;
    return x < y;
}

int main() {
    int size;
    do {
        std::cout << "n="; std::cin >> size;
    } while (size < 2);
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        std::cout << "v[" << i << "]=";
        std::cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\nCompars: " << counter << std::endl;
}
