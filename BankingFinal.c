#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>


typedef struct
{
    char name[50];
    int accountNumber;
    char password[50];
    float balance;
    float loan;
} Account;



char adminPassword[50]="ADM";


Account accounts[100];
int accountCount=0;



void loadAccounts()
{
    FILE *file=fopen("accounts.txt","r");
    if(file!=NULL)
    {
        fscanf(file,"%s",adminPassword);
        fscanf(file,"%d",&accountCount);
        for(int i=0;i<accountCount;i++)
        {
            fscanf(file,"%s %d %s %f %f",accounts[i].name,&accounts[i].accountNumber,accounts[i].password,&accounts[i].balance,&accounts[i].loan);
        }
        fclose(file);
    }

    else
    {
        strcpy(adminPassword, "ADM");
    }
}


void saveAccounts()
{
    FILE *file=fopen("accounts.txt","w");
    fprintf(file,"%s\n",adminPassword);
    fprintf(file,"%d\n",accountCount);
    for(int i=0;i<accountCount;i++)
    {
        fprintf(file,"%s %d %s %.2f %.2f\n",accounts[i].name,accounts[i].accountNumber,accounts[i].password,accounts[i].balance,accounts[i].loan);
    }
    fclose(file);
}


void createAccount() {
   int accountnum;
    printf("Enter name (Without spaces): ");
    scanf("%s", accounts[accountCount].name);
    for (int i = 0; accounts[accountCount].name[i] != '\0'; i++) {
        if (!isalpha(accounts[accountCount].name[i])) {
            system("cls");
            printf("Invalid data type. Please enter only alphabets for the name.\n");
            printf("Press any key to continue.\n");
            getch();
            system("cls");
            createAccount();
            return;
        }
    }
    printf("Enter account number: ");
    if (scanf("%d",&accountnum)!=1)
    {
        fflush(stdin);
        system("cls");
        printf("Please enter a valid datatype (Integer).\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
        createAccount();
    }
    for (int i=0;i<=accountnum;i++)
    {
        if(accounts[i].accountNumber==accountnum)
        {
            fflush(stdin);
            system("cls");
            printf("This account number already exists! please select any other number.\n");
            printf("Press any key to continue.\n");
            getch();
            system("cls");
            main();
        }
    }
    accounts[accountCount].accountNumber=accountnum;
    printf("Enter password: ");
    scanf("%s",accounts[accountCount].password);
    accounts[accountCount].balance=0;
    accountCount++;
    saveAccounts();
    system("cls");
    printf("Account created successfully.\n");
    printf("Press any key to continue.\n");
    getch();
    system("cls");
}


void deposit()
{
    int accountNumber;
    printf("Enter account number: ");
    if (scanf("%d",&accountNumber)!=1)
    {
        fflush(stdin);
        system("cls");
        printf("Please enter a valid datatype (Integer).\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
        deposit();
    }
    for(int i=0;i<accountCount;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            char password[50];
            printf("Enter password: ");
            scanf("%s",password);
            if(strcmp(accounts[i].password,password) ==0)
            {
                float amount;
                printf("Enter amount to deposit: ");
                if (scanf("%f",&amount)!=1)
                {
                    fflush(stdin);
                    system("cls");
                    printf("Please enter a valid datatype (float/Integer).\n");
                    printf("Press any key to continue.\n");
                    getch();
                    system("cls");
                    deposit();
                }
                accounts[i].balance+=amount;
                system("cls");
                printf("Deposit successful.\nNew balance: %.2f\n\n",accounts[i].balance);
                saveAccounts();
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }

            else
            {
                system("cls");
                printf("Incorrect password.\nPlease retry.\n\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }
            return;
        }
    }
    printf("Account not found.\n\n");
    printf("Press any key to continue.\n");
    getch();
    system("cls");
}


void withdraw()
{
    int accountNumber;
    printf("Enter account number: ");
    if (scanf("%d",&accountNumber)!=1)
    {
        fflush(stdin);
        system("cls");
        printf("Please enter a valid datatype (Integer).\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
        withdraw();
    }
    for(int i=0;i<accountCount;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            char password[50];
            printf("Enter password: ");
            scanf("%s",password);
            if(strcmp(accounts[i].password,password) ==0)
            {
                float amount;
                printf("Enter amount to withdraw: ");
                if (scanf("%f",&amount)!=1)
                {
                    fflush(stdin);
                    system("cls");
                    printf("Please enter a valid datatype (Integer).\n");
                    printf("Press any key to continue.\n");
                    getch();
                    system("cls");
                    withdraw();
                }
                if(amount<=accounts[i].balance)
                {
                    accounts[i].balance-=amount;
                    saveAccounts();
                    system("cls");
                    printf("Withdrawal successful.\nNew balance: %.2f\n\n",accounts[i].balance);
                    printf("Press any key to continue.\n");
                    getch();
                    system("cls");
                }

                else
                {
                    system("cls");
                    printf("Insufficient funds.\n");
                    printf("Press any key to continue.\n");
                    getch();
                    system("cls");
                }
            }

            else
            {
                system("cls");
                printf("Incorrect password.\nPlease retry.\n\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }
            return;
        }
    }
    printf("Account not found.\n");
    printf("Press any key to continue.\n");
    getch();
    system("cls");
}


void checkBalance()
{
    int accountNumber;
    printf("Enter account number: ");
    if (scanf("%d",&accountNumber)!=1)
    {
        fflush(stdin);
        system("cls");
        printf("Please enter a valid datatype (Integer).\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
        checkBalance();
    }
    for(int i=0;i<accountCount;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            char password[50];
            printf("Enter password: ");
            scanf("%s",password);
            if(strcmp(accounts[i].password,password)==0)
            {
                system("cls");
                printf("Your balance is: %.2f\n",accounts[i].balance);
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }

            else
            {
                system("cls");
                printf("Incorrect password.\nPlease retry.\n\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }
            return;
        }
    }
    system("cls");
    printf("Account not found.\n");
    printf("Press any key to continue.\n");
    getch();
    system("cls");
}


void modifyAccount()
{
    int accountNumber;
    printf("Enter account number: ");
    if (scanf("%d",&accountNumber)!=1)
    {
        fflush(stdin);
        system("cls");
        printf("Please enter a valid datatype (Integer).\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
        modifyAccount();
    }
    for(int i=0;i<accountCount;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            char password[50];
            printf("Enter current password: ");
            scanf("%s",password);
            if(strcmp(accounts[i].password, password)==0)
            {
                printf("Your account name is %s. ",accounts[i].name);
                printf("Enter new password: ");
                scanf("%s",accounts[i].password);
                saveAccounts();
                system("cls");
                printf("Account modified successfully.\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }
            
            else
            {
                system("cls");
                printf("Incorrect password. Please retry.\n\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }
            return;
        }
    }
    system("cls");
    printf("Account not found.\n");
    printf("Press any key to continue.\n");
    getch();
    system("cls");
}


void takeloan()
{
    int accountNumber;
    printf("Enter account number: ");
    if (scanf("%d",&accountNumber)!=1)
    {
        fflush(stdin);
        system("cls");
        printf("Please enter a valid datatype (Integer).\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
        takeloan();
    }
    for(int i=0;i<accountCount;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            char password[50];
            printf("Enter password: ");
            scanf("%s",password);
            if(strcmp(accounts[i].password,password)==0)
            {
                float amount,temp;
                temp=accounts[i].loan;
                printf("Enter loan amount (Maximum 1 Lakhs.): ");
                if (scanf("%f",&amount)!=1)
                {
                    fflush(stdin);
                    system("cls");
                    printf("Please enter a valid datatype (Integer).\n");
                    printf("Press any key to continue.\n");
                    getch();
                    system("cls");
                    takeloan();
                }
                if(amount>100000 || ((temp+=amount)>100000))
                {
                    printf("Loan amount exceeds limit.\n");
                    printf("Press any key to continue.\n");
                    getch();
                    system("cls");
                }

                else
                {
                    accounts[i].loan+=amount;
                    saveAccounts();
                    printf("Loan granted.\n");
                    printf("Press any key to continue.\n");
                    getch();
                    system("cls");
                }
            }

            else
            {
                printf("Incorrect password. Please retry.\n\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }
            return;
        }
    }
    printf("Account not found.\n");
    printf("Press any key to continue.\n");
    getch();
    system("cls");
}


void repayLoan()
{
    int accountNumber;
    printf("Enter account number: ");
    if (scanf("%d",&accountNumber)!=1)
    {
        fflush(stdin);
        system("cls");
        printf("Please enter a valid datatype (Integer).\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
        repayLoan();
    }
    for(int i=0;i<accountCount;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            char password[50];
            printf("Enter password: ");
            scanf("%s",password);
            if(strcmp(accounts[i].password,password)==0)
            {
                printf("Your current loan amount is: %.2f\n",accounts[i].loan);
                float amount;
                printf("Enter amount to repay: ");
                if (scanf("%f",&amount)!=1)
                {
                    fflush(stdin);
                    system("cls");
                    printf("Please enter a valid datatype (Integer).\n");
                    printf("Press any key to continue.\n");
                    getch();
                    system("cls");
                    repayLoan();
                }
                if(amount<=accounts[i].loan)
                {
                    accounts[i].loan-=amount;
                    saveAccounts();
                    system("cls");
                    printf("Loan repaid successfully.\nRemaining loan: %.2f\n\n",accounts[i].loan);
                    printf("Press any key to continue.\n");
                    getch();
                    system("cls");
                }
                
                else
                {
                    system("cls");
                    printf("Repayment amount exceeds loan amount, Plese repay upto the loan balance only.\n");
                    printf("Press any key to continue.\n");
                    getch();
                    system("cls");

                }
            }

            else
            {
                system("cls");
                printf("Incorrect password. Please retry.\n\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }
            return;
        }
    }
    system("cls");
    printf("Account not found.\n");
    printf("Press any key to continue.\n");
    getch();
    system("cls");
}


void loan()
{
    system("cls");
    printf("\t\t\t~~~~~~~~~~ LOAN ~~~~~~~~~~\n\n");
    int choice;
    printf("1. Loan\n2. Repay loan\n3. Exit\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            system("cls");
            takeloan();
            break;
        }

        case 2:
        {
            system("cls");
            repayLoan();
            break;
        }

        case 3:
        {
            system("cls");
            return;
        }

        default:
            {
                printf("Invalid choice.\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }
    }
}


void deleteAccount()
{
    int accountNumber;
    printf("Enter account number: ");
    if (scanf("%d", &accountNumber)!=1)
    {
        fflush(stdin);
        system("cls");
        printf("Please enter a valid datatype (Integer).\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
        deleteAccount();
    }
    for(int i=0;i<accountCount;i++)
    {
        if(accounts[i].accountNumber==accountNumber)
        {
            char password[50];
            printf("Enter password: ");
            scanf("%s",password);
            if(strcmp(accounts[i].password,password)==0)
            {
                for(int j=i;j<accountCount-1;j++)
                {
                    accounts[j]=accounts[j+1];
                }
                accountCount--;
                saveAccounts();
                system("cls");
                printf("Account deleted successfully.\n\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }

            else
            {
                printf("Incorrect password. Please retry.\n\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
            }
            return;
        }
    }
    printf("Account not found.\n");
}


void adminlist()
{
    printf("Total Accounts: %d\n\n", accountCount);
    for(int i=0;i<accountCount;i++)
    {
        printf("Account %d:\n",i+1);
        printf("Name: %s\n",accounts[i].name);
        printf("Account Number: %d\n",accounts[i].accountNumber);
        printf("Balance: %.2f\n",accounts[i].balance);
        printf("Loan: %.2f\n\n",accounts[i].loan);
    }
    printf("Press any key to continue.");
    getch();
    system("cls");
}


void changeAdminPassword()
{
    char oldPassword[50],newPassword[50];
    printf("Enter old password: ");
    scanf("%s",oldPassword);
    if(strcmp(oldPassword,adminPassword)==0)
    {
        printf("Enter new password: ");
        scanf("%s",newPassword);
        strcpy(adminPassword,newPassword); 
        printf("Password changed successfully.\n");
        saveAccounts();
        system("cls");
        printf("Admin password has been successfully updated.\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
    }
    
    else
    {
        printf("Incorrect old password. Please retry.\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
    }
}


void adminLogin()
{
    int x;
    system("cls");
    char password[50];
    printf("Enter admin password: ");
    scanf("%s",password);
    if(strcmp(password,"ADM")==0)
    {
        printf("Admin login successful.\n");
        printf("Press any key to continue.\n");
        getch(); 
        system("cls");
        printf("\t\t\t~~~~~~~~~~ ADMIN PANNEL ~~~~~~~~~~\n\n");
        printf("1. User list\n2. Change admin password\n3. Exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            {
                adminlist();
                break;
            }

            case 2:
            {
                changeAdminPassword();
                break;
            }

            case 3:
            {
                system("cls");
                printf("Exited Admin pannel.\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
                return;
                break;
            }

            default:
            {
                printf("Invalid Choice.\n");
                getch();
                printf("Press any key to continue.\n");
            }
        }
    }

    else
    {
        printf("Incorrect password. Please retry.\n");
        printf("Press any key to continue.\n");
        getch();
        system("cls");
    }
}


void credits()
{
    system("cls");
    printf("\t\t\t~~~~~~~~~~ CREDITS ~~~~~~~~~~\n\n");
    printf("This project was developed by:");
    printf("Press any key to continue.\n");
    getch();
    system("cls");
}


void help()
{
    system("cls");
    printf("\t\t\t~~~~~~~~~~ HELP ~~~~~~~~~~\n\n");
    printf("1. Create Account: Allows you to create a new account.\n");
    printf("2. Deposit: Deposit money into your account.\n");
    printf("3. Withdraw: Withdraw money from your account.\n");
    printf("4. Check Balance: View the balance of your account.\n");
    printf("5. Modify Account: Change account details.\n");
    printf("6. Delete Account: Remove an account from the system.\n");
    printf("7. Loan: Take out or repay a loan.\n");
    printf("8. Admin Login: Access the admin panel to manage accounts.\n");
    printf("9. Credits: View information about the developers.\n");
    printf("Press any key to continue.\n");
    getch();
    system("cls");
}


int main()
{
    system("cls");
    loadAccounts();
    while(1)
    {
        printf("\t\t\t~~~~~~~~~~ BANKING SYSTEM ~~~~~~~~~~\n\n");
        printf("1. Admin login\n2. User login\n3. Loan\n4. Credits\n5. Help\n6. Exit\nEnter your choice: ");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    adminLogin();
                    break;
                }

            case 2:
            {
                system("cls");
                printf("\t\t\t~~~~~~~~~~ USER PANNEL ~~~~~~~~~~\n\n");
                printf("1. Create account\n2. Deposit\n3. Withdraw\n4. Check balance\n5. Modify account\n6. Delete account\nEnter your choice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                        {
                            createAccount();
                            break;
                        }
                    
                    case 2:
                        {
                            deposit();
                            break;
                        }
                        
                    case 3:
                        {
                            withdraw();
                            break;
                        }
                    
                    case 4:
                        {
                            checkBalance();
                            break;
                        }

                    case 5:
                        {
                            modifyAccount();
                            break;
                        }

                    case 6:
                        {
                            deleteAccount();
                            break;
                        }
                        
                    default:
                        {
                            printf("Invalid choice.\n");
                        }  
                }
                break;
            }

            case 3:
                {
                    loan();
                    break;
                }

            case 4:
                {
                    credits();
                    break;
                }

            case 5:
                {
                    help();
                    break;
                }

            case 6:
                {
                    exit(0);
                }

            default:
                system("cls");
                printf("Invalid choice.\n");
                printf("Press any key to continue.\n");
                getch();
                system("cls");
        }
    }
    return 0;
}