#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu(void)
{
	printf("*****************************\n");
	printf("***  1.add       2.del    ***\n");
	printf("***  3.search    4.modify ***\n");
	printf("***  5.sort      6.show   ***\n");
	printf("***********0.exit************\n");
	printf("*****************************\n");
}

void test(void)
{
	int input = 0;
	Contact con = { {0},0 };

	//初始化通讯录
	InitContact(&con);


	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case SORT:
			sort_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case EXIT:
			save_contact(&con);
			destroy_contact(&con);
			//printf("通讯录已销毁。\n");
			printf("程序退出.\n");
			break;
		default:
			printf("菜单无该选项，请重新选择：>\n");
			break;
		}
	} while (input);
}

int main(void)
{

	test();

	return 0;
}