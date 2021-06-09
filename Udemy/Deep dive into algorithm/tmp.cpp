#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int t, l, a, b; //t:max downlode speed l:max upload speed a:上網費牌價 b:電路費牌價
	int total;
	int select;
	printf("請輸入最高下載速率(單位:M)");
	printf("\n最高下載速率(1024、500、300、100、60、35、16)");
	scanf("%d", &t);

	printf("請輸入最高上傳速率(單位:M)");
	printf("最高上傳速率(600、250、100、40、20、6、3)");
	scanf("%d", &l);

	if (t = 1024)

		a = 1067;
	else if (t = 500)
		a = 862;
	else if (t = 300)
		a = 672;
	else if (t = 100)
		a = 466;
	else if (t = 60)
		a = 459;
	else if (t = 35)
		a = 435;
	else if (t = 16)
		a = 360;
	else
		printf("下載速率輸入錯誤");

	if (l = 600)
		;
	b = 1332;
	if (l == 600)
		;
	else
	{
		switch (l)
		{

		case 250:
			b = 937;
			break;

		case 100:
			b = 727;
			break;

		case 40:
			b = 443;
			break;

		case 2:
			b = 390;
			break;

		case 6:
			b = 367;
			break;

		case 3:
			b = 294;
			break;

		defult:
			printf("最高上傳速率輸入錯誤");
			select = 1;
		}
	}

	if (select == 0)
	{
		printf("\n您的上網費牌價%d元、電路費牌價%d元", a, b);
		total = a + b;
		printf("\n總計%d元", total);
	}
	else
		printf("請輸入正確的最高上傳速率!");
	return 0;

}