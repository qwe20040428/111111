#include <iostream>
#include <string>
#define Max 1000
using namespace std;
struct Student
{
	string Name;//学生姓名 
	int Age;//年龄
	string Id;//学号
	string Major;//专业
	float Score[3];//成绩
	float Total;//总分
	float Ave;//平均分
};
struct Manage
{
	Student stuArray[Max];//保存的学生总数
	int num;//学生数量
};
//菜单
void Menu()
{
	cout << "============================================" << endl;
	cout << "*************  1.添加学生信息  *************" << endl;
	cout << "*************  2.输出学生信息  *************" << endl;
	cout << "*************  3.删除学生信息  *************" << endl;
	cout << "*************  4.查找学生信息  *************" << endl;
	cout << "*************  5.修改学生信息  *************" << endl;
	cout << "*************  6.清空学生信息  *************" << endl;
	cout << "***************  0.退出菜单  ***************" << endl;
	cout << "============================================" << endl;
}

//添加学生函数
void AddStudent(Manage* Stu)
{
	//姓名
	string name;
	cout << "请输入姓名: " << endl;
	cin >> name;
	Stu->stuArray[Stu->num].Name = name;

	//年龄
	int age;
	cout << "请输入年龄: " << endl;
	cin >> age;
	Stu->stuArray[Stu->num].Age = age;

	// 学号
	string num;
	cout << "请输入学号: " << endl;
	cin >> num;
	Stu->stuArray[Stu->num].Id = num;

	// 专业
	string major;
	cout << "请输入专业: " << endl;
	cin >> major;
	Stu->stuArray[Stu->num].Major = major;

	//数学成绩
	float score1;
	cout << "请输入数学成绩: " << endl;
	cin >> score1;
	Stu->stuArray[Stu->num].Score[0] = score1;

	//英语成绩
	float score2;
	cout << "请输入英语成绩: " << endl;
	cin >> score2;
	Stu->stuArray[Stu->num].Score[1] = score2;

	//物理成绩
	float score3;
	cout << "请输入物理成绩: " << endl;
	cin >> score3;
	Stu->stuArray[Stu->num].Score[2] = score3;

	//更新人数
	Stu->num++;
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
}

//输出学生信息
void ShowStudent(Manage *stu)
{
	float Total = 0.0, Ave = 0.0;
	if (stu->num == 0)
	{
		cout << "目前没有学生信息" << endl;
	}
	else
	{
		for (int i = 0; i < stu->num; i++)
		{
			Total= stu->stuArray[i].Score[0] + stu->stuArray[i].Score[1] + stu->stuArray[i].Score[2];
			Ave= (stu->stuArray[i].Score[0] + stu->stuArray[i].Score[1] + stu->stuArray[i].Score[2]) / 3;
			cout << "姓名： " << stu->stuArray[i].Name << '\t'
			     << "年龄： " << stu->stuArray[i].Age << '\t'
			     << "学号： " << stu->stuArray[i].Id << '\t'
			     << "专业： " << stu->stuArray[i].Major << '\t'
			     << "数学成绩： " << stu->stuArray[i].Score[0] << '\t'
		         << "英语成绩： " << stu->stuArray[i].Score[1] << '\t'
			     << "物理成绩： " << stu->stuArray[i].Score[2] << '\t'
			     << "总分： " << Total <<'\t'
			     << "平均分： " << Ave << endl;
		} 
		cout << endl;
	}
	system("pause");
	system("cls");
}

//检测学生是否存在
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

//删除学生信息
void DeleteStudent(Manage *Stu)
{
	string name;
	cout << "输入所要删除学生的姓名： " << endl;
	cin >> name;
	int ret = Exist(Stu, name);  
	if (ret != -1)
	{
		for (int i = ret; i < Stu->num; i++)
		{
			Stu->stuArray[i] = Stu->stuArray[i + 1];
		}

		Stu->num--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找学生信息
void FindStudent(Manage* Stu)
{
	cout << "请输入你要查找的联系人： " << endl;
	string name;
	float Total = 0.0, Ave = 0.0;
	cin >> name;
	int ret = Exist(Stu, name);
	Total = Stu->stuArray[ret].Score[0] + Stu->stuArray[ret].Score[1] + Stu->stuArray[ret].Score[2];
	Ave = (Stu->stuArray[ret].Score[0] + Stu->stuArray[ret].Score[1] + Stu->stuArray[ret].Score[2]) / 3;
	if (ret != -1)
	{
		cout << "姓名： " << Stu->stuArray[ret].Name << '\t'
			<< "年龄： " << Stu->stuArray[ret].Age << '\t'
			<< "学号： " << Stu->stuArray[ret].Id << '\t'
			<< "专业： " << Stu->stuArray[ret].Major << '\t'
			<< "数学成绩： " << Stu->stuArray[ret].Score[0] << '\t'
			<< "英语成绩： " << Stu->stuArray[ret].Score[1] << '\t'
			<< "物理成绩： " << Stu->stuArray[ret].Score[2] << '\t'
			<< "总分： " << Total << '\t'
			<< "平均分： " << Ave << endl;
	}
	else
	{
		cout << "未找到该学生信息" << endl;
	}
	system("pause");
	system("cls");
}

//修改学生信息
void ModifyStudent(Manage* Stu)
{
	cout << "请输入你要修改的联系人： " << endl;
	string name;
	cin >> name;
	int ret = Exist(Stu, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入修改后的姓名： " << endl;
		cin >> name;
		Stu->stuArray[ret].Name = name;

		int age;
		cout << "请输入修改后的年龄： " << endl;
		cin >> age;
		Stu->stuArray[ret].Age = age;

		string id;
		cout << "请输入修改后的学号： " << endl;
		cin >> id;
		Stu->stuArray[ret].Id = id;

		string major;
		cout << "请输入修改后的专业： " << endl;
		cin >> major;
		Stu->stuArray[ret].Major = major;

		float score[3];
		cout << "请输入修改后的数学成绩： " << endl;
		cin >> score[0];
		Stu->stuArray[ret].Score[0] = score[0];

		cout << "请输入修改后的英语成绩： " << endl;
		cin >> score[1];
		Stu->stuArray[ret].Score[1] = score[1];

		cout << "请输入修改后的物理成绩： " << endl;
		cin >> score[2];
		Stu->stuArray[ret].Score[2] = score[2];
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//清空学生信息
void CleanStudent(Manage* Stu)
{
	Stu->num = 0;
	cout << "已清空学生信息" << endl;
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
			cout << "欢迎下次使用！" << endl;
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

