#include<iostream>
#include <string>
using namespace std;
struct Hero{
	string name;
	int age;
	string sex;
};
int main(){
	struct Hero heroArray[3]={
	{"������",19,"��"},
	 {"����",19,"��"},
	 {"��ʥ˶",18,"��"},
	};
	int len=sizeof(heroArray)/sizeof(heroArray[0]);
	for(int i=0;i<len;i++){
		cout<<"����"<<heroArray[i].name<<"����"<<heroArray[i].age
		<<"�Ա�"<<heroArray[i].sex<<endl; 
	} 
	system("pause");
	return 0;
}
