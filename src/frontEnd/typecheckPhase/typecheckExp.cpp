#include <iostream>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;
using std::endl;
using std::cerr;

//binary expressions: assert that lhs has type1 and rhs has type2
void assert(const NExpression &lhs, const NType &type1, const NExpression &rhs, const NType &type2) {
    if(lhs.type != type1 && rhs.type != type2) {
        cerr << "Error: (line ) assignment lhs type is incompatible with rhs type";
        cerr << "[" << lhs.type << "!=" << rhs.type << "]" << endl;
        exit(EXIT_FAILURE);
    }
}

void assertOrdered(const NExpBinary &binaryExp) {
    const NExpression &lhs = binaryExp.lhs;
    const NExpresison &rhs = binaryExp.rhs;
    if(lhs.type == NType.boolType || rhs.type == NType.boolType) {
        cerr << "Error: (line ) Error: (line 4) incompatible type in relational op" << binaryExp.op;
        cerr << "[received bool, expected ordered (int, rune, float64, string)]" << endl;
        exit(EXIT_FAILURE);
    }
    assert(lhs, lhs.type, rhs, rhs.type);
}

void assertNumeric(constNExpBinary &binaryExp) {
    const NExpression &lhs = binaryExp.lhs;
    const NExpresison &rhs = binaryExp.rhs;
    if(!(lhs.type == NType.intType || lhs.type == NType.floatType) 
        || !(lhs.type == NType.intType || lhs.type == NType.floatType)) {
        assert(lhs, lhs.type, rhs, rhs.type);
    }
    else {

    }
}

NType assignType(NType &lhs, NType *rhs) {
    
}

void TypecheckDispatcher::dispatch(const NExpression &exp) const {
    exp.accept(*typecheckDispatcher);
}

void TypecheckDispatcher::dispatch(const NExpBinary &binaryExp) const {
    const NExpression &lhs = binaryExp.lhs;
    const NExpresison &rhs = binaryExp.rhs;
    lhs.accept(*typecheckDispatcher);
    rhs.accept(*typecheckDispatcher);
    switch(binaryExp.op) {
        case orExp : //       ||
            assert(lhs, NType.boolType, rhs, NType.boolType);
            break;
        case andExp: //       &&
            assert(lhs, NType.boolType, rhs, NType.boolType);
            break; 
        case equalExp: //     ==
            assert(lhs, lhs.type, rhs, rhs.type);
            break; 
        case noteqExp: //     !=
            assert(lhs, lhs.type, rhs, rhs.type);
            break; 
        case lessExp: //      <
            assertOrdered(binaryExp);
            break;
        case lesseqExp: //    <= 
            assertOrdered(binaryExp);
            break; 
        case greaterExp: //   >
            assertOrdered(binaryExp);
            break; 
        case greatereqExp: // >=
            assertOrdered(binaryExp);
            break; 
        case plusExp: //      +
            break; 
        case minusExp: //     -
            assertNumeric(binaryExp);
            break; 
        case multExp: //   	  *
            assertNumeric(binaryExp);
            break; 
        case divExp: //    	  /
            assertNumeric(binaryExp);
            break; 
        case modExp: //       %
            break; 
        case bitOrExp: //     |
            break; 
        case bitAndExp: //    &
            break; 
        case lshiftExp:  //   <<
            break;
        case rshiftExp: //    >>
            break; 
        case andnotExp: //    &^
            break; 
        case xorExp: //       ^
            break; 
    }
}
void TypecheckDispatcher::dispatch(const NExpBuiltin &unaryExp) const {}
void TypecheckDispatcher::dispatch(const NExpFunc &funcExp) const {}
void TypecheckDispatcher::dispatch(const NExpIdentifier &idExp) const {}
void TypecheckDispatcher::dispatch(const NExpIndexer &indexerExp) const {}
void TypecheckDispatcher::dispatch(const NExpLiteral &literalExp) const {}
void TypecheckDispatcher::dispatch(const NExpUnary &unaryExp) const {}
void TypecheckDispatcher::dispatch(const NExpCaseClause &caseClauseExp) const {}
void TypecheckDispatcher::dispatch(const NExpSwitchCase &switchCaseExp) const {}