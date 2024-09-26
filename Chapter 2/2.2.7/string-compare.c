#include<stdio.h>
#include<string.h>
//--- Practice Problem 2.26

/* Prototype for library function strlen */
size_t strlen(const char *s);

/* Determine whether string s is longer than string t */
int strlonger(char *s, char *t) {
    return strlen(s) > strlen(t);
}

int main(){
  char *s = "a";
  char *t = "abc";
  printf("%d\n", strlonger(s, t));
  if (strlonger(s, t)) {
    printf("%s is longer than %s\n",s,t);
  } else {
    printf("%s is longer than or equal to %s\n",t,s);
  }
  return 0;
}