// DAAAB DABC
// 6.1
int fun(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else if (n > 2)
    {
        // return fun(n - 1) + fun(n - 2); 递归法，重复调用函数
        int a = 1, b = 1, c; // 循环法
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
    else
    {
        return 0;
    }
}

// 6.2
void CharPyramid(int n, char ch)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++) // 打印n-行数个空格
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++) // 打印从1到n个字符与空格
        {
            printf("%c ", ch);
        }
        printf("\n");
    }
}

// 6.3
int IsAutomorphic(int x)
{
    long final = x * x;
    int temp = x;
    while (temp > 0)
    {
        if (final % 10 != temp % 10) // 自守判断
        {
            return 0;
        }
        final /= 10; // 去除最后一位
        temp /= 10;
    }
    return 1;
}
void FindAutomorphic(int lower, int upper)
{
    int flag = 0;
    for (int i = lower; i <= upper; i++) // 循环判断区间内的数
    {
        if (IsAutomorphic(i))
        {
            printf("%d\n", i);
            flag = 1; // 找到了自守数，不输出none
        }
    }
    if (flag)
    {
        printf("None\n");
    }
}

// 7.1
#include <stdio.h>
int main()
{
    double eps;
    scanf("%le", &eps);
    double sum = 1.0, up = 1.0, down = 1.0; // up分子，down分母
    int i = 1;
    if (eps < 1) // eps>=1为特殊情况，sum直接为1
    {
        while (1)
        {
            up *= i;
            down *= (2 * i + 1);
            double term = up / down; // 计算当前项
            sum += term;             // 累加精度
            if (term < eps)          // 判断精度
            {
                break;
            }
            i++;
        }
    }
    double pi = sum * 2;
    printf("PI = %.5f\n", pi);
    getchar();
    getchar();
    return 0;
}

// 7.2
#include <stdio.h>
#include <math.h>

int is_prime(int num);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (is_prime(num)) // 通过返回的真假判断输出结果
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

int is_prime(int num)
{
    if (num <= 1)
    {
        return 0; // 1 和更小的数都不是素数
    }
    if (num == 2)
    {
        return 1; // 2 是素数
    }
    if (num % 2 == 0)
    {
        return 0; // 排除偶数
    }
    // 只检查奇数
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
        {
            return 0; // 找到可以整除的数，不是素数
        }
    }
    return 1; // 找不到，是素数
}

// 7.3
#include <stdio.h>
int main()
{
    int key;
    // 读入密钥
    scanf("%d", &key);
    getchar(); // 吸收掉换行符

    // 解密时的实际移动量
    // 因为字母表是 26 个字母，需要先将移动量规约到 [0, 25]
    int shift = (-key) % 26;
    if (shift < 0)
    {
        shift += 26;
    }

    char c;
    // 从标准输入读入一行密文（直到遇到换行或 EOF）
    while ((c = getchar()) != EOF && c != '\n')
    {
        // 如果是大写字母 A-Z
        if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' + shift) % 26 + 'A';
        }
        // 如果是小写字母 a-z
        else if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + shift) % 26 + 'a';
        }
        putchar(c);
    }

    // 输出换行
    putchar('\n');
    return 0;
}