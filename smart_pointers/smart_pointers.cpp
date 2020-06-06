/*
#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
}*/
// ESTE ES EL PROBLEMA QUE SE CREA CON PUNTEROS NORMALES
// cada vez que se entra en fun(), tenemos el problema de que no se borrar los objetos de
// memoria dinámica. Esto provoca que te quedes sin memoria. 
#include <iostream>
using namespace std;
class Rectangle
{
	private:
		int a;
		int b;
	public:
		Rectangle(int a_, int b_) 
		{
			a = a_;
			b = b_;
		};
		int area() { return (a*b); };
		int perimeter() { return (2 * a + 2 * b); };

};

void fun()
{

	shared_ptr<Rectangle> ptr(new Rectangle(10, 5));
	cout << ptr->area() << endl;
	shared_ptr<Rectangle> ptr2;
	ptr2 = ptr;
	// sin problemas porque son shared. Ambos apuntan al mismo objeto. 
	cout << ptr2->area() << endl;
	cout << ptr->area() << endl;
	// numero de punteros que se están usando tipo shared para el mismo objeto 
	cout << ptr.use_count() << endl;


	/*
	// se menciona la clase que quiere apuntar, y despues del new se crea el objeto. 
	unique_ptr<Rectangle> p1(new Rectangle(10,5));
	cout << p1->area();
	cout << p1->perimeter();
	unique_ptr<Rectangle> p2;
	// como es unique , no se puede tener dos punteros al mismo object! entonces.. asigno a p1 a p2.  
	p2 = move(p1);
	cout << p2->area();
	// o/p: se produce una infracción de lectura, porque p1 apunta a null ahora. 
	cout << p1->area();
	*/
	

};

 
/*
void fun()
{
	Rectangle *ptr = new Rectangle();


	delete ptr; // ESTO SI NO ESTA HAY MEMORY LEAK!!
};
*/

using namespace std;
int main()
{

	fun();
	return 0;
}