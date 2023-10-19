
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char username[20];
    char password[20];
    int active;
    char str[10];
} User;

typedef union persons
{
    User user; 
}p;


User users[MAX];  
int counter = 0;      

void registration() {
    
    p obj;
    if (counter >= MAX) {
        printf("Maximum user limit reached.\n");
        return;
    }


    printf(".....................   Registration   ...............................\n");
    
    printf("** username **: ");
    scanf("%s", obj.user.username);
    printf("** password **: ");
    scanf("%s", obj.user.password);

    // Check if user is active
    char choice;
    printf("Are You active or not? (t/1 ,f/0 ): ");
    scanf(" %c", &choice);
    if (choice == 'T' || choice == 't')
    {
        obj.user.active =1;
    }else if (choice == 'F' || choice == 'f'){
        obj.user.active =0;
    }else if (choice == '1' ){
        obj.user.str[0] ='1';
    }else if (choice == '0' ){
        obj.user.str[0] ='0';
    }
   

    users[counter++] = obj.user;

    printf("..................................................................\n");

}

int login() {
    char username[20];
    char password[20];

    printf("...........................  login   ..........................\n");

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf(".................................................................\n");


    
    for (int i = 0; i < counter; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (users[i].active==1 || users[i].str[0]=='1') {
                printf("Login successful. Welcome %s\n", users[i].username);
                printf(".................................................................\n");

                return 1;
            } else {
                printf("User is not active.\n");
                printf(".................................................................\n");

                return 0;
            }
        }
    }

    printf("Invalid username or password.\n");
    printf(".................................................................\n");

    return 0;
}

int main() {
    int choice;
    

    do {
        
        printf("-press 1 to Register\n-press 2 to Login\n-press 3 to exit\n");
        
        printf("====>>  ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registration();
                break;

            case 2:
               
                login();
                break;
            case 3:
                
                break;    

    
            default:
                printf("wrong choice.\n");
        }
    } while (choice != 3);

    return 0;
}