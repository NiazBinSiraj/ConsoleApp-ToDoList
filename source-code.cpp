//To Do List Source Code

#include <bits/stdc++.h>
using namespace std;
#define MX 10000

int counter()
{
    FILE *p;
    int cnt;
    p = fopen("counter.txt","r");
    fscanf(p,"%d",&cnt);
    fclose(p);
    return cnt;
}

void welcome()
{
    FILE *p;
    char s[100];
    p = fopen("welcome.txt","r");
    while(fgets(s,100,p) != NULL)
    {
        printf("%s",s);
    }
    fclose(p);
    return;
}


int select()
{
    FILE *p;
    char s[100];
    p = fopen("select.txt","r");
    while(fgets(s,100,p) != NULL)
    {
        printf("%s",s);
    }
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
    printf("%s\n",s);
    fclose(p);

    gets(s);
    gets(s);
    p = fopen("list.txt","a");
    fprintf(p,"%d. %s\n",counter()+1,s);
    fclose(p);

    int cnt;
    p = fopen("counter.txt","r");
    fscanf(p,"%d",&cnt);
    fclose(p);
    p = fopen("counter.txt","w");
    fprintf(p,"%d",cnt+1);
    fclose(p);
    return;
}

void show()
{
    printf("List:\n");
    if(counter() == 0) {printf("List is Empty\n"); return;}
    FILE *p;
    char s[MX];
    p = fopen("list.txt","r");
    while(fgets(s,MX,p) != NULL)
    {
        printf("%s",s);
    }
    fclose(p);
    printf("\n");
    return;
}

void delete_item()
{
    FILE *p;
    char s[100];
    p = fopen("delete-message.txt","r");
    while(fgets(s,100,p) != NULL)
    {
        printf("%s",s);
    }
    printf("\n");
    fclose(p);
    int number;
    scanf("%d", &number);


    char temp[MX];
    p = fopen("list.txt","r");
    FILE *p1, *p2;
    p1 = fopen("temp.txt","a");
    p2 = fopen("deleted-item.txt","a");

    int t,i=0;
    int def=0;
    while(i<counter())
    {
        i++;
        fscanf(p,"%d",&t);
        fgets(temp,MX,p);

        if(t != number)
        {
            fprintf(p1,"%d%s",t-def,temp);
        }
        else
        {
            fprintf(p2,"%d%s",t,temp);
            def=1;
        }
    }
    fclose(p);
    fclose(p1);

    int cnt;
    p = fopen("counter.txt","r");
    fscanf(p,"%d",&cnt);
    fclose(p);
    p = fopen("counter.txt","w");
    fprintf(p,"%d",cnt-1);
    fclose(p);

    rename("list.txt","del.txt");
    rename("temp.txt","list.txt");
    remove("del.txt");

    printf("Successfully Deleted\n");
    return;
}

void reset()
{
    fclose(fopen("list.txt", "w"));
    fclose(fopen("deleted-item.txt", "w"));

    FILE *p;
    p = fopen("counter.txt","w");
    fprintf(p,"%d",0);
    fclose(p);

    printf("Reset Successful\n");
    return;
}

int main()
{
    welcome();

    while(true)
    {
        int a = select();
        if(a == 1) add();
        else if(a == 2) show();
        else if(a == 3) delete_item();
        else if(a == 4) reset();
        else if(a == 5) break;
    }

    return 0;
}
