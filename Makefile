##################### 
#  Makefile 
##################### 
#  the compile options 

CFLAGS = -Wall -std=gnu99 -O2 -pedantic -Wextra -g 
CXXFLAGS = -Wall -std=c++11 -O2 -pedantic -Wextra -g 

SHAREDLIB_LINK_OPTIONS = -shared 
FPIC = -fPIC 

#  the include directory 
INC = -I./ 
target=libcmap.so libcmap.a main main_sdk 
all:$(target) 

%.o:%.cpp 
	$(CXX) $(FPIC) $(CXXFLAGS) -c $^ -o $@ $(INC) 
%.o:%.c 
	$(CC) $(FPIC) $(CFLAGS) -c $^ -o $@ $(INC) 

libcmap.a : cmap.o 
	ar crv $@ $^ 
libcmap.so : cmap.o 
	$(CXX) $(SHAREDLIB_LINK_OPTIONS) $(FPIC) $(LDFLAGS) $^ -o $@ 

main : main.o libcmap.a 
	$(CC) $^ -o $@ -ldl -lstdc++ 

main_sdk : main.o libcmap.so 
	$(CC) $^ -o $@ -ldl -lstdc++ -L./ -lcmap  

clean : 
	rm -rf *.o 
	rm -rf $(target)

