#include <stdio.h>
int main(){
    printf("scanf one num\n");
    
    int num;
    scanf("%d", &num);
    
    printf("You entered: %d\n", num);
    printf("scanf two nums\n");
    
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    
    printf("You entered: %d and %d\n", num1, num2);
    
    int num3 = num1++;
    
    printf("num1 = %d\n", num1);
    printf("num3 = %d\n", num3);
    
    int num4 = ++num1;
    printf("num1 = %d\n", num1);
    printf("num4 = %d\n", num4);

    return 0;
}