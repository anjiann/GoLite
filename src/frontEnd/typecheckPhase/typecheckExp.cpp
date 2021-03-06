#include <iostream>
#include "typecheckPhase/typecheckDispatcher.hpp"

using std::cout;
using std::endl;
using std::cerr;

//binary expressions: assert that lhs has type1 and rhs has type2
void assert(const NExpression &lhs, const NType &type1, const NExpression &rhs, const NType &type2) {
    if(lhs.type != type1 || rhs.type != type2) {
        cerr << "Error: (line " << lhs.lineno << ") assignment lhs type is incompatible with rhs type";
        cerr << "[" << lhs.type << "!=" << rhs.type << "]" << endl;
        exit(EXIT_FAILURE);
    }
}

void assertOrdered(const NExpBinary &binaryExp) {
    const NExpression &lhs = binaryExp.lhs;
    const NExpression &rhs = binaryExp.rhs;
    if(!isOrdered(lhs.type) || !isOrdered(rhs.type)) {
        NType errType = isOrdered(lhs.type) ? rhs.type : lhs.type;
        cerr << "Error: (line " << binaryExp.lineno << ") incompatible type in relational op " << binaryExp.op;
        cerr << " [received" << errType << ", expected ordered (int, rune, float64, string)]" << endl;
        exit(EXIT_FAILURE);
    }
    assert(lhs, lhs.type, rhs, rhs.type);
}

void assertNumeric(const NExpBinary &binaryExp) {
    const NExpression &lhs = binaryExp.lhs;
    const NExpression &rhs = binaryExp.rhs;
    if(!isNumeric(lhs.type) || !isNumeric(rhs.type)) {
        NType errType = isNumeric(lhs.type) ? rhs.type : lhs.type;
        cerr << "Error: (line " << binaryExp.lineno << ") incompatible type in relational op " << binaryExp.op;
        cerr << " [received" << errType << ", expected numeric (int, rune, float64) or string]" << endl;
        exit(EXIT_FAILURE);
    }
    assert(lhs, lhs.type, rhs, rhs.type);
}

void assertNumeric(const NExpUnary &unaryExp) {
    const NExpression &exp = unaryExp.exp;
    if(!isNumeric(exp.type)) {
        cerr << "Error: (line " << unaryExp.lineno << ") incompatible type in unary op " << unaryExp.op;
        cerr << " [received" << exp.type << ", expected numeric (int, rune, float64)]" << endl;
        exit(EXIT_FAILURE);
    }
}

void assertInteger(const NExpBinary &binaryExp) {
    const NExpression &lhs = binaryExp.lhs;
    const NExpression &rhs = binaryExp.rhs;
    if(!(isInteger(lhs.type) || isRune(rhs.type)) || !(isInteger(rhs.type) || isRune(lhs.type))) {
        cerr << "Error: (line " << binaryExp.lineno << ") incompatible type in arithmetic op " << binaryExp.op;
        cerr << " [received "<< lhs.type << ", expected integer (int, rune)]" << endl;
        exit(EXIT_FAILURE);
    }
    assert(lhs, lhs.type, rhs, rhs.type);
}

void assertBool(const NExpUnary &unaryExp) {
    const NExpression &exp = unaryExp.exp;
    if(!isBoolean(exp.type)) {
        cerr << "Error: (line " << unaryExp.lineno << ") incompatible type in unary op " << unaryExp.op;
        cerr << " [received" << exp.type << ", expected bool]" << endl;
        exit(EXIT_FAILURE);
    }
}

void assertInteger(const NExpUnary &unaryExp) {
    const NExpression &exp = unaryExp.exp;
    if(!(isInteger(unaryExp.type) || isRune(unaryExp.type))) {
        cerr << "Error: (line " << unaryExp.lineno << ") incompatible type in unary op " << unaryExp.op;
        cerr << " [received" << exp.type << ", expected integer (int, rune)]" << endl;
        exit(EXIT_FAILURE);
    }
}

//DISPATCHER

void TypecheckDispatcher::dispatch(const NExpression &exp) const {
    exp.accept(*this);
}

