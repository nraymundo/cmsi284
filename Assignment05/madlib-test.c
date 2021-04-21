#include <assert.h>
#include <string.h>

#include "madlib.h"

int main()
{
  assert(strcmp(madlib("The %s %s likes to %s in the moonlight", "brilliant", "git", "swim"), "The brilliant git likes to swim in the moonlight") == 0);
  assert(strcmp(madlib("My %s %s enjoys going to the %s whenever she's bored", "awesome", "mom", "movies"), "My awesome mom enjoys going to the movies whenever she's bored") == 0);
  return 0;
}
