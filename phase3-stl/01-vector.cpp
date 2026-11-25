#include <iostream>
#include <vector>

struct Sample {
    unsigned int t;
    short ax, ay, az;
};

double mean_ax(std::vector<Sample> v) {
    if (v.empty()) return 0.0;
    double sum = 0.0;
    for (const auto& s : v) sum += s.ax;
    return sum / v.size();
}

int main() {
    std::vector<Sample> data;
    
    std::cout << "size " << data.size() << " capacity " << data.capacity() << "\n";

    for (unsigned int i = 0; i < 5; i++) {
        data.push_back({i * 10, static_cast<short>(i * 100), 0, 980});
        std::cout << " capacity " << data.capacity() << "\n";
    }
    std::cout << "size " << data.size() << " capacity " << data.capacity() << "\n";
    std::cout << "mean ax " << mean_ax(data) << "\n";

    data.push_back({50, 500, 0, 980});   // exceeds reserve
    std::cout << " capacity " << data.capacity() << "\n";
    std::cout << "size " << data.size() << " capacity " << data.capacity() << "\n";

    std::cout << "last t " << data.back().t << "\n";
    return 0;
}