#pragma once
#include "base.hpp"
#include <cmath>

class exponent : public Base {
    public:
        exponent(Base* value1, Base* value2) : Base() {
                x = value1;
                y = value2; }
        virtual double evaluate() { return pow(x->evaluate(),y->evaluate()); }
        virtual std::string stringify() {
		std::string str = x->stringify();;
		//str.erase(str.find_last_not_of('0') + 1, std::string::npos);
		std::string str2 = y->stringify();;
                //str2.erase(str2.find_last_not_of('0') + 1, std::string::npos);
                        return "(" + str + "**" + str2 + ")"; }
	virtual int number_of_children() { return 2; }
	virtual Base* get_child(int i) {
 		if (i == 0) { return x; }
		else if (i == 1) { return y; }
		else { return nullptr; }			
	}
	virtual void accept(Visitor *visitor, int index) {
		if (index == 0) { visitor->visit_pow_begin(this); }
		else if (index == 1) { visitor->visit_pow_middle(this); }
		else if (index == 2) { visitor->visit_pow_end(this); }
	}

	private:
        	Base* x;
        	Base* y;
};

