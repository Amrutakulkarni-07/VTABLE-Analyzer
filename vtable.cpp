//In this project we are using concept of pointer and explicit type casting 

using namespace std;
#include<iostream>

class Base           //12 bytes
{
    public:
    int x,y;
    virtual void fun()               //1000
    {
        cout<<"base fun\n";
    }
    virtual void gun()                //2000
    {
        cout<<"base gun\n";
    }
    void sun()                        //3000
    {
        cout<<"base sun\n";
    }

};
class Derived:public Base                     //20 bytes
{
    public:
    int i,j;
     void fun()                   //4000
    {
        cout<<"derived fun\n";
    }
    void sun()                              //5000
    {
        cout<<"derived sun\n";
    }
    virtual void run()                   //6000
    {
        cout<<"derived run\n";
    }
    
};

int main()
{

    Base bobj;
    Derived dobj;

    cout<<sizeof(bobj)<<"\n";
    cout<<sizeof(dobj)<<"\n";

    long int *op=(long int*)&dobj;            

    cout<<"base address of dobj is:"<<op<<"\n";  //100
    
    long int *vptr=(long int*)*op;                //400  object first 4 bytes 
    cout<<"address of vtable is:"<<vptr<<"\n";    

    void (*fp)();
    fp=(void(*)())(*vptr);            //derived fun-virtual 1st function from vtable
    fp();
    
    fp=(void(*)())(*(vptr+1));               //base gun- 2nd function from vtable
    fp();

    fp=(void(*)())(*(vptr+2));            //derived run- 3rd function from vtable 
    fp();
                                    
return 0;
}
