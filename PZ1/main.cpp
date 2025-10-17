#include <iostream>
#include <iomanip>
#include "structs.h"
#include "func.h"
using namespace std;


int main(){

    Point A;
    Circle B;
    Square C, F;
    // cntering_point_coordinates(&A);
    // conclusion_point_coordinates(A);
    circle_inf_input(&B);
    // circle_inf_conclusion(B);
    // length_circule(B);
    // square_circule(B);
    square_inf_input(&C);
    // square_inf_input(&F);
    // square_inf_conclusion(C);
    // square_perimeter_square(C);
    // point_in_circle(A, B);
    // poit_in_square(A, C);
    // point_on_circle(A, B);
    // poit_on_square(A, C);
    // intersection_of_square(C, F);
    // intersection_of_circles_and_square(B, C);
    // square_in_square(C, F);
    // square_in_circle(B, C);
    circle_in_square(B, C);
    return 0;
}