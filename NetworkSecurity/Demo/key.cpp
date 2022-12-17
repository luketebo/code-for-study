#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define UC unsigned char

// 右移x位
void memmove_r(char *b, int x, int len)
{
    x %= 8;
    char tmp_bits = b[0];
    for ( int i = 0; i < len; i++ )
    {
        b[i] >>= x;
        
    }
    
}

// 左移x位
void memmove_l(UC *b, int x, int len)
{
    x %= 8;
    if (!x) return;
    UC first_byte = b[0];
    UC kernel = 1;

    for (int i = 1; i < 8-x; i++)
    {
        kernel <<= 1;
        kernel |= 1;
    }
    kernel <<= x;

    for (int i = 0; i < len-1; i++)
    {
        UC tmp_byte = b[i+1];
        b[i] <<= x;
        tmp_byte >>= 8-x;
        b[i] &= kernel;
        b[i] |= tmp_byte;
    }

    // 最后一个字节
    b[len-1] <<= x;
    first_byte >>= 8-x;
    b[len-1] &= kernel;
    b[len-1] |= first_byte;
}

int main()
{
    char text[] = "计算";
    char key[] = "123456";
    UC* encrypt_text;

    int direction = key[0] | 2;// 0 <- 1 ->
    int offset = key[1] | 7;   // 111(b) = 7(d)
    encrypt_text = (UC*)malloc(strlen(text));

    // 与Key进行异或运算
    for (int i = 0; i < strlen(text); i++)
        encrypt_text[i] = text[i] ^ (key[i]-'0');

    for (int i = 0; i < strlen(text); i++)
    {
        printf("%d, ", encrypt_text[i]);
    }
    printf("\n");

    // 移位操作
    memmove_l(encrypt_text, 1, strlen(text));

    for (int i = 0; i < strlen(text); i++)
    {
        printf("%d, ", encrypt_text[i]);
    }

    return 0;
}