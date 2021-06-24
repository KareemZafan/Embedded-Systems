#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SIZE 100

typedef enum
{
    BALANCED,
    NON_BALANCED

} balance;
typedef unsigned char u8 ;

void Stack_Push(int value) ;
int  Stack_Pull(void) ;
void Stack_Print(void) ;
balance balancedParenthesis(u8* experssion);


static  int top = -1 ;
static  int arr[SIZE];
int main()
{
    u8 expression[30] ;
    u8 toContinue;

    do{
    printf("Enter an expression \n") ;
    gets(expression) ;

    if(balancedParenthesis(expression) != BALANCED)
    {
        printf("Non Balanced\n") ;

    }
    else
    {
        printf("Balanced\n") ;
    }
    printf("press any key to continue or Press -1 to exit\n");
    toContinue = (u8) getche() ;
    printf("\n\n") ;
    }while(toContinue != -1) ;

    return 0;
}

void Stack_Push(int value)
{
    if(top < SIZE)
    {
//        printf("%d is pushed\n",value) ;
        arr[++top] = value ;

    }
    else
    {
        top = -1 ;
        printf("Stack Overflow!!\n") ;
    }
    return ;
}

int Stack_Pull(void)
{
    if(top >= 0 )
    {
//        printf("%d is poped\n",arr[top]) ;
        return arr[top--] ;
    }
    else
    {
        printf("Stack Underflow (Stack is Empty ) !!\n");
        top = -1 ;
    }
}

void Stack_Print(void)
{

    if(top < 0 ) printf("Stack is empty !\n") ;
    else
        for(int i= top ; i >= 0  ; --i)
        {
            printf("%d \n",arr[i]) ;

        }
    return ;
}

balance balancedParenthesis(u8* experssion)
{
    int curelyParcesRightCount= 0 ;
    int curelyParcesLeftCount = 0 ;
    int parenthesisRightCount = 0 ;
    int parenthesisLeftCount  = 0 ;

    if(0 == strlen(experssion))
    {
        printf("The expression is empty !!\n"); return BALANCED;
    }

    else{
        for(int i = 0 ; i <strlen(experssion); ++i )
        {
            Stack_Push(experssion[i]) ;
            switch((char)experssion[i])
            {
            case '}':
                curelyParcesRightCount++ ;
                break ;
            case '{':
                curelyParcesLeftCount++ ;
                break ;
            case ')':
                parenthesisRightCount++ ;

                break ;
            case '(':
                parenthesisLeftCount++ ;
                break ;
            default:
                break ;
            }

        }
        for(int i = 0 ; i <strlen(experssion); ++i ) Stack_Pull() ;
    }

    if((parenthesisLeftCount - parenthesisRightCount ) == 0 && (curelyParcesLeftCount - curelyParcesRightCount) == 0 )
        return BALANCED ;
    else
        return NON_BALANCED ;
}


