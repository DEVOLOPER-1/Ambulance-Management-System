//
// Created by youss on 25-Nov-24.
//

#ifndef DECORATORS_H
#define DECORATORS_H
#include<ostream>
using namespace std;
struct Bold {
    ostream& operator<<(ostream& os, const Bold&) {
        return os << "\033[1m";
    }
};

struct Reset {
     ostream& operator<<(ostream& os, const Reset&) {
        return os << "\033[0m";
    }
};


struct Red {
    ostream& operator<<(ostream& os, const Reset&) {
        return os << "\033[31m";
    }
};
#endif //DECORATORS_H


/*
 Colors
\033[31m: Red
\033[32m: Green
\033[33m: Yellow
\033[34m: Blue
\033[0m: Reset to default color

*/


/*
Background Colors

\033[41m: Red background
\033[42m: Green background
\033[43m: Yellow background

*/

/*
*Text Effects

\033[1m: Bold text
\033[3m: Italic text
\033[4m: Underlined text

*/