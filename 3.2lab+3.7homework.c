//拉格朗日问题
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    double c = (a + b) / 2.0;
    printf("%.1f\n", c);
    return 0;
}

//推算钟点
#include <stdio.h>
int main() {
    int h, m;
    long long add;
    scanf("%d:%d", &h, &m);
    scanf("%lld", &add);
    long long total = h * 60 + m + add;
    printf("%02d:%02d", (total / 60) % 24, total % 60);
    return 0;
}

//海伦公式
#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, p;
    scanf("a=%lf,b=%lf,c=%lf", &a, &b, &c);
    p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("S=%.4f", s);
    return 0;
}

//四则运算
#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
    return 0;
}

//大小写转换
#include <stdio.h>

int main() {
    char ch;
    scanf("%c", &ch);
    ch = ch + 32;
    printf("%c\n", ch);

    return 0;
}

//交换变量并输出
#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d",&a,&b);
    c = a,a = b,b = c;
    printf("a=%d,b=%d",a,b);
    return 0;
}

//分苹果
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d,%d",a / 4,a % 4);
    system("pause");
    return 0;
}
