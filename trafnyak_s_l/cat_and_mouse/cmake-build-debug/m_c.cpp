#include <geom/geom.hpp>
#include<iostream>

int Life_or_death(const double& dt, const double& mod_speed_mouse_start, Rdec2D& r_mouse, const double& mod_speed_cat_start, Rdec2D& r_cat, const double& r_kill) {

    // мыш
    Rdec2D speed_mouse = (Rdec2D{ 0.0, 0.0 } - r_mouse) / Norm(Rdec2D{ 0.0, 0.0 } - r_mouse) * mod_speed_mouse_start;
    Rdec2D delta_r_mouse;
    Rdec2D past_r_mouse = r_mouse;

    // кошь
    Rdec2D speed_cat = (r_mouse - r_cat) / Norm(r_mouse - r_cat) * mod_speed_cat_start;
    Rdec2D delta_r_cat;
    Rdec2D past_r_cat = r_cat;

    for (double t = 0.0; t < 1000.0; t += dt) {
        // ворк мыш
        speed_mouse = (Rdec2D{ 0.0, 0.0 } - r_mouse) / Norm(Rdec2D{ 0.0, 0.0 } - r_mouse) * mod_speed_mouse_start;
        delta_r_mouse = speed_mouse * dt;
        r_mouse += delta_r_mouse;
        std::cout << "r_mouse " << r_mouse << std::endl;
        // ворк кошь
        speed_cat = (r_mouse - r_cat) / Norm(r_mouse - r_cat) * mod_speed_cat_start;
        delta_r_cat = speed_cat * dt;
        r_cat += delta_r_cat;
        std::cout << "r_cat " << r_cat << std::endl;
        // бряк
        if (r_mouse.y >= 0) {
            std::cout << "mouse won:)";
            return 1;
            break;
        }
        else {
            if (Norm(r_mouse - r_cat) <= r_kill) {
                std::cout << "mouse died:(";
                return 2;
                break;
            }
            else {
                if (Norm(r_mouse - r_cat) > Norm(past_r_mouse - past_r_cat)) {
                    std::cout << "mouse will win<3";
                    return 3;
                    break;
                }
            }
        }
        past_r_mouse = r_mouse;
        past_r_cat = r_cat;
    }
}
int main() {
    double dt = 0.0001;
    double mod_speed_mouse_start = 1.0;
    Rdec2D r_mouse = { 0,-10 };//положение мышки
    double mod_speed_cat_start = mod_speed_mouse_start;
    Rdec2D r_cat = { 10,0 };//положение кошки
    double r_kill = 0.0001;
    /*while (Life_or_death(dt, mod_speed_mouse_start, r_mouse, mod_speed_cat_start, r_cat, r_kill) == 1) {
       mod_speed_cat_start +=dt;//1.3886
    }*/
    Life_or_death(dt, mod_speed_mouse_start, r_mouse, mod_speed_cat_start, r_cat, r_kill);
    //std::cout << mod_speed_cat_start;
    // Life_or_death(dt, mod_speed_mouse_start, r_mouse, mod_speed_cat_start, r_cat, r_kill);
}