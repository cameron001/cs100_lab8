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

class VisitorLatex : public Visitor{
private:
   std::string latex = "";
public:
    VisitorLatex(){ }
    std::string PrintLaTeX(Base* ptr){
      VisitorLatex* visitor_ = new VisitorLatex();
    	for (Iterator it(ptr); !it.is_done(); it.next()){
        	it.current_node()->accept(visitor_, it.current_index());
    	}
   	std::string latexFormat = visitor_->getLatex();
   	delete visitor_;
   	return latexFormat;
      }
    virtual ~VisitorLatex() = default;
    std::string getLatex(){
        latex = "$" + latex;
        latex = latex + "$";
        return latex;
    }
    virtual void visit_op(Op* node){
        latex = latex + "{";
        latex = latex + node->stringify();
        latex = latex + "}";
    }
	virtual void visit_rand(Rand* node){
	latex = latex + "{";
        latex = latex + node->stringify();
        latex = latex + "}";
    }
        virtual void visit_add_begin(add* node){
        latex = latex + "{(";
    }
    virtual void visit_add_middle(add* node){
        latex = latex + "+";
    }
    virtual void visit_add_end(add* node){
        latex = latex + ")}";
    }
    virtual void visit_sub_begin(sub* node){
        latex = latex + "{(";
    }
    virtual void visit_sub_middle(sub* node){
        latex = latex + "-";
    }
    virtual void visit_sub_end(sub* node){
        latex = latex + ")}";
    }
    virtual void visit_mult_begin(mult* node){
        latex = latex + "{(";
    }
    virtual void visit_mult_middle(mult* node){
        latex = latex + "\\cdot";
    }
    virtual void visit_mult_end(mult* node){
        latex = latex + ")}";
    }
    virtual void visit_div_begin(Div* node){
        latex = latex + "{\\frac"; 
    }
    virtual void visit_div_middle(Div* node){
		
    }
    virtual void visit_div_end(Div* node){
        latex = latex + "}";
    }
    virtual void visit_pow_begin(exponent* node){
        latex = latex + "{(";
    }
    virtual void visit_pow_middle(exponent* node){
        latex = latex + "^";
    }
    virtual void visit_pow_end(exponent* node){
        latex = latex + ")}";
    }
};


