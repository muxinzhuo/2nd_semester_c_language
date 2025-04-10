// 4.18？那顺祝作者19岁生日快乐！！！
// 本次使用了AI生成注释
// 7.1
#include <stdio.h> // 标准输入输出头文件，提供scanf和printf等函数

int main() // 主函数入口
{
    // 定义两个字符数组，用于存储输入的字符串
    char word1[20], word2[20]; // 每个字符串最大长度19+1('\0')

    // 读取两个字符串输入
    scanf("%s", &word1); // 读取第一个字符串
    scanf("%s", &word2); // 读取第二个字符串

    int i = 0; // 初始化索引变量

    // 逐个字符比较两个字符串
    while (word1[i] != '\0' && word2[i] != '\0') // 当两个字符串都未到结尾时
    {
        // 比较当前字符的ASCII值
        if (word1[i] > word2[i]) // 如果word1的字符较大
        {
            printf(">"); // 输出'>'
            return 0;    // 立即结束程序
        }
        else if (word1[i] < word2[i]) // 如果word1的字符较小
        {
            printf("<"); // 输出'<'
            return 0;    // 立即结束程序
        }
        i++; // 字符相同，比较下一个字符
    }

    // 处理字符串长度不同的情况
    if (word1[i] == '\0' && word2[i] == '\0') // 如果同时到达字符串结尾
    {
        printf("="); // 字符串完全相等
    }
    else if (word1[i] == '\0') // 如果word1先结束
    {
        printf("<"); // word1较小
    }
    else // 如果word2先结束
    {
        printf(">"); // word1较大
    }

    return 0; // 程序正常结束
}

// 7.2
#include <stdio.h>  // 标准输入输出头文件，提供printf、gets等函数
#include <string.h> // 字符串处理头文件，提供strlen函数

int main() // 主函数入口
{
    char str[85];     // 定义字符数组str，用于存储输入的字符串，最大长度84+1('\0')
    int a[128] = {0}; // 定义整型数组a，初始化全0，用于统计ASCII字符出现次数(0-127)

    gets(str); // 读取输入的字符串(注意：gets函数存在安全隐患，可能造成缓冲区溢出)

    int len = strlen(str); // 计算输入字符串的长度

    // 遍历字符串中的每个字符
    for (int i = 0; i < len; i++)
        a[str[i]]++; // 将字符的ASCII码作为索引，对应数组元素值加1(统计字符出现次数)

    // 遍历ASCII码表(0-127)
    for (int i = 0; i <= 127; i++)
    {
        // 如果当前ASCII码对应的字符出现过(计数值大于0)
        if (a[i] > 0)
        {
            printf("%c", i); // 输出该ASCII码对应的字符
            a[i] = 0;        // 将计数值重置为0(避免重复输出)
        }
    }

    return 0; // 程序正常结束
}

// 7.3
#include <stdio.h>  // 标准输入输出库
#include <string.h> // 字符串操作库

int main() // 主函数
{
    char str[1001]; // 定义字符数组存储输入字符串，最多1000字符+1结束符
    gets(str);      // 读取一行输入(注意：gets函数不安全，可能造成缓冲区溢出)

    int count = 0; // 计数器，记录连续'6'的数量

    // 遍历字符串中的每个字符
    for (int i = 0; i < strlen(str); i++) // 使用strlen获取字符串长度
    {
        if (str[i] == '6') // 当前字符是'6'
        {
            count++; // 增加连续'6'的计数
        }
        else // 当前字符不是'6'
        {
            // 处理之前累计的连续'6'
            if (count <= 3) // 连续3个或更少的'6'
            {
                for (int j = 0; j < count; j++) // 原样输出所有'6'
                {
                    printf("6");
                }
            }
            else if (count <= 9) // 连续4-9个'6'
            {
                printf("9"); // 替换为'9'
            }
            else // 连续10个及以上'6'
            {
                printf("27"); // 替换为'27'
            }

            count = 0;            // 重置计数器
            printf("%c", str[i]); // 输出当前非'6'字符
        }
    }

    // 处理字符串末尾可能剩余的连续'6'
    if (count > 0) // 如果还有未处理的'6'
    {
        if (count <= 3) // 连续3个或更少的'6'
        {
            for (int j = 0; j < count; j++) // 原样输出
            {
                printf("6");
            }
        }
        else if (count <= 9) // 连续4-9个'6'
        {
            printf("9"); // 替换为'9'
        }
        else // 连续10个及以上'6'
        {
            printf("27"); // 替换为'27'
        }
    }

    return 0; // 程序正常结束
}