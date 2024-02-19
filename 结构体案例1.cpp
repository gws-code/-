#include <iostream>
using namespace std;
#include<string>
#include <ctime>
struct Student{
	string sName;
	int score;
};
struct Teacher{
  string tName;
  struct Student sArray[5];
};

void allocateSpace(struct Teacher tArray[],int len){
	for(int i=0;i<len;i++){
		string nameSeed="ABCDE";
		tArray[i].tName="Teacher_";
		tArray[i].tName+=nameSeed[i];
		//int random=rand()%60 0~59
		//int random=rand()%60+40 40~99
		
			for(int j=0;j<5;j++){
			tArray[i].sArray[j].sName="Student_";
			tArray[i].sArray[j].sName+=nameSeed[j]; 
			int random=rand()%61+40; //40~100;
			tArray[i].sArray[j].score=60;
		}
	}
}
void printfInfo(struct Teacher tArray[], int len){
	for( int i=0;i<len;i++){
		cout<<"老师姓名："<<tArray[i].tName<<endl;
		for(int j=0;j<5;j++){
			cout<<"学生姓名："<<tArray.sArray[j].sName
			    <<"考试分数："<< tArray.sArray[j].score<<endl;
		} 
	}
}
  int main(){
  	 int srand ((unsigned int)time(NULL));
  	struct  Teacher  tArray[3];
  	int len=sizeof(tArray)/sizeof(tArray[0]);
  	allocateSpace(tArray,len);
  	printfInfo(tArray,len);
  }
