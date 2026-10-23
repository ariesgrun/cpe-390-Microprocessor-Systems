#include <iostream>
#include <chrono>

class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle(int len, int wid) : length(len), width(wid) {}

    inline int area_inline() const {
        return length * width;
    }

    int area_non_inline() const;
};

int Rectangle::area_non_inline() const {
    return length * width;
}

int main() {
    Rectangle r(5000, 7000);

    // non-inline function call
    auto start_time_non_inline = std::chrono::high_resolution_clock::now();
    int result_non_inline = r.area_non_inline();
    auto end_time_non_inline = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_time_non_inline = end_time_non_inline - start_time_non_inline;
    std::cout << "Area (non-inline): " << result_non_inline << std::endl;
    std::cout << "Time taken (non-inline): " << elapsed_time_non_inline.count() << " ms" << std::endl;
    
    // inline function call
    auto start_time_inline = std::chrono::high_resolution_clock::now();
    int result_inline = r.area_inline();
    auto end_time_inline = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_time_inline = end_time_inline - start_time_inline;
    std::cout << "Area (inline): " << result_inline << std::endl;
    std::cout << "Time taken (inline): " << elapsed_time_inline.count() << " ms" << std::endl;
    return 0;
}
