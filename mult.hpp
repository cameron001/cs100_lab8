#ifndef __MULT_HPP__
#define __MULT_HPP__
#pragma once
#include "base.hpp"
//using namespace std;
class mult : public Base{

	public:
		mult(Base* val1, Base* val2) :Base(){
			x = val1;
			y = val2;
		}
		virtual double evaluate(){
			return x->evaluate() * y->evaluate();
		}
		virtual std::string stringify(){
			return "(" + x->stringify() + "*" + y->stringify() + ")";
		}
		virtual int number_of_children() { return 2; }
		virtual Base* get_child(int i) {
			if (i == 0) { return x; }
			else if (i == 1) { return y; }
			else { return nullptr; }
		}
		virtual void accept(Visitor *visitor, int index) {
			if (index == 0) { visitor->visit_mult_begin(this); }
			else if (index == 1) { visitor->visit_mult_middle(this); }
			else if (index == 2) { visitor->visit_mult_end(this); }
		}
	private:
		Base* x;
		Base* y;

};

#endif 
		
