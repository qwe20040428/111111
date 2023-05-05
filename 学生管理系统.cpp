#include <iostream>
#include <string>
#define Max 1000
using namespace std;
struct Student
{
	string Name;//ѧ������ 
	int Age;//����
	string Id;//ѧ��
	string Major;//רҵ
	float Score[3];//�ɼ�
	float Total;//�ܷ�
	float Ave;//ƽ����
};
struct Manage
{
	Student stuArray[Max];//�����ѧ������
	int num;//ѧ������
};
//�˵�
void Menu()
{
	cout << "============================================" << endl;
	cout << "*************  1.���ѧ����Ϣ  *************" << endl;
	cout << "*************  2.���ѧ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ��ѧ����Ϣ  *************" << endl;
	cout << "*************  4.����ѧ����Ϣ  *************" << endl;
	cout << "*************  5.�޸�ѧ����Ϣ  *************" << endl;
	cout << "*************  6.���ѧ����Ϣ  *************" << endl;
	cout << "***************  0.�˳��˵�  ***************" << endl;
	cout << "============================================" << endl;
}

//���ѧ������
void AddStudent(Manage* Stu)
{
	//����
	string name;
	cout << "����������: " << endl;
	cin >> name;
	Stu->stuArray[Stu->num].Name = name;

	//����
	int age;
	cout << "����������: " << endl;
	cin >> age;
	Stu->stuArray[Stu->num].Age = age;

	// ѧ��
	string num;
	cout << "������ѧ��: " << endl;
	cin >> num;
	Stu->stuArray[Stu->num].Id = num;

	// רҵ
	string major;
	cout << "������רҵ: " << endl;
	cin >> major;
	Stu->stuArray[Stu->num].Major = major;

	//��ѧ�ɼ�
	float score1;
	cout << "��������ѧ�ɼ�: " << endl;
	cin >> score1;
	Stu->stuArray[Stu->num].Score[0] = score1;

	//Ӣ��ɼ�
	float score2;
	cout << "������Ӣ��ɼ�: " << endl;
	cin >> score2;
	Stu->stuArray[Stu->num].Score[1] = score2;

	//����ɼ�
	float score3;
	cout << "����������ɼ�: " << endl;
	cin >> score3;
	Stu->stuArray[Stu->num].Score[2] = score3;

	//��������
	Stu->num++;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
}

//���ѧ����Ϣ
void ShowStudent(Manage *stu)
{
	float Total = 0.0, Ave = 0.0;
	if (stu->num == 0)
	{
		cout << "Ŀǰû��ѧ����Ϣ" << endl;
	}
	else
	{
		for (int i = 0; i < stu->num; i++)
		{
			Total= stu->stuArray[i].Score[0] + stu->stuArray[i].Score[1] + stu->stuArray[i].Score[2];
			Ave= (stu->stuArray[i].Score[0] + stu->stuArray[i].Score[1] + stu->stuArray[i].Score[2]) / 3;
			cout << "������ " << stu->stuArray[i].Name << '\t'
			     << "���䣺 " << stu->stuArray[i].Age << '\t'
			     << "ѧ�ţ� " << stu->stuArray[i].Id << '\t'
			     << "רҵ�� " << stu->stuArray[i].Major << '\t'
			     << "��ѧ�ɼ��� " << stu->stuArray[i].Score[0] << '\t'
		         << "Ӣ��ɼ��� " << stu->stuArray[i].Score[1] << '\t'
			     << "����ɼ��� " << stu->stuArray[i].Score[2] << '\t'
			     << "�ܷ֣� " << Total <<'\t'
			     << "ƽ���֣� " << Ave << endl;
		} 
		cout << endl;
	}
	system("pause");
	system("cls");
}

//���ѧ���Ƿ����
int Exist(Manage* Stu, string name)
{
	for (int i = 0; i < Stu->num; i++)
	{
		if (Stu->stuArray[i].Name == name)
		{
			return i;
		}
	}
	return -1;
}

