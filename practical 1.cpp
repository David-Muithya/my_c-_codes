**syntax**

c++
for(initiliazation;increment/decrement){
	//code to be executed
}


**components**:
-**Initilization**:Executed once before the loop starts.Typically used to initialize a loop control variable
-**condition**:checked before each iteration.If true,the loop continues;otherwise,it terminates

-**Increment/Decrement**:Executed after each iteration.Used to modify the loop control variable.

**Example**:
```cpp
#include<iostream>
using namespace std;
int main(){
	//Prrint numbers from 1 to 5
	for(int i=;<=5;i++){
		cout<<i<<"";

	}
	
	
	return 0;
}
````

output:
12345

4.**Characteristics**:  
   
-The loop control variable(`i` in the example) is scoped to the loop.
-You can use only any valid c++ expression for initialization    

 