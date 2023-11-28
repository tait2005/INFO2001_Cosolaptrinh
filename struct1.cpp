#include <stdio.h>
#include <string.h>

struct Student{
	char id[30];
	char name[30];
	int age;
};
void displayStudent(struct Student student){
	printf("Ho va ten sinh vien :%s",student.name);
	printf("Ma sinh vien :%s",student.id);
	printf("Tuoi sinh vien :%d\n",student.age);
}
int main(){
	struct Student student;
	printf("Ma sinh vien :");
	fgets(student.id,30,stdin);
	printf("Ho va ten :");
	fgets(student.name,30,stdin);
	printf("Tuoi :");
	scanf("%d",&student.age);
	getchar();
	printf("\tTHONG TIN SINH VIEN \n");
	displayStudent(student);
	char choice;
	printf("Ban muon cap nhat thong tin?(y/n)");
	scanf("%c",&choice);
	getchar();
	if(choice=='y'){
		printf("Sua doi thong tin sinh vien:\n");
		printf("Ho va ten sinh vien:");
		fgets(student.name,30,stdin);
		printf("Ma sinh vien:");
		fgets(student.id,30,stdin);
		printf("Tuoi:");
		scanf("%d",&student.age);
		displayStudent(student);
	}
	return 0;
}
