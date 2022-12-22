#include <geom/geom.hpp>
#include<iostream>
#include <cmath>
#include <fstream>

#define C1 0.01
#define C2 50.0
#define num_of_itterations 10

int main() {
    std::ofstream output_file;
    output_file.open("out.csv");
    output_file << "mouse_x" << ";" << "mouse_y" << ";" << "cat_x" << ";" << "cat_y" << ";"
                << "mouse_a_x" << ";" << "mouse_a_y" << ";" << "|V_mouse|" << ";" << "|V_cat|"  << std::endl;
    double x, y;
    std::cin >> x >> y;
    Rdec2D V_cat{x, y};

    std::cin >> x >> y;
    Rdec2D coord_cat{x, y};

    std::cin >> x >> y;
    Rdec2D coord_mouse{x, y};

    std::cin >> x >> y;
    Rdec2D V_mouse{x, y};

    std::cin >> x >> y;
    Rdec2D mouse_house{x, y};

    Rdec2D a_mouse{0, 0};

    double mouse_x[num_of_itterations];
    double mouse_y[num_of_itterations];
    double cat_x[num_of_itterations];
    double cat_y[num_of_itterations];
    for (int i = 0; i < num_of_itterations; i++) {
        V_cat = (coord_mouse - coord_cat) / Norm(coord_mouse - coord_cat) * Norm(V_cat);
        Rdec2D temp_vec = coord_mouse - coord_cat;
        a_mouse = (temp_vec) * C1 / ((Norm(temp_vec)) + C2);
        V_mouse += a_mouse;

        coord_cat += V_cat;
        coord_mouse += V_mouse;

        output_file << coord_mouse.x << ";" << coord_mouse.y << ";" << coord_cat.x << ";" << coord_cat.y << ";"
                    << a_mouse.x << ";" << a_mouse.y << ";" << Norm(V_mouse) << ";" << Norm(V_cat) << std::endl;

    }

    output_file.close();
    return 0;
}