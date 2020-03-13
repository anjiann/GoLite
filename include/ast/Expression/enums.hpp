#ifndef ENUMS_HPP
#define ENUMS_HPP

enum class NExpOpKind {
    notExp, //       ! 
    plusExp, //      +
	minusExp, //     -
    xorExp, //       ^
    parenExp, //    (e)
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
	lshiftExp, //    <<
	rshiftExp, //    >>
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

#endif