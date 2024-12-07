#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 256
#define PRIME 101

void rabinKarp(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);


    int patternHash = 0;
    int textHash = 0;
    int h = 1;


    for (int i = 0; i < m - 1; i++)
    {
        h = (h * BASE) % PRIME;
    }


    /**hash=(BASE×previous_hash+current_character)%PRIME**/


    for (int i = 0; i < m; i++)
    {
        patternHash = (BASE * patternHash + pattern[i]) % PRIME;
        textHash = (BASE * textHash + text[i]) % PRIME;
    }


    for (int i = 0; i <= n - m; i++)
    {

        if (patternHash == textHash)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }


            if (j == m)
            {
                printf("Pattern found at index %d\n", i);
                return;
            }
        }

        /**newHash=(BASE×(currentHash−oldCharValue×h)+newCharValue)%PRIME**/


        if (i < n - m)
        {
            textHash = (BASE * (textHash - text[i] * h) + text[i + m]) % PRIME;


            if (textHash < 0)
            {
                textHash += PRIME;
            }
        }
    }


    printf("Pattern not found\n");
}

int main()
{
    char text[] = "The quick brown fox jumps over the lazy dog";
    char pattern[] = "fox";

    rabinKarp(text, pattern);

    return 0;
}
