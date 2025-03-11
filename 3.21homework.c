//7.1
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    int sum = 0;
    int ret = 1;
    scanf("%d", &num);// 获取n
    for (int i = 1; i <= num; i++)
    {
        ret *= i;// 计算并储存阶乘的值，减少重复的计算，例如4！= 3！* 4
        sum += ret;// 直接进行求和
    }
    printf("%d", sum);
    system("pause");
    return 0;
}

//7.2
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[1000] = {0};// 创建一个数组储存所有的数，n<=1000，所以数组长度为1k
    int n;
    int odd = 0;
    int even = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);// 通过循环储存第二行所有的数字
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[j] % 2 == 0)
        {
            even++;// 偶数计数器
        }
        else
        {
            odd++;// 奇数计数器
        }
    }
    printf("%d %d", odd, even);

    system("pause");
    return 0;
}
//7.3
#include <stdio.h>
int main() {
    int m, n;
    int number = 0; // 素数的个数
    int sum = 0;  // 素数的和
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        int flag = 1;// 假设是素数，1真0假
        if (i < 2)
        {
            flag = 0; // 小于2不是素数
        }
        else
        {
            for (int j = 2; j * j <= i; j++)// 继续假设是素数，且只需要测试到√i
            {
                if (i % j == 0)
                {
                    flag = 0;// 如果能整除，就不是素数
                    break;// 退出循环
                }
            }
        }
        if (flag)// flag是1，为真，直接执行以下内容
        {
            number++;
            sum += i;
        }
        
        
    }
    printf("%d %d", number, sum);
    return 0;
}

//7.4
#include <stdio.h>

int main() {
    long h, n;// 输入在长整形范围内
    scanf("%ld %ld", &h, &n);
    
    if (n == 0)// 特殊情况进行考虑
    {
        printf("0.0 0.0");// n = 0时，空中没有经过距离，也没有反弹高度
    } else 
    {
        double total_distance = (double)h;// 强制类型转换，将long转化为double，保证输出为小数
        double rebound_height = h / 2.0;// 回弹高度是启始高度的一半
        
        for (int i = 1; i < n; i++) {
            total_distance += 2 * rebound_height;// 反弹加上下落的路程
            rebound_height /= 2.0;// 反弹一次高度减半
        }
        
        printf("%.1lf %.1lf", total_distance, rebound_height);
    }
    
    return 0;
}
//7.5
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int num1, num2, temp;
    scanf("%d %d", &num1, &num2);
    int plus = num1 * num2;
    // 欧几里得算法求最大公约数
    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    // 两个数的乘积等于它们的最大公约数和最小公倍数的乘积
    num2 = plus / num1;
    printf("%d %d", num1, num2);
    return 0;
}
//7.6 斐波那契数列问题
#include <stdio.h>
int main()
{
    int n, month = 2;
    scanf("%d", &n);
    if (n == 1) // 一开始就有一对，特殊情况特殊处理
    {
        printf("1");
        return 0;
    }
    long long f1 = 1, f2 = 1, f;// f1上月兔子数，f2当前月，f为总和
    while (f2 < n) //当前月小于n时，持续循环增加
    {
        f = f1 + f2;// 当前月份兔子总数
        f1 = f2;// 前一个月的兔子数
        f2 = f;// 当前月的兔子数
        month++;// 月份增加
    }
    printf("%d\n", month);
    return 0;
}

//7.7
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int count = 0, sum = 0;
    int temp = n;
    while (temp > 0) {
        count++;            // 位数加1
        sum += temp % 10;   // 取当前最低位数字并累加到sum
        temp /= 10;         // 去掉最低位，准备下一次循环
    }
    
    // 输出位数和各位数字之和，中间用一个空格隔开
    printf("%d %d", count, sum);
    
    return 0;
}

//7.8
#include <stdio.h>

int main() {
    double x, term = 1.0, sum = 1.0;// term：当前项的值；sum：累加的结果
    int k = 1; // 当前阶的项数
    
    scanf("%lf", &x);
    
    while (term >= 0.00001) // 当前项的值大于0.00001时持续循环
    {
        term *= x / k; // 前一项乘x/k是当前项
        sum += term; // 累加总和
        k++; // 阶更新
    }
    
    printf("%.4f\n", sum);
    return 0;
}

//7.9
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d*%d=%-4d", j, i, j * i);// 输出一个整数。整数至少占用 4 个字符的宽度。如果整数的位数不足 4 位，右侧用空格填充（左对齐）。
        }
        printf("\n");
    }
    return 0;
}
//7.10
#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);

    int count = 0;
    // 5 分硬币的最大数量为：(x - 3) / 5
    int max_5 = (x - 3) / 5;
    for (int a = max_5; a >= 1; a--) 
    {
        int max_2 = (x - 5 * a - 1) / 2;// 计算 2 分硬币的最大数量
        for (int b = max_2; b >= 1; b--) 
        {
            int c = x - 5 * a - 2 * b;
            if (c >= 1) // 1 分硬币要至少有一枚
            {
                int total = a + b + c;
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", a, b, c, total);
                count++;
            }
        }
    }
    printf("count = %d", count);
    return 0;
}