void TypecheckDispatcher::dispatch(const NExpArrIdentifier &arrIdExp) const {
    for(const auto &sizeExp : arrIdExp.sizeExps) {
        sizeExp->accept(*this);
        if(!isInteger(sizeExp->type)) {
            cerr << "Error: (line " << arrIdExp.lineno << ") index must be an int";
            cerr << "[received " << sizeExp->type << "]" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

void TypecheckDispatcher::dispatch(const NExpBinary &binaryExp) const {
    const NExpression &lhs = binaryExp.lhs;
    const NExpression &rhs = binaryExp.rhs;
    lhs.accept(*this);
    rhs.accept(*this);
    switch(binaryExp.op) {
        case NExpOpKind::orExp: //        ||
            assert(lhs, NType::boolType, rhs, NType::boolType);
            binaryExp.type = NType::boolType;
            break;
        case NExpOpKind::andExp: //       &&
            assert(lhs, NType::boolType, rhs, NType::boolType);
            binaryExp.type = NType::boolType;
            break; 
        case NExpOpKind::equalExp: //     ==
            assert(lhs, lhs.type, rhs, rhs.type);
            binaryExp.type = NType::boolType;
            break; 
        case NExpOpKind::noteqExp: //     !=
            assert(lhs, lhs.type, rhs, rhs.type);
            binaryExp.type = NType::boolType;
            break; 
        case NExpOpKind::lessExp: //      <
            assertOrdered(binaryExp);
            binaryExp.type = NType::boolType;
            break;
        case NExpOpKind::lesseqExp: //    <= 
            assertOrdered(binaryExp);
            binaryExp.type = NType::boolType;
            break; 
        case NExpOpKind::greaterExp: //   >
            assertOrdered(binaryExp);
            binaryExp.type = NType::boolType;
            break; 
        case NExpOpKind::greatereqExp: // >=
            assertOrdered(binaryExp);
            binaryExp.type = NType::boolType;
            break; 
        case NExpOpKind::plusExp: //      +
            if(!(isString(lhs.type) && isString(rhs.type))) {
                assertNumeric(binaryExp);
            }
            binaryExp.type = lhs.type;
            break; 
        case NExpOpKind::minusExp: //     -
            assertNumeric(binaryExp);
            binaryExp.type = lhs.type;
            break; 
        case NExpOpKind::multExp: //   	  *
            assertNumeric(binaryExp);
            binaryExp.type = lhs.type;
            break; 
        case NExpOpKind::divExp: //    	  /
            assertNumeric(binaryExp);
            binaryExp.type = lhs.type;
            break; 
        case NExpOpKind::modExp: //       %
            assertInteger(binaryExp);
            break; 
        case NExpOpKind::bitOrExp: //     |
            assertInteger(binaryExp);
            binaryExp.type = lhs.type;
            break; 
        case NExpOpKind::bitAndExp: //    &
            assertInteger(binaryExp);
            binaryExp.type = lhs.type;
            break; 
        case NExpOpKind::lshiftExp:  //   <<
            assertInteger(binaryExp);
            break;
        case NExpOpKind::rshiftExp: //    >>
            assertInteger(binaryExp);
            binaryExp.type = lhs.type;
            break; 
        case NExpOpKind::andnotExp: //    &^
            assertInteger(binaryExp);
            binaryExp.type = lhs.type;
            break; 
        case NExpOpKind::xorExp: //       ^
            assertInteger(binaryExp);
            binaryExp.type = lhs.type;
            break; 
        default:
            cerr << "non binary op " << binaryExp.op << " in binary expression" << endl;
            exit(EXIT_FAILURE);
    }
}
void TypecheckDispatcher::dispatch(const NExpBuiltin &builtinExp) const {
    const NExpression &exp = builtinExp.exp;
    exp.accept(*this);
    switch(builtinExp.kind) {
        case NExpBuiltinKind::lenExp: 
            if(!(isArray(exp.type) || isString(exp.type))) {
                cerr << "Error: (line " << exp.lineno << ") length builtin expects slice, array or string type as argument [received " << exp.type << "]" << endl;
                exit(EXIT_FAILURE);
            }
            break;
        case NExpBuiltinKind::capExp: 
            if(!isArray(exp.type)) {
                cerr << "Error: (line " << exp.lineno << ") capacity builtin expects slice or array type as argument [received " << exp.type << "]" << endl;
                exit(EXIT_FAILURE);
            }
            break;
    }
}

void TypecheckDispatcher::dispatch(const NExpFunc &funcExp) const {
    funcExp.expId.accept(*this);
    // try {
    //     FuncSymbol &funcSym = dynamic_cast<FuncSymbol&>(funcExp.expId.sym);
    // }
    // catch() {
    //     cerr << "Error: (line 8) foo is not a function type";
    // }

    // const NDecVarList &params = funcSym.decFunc.params;
    // const NExpressionList &args = funcExp.args;
    // auto itParams = params.begin();
    // auto itArgs = args.begin();
    // while(itParams != )
    // while(itParams != params.end() || itArgs != args.end()) {
    //     auto &decVar = *itParams++;
    //     auto &exp = *itArgs++;

    //     NExpIdentifier &expId = decVar->lhs.front();
    //     assert(expId.type, exp.type);
    // }
}

void TypecheckDispatcher::dispatch(const NExpIdentifier &idExp) const {
    auto localSym = idExp.symbol;
    localSym->expId.accept(*this);

    idExp.type = localSym->expId.type;
}

void TypecheckDispatcher::dispatch(const NExpIndexer &indexerExp) const {

}

void TypecheckDispatcher::dispatch(const NExpLiteral &literalExp) const {
    switch(literalExp.kind) {
        case NExpLiteralKind::intLiteral : literalExp.type = NType::intType; break;
        case NExpLiteralKind::floatLiteral : literalExp.type = NType::floatType; break;
        case NExpLiteralKind::runeLiteral : literalExp.type = NType::runeType; break;
        case NExpLiteralKind::boolLiteral : literalExp.type = NType::boolType; break;
        case NExpLiteralKind::stringLiteral : literalExp.type = NType::stringType; break;
    }
}

void TypecheckDispatcher::dispatch(const NExpUnary &unaryExp) const {
    const NExpression &exp = unaryExp.exp;
    exp.accept(*this);
    switch(unaryExp.op) {
        case NExpOpKind::plusExp : //  +
            assertNumeric(unaryExp);
            unaryExp.type = exp.type;
            break; 
        case NExpOpKind::minusExp : // -
            assertNumeric(unaryExp);
            unaryExp.type = exp.type;
            break; 
        case NExpOpKind::notExp : //   ! 
            assertBool(unaryExp);
            unaryExp.type = exp.type;
            break; 
        case NExpOpKind::xorExp : //   ^
            assertInteger(unaryExp);
            unaryExp.type = exp.type;
            break; 
        default:
            cerr << "non unary op " << unaryExp.op << " in unary expression" << endl;
            exit(EXIT_FAILURE);
    }
}

void TypecheckDispatcher::dispatch(const NExpCaseClause &caseClauseExp) const {
    caseClauseExp.switchCase.accept(*this);
    for(const auto &stmt : caseClauseExp.stmts) {
        stmt->accept(*this);
    }
}

void TypecheckDispatcher::dispatch(const NExpSwitchCase &switchCaseExp) const {
    for(const auto &exp : switchCaseExp.explist) {
        exp->accept(*this);
    }
}