#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct students{
    char name[25];
    char id[10];

    struct students *next;
};


typedef struct students* student_t;


student_t init(){
    student_t root;
    root = NULL;
    return root;
}

student_t create_student_t(char name[], char id[]) {
    student_t new;
    new = (student_t)malloc(sizeof(struct students));
    new->next = NULL;
    strcpy(new->name,name);
    strcpy(new->id,id);
    return new;
}


student_t addHead(student_t root, student_t addH){
    char name[30],id[10];
    addH = create_student_t(name,id);
    if(root = NULL){
        root = addH;
    } else{
        addH->next = root;
        root = addH;
    }
    return root;
}


student_t addTail(student_t root, student_t addT){
    student_t p;
    char name[30],id[10];
    //addT = create_student_t(name,id);
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

student_t delHead(student_t root){
    if(root = NULL){
        printf("Error");
    } else{
        root = root->next;
    }
    return root;
}

student_t delTail(student_t root){
    if(root == NULL || root->next == NULL){
        return delHead(root);
    } else{
        student_t p = root;
        while(p->next->next != NULL){
            p = p->next;
        }
        p->next = p->next->next;
        return root;
    }
}

student_t delAt(student_t root,char *id){
    printf("Nhap id can xoa");
    scanf("%s",id);

    student_t p = root,prev;

    while (p!=NULL && strcmp(p->id,id)!=0){
        prev = p;
        p = p->next;
    }
    if(p!=NULL){
        prev->next = p->next;
        free(p);
    }
    return root;  
}


student_t getinfo(FILE *in){
    student_t add, root = init();
    char str[100];
    char name[30], id[10];
    while(fgets(str,100,in) != NULL){
        int i=0;
        str[strlen(str) - 1] = '\0';
        char *s = strtok(str,";");
        while (s != NULL){
            if(i==0){
                strcpy(name,s);
                printf("%s ",name);
            } else if(i==1){
                strcpy(id,s);
                printf("%s\n",id);
            }       
        i++;
        s = strtok(NULL,";");
        } 
        add = create_student_t(name,id);   
        root = addTail(root,add); 
    }
    return root;
}

student_t find(student_t root, char *id){ 
    student_t p = root;
    while (p != NULL && strcmp(p->id,id)!=0){
        p = p->next;
    }
    return p;
}

int main(){
    FILE *in;
    in = fopen("info.txt","r");
    student_t root = getinfo(in);
    char idf[10];
    printf("Nhap id SV can tim: ");
    scanf("%s",idf);
    student_t found = find(root,idf);

    if(found != NULL){
        printf("%s %s",found->name,found->id);
    } else{
        printf("Not found");
    }

    fclose(in);
}