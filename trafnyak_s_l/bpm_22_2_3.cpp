#include <iostream>
#include <string>

int main() {
    std::string input = "";
    std::string output = "";
    int size;
    std::cin >> size >> input;

    for (int k = 0; k < size; k++) {
        if (input.size() % 2 == 1) {
            std::string temp1 = "";
            std::string temp2 = "";
            if (output.size() > 1) {
                if(input.size() > 1) {
                    for (int i = 0; i < output.size() / 2; i++) {
                        temp1 += output[i];
                        temp2 += output[output.size() - i - 1];
                    }
                    output = temp1 + input[input.size() / 2 + 1] + temp2;
                } else{
                    output.insert(output.size()/2,input);
                }
            } else {
                if (output.size() == 0) {
                    output = input[input.size() - 1];
                } else {
                    output = input[input.size() - 1] + output;
                }
            }

            temp1 = "";
            for (int i = 0; i < input.size() - 1; i++) {
                temp1 += input[i];
            }
            input = temp1;
        } else {
            std::string temp1 = "";
            std::string temp2 = "";

            if (output.size() > 1) {
                for (int i = 0; i < output.size() / 2; i++) {
                    temp1 += output[i];
                    temp2 += output[output.size() - i - 1];
                }
                output = temp1 + input[input.size() - 1] + output[output.size() / 2] + temp2;
            } else {
                if (output.size() == 0) {
                    output = input[input.size() - 1];
                } else {
                    output = input[input.size() - 1] + output;
                }
            }

            temp1 = "";
            for (int i = 0; i < input.size() - 1; i++) {
                temp1 += input[i];
            }
            input = temp1;
        }
        std::cout << input << "\t" << output << "\n";
    }
    std::cout << output;
}