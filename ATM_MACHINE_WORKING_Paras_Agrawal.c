#include<stdio.h>
#include<conio.h>
#include<string.h>
struct ATM
{
       int acno;
       char name[50];
       int amount;
       int phonum;
       int transactions[100];
       int transactioncount;
       char status[20];
};struct ATM A1;
 void design();
 void Createacc();
 void Deposit();
 void withdrawl();
 void Balance();
 void TransactionHistory();
 void ChangePin();

int main(){
    int choice=0;
    char ch1,ch2,ch3,ch4;
    printf("Enter Your pin:");
    ch1=getch();
    printf("*");
    ch2=getch();
    printf("*");
    ch3=getch();
    printf("*");
    ch4=getch();
    printf("*");
    if(ch1=='1'&& ch2=='2'&& ch3=='3'&&ch4=='4'){
    
    do{
    design();
    printf("\n Enter your choice");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:Createacc();
           break;
    case 2:Deposit();
           break;
    case 3:withdrawl();
           break;
    case 4:Balance();
           break;
    case 5:TransactionHistory();
           break;
    case 6:ChangePin();
           break;
    default:printf("Invalid Choice.....");
    }
    }while(choice!=7);
    }
    else{
       printf("\n Invalid Pin");
    }
    return 0;
}
void ChangePin(){
       char newCh1,newCh2,newCh3,newCh4;
       printf("\nEnter a new 4-Digit PIN:");
       newCh1=getch();
       printf("*");
       newCh2=getch();
       printf("*");
       newCh3=getch();
       printf("*");
       newCh4=getch();
       printf("*");
       char ch1,ch2,ch3,ch4;
       ch1=newCh1;
       ch2=newCh2;
       ch3=newCh3;
       ch4=newCh4;
       printf("\nPIN successfully changed!\n");

}
void design(){
    printf("\n______________________!!Welcome!!__________________________");
    printf("\n_____________ATM Banking Management System_________________");
    printf("\n\t 1 Create Account");
    printf("\n\t 2 Deposit Amount");
    printf("\n\t 3 withdrawl Amount");
    printf("\n\t 4 Check Balance"); 
    printf("\n\t 5 Transaction History");
    printf("\n\t 6 Change Pin");
    printf("\n\t 7 Exit");
    printf("\n___________________________________________________________");
}
void Createacc()
{
    printf("\nEnter Account Number");
    scanf("%d",&A1.acno);
    printf("\nEnter Your Name");
    scanf("%s",&A1.name);
    printf("\nEnter Amount");
    scanf("%d",&A1.amount);
    printf("\nEnter Phone Number");
    scanf("%d",&A1.phonum);
    A1.transactioncount =0;
    printf("Enter User Status (e.g.,Active,Inactive):");
    scanf("%s",A1.status);

}
void Deposit()
{
    int amt;
    printf("\nEnter an amount for deposit");
    scanf("%d",&amt);
    if(amt<0){
       printf("\nInvalid amount");
    }
    else{
       A1.amount=A1.amount+amt;
       A1.transactions[A1.transactioncount++]=amt;
       printf("Deposit Successful NewBalance:%d\n",A1.amount);
    }
}
void withdrawl()
{
   int amt;
   printf("\nEnter an amount for withdrawl");
   scanf("%d",&amt);
   if(amt<0){
      printf("\nInvalid amount");
   }
   if(amt>A1.amount){
       printf("\nInsufficiant Balance");
   }
   else{
      A1.amount=A1.amount-amt;
      A1.transactions[A1.transactioncount++]=-amt;
      printf("Deposit Successful NewBalance:%d\n",A1.amount);
   }
}
void Balance()
{
       printf("\nAccount No: %d",A1.acno);
       printf("\nName: %s",A1.name);
       printf("\nBalance: %d",A1.amount);
       printf("\nPhone Number:%d",A1.phonum);
       printf("\nStatus: %s\n",A1.status);

}
void TransactionHistory(){
       printf("\nTransition History for Accont Name %s:\n",A1.name);
       printf("\nTransition History for Account No %d:\n",A1.acno);
       for(int i=0;i<A1.transactioncount;i++){
              if(A1.transactions[i]>0){
                     printf("Desposit: %d\n",A1.transactions[i]);
              }
              else{
                     printf("Withdrawl : %d\n",-A1.transactions[i]);
              }
       }
}