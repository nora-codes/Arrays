#include <stdio.h>
#include <cs50.h>

bool check_sides(float x, float y, float z);

int main(void)
{

    //get triangle sides and check they are positive numbers

    float a, b, c;

    do
    {
        a = get_float("Side a: ");
    }
    while (a <= 0);

    do
    {
        b = get_float("Side b: ");
    }
    while (b <= 0);

    do
    {
        c = get_float("Side c: ");
    }
    while (c <= 0);

    // call check_sides to check the triangle calculation
    // print result

    if ((check_sides(a, b, c) == 1) && (check_sides(b, c, a) == 1) && (check_sides(a, c, b) == 1))
    {
        printf("True\n");
    }

    else
    printf("False\n");
}

bool check_sides(float x, float y, float z)
{
    float sum = x + y;

    if(sum > z)
    {
        return 1;
    }

    else
    return 0;
}
