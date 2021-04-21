#include <stdio.h>
#include <string.h>

char *allKeys[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
char *intervals[12] = {"minor second", "major second", "minor third", "major third", "perfect fourth", "tritone", "perfect fifth", "minor sixth", "major sixth", "minor seventh", "major seventh", "perfect octave"};
int numOfKeys = 12;

int getKeyLocation(char *key, char *allKeys[])
{
  int index = 0;
  int i;
  for (i = 0; i < 12; i++)
  {
    if (strcmp(allKeys[i], key) == 0)
    {
      index = i;
    }
  }
  return index;
}

void getKeyInterval(char *key1, char *key2, char *allKeys[], char *intervals[], int startingPosition)
{
  int key1Location = getKeyLocation(key1, allKeys);
  int key2Location = getKeyLocation(key2, allKeys);
  if (key1Location > key2Location)
  {
    printf("%s to %s is a %s\n", key1, key2, intervals[11 - (key1Location - key2Location)]);
  }
  else
  {
    printf("%s to %s is a %s\n", key1, key2, intervals[((key2Location - startingPosition) - 1) % 12]);
  }
}

int checkArgs(char *arg)
{
  int i;
  int index = -1;
  for (i = 0; i < 12; i++)
  {
    if (strcmp(allKeys[i], arg) == 0)
    {
      index = i;
    }
  }
  if (index == -1)
  {
    return 0;
  }
  return 1;
}

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    printf("This program requires exactly two command line arguments.\n");
  }
  else if (checkArgs(argv[1]) == 0)
  {
    printf("No such key: %s\n", argv[1]);
  }
  else if (checkArgs(argv[2]) == 0)
  {
    printf("No such key: %s\n", argv[2]);
  }
  else
  {
    if (strcmp(argv[1], argv[2]) == 0)
    {
      printf("%s to %s is a perfect octave\n", argv[1], argv[2]);
    }
    else
    {
      for (int i = 0; i < numOfKeys; i++)
      {
        if (strcmp(allKeys[i], argv[1]) == 0)
        {
          getKeyInterval(argv[1], argv[2], allKeys, intervals, i);
        }
      }
    }
  }
}
