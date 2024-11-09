#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

	int main(){
		char file[50];
		int bpm,opt1,opt2,n=1;
		int high0=0,low0=0,aver,min,sec;
		double ratio;
		int month;
		unsigned int high[20];
		unsigned int low[20];
		
		time_t timep;
        struct tm *p;
        char time1[28];
        time (&timep);
        p=gmtime(&timep);
        if(p->tm_hour>=16) month=2+p->tm_mon;
        else month=1+p->tm_mon;
        sprintf(time1,"%d年%d月%d日",1900+p->tm_year,month,p->tm_mday);
        
		cout<<"请输入您这次爬楼的关键字（如楼栋，楼层等）"<<endl;
		cin>>file;
		cout<<"请输入您这次爬楼的BPM"<<endl;
		cin>>bpm;
		
		FILE *ft=fopen("total.txt","a+");
		
		cout<<"请依次输入爬楼时间与电梯时间，不加小数点，如果已经输入完毕，请输入E"<<endl;
		while(1){
			cout<<"爬楼时间：";
			opt1=scanf("%u",&high[n]);
			if(opt1!=1) break;
			high[n]=(high[n]/100)*60+high[n]%100;
			cout<<"电梯时间：";
			opt2=scanf("%u",&low[n]);
			if(opt2!=1) break;
			low[n]=(low[n]/100)*60+low[n]%100;
			cout<<endl;
			n++;
		}
		n--;
		cout<<"好的，已经全部录入完毕，正在写入文件"<<endl;
		for(int i=1;i<=n;i++){
			high0+=high[i];
			low0+=low[i];
		}
		ratio=(high0*1.0/low0);
		aver=high0/n;
		min=aver/60;
		sec=aver-60*min;
		
		fprintf(ft,"%s\n%s BPM:%d\n",time1,file,bpm);
		fprintf(ft,"您这一次的楼电比为%.2lf 平均爬楼时间为%d分%d秒\n\n",ratio,min,sec);
		
		cout<<"写入已完成，请稍后自行打开total.txt文件进行查看\n"<<endl;
		cout<<"接下来为您展示这一次的相关数据"<<endl;
		printf("您这一次的楼电比为%.2lf 平均爬楼时间为%d分%d秒\n",ratio,min,sec);
		cout<<"您一共爬了"<<n<<"次楼，今天也很努力呢，系统已关闭，期待您明天的到来" <<endl; 
		return 0;
	}
