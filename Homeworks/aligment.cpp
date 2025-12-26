#include <iostream>
#include <vector>

class Layout {
private:
    std::vector<int> memberSizes;     
    std::vector<int> memberOffsets;   
    int totalSize;                

public:

    Layout(const std::vector<int>& sizes)
        : memberSizes(sizes), totalSize(0)
    {
        calculateLayout(); 
    }

private:
    void calculateLayout() {
        memberOffsets.clear();
        int offset = 0;

        for (int i = 0; i < memberSizes.size(); ++i) {
            int align = memberSizes[i];

            if (offset % align != 0) {
                offset += align - (offset % align);
            }

            memberOffsets.push_back(offset);
            offset += align;
        }

        int maxAlign = 0;
        for (int i = 0; i < memberSizes.size(); ++i) {
            if (memberSizes[i] > maxAlign)
                maxAlign = memberSizes[i];
        }

        if (offset % maxAlign != 0) {
            offset += maxAlign - (offset % maxAlign);
        }

        totalSize = offset;
    }

public:
    const std::vector<int>& getOffsets() const {
        return memberOffsets;
    }

    int getTotalSize() const {
        return totalSize;
    }
};

int main() {
    int count;
    std::cout << "Enter count of members: ";
    std::cin >> count;

    std::vector<int> sizes(count);

    std::cout << "Enter size each member: ";
    for (int i = 0; i < count; ++i) {
        std::cin >> sizes[i];
    }

    Layout layout(sizes);

    std::cout << "Class size = "
              << layout.getTotalSize()
              << " bytes\n";

    const std::vector<int>& offsets = layout.getOffsets();

    for (int i = 0; i < offsets.size(); ++i) {
        std::cout << "Member "
                  << i
                  << " starts from "
                  << offsets[i]
                  << " bytes\n";
    }

    return 0;
}
