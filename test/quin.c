#include <stdio.h>
char*s="#include <stdio.h>%cchar*s=%c%s%c;int main(){printf(s,10,34,s,34);}";int main(){printf(s,10,34,s,34);}
/*#include <stdio.h>
char*s="#include <stdio.h>%cchar*s=%c%s%c;int main(){printf(10,s,34,s,34);}";int main(){printf(10,s,34,s,34);}*/