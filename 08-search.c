#include <stdio.h>
#include <string.h>
void calcLPS(char pattern[], int lps[])
{
    int len = strlen(pattern);
    int i = 1, j = 0;
    while (i < len)
    {
        if (pattern[j] == pattern[i])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPAlgorithm(char* txt, char* pat){
    int p = strlen(pat);
    int t = strlen(txt); 

    int lps[p];
    calcLPS(pat, lps);

    int i=0,j=0;
    while (i<t)
    {
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        if(j==p){
            printf("Found at %d index.\n",i-j);
            j=lps[j-1];
        }
        else if(i<t && pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }else{
                i=i+1;
            }
        }
    }
     
}

void naiveSearch(char* txt, char* pat){
    int p = strlen(pat);
    int t = strlen(txt);

    for(int i=0; i<=t-p;i++){
        int j;
        for( j=0;j<p;j++){
            if(txt[i+j]!=pat[j]){
                break;
            }
        }
        if(j==p){
            printf("\nPattern fount at %d index.", i);
        }
    }
}

void main()
{
    int lenOfTxt;
    printf("\nEnter length of string:");
    scanf("%d", &lenOfTxt);

    char txt[lenOfTxt];
    printf("\nEnter the string:");
    scanf("%s", txt);

    int lenOfSe;
    printf("\nEnter length of search string:");
    scanf("%d", &lenOfSe);
    char searchP[lenOfSe];
    printf("\nEnter the search string:");
    scanf("%s", searchP);

    int ch;
    printf("\n1 Naive\n2 KMP\n0 Exit\nSelect-");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        naiveSearch(txt,searchP);
        break;
    case 2:
        KMPAlgorithm(txt,searchP);
        break;
    case 0:
        return;
    default:
        printf("Try Again...");
        break;
    }

}