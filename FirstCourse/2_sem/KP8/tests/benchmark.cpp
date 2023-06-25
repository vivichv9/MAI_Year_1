#include "../include/List.hpp"
#include <forward_list>
#include <chrono>

void benchmark() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    List<int> myLs;
    std::forward_list<int> stdLs;

    std::cout << "Push_front:" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdLs.push_front(i);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myLs.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << std::endl;

    std::cout << "Pop_front:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdLs.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myLs.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Push_back(1000):" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        myLs.push_back(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << std::endl;

    std::cout << "pop_back(1000):" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000; ++i){
        myLs.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;


}