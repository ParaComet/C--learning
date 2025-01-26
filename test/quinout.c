#include <stdio.h>/*
'''*/
char*s="#include <stdio.h>/*%c'''*/%cchar*s=%c%s%c;int main(){printf(s,10,34,s,34,10,10);}%c//'''%c#if 0%cr='r=%r\nprint(r%%r)'";int main(){printf(s,10,10,34,s,34,10,10,10,10);}
//'''
#if 0
r='r=%r\nprint(r%%r)'
print(r%r)
#endif
