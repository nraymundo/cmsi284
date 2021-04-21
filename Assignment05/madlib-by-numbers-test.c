#include <assert.h>
#include <string.h>

#include "madlib-by-numbers.h"

int main()
{
  char *words_to_use[] = {"swim", "brilliant", "git"};
  assert(strcmp(madlib_by_numbers("The 1 2 likes to 0 in the 1 moonlight", 3, words_to_use), "The brilliant git likes to swim in the brilliant moonlight") == 0);
  assert(strcmp(madlib_by_numbers("The 12 44 likes to 0 in the 1 moonlight", 3, words_to_use), "The brilliantgit 44 likes to swim in the brilliant moonlight") == 0);
  assert(strcmp(madlib_by_numbers("The 01 44 likes to 0 in the 1 moonlight", 3, words_to_use), "The swimbrilliant 44 likes to swim in the brilliant moonlight") == 0);

  char *words_to_use2[] = {"dance", "sing", "laugh"};
  assert(strcmp(madlib_by_numbers("I like to 2 whenever I 1 because it makes me think about how I hate to 0", 3, words_to_use2), "I like to laugh whenever I sing because it makes me think about how I hate to dance") == 0);
  assert(strcmp(madlib_by_numbers("222211110000", 3, words_to_use2), "laughlaughlaughlaughsingsingsingsingdancedancedancedance") == 0);
  assert(strcmp(madlib_by_numbers("2 1 0 3", 3, words_to_use2), "laugh sing dance 3") == 0);
  assert(strcmp(madlib_by_numbers("1 2 4 5 0 0 0", 3, words_to_use2), "sing laugh 4 5 dance dance dance") == 0);

  char *words_to_use3[] = {"swim"};
  assert(strcmp(madlib_by_numbers("The 2 likes to 2 in the 2 moonlight", 1, words_to_use3), "The 2 likes to 2 in the 2 moonlight") == 0);

  char *words_to_use4[] = {"barf"};
  assert(strcmp(madlib_by_numbers("      The 2 likes to 2 in the 2 moonlight      ", 1, words_to_use4), "      The 2 likes to 2 in the 2 moonlight      ") == 0);

  char *words_to_use5[] = {"bro", "hahaha", "lol", "moonlight"};
  assert(strcmp(madlib_by_numbers("      My freaking 0 likes to 2 whenever he goes like 1 in the 3      ", 4, words_to_use5), "      My freaking bro likes to lol whenever he goes like hahaha in the moonlight      ") == 0);
  assert(strcmp(madlib_by_numbers("      My freaking 0 likes to 2        whenever he goes like 1 in the 4      ", 4, words_to_use5), "      My freaking bro likes to lol        whenever he goes like hahaha in the 4      ") == 0);

  char *words_to_use6[] = {"dance", "sing", "sack", "laugh", "swim", "brilliant", "git", "hello", "yay", "coffee", "lmao"};
  assert(strcmp(madlib_by_numbers("my 1 likes to 2 because 3", 11, words_to_use6), "") == 0);

  char *words_to_use7[] = {"dance", "sing", "sack", "laugh", "swim", "brilliant", "git", "hello", "yay", "coffee"};
  assert(strcmp(madlib_by_numbers("my 1 likes to 2 because 9", 10, words_to_use7), "my sing likes to sack because coffee") == 0);
  assert(strcmp(madlib_by_numbers("my 1 likes to -2 because 9", 10, words_to_use7), "my sing likes to -sack because coffee") == 0);
  assert(strcmp(madlib_by_numbers("my !!!!! because 9", 10, words_to_use7), "my !!!!! because coffee") == 0);
  assert(strcmp(madlib_by_numbers("my _ ! $$$ because 9", 10, words_to_use7), "my _ ! $$$ because coffee") == 0);
  return 0;
}