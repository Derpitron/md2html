// This file is my own idea but I don't think it's good design
#include "stdio.h"

void parseLine(char text[], int len) {
  //Parsing h1
  
  char elementContentBuf[64];
  
  int index = 0;
  int hCount = 0;

  while (text[index] == '#') {
    index++;
    hCount++;
  }

  //capture the rest of the non-format text
  for (int j = index; j < len; j++) {
    if (text[j] != '\n') {
     elementContentBuf[j-index] = text[j];
    }
  }

  printf("<h%2$d>%s</h%2$d>\n", elementContentBuf, hCount);
  return;
}

int main() {
  char example[] = "##he# hello";
  parseLine(example, sizeof(example)/sizeof(char));
  return 0;
}
