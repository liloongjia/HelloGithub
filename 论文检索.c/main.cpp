#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 51
typedef struct
{
    int num;//编号
    char name[20];//题名
    char writer[20];//作者
    char time[20];//时间
    char key[20];//关键词
    char writing[100];//正文
}elemtype;//论文结构
typedef struct
{
    elemtype *elem;//储存基址
    int length;
}stable;//查找表
void creat(stable &S)//输入数据
{
    S.elem=(elemtype *)malloc(51*sizeof(elemtype));
    if(!S.elem)
        exit(-2);
    S.length=0;
    int i=0;
    printf("请输入数据\n");
    for(i=1;i<=50;i++)
    {
        scanf("%d %s %s %s %s %s",&S.elem[i].num,S.elem[i].name,S.elem[i].writer,S.elem[i].time,S.elem[i].key,S.elem[i].writing);
        S.length++;
    }
    printf("请选择菜单功能\n");
}
void soft(stable &S)//按编号从小到大排序
{
    elemtype temp;
    int i=0,j=0;
    for(i=1;i<50;i++)
    {
        for(j=i+1;j<=50;j++)
        {
            if(S.elem[j].num<S.elem[i].num)
            {
                temp=S.elem[i];
                S.elem[i]=S.elem[j];
                S.elem[j]=temp;
            }
        }
    }
}
void found(stable S)//检索,可以设置监视哨大于1000时平均减少一半时间
{
    printf("按以下方式查询:\n1.编号\n2.题名\n3.作者\n4.时间\n5.关键字\n");
    int m,f=1,i,x;
    char c[100];
    printf("输入查询方式\n");
    scanf("%d",&m);//查询方式
    if(m==1)//回车执行2
    {printf("输入编号\n");
    scanf("%d",&x);
    for(i=1;i<=50;i++)
    {
        if(x==S.elem[i].num)
        {
            f=0;
            printf("%d %s %s %s %s %s\n",S.elem[i].num,S.elem[i].name,S.elem[i].writer,S.elem[i].time,S.elem[i].key,S.elem[i].writing);
        }
    }
    if(f==1)
        printf("NO FOUND\n");
    }
    f=1;
    if(m==2)
    {printf("输入题名\n");
    scanf("%s",c);
    for(i=1;i<=50;i++)
    {
        if(strcmp(c,S.elem[i].name)==0)
        {
            f=0;
            printf("%d %s %s %s %s %s\n",S.elem[i].num,S.elem[i].name,S.elem[i].writer,S.elem[i].time,S.elem[i].key,S.elem[i].writing);
        }
    }
    if(f==1)
        printf("NO FOUND\n");
    }
    f=1;
    if(m==3)
    {
        printf("输入作者名\n");
        scanf("%s",c);
    for(i=1;i<=50;i++)
    {
        if(strcmp(c,S.elem[i].writer)==0)
        {
            f=0;
            printf("%d %s %s %s %s %s\n",S.elem[i].num,S.elem[i].name,S.elem[i].writer,S.elem[i].time,S.elem[i].key,S.elem[i].writing);
        }
    }
    if(f==1)
        printf("NO FOUND\n");
    }
    f=1;
    if(m==4)
    {
        printf("输入时间\n");
        scanf("%s",c);
    for(i=1;i<=50;i++)
    {
        if(strcmp(c,S.elem[i].time)==0)
        {
            f=0;
            printf("%d %s %s %s %s %s\n",S.elem[i].num,S.elem[i].name,S.elem[i].writer,S.elem[i].time,S.elem[i].key,S.elem[i].writing);
        }
    }
    if(f==1)
        printf("NO FOUND\n");
    }
    f=1;
    if(m==5)
    {
        printf("输入关键字\n");
        scanf("%s",c);
    for(i=1;i<=50;i++)
    {
        if(strcmp(c,S.elem[i].key)==0)
        {
            f=0;
            printf("%d %s %s %s %s %s\n",S.elem[i].num,S.elem[i].name,S.elem[i].writer,S.elem[i].time,S.elem[i].key,S.elem[i].writing);
        }
    }
    if(f==1)
        printf("NO FOUND\n");
    }
    printf("请选择菜单功能\n");
}
int main()
{
    printf("菜单：\n1.输入数据\n2.检索及输出\n3.退出系统\n");
    int n;
    stable S;
    for(;;)
    {
        scanf("%d",&n);//之后回车执行
        if(n==1)
        {
            creat(S);
            soft(S);
        }
        if(n==2)found(S);
        if(n==3)
        {
            printf("谢谢使用\n");
            return 0;
        }
    }
}
/*
3 1 2 3 4 5
2 1 3 4 5 6
1 1 4 5 6 7
4 4 5 6 7 8
5 5 6 7 8 9
6 6 7 8 9 10
7 7 8 9 10 11
8 8 9 10 11 12
9 9 10 11 12 13
10 10 11 12 13 14
11 11 12 13 14 15
12 12 13 14 15 16
13 13 14 15 16 17
14 14 15 16 17 18
15 15 16 17 18 19
16 16 17 18 19 20
17 17 18 19 20 21
18 18 19 20 21 22
19 19 20 21 22 23
20 20 21 22 23 24
21 21 22 23 24 25
22 22 23 24 25 26
23 23 24 25 26 27
24 24 25 26 27 28
25 25 26 27 28 29
26 26 27 28 29 30
27 27 28 29 30 31
28 28 29 30 31 32
29 29 30 31 32 33
30 30 31 32 33 34
31 31 32 33 34 35
32 32 33 34 35 36
33 33 34 35 36 37
34 34 35 36 37 38
35 35 36 37 38 39
36 36 37 38 39 40
37 37 38 39 40 41
38 38 39 40 41 42
39 39 40 41 42 43
40 40 41 42 43 44
41 41 42 43 44 45
42 42 43 44 45 46
43 43 44 45 46 47
44 44 45 46 47 48
45 45 46 47 48 49
46 46 47 48 49 50
47 47 48 49 50 51
48 48 49 50 51 52
49 49 50 51 52 53
50 50 51 52 53 54
*/
