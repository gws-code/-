#include <include.h>
#include <string.h>
#define MAX 1000
using namespace std;
//��ϵ�˽ṹ�嶨�� 
struct person{
	string m_name;
	int m_age;
	int m_sex;
	string m_phone;
	string m_addr;
};
//ͨѶ¼�ṹ�嶨�� 
struct addressbooks{
	struct person personarry[MAX]; 
	int m_size;
};
//��ʾҳ�� 
void showmenu(){
	printf("********************"); 
    printf("****1.�����ϵ��****"); 
	printf("****2.��ʾ��ϵ��****"); 
	printf("****3.ɾ����ϵ��****"); 
	printf("****4.������ϵ��****"); 
	printf("****5.�޸���ϵ��****"); 
	printf("****6.�����ϵ��****"); 
	printf("****0.�˳�ͨѶ¼****"); 
	printf("********************"); 
}
//�����ϵ�� 
void addperson(addressbooks*abs){
	if(abs->m_size==MAX){
		printf("ͨѶ¼����");
	}else{
		string name;
		printf("������������"); 
		cin>>name;
		abs->personarry[abs->m_size].m_name=name;
		cout<<"�������Ա�"<<endl;
		int sex=0;
	    cout<<"1---��"<<endl;
		cout<<"2---Ů"<<endl; 
		while(true){
			cin>>sex;
			if(sex==1||sex==2){
		abs->personarry[abs->m_size].m_sex=sex;
				break;
			}
			else{
				cout<<"����������"<<endl; 
			}
		} 
		int age=0;
		cout<<"����������"<<endl; 
		cin>>age;
		abs->personarry[abs->m_size].m_age=age;
		cout<<"��������ϵ�绰"<<endl;
		string phone;
		cin>>phone;
		abs->personarry[abs->m_size].m_phone=phone;
		cout<<"�������ַ"<<endl;
		string address;
		cin>>address;
		abs->personarry[abs->m_size].m_addr=address;
		abs->m_size++;
		cout<<"��ӳɹ�"<<endl;
		system("pause");
		system("cls");
	}
}
//
void showperson(addressbooks*abs){
	if(abs->m_size==0){
		cout<<"��ǰ��¼Ϊ��"<<endl; 
	}
	else{
		for(int i=0;i<abs->m_size;i++){
		cout<<"������"<<abs->personarry[i].m_name<<"\t";
		cout<<"�Ա�"<<(abs->personarry[i].m_sex==1?"��":"Ů")<<"\t";
		cout<<"���䣺"<<abs->personarry[i].m_age<<"\t";
	 	cout<<"�绰��"<<abs->personarry[i].m_phone<<"\t";
	 	cout<<"סַ��"<<abs->personarry[i].m_addr<<endl;
	}
	system("pause");
		system("cls");
  }
}
//������ϵ��
int isexist(addressbooks*abs,string name){
	for(int i=0;i<abs->m_size;i++){
    if(abs->personarry[i].m_name==name){
    	return i;
	}
	}
	return -1;
}
//ɾ����ϵ�� 
void deleteperson(addressbooks*abs){
	cout<<"��������Ҫɾ������ϵ��"<<endl;
	string name;
	cin>>name;
	int ret=isexist (abs,name);
	if(ret!=-1){
		for(int i=ret;i<abs->m_size;i++){
			abs->personarry[i]=abs->personarry[i+1];
		} 
		abs->m_size--;
		cout<<"ɾ���ɹ�"<<endl; 
	}
	else{
		cout<<"���޴���"<<endl; 
	}
	system("pause");
	system("cls");
} 
//������ϵ�� 
void  findperson(addressbooks*abs){
	cout<<"��������Ҫ���ҵ���ϵ��"<<endl;
	string name;
	cin>>name;
	int ret=isexist(abs,name);
	if(ret!=-1){
	cout<<"������"<<abs->personarry[ret].m_name<<"\t";
	cout<<"�Ա�"<<(abs->personarry[ret].m_sex==1?"��":"Ů")<<"\t";
	cout<<"���䣺"<<abs->personarry[ret].m_age<<"\t";	 	
	cout<<"�绰��"<<abs->personarry[ret].m_phone<<"\t";
	cout<<"סַ��"<<abs->personarry[ret].m_addr<<endl;	
	} 
	else{
		cout<<"���޴���"<<endl; 
	}
	system("pause");
	system("cls");
} 
//�޸���ϵ�� 
void changeperson(addressbooks*abs){
	cout<<"��������Ҫ�޸ĵ���ϵ��"<<endl;
	string name;
	cin>>name;
	int ret=isexist(abs,name);
	if(ret!=-1){
	string name;
		cout<<"������������"<<endl;
		cin>>name;
		abs->personarry[abs->m_size].m_name=name;
		cout<<"�������Ա�"<<endl;
		int sex=0;
	    cout<<"1---��"<<endl;
		cout<<"2---Ů"<<endl; 
		while(true){
			cin>>sex;
			if(sex==1||sex==2){
		abs->personarry[abs->m_size].m_sex=sex;
				break;
			}
			else{
				cout<<"����������"<<endl; 
			}
		} 
		int age=0;
		cout<<"����������"<<endl; 
		cin>>age;
		abs->personarry[abs->m_size].m_age=age;
		cout<<"��������ϵ�绰"<<endl;
		string phone;
		cin>>phone;
		abs->personarry[abs->m_size].m_phone=phone;
		cout<<"�������ַ"<<endl;
		string address;
		cin>>address;
		abs->personarry[abs->m_size].m_addr=address;
		abs->m_size++;
		cout<<"�޸ĳɹ�"<<endl;
		system("pause");
		system("cls");
	
}
	else{
		cout<<"���޴���"<<endl; 
	}
	system("pause");
	system("cls");
} 
// 
void clearallperson(addressbooks*abs){
	abs->m_size=0;
	cout<<"ͨѶ¼�����"<<endl;
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
			cout<<"�Ƿ������ϵ��"<<endl;
			cout<<"1--��"<<endl;
			cout<<"2--��"<<endl;
			int sure;
			cin>>sure;
			if(sure==1){
			clearallperson(&abs); 
			break;}
			else
			break;
		case 0:
		cout<<"��ӭ�´�ʹ��"<<endl;
		system("pause");
		return 0; 
			default:
			break;
		} N
	}
    system("pause");
    return 0;
} 
