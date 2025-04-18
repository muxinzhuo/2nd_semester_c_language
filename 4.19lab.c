// 6.1
int decode(char **s)
{
    int password = 0;
    for (int i = 0; i < 4; i++) // 遍历前四行
    {
        int count = 0;
        for (int j = 0; s[4][j] != '\0'; j++) // 遍历第五行的每一个元素
        {
            for (int k = 0; s[i][k] != '\0'; k++) // 遍历第五行的一个元素对应的整整一行元素
            {
                if (s[4][j] == s[i][k])
                {
                    count++;
                }
            }
        }
        password = password * 10 + count;
    }
    return password;
}

// 6.2
void fun(int *Num, int begin, int end, int digi, int *Count)
{
    int time = 0; // 记录符合规范的数的个数
    for (int i = begin; i <= end; i++)
    {
        int temp = i; // 防止循环变量被更改
        if (temp % digi == 0)
        {
            int count = 0;
            while (temp > 0)
            {
                if (temp % 10 == digi)
                {
                    count++;
                }
                temp /= 10;
            }
            if (count > 1)
            {
                Num[time] = i; // 储存符合规则的i
                time++;
            }
        }
    }
    *Count = time;
}
void printNum(int *Num, int Count)
{
    if (Count == 0)
    {
        printf("No number!");
    }
    else
    {
        for (int i = 0; i < Count; i++)
        {
            printf("%d", Num[i]);
            if (i != Count - 1) // 防止末位出现空格
            {
                printf(" ");
            }
        }
    }
}

// 6.3
void proceed(int *a, int *b, int size, void (*fp)(int x, int y))
{
    for (int i = 0; i < size; i++)//题目是要调两个参数然后传给函数，重复该操作直到结束
    {
        fp(a[i], b[i]);
    }
}

// 6.4
void MinArray(int a[], int n, int *p, int *q)
{
    int min = 1000000000;//只要小于该数就更新最小值
    int max = 0;//只要大于0就更新最大值
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)//比较并更新最大最小值
        {
            min = a[i];
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    *p = max;
    *q = min;
}