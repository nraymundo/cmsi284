#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *getChar(char *template, int i)
{
    char *string = malloc(2 * sizeof(char));
    string[1] = '\0';
    string[0] = template[i];
    return string;
}

int countLengthOfMadlib(char *template, int word_count, char *words[])
{
    int counter = 0;
    for (int i = 0; template[i] != '\0'; i++)
    {
        if (isdigit(template[i]) != 0 && atoi(getChar(template, i)) < word_count)
        {
            counter = counter + strlen(words[atoi(getChar(template, i))]);
        }
        else
        {
            counter++;
        }
    }
    return counter;
}

char *createNewMadlib(char *template, char *madlib, int word_count, char *words[])
{
    for (int i = 0; template[i] != '\0'; i++)
    {
        if (isdigit(template[i]) != 0 && atoi(getChar(template, i)) < word_count)
        {
            char *index = getChar(template, i);
            strcat(madlib, words[atoi(index)]);
        }
        else
        {
            strcat(madlib, getChar(template, i));
        }
    }
    return madlib;
}

char *madlib_by_numbers(char *template, int word_count, char *words[])
{
    char *madlib = malloc(countLengthOfMadlib(template, word_count, words) * sizeof(char));
    if (word_count > 10 || word_count < 0)
    {
        return madlib;
    }
    else
    {
        return createNewMadlib(template, madlib, word_count, words);
    }
}