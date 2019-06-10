//Kathrine von Friedl 20760403
//Aurelie Sinclair 20784400
//Urban Pistek 20802700

//NOTE REGARDING MARKING compiler used was VS Code and Dev C++

#include "Polynomial.hpp"
#include <vector>

using namespace std;

class PolynomialTest{
    private:
    public:
        bool test_file_constructor1() {
            //File contains:
            //0
            Polynomial test("Constructors1.txt");
            if (test.pVector.size() == 0)
                return true;
            return false;
        }
        bool test_file_constructor2() {
            //File contains:
            //3 2 4 5
            bool success = true;
            Polynomial test("Constructors2.txt");
            vector<int> chkValue{2,4,5};
			for(int index = 0; index < test.pVector.size(); index++){
				if (test.pVector.at(index) == chkValue[index])
                	success = success && true; 
                else
                success = false; 
			} 
            return success;
        }            
        bool test_file_constructor3() {
            //File contains:
            //-4 3 5 0 6
            Polynomial test("Constructors3.txt");
            if (test.pVector.size() == 0)
                return true;
            return false;
        }
        bool test_file_constructor4() {
            //
            Polynomial test("Constructors4.txt");
            if (test.pVector.size() == 0)
                return true;
            return false;
        }
        bool test_array_constructor1(){
            int testVal[0] = {};
            Polynomial test(testVal,0);
            // int size = test.pVector.size();
            if(test.pVector.empty())
                return true;
            return false;
        }
        bool test_array_constructor2(){
            int numbers[] = {4,5,8,-5};
            Polynomial test(numbers,4);

            vector<int> chkValue{4,5,8,-5};
            if (test.pVector.size() == 4 && test.pVector == chkValue)
                return true;
            //return false;
        }
        bool test_random_constructor(){
            for (int index = 0; index < 5; index++){
                bool result = true;
                Polynomial testValue;

                if (testValue.pVector.size() > 1000)
                    return false;
                for (int index2 = 0; index2 < testValue.pVector.size(); index2++)
                {
                    if (testValue.pVector.at(index) > 1000 || testValue.pVector.at(index) < -1000)
                        return false;
                }
            }
            return true;
        }

        void test_print(){
            int test1[5] = {5, 3, 6, 4, 10};
            Polynomial poly1(test1, 5);
	        //cout << "            ";
            //poly1.print();
            //cout << endl << "should be : 10x^4 +4x^3 +6x^2 +3x +5" << endl;

            int test2[5] = {5, 3, 0, 4, 0};
            Polynomial poly2(test2, 5);
	        //cout << "            ";
            //poly2.print();
            //cout << endl << "should be : 4x^3 +3x +5" << endl;

            int test3[5] = {-5, 3, 6, -4, 10};
            Polynomial poly3(test3, 5);
	        //cout << "            ";
            //poly3.print();
            //cout << endl << "should be : -10x^4 +4x^3 -6x^2 +3x +5" << endl;
        
            //             10x^4 +4x^+3 +6x^+2 +3x^+1 +5
            // should be : 10x^4 +4x^3 +6x^2 +3x +5
            //             +4x^+3 +3x^+1 +5
            // should be : 4x^3 +3x +5
            //             +10x^4 -4x^+3 +6x^+2 +3x^+1 -5
            // should be : -10x^4 +4x^3 -6x^2 +3x +5
        }

        bool test_equality_operator(){
        	bool success = true; 
        	int etest1a[] = {3,5,0,6,1};
        	int etest1b[] = {3,5,0,6,1};
        	int etest2a[] = {3,-33,0,0,1};
        	int etest2b[] = {3,-33,0,0,1};
        	
        	Polynomial petest1a(etest1a,5);
        	Polynomial petest1b(etest1b,5);
        	Polynomial petest2a(etest2a,5);
        	Polynomial petest2b(etest2b,5);
           	
        	for(int index = 0; index < 5; index++){
        		if(petest1a.pVector.at(index) == petest1b.pVector.at(index))
        			success = success && true; 
        		else
        			success = false; 
			}
			for(int index = 0; index < 5; index++){
        		if(petest2a.pVector.at(index) == petest2b.pVector.at(index))
        			success = success && true; 
        		else
        			success = false; 
			}
				
		return success; 
        }
        
