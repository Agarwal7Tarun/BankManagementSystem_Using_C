#include<stdio.h> //Default C Library
#include<conio.h> //Used especially for getch()
#include<string.h> //Used especially for gets() and other string functions
#include<stdlib.h> // For standard input and output method 
#include<windows.h> //Used especially for commands including funtion system i.e. system("cls")
struct date
{
    int day,month,year;
};
struct Bank
{
    char name[30];
    char parent_name[30];
    struct date dob;
    int age;
    char mobile_no[20];
    char citizenship[20];
    char address[90];
    char account_type[10];
    char account_no[100];
    float avail_bal;
    struct date deposit; 
    struct date withdraw;
    int no_of_deposits;
    int no_of_withdrawls;
    int status;
}add,upd,check,rem,transact;
void login();   
void mainmenu();
void acc_open();
void update_acc();
void transaction();
void view_acc_info();
void delete_acc();
void view_all();
void close();
void makeDeposit();
void makeWithdrawal();
void main()     
{
    system("cls");
    printf("\n\n\t\t\tWelcome to The British College Bank");
    printf("\n\n\t\t\t Press any key to continue..");
    getch();
    login();

}
void login()
{
    char user[25];
    char pass[10];
    int x;  
    system("cls");
    enter_user_again:
    printf("\n\n\t\t\tEnter Username: ");
    gets(user);
    if(strcmp(user,"tbcbank10")==0) 
    {
        enter_pass_again:
        printf("\n\n\t\t\tEnter Password: ");  
        gets(pass);
        if(strcmp(pass,"expensive")==0) 
        {
            printf("\n\n\t\t\tLogin Successfull!!");
            printf("\n\n\t\t\tPress any key to continue...");
            getch();       
            mainmenu();
        }
        else
        {
            printf("\n\n\t\t\tWrong Password!!");
            printf("\n\n\t\t\tPress any key to try again!!");
            getch();
            goto enter_pass_again;
        }
    }
    else
    {
        printf("\n\n\t\t\tInvalid username"); 
        printf("\n\n\t\t\tPress any key to try again!!");
        getch(); 
        goto enter_user_again;
    }
}
void mainmenu()
{
    int choice;
    home: 
    system("cls");
    printf("\n\n\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t1.Account Opening\n\t\t\t\t2.Update Details of Account\n\t\t\t\t3.Transaction \n\t\t\t\t4.Check Details of Exisiting Account\n\t\t\t\t5.Remove an Existing Account\n\t\t\t\t6.View All Customer List\n\t\t\t\t7.Exit");
    printf("\n\t\t\t\tYou have entered: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            acc_open();
            goto home;
        case 2:
            update_acc();
            goto home;
        case 3:
            transaction();
            goto home;
        case 4:
            view_acc_info();
            goto home;
        case 5:
            delete_acc();
            goto home;
        case 6:
            view_all();
            goto home;
        case 7:
            close();
        default:
            printf("\n\t\t\t\tInvalid Selection!! Please choose a valid choice");
            printf("\n\t\t\t\tPress any key to continue..");
            getch();
            goto home;
    }

}
void acc_open()
{
    int choice;
    FILE *ptr=fopen("user_info.bin","ab+");
    if (ptr == NULL)
    {
        printf("\n\t\t\tError!! Please Try Later!!\n");
    }
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\t\t\t\tEnter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    account_no:
    printf("\n\n\t\t\t\tEnter the account number:");
    scanf("%s",&check.account_no);
    while(fread(&add, sizeof(add), 1, ptr) == 1)    
    {
        if (strcmp(check.account_no,add.account_no)==0)
            {
                printf("Account no. already in use!\nPress Any key to try again");
                getch();
                goto account_no;
            }
    }
    strcpy(add.account_no, check.account_no);
    printf("\n\t\t\t\t\xB2\xB2\xB2 Account Opening Form \xB2\xB2\xB2");
    printf("\n\t\t\t\tEnter Personal Details ");
    printf("\n\t\t\t\tEnter Account Holder Name: ");
    fflush(stdin);
    gets(add.name);
    printf("\n\t\t\t\tEnter Parent Name: ");
    fflush(stdin);
    gets(add.parent_name);
    printf("\n\t\t\t\tEnter Date of Birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\n\t\t\t\tEnter age: ");
    scanf("%d",&add.age);
    printf("\n\t\t\t\tEnter Address: ");
    fflush(stdin);
    gets(add.address);
    printf("\n\t\t\t\tEnter Mobile Number: "); 
    gets(add.mobile_no);
    printf("\n\t\t\t\tEnter CitizenShip Number: ");
    fflush(stdin);
    gets(add.citizenship);
    printf("\n\t\t\t\tDo you want to make an Deposit (Enter 1 to make a Deposit/0 to skip): ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n\t\t\t\tEnter the Amount to Deposit: ");
        scanf("%f",&add.avail_bal);
        add.no_of_deposits++;
    }
    else
    {
        add.no_of_deposits=0;
    }
    add.no_of_withdrawls=0;
    add.status=1;
    account_type_again:
    printf("\n\n\t\t\t\tType of account:\n\n\t\t\t\t\t1.Saving\n\n\t\t\t\t\t2.Current\n\n\t\t\t\t\tEnter your choice(1 for Savings, 2 for Current):");
    scanf("%d",&choice);
    if(choice==1)
    {
        strcpy(add.account_type,"Savings");
    }
    else if(choice==2)
    {
        strcpy(add.account_type,"Currents");
    }
    else
    {
        printf("Invalid Choice");
        goto account_type_again;
    }
    fwrite(&add, sizeof(add), 1 , ptr);
    printf("\n\t\t\t\tAccount created successfully!");
    printf("\n\t\t\t\tPress any key to continue... ");
    getch();

    fclose(ptr);
}
void update_acc()
{
    system("cls");
    int choice, reply=0; 
    FILE *ptr=fopen("user_info.bin","rb+");
    FILE *temp=fopen("temp.bin","wb+");
    if (ptr == NULL || temp == NULL)
    {
        printf("\n\t\t\t\tError Please Try Again Later!!");
    }
    printf("\t\t\t\t====== Update Account Information ======\n");
    printf("\n\t\t\tEnter Account Number : ");
    getchar();
    gets(upd.account_no);
    while(fread(&add,sizeof(add),1,ptr)==1)
    {
        if(strcmp(add.account_no, upd.account_no)==0)
        {
            reply++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Account Name\n\t\t\t2.Update Date of Birth.\n\t\t\t3.Update Address\n\t\t\t4.Update Contact No\n\t\t\t5.Update Account Status");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Account's Name to Update: ");
                getchar();
                gets(upd.name);
                strcpy(add.name, upd.name);
                fwrite(&add, sizeof(add),1,temp);
                printf("\n\t\t\t\tUpdate Successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Date of Birth to Update: ");
                getchar();
                scanf("%d/%d/%d",&upd.dob.day,&upd.dob.month,&upd.dob.year);
                upd.dob.day,upd.dob.month,upd.dob.year=add.dob.day,add.dob.month,add.dob.year;
                fwrite(&add, sizeof(add),1,temp);
                printf("\n\t\t\t\tUpdate Successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Address to Update: ");
                getchar();
                gets(upd.address);
                strcpy(add.address, upd.address);
                fwrite(&add, sizeof(add),1,temp);
                printf("\n\t\t\t\tUpdate Successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter Contact no. to Update: ");
                getchar();
                gets(upd.mobile_no);
                strcpy(add.mobile_no, upd.mobile_no);
                fwrite(&add, sizeof(add),1,temp);
                printf("\n\t\t\t\tUpdate Successfully!\n\n");
            }
            else if (choice == 5)
            {

                add.status==1;
                fwrite(&add, sizeof(add),1,temp);
                printf("\n\t\t\t\tUpdate Successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&add, sizeof(add),1,temp);
            }
        }
        else
        {
            fwrite(&add,sizeof(add),1,temp);
        }
    }
    fclose(ptr);
    fclose(temp);
    remove("user_info.bin");
    rename("temp.bin", "user_info.bin");

    if (reply==0)
    {
        printf("\n\t\t\tAccount Not Found!!");
    }
    printf("\n\t\t\t\tEnter Any key to continue.....");
    getch();
}
void transaction()
{
    FILE *ptr = fopen("user_info.bin","rb+");
    FILE *temp = fopen("temp.bin","wb+");
    int choice, reply = 0;
    if (ptr == NULL || temp == NULL)
    {
        printf("\n\t\t\tError!! \n");
    }
    transaction_menu:
    system("cls");
    printf("\t\t\t\t======Account Transaction======\n");
    printf("\n\t\t\tEnter Account Number: ");
    getchar();
    gets(transact.account_no);
    while(fread(&add, sizeof(add),1,ptr)==1)
    {
        if(strcmp(add.account_no, transact.account_no)==0)
        {
            reply++;
            printf("\n\n\t\t\tDo you want to\n\t\t\t1.Deposit\n\t\t\t2.Withdraw\n\n\t\t\tEnter your choice:");
            scanf("%d", &choice);
            printf("\n\t\t\tCurrent Balance:$ %.2f", add.avail_bal);
            if (choice==1)
            {
                makeDeposit();
                getch();
            }
            else if (choice==2)
            {
                makeWithdrawal();
                getch();
            }
            else
            {
                printf("Invalid Option!!");
                goto transaction_menu;
            }
        }
        else
        {
            fwrite(&add, sizeof(add),1,temp);
        }
    }
    if (reply==0)
    {
        printf("\n\t\t\tInvalid Account Number");
    }
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
    fclose(ptr);
    fclose(temp);
    remove("user_info.bin");
    rename("temp.bin","user_info.bin");
}
void makeDeposit()
{
    FILE *ptr = fopen("user_info.bin","rb+");
    FILE *temp = fopen("temp.bin","wb+");
    printf("\n\t\t\tEnter the amount you want to deposit:$ ");
    scanf("%f", &transact.avail_bal);
    add.avail_bal+=transact.avail_bal;
    add.no_of_deposits++;
    printf("\n\t\t\tCurrent Balance after Deposit: $%.2f", add.avail_bal);
    fwrite(&add, sizeof(add),1,temp);
    printf("\n\t\t\tDeposited Successfully!!");
    fclose(ptr);
    fclose(temp);
    remove("user_info.bin");
    rename("temp.bin","user_info.bin");
}
void makeWithdrawal()
{
    FILE *ptr = fopen("user_info.bin","rb+");
    FILE *temp = fopen("temp.bin","wb+");
    printf("\n\t\t\tEnter the amount you want to withdraw: $");
    scanf("%f", &transact.avail_bal);
    if (add.status=1)
    {
        if (add.avail_bal<transact.avail_bal)
        {
            printf("\n\t\t\tInsufficient Balanace!\n\nYour account has been blocked!! Please contact IT Support!!");
            add.status=0;
            fwrite(&add, sizeof(add),1,temp);
        }
        else
        {
            add.avail_bal -=transact.avail_bal;
            add.no_of_withdrawls++;
            printf("\n\t\t\tCurrent Balance after Withdraw:$%.2f",add.avail_bal);
            fwrite(&add, sizeof(add),1,temp);
            printf("Withdraw Successfull");
        }
    }
    else 
    {
        printf("Your account is blocked please visit IT support...");
    }
    fclose(ptr);
    fclose(temp);
    remove("user_info.bin");
    rename("temp.bin","user_info.bin");

}
void view_acc_info()
{
    FILE *ptr=fopen("user_info.bin","rb");
    int choice, reply=0;  
    printf("\t\t\t\t====== Search Account Information ======\n");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    system("cls");
    if(choice==1)
    {
        printf("\t\t\t\t====== Search Account Information ======\n");
        printf("\n\n\t\t\tEnter Account Number : ");
        getchar();
        gets(check.account_no);
        while(fread(&add, sizeof(add),1,ptr)==1)
        {
            if(strcmp(add.account_no, check.account_no)==0)
            {
                system("cls");
                reply=1;
                printf("\n\t\t\t\tAccount NO.:%s\n\t\t\t\tName:%s \n\t\t\t\tParent Name: %s \n\t\t\t\tDOB:%d/%d/%d \n\t\t\t\tAge:%d \n\t\t\t\tAddress:%s \n\t\t\t\tCitizenship No:%s \n\t\t\t\tPhone number:%.0lf \n\t\t\t\tType Of Account:%s \n\t\t\t\tAmount deposited:$ %.2f \n\t\t\t\tDate Of Account Opening:%d/%d/%d \n\t\t\t\tNumber of Deposits: %d \n\t\t\t\tNumber of Withdrawls: %d\n\t\t\t\tAccount Status: %d\n\t\t\t\t",add.account_no,add.name,add.parent_name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.mobile_no,add.account_type,add.avail_bal,add.deposit.month,add.deposit.day,add.deposit.year,add.no_of_deposits,add.no_of_withdrawls,add.status);
            }
            else
            {
                printf("Sorry!! We couldn't process your request");
            }
        }
        if (reply==0)
        {
            printf("\n\t\t\tAccount Not Found!!");
        }
    }
    else if (choice==2)
    {
        system("cls");
        printf("\t\t\t\t====== Search Account Information ======\n");
        printf("\n\n\t\t\tEnter Account Name : ");
        getchar();
        gets(check.name);
        while(fread(&add, sizeof(add),1,ptr)==1)
        {
            if(stricmp(add.name,check.name)==0)
            {
                system("cls");
                reply=1;
                printf("\n\t\t\t\tAccount NO.:%s\n\t\t\t\tName:%s \n\t\t\t\tParent Name: %s \n\t\t\t\tDOB:%d/%d/%d \n\t\t\t\tAge:%d \n\t\t\t\tAddress:%s \n\t\t\t\tCitizenship No:%s \n\t\t\t\tPhone number:%.0lf \n\t\t\t\tType Of Account:%s \n\t\t\t\tAmount deposited:$ %.2f \n\t\t\t\tDate Of Account Opening:%d/%d/%d \n\t\t\t\tNumber of Deposits: %d \n\t\t\t\tNumber of Withdrawls: %d\n\t\t\t\tAccount Status: %d\n\t\t\t\t",add.account_no,add.name,add.parent_name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.mobile_no,add.account_type,add.avail_bal,add.deposit.month,add.deposit.day,add.deposit.year,add.no_of_deposits,add.no_of_withdrawls,add.status);
            }
            else
            {
                printf("Sorry!! We couldn't process your request");
            }
        }
        if(reply==0)
        {
            printf("\n\t\t\t\tAccount Not Found!!");
        }
    }
    else
    {
        printf("Press any key to continue.....");
        getch();
    }
    fclose(ptr);
    printf("Press any key to continue...");
    getch();
}
void delete_acc()
{
    FILE *ptr = fopen("user_info.bin","rb+");
    FILE *temp = fopen("temp.bin","wb");
    int choice, reply=0;
    if (ptr == NULL ||temp == NULL )
    {
        printf("\n\t\t\tError!\n");
    }
    system("cls");
    printf("\t\t\t\t=====Delete Account=====");
    printf("\n\t\t\tEnter Account Number: ");
    getchar();
    gets(rem.account_no);
    while(fread(&add, sizeof(add),1,ptr)==1)
    {
        if(strcmp(add.account_no, rem.account_no)==0)
        {
            reply++;
            printf("\n\t\t\tAre you sure to delete?\n\t\t\t\t1.Yes\n\t\t\t\t2.No\n\t\t\t\tEnter Your Choice: ");
            scanf("%d",&choice);
            if (choice == 1)
            {
                printf("\n\t\t\t\tAccount is Deleted!!\n\n");
            }
            else if(choice==2)
            {
                fwrite(&add, sizeof(add),1,temp);   
            }
            else
            {
                printf("\n\t\t\t\tInvalid Option");
                fwrite(&add, sizeof(add),1,temp);
            }
        }
        else
        {
            fwrite(&add, sizeof(add),1,temp);
        }
    }
    fclose(ptr);
    fclose(temp);
    remove("user_info_bin");
    rename("temp.bin", "user_info_bin");
    if(reply==0)
    {
        printf("\n\t\t\tAccount is not Found");
    }
    printf("\n\t\t\t\tPress Any key to continue...");
    getch();
}
void view_all()
{
    FILE *ptr=fopen("user_info.bin","rb+");
    if (ptr == NULL)
    {
        printf("\n\t\t\tError!");
    }
    system("cls");
    while(fread(&add, sizeof(add),1,ptr)==1)
    {
        printf("\n\t\t\t\tAccount NO.:%s\n\t\t\t\tName:%s \n\t\t\t\tParent Name: %s \n\t\t\t\tDOB:%d/%d/%d \n\t\t\t\tAge:%d \n\t\t\t\tAddress:%s \n\t\t\t\tCitizenship No:%s \n\t\t\t\tPhone number:%.0lf \n\t\t\t\tType Of Account:%s \n\t\t\t\tAmount deposited:$ %.2f \n\t\t\t\tDate Of Account Opening:%d/%d/%d \n\t\t\t\tNumber of Deposits: %d \n\t\t\t\tNumber of Withdrawls: %d\n\t\t\t\tAccount Status: %d\n\t\t\t\t",add.account_no,add.name,add.parent_name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.mobile_no,add.account_type,add.avail_bal,add.deposit.month,add.deposit.day,add.deposit.year,add.no_of_deposits,add.no_of_withdrawls,add.status);
        printf("\t\t\t---------------------------------------------------\n"); 
    }
    fclose(ptr);
    printf("\n\t\t\t\tPress any key to continue..");
    getch();
}
void close(void)
{
    system("cls");
    printf("\n\t\t\t\tThank You for Visiting The British College Bank!!");
    printf("\n\t\t\t\tPress any key to exit!!");
    getch();
    exit(0);
}