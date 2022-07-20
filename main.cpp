//https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-c-set-1-introduction/

#include <iostream> 
using namespace std; 
  
class Base { 
public: 
	virtual void show() 
	{ 
	    cout << " In Base \n"; 
	} 
	
	virtual void go() 
	{ 
	    cout << "go In Base \n"; 
	} 
}; 
  
class Derived : public Base { 
public: 
    void show() 
    { 
        cout << "In Derived \n"; 
    } 
}; 

class Derived_from_Derived : public Derived { 
public: 
    void show() 
    { 
        cout << "In Derived from derived \n";
		Derived::show();
    } 
}; 

void func(void){
	printf("func \n");
}
  
int main(void) 
{ 
	//B2

    Base* bp = new Derived; 
    // RUN-TIME POLYMORPHISM 
    bp->show(); 
    Base* bpd = new Derived_from_Derived; 
    // RUN-TIME POLYMORPHISM 
    
    //  void * v = (void * )func;
    //  void (* fptr)() = (void (*)()) v;
    //  fptr();
    
    bpd->show(); 
    //void (**vt)() = *(void (***)  ())bpd; // p* vt@10 in gdb, This is a recommended workaround for those occasions when you need to cast a void* to a function pointer. For example the dlsym() function.
    									// https://stackoverflow.com/questions/18246016/void-vt-void-ptr-a-helper-variable-for-virtual-table-in-c  
    									//https://www.codeproject.com/Tips/90875/Displaying-vtable-when-debugging
    									
    void (**vt)() = *(void (***)  ()) (bpd);
    
    return 0; 
} 
