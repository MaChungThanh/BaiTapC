#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct add_book{
    char name[25];
    char phone[12];

    struct add_book *next;
};


typedef struct add_book* address;


address init(){
    address root;
    root = NULL;
    return root;
}

address create_student_t(char name[], char phone[]) {
    address new;
    new = (address)malloc(sizeof(struct add_book));
    new->next = NULL;
    strcpy(new->name,name);
    strcpy(new->phone,phone);
    return new;
}

address addTail(address root, address addT){
    address p;
    char name[30],phone[10];
    //addT = create_student_t(name,phone);
    if(root == NULL){
        root = addT;
    } else{
        p = root;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = addT;
    }
    return root;
}


address getinfo(FILE *in){
    address add, root = init();
    char str[100];
    char name[30], phone[10];
    while(fgets(str,100,in) != NULL){
        int i=0;
        str[strlen(str) - 1] = '\0';
        char *s = strtok(str,";");
        while (s != NULL){
            if(i==0){
                strcpy(name,s);
                printf("%s ",name);
            } else if(i==1){
                strcpy(phone,s);
                printf("%s\n",phone);
            }       
            i++;
            s = strtok(NULL,";");
        } 
        add = create_student_t(name,phone);   
        root = addTail(root,add); 
    }
    return root;
}

address find(address root, char *name){ 
    address p = root;
    while (p != NULL && strcmp(p->name,name)!=0){
        p = p->next;
    }
    return p;
}

int main(){
    FILE *in;
    in = fopen("info.txt","r");
    address root = getinfo(in);

    char namef[30];
    printf("Nhap ten SV can tim: ");
    gets(namef);

    address found = find(root,namef);

    if(found != NULL){
        printf("%s\n%s",found->name,found->phone);
    } else{
        printf("Not found");
    }

    fclose(in);
}