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
	{"ºú¼ÒÏé",19,"ÄÐ"},
	 {"³ÂÑó",19,"ÄÐ"},
	 {"¶­Ê¥Ë¶",18,"ÄÐ"},
	};
	int len=sizeof(heroArray)/sizeof(heroArray[0]);
	for(int i=0;i<len;i++){
		cout<<"ÐÕÃû"<<heroArray[i].name<<"ÄêÁä"<<heroArray[i].age
		<<"ÐÔ±ð"<<heroArray[i].sex<<endl; 
	} 
	system("pause");
	return 0;
}
