#include<stdio.h>
//struct S1
//{
//    double d;
//    char c;
//    int i;
//};
//struct S2
//{
//    char c1;
//    struct S1 s;
//    double d;;
//};
//int main()
//{
//    struct S2 s;
//    printf("%d\n", sizeof(s));
//    return 0;
//}
//����Ĭ�϶����� 1
//#pragma pack(1)
//
//struct S1 
//{
//    char c1;
//    int i;
//    char c2;
//};
//
////�ָ�Ĭ�϶�����
//#pragma pack()
//
//int main()
//{
//    printf("%d\n", sizeof(struct S1));
//
//    return 0;
//}

#pragma pack(4)//�趨Ϊ4�ֽڶ��� 
struct S1
{
    char m1;
    double m4;
    int m3;
};
#pragma pack()//�ָ�����״̬ 
int main()
{
    printf("%d\n", sizeof(struct S1));

    return 0;
}