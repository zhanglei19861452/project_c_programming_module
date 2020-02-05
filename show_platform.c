#include <stdio.h>

void show_bytes(unsigned char *start,unsigned int len)
{
    unsigned int i;
    for(i = 0;i < len;i ++)
    {
        printf("%.2x ",start[i]);
    }
    printf("\n");
}

void show_short(short x)
{
    show_bytes((unsigned char *)&x,sizeof(x));
}

void show_int(int x)
{
    show_bytes((unsigned char *)&x,sizeof(x));
}

void show_float(float x)
{
    show_bytes((unsigned char *)&x,sizeof(x));
}

void show_double(double x)
{
    show_bytes((unsigned char *)&x,sizeof(x));
}

void show_pointer(void *x)
{
    show_bytes((unsigned char *)&x,sizeof(x));
}


/*
 测试平台的各种数据类型，以及大小端
 
MAC_PRO 2.6 GHz Intel Core i7 测试结果：
78 56 
78 56 34 12 
b4 a2 91 4d 
00 00 00 78 56 34 b2 41 
8c d9 45 e5 fe 7f 00 00 


 short 2Bytes
 int 4Bytes
 float 4Bytes
 double 8Bytes
 pointer 8Bytes
 CPU 模式：小端
 */
void test_show_bytes(int x)
{
    short sval = x;
    int inval = x;
    float fval = x;
    double dval = x;
    int *pval = &x;
    
    show_short(sval);
    show_int(inval);
    show_float(fval);
    show_double(dval);
    show_pointer(pval);
}



int main(void)
{
    test_show_bytes(0x12345678);
    
}
