#include <stdio.h>
#include <math.h> // pow, sqrt
#include <Windows.h> // Sleep
#include <stdlib.h>
#include <time.h>

// ����ü�� �ϳ��� �ڷ����̴�.
typedef struct point
{
	int xpos;
	int ypos;
}Point;

struct Human
{
	char name[256];
	char gender[256];
	int age;
	float height;
};

struct Human h;

typedef struct _Monster
{
	char name[256];
	int hp;
	int atk;
	int exp;
}Monster;

typedef struct // �͸� ����ü
{
	char name[256];
	int hp;;
	int atk;
	int exp;
	int gold;
}Player;

void rpg();

int main()
{
	//Point p; // -> c���� typedef, Point; �ʿ�
	//p.xpos = 20; // . -> ����ü ����
	//p.ypos = 30;

	//Player p2 = { "���ΰ�",500,100,100,0 }; // ����� ���ÿ� �ʱ�ȭ

	//{
	//	Point pos1, pos2;
	//	double distance;

	//	printf("Point pos1 : ");
	//	scanf_s("%d %d", &pos1.xpos, &pos1.ypos);

	//	printf("Point pos2 : ");
	//	scanf_s("%d %d", &pos2.xpos, &pos2.ypos);

	//	distance = sqrt((double)pow((pos1.xpos - pos2.xpos), 2) + pow((pos1.ypos - pos2.ypos), 2));
	//
	//	printf("�� ���� �Ÿ��� %g �Դϴ�\n\n", distance);
	//}

	rpg();

	return 0;
}

void rpg()
{
	Player p;

	Monster m[2] = {
		{"������",100,100,50},
		{"����", 60,150,70}
	}; // ����ü �迭

	printf("���� ����! ����� �̸���? : ");
	scanf_s("%s", &p.name, sizeof(p.name));

	printf("hp : ");
	scanf_s("%d", &p.hp);

	printf("atk : ");
	scanf_s("%d", &p.atk);

	p.exp = 0;
	p.gold = 0;

	printf("************ ���� ����! ************\n");

	srand((unsigned int)time(NULL));

	while (1)
	{
		if (p.hp <= 0)
		{
			printf("%s ���, ��������\n", p.name);
			exit(1);
		}
		printf("\n ���� �������ϴ�\n");
		Sleep(1500); // 1.5��

		int event_key = rand() % 5;

		switch (event_key)
		{
		case 0:
		{
			printf("�������� �߰�!\n");
			Sleep(1500);
			p.gold += 100;

			printf("���� ���� ��� : %d", p.gold);
			Sleep(1000);

			printf("�������� �̵�\n");
			Sleep(1000);
			break;
		}
		case 1:
		{
			printf("������ �������ϴ�\n");
			Sleep(1500);
			p.hp -= 50;

			printf("���� ü�� : %d", p.hp);
			Sleep(1000);

			printf("�������� �̵�\n");
			Sleep(1000);
			break;
		}
		case 2:
		{
			int m_num = rand() % 2;
			int m_hp = m[m_num].hp;
			printf("\n %s �������ϴ�! ���� ����!", m[m_num].name);
			
			while (1)
			{
				printf("%s�� ����!\n", p.name);
				Sleep(1000);
				printf("%d�� ������\n", p.atk);
				Sleep(1000);
				printf("%s�� ü�� %d => %d\n", m[m_num].name, m_hp, m_hp - p.atk);
				Sleep(1000);

				m_hp -= p.atk;

				if (m_hp <= 0)
				{
					printf("�÷��̾� �¸�!");
					Sleep(1000);

					p.exp += m[m_num].exp;
					printf("����ġ : %d\n", p.exp);

					printf("�������� �̵�\n");
					Sleep(1000);
					break;
				}
			}
			break;
		}

		}
	}
}

// ������ homework - rpg �����(�׷��� �߰�)
// �׷��� �� ���� ��� óġ�ϸ� ���� ����
// 10 * 10 �迭�� ���� �����ϸ� ��

// ������ ���̷ο켼��
// 52�� �����̵� ���̾� ��Ʈ Ŭ�ι� A ~ K
// 5���� ī�� ����
// ���� ī�� ���߱�
// high - 8 ~ K, low - a ~ 6, seven - 7
// high : ���ñݸ�ŭ ���� low : ���ñݸ�ŭ ����
// seven �� ������ ���� ���� 13��
// ī�� �� ���� ī�� �ٽ� ����

//typedef struct
//{
//	int number;
//	char shape[4];
//}Trump;
//
//char shape[4][3] = {"��" }
//strcpy