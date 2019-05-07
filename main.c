#include "cmap.h"
int main()
{
	void* m=createMap();
	call_insert(m,1234,"123ef");
	call_insert(m,3,4);
	printf("%s",call_at(m,1234));
	show(m);
	return 0;
}
