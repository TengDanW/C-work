//学生管理系统
#include<stdio.h>
#include<stdlib.h> 
#include<Windows.h>
//定义，声明变量
int nCount = 0;
typedef struct STUDENT {
	int number;
	char name[12];
	double cld;//c 语言 设计
	double eng;
	double math;
	double avg;
}stu;
typedef struct Node {
	stu data;
	struct Node* next;
}node;
node* head = NULL;
//
//函数声明区
int Start();
int Menu();
int DataAdd();
double Avg(int c, int e, int m);
void Show();
void ClassTable();
node* NewSpace(const int num);
void NumberSequence();
void AvgScoreSequence();
int Delete();
void NodeDelete(int n);
int Change();
void NumberChange();
void NameChange();
void ScoreChange(char c);
int Search();
int BorC();
void Quit();
//
//函数入口
int main() {
	system("color E0");
	if (Start()) {
		while (Menu());
	}
	Quit();
	return 0;
}
//欢迎页面
int Start() {
	char username[20];
	char password[10];
	int key = 0, time = 3;
	char welcome[] = "Welcome To ZhuJiang College of South China Agricultural University";
	while (time-- && !key) {
		printf("\t\t\t  ");
		for (int i = 0; welcome[i] != '\0'; i++) {
			Sleep(10);
			printf("%c", welcome[i]);
		}
		Sleep(5);
		printf("\n\n\t\t\t\t\t\t%d times errors will exit\n\n", time + 1);
		printf("\t\t\t\t Username :");
		scanf("%s", username);
		printf("\n\n\t\t\t\t Password :");
		scanf("%s", password);
		if (strcmp(username, "TengDanW") == 0 && strcmp(password, "123456") == 0)key = 1;
		system("cls");
	}
	return key;
}
//选择菜单
int Menu() {
	char c;
	do {
		system("cls");
		system("color E0");
		printf("\n\n\n\n\t\t\t\t      Student Management System---Menu\n\n\n");
		printf("\t\t\t\t1.ClassTable                      2.Add Data\n\n\n");
		printf("\t\t\t\t3.Show Data                       4.Score ranking\n\n\n"); 
		printf("\t\t\t\t5.Alter Data                      6.Find Data\n\n\n");
		printf("\t\t\t\t7.Delete Data                     0.Exit Window\n\n\n");
		c = getche();
		switch (c) {
		case '1':
			system("cls");
			ClassTable();
			break;
		case '2':
			do {
				system("cls");
			} while (DataAdd());
			break;
		case '3':
			system("cls");
			NumberSequence();
			Show();
			printf("\n\t\t\t\tAny key go back or Esc exit...");
			if (getche() == 27)Quit();
			break;
		case '4':
			system("cls");
			AvgScoreSequence();
			Show();
			printf("\n\t\t\t\tAny key go back or Esc exit...");
			if (getche() == 27)Quit();
			break;
		case '5':
			while (Change());
			break;
		case '6':
			while (Search());
			break;
		case '7':
			do {
				system("cls");
			} while (Delete());
			break;
		case '0':
			Quit();
			break;
		}
	} while (c < '0' || c>'7');

	return 1;
}
void ClassTable() {
	char c;
	printf("\t\t\t\t\t Student Management System---ClassTable\n\n\n");
	printf("\t\t         MON      TUE      WED      THU      FRI\n\n");
	printf("\t\t1-2	 NT       MATH     ENG    HISTORY    ENG\n\n");
	printf("\t\t3-4      CLD                                 CLD\n\n");
	printf("\t\t5-6      CND      P.E               MATH     CLD\n\n");
	printf("\t\t7-8                                             \n\n");
	printf("\t\t9-10                                CND         \n\n");
	printf("\t\tAny key go back or Esc exit...");
	if (getche() == 27)Quit();
}
//平均分
double Avg(int c, int e, int m) {
	return (c + e + m) / 3.0;
}
//增加数据
int DataAdd() {
	node* p;
	p = NewSpace(nCount);
	nCount++;
	printf("\n\t\t\tPlease input students' number\n\t\t\t");
	scanf("%d", &p->data.number);
	printf("\n\t\t\tPlease input students' name\n\t\t\t");
	scanf("%19s", p->data.name);
	printf("\n\t\t\tPlease input students' score: Cld Eng Math\n\t\t\t");
	scanf("%lf %lf %lf", &p->data.cld, &p->data.eng, &p->data.math);
	p->data.avg = Avg(p->data.cld, p->data.eng, p->data.math);
	return BorC();
}
//增加链表
node* NewSpace(const int num) {
	node* p, * l;
	if (!num) {
		if (head = p = (node*)malloc(sizeof(node))) {
			head->next = NULL;
		}
		else {
			printf("Failed to allocate memory before processing. Exiting...");
			exit(1);
		}
	}
	if (p = (node*)malloc(sizeof(node))) {
		p->next = head->next;
		head->next = p;
	}
	else {
		printf("Failed to allocate memory before processing. Exiting...");
		exit(1);
	}
	return p;
}
//学号排序
void NumberSequence() {
	stu t;
	if (head) {
		for (node* i = head->next; i; i = i->next) {
			for (node* j=head->next;j;j=j->next) {
				if (i->data.number<j->data.number) {
					t = i->data;
					i->data = j->data;
					j->data = t;
				}
			}
		}
	}
}
void AvgScoreSequence() {
	stu t;
	if (head) {
		for (node* i = head->next; i; i = i->next) {
			for (node* j = head->next; j; j = j->next) {
				if (i->data.avg > j->data.avg) {
					t = i->data;
					i->data = j->data;
					j->data = t;
				}
			}
		}
	}
}
//展示信息
void Show() {
	printf("\n\tNumber\t\tName\t\tCld Score\t\tEng Score\tMath Score\tAvg Score:\n");
	if (head) {
		for (node* p = head->next; p; p = p->next) {
			printf("\n\t%d\t\t%s\t\t %6.2f\t\t\t  %6.2f\t  %6.2f\t%6.2f\n", p->data.number, p->data.name, p->data.cld, p->data.eng, p->data.math, p->data.avg);
		}
	}

}
//删除数据
int Delete() {
	int number;
	Show();
	printf("\n\n\t\t\t\tPlease input the student's number to delete.\n");
	scanf("%d", &number);
	NodeDelete(number);
	return BorC();
}
//目标节点的寻找和删除
void NodeDelete(int n) {
	int flag=1;
	if (head) {
		for (node* search = head->next, *last = head; search; search = search->next, last = last->next) {
			if (search->data.number == n) {
				last->next = search->next;
				search->next = NULL;
				free(search);
				flag = 0;
				break;
			}
		}
	}
	if (flag)printf("\n\t\t\t\tThe target is not found...");
}
//数据更改
int Change() {
	char c;
	do {
		system("cls");
		Show();
		printf("\n\n\t\t\t\t\tChoose an option to change...");
		printf("\n\n\t\t\t1.Number  2.Name  3.CLD Score  4.Eng Score  5.Math Score\n");
		switch (c = getche()) {
		case '1':
			NumberChange();
			break;
		case '2':
			NameChange(c);
			break;
		case '3':
		case '4':
		case '5':
			ScoreChange(c);
			break;
		}
	} while (c < '1' || c>'5');
	return BorC();
}
//改变学号
void NumberChange() {
	int originNumber;
	int flag = 1;
	printf("\n\n\t\t\tPlease input the number you want to change\n\t\t\t");
	scanf("%d", &originNumber);
	if (head) {
		for (node* search = head->next; search; search = search->next) {
			if (search->data.number == originNumber) {
				printf("\n\n\t\t\tPlease input the number you want to conserve\n\t\t\t");
				scanf("%d", &search->data.number);
				flag = 0;
				break;
			}
		}
	}
	if (flag)printf("\n\t\t\t\tThe target is not found...");
}
//改变名字
void NameChange() {
	char originName[12];
	int flag = 1;
	printf("\n\n\t\t\tPlease input the name you want to change\n\t\t\t");
	scanf("%s", &originName);
	if (head) {
		for (node* search = head->next; search; search = search->next) {
			if (strcmp(search->data.name, originName) == 0) {
				printf("\n\n\t\t\tPlease input the name you want to conserve\n\t\t\t");
				scanf("%s", &search->data.name);
				flag = 0;
				break;
			}
		}
	}
	if (flag)printf("\n\t\t\t\tThe target is not found...");
}
//改变分数
void ScoreChange(char c) {
	char content[3][12] = { "CLD Score","Eng Score","Math Score" };
	int number;
	int flag = 1;
	printf("\n\n\t\t\tPlease input the number you want to change\n\t\t\t");
	scanf("%d", &number);
	if (head) {
		for (node* search = head->next; search; search = search->next) {
			if (search->data.number == number) {
				switch (c) {
				case '3':
					printf("\n\n\t\t\tPlease input the %s you want to conserve\n\t\t\t", content[c - '3']);
					scanf("%lf", &search->data.cld);
					search->data.avg = Avg(search->data.cld, search->data.eng, search->data.math);
					flag = 0;
					break;
				case '4':
					printf("\n\n\t\t\tPlease input the %s you want to conserve\n\t\t\t", content[c - '3']);
					scanf("%lf", &search->data.eng);
					search->data.avg = Avg(search->data.cld, search->data.eng, search->data.math);
					flag = 0;
					break;
				case '5':
					printf("\n\n\t\t\tPlease input the %s you want to conserve\n\t\t\t", content[c - '3']);
					scanf("%lf", &search->data.math);
					search->data.avg = Avg(search->data.cld, search->data.eng, search->data.math);
					flag = 0;
					break;
				}
			}
		}
	}
	if (flag)printf("\n\t\t\t\tThe target is not found...");
}
//通过名字或学号寻找学生
int Search() {
	char c;
	char findName[12];
	int findNumber;
	int flag = 1;
	node* search;
	do {
		system("cls");
		printf("\t\t\tPlease select 1.NumberSearch or 2.NameSearch...\n\n\t\t\t");
		switch (c = getche()) {
		case '1':
			printf("\t\t\tPlease input the number you want to find\n\n\t\t\t");
			scanf("%d", &findNumber);
			if (head) {
				for (node* search = head->next; search; search = search->next) {
					if (search->data.number == findNumber) {
						printf("\n\t%d\t%12s\t\t  ", search->data.number, search->data.name);
						printf("%.2f\t\t  %.2f\t\t  %.2f\t\t  ", search->data.cld, search->data.eng, search->data.math);
						printf("%.2f\t\n", search->data.avg);
						flag = 0;
					}
				}
			}
			break;
		case '2':
			printf("\t\t\tPlease input the name you want to find\n\n\t\t\t");
			scanf("%s", &findName);
			if (head) {
				for (node* search = head->next; search; search = search->next) {
					if (strcmp(search->data.name, findName) == 0) {
						printf("\n\t%d\t%12s\t\t  ", search->data.number, search->data.name);
						printf("%.2f\t\t  %.2f\t\t  %.2f\t\t  %.2f\t\n", search->data.cld, search->data.eng, search->data.math, search->data.avg);
						flag = 0;
					}
				}
			}
			break;
		}
	} while (c < '1' || c>'2');
	if (flag)printf("\n\t\t\t\tThe target is not found...");
	return BorC();
}
//退出或继续
int BorC() {
	int flag = 0;
	printf("\n\n\n\n\t\t\t\tBack or Continue\n\n\t\t\t\tAny key / ';'");
	if (getche() == ';') {
		flag = 1;
	}
	return flag;
}
//退出函数
void Quit() {
	char end[] = "The program is over\n";
	system("cls");
	for (int i = 0; end[i] != '\0'; i++) {
		Sleep(25);
		printf("%c", end[i]);
	}
	Sleep(25);
	exit(0);
}