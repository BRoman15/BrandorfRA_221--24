#pragma once

struct Point{
    int x, y;
};


struct Circle {
    Point centre;
    int radius;
};

struct Square {
    Point upper_left_corner;
    int side_length;
};