        bool test_add_operator(){
        	bool success = false; 
        	int atest1a[] = {3,5,0,6,1,3};
        	int atest1b[] = {2,3,1,0,5,2};
        	int atest1result[] = {5,8,1,6,6,5};
        	
        	int atest2a[] = {-2,3,7,-6};
        	int atest2b[] = {3,-4,1,3};
        	int atest2result[] = {1,-1,8,-3};
        	
        	int atest3a[] = {0,3,-7};
        	int atest3b[] = {-1,3,-3};
        	int atest3result[] = {-1,6,-10};
        	
        	Polynomial patest1a(atest1a,6);
        	Polynomial patest1b(atest1b,6);
        	Polynomial patest1result(atest1result,6);
        	Polynomial patest2a(atest2a,4);
        	Polynomial patest2b(atest2b,4);
        	Polynomial patest2result(atest2result,4);
        	Polynomial patest3a(atest3a,3);
			Polynomial patest3b(atest3b,3);
			Polynomial patest3result(atest3result,3);
			
			Polynomial patest1ab = patest1a+patest1b;
			Polynomial patest2ab = patest2a+patest2b;
			Polynomial patest3ab = patest3a+patest3b;
			 
			if(patest1ab == patest1result 
			&& patest2ab == patest2result 
			&& patest3ab == patest3result)
			{
				success = true;	
			}		
		return success; 
		}
		
		bool test_subtract_operator(){
        	bool success = false; 
        	int test1a[] = {3,5,0,6,1,3};
        	int test1b[] = {2,3,1,0,5,2};
        	int test1result[] = {1,2,-1,6,-4,1};
        	
        	int test2a[] = {-2,3,7,-6};
        	int test2b[] = {3,-4,1,3};
        	int test2result[] = {-5,7,6,-9};
        	
        	int test3a[] = {0,3,-7};
        	int test3b[] = {-1,3,-3};
        	int test3result[] = {1,0,-4};
        	
        	Polynomial ptest1a(test1a,6);
        	Polynomial ptest1b(test1b,6);
        	Polynomial ptest1result(test1result,6);
        	Polynomial ptest2a(test2a,4);
        	Polynomial ptest2b(test2b,4);
        	Polynomial ptest2result(test2result,4);
        	Polynomial ptest3a(test3a,3);
			Polynomial ptest3b(test3b,3);
			Polynomial ptest3result(test3result,3);
			
			Polynomial ptest1ab = ptest1a-ptest1b;
			Polynomial ptest2ab = ptest2a-ptest2b;
			Polynomial ptest3ab = ptest3a-ptest3b;

			if(ptest1ab == ptest1result 
			&& ptest2ab == ptest2result 
			&& ptest3ab == ptest3result)
			{
				success = true;	
			}		
		return success; 
		}
		
		 bool test_multiply_operator(){
        	bool success = false; 
        	int test1a[] = {-3,2,1};
        	int test1b[] = {-2,0,2};
        	int test1result[] = {6,-4,-8,4,2};
        	
        	int test2a[] = {-3,2,1};
        	int test2b[] = {4,2};
        	int test2result[] = {-12,2,8,2};
        	
        	int test3a[] = {2,1};
        	int test3b[] = {4,2};
        	int test3result[] = {8,8,2};
        	
        	Polynomial ptest1a(test1a,3);
        	Polynomial ptest1b(test1b,3);
        	Polynomial ptest1result(test1result,5);
        	Polynomial ptest2a(test2a,3);
        	Polynomial ptest2b(test2b,2);
        	Polynomial ptest2result(test2result,4);
        	Polynomial ptest3a(test3a,2);
			Polynomial ptest3b(test3b,2);
			Polynomial ptest3result(test3result,3);
			
			Polynomial ptest1ab = ptest1a*ptest1b;
			Polynomial ptest2ab = ptest2a*ptest2b;
			Polynomial ptest3ab = ptest3a*ptest3b;
			
			// cout << " [ ";
			// for(int index = 0; index < ptest1ab.pVector.size(); index++){
			// 	cout << ptest1ab.pVector.at(index) << " "; 
			// }
			// cout << " ] ";
			// cout << " [ ";
			// for(int index = 0; index < ptest2ab.pVector.size(); index++){
			// 	cout << ptest2ab.pVector.at(index) << " "; 
			// }
			// cout << " ] ";
			// cout << " [ ";
			// for(int index = 0; index < ptest3ab.pVector.size(); index++){
			// 	cout << ptest3ab.pVector.at(index) << " "; 
			// }
			// cout << " ] " << endl;
			
			if(ptest1ab == ptest1result 
			&& ptest2ab == ptest2result 
			&& ptest3ab == ptest3result)
			{
				success = true;	
			}		

            // RETURNS [ +6 -4 -8 +4 +2  ]  [ -12 +2 +8 +2  ]  [ +8 +8 +2  ]

		return success;	
		}
		
        bool test_derivative1(){
            int testD4[3] = {8, 3, 2};
            int testD4deriv[2] = {3, 4};
            Polynomial poly4(testD4, 3);
            Polynomial poly4deriv(testD4deriv, 2);

            Polynomial temp = poly4.derivative();
            // cout << "            ";
            // temp.print();
            // cout << endl << "should be : 4x^1 + 3" << endl << endl;
            if (temp == poly4deriv)
                return true;
            return false;

            //RETURN
            //             4x^1 +3
            // should be : 4x^1 + 3
        }

