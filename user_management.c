#include<stdio.h>
#include<string.h>
#define MAX_USERS 10
#define Credential_length 30

typedef struct user_management
{
    char username[Credential_length];
    char password[Credential_length];
}User;
User users[MAX_USERS];
int user_count =0;

void register_user();
int login_user();
void fix_fgets_input(char*);
void input_password(char*);

int main()
{
    int option;
    int user_index;
    while(1){
    printf("\nWelcome to user management");
    printf("\n1.Register");
    printf("\n2.Login");
    printf("\n3.Exit");
    printf("Select an option");
    scanf("%d",&option);
    getchar(); //consume extra enter
    switch (option)
    {
    case 1:
    register_user();
        break;
    case 2:
    user_index= login_user();
    if(user_index >= 0)
    {
        printf("\nLogin Successful. Welcome back %s", users[user_index].username);
    }else {
        printf("\nLogin failed. Incorrect username or password\n");
    }
        break;
    case 3:
    printf("\nexiting program\n");
    return 0;
        break;
    default:
    printf("\nInvalid option. Please try again.\n");
        break;
    }





    }


    return 0;
}
void register_user()
{
    if( user_count == MAX_USERS)
    {
        printf("\n Maximum %d users are supported. No more registrations allowed.", MAX_USERS);
        return;
    }
    int new_index= user_count;

    printf("\nRegister a new user");
    printf("\nEnter Username:");
    fgets(users[new_index].username,Credential_length,stdin);
    fix_fgets_input(users[new_index].username);
    input_password(users[new_index].password);
    user_count++;
    printf("\nregistration successful\n");
}
int login_user()
{
    char username[Credential_length];
    char password[Credential_length];
    printf("Enter Username:");
    fgets(username,Credential_length,stdin);
    fix_fgets_input(username);
    input_password(password);

    for(int i=0;i<user_count;i++){
        if(strcmp(username,users[i].username)==0 && 
           strcmp(password,users[i].password)){
            return i;
           }
         }
    return -1;
}

void input_password(char* password){
    printf("\nEnter password\n");
    fgets(password,Credential_length,stdin);
    fix_fgets_input(password);
}

void fix_fgets_input(char* string ){
    int index= strcspn(string,"\n");
    string[index]='\0';

}