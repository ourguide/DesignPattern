// 12_�޴�2
// Composite Pattern �ǽ�
#include <string>
#include <iostream>
using namespace std;

// Item
// - File, Folder
// - getSize

int main()
{
	// �Ʒ� �ڵ尡 ����ǵ���, Folder, File Ŭ������ ����� ������
	Folder* fol1 = new Folder("C");
	Folder* fol2 = new Filder("A");
	
	File* f1 = new File("a.txt", 10); // �̸�, ũ��
	File* f2 = new File("b.txt", 20); 

	//  ���� ����
	fol2->addItem(f1);
	fol1->addItem(f2);
	fol1->addItem(fol2);

	cout << f2->getSize() << endl;
	cout << fol2->getSize() << endl;
	cout << fol1->getSize() << endl;

}