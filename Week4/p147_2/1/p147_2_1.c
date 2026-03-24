#include <stdio.h>

int reverse(int n)
{
    int result = 0;

    while(n != 0)
    {
        result = result * 10 + n % 10;
        n = n / 10;
    }

    return result;
}

int main()
{
    int num = 12345;
    int r;

    r = reverse(num);

    printf("reverse=%d", r);
}
