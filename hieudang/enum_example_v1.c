#include <stdio.h>

enum Color { //enum la bien nguyen, kich thuoc 2 byte
    red, //0
    green, //1
    blue, //2
};

int main(){
    enum Color myColor;// myColor is a variable of type enum Color
    myColor = green;
    printf("The color is chosen is %d\n", myColor);
    return 0;
}