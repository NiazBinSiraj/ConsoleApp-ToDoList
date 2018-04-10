#include <bits/stdc++.h>
using namespace std;

void Welcome()
{
    char s[50];
    freopen("welcome.txt","r",stdin);
    while(gets(s)!=NULL)
      puts(s);
}


void Add()
{
    freopen("input-message.txt","r",stdin);
    char s[50];
    gets(s);
    puts(s);
}

int main()
{
    Welcome();
    Add();
    return 0;
}
