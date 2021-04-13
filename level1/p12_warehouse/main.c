#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void show(void);
void append(void);
void pop(void);
void initialize(void);
void save(void);

char type[1000];
int quantity[1000];
int i;//总货物数量 
FILE* fp;

int main(){
	initialize();
	char a;
	while(1){
		printf("1:看列表\n2:入库\n3:出库\n4:保存\n");//菜单 
		a = getche();
		system("cls");
		switch(a){
			case '1':show();break;
			case '2':append();break;
			case '3':i--;break;
			case '4':save();return 0;
		}
	}
} 

void initialize(void){
	i=0;
	fp=fopen("warehouse.txt","r");
	while(feof(fp)==0){
		fscanf(fp,"%c ",&type[i]);
		fscanf(fp,"%d ",&quantity[i]);
		i++;
	}
	fclose(fp);
}
void show(void){

	for(int count=0;count<i;count++){
		printf("Cargo %d\n",count+1);
		printf("Type:%c\n",type[count]);
		printf("Quantity:%d\n",quantity[count])	;
	}

}

void append(void){
	printf("Type:");
	scanf("%s",&type[i]);
	printf("Quantity:");
	scanf("%d",&quantity[i]);
	i++;
}

void save(void){
	fp=fopen("warehouse.txt","w");
	for(int count=0;count<i;count++){
		fprintf(fp,"%c ",type[count]);
		fprintf(fp,"%d\n",quantity[count]);
	}
	fclose(fp);
}


