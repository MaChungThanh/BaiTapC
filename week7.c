#include<stdio.h>

int search(int a[], int low, int high, int key){
    if(high >= low){
        int mid = (low + high)/2;
        if(a[mid] == key){
            return mid;
        }
        if(a[mid] > key){
            return search(a, low, mid-1, key);
        }
        return search(a, mid+1, high, key);
    }
    return -1;
}

/* hàm search cho bài tập tìm kiếm tên*/
/*
int search(char a[], int low, int high, char key[]){
    if(high >= low){
        int mid = (low + high)/2;
        if(strcmp(a,key) == 0){
            return mid;
        }
        if(strcmp(a,key) > 0){
            return search(a, low, mid-1, key);
        }
        if(strcmp(a,key) < 0){
            return search(a, mid+1, high, key);
        }
    }
    return -1;
}
*/

int main(){
    int a[5];
    int key,i;

    for(i=0; i<5; i++){
        scanf("%d",&a[i]);
    }

    printf("Nhap so can tim: ");
    scanf("%d",&key);
    
    int found = search(a,0,4,key);
    (found == -1) ? 
        printf("Khong tim thay")
        : printf("So can tim o vi tri %d", found);
    return 0;
}
© 2022 GitHub, Inc.
Terms
