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
        sprintf(time1,"%d��%d��%d��",1900+p->tm_year,month,p->tm_mday);
        
		cout<<"�������������¥�Ĺؼ��֣���¥����¥��ȣ�"<<endl;
		cin>>file;
		cout<<"�������������¥��BPM"<<endl;
		cin>>bpm;
		
		FILE *ft=fopen("total.txt","a+");
		
		cout<<"������������¥ʱ�������ʱ�䣬����С���㣬����Ѿ�������ϣ�������E"<<endl;
		while(1){
			cout<<"��¥ʱ�䣺";
			opt1=scanf("%u",&high[n]);
			if(opt1!=1) break;
			high[n]=(high[n]/100)*60+high[n]%100;
			cout<<"����ʱ�䣺";
			opt2=scanf("%u",&low[n]);
			if(opt2!=1) break;
			low[n]=(low[n]/100)*60+low[n]%100;
			cout<<endl;
			n++;
		}
		n--;
		cout<<"�õģ��Ѿ�ȫ��¼����ϣ�����д���ļ�"<<endl;
		for(int i=1;i<=n;i++){
			high0+=high[i];
			low0+=low[i];
		}
		ratio=(high0*1.0/low0);
		aver=high0/n;
		min=aver/60;
		sec=aver-60*min;
		
		fprintf(ft,"%s\n%s BPM:%d\n",time1,file,bpm);
		fprintf(ft,"����һ�ε�¥���Ϊ%.2lf ƽ����¥ʱ��Ϊ%d��%d��\n\n",ratio,min,sec);
		
		cout<<"д������ɣ����Ժ����д�total.txt�ļ����в鿴\n"<<endl;
		cout<<"������Ϊ��չʾ��һ�ε��������"<<endl;
		printf("����һ�ε�¥���Ϊ%.2lf ƽ����¥ʱ��Ϊ%d��%d��\n",ratio,min,sec);
		cout<<"��һ������"<<n<<"��¥������Ҳ��Ŭ���أ�ϵͳ�ѹرգ��ڴ�������ĵ���" <<endl; 
		return 0;
	}
