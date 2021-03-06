/*  --------- Project Euler Number 29 -----------
		//Distinct Powers
		
		Problem Statement-
		Consider all integer combinations of ab for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:

		2^2=4, 2^3=8, 2^4=16, 2^5=32
		3^2=9, 3^3=27, 3^4=81, 3^5=243
		4^2=16, 4^3=64, 4^4=256, 4^5=1024
		5^2=25, 5^3=125, 5^4=625, 5^5=3125
		If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:

		4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

		How many distinct terms are in the sequence generated by a^b for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?

*/
//Solution-9183

 #include <iostream>
 #include <cmath>
 
 #define MAX 100 
 int pow_factors(int tb_fact);
 int simple_test(int test_int,int max_divisor);
 
 int main()
 {
 	int counter =0,fact_num,exp = 1;
 	int test_bool;
 	for(int a = 2;a<=MAX;a++)
 	{
 		fact_num = pow_factors(a);
 		for(int b = 2;b<=MAX;b++)
 		{
 			if(fact_num ==0)counter++;//If a isn't a perfect square, cube, etc, add to the counter.
 			
 			//b is the exponent, so exp will check if the base, raised to the tested power is greater than the max power, in which case it'l count as distinct. If its less than the max exponent, we'll cover that number with a perfect cube late.r
 			if(fact_num !=0)
 			{
 			 exp = b*fact_num;
 			 if(exp > ((fact_num-1)*MAX ) )counter++;//if greater than max last power
 			 
 			 test_bool = simple_test(exp,fact_num);
 			 if( (exp>MAX && exp< (fact_num-1) * MAX ))
 			  {
 			   if(test_bool !=0)if( exp > MAX*test_bool )counter++;//if divisible, but greater than max*low_divisor
 			   if(test_bool ==0)counter++;//if not divisible, but in lower range
 			   }
 			 }
 		}
 	}
 std::cout<<counter<<std::endl;
 	return 0;
 
 }
 
 int simple_test(int test_int,int max_divisor)
 {
 	//Finds the largest devisor of test_int smaller than max_divisor. If they're relatively prime, returns zero.
 	int result = 0;
 	for(int i = max_divisor-1;i>=2;i--)
 	{
 		if(test_int%i ==0){result=i;break;}
 	}
 	return result;
 }
 int pow_factors(int tb_fact)
 {
 	/*This function finds out if the input function is a power (of a smaller base), returns what the power is.
 	int base = 2,pow = 1,other=base;
 	while(base*base<=tb_fact)
 	{
 		if(other<tb_fact)
 		{
 			other*=base;
 			pow++;
 		}
 		if(other==tb_fact)
 		{
 			break;
 		}
 		if(other>tb_fact)
 		{
 			base++;
 			other = base;
 			pow = 1;
 			//reset, essentially
 		}
 	}
 	if(pow==1)pow=0;
 	return pow;
 }