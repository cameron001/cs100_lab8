#pragma once

#include "visitor.hpp"
#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "exp.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "iterator.hpp"

class Op;

class VisitorMathML: public Visitor{
private:
   std::string mathml = "";
public:
    VisitorMathML(){ }
    std::string PrintMathML(Base* ptr){
      VisitorMathML* visitor_ = new VisitorMathML();
    	for (Iterator it(ptr); !it.is_done(); it.next()){
        	it.current_node()->accept(visitor_, it.current_index());
    	}
   	std::string mathmlFormat = visitor_->getMathML();
   	delete visitor_;
   	return mathmlFormat;
      }
    virtual ~VisitorMathML() = default;
    std::string getMathML(){
        mathml = "<math>\n" + mathml;
        mathml = mathml + "</math>";
        return mathml;
    }
    virtual void visit_op(Op* node){
        mathml = mathml + "<cn>";
        mathml = mathml + node->stringify();
        mathml = mathml + "</cn>\n";
    }
	virtual void visit_rand(Rand* node){
	    mathml = mathml + "<cn>";
        mathml = mathml + node->stringify();
        mathml = mathml + "</cn>\n";
    }
    
    virtual void visit_add_middle(add* node){
        mathml = mathml + "<plus/>\n";
    }
    
    
    virtual void visit_add_begin(add* node){
        mathml = mathml + "<apply>\n";
    }
    
    
    
    virtual void visit_add_end(add* node){
        mathml = mathml + "</apply>\n";
    }
    virtual void visit_sub_begin(sub* node){
        mathml = mathml + "<apply>\n";
    }
    virtual void visit_sub_middle(sub* node){
        mathml = mathml + "<minus/>\n";
    }
    virtual void visit_sub_end(sub* node){
        mathml = mathml + "</apply>\n";
    }
    virtual void visit_mult_begin(mult* node){
        mathml = mathml + "<apply>\n";
    }
    virtual void visit_mult_middle(mult* node){
        mathml = mathml + "<times/>\n";
    }
    virtual void visit_mult_end(mult* node){
        mathml = mathml + "</apply>\n";
    }
    virtual void visit_div_begin(Div* node){
        mathml = mathml + "<apply/>\n"; 
    }
    virtual void visit_div_middle(Div* node){
		mathml = mathml + "<divide/>\n";
    }
    virtual void visit_div_end(Div* node){
        mathml = mathml + "</apply>\n";
    }
    virtual void visit_pow_begin(exponent* node){
        mathml = mathml + "<apply/>\n";
    }
    virtual void visit_pow_middle(exponent* node){
        mathml = mathml + "<power/>\n";
    }
    virtual void visit_pow_end(exponent* node){
        mathml = mathml + "</apply>\n";
    }
};
