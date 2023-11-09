#include <iostream>
#include <string.h>

using namespace std;
void prefixlps(char * pattern,int M,int *lps){
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<M){
        if(pattern[i]==pattern[len]){
            i++;
            len++;
            lps[len]=len;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}


void kmpsearch(char *text,char *pattern){
    int N=strlen(text);
    int M=strlen(pattern);
    int lps[M];
    prefixlps(pattern,M,lps);
    int i=0,j=0;
    while((N-i)>=(M-j)){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i=i+1;
            }
        }
        if(j==M){
        printf("Pattern found");
        j=lps[j-1];
        }
    }
}

int main()
{
    char txt[]="aaacaababaca";
    char pat[]="aaba";
    kmpsearch(txt,pat);

    return 0;
}

