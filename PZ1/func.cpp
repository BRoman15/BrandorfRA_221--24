#include "structs.h"
#include <iostream>
#include "func.h"
#include <cmath>
using namespace std;

void cntering_point_coordinates(Point* a){
    int cx, cy;
    cout << "Enter the coordinates of the point" << endl;
    cout << "x: ";
    cin >> cx;
    cout << "y: ";
    cin >> cy;
    (a->x) = cx;
    (a->y) = cy;
}

void conclusion_point_coordinates(Point a){
    cout << "x: "<< a.x << " " << "y: " << a.y << endl << endl;
}


void circle_inf_input(Circle* b){
    int cx, cy, r;
    cout << "Enter the information of the circle" << endl;
    cout << "centre x: ";
    cin >> cx;
    cout << "centre y: ";
    cin >> cy;
    cout << "radius: ";
    cin >> r;
    (b -> centre.x) = cx;
    (b -> centre.y) = cy;
    (b -> radius) = r;
}

void circle_inf_conclusion(Circle b){
    cout << "centre x: "<< b.centre.x << " " << "centre y: " << b.centre.y << "radius: " << b.radius << endl << endl;
}

void length_circule(Circle b){
    cout << "length of circule: " << 2 * M_PI * b.radius;
}

void square_circule(Circle b){
    cout << "Square of circule" << M_PI * b.radius * b.radius;
}

void square_inf_input(Square* c){
    int cx, cy, l;
    cout << "Enter the information of the square" << endl;
    cout << "Upper left corner x: ";
    cin >> cx;
    cout << "Upper left corner y: ";
    cin >> cy;
    cout << "Side length: ";
    cin >> l;
    (c -> upper_left_corner.x) = cx;
    (c -> upper_left_corner.y) = cy;
    (c -> side_length) = l;
}

void square_inf_conclusion(Square c){
    cout << "Upper left corner x: "<< c.upper_left_corner.x << " " << "Upper left corner y: " << c.upper_left_corner.y << "Side length: " << c.side_length << endl << endl;
}

void square_perimeter_square(Square c){
    cout << "Perimeter: " << c.side_length*4 << endl << "Square: " << c.side_length * c.side_length;
}

void point_in_circle(Point a, Circle b){
    if (sqrt((a.x-b.centre.x)*(a.x-b.centre.x)+(a.y-b.centre.y)*(a.y-b.centre.y))<b.radius){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

void poit_in_square(Point a, Square c){
    if ((a.x > c.upper_left_corner.x and a.y < c.upper_left_corner.y) and ((a.x - c.upper_left_corner.x) < c.side_length and (c.upper_left_corner.y - a.y) < c.side_length)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

void point_on_circle(Point a, Circle b){
    if (sqrt((a.x - b.centre.x) * (a.x - b.centre.x) + (a.y - b.centre.y) * (a.y - b.centre.y)) == b.radius){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

void poit_on_square(Point a, Square c){
    if ((a.x == c.upper_left_corner.x and c.upper_left_corner.y - a.y < c.side_length) or (a.y == c.upper_left_corner.y and a.y - c.upper_left_corner.x < c.side_length) or (a.x == c.upper_left_corner.x - c.side_length and c.upper_left_corner.y - a.y < c.side_length) or (a.y == c.upper_left_corner.y - c.side_length and a.y - c.upper_left_corner.x < c.side_length)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

void intersection_of_circles(Circle b, Circle i){
    if (sqrt((b.centre.x - i.centre.x) * (b.centre.x - i.centre.x) + (b.centre.y - i.centre.y) * (b.centre.y - i.centre.y)) <= b.radius + i.radius){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

void intersection_of_square(Square c, Square f){
    if ((c.upper_left_corner.x + c.side_length < f.upper_left_corner.x) or (c.upper_left_corner.y - c.side_length > f.upper_left_corner.y) or (c.upper_left_corner.x > f.upper_left_corner.x + f.side_length) or (c.upper_left_corner.y < f.upper_left_corner.y - f.side_length)){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
}

void intersection_of_circles_and_square(Circle b, Square c){
    int x1, y1, projection_x, projection_y;

    x1 = max(c.upper_left_corner.x, min(b.centre.x,c.upper_left_corner.x + c.side_length));
    y1 = min(c.upper_left_corner.y, max(b.centre.y,c.upper_left_corner.y - c.side_length));
    projection_x = c.upper_left_corner.x - x1;
    projection_y = c.upper_left_corner.y - y1;

    if (sqrt(projection_x * projection_x + projection_y * projection_y) < b.radius){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

void circle_in_circle(Circle b, Circle i){
    if (sqrt((b.centre.x-i.centre.x) * (b.centre.x-i.centre.x) + (b.centre.y-i.centre.y) * (b.centre.y-i.centre.y)) + b.radius <= i.radius){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

void square_in_square(Square c, Square f){
    if ((c.upper_left_corner.x >= f.upper_left_corner.x and c.upper_left_corner.y <= f.upper_left_corner.y) and (c.upper_left_corner.x + c.side_length <= f.upper_left_corner.x + f.side_length) and (c.upper_left_corner.y - c.side_length >= f.upper_left_corner.y - f.side_length)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

void square_in_circle(Circle b, Square c){
    if (((c.upper_left_corner.x - b.centre.x) * (c.upper_left_corner.x - b.centre.x) + (c.upper_left_corner.y - b.centre.y) * (c.upper_left_corner.y - b.centre.y) <= b.radius* b.radius) and \
    ((c.upper_left_corner.x + c.side_length - b.centre.x) * (c.upper_left_corner.x + c.side_length - b.centre.x) + (c.upper_left_corner.y - b.centre.y) * (c.upper_left_corner.y - b.centre.y) <= b.radius* b.radius) and \
    ((c.upper_left_corner.x - b.centre.x) * (c.upper_left_corner.x - b.centre.x) + (c.upper_left_corner.y - c.side_length - b.centre.y) * (c.upper_left_corner.y - c.side_length - b.centre.y) <= b.radius* b.radius) and \
    ((c.upper_left_corner.x + c.side_length - b.centre.x) * (c.upper_left_corner.x + c.side_length - b.centre.x) + (c.upper_left_corner.y - c.side_length - b.centre.y) * (c.upper_left_corner.y - c.side_length - b.centre.y) <= b.radius* b.radius)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

void circle_in_square(Circle b, Square c){
    int left_circle = b.centre.x - b.radius;
    int top_circle = b.centre.y + b.radius;
    int right_circle = b.centre.x + b.radius;
    int bottom_circle = b.centre.y - b.radius;

    if (left_circle >= c.upper_left_corner.x and top_circle <= c.upper_left_corner.y and right_circle <= c.upper_left_corner.x + c.side_length and bottom_circle >= c.upper_left_corner.y - c.side_length){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}