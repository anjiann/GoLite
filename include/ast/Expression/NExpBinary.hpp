#ifndef NEXPBINARY_H
#define NEXPBINARY_H

#include <string>
#include "NExpression.h"

using std::string;

class NExpBinary : NExpression {    
    public:
        const NExpression &lhs;
        const NExpression &rhs;
        NExpBinaryOp op;
        NExpBinary(const NExpression &lhs, const NExpression &rhs, NExpBinaryOp op) : lhs{lhs}, rhs{rhs}, op{op};
};

enum NExpBinaryOp {
    plusExp, //   	 +
	minusExp, //  	 -
	multExp, //   	 *
	divExp, //    	 /
	modExp, //       %
	equalExp, //     ==
	noteqExp, //     !=
	greatereqExp, // >=
	lesseqExp, //    <= 
	greaterExp, //   >
	lessExp,//       <
	orExp,//         ||
	andExp, //       &&
	andnotExp, //    &^
	bitAndExp, //    & 
	bitOrExp, //     |
	xorExp, //       ^
	lshiftExp, //    <<
	rshiftExp, //    >>
};

#endif /* !NEXPBINARY_H */