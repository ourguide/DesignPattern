// 21_������
#include <iostream>
#include <vector>
using namespace std;

// 1. ����: �ϳ��� �̺�Ʈ�� ���� ��ü�� ����
// 2. Subject�� data�� �����ϴ� ���
//   1) Subject�� Observer���� ���� - push
//   2) Observer�� Subject�� ���� �������� ��� - pull

struct IObserver
{
	virtual void OnUpdate(void* data) = 0;
	virtual ~IObserver() {}
};

// ������ ���
// ��� Table�� ������ Ư¡(������ ������ �⺻����)�� �׻� �����ϴ�.
// �θ� Ŭ������ �̾Ƴ���.
// - �޶����� ���� �ڽ� Ŭ������ ���� ����, �������� ���� �θ� Ŭ������ ���� ��������.
class Subject
{
	vector<IObserver*> v;
public:
	void Attach(IObserver* p) { v.push_back(p); }
	void Detach(IObserver* p) {}

	// !!
	void Notify(void *data)
	{
		for (int i = 0; i < v.size(); ++i)
			v[i]->OnUpdate(data);
	}
};

class Table: public Subject
{
	int data[5];
public:
	Table() { memset(data, 0, sizeof(data)); }

	void Edit()
	{
		while (1)
		{
			int index;
			cout << "index: "; cin >> index;
			cout << "data: "; cin >> data[index];

			Notify(data);
		}
	}
};

class BarGarch : public IObserver
{
public:
	void OnUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "*************** Bar Graph *************" << endl;
		for (int i = 0; i < 5; ++i)
			cout << i << ": " << data[i] << endl;
	}
};

class PieGraph : public IObserver
{
public:
	void OnUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "*************** Pie Graph *************" << endl;
		for (int i = 0; i < 5; ++i)
			cout << i << ": " << data[i] << endl;
	}
};

int main()
{
	Table table;
	PieGraph pg;
	BarGarch bg;

	table.Attach(&pg);
	table.Attach(&bg);

	table.Edit();
}