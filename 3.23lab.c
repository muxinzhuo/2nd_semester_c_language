//6.1
void F(int n)
{
    if (n == 0)
    {
        return;
    }
    int num;
    scanf("%d", &num);
    F(n - 1);//从最后一项开始执行输出
    printf("%d ", num);
}

//6.2
int test(int x)// 本题不允许调用原先的函数接口，所以给之前写的函数改个名字交了就行
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
    int flag = 1;
    for (int i = lower; i <= upper; i++) // 循环判断区间内的数
    {
        if (test(i))
        {
            printf("%d\n", i);
            flag = 0; // 找到了自守数，不输出none
        }
    }
    if (flag)
    {
        printf("None\n");
    }
}
//6.3
int IsTheNumber(const int N)
{
    if (N < 0) // 负数不是完全平方数
    {
        return 0;
    }
    int sqrtn = (int)sqrt(N); // 开根号以后强制取整数
    if (sqrtn * sqrtn != N)   // 如果整数相乘不等于n，则不是完全平方数
    {
        return 0;
    }
    int arr[10] = {0}; // 0~9共10个数字
    int temp = N;
    // 循环统计每个数字的出现次数
    while (temp > 0)
    {
        int num = temp % 10; // 每次除10的余数就是一位数字
        arr[num]++;          // 该数字出现次数加一
        temp /= 10;          // 去除刚刚的一位数字
    }
    // 检查有没有某一位出现了两次
    for (int i = 0; i < 10; i++)
    {
        if (arr[i]>=2)
        {
            return 1;
        }
        
    }
    return 0;
}

//6.4
int is( int number )
{
    int sum = 0;//创建加和变量
    int temp = number;//通过temp临时储存输入的数
    while (temp>0)
    {
        sum += temp % 10;//累加个位数
        temp /= 10;//去除刚刚累加的数
    }
    if (sum == 5)
    {
        return 1;
    }
    return 0;
}
void count_sum( int a, int b )
{
    int count = 0, sum = 0;
    if (a > b)//如果a>b就交换a和b的值
    {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = a; i <= b; i++)
    {
        if (is(i))
        {
            count++;//如果是，那么计数器增加
            sum += i;//累加区间内符合的数
        }
    }
    printf("count = %d, sum = %d", count, sum);
}

//6.5
int fun (void)
{
    int num;
    int count = 0;
    static int sum = 0;//用静态变量sum储存全局中所有数的加和
    while (1)
    {
    scanf("%d", &num);
    if (num<0)
    {
        break;//接收到负数时，跳出while循环，结束本组输入
    }
    count++;
    total += num;
    if (num>max)max = num;//进行最大最小值的判定
    if (num<min)min = num;
    }
    sum += count;
    return sum;
}

//6.6
int sign( int x )
{
    if(x>0)
    {
        return 1;
    }
    else if(0 == x)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

//6.7
void Fun(int x, int p)
{
    // 如果 x 大于等于 p，先处理x除以p后的部分
    if (x >= p)
    {
        Fun(x / p, p);
    }
    // x 代表当前数字，取余得到最低位
    int num = x % p;
    // 输出当前位：小于10输出数字，大于就输出大写字母
    if (num < 10) 
        putchar('0' + num);
    else 
        putchar('A' + (num - 10));
}
