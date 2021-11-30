#include<iostream>
using namespace std;
class complex
    {
        private:
            int a;
            int b;
        public:
            void set_data(int x,int y)
            {
                a=x;
                b=y;
            }
            void show_data()
            {
                cout<<"a="<<a<<endl<<"b="<<b;
            }
    };
int main()
{
    complex c;
    c.set_data(5,6);
    c.show_data();
    return(0);
}