        bool test_derivative2(){
            int testD5[4] = {4, 7, 3, 11};
            int testD5deriv[3] = {7, 6, 33};
            Polynomial poly5(testD5, 4);
            Polynomial poly5deriv(testD5deriv, 3);

            Polynomial temp = poly5.derivative();
            // cout << "            ";
            // temp.print();
            // cout << endl << "should be : 33x^2 +6x^1 +7" << endl << endl;
            if (temp == poly5deriv)
                return true;
            return false;

            //RETURN
            //            33x^2 +6x^+1 +7
            // should be : 33x^2 +6x^1 +7
        }

        bool test_derivative3(){
            int testD6[6] = {17, 4, 8, 1, 0, 1};
            int testD6deriv[6] = {4, 16, 3, 0, 5};
            Polynomial poly6(testD6, 6);
            Polynomial poly6deriv(testD6deriv, 5);

            Polynomial temp = poly6.derivative();
            // cout << "            ";
            // temp.print();
            // cout << endl << "should be : 5x^4 + 3x^2 + 16x^1 + 4" << endl << endl;
            
            if (temp == poly6deriv)
                return true;
            return false;

            //RETURN
            //            +5x^4 +3x^+2 +16x^+1 +4
            // should be : 5x^4 + 3x^2 + 16x^1 + 4
        }

        void run() {
            test_print();
            if(test_file_constructor1())
                cout << "Test File Constructors1 Passed" << endl;
            else
                cout << "Test File Constructors1 Failed" << endl;   
            if(test_file_constructor2())
                cout << "Test File Constructors2 Passed" << endl;
            else
                cout << "Test File Constructors2 Failed" << endl;   
            if(test_file_constructor3())
                cout << "Test File Constructors3 Passed" << endl;
            else
                cout << "Test File Constructors3 Failed" << endl;
            if(test_file_constructor4())
                cout << "Test File Constructors4 Passed" << endl;
            else
                cout << "Test File Constructors4 Failed" << endl;
                
                
            if(test_array_constructor1())
                cout << "Test Array Constructors1 Passed" << endl;
            else
                cout << "Test Array Constructors1 Failed" << endl;
            if(test_array_constructor2())
                cout << "Test Array Constructors2 Passed" << endl;
            else
                cout << "Test Arary Constructors2 Failed" << endl;


            if(test_random_constructor())
                cout << "Test Random Constructor Passed" << endl;
            else
                cout << "Test Random Constructor Failed" << endl;


            if(test_derivative1())
                cout << "Test Derivative Function 1 Passed" << endl;
            else
                cout << "Test Derivative Function 1 Failed" << endl;

            if(test_derivative2())
                cout << "Test Derivative Function 2 Passed" << endl;
            else
                cout << "Test Derivative Function 2 Failed" << endl;

            if(test_derivative3())
                cout << "Test Derivative Function 3 Passed" << endl;
            else
                cout << "Test Derivative Function 3 Failed" << endl;

                //AS PREVIOUSLY STATED ABOVE THE RETURN FOR THESE TEST CASES ARE AS FOLLOWS

                //              +4x^1 +3
                // should be : 4x^1 + 3

                //            33x^2 +6x^+1 +7
                // should be : 33x^2 +6x^1 +7

                //             +5x^4 +3x^+2 +16x^+1 +4
                // should be : 5x^4 + 3x^2 + 16x^1 + 4

            if(test_add_operator())
                cout << "Test Add Operator Passed" << endl;
            else
                cout << "Test Add Operator Failed" << endl;
            
			if(test_subtract_operator())
                cout << "Test Subtract Operator Passed" << endl;
            else
                cout << "Test Subtract Operator Failed" << endl;
                
            if(test_equality_operator())
                cout << "Test Eqaulity Operator Passed" << endl;
            else
                cout << "Test Eqaulity Operator Failed" << endl;
                
            if(test_multiply_operator())
                cout << "Test Multiply Operator Passed" << endl;
            else
                cout << "Test Multiply Operator Failed" << endl;
        }

        //RETURN
        // Test File Constructors1 Passed
        // Test File Constructors2 Passed
        // Test File Constructors3 Passed
        // Test File Constructors4 Passed
        // Test Array Constructors1 Passed
        // Test Array Constructors2 Passed
        // Test Random Constructor Passed
        // Test Derivative Function 1 Passed
        // Test Derivative Function 2 Passed
        // Test Derivative Function 3 Passed
        // Test Add Operator Passed
        // Test Subtract Operator Passed
        // Test Eqaulity Operator Passed
        // Test Multiply Operator Passed 
};

int main() {
    PolynomialTest my_test;
    my_test.run();
    return 0;
}