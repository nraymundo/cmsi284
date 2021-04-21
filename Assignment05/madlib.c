#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *madlib(char *template, char *adjective, char *noun, char *verb)
{
    char *newTemplate = malloc(strlen(template) * strlen(template));
    sprintf(newTemplate, template, adjective, noun, verb);
    return newTemplate;
}