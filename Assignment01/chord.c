#include <stdio.h>
#include <string.h>

char *allKeys[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
int numOfKeys = 12;

void getMajorKeys(char *key, char *allKeys[], int start)
{
  printf("%s: %s %s %s\n", key, key, allKeys[(start + 4) % 12], allKeys[(start + 7) % 12]);
}

void getMinorKeys(char *key, char *allKeys[], int start)
{
  printf("%sm: %s %s %s\n", key, key, allKeys[(start + 3) % 12], allKeys[(start + 7) % 12]);
}

void getDominantSeventh(char *key, char *allKeys[], int start)
{
  printf("%sm: %s %s %s %s\n", allKeys[start % 12], allKeys[start % 12], allKeys[(start + 4) % 12], allKeys[(start + 7) % 12], allKeys[(start + 10) % 12]);
}

void getDiminishedSeventh(char *key, char *allKeys[], int start)
{
  printf("%sm: %s %s %s %s\n", allKeys[start % 12], allKeys[start % 12], allKeys[(start + 3) % 12], allKeys[(start + 6) % 12], allKeys[(start + 9) % 12]);
}

void printKeys(char *key, char *allKeys[], int start)
{
  getMajorKeys(key, allKeys, start);
  getMinorKeys(key, allKeys, start);
  getDominantSeventh(key, allKeys, start);
  getDiminishedSeventh(key, allKeys, start);
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
  if (argc != 2)
  {
    printf("This program requires exactly one command line argument.\n");
  }
  else if (checkArgs(argv[1]) == 1)
  {
    for (int i = 0; i < numOfKeys; i++)
    {
      if (strcmp(allKeys[i], argv[1]) == 0)
      {
        printKeys(argv[1], allKeys, i);
      }
    }
  }
  else
  {
    printf("No such key: %s\n", argv[1]);
  }
  return 0;
}
