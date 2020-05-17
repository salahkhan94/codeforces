#include <stdio.h>

typedef struct UserInfo
{
    long long credit_amount;
    int last_payment;
    int id;
    int years_member;
    char first_name_initial;
    char suffix;    
    char last_name_initial;
    char prefix;
    
} UserInfo;

#ifndef RunTests
int main()
{
    printf("%ld", sizeof(UserInfo));
}
#endif