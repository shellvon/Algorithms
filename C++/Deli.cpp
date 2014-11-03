/**
 * See:http://acm.bnu.edu.cn/bnuoj/problem_show.php?pid=1010
 * 
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <cctype>
#include <limits>
#define N 1000
using namespace std;
int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}
int n,t;
char spa[21][21];
char spb[21][21];

void init(char *s)
{
    int flag=0;
    for(int i=0; i<n; i++)
    {
        if(!strcmp(s,spa[i]))
        {
            puts(spb[i]);
            flag=1;
            break;
        }
    }
    /*
    1：如果需要替换成复数形式的单词出现在特殊表中，则用表中的形式替换。
    2：如果是以辅音字母+“y”结尾的单词，将“y”变成“ies”。
    3：如果是以“o”，“s”，“ch”，“sh”或者“x”结尾的单词，在结尾添加“es”。
    4：对于其他的情况，在单词末添加“s”。*/
    if(!flag) //不在特殊表之内
    {
        int len = strlen(s)-1;
        char c=s[len-1];
        if((s[len]=='y')&&(c!='a'&&c!='i'&&c!='o'&&c!='u'&&c!='e'))
        {
            for(int i=0; i<len; i++)
                putchar(s[i]);
            puts("ies");
        }
        else if(s[len]=='o'||s[len]=='x'||s[len]=='s'||(s[len]=='h'&&(s[len-1]=='c'||s[len-1]=='s')))
        {
            printf("%s",s);
            puts("es");
        }
        else
        {
            printf("%s",s);
            puts("s");
        }
    }
}

int main()
{
    char table[40];
    scanf("%d%d",&n,&t);
    for(int i=0; i<n; i++)
        scanf("%s%s",spa[i],spb[i]);
    for(int i=0; i<t; i++)
    {
        scanf("%s",table);
        init(table);
    }
    return 0;
}