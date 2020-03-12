#ifndef ENUMS_HPP
#define ENUMS_HPP

enum NExpOp {
    notExp, //       ! 
    posExp, //       +
	negExp, //       -
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

enum NExpBuiltinKind {
    lenExp,
    capExp,
    funcExp
    // append, //not required in golite_mini
};

#endif