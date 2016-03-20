#include <iostream>
using namespace std;
/*
   Write a function that calculates the intersection of two rectangles, returning
   either a new rectangle or some kind of null value.

   You're free to represent these rectangles in any way you want: tuples of numbers,
   class objects, new datatypes, anything goes. For this challenge, you'll probably
   want to represent your rectangles as the x and y values of the top-left and
   bottom-right points. (Rect(3, 3, 10, 10) would be a rectangle from (3, 3)
   (top-left) to (10, 10) (bottom-right).)

   As an example, rectIntersection(Rect(3, 3, 10 10), Rect(6, 6, 12, 12)) would
   return Rect(6, 6, 10, 10), while rectIntersection(Rect(4, 4, 5, 5),
   Rect(6, 6, 10 10)) would return null.

 */

typedef struct xyplane{
    size_t x;
    size_t y;
}XY;

typedef struct rectangle{
    XY a;
    XY b;
    XY c;
    XY d;
}R;


R
createRect(size_t ax, size_t ay, size_t bx, size_t by, size_t cx, size_t cy, size_t dx, size_t dy){
    R rect;
    rect.a.x = ax; rect.a.y = ay;
    rect.b.x = bx; rect.b.y = by;
    rect.c.x = cx; rect.c.y = cy;
    rect.d.x = dx; rect.d.y = dy;
    return rect;
}

bool
equals(R r1, R r2){
    if(r1.a.x == r2.a.x && r1.b.x == r2.b.x && r1.c.x == r2.c.x && r1.d.x == r2.d.x &&
        r1.a.x == r2.a.y && r1.b.y == r2.b.y && r1.c.y == r2.c.y && r1.d.y == r2.d.y)
        return 1;
    return 0;
}

R
rectIntersection(R r1, R r2){
    R r3;
    //assign x values
    (r1.a.x < r2.a.x ? r3.a.x = r1.a.x : r3.a.x = r2.a.x);
    (r1.b.x < r2.b.x ? r3.b.x = r1.b.x : r3.b.x = r2.b.x);
    (r1.c.x < r2.c.x ? r3.c.x = r1.c.x : r3.c.x = r2.c.x);
    (r1.d.x < r2.d.x ? r3.d.x = r1.d.x : r3.d.x = r2.d.x);
    //assign y values
    (r1.a.y < r2.a.y ? r3.a.y = r1.a.y : r3.a.y = r2.a.y);
    (r1.b.y < r2.b.y ? r3.b.y = r1.b.y : r3.b.y = r2.b.y);
    (r1.c.y < r2.c.y ? r3.c.y = r1.c.y : r3.c.y = r2.c.y);
    (r1.d.y < r2.d.y ? r3.d.y = r1.d.y : r3.d.y = r2.d.y);
    if (equals(r3,r2))
        r3 = createRect(0,0,0,0,0,0,0,0);           //NULL RECT
    return r3;
}

void
printRect(R r3){
    cout << "(" <<  r3.a.x << ", " << r3.a.y << ")"<< endl << "(" << r3.b.x << ", " << r3.b.y << ")" << endl << "(" << r3.c.x << ", " << r3.c.y << ")" << endl << "(" << r3.d.x << ", " << r3.d.y << ")" << endl;
}

int
main(void){
    R r1,r2;
    r1 = createRect(0,0,4,0,4,3,0,4);
    r2 = createRect(0,0,2,0,2,4,0,2);
    R r3 = rectIntersection(r1,r2);
    printRect(r3);
}
