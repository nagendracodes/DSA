#include<iostream>
using namespace std;
class Array
{
private:
    int capacity;
    int lastindex;
    int *ptr;
protected:
    void doubleArray()
    {
        int *temp;
        temp=new int[capacity*2];
        for(int i=0;i<lastindex+1;i++)
        temp[i]=ptr[i];
        delete []ptr;
        ptr=temp;
        capacity*=2;
    }
    void halfArray()
    {
        int *temp;
        temp=new int[capacity/2];
        for(int i=0;i<lastindex+1;i++)
        temp[i]=ptr[i];
        delete []ptr;
        ptr=temp;
        capacity/=2;
    }
public:
    Array();
    void createArray(int cap);
    void append(int data);
    void insert(int index,int data);
    void del(int index);
    int search(int data);
    int getdata(int index);
    int count();
    void edit(int index,int newdata);
    void view();
    ~Array();
};
Array::Array()
{
    capacity=0;
    lastindex=-1;
    ptr=NULL;
}
void Array::createArray(int cap)
{
    capacity=cap;
    lastindex=-1;
    ptr=new int[cap];
}
void Array::append(int data)
{
    if(lastindex==capacity-1)
        doubleArray();
            ++lastindex;
            ptr[lastindex]=data;
    
}
void Array::insert(int index,int data)
{
    if(index>lastindex+1||index<0)
        cout<<"insertion is not possible";
        
    else
    {
        if(lastindex+1==capacity)
            doubleArray();
        for(int i=0;i<=lastindex-index;i++)
            ptr[lastindex+1-i]=ptr[lastindex-i];
        ptr[index]=data;
        lastindex++;
    }
}
void Array::del(int index)
{
    if(index<0||index>lastindex)
    printf("deletion is not possible");
    else{
        
    for(int i=0;i<=lastindex-1-index;i++)
        ptr[index+i]=ptr[index+1+i];
        lastindex--;
        if(capacity/2==lastindex+1)
        halfArray();
    }
}
int Array::search(int data)
{
    for(int i=0;i<=lastindex;i++)
        if(ptr[i]==data)
            return i;
            return -1;
}
int Array::getdata(int index)
{
    return ptr[index];
}
int Array::count()
{
    return lastindex+1;
}
void Array::edit(int index,int newdata)
{
    ptr[index]=newdata;
}
void Array::view()
{
    for(int i=0;i<=lastindex;i++)
        cout<<ptr[i]<<" ";
        cout<<"\n";
}
Array::~Array()
{
    delete []ptr;
}
int main()
{
    Array A;
    A.createArray(5);
    A.insert(0,1);
    A.insert(1,2);
    A.insert(2,3);
    A.append(4);
    A.append(5);
    A.insert(5,6);
    A.view();
    A.del(1);
    A.view();
    int s=A.search(1);
    printf("%d\n",s);
    int data=A.getdata(2);
    printf("%d\n",data);
    int c=A.count();
    printf("%d\n",c);
    A.edit(2,6);
    A.view();
    return 0;
}
