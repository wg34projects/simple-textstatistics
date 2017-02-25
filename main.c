#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LETTERS 150 //Festlegung maximale Zeichen pro Zeile
#define LINES 10    //Festlegung maximale Zeilen

int main()
{
    char text[LETTERS+1][LINES];
    char input[LETTERS+1];
    char *rv_input;
    int textlength[LINES];
    int Alpha = 0;
    int Punctuation = 0;
    int Spaces = 0;
    int Numeric = 0;
    int Words = 0;
    int LineCount = 0;

    printf("Text Statistics - alphanumeric, punctuation, space, numeric, words, lines\n");
    printf("max. %d letters per line, max. %d lines possible\n", LETTERS, LINES);
    printf("do not start a line with a space, start with a character\n");
    printf("do not make more than one space and no space between Punctuation\n");
    printf("press ENTER for next line, press ENTER twice to go to next level\n\n");

    for(int i = 0; i < LINES; i++)
    {
        rv_input = fgets(input,LETTERS+1,stdin);

        if (rv_input == NULL)   //eventuelle "kapitalere" Fehler abfangen
        {
            printf("ERROR - LEAVING PROGRAM");
            return -1;
        }

        if(i != 0 && input[0] == '\n')  //doppelt Enter Beendigung erst ab zweiten Schleichendurchlauf i=1 prüfen
        {
            break;
        }

        for(int j = 0; j < strlen(input); j++)
        {
            text[j][i] = input[j];
            textlength[i] = strlen(input) - 1;

            if(text[j][i] == '\n')
            {
                text[j][i] = '\0';
            }
        }

        LineCount = i + 1;

        for(int k = strlen(input); k < LETTERS; k++)    //auffüllen der restlichen Plätze im 2-dimensionalen Array mit Leerzeichen
        {
            text[k][i] = '\0';
        }
    }

//    for(int i = 0; i < LineCount; i++)
//    {
//        for(int j = 0; j < LETTERS; j++)
//        {
//            printf("%c", text[j][i]);
//
//        }
//        printf("\n");
//    }

        for (int i = 0; i < LineCount; i++)
        {
            for(int j = 0; j < textlength[i]; j++)
            {
                if(text[j][i] == 32)
                {
                    Spaces = Spaces + 1;
                }

                if((text[j][i] > 64) && (text[j][i] < 91))
                {
                    Alpha = Alpha + 1;
                }

                if((text[j][i] > 96) && (text[j][i] < 123))
                {
                    Alpha = Alpha + 1;
                }

                if((text[j][i] > 47) && (text[j][i] < 58))
                {
                    Numeric = Numeric + 1;
                }

                if((text[j][i] > 32) && (text[j][i] < 36))
                {
                    Punctuation = Punctuation + 1;
                }

                if((text[j][i] > 36) && (text[j][i] < 48))
                {
                    Punctuation = Punctuation + 1;
                }

                if((text[j][i] > 57) && (text[j][i] < 64))
                {
                    Punctuation = Punctuation + 1;
                }

                if((text[j][i] > 90) && (text[j][i] < 96))
                {
                    Punctuation = Punctuation + 1;
                }

                if((text[j][i] > 122) && (text[j][i] < 127))
                {
                    Punctuation = Punctuation + 1;
                }

            Words = Spaces + LineCount;
            }
        }


    printf("Here some statistics...\n\n");
    printf("alphanumeric characters: %d", Alpha);
    printf("\n");
    printf("punctuation characters (w.o. space): %d", Punctuation);
    printf("\n");
    printf("SPACES: %d", Spaces);
    printf("\n");
    printf("numeric characters: %d", Numeric);
    printf("\n");
    printf("words: %d", Words);
    printf("\n");
    printf("lines: %d", LineCount);

    return 0;
}

int TextCheck(char text[LETTERS+1][LINES])
{
    printf("check");
    return 0;
}
