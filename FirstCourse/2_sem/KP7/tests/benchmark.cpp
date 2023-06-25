#include <vector>
#include <chrono>
#include "../include/Vector.hpp"

void benchmark(){
    std::cout << "Initialization(100_000 elements):" << std::endl;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Vector<int> Vec1(100000);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    std::vector<int> vec1(100000);
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Push_back" << std::endl;

    begin = std::chrono::steady_clock::now();
    Vector<int> Vec2;
    for (size_t i = 0; i < 1000000; ++i){
        Vec2.push_back(i);
    }
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    std::vector<int> vec2;
    for (size_t i = 0; i < 1000000; ++i){
        vec2.push_back(i);
    }
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Pop_back:" << std::endl;

    begin = std::chrono::steady_clock::now();
    for (size_t i = 0; i < 1000000; ++i){
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for (size_t i = 0; i < 1000000; ++i){
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Clear:" << std::endl;

    begin = std::chrono::steady_clock::now();
    Vec2.clear();
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    Vec2.clear();
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Shrink_to_fit:" << std::endl;

    begin = std::chrono::steady_clock::now();
    Vec2.shrink_to_fit();
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    vec2.shrink_to_fit();
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Reserve(10000):" << std::endl;

    begin = std::chrono::steady_clock::now();
    for (size_t i = 1; i < 10000; ++i){
        Vec2.reserve(i);
    }
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for (size_t i = 1; i < 10000; ++i){
        vec2.reserve(i);
    }
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Resize:" << std::endl;

    vec2.clear();
    vec2.shrink_to_fit();
    Vec2.clear();   
    Vec2.shrink_to_fit();

    begin = std::chrono::steady_clock::now();
    for (size_t i = 1; i < 10000; ++i){
        Vec2.resize(i);
    }
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for (size_t i = 1; i < 10000; ++i){
        vec2.resize(i);
    }
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    
    Vector<int> Vec3(1000000);
    Vector<int> Vec4(1000000);
    std::vector<int> vec3(1000000); 
    std::vector<int> vec4(1000000);

    std::cout << "==:" << std::endl;

    begin = std::chrono::steady_clock::now();
    if (Vec3 == Vec4){
        end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }

    begin = std::chrono::steady_clock::now();
    if (vec3 == vec4){
        end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "!=:" << std::endl;

    begin = std::chrono::steady_clock::now();
    if (!(Vec3 != Vec4)){
        end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }

    begin = std::chrono::steady_clock::now();
    if (!(vec3 != vec4)){
        end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }

    std::cout << std::endl;
}