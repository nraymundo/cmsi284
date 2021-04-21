#include <string.h>
#include <stdbool.h>

#include "reverse-range-in-place.h"

char *reverseString(char *string)
{
    int start_index = 0;
    int end_index = 0;
    bool inWord = false;
    int strLength = strlen(string);
    reverse_range_in_place(string, 0, strlen(string));
    for (int i = 0; i <= strLength; i++)
    {
        if (string[i] != ' ' && inWord == false)
        {
            inWord = true;
            start_index = i;
        }
        else if ((string[i] == ' ' && inWord == true) || (string[i] == '\0' && inWord == true))
        {
            inWord = false;
            end_index = i - 1;
            reverse_range_in_place(string, start_index, end_index);
        }
        if (end_index > start_index)
        {
            start_index = end_index;
        }
    }
    return string;
}

void reverse_words(char *string)
{
    reverseString(string);
}