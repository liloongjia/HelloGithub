#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 51
typedef struct
{
    int num;//���
    char name[20];//����
    char writer[20];//����
    char time[20];//ʱ��
    char key[20];//�ؼ���
    char writing[100];//����
}elemtype;//���Ľṹ
typedef struct
{
    elemtype *elem;//�����ַ
    int length;
}stable;//���ұ�
void creat(stable &S)//��������
{
    S.elem=(elemtype *)malloc(51*sizeof(elemtype));
    if(!S.elem)
        exit(-2);
    S.length=0;
    int i=0;
    printf("����������\n");
    for(i=1;i<=50;i++)
    {
        scanf("%d %s %s %s %s %s",&S.elem[i].num,S.elem[i].name,S.elem[i].writer,S.elem[i].time,S.elem[i].key,S.elem[i].writing);
        S.length++;
    }
    printf("��ѡ��˵�����\n");
}
void soft(stable &S)//����Ŵ�С��������
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
void found(stable S)//����,�������ü����ڴ���1000ʱƽ������һ��ʱ��
{
    printf("�����·�ʽ��ѯ:\n1.���\n2.����\n3.����\n4.ʱ��\n5.�ؼ���\n");
    int m,f=1,i,x;
    char c[100];
    printf("�����ѯ��ʽ\n");
    scanf("%d",&m);//��ѯ��ʽ
    if(m==1)//�س�ִ��2
    {printf("������\n");
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
    {printf("��������\n");
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
        printf("����������\n");
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
        printf("����ʱ��\n");
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
        printf("����ؼ���\n");
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
    printf("��ѡ��˵�����\n");
}
int main()
{
    printf("�˵���\n1.��������\n2.���������\n3.�˳�ϵͳ\n");
    int n;
    stable S;
    for(;;)
    {
        scanf("%d",&n);//֮��س�ִ��
        if(n==1)
        {
            creat(S);
            soft(S);
        }
        if(n==2)found(S);
        if(n==3)
        {
            printf("ллʹ��\n");
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
