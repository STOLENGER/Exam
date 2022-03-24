#include <iostream>

class A
{
    int x;
public:
    A()

    {}

    A (const A& other)
    {
        this->x=other.x;
    }
    void show()
    {
        std::cout<<"oooo"<<std::endl;
    }
    A& operator=(const A& other )
    {
        if (this==&other)
            return *this;
        this->x=other.x;
        return *this;

    }

};
class B
        : public A
{

    int y;
public:
    B()
    {
    }
    B (const B& other1)
    : A(other1)
    {
        this->y=other1.y;

    }
    B& operator=(const B& other )
    {
        if (this==&other)
            return *this;
        A::operator=(other);
        this->y=other.y;

        return *this;

    }
};

int main() {
  int c=2;
  auto f1=[=]( const int b )
  {
      return b%c==0 ;
  };
  f1(2);
    return 0;
}
