// using enum in switch case

#include <stdio.h>

// khai bao enum
enum TrafficLight {
    red =1,
    yellow,
    green,
};

void checkTrafficLight(enum TrafficLight light)
{
    switch (light)
    {
        case red:
        printf("Stop\n");
        break;
        case yellow:
        printf("Ready\n");
        break;
        case green:
        printf("Go\n");
        break;
        default:
        printf("Invalid\n");

    }
}

int main()
{
    enum TrafficLight light = red;
    checkTrafficLight(light);
    return 0;
}