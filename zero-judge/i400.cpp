#include <stdio.h>
#include <string.h>

char m, n;
char encrypts[101][101], cipher[101], buffer[101];

inline void append_str(char *str, char c)
{
    char len = strlen(str);
    str[len + 1] = '\0';
    str[len] = c;
}

inline void prepend_str(char *str, char c)
{
    memcpy(str + 1, str, strlen(str) * sizeof(char));
    str[0] = c;
}

int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
        scanf("%s", encrypts[i]);

    scanf("%s", cipher);

    for (int enc_index = m - 1; enc_index >= 0; enc_index--)
    {
        memset(buffer, '\0', sizeof buffer);
        char ones = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            char code = encrypts[enc_index][i];
            if (code == '1')
            {
                ones++;
                append_str(buffer, cipher[i]);
            }
            else
                prepend_str(buffer, cipher[i]);
        }
        if (ones % 2)
        {
            char sub = n % 2 ? n / 2 + 1 : n / 2;
            char left_tmp[53];
            memcpy(left_tmp, buffer, n / 2);
            memcpy(buffer, buffer + sub, n / 2);
            memcpy(buffer + sub, left_tmp, n / 2);
        }
        memcpy(cipher, buffer, n);
    }
    printf("%s\n", cipher);
    return 0;
}