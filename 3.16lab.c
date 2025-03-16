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
// 警告：本题超纲严重，建议直接跳过，如果你会数组，指针，或者stl，可以做
#include <stdio.h>
#include <stdlib.h>
// AI写的，学习一下吧
// 计算绝对值
int myAbs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int N, R;
    scanf("%d %d", &N, &R);
    int players[101]; // 总队员数（N最大100）
    int A[101], B[101];
    int a_cnt = 0, b_cnt = 0;
    
    // 读取所有队员实力，并分队存储
    for (int i = 0; i < N; i++) {
        scanf("%d", &players[i]);
        if (players[i] > 0) {
            A[a_cnt++] = players[i];
        } else {
            B[b_cnt++] = players[i];
        }
    }
    
    // 对A队按绝对值降序排序（实力越大越靠前）
    for (int i = 0; i < a_cnt - 1; i++) {
        for (int j = i + 1; j < a_cnt; j++) {
            if (myAbs(A[j]) > myAbs(A[i])) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    
    // 对B队按绝对值降序排序
    for (int i = 0; i < b_cnt - 1; i++) {
        for (int j = i + 1; j < b_cnt; j++) {
            if (myAbs(B[j]) > myAbs(B[i])) {
                int temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
    }
    
    // 输出排序结果：先A队，后B队，每个数字之间用空格分隔，最后一位后不输出空格
    for (int i = 0; i < a_cnt; i++) {
        printf("%d", A[i]);
        if (i < a_cnt - 1 || b_cnt > 0)
            printf(" ");
    }
    for (int i = 0; i < b_cnt; i++) {
        printf("%d", B[i]);
        if (i < b_cnt - 1)
            printf(" ");
    }
    printf("\n");
    
    // 模拟R轮比赛，使用两个下标分别表示A队和B队当前待出场的队员
    int i = 0, j = 0;
    for (int round = 0; round < R; round++) {
        if (i < a_cnt && j < b_cnt) { // 两队都有队员
            if (myAbs(A[i]) > myAbs(B[j]))
                printf("A Wins!\n");
            else if (myAbs(A[i]) < myAbs(B[j]))
                printf("B Wins!\n");
            else
                printf("Draw!\n");
            i++; j++;  // 同时出场
        } else if (i < a_cnt) { // 只有A队有队员
            printf("A Wins!\n");
            i++;
        } else if (j < b_cnt) { // 只有B队有队员
            printf("B Wins!\n");
            j++;
        } else { // 双方都没有队员时提前结束
            break;
        }
    }
    
    return 0;
}

//7.4
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
//7.5
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