// ����� ��� ���������� �������������� ���������
#include "arithmetic.h"
#include <gtest.h>
  
TEST(Lexem, Lexem1)
 {
 	Lexem t1('*');
 	EXPECT_EQ(3, t1.value);
 }
 
 TEST(Lexem, Lexem2)
 {
 	Lexem t1("3");
 	EXPECT_EQ(3, t1.value);
 }
 
 TEST(Lexem, Lexem3)
 {
 	Lexem t1('+');	
 	EXPECT_EQ(1, t1.prioritet());
 }
 
 TEST(Arithmetic, DivideToTerms)
 {
 	Arithmetic t1("7*8");
 	t1.DivideToinputLexems();	
		EXPECT_EQ(7,t1.GetValueLexem(0));
  		EXPECT_EQ(3, t1.GetValueLexem(1));
 		EXPECT_EQ(8, t1.GetValueLexem(2));
 } 


 TEST(Arithmetic, CanCalcDiv1)
 { 
 	Arithmetic t1("1+1"); 
 	t1.DivideToinputLexems();
 	t1.ConvertToPolish();
 	double x = t1.Calculate(); 
 	EXPECT_EQ(2.0, x); 
  }
  

 TEST(Arithmetic, CanCalcDiv2)
 { 
	 Arithmetic t1("1+1+2"); 
	 t1.DivideToinputLexems();
	 t1.ConvertToPolish();
	 double x = t1.Calculate(); 
	 EXPECT_EQ(4.0, x); 
 }

 TEST(Arithmetic,StringConversion)
 {
	 string x="-(3*2/2)";
	 string y="0-(3*2/2)";
	 Arithmetic t1("1+1");
	 string w=t1.StringConversion(x);
	 EXPECT_EQ(y,w);

 }
 TEST(Arithmetic,inputVar)
 {
	 Arithmetic t1("(10+(-10))");
	 t1.DivideToinputLexems();
	 t1.Change();
	 t1.ConvertToPolish();
	 double x=t1.Calculate();
	 EXPECT_EQ(0,x);
 }

 TEST(Arithmetic,CheckBrackets)
 {		bool s;
	 Arithmetic t1("(32((6-4*3");
	 t1.DivideToinputLexems();
	 s=t1.CheckBrackets();
	 EXPECT_EQ(false,s);
 }

 TEST(Arithmetic,CheckSymbol)
 {		bool s;
	 Arithmetic t1("10+5-$23");
	 t1.DivideToinputLexems();
	 s=t1.CheckSymbol();
	 EXPECT_EQ(false,s);
 }

 TEST(Arithmetic,CheckOperators)
 {		bool s;
	 Arithmetic t1("48+12-*34");
	 t1.DivideToinputLexems();
	 s=t1.CheckOperators();
	 EXPECT_EQ(false,s);
 }

 