#include<stdio.h> 
#include<iostream>
#include<stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	//��������ƶ� 
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
	printf("������������ɡ�������Ϸ������\n\n") ;
	//��Ϸ��ʼ 
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
	//������� 
	printf("��Ϸ����������1���ƶѴ���ƣ�����2������ѡ�����ơ�\n\n");
	printf("-----------------------------------------------------------------------------\n"); 
	printf("��Ϸ�������£�\n");
	printf("1.��Ϸ����ʹ��ȥ��˫�����˿��ƣ�AΪ���ң�BΪ���ң�CΪ�ݻ���DΪ��Ƭ�����ִ��������1--13������ҳ�ʼ����Ϊ�ա�\n");
	printf("2.��һ����ҿ�ʼ���������������������<����>�����ȡ����һ���˿��ƣ��������ѡ��һ���˿��ƣ�����<������>�ϡ�\n");
	printf("3.������Ļ�ɫ��<������>ԭ�����˿��ƻ�ɫ��ͬ�������������������յ��Լ�<����>�ڣ������ƣ���\n");
	printf("4.��<����>�ǿգ����ظ���Ϸ������\n");
	printf("5.��<����>Ϊ�գ��Ҳ����ж�������ɣ���Ϸ��ֹ�����н����ж�:�������߻�ʤ��\n");
	printf("��Ϸ���ߣ��\n��ϵ��ʽ��QQ1049783572\n");
	printf("-----------------------------------------------------------------------------\n"); 
	printf("���롮1����Ϸ��ʼ\n");
	int game;
	scanf("%d",&game);
	printf("\n");
	if(game==1)
	{
	for(i=0;i<9999;i++)
	{
		//A��һغϿ�ʼ 
		if(qi!=0)
		{
			printf("��ǰ��������Ϊ:%c%d \n",qpaiduih[qi-1],qpaiduis[qi-1]);
		}
		else
		printf("������Ϊ��\n");
		printf("ʣ���ƶ�������%d\n",52-pi);
		printf("A��ҵĻغϣ���������%d����:\n",ap);
		if(ap!=0)
		{
			for(ai=0;ai<ap;ai++)
			{
				printf("%c",apaiduih[ai]);
				printf("%d ",apaiduis[ai]);
			}
			printf("\n");
			printf("��ѡ�����ģʽ(1/2):\n");
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
				printf("��Ҫ�����һ���ƣ�(1��2��3......)��\n");
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
			printf("��ֻ�����ƣ���ѡ��1:\n");
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
		    printf("�����˷��������е��ơ�\n\n");
	    }
	    if(pi==52)
	    break;
		//A��һغϽ��� 
		//B��һغϿ�ʼ 
		if(qi!=0)
		{
			printf("��ǰ��������Ϊ:%c%d \n",qpaiduih[qi-1],qpaiduis[qi-1]);
		}
		else
		printf("������Ϊ��\n");
		printf("ʣ���ƶ�������%d\n",52-pi);
		printf("B��ҵĻغϣ���������%d����:\n",bp);
		if(bp!=0)
		{
			for(bi=0;bi<bp;bi++)
			{
				printf("%c",bpaiduih[bi]);
				printf("%d ",bpaiduis[bi]);
			}
			printf("\n");
			printf("��ѡ�����ģʽ(1/2):\n");
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
				printf("��Ҫ�����һ���ƣ�(1��2��3......)��\n");
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
			printf("��ֻ�����ƣ���ѡ��1:\n");
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
		    printf("�����˷��������е��ơ�\n\n");
	    }
	    if(pi==52)
	    break;
	    //B��һغϽ��� 
	}
	//��Ϸ���� 
	if(flag==0)
	{
	    if(ap<bp)
	    printf("A���ʤ����\n");
	    if(ap>bp)
     	printf("B���ʤ����\n");
    	if(ap==bp)
    	printf("���ƽ�֣�\n");
    	printf("��Ϸ������"); 
    }
    else
    {
    	printf("�������룬��Ϸ������"); //��ֹ�������� 
	}
    }
	return 0;
}
