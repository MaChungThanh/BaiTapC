#include<stdio.h>
#include<string.h>

typedef struct Address{
    char name[30];
    char phone[12];
}address;

address info[10];

void getinfo(FILE *in){
    char str[100];
    char name[30], id[10];
    int j = 0;
    while(fgets(str,100,in) != NULL){
        int i=0;
        str[strlen(str) - 1] = '\0';
        char *s = strtok(str,";");
        while (s != NULL){  
            if(i==0){
                strcpy(info[j].name,s);
            } else if(i==1){
                strcpy(info[j].phone,s);
                j++;
            }       
        i++;
        s = strtok(NULL,";");
        }
    }
}

void quicksort(address a[], int l, int r){
    int i = l, j = r;
    address m = a[(l+r)/2];
    address temp;
    while(i <= j) {
        while(strcmp(a[i].name, m.name) < 0) ++i;
        while(strcmp(a[j].name, m.name) > 0) --j;
        if(i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++; j--;
        }
    }
    if(l < j) quicksort(a, l, j);
    if(i < r) quicksort(a, i, r);
}

int main(){
    FILE *in;
    in = fopen("info.txt","r");
    getinfo(in);
    quicksort(info,0,4);
    for(int i = 0; i < 5; i++){
        printf("%-30s%-12s\n", info[i].name, info[i].phone);
    }
    fclose(in);
}