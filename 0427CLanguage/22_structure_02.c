#include <stdio.h>
#include <math.h> // pow, sqrt
#include <Windows.h> // Sleep
#include <stdlib.h>
#include <time.h>

// 구조체도 하나의 자료형이다.
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

typedef struct // 익명 구조체
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
	//Point p; // -> c에선 typedef, Point; 필요
	//p.xpos = 20; // . -> 구조체 접근
	//p.ypos = 30;

	//Player p2 = { "주인공",500,100,100,0 }; // 선언과 동시에 초기화

	//{
	//	Point pos1, pos2;
	//	double distance;

	//	printf("Point pos1 : ");
	//	scanf_s("%d %d", &pos1.xpos, &pos1.ypos);

	//	printf("Point pos2 : ");
	//	scanf_s("%d %d", &pos2.xpos, &pos2.ypos);

	//	distance = sqrt((double)pow((pos1.xpos - pos2.xpos), 2) + pow((pos1.ypos - pos2.ypos), 2));
	//
	//	printf("두 점의 거리는 %g 입니다\n\n", distance);
	//}

	rpg();

	return 0;
}

void rpg()
{
	Player p;

	Monster m[2] = {
		{"슬라임",100,100,50},
		{"버섯", 60,150,70}
	}; // 구조체 배열

	printf("게임 시작! 당신의 이름은? : ");
	scanf_s("%s", &p.name, sizeof(p.name));

	printf("hp : ");
	scanf_s("%d", &p.hp);

	printf("atk : ");
	scanf_s("%d", &p.atk);

	p.exp = 0;
	p.gold = 0;

	printf("************ 던전 입장! ************\n");

	srand((unsigned int)time(NULL));

	while (1)
	{
		if (p.hp <= 0)
		{
			printf("%s 사망, 게임종료\n", p.name);
			exit(1);
		}
		printf("\n 한층 내려갑니다\n");
		Sleep(1500); // 1.5초

		int event_key = rand() % 5;

		switch (event_key)
		{
		case 0:
		{
			printf("보물상자 발견!\n");
			Sleep(1500);
			p.gold += 100;

			printf("현재 소지 골드 : %d", p.gold);
			Sleep(1000);

			printf("다음으로 이동\n");
			Sleep(1000);
			break;
		}
		case 1:
		{
			printf("함정에 빠졌습니다\n");
			Sleep(1500);
			p.hp -= 50;

			printf("현재 체력 : %d", p.hp);
			Sleep(1000);

			printf("다음으로 이동\n");
			Sleep(1000);
			break;
		}
		case 2:
		{
			int m_num = rand() % 2;
			int m_hp = m[m_num].hp;
			printf("\n %s 만났습니다! 전투 시작!", m[m_num].name);
			
			while (1)
			{
				printf("%s의 공격!\n", p.name);
				Sleep(1000);
				printf("%d의 데미지\n", p.atk);
				Sleep(1000);
				printf("%s의 체력 %d => %d\n", m[m_num].name, m_hp, m_hp - p.atk);
				Sleep(1000);

				m_hp -= p.atk;

				if (m_hp <= 0)
				{
					printf("플레이어 승리!");
					Sleep(1000);

					p.exp += m[m_num].exp;
					printf("경험치 : %d\n", p.exp);

					printf("다음으로 이동\n");
					Sleep(1000);
					break;
				}
			}
			break;
		}

		}
	}
}

// 다음주 homework - rpg 만들기(그래픽 추가)
// 그래픽 내 몬스터 모두 처치하면 게임 종료
// 10 * 10 배열로 만들어서 구현하면 됨

// 다음주 하이로우세븐
// 52장 스페이드 다이아 하트 클로버 A ~ K
// 5장의 카드 오픈
// 다음 카드 맞추기
// high - 8 ~ K, low - a ~ 6, seven - 7
// high : 베팅금만큼 받음 low : 베팅금만큼 잃음
// seven 을 맞히면 베팅 금의 13배
// 카드 다 쓰면 카드 다시 섞음

//typedef struct
//{
//	int number;
//	char shape[4];
//}Trump;
//
//char shape[4][3] = {"☆" }
//strcpy