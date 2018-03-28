#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <time.h>
#include "Header.h"

using namespace std;

#define MAX 50

struct group
{
	char *name;
	int oc[5];
	int priznak;
};

void generateName(char *name, int type)
{
	strcpy(name, "person #");

	int a = 1 + rand() % 30;
	char t[3];
	itoa(a, t, 10);
	strcat(name, t);
}

void sortPr(int * a, int r)
{
	int temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

struct Student
{
	string fio;
	int math, info, phys;
	bool metka;
	Student *next;
};

bool mark(int a)
{
	if (a>1 && a<6)
		return true;
	else
	{
		cout << "Error mark - vozmozhno tolko(2,3,4,5):" << endl;
		return false;
	}
}

struct worker {
	int id_factory;
	char* name;
	int age;
	char* specility;
	int salary;
};

void print_worker(struct worker worker) {
	printf("Id factory %d\n", worker.id_factory);
	printf("Name %s\n", worker.name);
	printf("Age %d\n", worker.age);
	printf("Specility %s\n", worker.specility);
	printf("Salary %d\n", worker.salary);
	printf("\n");
}

struct bagaje
{
	int * name;
	int * kol;
	int * ves;
};

void main()
{
	setlocale(LC_ALL, ("Rus"));
	srand(time(NULL));
	int nz;
	do
	{
		printf("Vvedite nomer zadaniya?");
		scanf("%d", &nz);
		if (nz == 1)
		{
			/*2.	������������ ������ ��������, ������ ������� �������� �������� ��������� ��� ����:
a.	�������, ��� �������� �������� (������); 
b.	������ ������ � �������������� ������� (������); 
c.	�������

��� ������� �������� �������� ���� �� ��������� �������� ��������: 5 � �������� (������ 9 � (���) 10), 4 � ��������
(��� ������, ������ 6, �� �� ��� 9 ��� 10, � ���� 6 � (���) 7 � (���) 8), 3 � �������� (��� ������, ������ 4, �� ���� 4 � (���) 5),
2 � ������������ (���� 1 � (���) 2 � (���) 3). �������������� ������ �������� �� �������� ����������� ��������.*/
			int a = 1 + rand() % 25;
			printf("���������� ��������� : %d\n", a);
			group *students = NULL;
			students = (group*)malloc(a * sizeof(group));
			if (students == NULL)
			{
				printf("��������� ���\n");
				system("exit");
				//exit(EXIT_FAILURE);
			}
			else
			{
				for (int i = 0;i < a;i++)
				{
					(students + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((students + i)->name, 0);
					for (int h = 0; h < 5; h++)
					{
						(students+i)->oc[h] = 2 + rand() % 10;
					}

					//(students + i)->priznak = (int*)calloc(2, sizeof(int));

					for (int h = 0; h < 5; h++)
					{
						if ((students + i)->oc[h] == 9 || (students + i)->oc[h] == 10)
							(students + i)->priznak = 5;
						else if ((students + i)->oc[h] >=6 )
							(students + i)->priznak = 4;
						else if ((students + i)->oc[h] >=4 )
							(students + i)->priznak = 3;
						else
							(students + i)->priznak = 2;
					}

					//sortPr((students + i)->priznak, a);

					printf("%d\n", (students+i)->priznak);
					
				}
				
				
					
				
			}



		}
		else if (nz == 2)
		{
			/*7.	�������� ���������, ������� ���������� ������������ ������ ����, ����� � ���.����� ����� ���� ����������� ���������� �������,
				��������� ��� �������������.����� ��������� ������ ���������� ����� ���������� ����, �� - ������ � ������ ���� �� ��������� ���� ������������.*/
			int day, month, year;
			cout << "������� ���� ..." << endl;
			cin >> day >> month >> year;
			int day1;
		}
		else if (nz == 3)
		{
			/*6.	������� ���������� �� ������ ��������� � ��������� ����� � ������ N �������.�� ������� �� ��������� ������� ��������� �������� : 
			�������, ������ �� ����������, ������ �� ����������� � ������ �� ������.������ ���������� �� ��������� � ���������� ���������� � ������� ����������.*/
			bool f = true;
			string fio;
			int N = 0;
			int math, info, phys;

			Student * firstStud;
			Student * currentStud;

			cout << "Vvedite students" << endl;

			while (1)
			{
				Student *newStud = new Student;
				cout << "Vvedite fio (exit - vihod)" << endl;
				cin >> fio;
				if (fio == "exit")
					break;
				N++;
				cout << "Vvedite ocenki" << endl;
				cin >> math >> info >> phys;


				newStud->fio = fio;
				newStud->info = info;
				newStud->math = math;
				newStud->phys = phys;
				newStud->metka = false;
				newStud->next = NULL;

				if (f)
				{
					firstStud = newStud;
					currentStud = newStud;
					f = false;
					continue;
				}

				currentStud->next = newStud;
				currentStud = newStud;
			}
			currentStud = firstStud;

			int kol = 0;

			while (currentStud != NULL)
			{
				if (currentStud->math == 5 && currentStud->phys == 5 && currentStud->info == 5)
				{
					currentStud->metka = true;
					kol++;
				}
				currentStud = currentStud->next;
			}

			cout << "Vsego students otlichikov:" << kol << endl << "Familii students:" << endl;

			currentStud = firstStud;
			while (currentStud != NULL)
			{
				if (currentStud->metka == true)
					cout << currentStud->fio << " � ";
				currentStud = currentStud->next;
			}

			cout << endl;


		}
		else if (nz == 4)
		{
			int count_slesar = 0;
			int count_tokar = 0;
			int i = 0;

			struct worker first_worker,
				second_worker,
				third_worker,
				forth_worker;


			first_worker.id_factory = 1;
			first_worker.name = "��������";
			first_worker.age = 36;
			first_worker.specility = "�������";
			first_worker.salary = 3000;

			second_worker.id_factory = 1;
			second_worker.name = "������";
			second_worker.age = 32;
			second_worker.specility = "������";
			second_worker.salary = 2500;

			third_worker.id_factory = 2;
			third_worker.name = "��������";
			third_worker.age = 40;
			third_worker.specility = "�������";
			third_worker.salary = 3000;

			forth_worker.id_factory = 1;
			forth_worker.name = "�������";
			forth_worker.age = 30;
			forth_worker.specility = "���������";
			forth_worker.salary = 5000;

			struct worker workers[4] = { first_worker,
				second_worker,
				third_worker,
				forth_worker
			};

			for (i = 0; i < 4; i++) {
				if (strcmp(workers[i].specility, "������") == 0) {
					count_tokar++;
				}

				if (strcmp(workers[i].specility, "�������") == 0) {
					count_slesar++;
				}


			}

			printf("Count ������� : %d\n", count_tokar);
			printf("Count �������� : %d\n", count_slesar);

		}
		else if (nz == 5)
		{
			/*5.	����� ��������� ��������������� ����������� ����� � ����� �����.������ ���������� �� N ���������� �
				���������� ���� �� ����� ���������� �����, � �������� ����� ������� ����� �� ����� � �� ����.*/
			int a = 1 + rand() % 25;
			printf("���������� ���������� : %d\n", a);
			bagaje *pas = NULL;
			pas = (bagaje*)malloc(a * sizeof(bagaje));
			if (pas == NULL)
			{
				printf("���������� ���\n");
				system("exit");
				//exit(EXIT_FAILURE);
			}
			else
			{
				int max = 0, max2 = 0;
				for (int i = 0;i < a;i++)
				{
					
					(pas + i)->name = (int*)malloc(12 * sizeof(int));
					*(pas + i)->name = 1 + rand() % 40;
					(pas + i)->kol = (int*)malloc(20 * sizeof(int));
					*(pas + i)->kol = 1 + rand() % 6;
					(pas + i)->ves = (int*)malloc(20 * sizeof(int));
					*(pas + i)->ves = 10 + rand() % 60;

					if (pas->kol[i] > max)
						max = i;
					if (pas->ves[i] > max2)
						max2 = i;
				}
				if (max == max2)
					printf("����� ������� ����� �� ����� � �� ���� %s\n", pas->name[max]);
				else
					printf("������ ��������� ���\n");
			}

		}
	} while (nz == 999);

}