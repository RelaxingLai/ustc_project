
 
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
 
 
#include <stdio.h>
char *pszNian[]={" ","ʮ","��","ǧ","��","ʮ","��","ǧ","��"};
char *pszShu[]={"��","Ҽ","��","��","��","��","½","��","��","��"};
void f1(int a,int b)
{
    if(a>=10)
        f1(a/10,b+1);
    if(a%10!=0)
        printf("%s%s",pszShu[a%10],pszNian[b]);
    else
        printf("%s",pszShu[a%10]);
}
 
int main() {
    char a='0';
    string t="12345";
    int t1[t.size()];
    for(int i=0;i<t.size();i++){
        t1[i]=int(t[i]);
    }
    cout<<t[1];
    return 0;
} 
