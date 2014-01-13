#include <taq.h>


int IsQuote(const char *NomeFile)
{
	int q=0, t=0, Type;
	const char quote[10][10]={"SYMBOL","DATE","TIME","BID","OFR","BIDSIZ","OFRSIZ","MODE","EX","MMID"};
	const char trade[9][10]={"SYMBOL","DATE","TIME","PRICE","G127","CORR","COND","EX","SIZE"};
	char head[10];
	igzstream inq(NomeFile);
	if(!inq){
		cout << "Unable to open the file "<< NomeFile << "\n";
		return 3;
	}
	inq >> head;
	while((!strcmp(head,quote[q])) && (q <= 9)){
		q++;
		inq >> head;
	}
	inq.close();
	if(q==10) Type=0;
	else{
		igzstream intr(NomeFile);
		intr >> head;
		while((!strcmp(head,trade[t])) && (t <= 8)){
			t++;
			intr >> head;
		}
		intr.close();
		if(t==9) Type=1;
		else Type=2;
	}
	return Type;
}