//ɾ��ѧ����Ϣ
void DeleteStudent(Manage *Stu)
{
	string name;
	cout << "������Ҫɾ��ѧ���������� " << endl;
	cin >> name;
	int ret = Exist(Stu, name);  
	if (ret != -1)
	{
		for (int i = ret; i < Stu->num; i++)
		{
			Stu->stuArray[i] = Stu->stuArray[i + 1];
		}

		Stu->num--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//����ѧ����Ϣ
void FindStudent(Manage* Stu)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ� " << endl;
	string name;
	float Total = 0.0, Ave = 0.0;
	cin >> name;
	int ret = Exist(Stu, name);
	Total = Stu->stuArray[ret].Score[0] + Stu->stuArray[ret].Score[1] + Stu->stuArray[ret].Score[2];
	Ave = (Stu->stuArray[ret].Score[0] + Stu->stuArray[ret].Score[1] + Stu->stuArray[ret].Score[2]) / 3;
	if (ret != -1)
	{
		cout << "������ " << Stu->stuArray[ret].Name << '\t'
			<< "���䣺 " << Stu->stuArray[ret].Age << '\t'
			<< "ѧ�ţ� " << Stu->stuArray[ret].Id << '\t'
			<< "רҵ�� " << Stu->stuArray[ret].Major << '\t'
			<< "��ѧ�ɼ��� " << Stu->stuArray[ret].Score[0] << '\t'
			<< "Ӣ��ɼ��� " << Stu->stuArray[ret].Score[1] << '\t'
			<< "����ɼ��� " << Stu->stuArray[ret].Score[2] << '\t'
			<< "�ܷ֣� " << Total << '\t'
			<< "ƽ���֣� " << Ave << endl;
	}
	else
	{
		cout << "δ�ҵ���ѧ����Ϣ" << endl;
	}
	system("pause");
	system("cls");
}

//�޸�ѧ����Ϣ
void ModifyStudent(Manage* Stu)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ� " << endl;
	string name;
	cin >> name;
	int ret = Exist(Stu, name);
	if (ret != -1)
	{
		string name;
		cout << "�������޸ĺ�������� " << endl;
		cin >> name;
		Stu->stuArray[ret].Name = name;

		int age;
		cout << "�������޸ĺ�����䣺 " << endl;
		cin >> age;
		Stu->stuArray[ret].Age = age;

		string id;
		cout << "�������޸ĺ��ѧ�ţ� " << endl;
		cin >> id;
		Stu->stuArray[ret].Id = id;

		string major;
		cout << "�������޸ĺ��רҵ�� " << endl;
		cin >> major;
		Stu->stuArray[ret].Major = major;

		float score[3];
		cout << "�������޸ĺ����ѧ�ɼ��� " << endl;
		cin >> score[0];
		Stu->stuArray[ret].Score[0] = score[0];

		cout << "�������޸ĺ��Ӣ��ɼ��� " << endl;
		cin >> score[1];
		Stu->stuArray[ret].Score[1] = score[1];

		cout << "�������޸ĺ������ɼ��� " << endl;
		cin >> score[2];
		Stu->stuArray[ret].Score[2] = score[2];
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//���ѧ����Ϣ
void CleanStudent(Manage* Stu)
{
	Stu->num = 0;
	cout << "�����ѧ����Ϣ" << endl;
	system("pause");
	system("cls");
}
int main()
{
	Manage Stu;
	Stu.num = 0;
	int select;
	while (1)
	{
		Menu();

		cin >> select;
		switch (select)
		{
		case 1:
			AddStudent(&Stu);
			break;
		case 2:
			ShowStudent(&Stu);
			break;
		case 3:
			DeleteStudent(&Stu);
			break;
		case 4:
			FindStudent(&Stu);
			break;
		case 5:
			ModifyStudent(&Stu);
			break;
		case 6:
			CleanStudent(&Stu);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

