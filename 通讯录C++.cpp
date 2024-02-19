#include <include.h>
#include <string.h>
#define MAX 1000
using namespace std;
//联系人结构体定义 
struct person{
	string m_name;
	int m_age;
	int m_sex;
	string m_phone;
	string m_addr;
};
//通讯录结构体定义 
struct addressbooks{
	struct person personarry[MAX]; 
	int m_size;
};
//显示页面 
void showmenu(){
	printf("********************"); 
    printf("****1.添加联系人****"); 
	printf("****2.显示联系人****"); 
	printf("****3.删除联系人****"); 
	printf("****4.查找联系人****"); 
	printf("****5.修改联系人****"); 
	printf("****6.清空联系人****"); 
	printf("****0.退出通讯录****"); 
	printf("********************"); 
}
//添加联系人 
void addperson(addressbooks*abs){
	if(abs->m_size==MAX){
		printf("通讯录已满");
	}else{
		string name;
		printf("请输入姓名："); 
		cin>>name;
		abs->personarry[abs->m_size].m_name=name;
		cout<<"请输入性别："<<endl;
		int sex=0;
	    cout<<"1---男"<<endl;
		cout<<"2---女"<<endl; 
		while(true){
			cin>>sex;
			if(sex==1||sex==2){
		abs->personarry[abs->m_size].m_sex=sex;
				break;
			}
			else{
				cout<<"请重新输入"<<endl; 
			}
		} 
		int age=0;
		cout<<"请输入年龄"<<endl; 
		cin>>age;
		abs->personarry[abs->m_size].m_age=age;
		cout<<"请输入联系电话"<<endl;
		string phone;
		cin>>phone;
		abs->personarry[abs->m_size].m_phone=phone;
		cout<<"请输入地址"<<endl;
		string address;
		cin>>address;
		abs->personarry[abs->m_size].m_addr=address;
		abs->m_size++;
		cout<<"添加成功"<<endl;
		system("pause");
		system("cls");
	}
}
//
void showperson(addressbooks*abs){
	if(abs->m_size==0){
		cout<<"当前记录为空"<<endl; 
	}
	else{
		for(int i=0;i<abs->m_size;i++){
		cout<<"姓名："<<abs->personarry[i].m_name<<"\t";
		cout<<"性别："<<(abs->personarry[i].m_sex==1?"男":"女")<<"\t";
		cout<<"年龄："<<abs->personarry[i].m_age<<"\t";
	 	cout<<"电话："<<abs->personarry[i].m_phone<<"\t";
	 	cout<<"住址："<<abs->personarry[i].m_addr<<endl;
	}
	system("pause");
		system("cls");
  }
}
//搜索联系人
int isexist(addressbooks*abs,string name){
	for(int i=0;i<abs->m_size;i++){
    if(abs->personarry[i].m_name==name){
    	return i;
	}
	}
	return -1;
}
//删除联系人 
void deleteperson(addressbooks*abs){
	cout<<"请输入你要删除的联系人"<<endl;
	string name;
	cin>>name;
	int ret=isexist (abs,name);
	if(ret!=-1){
		for(int i=ret;i<abs->m_size;i++){
			abs->personarry[i]=abs->personarry[i+1];
		} 
		abs->m_size--;
		cout<<"删除成功"<<endl; 
	}
	else{
		cout<<"查无此人"<<endl; 
	}
	system("pause");
	system("cls");
} 
//查找联系人 
void  findperson(addressbooks*abs){
	cout<<"请输入你要查找的联系人"<<endl;
	string name;
	cin>>name;
	int ret=isexist(abs,name);
	if(ret!=-1){
	cout<<"姓名："<<abs->personarry[ret].m_name<<"\t";
	cout<<"性别："<<(abs->personarry[ret].m_sex==1?"男":"女")<<"\t";
	cout<<"年龄："<<abs->personarry[ret].m_age<<"\t";	 	
	cout<<"电话："<<abs->personarry[ret].m_phone<<"\t";
	cout<<"住址："<<abs->personarry[ret].m_addr<<endl;	
	} 
	else{
		cout<<"查无此人"<<endl; 
	}
	system("pause");
	system("cls");
} 
//修改联系人 
void changeperson(addressbooks*abs){
	cout<<"请输入你要修改的联系人"<<endl;
	string name;
	cin>>name;
	int ret=isexist(abs,name);
	if(ret!=-1){
	string name;
		cout<<"请输入姓名："<<endl;
		cin>>name;
		abs->personarry[abs->m_size].m_name=name;
		cout<<"请输入性别："<<endl;
		int sex=0;
	    cout<<"1---男"<<endl;
		cout<<"2---女"<<endl; 
		while(true){
			cin>>sex;
			if(sex==1||sex==2){
		abs->personarry[abs->m_size].m_sex=sex;
				break;
			}
			else{
				cout<<"请重新输入"<<endl; 
			}
		} 
		int age=0;
		cout<<"请输入年龄"<<endl; 
		cin>>age;
		abs->personarry[abs->m_size].m_age=age;
		cout<<"请输入联系电话"<<endl;
		string phone;
		cin>>phone;
		abs->personarry[abs->m_size].m_phone=phone;
		cout<<"请输入地址"<<endl;
		string address;
		cin>>address;
		abs->personarry[abs->m_size].m_addr=address;
		abs->m_size++;
		cout<<"修改成功"<<endl;
		system("pause");
		system("cls");
	
}
	else{
		cout<<"查无此人"<<endl; 
	}
	system("pause");
	system("cls");
} 
// 
void clearallperson(addressbooks*abs){
	abs->m_size=0;
	cout<<"通讯录已清空"<<endl;
	system("pause");
	system("cls"); 
	}
//
int main(){
	int select=0;
	addressbooks abs;
	abs.m_size=0;
	while(true){
		showmenu();
		cin>>select;
		switch(select){	
		case 1:
			addperson(&abs);
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
			deleteperson(&abs);
			break;
		case 4:
			findperson(&abs); 
			break;
		case 5:
			changeperson(&abs);
			break;
		case 6:
			cout<<"是否清空联系人"<<endl;
			cout<<"1--是"<<endl;
			cout<<"2--否"<<endl;
			int sure;
			cin>>sure;
			if(sure==1){
			clearallperson(&abs); 
			break;}
			else
			break;
		case 0:
		cout<<"欢迎下次使用"<<endl;
		system("pause");
		return 0; 
			default:
			break;
		} N
	}
    system("pause");
    return 0;
} 
