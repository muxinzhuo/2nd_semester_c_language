// TFFTT
// CBDDC D
// n-1
//6.1
void Pack(FILE *src, FILE *dst)
{
    int c, next;
    int in_comment = 0;
    int in_string = 0;    // 1 表示双引号字符串，2 表示单引号字符常量
    int escape = 0;

    while ((c = fgetc(src)) != EOF)
    {
        if (in_comment) {
            // 在注释中，查找结束标志 */
            if (c == '*') {
                next = fgetc(src);
                if (next == '/') {
                    in_comment = 0;
                    fputc(' ', dst);  // 注释结束后补一个空格
                } else if (next != EOF) {
                    ungetc(next, src); // 不是 / 就退回去继续处理
                }
            }
            // 忽略注释内其他字符
            continue;
        }

        if (in_string) {
            fputc(c, dst);
            if (escape) {
                escape = 0;
            } else if (c == '\\') {
                escape = 1;
            } else if ((in_string == 1 && c == '"') || (in_string == 2 && c == '\'')) {
                in_string = 0;
            }
            continue;
        }

        if (c == '"') {
            in_string = 1;
            fputc(c, dst);
            continue;
        } else if (c == '\'') {
            in_string = 2;
            fputc(c, dst);
            continue;
        }

        if (c == '/') {
            next = fgetc(src);
            if (next == '*') {
                in_comment = 1; // 进入注释状态
                continue;
            } else {
                fputc(c, dst);
                if (next != EOF) {
                    fputc(next, dst);
                }
                continue;
            }
        }

        fputc(c, dst); // 正常字符，直接写入目标文件
    }
}

//6.2
void ReadArticle(FILE *f)
{
    int ch;
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
    }
}