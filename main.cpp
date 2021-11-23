#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp"
#include "printLat.hpp"
#include "printMathml.hpp"

#include <iostream>
#include <memory>

int main() {
	Base *three = new Op(3);
	Base *seven = new Op(7);
	Base* ad = new add(three, seven);
    	Base* minus = new sub(three, seven);
    	Base* expt = new exponent(three, seven);
    	Base* d = new Div(three, seven);    
    	Base* m = new mult(three, seven);
   	Base* ran = new Rand();
	VisitorLatex* v_ = new VisitorLatex();
	std::cout << v_->PrintLaTeX(three) << std::endl;
	std::cout << v_->PrintLaTeX(ad) << std::endl;
	std::cout << v_->PrintLaTeX(minus) << std::endl;
	std::cout << v_->PrintLaTeX(expt) << std::endl;
	std::cout << v_->PrintLaTeX(d) << std::endl;
	std::cout << v_->PrintLaTeX(m) << std::endl;
	std::cout << v_->PrintLaTeX(ran) << std::endl;
	delete v_;

	VisitorMathML* t_ = new VisitorMathML();
	std::cout << t_->PrintMathML(three) << std::endl;
        std::cout << t_->PrintMathML(ad) << std::endl;
        std::cout << t_->PrintMathML(minus) << std::endl;
        std::cout << t_->PrintMathML(expt) << std::endl;
        std::cout << t_->PrintMathML(d) << std::endl;
        std::cout << t_->PrintMathML(m) << std::endl;
        std::cout << t_->PrintMathML(ran) << std::endl;
 
	return 0;
}
