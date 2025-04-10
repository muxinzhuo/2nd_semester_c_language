// AACDA BDDBB
// 7.1
#include <stdio.h>
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    M = M % N; // 防止 M 超过 N
    // 先输出最后 M 个元素
    for (int i = N - M; i < N; i++)
    {
        printf("%d", arr[i]);
        if (i < N - 1)
            printf(" "); // 控制格式，防止多余空格
    }
    // 再输出前 N-M 个元素
    for (int i = 0; i < N - M; i++)
    {
        if (i == 0 && M > 0)
            printf(" "); // 在 M > 0 时补充空格
        printf("%d", arr[i]);
        if (i < N - M - 1)
            printf(" ");
    }
    return 0;
}

// 7.2
#include <stdio.h>
int main()
{
    int arr1[20] = {0}, arr2[20] = {0}, m, n;
    int count = 0, arr3[40] = {0}, outputtime = 1;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &arr2[j]);
    }
    for (int i = 0; i < m; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr1[i] == arr2[j])
            {
                flag = 1;
                break;
            }
        }
        int printed = 0;
        for (int k = 0; k < count; k++)
        {
            if (arr3[k] == arr1[i])
            {
                printed = 1;
                break;
            }
        }

        if (flag == 0 && printed == 0)
        {
            if (!outputtime)
            {
                printf(" ");
            }
            printf("%d", arr1[i]);
            arr3[count++] = arr1[i];
            outputtime = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr2[i] == arr1[j])
            {
                flag = 1;
                break;
            }
        }
        int printed = 0;
        for (int k = 0; k < count; k++)
        {
            if (arr3[k] == arr2[i])
            {
                printed = 1;
                break;
            }
        }
        if (flag == 0 && printed == 0)
        {
            if (!outputtime)
            {
                printf(" ");
            }
            printf("%d", arr2[i]);
            arr3[count++] = arr2[i];
            outputtime = 0;
        }
    }
    return 0;
}

// 7.3
#include <stdio.h>

int main()
{
    int arr[10] = {0}; // 存储数字0-9的出现次数

    // 读取输入的10个数字
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    int first_digit; // 记录最小的非零数字

    // 找到最小的非零数字作为首位
    for (int i = 1; i < 10; i++)
    {
        if (arr[i] > 0)
        {
            first_digit = i;
            arr[i]--; // 该数字使用一次
            break;
        }
    }

    printf("%d", first_digit); // 先输出首位数字

    // 按从小到大的顺序输出剩余数字
    for (int i = 0; i < 10; i++)
    {
        while (arr[i] > 0)
        {
            printf("%d", i);
            arr[i]--;
        }
    }

    return 0;
}

// 7.5
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);  // 读取矩阵的大小
    int matrix[n][n]; // 定义 n × n 的矩阵

    // 读取矩阵元素
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0; // 记录累加和

    // 遍历矩阵，计算需要的元素之和
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 判断是否是主对角线、最后一列或最后一行
            if ((i + j == n - 1 || j == n - 1 || i == n - 1) == 0)
            {
                sum += matrix[i][j]; // 累加非边界元素
            }
        }
    }

    printf("%d", sum); // 输出结果
    return 0;
}

// 7.6
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);  // 读取矩阵的大小
    int matrix[n][n]; // 定义 n × n 矩阵

    // 读取矩阵元素
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int found = 0; // 标记是否找到“马鞍点”

    // 遍历每一行，寻找行内最大值
    for (int i = 0; i < n; i++)
    {
        int line_max = matrix[i][0]; // 设定当前行的最大值
        for (int j = 0; j < n; j++)
        {
            if (line_max < matrix[i][j])
            {
                line_max = matrix[i][j]; // 更新行最大值
            }
        }

        // 在该行查找所有等于 line_max 的元素
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == line_max)
            {
                int flag = 1; // 标志是否是马鞍点

                // 判断该元素是否是所在列的最小值
                for (int k = 0; k < n; k++)
                {
                    if (matrix[k][j] < line_max)
                    {
                        flag = 0; // 不是马鞍点，跳出循环
                        break;
                    }
                }

                if (flag) // 如果满足条件
                {
                    printf("%d %d\n", i, j); // 输出行号和列号
                    found = 1;
                    return 0; // 找到后立即结束程序
                }
            }
        }
    }

    // 如果没有找到马鞍点，输出 NONE
    if (!found)
    {
        printf("NONE\n");
    }

    return 0;
}

// 7.7
#include <stdio.h>

int arr[15][15]; // 定义最大支持 15×15 的矩阵

int main()
{
    int x, y, n, total;
    scanf("%d", &n); // 读取矩阵大小

    x = 1, y = 1;             // 起始位置
    arr[x][y] = 1, total = 1; // 初始化起点值为 1

    // 生成螺旋矩阵
    while (total < n * n)
    {
        // 向右移动
        while (y + 1 <= n && arr[x][y + 1] == 0)
        {
            arr[x][++y] = ++total;
        }
        // 向下移动
        while (x + 1 <= n && arr[x + 1][y] == 0)
        {
            arr[++x][y] = ++total;
        }
        // 向左移动
        while (y - 1 >= 1 && arr[x][y - 1] == 0)
        {
            arr[x][--y] = ++total;
        }
        // 向上移动
        while (x - 1 >= 1 && arr[x - 1][y] == 0)
        {
            arr[--x][y] = ++total;
        }
    }

    // 输出螺旋矩阵
    for (x = 1; x <= n; x++)
    {
        for (y = 1; y <= n; y++)
        {
            printf("%3d", arr[x][y]); // 格式化输出，每个数字占 3 格
        }
        printf("\n");
    }

    return 0;
}
