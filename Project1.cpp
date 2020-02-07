#include <iostream>
using namespace std;

//Ira Porchia
//Social Issues Project

const int MAX = 5;
int socialIssue, linkNum, again;
/////////////////Node Classes///////////////////////////
class node1
{
    friend class ListL;
private:
    string _data1;
    node1 *_next1;
    node1(string data1);
};

class node2
{
    friend class ListL;
private:
    string _data2;
    node2 *_next2;
    node2(string data2);
};

class node3
{
    friend class ListL;
private:
    string _data3;
    node3 *_next3;
    node3(string data3);
};
/////////////////Linked List class/////////////////////////
class ListL
{
private:
    node1 *_head1;
    node2 *_head2;
    node3 *_head3;
public:
    ListL();
    ~ListL();
    void clear();
    void prepend1(string data1);
    void prepend2(string data2);
    void prepend3(string data3);
    string output(int a, int l);
};
////////////////Constructors and Destructors//////////////////////
ListL::ListL():
    _head1(nullptr),
    _head2(nullptr),
    _head3(nullptr){
    }

node1::node1(string data1):
    _data1(data1),
    _next1(nullptr){
    }
node2::node2(string data2):
    _data2(data2),
    _next2(nullptr){
    }
node3::node3(string data3):
    _data3(data3),
    _next3(nullptr){
    }

ListL::~ListL()
{
    clear();
}
/////////////////Clear Method///////////////////////
void ListL::clear()
{
    node1 *p;
    node2 *q;
    node3 *r;
    while(_head1 != nullptr){
        p = _head1;
        _head1 = _head1->_next1;
        p->_next1 = nullptr;
        delete p;
    }
    while(_head2 != nullptr){
        q = _head2;
        _head2 = _head2->_next2;
        q->_next2 = nullptr;
        delete q;
    }
    while(_head3 != nullptr){
        r = _head3;
        _head3 = _head3->_next3;
        r->_next3 = nullptr;
        delete r;
    }
}
////////////////Prepend Method//////////////////////////
void ListL::prepend1(string data1)
{
    node1 *temp = _head1;
    _head1 = new node1(data1);
    _head1->_next1 = temp;
}

void ListL::prepend2(string data2)
{
    node2 *temp = _head2;
    _head2 = new node2(data2);
    _head2->_next2 = temp;
}

void ListL::prepend3(string data3)
{
    node3 *temp = _head3;
    _head3 = new node3(data3);
    _head3->_next3 = temp;
}

string ListL::output(int a, int l)
{
    int count = 0;
    prepend1("https://www.thetrace.org/features/gun-violence-facts-and-solutions/");
    prepend1("An American woman is fatally shot by her partner every 16 hours.");
    prepend1("In 2017, there were 346 mass shootings in the U.S.");
    prepend2("https://www.usnews.com/news/cities/articles/2019-09-23/10-facts-about-homelessness-in-america");
    prepend2("60% of homeless people in the U.S. are males.");
    prepend2("African Americans represent 13 percent of the population, but are 40% of the homeless population.");
    prepend3("https://inequality.org/facts/wealth-inequality/");
    prepend3("Only around 40% of African Americans and Latinos own their home.");
    prepend3("1% of Americans hold more than half the national wealth.");
    if(a == 1){
        while(count != l - 1){
            _head1 = _head1->_next1;
            count++;
        }
        return _head1->_data1;
    }
    if(a == 2){
        while(count != l - 1){
            _head2 = _head2->_next2;
            count++;
        }
        return _head2->_data2;
    }
    while(count != l - 1){
        _head3 = _head3->_next3;
        count++;
    }
    return _head3->_data3;
}
///////////////Main Program///////////////////////////
int main()
{
    do{
        cout << "Enter in the corresponding number with what social issue you want to learn about" << endl;
        cout << "Gun Violence: 1 " << endl;
        cout << "Homelessness: 2" << endl;
        cout << "Wealth Inequality: 3" << endl;
        cout << "\n";
        cin >> socialIssue;
        cout << "Now enter in the corresponding number with the topic you want to  choose" << endl;
        cout << "First Fact: 1 " << endl;
        cout << "Second Fact: 2" << endl;
        cout << "If you want more info, copy this url: 3" << endl;
        cout << "\n";
        cin >> linkNum;
        if(socialIssue < 1 || socialIssue > 3){
            cerr << "Not a valid number";
            throw -1;
        }
        if(linkNum < 1 || linkNum > 3){
            cerr << "Not a valid number ";
            throw -1;
        }
        ListL x;
        cout << "\n";
        cout << x.output(socialIssue, linkNum) << endl;
        cout << "\n";
        cout << "If you want to try again, press 1.";
        cout << " If not, type in -1: ";
        cin >> again;
        cout << "\n";
    }while(again == 1);
    return 0;
}
