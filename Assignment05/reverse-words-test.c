#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "reverse-words.h"

int main()
{
  char test[] = "hi bye";
  reverse_words(test);
  assert(strcmp(test, "bye hi") == 0);

  char test2[] = "      my name is john";
  reverse_words(test2);
  assert(strcmp(test2, "john is name my      ") == 0);

  char test3[] = "    I      like    to   sing ";
  reverse_words(test3);
  assert(strcmp(test3, " sing   to    like      I    ") == 0);

  char test4[] = "123456 789 10";
  reverse_words(test4);
  assert(strcmp(test4, "10 789 123456") == 0);

  char test5[] = "Mom, please stop calling me john.";
  reverse_words(test5);
  assert(strcmp(test5, "john. me calling stop please Mom,") == 0);
  return 0;
}
