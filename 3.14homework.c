//7.1
#include <stdio.h>
#include <math.h>

int main() {
    int speed, limit;
    scanf("%d %d", &speed, &limit);
    
    double percent = (speed - limit) * 100.0 / limit;
    if (percent < 10) {
        printf("OK");
    } else if (percent < 50) {
        printf("Exceed %.0f%%. Ticket 200", round(percent)); 
    } else {
        printf("Exceed %.0f%%. License Revoked", round(percent));
    }
    return 0;
}

//7.2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long double a, b, c;
    scanf("%Lf %Lf %Lf", &a, &b, &c);

    if (a == 0 && b == 0 && c == 0) 
    {
        printf("Zero Equation\n");
    }
    else if (a == 0 && b == 0)
    {
        printf("Not An Equation\n");
    }
    else if (a == 0) 
    {
        long double root = -c / b;
        if (fabsl(root) < 1e-9)
            root = 0;
        printf("%.2Lf\n", root);
    }
    else {
        long double delta = b * b - 4 * a * c;
        if (delta > 0) {
            long double root1 = (-b + sqrtl(delta)) / (2 * a);
            long double root2 = (-b - sqrtl(delta)) / (2 * a);
            if (fabsl(root1) < 1e-9)
                root1 = 0;
            if (fabsl(root2) < 1e-9)
                root2 = 0;
            if (root1 < root2) {
                long double temp = root1;
                root1 = root2;
                root2 = temp;
            }
            printf("%.2Lf\n%.2Lf\n", root1, root2);
        }
        else if (fabsl(delta) < 1e-9) {
            long double root = -b / (2 * a);
            if (fabsl(root) < 1e-9)
                root = 0;
            printf("%.2Lf\n", root);
        }
        else {
            long double realPart = -b / (2 * a);                // 实部
            long double imaginaryPart = sqrtl(-delta) / (2 * a);  // 虚部
            if (fabsl(realPart) < 1e-9)
                realPart = 0;
            printf("%.2Lf+%.2Lfi\n", realPart, imaginaryPart);
            printf("%.2Lf-%.2Lfi\n", realPart, imaginaryPart);
        }
    }
    system("pause");
    return 0;
}

//7.3
#include <stdio.h>
int main()
{
    int minute, hour;
    scanf("%d:%d", &hour, &minute);
    if (hour < 12)
    {
        printf("%d:%d AM", hour, minute);
    }
    else if (hour == 12)
    {
        printf("%d:%d PM", hour, minute);
    }
    
    else
    {
        hour = hour - 12;
        printf("%d:%d PM", hour, minute);
    }
    
    return 0;
}

//7.4
#include <stdio.h>
int main()
{
    int year;
    scanf("%d", &year);
    if ((year%4==0 && year%100!=0) || (year%400==0))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}

//7.5
#include <stdio.h>
int main()
{
    float x, pay;
    scanf("%f", &x);
    if (x < 0)
    {
        printf("f(%.2f) = 0.00",x);
    }
    else if (x <= 15)
    {
        pay = 4.0 / 3 * x;
        printf("f(%.2f) = %.2f", x, pay);
    }
    else
    {
        pay = 2.5 * x - 10.5;
        printf("f(%.2f) = %.2f", x, pay);
    }
    
    return 0;
}

//7.6
#include <stdio.h>
int main()
{
    int weight, cost, over;
    char add;
    scanf("%d %c", &weight, &add);
    if (weight <= 1000)
    {
        cost = 8;
    }
    else
    {
        over = weight - 1000;
        cost = 8 + ((over + 499) / 500) * 4;//向上取整进行计算
        
    }
    if (add == 'y')
    {
        cost += 5;
    }
    printf("%d", cost);
    
    return 0;
}

//7.7
#include <stdio.h>
int main()
{
    float a, b, result;
    char symbol;
    scanf("%f %c %f", &a, &symbol, &b);
    if (symbol == '/' && b == 0.0)
    {
        printf("The divisor is 0.");
    }
    else
    {
        if (symbol == '+')
        {
            result = a + b;
        }
        else if (symbol == '-')
        {
            result = a - b;
        }
        else if (symbol == '*')
        {
            result = a * b;
        }
        else
        {
            result = a / b;
        }
        printf("%.2f", result);
    }

    return 0;
}

//7.8
#include <stdio.h>
int main()
{
    int day = 0;
    scanf("%d", &day);
    
    switch (day)
    {
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        case 7:
            printf("Sunday");
            break;
        default:
            printf("-1");
            break;
    }
    
    return 0;
}

//7.9
#include <stdio.h>
int main()
{
    int num1, num2;
    char op;
    scanf("%d %c %d", &num1, &op, &num2);
    switch (op)
    {
    case '&':
        printf("%d & %d = %d", num1, num2, num1 & num2);
        break;
    case '|':
        printf("%d | %d = %d", num1, num2, num1 | num2);
        break;
    case '^':
        printf("%d ^ %d = %d", num1, num2, num1 ^ num2);
        break;
    default:
        printf("ERROR");
        break;
    }
    
    return 0;
}

//7.10
#include <stdio.h>

int main()
{
    int year, month, days;
    scanf("%d %d", &year, &month);
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
        if ((year%4==0 && year%100!=0) || (year%400==0))
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
    default:
        break;
    }
    printf("%d", days);
    
    return 0;
}
