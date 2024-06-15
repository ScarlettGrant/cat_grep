#include <string.h>

#include "s21_sscanf.h"
#include "s21_sscanf.c"




int main() {
    //Test1
    const char *str1 = "123";
    int i1, i2;

    int count1 = s21_sscanf(str1, "%2d", &i1);
    printf("S21_sscanf: Count: %d, i: %d\n", count1, i1);

    int count2 = sscanf(str1, "%2d", &i2);
    printf("Original sscanf: Count: %d, i: %d\n", count2, i2);
    printf((count1 == count2 && i1 == i2) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test2
    const char *str2 = "123 Hello";
    int i3, i4;
    char s1[BUF_SIZE], s2[BUF_SIZE];

    int count3 = s21_sscanf(str2, "%d %s", &i3, s1);
    printf("S21_sscanf: Count: %d, i: %d, s: %s\n", count3, i3, s1);

    int count4 = sscanf(str2, "%d %s", &i4, s2);
    printf("Original sscanf: Count: %d, i: %d, s: %s\n", count4, i4, s2);
    printf((count3 == count4 && strcmp(s1, s2) == 0) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test3
    const char *str3 = "12345";
    int i5, i6;

    int count5 = s21_sscanf(str3, "%6d", &i5);
    printf("S21_sscanf: Count: %d, i: %d\n", count5, i5);

    int count6 = sscanf(str3, "%6d", &i6);
    printf("Original sscanf: Count: %d, i: %d\n", count6, i6);
    printf((count5 == count6 && i5 == i6) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test4
    const char *str4 = "Helloworld";
    char s3[BUF_SIZE], s4[BUF_SIZE];

    int count7 = s21_sscanf(str4, "%6s", s3);
    printf("S21_sscanf: Count: %d, s: %s\n", count7, s3);

    int count8 = sscanf(str4, "%6s", s4);
    printf("Original sscanf: Count: %d, s: %s\n", count8, s4);
    printf((count7 == count8 && strcmp(s3, s4) == 0) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test5
    const char *str5 = "Hello world";
    char s5[BUF_SIZE], s6[BUF_SIZE];

    int count9 = s21_sscanf(str5, "%15s", s5);
    printf("S21_sscanf: Count: %d, s: %s\n", count9, s5);

    int count10 = sscanf(str5, "%15s", s6);
    printf("Original sscanf: Count: %d, s: %s\n", count10, s6);
    printf((count9 == count10 && strcmp(s5, s6) == 0) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test6
    const char *str6 = "-123 45";
    int i7, i8;

    int count11 = s21_sscanf(str6, "%*d %d", &i7);
    printf("S21_sscanf: Count: %d, i: %d\n", count11, i7);

    int count12 = sscanf(str6, "%*d %d", &i8);
    printf("Original sscanf: Count: %d, i: %d\n", count12, i8);
    printf((count11 == count12 && i8 == i7) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test7
    const char *str7 = "Hello world";
    char s7[BUF_SIZE], s8[BUF_SIZE];

    int count13 = s21_sscanf(str7, "%*s %3s", s7);
    printf("S21_sscanf: Count: %d, s: %s\n", count13, s7);

    int count14 = sscanf(str7, "%*s %3s", s8);
    printf("Original sscanf: Count: %d, s: %s\n", count14, s8);
    printf((count13 == count14 && strcmp(s7, s8) == 0) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test8
    const char *str8 = "-123";
    int i9, i10;

    int count15 = s21_sscanf(str8, "%3d", &i9);
    printf("S21_sscanf: Count: %d, i: %d\n", count15, i9);

    int count16 = sscanf(str8, "%3d", &i10);
    printf("Original sscanf: Count: %d, i: %d\n", count16, i10);
    printf((count15 == count16 && i9 == i10) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test9
    const char *str9 = "w c";
    char c1, c2;

    int count17 = s21_sscanf(str9, "%*c %c" , &c1);
    printf("S21_sscanf: Count: %d, c: %c\n", count17, c1);

    int count18 = sscanf(str9, "%*c %c", &c2);
    printf("Original sscanf: Count: %d, c: %c\n", count18, c2);
    printf((count17 == count18 && c1 == c2) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test10
    const char *str10 = "wc";
    char c3, c4;

    int count19 = s21_sscanf(str10, "%c" , &c3);
    printf("S21_sscanf: Count: %d, c: %c\n", count19, c3);

    int count20 = sscanf(str10, "%c", &c4);
    printf("Original sscanf: Count: %d, c: %c\n", count20, c4);
    printf((count19 == count20 && c3 == c4) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test11
    const char *str11 = "01733 987 -987 0x3db";
    int i11, i12, i13, i14, i15, i16;

    int count21 = s21_sscanf(str11, "%i %*i %3i %i" , &i11, &i12, &i15);
    printf("S21_sscanf: Count: %d, i1: %d, i2: %d, i3: %d\n", count21, i11, i12, i15);

    int count22 = sscanf(str11, "%i %*i %3i %i" , &i13, &i14, &i16);
    printf("Original sscanf: Count: %d, i1: %d, i2: %d, i3: %d\n", count22, i13, i14, i16);
    printf((count21 == count22 && i11 == i13 && i12 == i14 && i15 == i16) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test12
    const char *str12 = "Hello world";
    char s9[BUF_SIZE], s10[BUF_SIZE], s11[BUF_SIZE];
    char s12[BUF_SIZE], s13[BUF_SIZE], s14[BUF_SIZE];

    int count23 = s21_sscanf(str12, "%3s %2s %5s", s9, s10, s11);
    printf("S21_sscanf: Count: %d, s1: %s, s2: %s, s3: %s\n", count23, s9, s10, s11);

    int count24 = sscanf(str12, "%3s %2s %5s", s12, s13, s14);
    printf("Original sscanf: Count: %d, s1: %s, s2: %s, s3: %s\n", count24, s12, s13, s14);
    printf((count23 == count24 && strcmp(s9, s12) == 0 && strcmp(s10, s13) == 0 && strcmp(s11, s14) == 0) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test13
    const char *str13 = "0x7c4 0X7C4 0x3db 03704 64555";
    unsigned int x1, x2, X1, X2, o1, o2, u1, u2;

    int count25 = s21_sscanf(str13, "%x %X %*x %o %u", &x1, &X1, &o1, &u1);
    printf("S21_sscanf: Count: %d, x1: %u, X1: %u, o1: %u, u1: %u\n", count25,  x1, X1, o1, u1);

    int count26 = sscanf(str13, "%x %X %*x %o %u", &x2, &X2, &o2, &u2);
    printf("Original sscanf: Count: %d, x2: %u, X2: %u, o2: %u, u2: %u\n", count26, x2, X2, o2, u2);
    printf((count25 == count26 && x1 == x2 && X1 == X2 && o1 == o2 && u1 == u2) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");

    //Test14
    const char *str14 = "64.555";
    float f1, f2;
    int count27 = s21_sscanf(str14, "%f", &f1);
    printf("s21_sscanf: count %d, f1: %f\n", count27, f1);

    int count28 = sscanf(str14, "%f", &f2);
    printf("Original sscanf: count %d, f2: %f\n", count28, f2);

    printf((count27 == count28 && f1 == f2) ? "\033[32mSUCCESS\033[0m\n" : "\033[31mFAIL\033[0m\n");
    return 0;
}