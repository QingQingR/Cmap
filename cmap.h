#ifdef __cplusplus
extern "C"{
#endif

void* createMap();
void call_insert(void *M,unsigned int a, char* b);
void show(void *M);
char* call_at(void *M, unsigned int a);
/*class A{
public:
	int a,b;
	int add(int a,int b);
};

int A::add(int a,int b)
{
	return a+b;
}*/

#ifdef __cplusplus
   }
#endif
