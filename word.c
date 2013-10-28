#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define M 300

#define sinput "testdata.txt"
#define soutput "WordOutPut.txt"
FILE *file,*fileout;

int used[M],i,j,k,x,maxl,l,y,n,u,t,an,ini[M],len[M],e,start,charused[M],ismin;

char a[M][M],s[M],g[M][M],sum,c[M],dx[]={0,1,-1,0,-1,1,-1,1},dy[]={1,0,0,-1,-1,1,1,-1};




int ising(int x,int y)
{
	return (x>=0&&x<n&&y>=0&&y<n);
}

f(int dx,int dy,int x,int y,char* s)
{
	int i;
	for(i=0;s[i];i++){
		g[x][y]=s[i];
		x+=dx;
		y+=dy;
	}
}


int pd(int dx,int dy,int x,int y,char *s)
{
	int i;
	for(i=0;s[i];i++){
		if(!(g[x][y]==s[i]||!g[x][y])||!ising(x,y)) return 0;
		x+=dx;
		y+=dy;
	}
	return 1;
	
}


main()
{
	file=fopen(sinput,"r");
	fileout=fopen(soutput,"w");
	
	while(fscanf(file,"%s",s)>0){
		t=strlen(s);
		len[an]=t;
		sum+=t;
		
		if(maxl<t) maxl=t;
		
		ini[s[0]]++;
		
		strcpy(a[an++],s);
	}
	
	


		for(i=0;i<an;i++)
		for(j=i+1;j<an;j++) if(len[i]<len[j]){
			strcpy(s,a[i]);
			strcpy(a[i],a[j]);
			strcpy(a[j],s);
			t=len[i];
			len[i]=len[j];
			len[j]=t;
		}
	
	
	
	x=0;
	u=3;
	
	while(1){
			for(i='a';i<='z';i++) if(ini[i]>=u&&!charused[i]){
				c[x++]=i;
				charused[i]=1;
			}
			
			if(x<4) u--;
			else break;
	}
	
	n=maxl;
	
	
	
	while(1){
	
	
	for(i=0;i<n;i++) 
	for(j=0;j<n;j++) g[i][j]=0;
	for(i=0;i<an;i++) used[i]=0;
	
	

	
	


	for(i=0;i<4;i++){
		x=y=0;
		if(i==1) y=n-1;
		else if(i==2) x=n-1;
		else if(i==3){
				x=n-1;
				y=n-1;
			}
		
		
		j=i;
			for(k=0;k<an;k++) if(!used[k]&&pd(dx[j],dy[j],x,y,a[k])&&a[k][0]==c[i]){
				used[k]=1;
				f(dx[j],dy[j],x,y,a[k]);
				break;
			}
	}
	
	
	
	
	
	///four courner
	for(i=0;i<4;i++){
		x=y=0;
		if(i==1) y=n-1;
		else if(i==2) x=n-1;
		else if(i==3){
				x=n-1;
				y=n-1;
			}
		
		
		for(j=0;j<4;j++)
			for(k=0;k<an;k++) if(!used[k]&&pd(dx[j],dy[j],x,y,a[k])&&a[k][0]==c[i]){
				used[k]=1;
				f(dx[j],dy[j],x,y,a[k]);
				break;
			}
	}
	
	
	

		/*
	
	//zhongjian
	
			x=0;
	y=0;
	for(i=0;i<n;i++){
		
		x++;
		y++;
		
		for(j=4;j<6;j++)
			for(k=0;k<an;k++) if(!used[k]&&pd(dx[j],dy[j],x,y,a[k])){
				used[k]=1;
				used[k]=1;
				f(dx[j],dy[j],x,y,a[k]);
				break;
			}
	}                                                                                                                                                                                                                                                                                           
	*/
	
	//sibian
	

	
	x=y=0;
	for(i=0;i<n;i++){

		y++;
		
		j=0;
			for(k=0;k<an;k++) if(!used[k]&&pd(dx[j],dy[j],x,y,a[k])){
				used[k]=1;
				used[k]=1;
				f(dx[j],dy[j],x,y,a[k]);
				break;
			}
	}
	
	
	x=0;
	y=n-1;
	for(i=0;i<n;i++){
		
		x++;
		
		j=1;
			for(k=0;k<an;k++) if(!used[k]&&pd(dx[j],dy[j],x,y,a[k])){
				used[k]=1;
				used[k]=1;
				f(dx[j],dy[j],x,y,a[k]);
				break;
			}
	}
	
	
	x=n-1;
	y=n-1;
	for(i=0;i<n;i++){
		y--;
		
		j=2;
			for(k=0;k<an;k++) if(!used[k]&&pd(dx[j],dy[j],x,y,a[k])){
				used[k]=1;
				used[k]=1;
				f(dx[j],dy[j],x,y,a[k]);
				break;
			}
	}
	
	
	x=n-1;
	y=0;
	for(i=0;i<n;i++){
		
		x--;
		
		j=3;
			for(k=0;k<an;k++) if(!used[k]&&pd(dx[j],dy[j],x,y,a[k])){
				used[k]=1;
				used[k]=1;
				f(dx[j],dy[j],x,y,a[k]);
				break;
			}
	}
	
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	for(l=7;l>=0;l--)
			for(k=0;k<an;k++) if(!used[k]&&pd(dx[l],dy[l],i,j,a[k])){
				used[k]=1;
				f(dx[l],dy[l],i,j,a[k]);
				break;
			}
	
	
	
	
	



	ismin=0;

	for(i=0;i<an;i++) if(!used[i])
		ismin=1;
	
	if(ismin) n++;
	
	
	
	else{
		srand(100);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)  if(g[i][j]) fprintf(fileout,"%c",g[i][j]); else fprintf(fileout,"%c",rand()%26+'a'); 
			fputs("\n",fileout);
		}
		return 0;
	}
	
}
}
