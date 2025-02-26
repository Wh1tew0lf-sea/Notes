#include<bits/stdc++.h>
void decryption(char* enc, char* key, int a3)
{
    char v3; // [rsp+2Bh] [rbp-15h]
    int n; // [rsp+2Ch] [rbp-14h]
    int m; // [rsp+30h] [rbp-10h]
    int k; // [rsp+34h] [rbp-Ch]
    int j; // [rsp+38h] [rbp-8h]
    int i; // [rsp+3Ch] [rbp-4h]
    for (n = 0; n < a3; ++n)
        enc[n] -= 10;
    for (m = 0; m <= a3 - 2; ++m)
        enc[m] += enc[m + 1];
    for (k = 0; k < a3 - 1; ++k)
        enc[k] ^= key[2];
    for (j = 0; j < a3; j += 2)
        enc[j] ^= key[j % 4];
    for (i = 0; i < a3; ++i)
        enc[i] += key[i % 4];
}
int main()
{
    char key2[] = "ISCC";
    char enc[] = { 0x36,0xE8,0x6F,0xA5,0xB2,0x9A,0x0D,0x36,
	0x7F,0x8D,0x18,0x32,0x4B,0xF5,0xD8,0x4A,
	0x38,0x09,0xC5,0x40,0x29,0xF1,0xC0,0x88,
	0xF0,0x34 };//0xC0,0x88,
    decryption(enc, key2, 26);
    puts(enc);
}
