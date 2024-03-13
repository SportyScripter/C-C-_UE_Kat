#include <stdio.h>

struct Point {
    int x;
    int y;
};

void changePoint(struct Point *p, int x, int y) {
    p->x = x;
    p->y = y;
}
void printPoint(struct Point p) {
    printf("x: %d, y: %d\n", p.x, p.y);
}

struct Rectangle {
    int a;
    int b;
};
void calculateAreaAndPerimeter(struct Rectangle rectangle){
    int calculateArea = 0;
    int calculatePerimeter = 0; 
    calculateArea = rectangle.a * rectangle.b;
    calculatePerimeter = 2 * (rectangle.a + rectangle.b);
    printf("Area: %d, Perimeter: %d\n", calculateArea, calculatePerimeter);
}
int main(){
struct Point p;
p.x = 1;
p.y = 2;
printPoint(p);
changePoint(&p, 3, 4);
printPoint(p);
struct Rectangle r;
r.a = 2;
r.b = 3;
calculateAreaAndPerimeter(r);
}