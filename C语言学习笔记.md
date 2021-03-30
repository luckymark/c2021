# C 语言学习笔记

(1.0 / 6 + 1.0 / 12 + 1.0 / 7) int 类型要记得往后补

//limits.h
UCHAR_MAX SCAHAR_MIN....CHAR_BIT//

整形内部 纯二进制计数法
无符号整数内部 高位补 0
负数：
反转符号位
反转所有位（反码）+1 = （补码）
补码：正数少一个
反码：正负数都少一个
符号和绝对值：和反码一样
位移降低程序的可移植性，不要对负数进行位移

顺序查找 哨兵查找

（ctype.h）toupper tolower

利用指针修改地址

CONSOLE_SCREEN_BUFFER_INFO cw;
GetConsoleScreenBufferInfo(GetStdHandle(STD_INPUT_HANDLE), &cw);

用指针实现的字符串数组 char*p[]={"PAUL","X","MAC"}
可使用下标 p[][]进行访问
操作字符串 while(*p++)
while(*d++=*p++)
warning 不要改写字符串字面量

<string.h>:strlen strcpy strncpy strcat strncat strcmp srtrncmp
strchr(s1, ch);
返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
strstr(s1, s2);
返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。

<stdlib.h>atoi atol atof//获取字符串中的数字
rand 函数//RAND_MAX rand() 种子基准为 1
srand//修改 seed
使用运行程序的时间当作种子//srand(time(NULL))//time.h
<time.h>time_h ? = time(NULL)//日历时间（1970.1.1.0.0.0）
sleep()

数组的元素个数//size of(a)/size of(a[0])
struct tm\*timer = Localtime(&?).//tm 结构体//需要用时自行查询//localtime 函数分解时间
文件处理 fopen fclose fgetc

\b 用于退格 \b \b 消除最后 fflush 消除缓冲区
%\*s n""来输入空白字符串

素数求算优化方案
@只需要求到开方

<ctype.h>
iscntrl isprint isgraph(不包含空白) isdigit issupper islower isalpha
isalum ispunct isxdigit isspace

#宏的本质 自动的 ctrl+c 和 ctrl+v

# 记录你学习过程中的所见所思！酸甜苦辣！

# 看什么看！ 赶紧填坑啊！

maze 要用到的
