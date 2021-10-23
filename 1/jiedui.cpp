#include<stdio.h> 
#include<iostream>
#include<stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	//随机生成牌堆 
	int i;
	int r;
	int ts;
	char th;
	char paiduih[52];
	int paiduis[52];
	srand((unsigned)time(NULL));
	for(i=0;i<52;i++)
	{
		paiduis[i]=(i%13)+1;
		if(i<=12)
		paiduih[i]='A';
		if(i>12&&i<=25)
		paiduih[i]='B';
		if(i>25&&i<=38)
		paiduih[i]='C';
		if(i>38)
		paiduih[i]='D';
	}
	for(i=0;i<52;i++)
	{
		r=rand()%52;
		if(r==0)
		continue;
		th=paiduih[i];
		paiduih[i]=paiduih[r];
		paiduih[r]=th;
		ts=paiduis[i];
		paiduis[i]=paiduis[r];
		paiduis[r]=ts;
	}
	printf("随机卡组已生成。载入游戏。。。\n\n") ;
	//游戏开始 
	int apaiduis[52];
	int bpaiduis[52];
	int qpaiduis[52];
	char qpaiduih[52];
	char apaiduih[52];
	char bpaiduih[52];
	int z;
	int j;
	int ap=0;
	int bp=0;
	int pp=52;
	int qp=0;
	int ai,bi,pi,qi;
	pi=0;
	qi=0;
	int flag=0;
	//规则介绍 
	printf("游戏操作：输入1从牌堆打出牌，输入2从手牌选择打出牌。\n\n");
	printf("-----------------------------------------------------------------------------\n"); 
	printf("游戏规则如下：\n");
	printf("1.游戏卡组使用去掉双王的扑克牌，A为红桃，B为黑桃，C为草花，D为方片，数字代表点数（1--13），玩家初始卡牌为空。\n");
	printf("2.由一名玩家开始，两名玩家轮流操作，从<卡组>随机抽取翻开一张扑克牌，或从手中选择一张扑克牌，置于<放置区>上。\n");
	printf("3.若置入的花色与<放置区>原顶部扑克牌花色相同，将放置区的所有牌收到自己<手牌>内（即吃牌）。\n");
	printf("4.若<卡组>非空，则重复游戏操作。\n");
	printf("5.当<卡组>为空，且插入判定结算完成，游戏终止，进行结算判定:手牌少者获胜！\n");
	printf("游戏作者：李涵\n联系方式：QQ1049783572\n");
	printf("-----------------------------------------------------------------------------\n"); 
	printf("输入‘1’游戏开始\n");
	int game;
	scanf("%d",&game);
	printf("\n");
	if(game==1)
	{
	for(i=0;i<9999;i++)
	{
		//A玩家回合开始 
		if(qi!=0)
		{
			printf("当前放置区顶为:%c%d \n",qpaiduih[qi-1],qpaiduis[qi-1]);
		}
		else
		printf("放置区为空\n");
		printf("剩余牌堆牌数：%d\n",52-pi);
		printf("A玩家的回合，你现在有%d张牌:\n",ap);
		if(ap!=0)
		{
			for(ai=0;ai<ap;ai++)
			{
				printf("%c",apaiduih[ai]);
				printf("%d ",apaiduis[ai]);
			}
			printf("\n");
			printf("请选择出牌模式(1/2):\n");
			scanf("%d",&z);
			if(z==1)
			printf("\n"); 
			if(z==1)
			{
				qpaiduih[qi]=paiduih[pi];
				qpaiduis[qi]=paiduis[pi];
				pi++;
				qi++;
			}
			else if(z==2)
			{
				printf("你要打出哪一张牌？(1，2，3......)：\n");
				scanf("%d",&z);
				if(z>ap)
				{
					flag=1;
					break;
				}
				printf("\n");
				qpaiduih[qi]=apaiduih[z-1];
				qpaiduis[qi]=apaiduis[z-1];
				for(j=z-1;j<ap-1;j++)
				{
					apaiduih[j]=apaiduih[j+1];
					apaiduis[j]=apaiduis[j+1];
				}
				ap--;
				qi++;
			}
			else
			{
				flag=1;
				break;
			}
		}
		else
		{
			printf("你只能摸牌，请选择1:\n");
			scanf("%d",&z);
			if(z!=1)
			{
				flag=1;
				break;
			}
			printf("\n");
			qpaiduih[qi]=paiduih[pi];
			qpaiduis[qi]=paiduis[pi];
			pi++;
			qi++;
		}
		if(qpaiduih[qi-1]==qpaiduih[qi-2])
		{
		    for(j=0;j<qi;j++)
		    {
			    apaiduih[ap]=qpaiduih[j];
			    apaiduis[ap]=qpaiduis[j];
			    ap++;
	     	}
		    qi=0;
		    printf("你获得了放置区所有的牌。\n\n");
	    }
	    if(pi==52)
	    break;
		//A玩家回合结束 
		//B玩家回合开始 
		if(qi!=0)
		{
			printf("当前放置区顶为:%c%d \n",qpaiduih[qi-1],qpaiduis[qi-1]);
		}
		else
		printf("放置区为空\n");
		printf("剩余牌堆牌数：%d\n",52-pi);
		printf("B玩家的回合，你现在有%d张牌:\n",bp);
		if(bp!=0)
		{
			for(bi=0;bi<bp;bi++)
			{
				printf("%c",bpaiduih[bi]);
				printf("%d ",bpaiduis[bi]);
			}
			printf("\n");
			printf("请选择出牌模式(1/2):\n");
			scanf("%d",&z);
			if(z==1)
			printf("\n");
			if(z==1)
			{
				qpaiduih[qi]=paiduih[pi];
				qpaiduis[qi]=paiduis[pi];
				pi++;
				qi++;
			}
			else if(z==2)
			{
				printf("你要打出哪一张牌？(1，2，3......)：\n");
				scanf("%d",&z);
				if(z>bp)
				{
					flag=1;
					break;
				}
				printf("\n");
				qpaiduih[qi]=bpaiduih[z-1];
				qpaiduis[qi]=bpaiduis[z-1];
				for(j=z-1;j<bp-1;j++)
				{
					bpaiduih[j]=bpaiduih[j+1];
					bpaiduis[j]=bpaiduis[j+1];
				}
				bp--;
				qi++;
			}
			else
			{
				flag=1;
				break;
			}
		}
		else
		{
			printf("你只能摸牌，请选择1:\n");
			scanf("%d",&z);
			if(z!=1)
			{
				flag=1;
				break;
			}
			printf("\n");
			qpaiduih[qi]=paiduih[pi];
			qpaiduis[qi]=paiduis[pi];
			pi++;
			qi++;
		}
		if(qpaiduih[qi-1]==qpaiduih[qi-2])
		{
		    for(j=0;j<qi;j++)
		    {
			    bpaiduih[bp]=qpaiduih[j];
			    bpaiduis[bp]=qpaiduis[j];
			    bp++;
	     	}
		    qi=0;
		    printf("你获得了放置区所有的牌。\n\n");
	    }
	    if(pi==52)
	    break;
	    //B玩家回合结束 
	}
	//游戏结束 
	if(flag==0)
	{
	    if(ap<bp)
	    printf("A玩家胜利！\n");
	    if(ap>bp)
     	printf("B玩家胜利！\n");
    	if(ap==bp)
    	printf("这把平局！\n");
    	printf("游戏结束！"); 
    }
    else
    {
    	printf("错误输入，游戏结束。"); //防止错误输入 
	}
    }
	return 0;
}
