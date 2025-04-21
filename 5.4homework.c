// CBDAB CCCBB

// 5-1:p <= q;if(p->score >= 60) {p->grade = 'P';};else {p->grade = 'F';}
// 5-2: &time.hour, &time.minute, &time.second;time.second;time.second = 0;time.hour = 24

// 6.1
struct complex multiply(struct complex x, struct complex y)
{
    struct complex result;
    result.real = x.real * y.real - x.imag * y.imag;
    result.imag = x.real * y.imag + x.imag * y.real;
    return result;
}

// 7.1
#include <stdio.h>
#include <string.h>
struct book
{
    char name[31];
    double price;
};
int main()
{
    int n;
    scanf("%d", &n);
    struct book booknumber[n];
    for (int i = 0; i < n; i++)
    {
        getchar();                          // 吸收换行符
        gets(booknumber[i].name);           // 获取名称
        scanf("%lf", &booknumber[i].price); // 获取价格
    }
    int max = 0, min = 0;
    for (int i = 0; i < n; i++) // 循环比较
    {
        if (booknumber[i].price > booknumber[max].price)
        {
            max = i;
        }
        if (booknumber[i].price < booknumber[min].price)
        {
            min = i;
        }
    }
    printf("%.2f, %s\n", booknumber[max].price, booknumber[max].name);
    printf("%.2f, %s\n", booknumber[min].price, booknumber[min].name);
    return 0;
}

// 7.2
#include <stdio.h>
#include <string.h>
struct friend
{
    char name[11];
    char birthday[9];
    char phone[18];
};
int main()
{
    int n;
    scanf("%d", &n);
    struct friend friends[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %s", friends[i].name, friends[i].birthday, friends[i].phone);
    }
    for (int i = 0; i < n - 1; i++) // 冒泡排序
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(friends[j].birthday, friends[j + 1].birthday) > 0)
            {
                struct friend temp = friends[j];
                friends[j] = friends[j + 1];
                friends[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s %s %s\n", friends[i].name, friends[i].birthday, friends[i].phone);
    }
    return 0;
}

// 7.3
#include <stdio.h>
struct student
{
    char id[6];
    char name[11];
    int score1;
    int score2;
    int score3;
    int total;
};
int main()
{
    int n;
    scanf("%d", &n);
    struct student students[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d %d %d", students[i].id, students[i].name, &students[i].score1, &students[i].score2, &students[i].score3);
        students[i].total = students[i].score1 + students[i].score2 + students[i].score3;
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i].total > students[max].total)
        {
            max = i;
        }
    }
    printf("%s %s %d\n", students[max].name, students[max].id, students[max].total);
    return 0;
}

// 7.6
#include <stdio.h>
#include <stdlib.h>

// 计算最大公约数（GCD）函数
int gcd(int a, int b)
{
    if (b == 0) // 如果 b 为 0，返回 a
        return a;
    else
        return gcd(b, a % b); // 递归计算最大公约数
}

// 约分函数：将分数化简为最简分数
void divide(int *up, int *down)
{
    if (*down < 0) // 如果分母为负数，调整分子和分母符号一致
    {
        *up = -(*up);
        *down = -(*down);
    }
    else if (*up == 0) // 如果分子为 0，分母置为 1
        *down = 1;
    else
    {
        int x = gcd(abs(*up), abs(*down)); // 计算分子和分母的最大公约数
        *up /= x;                          // 分子除以最大公约数
        *down /= x;                        // 分母除以最大公约数
    }
}

int main()
{
    int reup1, redown1, reup2, redown2;

    // 输入两个有理数
    scanf("%d/%d", &reup1, &redown1);
    scanf("%d/%d", &reup2, &redown2);

    // 计算两个有理数的和
    reup1 = reup1 * redown2 + reup2 * redown1; // 分子加和
    redown1 = redown1 * redown2;               // 分母乘积
    divide(&reup1, &redown1);                  // 约分

    // 输出结果
    if (redown1 == 1) // 如果分母为 1，则只输出分子
    {
        printf("%d", reup1);
    }
    else // 否则输出最简分数形式
    {
        printf("%d/%d", reup1, redown1);
    }

    return 0;
}

// 7.8
#include <stdio.h>
#include <stdlib.h>

// 计算最大公约数（Euclid算法）
int gcd(int a, int b)
{
    // 如果 b 为 0，最大公约数就是 a
    if (b == 0)
    {
        return a;
    }
    else
    // 递归调用，计算 a 和 b 的最大公约数
    {
        return gcd(b, a % b);
    }
}

// 规范化分数，将分子和分母的公因子除去
void divide(int *up, int *down)
{
    // 如果分母为负数，将分子和分母都转为负数，保证分母为正
    if (*down < 0)
    {
        *up = -(*up);
        *down = -(*down);
    }
    // 如果分子为 0，设置分母为 1，避免除以零
    else if (*up == 0)
    {
        *down = 1;
    }
    else
    {
        // 获取分子和分母的最大公约数
        int x = gcd(abs(*up), abs(*down));
        // 将分子和分母除以最大公约数
        *up /= x;
        *down /= x;
    }
}

int main()
{
    int n, reup, redown, up, down;

    // 输入整数 n（分数的个数）
    scanf("%d", &n);

    // 输入第一个分数
    scanf("%d/%d", &reup, &redown);

    // 逐个处理其余的分数
    for (int i = 1; i < n; i++)
    {
        // 输入一个新的分数
        scanf("%d/%d", &up, &down);

        // 合并当前分数和前一个分数，计算新的分数
        reup = reup * down + up * redown;
        redown = redown * down;

        // 规范化当前分数
        divide(&reup, &redown);
    }

    // 最终分母乘以 n
    redown *= n;

    // 规范化最终分数
    divide(&reup, &redown);

    // 输出最终结果
    if (redown == 1)
    {
        // 如果分母为 1，输出分子
        printf("%d", reup);
    }
    else
    {
        // 否则输出分数
        printf("%d/%d", reup, redown);
    }

    return 0;
}
// 7.9
#include <stdio.h>

// 定义一个结构体，用于存储学生的学号、测试分数和正式分数
struct student
{
    char number[20]; // 学号，最大长度为20
    int test;        // 测试分数
    int formal;      // 正式分数
};

int main()
{
    int n, m, formal;

    // 输入学生数量 n
    scanf("%d\n", &n);

    // 创建一个学生数组，用于存储每个学生的信息
    struct student arr[1001];

    // 输入每个学生的信息
    for (int i = 0; i < n; i++)
    {
        // 输入学生的学号、测试分数和正式分数
        scanf("%s %d %d\n", arr[i].number, &arr[i].test, &arr[i].formal);
    }

    // 输入要查询的测试分数数量 m
    scanf("%d", &m);

    // 对于每一个要查询的测试分数
    for (int i = 0; i < m; i++)
    {
        // 输入一个正式测试分数
        scanf("%d", &formal);

        // 查找所有测试分数等于 formal 的学生
        for (int j = 0; j < n; j++)
        {
            // 如果找到匹配的学生
            if (arr[j].test == formal)
            {
                // 输出该学生的学号和正式分数
                printf("%s %d\n", arr[j].number, arr[j].formal);
            }
        }
    }

    return 0;
}