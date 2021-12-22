//tests.cpp
#include "whattotest.cpp"
#include <gtest/gtest.h>
        
TEST(SquareRootTest , PositiveNos){
     ASSERT_EQ(6, squareRoot(36.0)) <<"raiz de 36 es"<< squareRoot(36.0);
    ASSERT_EQ(18.0, squareRoot(324.0)) <<"raiz de 324.0 es"<< squareRoot(324.0);
    ASSERT_EQ(25.4, squareRoot(645.16)) <<"raiz de 645.16 es"<< squareRoot(645.16);
    ASSERT_EQ(0, squareRoot(0.0))<<"raiz de 0.0 es"<< squareRoot(0.0);
}
        
TEST(SquareRootTest, NegativeNos){
    ASSERT_EQ(-1.0, squareRoot( -15.0))<< "raiz de -15.0 es" << squareRoot(-15.0);
    ASSERT_EQ(-1.0, squareRoot( -0.2)) << "raiz de -0.2 es" << squareRoot(-0.2);
}
        
int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}