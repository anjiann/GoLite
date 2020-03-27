#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <ostream>

using std::cout;

enum class NExpOpKind {
	//binary
	orExp,//         ||
	andExp, //       &&
	equalExp, //     ==
	noteqExp, //     !=
	lessExp,//       <
	lesseqExp, //    <= 
	greaterExp, //   >
	greatereqExp, // >=
	plusExp, //      +
	minusExp, //     -
	multExp, //   	 *
	divExp, //    	 /
	modExp, //       %
	bitOrExp, //     |
	bitAndExp, //    &
	lshiftExp, //    <<
	rshiftExp, //    >>
	andnotExp, //    &^
	xorExp, //       ^

	//unary
    notExp, //       ! 
    parenExp, //    (e)
};

enum class NExpBuiltinKind {
    lenExp,
    capExp,
    funcExp
    // append, //not required in golite_mini
};

enum class NExpLiteralKind {
	intLiteral,
	floatLiteral,
	boolLiteral,
	charLiteral,
	stringLiteral
};

inline std::ostream &operator<<(std::ostream &os, const NExpOpKind &op) {
	switch(op) {
		//binary
		case orExp : cout << "||"; break;
		case andExp : cout << "&&"; break;
		case equalExp : cout << "=="; break;
		case noteqExp : cout << "!="; break;
		case lessExp : cout << "<"; break;
		case lesseqExp : cout << "<="; break; 
		case greaterExp : cout << ">"; break;
		case greatereqExp : cout << ">="; break;
		case plusExp : cout << "+"; break; 
		case minusExp : cout << "-"; break;
		case multExp : cout << "*"; break;
		case divExp : cout << "/"; break; 
		case modExp : cout << "%"; break;
		case bitOrExp : cout << "|"; break;
		case bitAndExp : cout << "&"; break
		case lshiftExp : cout << "<<"; break;
		case rshiftExp : cout << ">>"; break;
		case andnotExp : cout << "&^"; break;
		case xorExp : cout << "^"; break;

		//unary
		case notExp : cout << "!"; break;
		case parenExp : cout << "(e)"; break;
	}
}

#endif