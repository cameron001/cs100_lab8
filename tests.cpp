#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp"
#include "printLat.hpp"


//#include <iostream>
#include <memory>

TEST(latexTest, justonenum){

        Base* num = new Op(3);
        VisitorLatex* v = new VisitorLatex();
        EXPECT_EQ(v->PrintLaTeX(num), "${3.000000}$");
}
TEST(latexTest, adding){
        Base* num = new Op(3);
        Base* num2 = new Op(4);
        Base* testval = new add(num, num2);
        VisitorLatex* v = new VisitorLatex();
        EXPECT_EQ(v->PrintLaTeX(testval), "${({3.000000}+{4.000000})}$");
        
}
TEST(latexTest, subtracting){
        Base* num = new Op(3);
        Base* num2 = new Op(4);
        Base* testval = new sub(num2, num);
        VisitorLatex* v = new VisitorLatex();
        EXPECT_EQ(v->PrintLaTeX(testval), "${({4.000000}-{3.000000})}$");
        
}

TEST(latexTest, powers){
        Base* num = new Op(3);
        Base* num2 = new Op(4);
        Base* testval = new exponent(num, num2);
        VisitorLatex* v = new VisitorLatex();
        EXPECT_EQ(v->PrintLaTeX(testval), "${({3.000000}^{4.000000})}$");
        
}
TEST(latexTest, multiplication){
        Base* num = new Op(3);
        Base* num2 = new Op(4);
        Base* testval = new mult(num, num2);
        VisitorLatex* v = new VisitorLatex();
        EXPECT_EQ(v->PrintLaTeX(testval), "${({3.000000}\\cdot{4.000000})}$");
        
}

TEST(latexTest, division){
        Base* num = new Op(3);
        Base* num2 = new Op(4);
        Base* testval = new Div(num, num2);
        VisitorLatex* v = new VisitorLatex();
        EXPECT_EQ(v->PrintLaTeX(testval), "${({3.000000}/{4.000000})}$");
        
}
TEST(latexTest, negativenums){
        Base* num = new Op(-3);
        Base* num2 = new Op(4);
        Base* testval = new add(num, num2);
        VisitorLatex* v = new VisitorLatex();
        EXPECT_EQ(v->PrintLaTeX(testval), "${({-3.000000}+{4.000000})}$");
        
}
TEST(latexTest, mixingoperations){
        Base* num = new Op(3);
        Base* num2 = new Op(4);
        Base* testval = new add(num, num2);
        Base* testval2 = new Div(num, testval);
        VisitorLatex* v = new VisitorLatex();
        EXPECT_EQ(v->PrintLaTeX(testval2), "${({3.000000}/{3.000000}/{4.000000})}$");
        
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
