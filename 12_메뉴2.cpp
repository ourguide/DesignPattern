// 12_메뉴2
// Composite Pattern 실습
#include <string>
#include <iostream>
using namespace std;

// Item
// - File, Folder
// - getSize

int main()
{
	// 아래 코드가 실행되도록, Folder, File 클래스를 만들어 보세요
	Folder* fol1 = new Folder("C");
	Folder* fol2 = new Filder("A");
	
	File* f1 = new File("a.txt", 10); // 이름, 크기
	File* f2 = new File("b.txt", 20); 

	//  관계 설정
	fol2->addItem(f1);
	fol1->addItem(f2);
	fol1->addItem(fol2);

	cout << f2->getSize() << endl;
	cout << fol2->getSize() << endl;
	cout << fol1->getSize() << endl;

}