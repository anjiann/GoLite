#include "tabs.hpp"

std::ostream& operator<<(std::ostream &os, const Tabs &rhs) {
    for(int i = 0; i < rhs.numTabs; i++) {
        os << "\t";
    }
    return os;
}

//prefix increment operator
Tabs Tabs::operator++() {
    numTabs++;
    return *this;
}

//postfix increment operator
Tabs Tabs::operator++(int) {
   Tabs temp = *this;
   ++*this;
   return temp;
}

//prefix decrement operator
Tabs Tabs::operator--() {
    numTabs--;
    return *this;
}

//postfix decrement operator
Tabs Tabs::operator--(int) {
    Tabs temp = *this;
    --*this;
    return temp;
}