#include "CkStore.h"
#include "CKPizza.h"
#include "MyPizza.h"

auto main() -> void
{
	Ckstore* ck = new Ckstore();

	Pizza * pizza = ck->orderPizza( new CKPizza() );
	cout << pizza->getName() << endl;
	cout << endl;
	cout << endl;
	Pizza * my = ck->orderPizza( new MyPizza() );
	cout << my->getName() << endl;

	getchar();
}