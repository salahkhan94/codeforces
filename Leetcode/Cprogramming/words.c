#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void sort_words(char *words[], int count)
{
    int max=0;
    for(int i=0;i<count;i++){
        if(max<strlen(words[i])) max = strlen(words[i]);
    }
    char *temp = (char *)malloc((max + 1) * sizeof(char));
    for(int i=0;i<count;i++){
        max =i;
        strcpy(temp,words[i]);
//        printf("%s \n", temp);
        for(int j=i+1;j<count;j++){
            if(strcmp(temp, words[j])<0){
                strcpy(temp,words[j]);
                max = j;
            }
        }
        if(i!=max){
//            printf("%s \n", temp);
            char *t=words[max];
            words[max] = words[i];
            words[i] = t;
        }
    }
}

#ifndef RunTests
int main()
{
    char *words[] = { "cherry", "orange", "apple" };
//    strcpy(words[0], words[1]);
    sort_words(words, 3);

    for (int i = 0; i < 3; i++)
    {
        printf("%s ", words[i]);
    }
}
#endif