#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
const int width=20;
const int height=20;
int gox[4]={0,1,0,-1};
int goy[4]={1,0,-1,0};
int fx,fy;
map<char,int>a{{'d',0},{'s',1},{'a',2},{'w',3}};
vector<vector<char>>mp(width,vector<char>(height,' '));
struct node
{
    int x,y;
};
vector<node>d(1);
void start()
{
    system("cls");
    d[0].x=3;
    d[0].y=3;
    for(int i=0;i<width;++i) mp[0][i]='#';
    for(int i=1;i<height-1;++i)
    {
        for(int j=0;j<width;++j) if(j==0||j==width-1) mp[i][j]='#';
    }
    for(int i=0;i<width;++i) mp[height-1][i]='#';
    fx=rand()%18+1;
    fy=rand()%18+1;
    mp[fx][fy]='!';
}
void print()
{
	system("cls");
    for(int i=0;i<d.size();++i)
    {
    	if(d[i].x<height&&d[i].y<width) mp[d[i].x][d[i].y]='o';
	}
    for(int i=0;i<height;++i)
    {
        for(int j=0;j<width;++j) cout<<mp[i][j];
        cout<<endl;
    }
    for(int i=0;i<d.size();++i)
    {
    	if(d[i].x<height&&d[i].y<width) mp[d[i].x][d[i].y]=' ';
	}
	for(int i=0;i<width;++i) mp[0][i]='#';
    for(int i=1;i<height-1;++i)
    {
        for(int j=0;j<width;++j) if(j==0||j==width-1) mp[i][j]='#';
    }
    for(int i=0;i<width;++i) mp[height-1][i]='#';
}
void walk(int &eat,int &sta,char inputx)
{
    for(int i=d.size()-1;i>0;--i)
    {
        d[i].x=d[i-1].x;
        d[i].y=d[i-1].y;
    }
    d[0].x+=gox[a[inputx]];
    d[0].y+=goy[a[inputx]];
    if(d[0].x==fx&&d[0].y==fy)
    {
    	eat=1;
    	mp[fx][fy]=' ';
    }
    int flag=1;
    for(int i=0;i<d.size();++i)
    {
    	if((d[i].x==0||d[i].x==19||d[i].y==0||d[i].y==19)&&d.size()>1)
    	{
    		flag=0;
    		break;
		}
	}
	if(flag) sta=1;
    if(d[0].x==0)
    {
    	for(int i=0;i<d.size();++i) d[i].x=19;
    	sta=0;
	}
	else if(d[0].x==19)
	{
		for(int i=0;i<d.size();++i) d[i].x=0;
		sta=0;
	}
	else if(d[0].y==0)
	{
		for(int i=0;i<d.size();++i) d[i].y=19;
		sta=0;
	}
	else if(d[0].y==19)
	{
		for(int i=0;i<d.size();++i) d[i].y=0;
		sta=0;
	}
}
int main()
{
    start();
    print(); 
    int eat=0,life=1,sta=1;
    char inputx;
    cin>>inputx;
    while(life)
    {
        if(eat)
        {
        	fx=rand()%18+1;
        	fy=rand()%18+1;
        	mp[fx][fy]='!';
        	eat=0;
        	print();
        }
        if(kbhit())
		{ 
            fflush(stdin);
			inputx=getchar();
		}
		else Sleep(100);
        walk(eat,sta,inputx);
        if(eat&&life)
        {
		    int x1=0,y1=0;
			if(inputx=='w')
            {
				x1=d[d.size()-1].x+gox[1];
				y1=d[d.size()-1].y+goy[1];
				d.push_back({x1,y1});
            }
			else if(inputx=='s')
			{
        	    x1=d[d.size()-1].x+gox[3];
				y1=d[d.size()-1].y+goy[3];
				d.push_back({x1,y1});
            }
            else if(inputx=='d')
            {
			    x1=d[d.size()-1].x+gox[2];
				y1=d[d.size()-1].y+goy[2];
				d.push_back({x1,y1});
            }
            else
            {
			    x1=d[d.size()-1].x+gox[0];
				y1=d[d.size()-1].y+goy[0];
				d.push_back({x1,y1});
            } 
        }
        print();
        if(d[d.size()-1].x==d[0].x&&d[d.size()-1].y==d[0].y&&d.size()>1&&sta) life=0;
        if(!life)
        {
            cout<<"game over"<<endl;
            break;
        }
    }
    return 0;
}

