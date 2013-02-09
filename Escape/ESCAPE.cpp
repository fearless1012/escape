#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>
#include<math.h>
#include<mouse.h>
#include<ctype.h>
int x,y;
int blk;
void background(int i)
{
	setfillstyle(1,i);
	bar(0,0,639,479);
}
int door1()
{
	cleardevice();
	if(blk==0)
	cout<<"This game is certainly a tricky one !";
	else
	blk++;
	cout<<"This game is similar to the one you played in one of the previous doors. Nevertheless,\n";
	cout<<"\nYour objective in this game is to push all the red colored boxes into the white area at the cornerof the field.";
	cout<<" You can see, on the field, your ball which will be carrying out your instructions on pushing the blocks around using the keys specified.";
	cout<<" But the ball can't push 2 boxes together. Neither can it pull a box from the wall.";
	cout<<"\nSo gear up all your decision making skills coz, its time to boss around ! \n\n Press a key to start playing.";
	getch();
	clrscr();
	restart:
	background(14);
	setcolor(0);
	line(50,200,75,200);
	line(45,200,55,190);
	line(45,200,55,210);
	outtextxy(35,200,"A");
	line(100,200,125,200);
	line(130,200,125,190);
	line(130,200,125,210);
	outtextxy(140,200,"D");
	line(88,187,88,164);
	line(88,159,78,169);
	line(88,159,98,169);
	outtextxy(88,149,"W");
	line(88,212,88,237);
	line(88,242,78,232);
	line(88,242,98,232);
	outtextxy(88,252,"S");
	outtextxy(20,280,"Undo last move: B");
	setcolor(0);
	setfillstyle(1,8);
	for(x=178;x<463;x+=15)
	for(y=160;y<415;y+=15)
	bar3d(x,y,x+14,y+14,1,0);
	setfillstyle(1,7);
	bar(254,206,298,250);
	bar(224,251,313,265);
	bar(224,266,238,295);
	bar(194,281,238,310);
	bar(238,296,418,310);
	bar(254,265,268,340);
	bar(268,326,328,340);
	bar(314,311,328,340);
	bar(299,251,313,310);
	bar(344,308,358,325);
	bar(389,281,418,325);
	setfillstyle(1,15);
	bar(418,281,448,325);
	setfillstyle(1,4);
	setcolor(2);
	int xb[6]={256,286,286,256,256,211},yb[6]={223,238,253,253,298,298};
	x=351,y=318;
	int f1,f2;
	for(int i=0;i<6;i++)
	bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
	char ch,s;
	int t=0,p;
	accept:
	do
	{
		p=0;
		for(int i=0;i<6;i++)
		if(xb[i]<421)
		p++;
		if(p==0)
		{
			setcolor(2);
			outtextxy(0,10,"Completed!!!");
			return 1;
		}
		setfillstyle(1,9);
		setcolor(2);
		fillellipse(x,y,4,7);
		ch=getche();
		if(ch=='r')
		{
			cleardevice();
			goto restart ;
		}
		if(ch=='b'&&f1!=0)
		{
			if(s=='d')
			{
				if(x==441||x==426)
				{
					setfillstyle(1,15);
					setcolor(15);
					fillellipse(x,y,4,7);
					x-=15;
				}
				else if((x!=261&&(y==243||y==228||y==213))||(y==258&&x!=231)||(y==288&&x!=396&&x!=306&&x!=261&&x!=201)||(y==273&&x!=396&x!=306&&x!=261&&x!=231)||(y==303&&x!=201)||(y==318&&x!=396&&x!=351&&x!=321&&x!=261)||(y==333&&x!=261))
				{
					setfillstyle(1,7);
					setcolor(7);
					fillellipse(x,y,4,7);
					x-=15;
				}
				if(f2!=-1)
				{
					if(xb[f2]==436||xb[f2]==421)
						setfillstyle(1,15);
					else
						setfillstyle(1,7);
					bar(xb[f2]-2,yb[f2]-2,xb[f2]+11,yb[f2]+12);
					xb[f2]-=15;
					setfillstyle(1,4);
					setcolor(2);
					bar3d(xb[f2],yb[f2],xb[f2]+9,yb[f2]+10,1,1);
				}
			}
			if(s=='a')
			{
				if((x!=291&&(y==243||y==228||y==213))||(y==258&&x!=306)||((y==273||y==288)&&(x!=441&&x!=426&x!=306&&x!=261&&x!=231))||(y==303&&x!=426&&x!=441)||(y==318&&x!=426&&x!=441&&x!=351&&x!=321&&x!=261)||(y==333&&x!=321))
				{
					setfillstyle(1,7);
					setcolor(7);
					fillellipse(x,y,4,7);
					x+=15;
				}
				else if(x==426&&x!=441)
				{
					setfillstyle(1,15);
					setcolor(15);
					fillellipse(x,y,4,7);
					x+=15;
				}
				if(f2!=-1)
				{
					if(xb[f2]==421||xb[f2]==436)
						setfillstyle(1,15);
					else
					setfillstyle(1,7);
					bar(xb[f2]-2,yb[f2]-2,xb[f2]+11,yb[f2]+12);
					xb[f2]+=15;
					setfillstyle(1,4);
					setcolor(2);
					bar3d(xb[f2],yb[f2],xb[f2]+9,yb[f2]+10,1,1);
				}
			}
			if(s=='w')
			{
				if(((x==201||x==216)&&y!=303)||((x==231||x==306)&&y!=303&&y!=333)||(x==261&&y!=333)||((x==276||x==291)&&(y==243||y==228||y==213))||(x==321&&y!=333)||(x==351&&y!=318)||((x==396||x==411)&&y!=318))
				{
					setfillstyle(1,7);
					setcolor(7);
					fillellipse(x,y,4,7);
					y+=15;
				}
				else if((x==426||x==441)&&y!=318)
				{
					setfillstyle(1,15);
					setcolor(15);
					fillellipse(x,y,4,7);
					y+=15;
				}
				if(f2!=-1)
				{
					if(xb[f2]==421||xb[f2]==436)
					setfillstyle(1,15);
					else
					setfillstyle(1,7);
					bar(xb[f2]-2,yb[f2]-2,xb[f2]+11,yb[f2]+12);
					yb[f2]+=15;
					setfillstyle(1,4);
					setcolor(2);
					bar3d(xb[f2],yb[f2],xb[f2]+9,yb[f2]+10,1,1);
				}
			}
			if(s=='s')
			{
				if(((x==201||x==216)&&y!=288)||((x==231||x==306)&&y!=258&&y!=333)||(x==261&&y!=213)||((x==276||x==291)&&(y==258||y==243||y==228))||(x==321&&y!=303)||(x==351&&y==318)||((x==396||x==411)&&y!=288))
				{
					setfillstyle(1,7);
					setcolor(7);
					fillellipse(x,y,4,7);
					y-=15;
				}
				else if((x==426||x==441)&&y!=288)
				{
				setfillstyle(1,15);
				setcolor(15);
				fillellipse(x,y,4,7);
				y-=15;
				f1++;
				}
				if(f2!=-1)
				{
					if(xb[f2]==436||xb[f2]==421)
					setfillstyle(1,15);
					else
					setfillstyle(1,7);
					bar(xb[f2]-2,yb[f2]-2,xb[f2]+11,yb[f2]+12);
					yb[f2]-=15;
					setfillstyle(1,4);
					setcolor(2);
					bar3d(xb[f2],yb[f2],xb[f2]+9,yb[f2]+10,1,1);
				}
			}
		}
		if(ch=='d')
		{
			f1=0;
			f2=-1;
			for(int i=0;i<6;i++)
			if((x+10==xb[i])&&(y-5==yb[i]))
			{
				if((yb[i]==253&&xb[i]!=301)||(yb[i]==253&&xb[i]!=301)||((yb[i]==298||yb[i]==283||yb[i]==313)&&xb[i]!=436))
				{
					for(int j=0;j<10;j++)
					if(yb[i]==yb[j]&&xb[i]+15==xb[j])
					goto accept ;
					if(xb[i]==421||xb[i]==436)
					setfillstyle(1,15);
					else
					setfillstyle(1,7);
					bar(xb[i]-2,yb[i]-2,xb[i]+11,yb[i]+12);
					xb[i]+=15;
					f2=i;
					setfillstyle(1,4);
					setcolor(2);
					bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
				}
				else
				goto accept ;
			}
			if((x!=291&&(y==243||y==228||y==213))||(y==258&&x!=306)||((y==273||y==288)&&(x!=441&&x!=426&x!=306&&x!=261&&x!=231))||(y==303&&x!=426&&x!=441)||(y==318&&x!=426&&x!=441&&x!=351&&x!=321&&x!=261)||(y==333&&x!=321))
			{
				setfillstyle(1,7);
				setcolor(7);
				fillellipse(x,y,4,7);
				t++;
				x+=15;
				f1++;
			}
			else if(x==426&&x!=441)
			{
				setfillstyle(1,15);
				setcolor(15);
				fillellipse(x,y,4,7);
				t++;
				x+=15;
				f1++;
			}
		}
		if(ch=='a')
		{
			f1=0;
			f2=-1;
			for(int i=0;i<6;i++)
			if((x-20==xb[i])&&(y-5==yb[i]))
			{
				if((yb[i]==253&&xb[i]!=226)||(yb[i]==283&&xb[i]!=391)||(yb[i]==298&&xb[i]!=196))
				{
					for(int j=0;j<10;j++)
					if(yb[i]==yb[j]&&xb[i]-15==xb[j])
					goto accept ;
					if(xb[i]==436||xb[i]==421)
					setfillstyle(1,15);
					else
					setfillstyle(1,7);
					bar(xb[i]-2,yb[i]-2,xb[i]+11,yb[i]+12);
					xb[i]-=15;
					f2=i;
					setfillstyle(1,4);
					setcolor(2);
					bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
				}
				else
				goto accept;
			}
			if(x==441||x==426)
			{
				setfillstyle(1,15);
				setcolor(15);
				fillellipse(x,y,4,7);
				t++;
				x-=15;
				f1++;
			}
			else if((x!=261&&(y==243||y==228||y==213))||(y==258&&x!=231)||(y==288&&x!=396&&x!=306&&x!=261&&x!=201)||(y==273&&x!=396&x!=306&&x!=261&&x!=231)||(y==303&&x!=201)||(y==318&&x!=396&&x!=351&&x!=321&&x!=261)||(y==333&&x!=261))
			{
				setfillstyle(1,7);
				setcolor(7);
				fillellipse(x,y,4,7);
				t++;
				x-=15;
				f1++;
			}
		}
		if(ch=='w')
		{
			f1=0;
			f2=-1;
			for(int i=0;i<6;i++)
			if((x-5==xb[i])&&(y-20==yb[i]))
			{
				if(((xb[i]==286||xb[i]==271||xb[i]==256)&&(yb[i]!=208))||((xb[i]==406||xb[i]==391||xb[i]==421||xb[i]==436)&&(yb[i]!=283)))
				{
					for(int j=0;j<10;j++)
					if(xb[i]==xb[j]&&yb[i]-15==yb[j])
					goto accept ;
					if(xb[i]==436||xb[i]==421)
					setfillstyle(1,15);
					else
					setfillstyle(1,7);
					bar(xb[i]-2,yb[i]-2,xb[i]+11,yb[i]+12);
					yb[i]-=15;
					f2=i;
					setfillstyle(1,4);
					setcolor(2);
					bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
				}
				else
				goto accept;
			}
			if(((x==201||x==216)&&y!=288)||((x==231||x==306)&&y!=258&&y!=333)||(x==261&&y!=213)||((x==276||x==291)&&(y==258||y==243||y==228))||(x==321&&y!=303)||(x==351&&y==318)||((x==396||x==411)&&y!=288))
			{
				setfillstyle(1,7);
				setcolor(7);
				fillellipse(x,y,4,7);
				t++;
				y-=15;
				f1++;
			}
			if((x==426||x==441)&&y!=288)
			{
				setfillstyle(1,15);
				setcolor(15);
				fillellipse(x,y,4,7);
				t++;
				y-=15;
				f1++;
			}
		}
		if(ch=='s')
		{
			f1=0;	f2=-1;
			for(int i=0;i<6;i++)
			if((x-5==xb[i])&&(y+10==yb[i]))
			{
				if((xb[i]==256&&yb[i]!=328)||(xb[i]==286&&yb[i]!=253)||((xb[i]==406||xb[i]==391||xb[i]==421||xb[i]==436)&&(yb[i]!=313)))
				{
					for(int j=0;j<10;j++)
					if(xb[i]==xb[j]&&yb[i]+15==yb[j])
					goto accept ;
					if(xb[i]==421||xb[i]==436)
					setfillstyle(1,15);
					else
					setfillstyle(1,7);
					bar(xb[i]-2,yb[i]-2,xb[i]+11,yb[i]+12);
					yb[i]+=15;
					f2=i;
					setfillstyle(1,4);
					setcolor(2);
					bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
				}
				else
				goto accept;
			}
			if(((x==201||x==216)&&y!=303)||((x==231||x==306)&&y!=303&&y!=333)||(x==261&&y!=333)||((x==276||x==291)&&(y==243||y==228||y==213))||(x==321&&y!=333)||(x==351&&y!=318)||((x==396||x==411)&&y!=318))
			{
				setfillstyle(1,7);
				setcolor(7);
				fillellipse(x,y,4,7);
				t++;
				y+=15;
				f1++;
			}
			if((x==426||x==441)&&y!=318)
			{
				setfillstyle(1,15);
				setcolor(15);
				fillellipse(x,y,4,7);
				t++;
				y+=15;
				f1++;
			}
		}
		s=ch;
	}while(ch!='q');
	if(ch=='q')
	{
			outtextxy(0,25,"Do you really want to quit?(y/n) ");
			ch=getche();
			if(ch=='n')
			{
				setcolor(14);
				outtextxy(0,25,"Do you really want to quit?(y/n) ");
				goto accept;
			}
	}
	return 0;
}
int door2()
{
	cleardevice();
	if(blk==0)
	cout<<"This game is certainly a tricky one !";
	else
	cout<<"This game is similar to the one you played in one of the previous doors. Nevertheless,\n";
	blk++;
	cout<<"\nYour objective in this game is to push all the red colored boxes into the white area at the cornerof the field.";
	cout<<" You can see, on the field, your ball which will be carrying out your instructions on pushing the blocks around using the keys specified.";
	cout<<" But the ball can't push 2 boxes together. Neither can it pull a box from the wall.";
	cout<<"\nSo gear up all your decision making skills coz, its time to boss around ! \n\n Press a key to start playing.";
	getch();
	clrscr();
	background(14);
	setcolor(0);
	line(50,200,75,200);
	line(45,200,55,190);
	line(45,200,55,210);
	outtextxy(35,200,"A");
	line(100,200,125,200);
	line(130,200,125,190);
	line(130,200,125,210);
	outtextxy(140,200,"D");
	line(88,187,88,164);
	line(88,159,78,169);
	line(88,159,98,169);
	outtextxy(88,149,"W");
	line(88,212,88,237);
	line(88,242,78,232);
	line(88,242,98,232);
	outtextxy(88,252,"S");
	outtextxy(20,280,"Undo last move: B");
	char ch;
	int p,i,j,f,fe,x,y;
	setfillstyle(1,8);
	setcolor(0);
	for(i=177;i<463;i+=14)
	for(j=165;j<415;j+=14)
	bar3d(i,j,i+13,j+13,1,0);
	restart:
	int xb[10]={345,359,359,359,345,359,345,303,317,303},yb[10]={249,249,263,277,291,305,319,291,305,319};
	x=366,y=228;
	setfillstyle(1,7);
	bar(275,221,303,277);
	bar(345,235,387,346);
	bar(289,291,317,346);
	bar(317,249,331,319);
	bar(303,249,345,263);
	bar(359,221,373,235);
	bar(317,319,345,333);
	setfillstyle(1,15);
	bar(247,221,274,289);
	accept:
	do
	{
	setfillstyle(1,4);
	setcolor(2);
	for(i=0;i<10;i++)
		bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
	setfillstyle(1,9);
	setcolor(2);
	fillellipse(x,y,4,7);
	p=0;
	char t;
	for(i=0;i<10;i++)
		if(xb[i]<275)
			p++;
	if(p==10)
	{
		setcolor(2);
		outtextxy(0,10,"Completed!!!");
		getch();
		return 1;
	}
	ch=getche();
	if(ch=='r')
		{
			goto restart ;
		}
	if(ch=='b'&&fe==1)
		{
			if(t=='d')
				{
				if(x<274)
					{
					setcolor(15);
					setfillstyle(1,15);
					}
				else
					{
					setcolor(7);
					setfillstyle(1,7);
					}
				fillellipse(x,y,4,7);
				x-=14;
				for(i=0;i<10;i++)
					if(x+21==xb[i]&&y-7==yb[i]&&f==1)
						  {
						  if(xb[i]<274)
							{
							setcolor(15);
							setfillstyle(1,15);
							}
						  else
							{
							setcolor(7);
							setfillstyle(1,7);
							}
						  bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
						  xb[i]-=14;
						  }
				}
			if(t=='a')
				{
				if(x<274)
					{
					setcolor(15);
					setfillstyle(1,15);
					}
				else
					{
					setcolor(7);
					setfillstyle(1,7);
					}
				fillellipse(x,y,4,7);
				x+=14;
				for(i=0;i<10;i++)
					if(x-35==xb[i]&&y-7==yb[i]&&f==1)
						 {
						 if(xb[i]<274)
							{
							setcolor(15);
							setfillstyle(1,15);
							}
						  else
							{
							setcolor(7);
							setfillstyle(1,7);
							}
						 bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
						 xb[i]+=14;
						 }
				}
			if(t=='w')
				{
				if(x<274)
					{
					setcolor(15);
					setfillstyle(1,15);
					}
				else
					{
					setcolor(7);
					setfillstyle(1,7);
					}
				fillellipse(x,y,4,7);
				y+=14;
				for(i=0;i<10;i++)
					if(y-35==yb[i]&&x-7==xb[i]&&f==1)
						 {
						  if(xb[i]<274)
							{
							setcolor(15);
							setfillstyle(1,15);
							}
						  else
							{
							setcolor(7);
							setfillstyle(1,7);
							}
						  bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
						  yb[i]+=14;
						  }
				}
			if(t=='s')
				{
				if(x<274)
					{
					setcolor(15);
					setfillstyle(1,15);
					}
				else
					{
					setcolor(7);
					setfillstyle(1,7);
					}
				  fillellipse(x,y,4,7);
				y-=14;
				for(i=0;i<10;i++)
					if(y+21==yb[i]&&x-7==xb[i]&&f==1)
						 {
						 if(xb[i]<274)
							{
							setcolor(15);
							setfillstyle(1,15);
							}
						  else
							{
							setcolor(7);
							setfillstyle(1,7);
							}
						 bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
						 yb[i]-=14;
						 }
				}
		}
	if(ch=='d')
		{
		f=0;	fe=0;
		if(x==380||(x==366&&y==228)||(x==296&&(y==228||y==242||y==270))||(x==261&&y==284)||(x==303&&y==340)||(x==324&&(y>269&&y<313)))
			goto accept;
		else
			{
			for(i=0;i<10;i++)
				{
				if(x+7==xb[i]&&y-7==yb[i])
					{
					for(int j=0;j<10;j++)
						{
						if(xb[i]+14==xb[j]&&yb[i]==yb[j])
							goto accept;
						}
					if(xb[i]==373||(xb[i]==282&&(yb[i]==235||yb[i]==221||yb[i]==263))||(xb[i]==254&&yb[i]==277)||(xb[i]==289&&yb[i]==333)||(xb[i]==317&&(yb[i]==291||yb[i]==305)))
						goto accept;
					else
						{
						if(xb[i]<274)
							{
							setcolor(15);
							setfillstyle(1,15);
							}
						else
							{
							setcolor(7);
							setfillstyle(1,7);
							}
						bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
						xb[i]+=14;	f++;
						}
					}
				}
			if(x<274)
				{
				setcolor(15);
				setfillstyle(1,15);
				}
			else
				{
				setcolor(7);
				setfillstyle(1,7);
				}
			fillellipse(x,y,4,7);
			x+=14;	fe++;
			}
		}
		if(ch=='a')
		{
		f=0;	fe=0;
		if((x==366&&y==228)||(x==254)||(x==324&&(y==270||y==284))||(x==296&&y>275)||(x==352&&(y!=256&&y!=326)))
			{
			goto accept;
			}
		else
			{
			for(i=0;i<10;i++)
				{
				if(x-21==xb[i]&&y-7==yb[i])
					{
					for(int j=0;j<10;j++)
						{
						if(xb[i]-14==xb[j]&&yb[i]==yb[j])
							goto accept;
						}
					if((xb[i]==247)||(xb[i]==289&&yb[i]>275)||(xb[i]==345&&(yb[i]!=249&&yb[i]!=319)))
						goto accept;
					else
						{
						if(xb[i]<274)
							{
							setcolor(15);
							setfillstyle(1,15);
							}
						  else
							{
							setcolor(7);
							setfillstyle(1,7);
							}
						bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
						xb[i]-=14;	f++;						}
					}
				}
			if(x<274)
				{
				setcolor(15);
				setfillstyle(1,15);
				}
			else
				{
				setcolor(7);
				setfillstyle(1,7);
				}
			fillellipse(x,y,4,7);
			x-=14;       fe++;
			}
		}
		if(ch=='w')
		{
		f=0;      fe=0;
		if((y==228)||(y==242&&(x==352||x==380))||(y==256&&(x<340&&x>300))||(y==298&&(x==310||x==296))||(y==326&&x==338))
			{
			goto accept;
			}
		else
			{
			for(i=0;i<10;i++)
				{
				if(x-7==xb[i]&&y-21==yb[i])
					{
					for(int j=0;j<10;j++)
						{
						if(xb[i]==xb[j]&&yb[i]-14==yb[j])
							goto accept;
						}
					if((yb[i]==221)||(yb[i]==235&&(xb[i]==345||xb[i]==373))||(yb[i]==256&&xb[i]==317)||(yb[i]==291&&(xb[i]==303||xb[i]==289)))
						goto accept;
					else
						{
						if(xb[i]<274)
							{
							setcolor(15);
							setfillstyle(1,15);
							}
						else
							{
							setcolor(7);
							setfillstyle(1,7);
							}
						bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
						yb[i]-=14;	f++;
						}
					}
				}
			if(x<274)
				{
				setcolor(15);
				setfillstyle(1,15);
				}
			else
				{
				setcolor(7);
				setfillstyle(1,7);
				}
			fillellipse(x,y,4,7);
			y-=14;        fe++;
			}
		}
		if(ch=='s')
		{
		f=0; fe=0;
		if((y==340)||(y==326&&(x==338||x==324))||(y==256&&(x==310||x==338))||(y==284&&x<270)||(y==270&&(x==296||x==282)))
			{
			goto accept;
			}
		else
			{
			for(i=0;i<10;i++)
				{
				if(x-7==xb[i]&&y+7==yb[i])
					{
					for(int j=0;j<10;j++)
						{
						if(xb[i]==xb[j]&&yb[i]+14==yb[j])
							goto accept;
						}
					if((yb[i]==333)||(yb[i]==319&&xb[i]==317)||(yb[i]==277&&xb[i]<263)||(yb[i]==263&&(xb[i]==289||xb[i]==275)))
						goto accept;
					else
						{
						if(xb[i]<274)
							{
							setcolor(15);
							setfillstyle(1,15);
							}
						  else
							{
							setcolor(7);
							setfillstyle(1,7);
							}
						bar3d(xb[i],yb[i],xb[i]+9,yb[i]+10,1,1);
						yb[i]+=14;	f++;
						}
					}
				}
			if(x<274)
				{
				setcolor(15);
				setfillstyle(1,15);
				}
			else
				{
				setcolor(7);
				setfillstyle(1,7);
				}
			fillellipse(x,y,4,7);
			y+=14;        fe++;
			}
		}
	t=ch;
	}while(ch!='q');
	if(ch=='q')
	{
		outtextxy(0,25,"Do you really want to go back?(y/n) ");
		ch=getche();
		if(ch=='n')
		{
			setcolor(14);
			outtextxy(0,25,"Do you really want to back?(y/n) ");
			goto accept;
		}
	}
	getch();
	return 0;
}
int tr=0;
void check(int k,int x,int y,int y2[19],int p[19][19],char z[][2])
{
	int i=(x-130)/20,j=(y-50)/20;
	p[i][j]=k+1;
	if((i>1&&(p[i-2][j]+p[i][j]==p[i-1][j]))&&(i<17&&(p[i][j]+p[i+2][j]==p[i+1][j])))
	{
		setfillstyle(1,14);
		bar(x-40,y,x+60,y+20);
		p[i-2][j]=20;
		p[i-1][j]=20;
		p[i][j]=20;
		p[i+2][j]=20;
		p[i+1][j]=20;
		y2[i]+=20;
		y2[i+1]+=20;
		y2[i+2]+=20;
		y2[i-1]+=20;
		y2[i-2]+=20;
		tr+=2;
	}
	if(i>1&&(p[i-2][j]+p[i][j]==p[i-1][j]))
	{
		setfillstyle(1,14);
		bar(x-40,y,x+20,y+20);
		p[i-2][j]=20;
		p[i][j]=20;
		p[i-1][j]=20;
		y2[i]+=20;
		y2[i-1]+=20;
		y2[i-2]+=20;
		tr++;

	}
	if(i>0&&i<18&&(p[i-1][j]+p[i+1][j]==p[i][j]))
	{
		setfillstyle(1,14);
		bar(x-20,y,x+40,y+20);
		p[i-1][j]=20;
		p[i+1][j]=20;
		p[i][j]=20;
		y2[i]+=20;
		y2[i-1]+=20;
		y2[i+1]+=20;
		tr++;
	}
	if(i<17&&(p[i][j]+p[i+2][j]==p[i+1][j]))
	{
		setfillstyle(1,14);
		bar(x,y,x+60,y+20);
		p[i][j]=20;
		p[i+2][j]=20;
		p[i+1][j]=20;
		y2[i]+=20;
		y2[i+1]+=20;
		y2[i+2]+=20;
		tr++;
	}
	if(j<17&&(p[i][j]+p[i][j+2]==p[i][j+1]))
	{
		setfillstyle(1,14);
		bar(x,y,x+20,y+59);
		p[i][j]=20;
		p[i][j+2]=20;
		p[i][j+1]=20;
		y2[i]+=60;
		tr++;
	}
	for(j=18;j>0;j--)
	for(i=0;i<19;i++)
	{
		if(p[i][j]==20&&p[i][j-1]!=20)
		{
			p[i][j]=p[i][j-1];
			p[i][j-1]=20;
			setfillstyle(1,14);
			setcolor(14);
			bar3d(130+(i*20),50+(20*(j-1)),150+(i*20),70+(j*20),1,1);
			setfillstyle(1,2);
			setcolor(0);
			bar3d(131+(i*20),50+(20*j),148+(i*20),70+(j*20),1,1);
			outtextxy(135+(i*20),55+(j*20),z[p[i][j]-1]);
		 }
	}
}
void repyel(int &x,int &y)
{
	setfillstyle(1,14);
	bar(x+1,y,x+19,y+19);
	y+=20;
}
void putgreen(int &x,int &y,int x2[],int &i,char z[][2],int &k)
{
	if(y!=50)
	x=x2[i];
	setfillstyle(1,2);
	setcolor(0);
	bar3d(x+1,y,x+18,y+19,1,1);
	outtextxy(x+5,y+5,z[k]);
	delay(400);
}
int ng(char z[][2],int n)
{
	clrscr();
	cleardevice();
	gotoxy(30,10);
	cout<<"B-shaw's men are awesome in maths. So he has made a math game which if won, will open the safe. \n ";
	cout<<endl<<"The game is that, you got to place 3 boxes together, such that the number on the middle box is equal to the sum of the numbers on the adjacent boxes. They should be placed be verticle or horizontal";
	getch();
	clrscr();
	setfillstyle(1,14);
	bar(0,0,639,479);
	int i,x,y=50,y2[19],x2[19],k,p[19][19];
	for(i=0;i<19;i++)
	for(k=0;k<19;k++)
	p[i][k]=20;
	for(i=0;i<19;i++)
	{
		x2[i]=130+i*20;
		y2[i]=410;
	}
	setcolor(0);
	rectangle(129,49,511,431);
	rectangle(128,48,512,432);
	rectangle(127,47,513,433);
	rectangle(126,46,514,434);
	rectangle(125,45,515,435);
	i=9;
	randomize();
	k=random(n);
	char d;
	again :
	while(!kbhit())
	{
		if(y!=y2[i])
		repyel(x,y);
		else
		{
			if(y2[i]==50)
			cout<<"GAME OVER";
			else
			{
				y2[i]-=20;
				x=x2[i];
				check(k,x,y,y2,p,z);
				gotoxy(10,20);
				cout<<tr;
				if(tr==10)
				{
					cout<<"COMPLETED";
					return 1;
				}
				y=50;
				k=random(n);
			}
		}
		putgreen(x,y,x2,i,z,k);
	 }
	d=getche();
	if(d=='a'&&i>0&&p[((x-130)/20)-1][(y-50)/20]==20&&y<y2[i]-20&&y<y2[i-1]-20)
	i--;
	else if(d=='d'&&i<18&&p[((x-130)/20)+1][(y-50)/20]==20&&y<y2[i]-20&&y<y2[i+1]-20)
	i++;
	else if(d=='s'&&p[((x-130)/20)][(y-50)/20+1]==20&&y<y2[i]-20)
	{
		y+=20;
		repyel(x,(y-20));
	}
	else if(d=='q')
	return 0;
	goto again;
}
int door3()
{
	cleardevice();
	tr=0;
	char z[9][2]={"1","2","3","4","5","6","7","8","9"};
	return ng(z,9);
}
int door4()
{
	tr=0;
	cleardevice();
	char z[5][2]={"1","2","3","4","5"};
	return ng(z,5);
}
int hangman(char a[60][40])
{
	cout<<" B-shaw's favourite movie/person is the code now.You play a geme of the traditional 'Hangman' to read your ally's mind. But remember, 9 wrong guesses, and you're out of the field ! And don't try to act smart coz when you come back for another round later, the word would have obviously been changed. Now, go get it !";
	char b[10],c[40];
	randomize();
	int i=0,r,j=random(60),l=strlen(a[j]),m;
	for(m=0;m<l;m++)
	{
		if(a[j][m]!=' ')
		c[m]='-';
		else
		c[m]=' ';
	}
	c[m]=NULL;
	setcolor(5);
	line(600,140,600,240);
	line(600,140,570,140);
	line(570,240,630,240);
	line(570,140,570,150);
	while(i!=10)
	{
		gotoxy(40,17);
		cout<<"Letters not found : ";
		for(r=0;r<i;r++)
		cout<<b[r]<<" ";
		moveto(0,0);
		m=0,r=0;
		for(int k=0;k<l;k++)
		{
			if(c[k]!='-')
			m++;
		}
		gotoxy(10,10);
		printf("You have ");
		cout<<9-i<<" guesses left : "<<c<<endl;
		if(m==l)
		{
			setcolor(2);
			outtextxy(100,120,"Great,You found the word !");
			setcolor(5);
			circle(570,170,20);
			line(570,190,570,225);
			line(570,200,550,210);
			line(570,200,590,210);
			line(570,225,550,235);
			line(570,225,590,235);
			circle(560,160,3);
			circle(580,160,3);
			circle(570,170,2);
			arc(570,170,240,300,8);
			r=100;
			getch();
			delay(50);
			return 1;
		}
		Again:
		gotoxy(10,11);
		printf("Enter your guess letter :");
		cin>>b[i];
		if(isalpha(b[i])==0)
		{
			setcolor(4);
			outtextxy(10,125,"Please enter proper letter");
			delay(1000);
			setcolor(0);
			outtextxy(10,125,"Please enter proper letter");
			goto Again;
		}
		for(k=0;k<l;k++)
		{
			for(int n=0;n<i;n++)
				if((b[i]==b[n])||(b[i]==c[k]))
				{
					setcolor(4);
					outtextxy(10,125,"You have already entered the letter");
					delay(1000);
					setcolor(0);
					outtextxy(10,125,"You have already entered the letter");
					goto Again;
				}
			if(b[i]==a[j][k])
			{
				 r=1;
				 c[k]=b[i];
			}
		}
		if(r==0)
		{
			setcolor(5);
			i++;
			switch(i)
			{
				case 10 :arc(570,190,45,135,8);
				case 9 :circle(570,170,2);
				case 8 :circle(580,160,3);
				case 7 :circle(560,160,3);
				case 6 :line(570,225,590,235);
				case 5 :line(570,225,550,235);
				case 4 :line(570,200,590,210);
				case 3 :line(570,200,550,210);
				case 2 :line(570,190,570,225);
				case 1 :circle(570,170,20);
			}
		}
	}
	if(r!=100)
	{
		setcolor(3);
		outtextxy(100,120,"Sorry your chances are over ! The answer is ");
		outtextxy(100,145,a[j]);
		outtextxy(10,155,"you can try again later,mind you the password will be changed");
		return 0;
	}
	getch();
	return 1;
}
int door5()
{
	char a[60][40]={"titanic","sound of music","final destination","the ring","toy story","avatar","inception","lost world",
	"Wolverine","home alone","harry potter and the chamber of secrets","finding nemo","sixth sense","a beautiful mind",
	"mummy returns","transformers","resident evil","armour of god","the myth","freaky friday","slumdog millionaire","exorcist",
	"men in black","hulk","shrek","madagascar","monsters inc","the mask","alice in wonderland","pirates of the carribean",
	"before sunrise","shangai knights","dark knight","spiderman","the incredibles","spy kids","camp rock","seventeen again",
	"godzilla","bend it like beckham","million dollar baby","omen","gandhi","the other end of the line","oliver twist",
	"lord of the rings","da vinci code","parent trap","inglorius basterds","memento","tarzan","percy jackson and the lightning thief",
	"space jam","the grudge","sleepless in seattle","troy","lion king","ice age","tuxedo","count of monte cristo"};
	clrscr();cleardevice();
	cout<<"THEME : MOVIES"<<endl;
	return hangman(a);
}
int door6()
{
	char a[60][40]={"barrack hussein obama","osama bin laden","indra gandhi","bill gates","vishwanathan anand","sachin tendulkar","mahendra singh dhoni","daniel radcliff",
	"robert pattenson","mahatma gandhi","kamal hasan","rajnikanth","amir khan","aishwarya rai",
	"a r rahman","sania misra","leonardo de caprio","demi lovato","miley cyrus","michael jackson","abdul kalam","george bush",
	"mani ratnam","chetan bhagat","shahrukh khan","amitabh bachan","sarojini naidu","jawahar lal nehru","jayalalitha","j ramya",
	"kalpana chawla","sunita williams","rakesh sharma","michael jordan","jackie chan","will smith","martin luther king","ronaldo",
	"j k rowling","enid blyton","eoin colfer","christopher paolini","francine pascal","diana","jaden smith",
	"james cameron","jeffrey archer","dan brown","j r r tolkien","khaled husseini","arthur hailey","shakira",
	"david copperfield","mother teresa","florece nightingale","vivekananda","subash chandra bose","jagdish chandra bose","c v raman","paul laurence dunbar"};
	clrscr();cleardevice();
	cout<<"THEME : PERSONALITIES"<<endl;
	return hangman(a);
}
int mine(int s)
{
	clrscr();
	int n=101,x[100],y[100],k=0,j,l,i[15],v,q[100],x1,y1,cl,r[100];
	char box;
	char z[101][4]={"0","1","2","3","4","5","6","7","8"};
	setfillstyle(1,WHITE);
	bar(0,0,getmaxx(),getmaxy());
	setcolor(0);
	outtextxy(200,100,"MINESWEEPER");
	outtextxy(20,130,"The purpose of the game is to open all the cells of the board which");
	outtextxy(20,145,"do not contain a bomb. You lose if you set off a bomb cell.");
	outtextxy(20,160,"Every non-bomb cell you open will tell you the total number of bombs");
	outtextxy(20,175,"in the eight neighboring cells. Once you are sure that a cell contains");
	outtextxy(20,190,"a bomb, you can right-click to put a 'flag' it on it as a reminder.");
	outtextxy(20,205,"Once you have flagged all the bombs around an open cell, you have won");
	outtextxy(20,220,"the game. To start a new game (abandoning the current one), just click");
	outtextxy(20,235,"on the 'Restart' button.	You can quit the game and go to the main");
	outtextxy(20,250,"maze page by clicking on the 'Quit' button. Happy mine hunting!");
	outtextxy(20,265,"Press a button to start the game. ");
	getch();
	cleardevice();
	setfillstyle(1,8);
	bar(0,0,getmaxx(),getmaxy());
	restart :
	setfillstyle(1,7);
	for(j=0;j<s;j++)
	{
		for(n=0;n<s;n++)
		{
			x[k]=200+n*32;
			y[k]=100+j*32;
			setcolor(8);
			bar3d(x[k],y[k],x[k]+30,y[k]+30,2,7);
			k++;
		}
	}
	setcolor(WHITE);
	rectangle(50,50,130,75);
	rectangle(185,50,245,75);
	outtextxy(60,60,"Restart");
	outtextxy(195,60,"Quit");
	for(j=0;j<pow(s,2);j++)
	{
		q[j]=0;
		r[j]=0;
	}
	restrictmouse(0,0,getmaxx(),getmaxy());
	setmouse(10,10);
	A:
	randomize();
	for(j=0;j<15;j++)
	{
		i[j]=random(pow(s,2));
	}
	char ch;
	for(j=0;j<15;j++)
	for(l=j+1;l<15;l++)
	if(i[j]==i[l])
	goto A;
	cout<<"Click on the box you want to open :";
	ABC:
	l=0;
	do
	{
		n=101;
		showmouse();
		getmouse(&cl,&x1,&y1);
		if(cl==1)
		{
			if(cl==1&&x1>50&&x1<130&&y1>50&&y1<75)
			{
				setcolor(WHITE);
				hidemouse();
				outtextxy(250,50,"Do you want to restart? (y/n): ");
				ch=getche();
				if(ch=='y'||ch=='Y')
					goto restart;
				else
				{
					setfillstyle(1,8);
					bar(250,50,600,75);
				}
			}
		else if(cl==1&&x1>185&&x1<245&&y1>50&&y1<75)
			{
				setcolor(WHITE);
				hidemouse();
				outtextxy(250,50,"Do you really want to quit? (y/n) : ");
				ch=getche();
				if(ch=='y'||ch=='Y')
				{
					setfillstyle(1,8);
					bar(250,50,600,75);
					outtextxy(250,50,"You can come back  and try again later.");
					delay(500);
					return 0;
				}
				else
				{
					setfillstyle(1,8);
					bar(250,50,600,75);
				}
			}
			hidemouse();
			for(j=0;j<pow(s,2);j++)
			if(x1>x[j]&&x1<x[j]+30&&y1>y[j]&&y1<y[j]+30)
			n=j+1;
			if(n==101||r[n-1]==1)
			goto ABC;
			k=n-1;
			q[k]=1;
			v=0;
			for(j=0;j<15;j++)
			{
				if(i[j]==k)
				{
					for(n=0;n<15;n++)
					{
						setfillstyle(1,4);
						bar(x[i[n]],y[i[n]],x[i[n]]+30,y[i[n]]+30);
						setcolor(10);
						setfillstyle(1,0);
						fillellipse(x[i[n]]+16,y[i[n]]+16,5,4);
					}
					cout<<"Ouch, you found a bomb that blasted you OUT";
					delay(1000);
					return 0;
				}
				else if((k==0)&&((k+s==i[j])||(k+1==i[j])||(k+s+1==i[j])))
				v++;
				else if((k==s-1)&&((k+s==i[j])||(k-1==i[j])||((k+s)-1==i[j])))
				v++;
				else if((k==(s)*(s-1))&&((k-s==i[j])||((k-s)+1==i[j])||(k+1==i[j])))
				v++;
				else if((k==pow(s,2)-1)&&((k-s==i[j])||((k-s)-1==i[j])||(k-1==i[j])))
				v++;
				else if((k>0&&k<(s-1))&&((k+s==i[j])||(k-1==i[j])||(k+1==i[j])||(k+(s-1)==i[j])||(k+(s+1)==i[j])))
				v++;
				else if((k>s*(s-1)&&k<pow(s,2)-1)&&((k-s==i[j])||((k-s)+1==i[j])||((k-s)-1==i[j])||(k-1==i[j])||(k+1==i[j])))
				v++;
				else if((n%s==1)&&((k+s==i[j])||(k-s==i[j])||(k-(s-1)==i[j])||(k+1==i[j])||(k+(s+1)==i[j])))
				v++;
				else if((n%s==0)&&((k+s==i[j])||(k-s==i[j])||(k-(s+1)==i[j])||(k-1==i[j])||(k+(s-1)==i[j])))
				v++;
				else
				for(int h=2;h<s;h++)
				if((n%s==h)&&((k+s==i[j])||(k-s==i[j])||(k-(s+1)==i[j])||(k-(s-1)==i[j])||(k-1==i[j])||(k+1==i[j])||(k+(s-1)==i[j])||(k+(s+1)==i[j])))
				v++;
			}
			if(n==200)
			break;
			else
			{
				setfillstyle(1,8);
				bar(x[k],y[k],x[k]+30,y[k]+30);
				setcolor(10);
				outtextxy(x[k]+10,y[k]+10,z[v]);
			}
			delay(200);
		}
		else if(cl==2)
		{
			hidemouse();
			for(j=0;j<pow(s,2);j++)
			if(x1>x[j]&&x1<x[j]+30&&y1>y[j]&&y1<y[j]+30)
			n=j+1;
			if(n==101)
			goto ABC;
			k=n-1;
			if(r[k]==1)
			{
				setfillstyle(1,7);
				setcolor(8);
				bar3d(x[k],y[k],x[k]+30,y[k]+30,2,7);
				r[k]=0;
			}
			else if(q[k]!=1)
			{
				setfillstyle(1,1);
				bar(x[k],y[k],x[k]+30,y[k]+30);
				setcolor(0);
				outtextxy(x[k]+10,y[k]+10,"*");
				r[k]=1;
			}
			l=0;
			for(j=0;j<15;j++)
			if(r[i[j]]==1)
			{
				l++;
			}
			delay(200);
		}
		else
		goto ABC;
	}while(l!=15);
	for(j=0,n=0;j<pow(s,2);j++)
	n+=r[j];
	if(l==15&&n==15)
	cout<<endl<<"Congrats ! You succesfully avoided the mines and unlocked the letter !";
	else if(n!=15)
	goto ABC;
	getch();
	return 1;
}
int door7()
{
	getch();
	return mine(8);
}
int door8()
{
	getch();
	return mine(10);
}
int cowsandbulls(char a[8][6],int n)
{
	cout<<"Now, B-Shaw tests your vocabulary ! ";
	cout<<"\t\tCows and Bulls.\n\n";
	cout<<"Instructions:-\n";
	cout<<"\nYou have 10 chances to guess the "<<n<<" letter word consisting "<<n<<" distinct letters.";
	cout<<"\nThe words you gues must only be "<<n<<" letters long and all the "<<n<<" letters must be dinstinct.";
	cout<<"\nYou would be given the number of cows and bulls in the words you guess.";
	cout<<"\nBULLS:Number of correct letters in their correct position.";
	cout<<"\nCOWS:Number of correct letters in the wrong position.\n";
	cout<<"\n\nFor example:\nWord to be guessed: SOAP\nYour guess: SALT\n\nBULLS:1('S') ; COWS:1('A')";
	cout<<"\n\n\nStart guessing :-\n\n";
	getch();
	char c[5];
	cleardevice();
	gotoxy(25,3);
	cout<<"WORD"<<setw(10)<<"COWS"<<setw(11)<<"BULLS";
	line(167,23,167,303);
	line(247,23,247,303);
	line(327,23,327,303);
	line(415,23,415,303);
	line(167,23,415,23);
	line(167,303,415,303);
	line(167,53,415,53);
	randomize();
	int i=random(7),q=0;
	for(int p=0;p<12;p++)
	{
		int l=0,w=0;
		q++;
		Again:
		for(int r=0;r<n;r++)
		{
			get:
			c[r]=getche();
			if(isalpha(c[r])==0)
			goto get;
			gotoxy(25+r,q+5);
			cout<<c[r];
		}
		for(int s=0;s<n;s++)
		for(r=s+1;r<n;r++)
		if(c[s]==c[r])
		{
			setcolor(2);
			outtextxy(100,350,"Please enter proper five letter words with no repitition : ");
			delay(100);
			setcolor(0);
			outtextxy(100,350,"Please enter proper five letter words with no repitition : ");
			goto Again;
		}
		r=0;
		for(s=0;s<n;s++)
		if(c[s]==a[i][s])
		r++;
		if(r==n)
		{
			setcolor(2);
			outtextxy(200,360,"Bulls-Eye !!");
			q=100;
			delay(1000);
			break;
		}
		for(int j=0;j<n;j++)
		{
			if(c[j]==a[i][j])
			l++;
			for(int m=0;m<n;m++)
			{
				if(m!=j)
				{
					if(c[j]==a[i][m])
					w++;
				}
			}
		}
		gotoxy(35,q+5);
		cout<<w;
		gotoxy(45,q+5);
		cout<<l;
	}
	if(q!=100)
	{
		cout<<endl<<"Sorry. Your chances are over. The word was "<<a[i];
		delay(1000);
		return 0;
	}
	getch();
	return 1;
}
int door9()
{
	clrscr();
	cleardevice();
	char a[][6]={"bike","fire","gear","stag","zero","sled","hump","acre","crap",
	"talc","idea","axis","node","flip","hymn","earl","roam","plan","told","what","atom",
	"belt","busy","cosy","cute","duty","dyes","epic","exit","fuse","fume","grey","goth",
	"halt","hyke","item","junk","jute","kept","skid","luke","musk","mint","numb",
	"nose","oven","only","pink","pine","quiz","quit","zone","plus","ache","army","play",
	"word","iron","term","into"};
	return cowsandbulls(a,4);
}
int door10()
{
	clrscr();
	cleardevice();
	char a[][6]={"stone","sting","cling","snore","tunic","lotus","pearl","storm","globe",
	"stake","infer","intra","","mango","raise","prize","agony","olive","spray","stray","super",
	"haunt","stick","lower","shift","flute","slope","scope","light","sight","might","stack",
	"liven","woven","black","prank","prick","quiet","quite","zebra","thumb","patch","charm","plant",
	"liver","stamp","trump","clamp","flesh","blend","board","place","sword","track","merit","inter"};
	return cowsandbulls(a,5);
}
int mmind(int n)
{
	int x,y,i,d[5],c[5];
	char e[6][2]={"0","1","2","3","4","5"};
	cout<<"This is B-Shaws surprise attack ! He has designed a colour code that you've got to crack. You've got no idea of what it is and by using brute force mechanism you've got to find the codes \n ";
	cout<<endl<<"The different colour that may be involved in the code are given and the number of colours are shown by the grey circles. Each time you enter a code, you'd be given the number of colours in their right places is revealed. Its time to tune your brain and crack that code !";
	getch();
	clrscr();
	setfillstyle(1,14);
	setcolor(14);
	bar(0,0,700,500);
	restrictmouse(0,0,getmaxx(),getmaxy());
	setfillstyle(1,0);
	bar(20,20,getmaxx()-20,getmaxy()-20);
	setfillstyle(1,7);
	bar(440,100,550,245);
	setfillstyle(1,8);
	bar(445,105,545,240);
	randomize();
	for(i=0;i<n;i++)
	c[i]=random(6);
	i=0;
	for(x=455;x<545;x+=45)
	for(y=110;y<245;y+=45)
	{
		setfillstyle(1,7);
		bar(x,y,x+35,y+35);
		setfillstyle(1,8);
		bar(x+5,y+5,x+30,y+30);
		setcolor(i+9);
		setfillstyle(6,i+1);
		fillellipse(x+18,y+18,10,10);
		i++;
	}
	setcolor(15);
	setfillstyle(1,8);
	for(x=200;x<(200+n*30);x+=30)
	for(y=80;y<440;y+=30)
	fillellipse(x,y,10,10);
	x=200,y=80;
	char u;
	int cl,mpx,mpy;
	setmouse(10,10);
	hey :
	while(!kbhit())
	{
		showmouse();
		getmouse(&cl,&mpx,&mpy);
		if(cl==1)
		{
			if(((mpy<145&&mpy>110)||(mpy<190&&mpy>155)||(mpy<235&&mpy>200))&&((mpx<490&&mpx>455)||(mpx<535&&mpx>500)))
			{
				if(mpx<490&&mpx>455)
				{
					if(mpy<145&&mpy>110)
					i=0;
					else if(mpy<190&&mpy>155)
					i=1;
					else if(mpy<235&&mpy>200)
					i=2;
				}
				else if(mpx<535&&mpx>500)
				{
					if(mpy<145&&mpy>110)
					i=3;
					else if(mpy<190&&mpy>155)
					i=4;
					else if(mpy<235&&mpy>200)
					i=5;
				}
			}
			else
			goto hey;
			setfillstyle(1,8);
			bar(455+(i/3)*45,110+(i%3)*45,490+(i/3)*45,145+(i%3)*45);
			setfillstyle(1,7);
			bar(460+(i/3)*45,115+(i%3)*45,485+(i/3)*45,140+(i%3)*45);
			delay(400);
			hidemouse();
			setfillstyle(1,7);
			bar(455+(i/3)*45,110+(i%3)*45,490+(i/3)*45,145+(i%3)*45);
			setfillstyle(1,8);
			bar(460+(i/3)*45,115+(i%3)*45,485+(i/3)*45,140+(i%3)*45);
			setcolor(i+9);
			setfillstyle(6,i+1);
			fillellipse(473+(i/3)*45,127+(i%3)*45,10,10);
			fillellipse(x,y,10,10);
			d[(x-200)/30]=i;
			x+=30;
			if(x==200+n*30)
			{
				x=0;
				for(i=0;i<n;i++)
				if(c[i]==d[i])
				x++;
				outtextxy(350,y,e[x]);
				if(x==n)
				{
					cout<<"You got it !!";
					delay(1000);
					return 1;
				}
				x=200,y+=30;
				if(y==440)
				{
					i=0;
					cout<<"Sorry. Your chaces are over. The answer was ";
					for(x=450;x<(450+n*30);x+=30)
					{
						setcolor(c[i]+9);
						setfillstyle(6,c[i]+1);
						fillellipse(x,350,10,10);
						i++;
					}
					delay(100);
					u='q';
					break;
				}
			}
		}
	}
	u=getche();
	if(u!='q'&&u!='Q')
	goto hey;
	return 0;
}
int door11()
{
	return mmind(3);
}
int door12()
{
	return mmind(4);
}
void tongue(int k,int x,int y,int x1,int y1,char gs[4])
{
	char g[16][10]={"not in ","Soaked ","half "," ",
				"route","crop ","yeasty","half ",
				"without","wheat","pen","mental ",
				"again"," "," "," "};
	setcolor(4);
	for(int i=x1,j=y1;;i=i*2,j=j*2)
	{
		if(i>50||i<-50||j>50||j<-50)
		break;
		line(x,y,x+i,y+j);
		delay(20);
	}
	delay(30);
	setcolor(14);
	line(x,y,x+x1*15,y+y1*15);
	delay(30);
	setfillstyle(1,4);
	for(x=269,y=323,x1=2;x>220,y>274;x-=5,y-=5,x1+=10)
	{
		bar(x,y,x+x1,y+x1);
		delay(20);
	}
	setcolor(0);
	outtextxy(x+30,y+20,g[k]);
	outtextxy(x+30,y+30,g[k+4]);
	outtextxy(x+30,y+40,g[k+8]);
	outtextxy(x+30,y+50,g[k+12]);
	gotoxy(30,22);
	cout<<"Ans : ";
	cin>>gs;
}
void main()
{
	clrscr();
	int gd=DETECT,gm,x,y,n[4]={0,0,0,0};
	initgraph(&gd,&gm,"d:\\BGI");
	cout<<"\n\tYou are the world reowned Agent Jack and you have sent a ball with a hidden camera (the latest technology !) to uncover a mafia gang's whereabouts. Your work, as always, proves to be efficient and your ball's got hold of the gang.";
	cout<<" But ,the scenario turns out to be mutual as your 'ball' too, has been tracked down by them and its your objective to get it back. Now don't let your hopes soar too high, its not as easy as it sounds !";	cout<<endl<<"Press Enter for further instructions";
	getch();
	cout<<endl<<endl<<"The invincible mafia leader, the one and only, B-Shaw has locked the  exit of your ball's escape route ! There are 4 codes in all and he's made cryptic clues for 'em.";
	cout<<" On the other hand, there are also 12 games which you can play to find out the letters contained in the words.";
	cout<<"\nPsst ! From our part, here's a peek: The four codes are all simple, arbitrary 3-letter words.";
	getch();
	cout<<"\nHaving told you the details, all you've got to do is, take the place of Agent Jack, and make your ball escape by cracking the codes. The 4 rooms in the middle of the maze have the ultimate clues.";
	cout<<" The sorrounding doors are guarded by B-Shaw's men who don't know the exact code, but parts of it. Each part will be revealed as and when you successfully complete the game. Don't worry! your ball may be just a camera, but you're a code breaker as well !";
	cout<<"\n\nNow, its time for you to sharpen your brain and go test your logical skills ! \nGo catch 'em all ! :bd";
	getch();
	clrscr();
	int i=0,k[16],m[16],l,j;
	char ans[4][4]={"out","wet","sty","men"},gs[4];
	char b[12][3]={"w ","e ","t ","o ","u ","t ","s ","t ","y ","m ","e ","n "};
	for(i=0;i<16;i++)
	{
		k[i]=0;
		m[i]=16;
	}
	randomize();
	for(i=0;i<16;i++)
	{
		god:
		if(i==5||i==6||i==9||i==10)
		{
			i++;
			goto god;
		}
		l=random(12);
		for(j=0;j<12;j++)
		if(l==m[j])
		goto god;
		m[i]=l;
	}
	accept :
	cleardevice();
	setfillstyle(1,14);
	bar(0,0,getmaxx(),getmaxy());
	setcolor(0);
	rectangle(140,194,400,454);
	setcolor(6);
	for(i=0;i<4;i++)
	if(n[i]==0)
	rectangle(400,314,400+i*2+1,334);
	else
	line(400,314,420,314+i*2);
	i=0,j=0;
	setcolor(0);
	line(125,100,150,100);
	line(120,100,130,90);
	line(120,100,130,110);
	outtextxy(110,100,"A");
	line(175,100,200,100);
	line(205,100,195,90);
	line(205,100,195,110);
	outtextxy(215,100,"D");
	line(163,87,163,64);
	line(163,59,153,69);
	line(163,59,173,69);
	outtextxy(163,49,"W");
	line(163,112,163,137);
	line(163,142,153,132);
	line(163,142,173,132);
	outtextxy(163,152,"S");
	setcolor(15);
	for(x=160;x<400;x+=60)
	for(y=214;y<454;y+=60)
	{
		setcolor(0);
		rectangle(x,y,x+40,y+40);
		setcolor(15);
		if(i>12||i==9)
		{
			rectangle(x,y+7,x+1,y+12);
			setfillstyle(1,4);
			bar(x+10,y+8,x+12,y+11);
		}
		else if(i%4==3||i==10)
		{
			rectangle(x+7,y,x+12,y+1);
			setfillstyle(1,4);
			bar(x+8,y+10,x+11,y+12);
		}
		else if(i<3||i==6)
		{
			rectangle(x+40,y+7,x+41,y+12);
			setfillstyle(1,4);
			bar(x+30,y+8,x+32,y+11);
		}
		else if(i%4==0||i==5||i==9)
		{
			rectangle(x+7,y+40,x+12,y+41);
			setfillstyle(1,4);
			bar(x+8,y+30,x+11,y+32);
		}
		if(k[i]==1)
		{
			setcolor(0);
			setfillstyle(1,4);
			bar(x+8,y+8,x+32,y+32);
			outtextxy(x+15,y+15,b[m[i]]);
		}
		i++;
	}
	char ch;
	x=150;
	y=324;
	do
	{
		p:
		setfillstyle(1,9);
		setcolor(2);
		fillellipse(x,y,4,7);
		if(n[0]==1&&n[1]==1&&n[2]==1&&n[3]==1)
		{
			setfillstyle(1,YELLOW);
			bar(0,0,400,200);
			outtextxy(10,10,"Good job, Agent Jack ! You have unlocked all the four gates and now,");
			outtextxy(10,25,"your ball can escape along with the details of B-Shaw's hideouts !");
			outtextxy(10,50,"Until next time, adieos !");
			delay(250);
			setcolor(14);
			setfillstyle(1,14);
			rectangle(400,314,401,334);
			fillellipse(x,y,4,7);
			x+=20;
			if(x>=430)
			exit(0);
			goto p;
		}
		ch=getche();
		if(ch=='d')
		{
			if((y==204||y==264||y==324||y==384||y==444)&&x!=390)
			{
				setcolor(14);
				setfillstyle(1,14);
				fillellipse(x,y,4,7);
				x+=20;
			}
			else if(((y==284||y==344||y==404)&&x==330)||y==284&&x==270)
			{
				if(y==284&&x==330)
				k[13]=door3();
				if(y==344&&x==330)
				k[14]=door8();
				if(y==404&&x==330)
				k[15]=door12();
				if(y==284&&x==270)
				{
					outtextxy(20,20,"Unveil the cryptic clue !");
					tongue(1,x+4,y,2,0,gs);
					if(strcmp(gs,ans[1])==0)
					n[1]=1;
					setfillstyle(1,14);
					bar(0,0,100,100);
				}
				goto accept;
			}
		}
		if(ch=='a')
		{
			if(((y==204||y==264||y==324||y==384||y==444)&&x!=150))
			{
				setcolor(14);
				setfillstyle(1,14);
				fillellipse(x,y,4,7);
				x-=20;
			}
			else if(((y==284||y==344||y==224)&&x==210)||y==344&&x==270)
			{
				if(y==284&&x==210)
				k[1]=door1();
				if(y==344&&x==210)
				k[2]=door5();
				if(y==224&&x==210)
				k[0]=door9();
				if(y==344&&x==270)
				{
					outtextxy(20,20,"Unveil the cryptic clue!");
					tongue(2,x-4,y,-2,0,gs);
					if(strcmp(gs,ans[2])==0)
					n[2]=1;
					setfillstyle(1,14);
					bar(20,20,100,100);

				}
				goto accept;
			}
		}
		if(ch=='w')
		{
			if(((x==150||x==210||x==270||x==330||x==390)&&y!=204))
			{
				setcolor(14);
				setfillstyle(1,14);
				fillellipse(x,y,4,7);
				y-=20;
			}
			else if(((x==230||x==290||x==350)&&y==264)||x==230&&y==324)
			{
				if(x==230&&y==264)
				k[4]=door4();
				if(x==290&&y==264)
				k[8]=door6();
				if(x==350&&y==264)
				k[12]=door10();
				if(x==230&&y==324)
				{
					outtextxy(20,20,"Unveil the cryptic clue !");
					tongue(3,x,y-7,0,-2,gs);
					if(strcmp(gs,ans[3])==0)
					n[3]=1;
					setfillstyle(1,14);
					bar(20,20,100,100);
				}
				goto accept;
			}
		}
		if(ch=='s')
		{
			if(((x==150||x==210||x==270||x==330||x==390)&&y!=444))
			{
				setcolor(14);
				setfillstyle(1,14);
				fillellipse(x,y,4,7);
				y+=20;
			}
			else if(((x==230||x==290||x==170)&&y==384)||x==290&&y==324)
			{
				if(y==384&&x==230)
				k[7]=door2();
				if(y==384&&x==290)
				k[11]=door7();
				if(y==384&&x==170)
				k[3]=door11();
				if(y==324&&x==290)
				{
					outtextxy(20,20,"Unveil the cryptic clue !");
					tongue(0,x,y+7,0,2,gs);
					if(strcmp(gs,ans[0])==0)
					n[0]=1;
					setfillstyle(1,14);
					bar(20,20,100,100);
				}
				goto accept;
			}
			gotoxy(12,10);
		}
	}while(ch!='q');
	getch();
}
