#include <bits/stdc++.h>
using namespace std;

int counter()
{
    FILE *p;
    int cnt;
    p = fopen("counter.txt","r");
    fscanf(p,"%d",&cnt);
    fclose(p);

    p = fopen("counter.txt","w");
    fprintf(p,"%d",cnt+1);
    fclose(p);
    return cnt;
}

void welcome()
{
    FILE *p;
    char s[100];
    p = fopen("welcome.txt","r");
    while(fgets(s,100,p)!=NULL)
      printf("%s",s);
    fclose(p);
}


int select()
{
    FILE *p;
    char s[100];
    p = fopen("select.txt","r");
    while(fgets(s,100,p)!=NULL)
      printf("%s",s);
    fclose(p);

    int action;
    scanf("%d",&action);
    return action;
}


void add()
{
    FILE *p;
    char s[5000];
    p = fopen("input-message.txt","r");
    fgets(s,100,p);
    printf("%s",s);
    fclose(p);

    gets(s);
    gets(s);
    p = fopen("list.txt","a");
    fprintf(p,"%d. %s\n\n",counter()+1,s);
    fclose(p);


    return;
}


int main()
{

    welcome();

    while(true)
    {
        int a = select();
        if(a == 1) add();
        else if(a==4) break;
    }

    return 0;
}
