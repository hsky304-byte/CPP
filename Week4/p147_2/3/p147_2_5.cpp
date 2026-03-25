int reverse(int n);


#include "reverse.h"

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


#include <stdio.h>
#include "reverse.h"

int main()
{
    int num;
    int r;

    printf("정수 입력: ");
    scanf("%d", &num);

    r = reverse(num);

    printf("뒤집은 숫자 = %d\n", r);

    return 0;
}

