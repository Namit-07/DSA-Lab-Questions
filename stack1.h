#include <iomanip>
using namespace std;

struct _stack {
    int *s;
    int size;
    int tos;
};

class stack {
    _stack sta;

    public:
    stack1(); // default constructor
    stack1(int); // parameterized constructor
    bool isfull(); // function
    bool isempty();
    void push(int); 
    int pop(); 
    void display(); 
    ~stack1(); // destructor
};
