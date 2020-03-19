#ifndef TAB_HPP
#define TAB_HPP

#include <ostream>

class Tabs {           
    friend std::ostream &operator<<(std::ostream &os, const Tabs &rhs);

    private:
        int numTabs;
    public:
        Tabs() {}

        Tabs operator++(); //prefix increment operator
        Tabs operator++(int); //postfix increment operator
        Tabs operator--(); //prefix decrement operator
        Tabs operator--(int); //postfix decrement operator
        
};

#endif