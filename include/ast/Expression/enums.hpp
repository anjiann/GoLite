#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <iostream>

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
	plusExp, //      + (unary)
	minusExp, //     - (unary)
	multExp, //   	 *
	divExp, //    	 /
	modExp, //       %
	bitOrExp, //     |
	bitAndExp, //    &
	lshiftExp, //    <<
	rshiftExp, //    >>
	andnotExp, //    &^ 
	xorExp, //       ^ (unary)

	//unary
    notExp, //       ! 
};

enum class NExpBuiltinKind {
    lenExp,
    capExp,
    // append, //not required in golite_mini
};

enum class NExpLiteralKind {
	intLiteral,
	floatLiteral,
	boolLiteral,
	runeLiteral,
	stringLiteral
};

inline std::ostream &operator<<(std::ostream &os, const NExpOpKind &op) {
	switch(op) {
		case NExpOpKind::orExp : cout << "||"; break;
		case NExpOpKind::andExp : cout << "&&"; break;
		case NExpOpKind::equalExp : cout << "=="; break;
		case NExpOpKind::noteqExp : cout << "!="; break;
		case NExpOpKind::lessExp : cout << "<"; break;
		case NExpOpKind::lesseqExp : cout << "<="; break; 
		case NExpOpKind::greaterExp : cout << ">"; break;
		case NExpOpKind::greatereqExp : cout << ">="; break;
		case NExpOpKind::plusExp : cout << "+"; break; 
		case NExpOpKind::minusExp : cout << "-"; break;
		case NExpOpKind::multExp : cout << "*"; break;
		case NExpOpKind::divExp : cout << "/"; break; 
		case NExpOpKind::modExp : cout << "%"; break;
		case NExpOpKind::bitOrExp : cout << "|"; break;
		case NExpOpKind::bitAndExp : cout << "&"; break;
		case NExpOpKind::lshiftExp : cout << "<<"; break;
		case NExpOpKind::rshiftExp : cout << ">>"; break;
		case NExpOpKind::andnotExp : cout << "&^"; break;
		case NExpOpKind::xorExp : cout << "^"; break;
		case NExpOpKind::notExp : cout << "!"; break;
	}
}

#endif