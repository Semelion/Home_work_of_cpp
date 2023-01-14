#include <iostream>

enum seasons{
    spring,
    summer,
    autumn,
    winter
};

int main(int argc, char *argv[]){
//    uint8_t a = 100;
//    uint_fast64_t a = 0;

    std::cout << argc <<"\n";

    for(int i = 1; i < argc; i++){
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    seasons test;
    seasons t = winter;
    std::cout << test << "\t" << t << std::endl;

    for(int i = 0; i <= 10; i++){

        uint_least8_t a8 = i;
        uint16_t a16 = i;
        uint32_t a32 = i;
        uint64_t a64 = i;
        std::cout << a8 << "\t" << a16 << "\t" << a32 << "\t" << a64 << "\n";
    }
}