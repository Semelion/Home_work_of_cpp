#include <iostream>
#include <cmath>

bool dot_in_area(double &x, double &y){
    if( (y >= std::abs(x)) && (y <= 2 - x*x) ){
        return true;
    } else{
        return false;
    }
}

int main(){
    double num_of_data = 0.0;
    double right_dots = 0.0;
    double score = 0.0;
    while (std::cin.good()){
        double x,y;
        std::cin >> x >> y;
        if(dot_in_area(x,y)){
            right_dots++;
        }

        num_of_data++;
    }
    score =  double (right_dots/(num_of_data - 1));
    std::cout << score;
}