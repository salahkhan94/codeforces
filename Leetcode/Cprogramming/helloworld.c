#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

double average(int n, ...){
    va_list arguments;
    double sum = 0;
    va_start(arguments, n);
    
    for(int x=0; x<n;x++){
        sum+=va_arg(arguments,double);
    }
    va_end(arguments);
    return sum/n;
}

void correctstring(char *trr, int size){
    for(int i=0;i<size;i++){
        if(trr[i]=='\n'){
            trr[i] = '\0';
            return;
        }
    }
}
struct node {
  int x;
  struct node *next;
};

int main(){
     printf( "%f\n", average ( 3, 12.2, 22.3, 4.5 ) );
    printf("The average of 4 numbers is : %f", average(5,1.0,2.0,3.0,4.3,5.2));
    struct node *root;
    root = (struct node *) malloc (sizeof(struct node));
    root->x = 6;
    root->next = NULL;
    struct node *conductor;
    conductor = root;
    if(conductor!=NULL){
        while (conductor->next!=NULL)
        {
            printf("Current value : %d \n ", conductor->x);
            conductor = conductor->next;    
        }
    }
    printf("Current value of the LinkedList : %d \n", conductor->x);
    conductor->next = (struct node *) malloc(sizeof(struct node));
    conductor = conductor->next;
    conductor->x = 8;
    conductor->next = NULL;

    conductor->next = (struct node *) malloc(sizeof(struct node));
    conductor = conductor->next;
    conductor->x = 10;
    conductor->next = NULL;

/*  printf("Hello World \n");
    int i;
    for(i=0; i<10;i++){
        printf("The Value of i is : %d\n", i);
    }
    for(char a=' '; a<'}';a++){
        printf("The Value of a is : %c\n", a);
    }
    int f;
// scanf("%d", &f);
    char s;
    char *t;
    t=&s;
    char name[20], fullname[40], lastname[20];
    fgets(name, 20, stdin);
    correctstring(name, 20);
    if(strcmp(name,"salahuddin") ==0){
        printf("That's my name too\n");
    }
    else printf("That's not my name\n");
    
    fgets(lastname, 20,stdin);
    correctstring(lastname,20);
    strncpy(fullname, name, 40);
    strncpy(fullname, " ", 40);
    strncpy(fullname, lastname, 40);
    fputs(fullname, stdout);
    fullname[0] = '\0';  
    strcat(fullname, name);
    //printf("The full name is : %s", fullname);
    strcat(fullname, " ");
    strcat(fullname, lastname);
    printf("The full name is : %s", fullname);
    for(i=0;i<128;i++){
        printf("Ascii value %d = %c \n", i, (char)i);
    }
    //fputs(fullname,stdout);
    //printf("")
    
    /*fputs(trr, stdout);
    scanf("%c %d %s", &s, &f, arr);
    //printf("You've entered integer less than 100: %d \n", f);
    for(i=0;i<10;i++){
        printf("%c", arr[i]);
    }
    printf("You've entered character : %c\n", *t);
    int *ptr = malloc(sizeof(int));
    ptr = &f;

    if(*ptr<50){
        printf("You've entered a number which is less than 50\n");
    }
    else printf("You've entered a number which is greater than 50\n");
    
    free(ptr);*/
    //putchar(s);
    //getchar();

    return 0;

}