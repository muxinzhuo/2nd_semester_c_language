//7.1
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int height;
    scanf("%d", &height);
    if (height % 2 == 0)
    {
        printf("Error");
    }
    else
    {
    // 上半部分菱形
    for (int i = 1; i <= height / 2 + 1; i++) 
    {
        // 打印空格
        for (int space = 1; space <= (height / 2 + 1) - i; space++) {
            printf(" ");
        }
        // 打印星号
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    // 下半部分菱形
    for (int i = height / 2; i >= 1; i--) 
    {
        // 打印空格
        for (int space = 1; space <= (height / 2 + 1) - i; space++) {
            printf(" ");
        }
        // 打印星号
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    }

    system("pause");
    return 0;
}
//7.2
#include <stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)// 循环获取每一组并输出，0为假时结束
    {
        int m, n;
        scanf("%d %d", &m, &n);
        for (int i = 0; i < n -m + 1; i++)// 控制行数
        {
            int temp = m + i;// 确保每行内容增加
            for (int j = 0; j < temp; j++)// 控制每行内容
            {
                printf("%d", temp);
            }
            printf("\n");
        }
    }
    getchar(); getchar();
    return 0;
}
//7.3

#include <stdio.h>
int main()
{
    long k, total = 0, now = 1;//用int第八例测试不通过
    scanf("%ld", &k);// 输入总天数k
    while (k >= now)
    {
        total += now * now;
        k -= now;
        now++;
    }
    printf("%ld", total + k * now);
    getchar();getchar();
    return 0;
}
//7.4
#include <stdio.h>
int main() 
{
    long m, n, temp = 0;
    scanf("%ld %ld", &m, &n);
    // 欧几里得算法求最大公约数,3.21作业中也有这个题
    while (n != 0) 
    {
    temp = m % n;
    m = n;
    n = temp;
    }
    printf("%ld", m);
    getchar();getchar();
    return 0;
}
