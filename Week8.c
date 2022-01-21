#include<math.h>
#include<stdio.h>
int b7_14(){
/* YCBT: In ra mot tan giac co so dong la cac so nguyen,moi dong tang so gia tri len 1 don vi
Input: Nhap so dong tu ban phim
Output: In ra man hinh tam giac co so dong tang dan
*/	
	int n,i,k;
	while( n <= 0){
		printf("Nhap so dong:");
		scanf("%d",&n);
	}
	i=1;
	while ( i<=n){
		k=1;
		while( k <= i){
				printf("%2d",k);
				k++;
		}
		printf("\n");
		i++;
	}
	return 0;
/* test
1. so dong 1: 1
2. so dong 3: 
 1
 1 2
 1 2 3
 3. so dong 5:
 1
 1 2
 1 2 3
 1 2 3 4
 1 2 3 4 5
*/
}
int b8_1(void){
/* YCBT:Viet chuong trinh in ra noi dung nguoi dung nhap tu ban phim, thay the chuoi dau cach bang 1 dau cach duy nhat
Input: Nhap vao mot chuoi ki tu tu ban phim
Ouput: In ra man hinh chuoi ki tu thay the chuoi dau cach bang dau cach duy nhat
*/
	int c;
	int inspace;
	inspace = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '  ')
		{
			if(inspace == 0)
			{
				inspace = 1;
				putchar(c);
			}
		}
	}
}
int b8_2(){
	/* YCBT:Viet chuong trinh thay the các kí tu ‘\’, ‘\t’, ‘\b’ boi “\\”, “\\t”, “\\b” trong chuoi nhap vao và in ra man hinh.
	Input: Nhap vao tu ban phim mot chuoi cac ki tu bat ki
	Output: in ra man hinh cac ki tu \,t,b bi thay the boi \\,\\t,\\b
	*/
	int c, d;
	while ( (c=getchar()) != EOF) 
	{
		d = 0;
		if (c == '\\') 
		{
			putchar('\\');
			putchar('\\');
			d = 1;
		}
	}
	if (c == '\t') {
		putchar('\\');
		putchar('t');
		d = 1;
	}
	if (c == '\b') {
		putchar('\\');
		putchar('b');
		d = 1;
	}
	if (d == 0)
	putchar(c);        
	return 0;
}
int b8_3(){
/* YCBT: Viet chuong trinh tinh so sinh vien qua, so sinh vien truot
Input:Nhap danh gia tu ban phim
Output: In so sinh vien qua, truot ra man hinh
*/
int t,d,sosv,kq;
sosv=1;
t=0;d=0;
while ( sosv <=10)
{
	printf("Nhap ket qua sinh vien thu %d:", sosv);
	scanf("%3d",&kq);
	if ( kq == 1) d=d+1;
		else if ( kq == 0) t=t+1;
	sosv=sosv+1;
}
printf("So hoc sinh do la:%d\n",d);
printf("So hoc sinh truot la: %d",t);
return 0;
/* test:
Nhap ket qua sinh vien thu 1:1
Nhap ket qua sinh vien thu 2:0
Nhap ket qua sinh vien thu 3:1
Nhap ket qua sinh vien thu 4:1
Nhap ket qua sinh vien thu 5:0
Nhap ket qua sinh vien thu 6:1
Nhap ket qua sinh vien thu 7:1
Nhap ket qua sinh vien thu 8:0
Nhap ket qua sinh vien thu 9:1
Nhap ket qua sinh vien thu 10:1
So hoc sinh do la:7
So hoc sinh truot la: 3
*/

}
int b8_4(){
/* YCBT: In ra cac so nguyen nho hon 1 so cho truoc
Input: Nhap vao 1 so tu ban phim
Ouput: In ra man hinh cac so nguyen nho hon so do
*/
int i,n;
i=0;
printf("Nhap n:");scanf("%d",&n);
while( i<n)
{
	printf(" %d",i);
	i=i+1;
}
return 0;
/* test:
n=1: 0 
n=5: 0 1 2 3 4
n=2: 0 1
*/
}
int b8_6(){
	/* YCBT: Tinh diem trung binh cac mon nhap vao tu ban phim
	Input: Cac mon hoc va diem 
	Ouput: Diem trung binh cua mon hoc do
	*/
	int mon,i;
	float tong,diem;
	printf("Nhap vao so mon hoc cua sinh vien:");scanf("%d",&mon);
	i=1;
	while ( i<=mon){
		printf("Nhap diem cua mon hoc thu %d:",i);scanf("%f",&diem);
		i=i+1;
		tong=tong+diem;
	}
	printf("Diem trung binh la: %f", tong/mon);
	return 0;
	/* test:
1. Nhap vao so mon hoc cua sinh vien:3
Nhap diem cua mon hoc thu 1:10
Nhap diem cua mon hoc thu 2:9
Nhap diem cua mon hoc thu 3:8
Diem trung binh la: 9.000000
2.Nhap vao so mon hoc cua sinh vien:4
Nhap diem cua mon hoc thu 1:8
Nhap diem cua mon hoc thu 2:6
Nhap diem cua mon hoc thu 3:5
Nhap diem cua mon hoc thu 4:10
Diem trung binh la: 7.250000
*/
}
int b8_7(){
	/* YCBT: Tinh giai thua cua 1 so tu nhien bat ki
	Input: Nhap vao so n tu ban phim
	Output: Hien thi ra man hinh n!
	*/
	int i,n,gt;
	printf("Nhap n:");scanf("%d",&n);
	gt=1;
	i=1;
	while( i<=n){
		gt=gt*i;
		i++;
	}
	printf("n!= %d",gt);
	return 0;
	/* test:
	1.n=1. n!=1
	2.n=4. n!=24
	3.n=10. n!=3628800
	*/
}
int b8_8(){
	/* YCBT: In ra n so tu nhien nho hon n
	Input: Nhap n tu ban phim
	Output: In ra man hinh n so tu nhien nho hon 
	*/
	int i,n;
	printf("Nhap n:");scanf("%d",&n);
	i=1;
	do {
		printf("%3d",i);
		i++;
	}
	while ( i <= n);
	return 0;
/* test:
1. n=1. 1
2. n=10. 1 2 3 4 5 6 7 8 9 10
3. n=3. 1 2 3
*/
}
int b8_31(){
/* YCBT: Tim cac so hoan hao nho hon n*/
	unsigned int n,m,i,tong;
	printf("Nhap n:");scanf("%d",&n);
	m=2;
	while ( m <= n){
		i=1;
		tong =0;
		while ( i < m){
			if ( m %i == 0)
				tong=tong+i;
				i=i+1;
		}
		if ( tong == m)
			printf(" %d la 1 so hoan hao nho hon %d\n",m,n);
	m=m+1;
		
	}
	return 0;
/* test:
1. n=10: 6 la 1 so hoan hao nho hon 10
2. n=100: 6 la 1 so hoan hao nho hon 100
		28 la 1 so hoan hao nho hon 100
3. n=1000: 6 la 1 so hoan hao nho hon 1000
		28 la 1 so hoan hao nho hon 1000
		496 la 1 so hoan hao nho hon 1000
*/
}

int main(){
	b7_14();
	b8_1();
	b8_2();
	b8_3();
	b8_4();
	b8_5();
	b8_6();
	b8_7();
	b8_8();
	b8_31();
}