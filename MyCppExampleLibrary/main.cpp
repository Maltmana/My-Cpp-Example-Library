#include <iostream>

// Example classifications : works, err, and WORKSWRONG! WORKSWRONG is the worst because it works but in a horrible way that will ruin your life.

void HelloWorld(); // if you get rid of this error because needs forward decleration


//CONST
class ConstExamples
{
	void ConstVariables()
	{

		// const modifies whatever is to the immediate left of it, except for when there is nothing to the left, then it modifies to the right.
		// best to just put it to the left of things.
		// but the compiler will often show error messages with const first.

		int const x = 1;
		//x++; // err can't modify const.

		// example const initialized with non-const
		{
			int x = 1;
			int const y = x;
		}

		

		int const * const pc = &x; // works because pc is a pointer to a const int and x is a const int. also pc is a const pointer and it is being initialized.
		//int const * const pc; // err uninitialized
		//int * p = &x; // err cannot assign a const int * to a nonconst int *

		const int const * px = &x; // WORKSWRONG because the pointer is still nonconst. int is just double const... I guess... because const is both left and right of int.
		//pc = nullptr; err because pc is correctly const
		//px = nullptr; works because px is nonconst

		// use : 

	}
};

//REFERENCES : A reference variable is an alias, that is, another name for an already existing variable.A reference, like a pointer is also implemented by storing the address of an object.
//A reference can be thought of as a constant pointer(not to be confused with a pointer to a constant value!) with automatic indirection, i.e the compiler will apply the * operator for you.
class ReferenceExamples
{
	void ReferenceVariables()
	{

		// example : simple initialization
		{
			//int & x; // err references are const and need initialization
			//int & x; int & const z; int * const y; // err these are all const and require initialization

			int x;

			int const & r = x; // works can assign non-const int x to const int reference r

		}

		// example : pointer reassignment
		{
			int x = 5, y = 5;
			int * p;
			p = &x;
			p = &y;
		}

		// example : reference non-reassignment
		{    
			int x = 5, y = 5;
			//int & p; // err needs init
			

			//int & r = &x; // err references must be  initialized with values not addresses

			int const cx = 5;
			//int const & const r = &cx; // err references must be initialized with values even when they are a const reference to const object and taking in a const object 



			int & r = x; // works reference assigned by value
			//r = y; // err references are const pointers and cannot be reassigned
		}

		// example : assigning references to pointers
		{
			int x = 5;
			int * p;
			//int & r = p; // err trying to assign a reference to an integer to be a reference to a pointer
			int * & r = p; // works reference to pointer to integer initialized with pointer to integer
			//int * & r = &x; // err the pointer must be const to init with address of operator see SPECIAL CASE # 1 
		}

		// SPECIAL CASE # 1 example : only references to const pointers can be initialized with the address of (&)
		{

			int cx = 5;

			//`int * & pr = &cx; // err reference to non-const pointer must be init with a value
			//int * & pr = cx; // err cannot initialize reference to non-const pointer with a value
			int * const & pr = &cx; // works pointer must be const

		// WHY : The address of (&) operator creates a temporary value, which cannot be bound to a reference to non-const.
		// The address-of operator creates a temporary value, and you can't normally have references to temporary values because they are, well, temporary.
		// Either do not use a reference for the argument, or better yet don't use a pointer.
		// Note that if you were to have a reference to the temporary value returned by address-of, when the temporary value gets immediately dumped, you would have a reference to free floating memory
		// Very bad.
		// When you pass a pointer by a non-const reference, you are telling the compiler that you are going to modify that pointer's value. 
		// Your code does not do that, but the compiler thinks that it does, or plans to do it in the future.
		

		}
	}

	class ReferencesWithFunctions
	{
		// evil example : return bad reference
		int & createIntEvila() {
			int i;
			return i;  // DON'T DO THIS. i is deleted when function ends and the return reference then points to nothing. never write return new int
		}

		// evil example : wrong way to have a function create something for you
		int & createIntEvilb() {
			int* i = new int;
			return *i;  // DON'T DO THIS.
		}
		// why evil : because necessitates this :
		//int& myInt = getInt(); // note the &, we cannot lose this reference!
		//delete &myInt;         // must delete...totally weird and  evil
		//int oops = getInt();
		//delete &oops; // undefined behavior, we're wrongly deleting a copy, not the original

		// correct example : this is the way a new dynamic object is created in a function
		//If you want to allocate something that lives beyond the scope of the function, use a smart pointer(or in general, a container) :
		std::unique_ptr<int> createIntGooda() {
			return std::make_unique<int>(0);
		}


	};
};

//POINTERS

//Pointers: A pointer is a variable that holds memory address of another variable.A pointer needs to be dereferenced with * operator to access the memory location it points to.



//this
//is a special pointer(== memory address) to the class its in.First, an object is instantiated :

//MEMORY ALLOCATION

//FUNCTION POINTERS

	/*
	void * function1(void) declares a function which returns void *,

	void(*function2)(void) declares a function pointer to a function which returns void.*/

void main()
{



	void * fp = HelloWorld;
}
void HelloWorld()
{
	std::cout << "hello world";
}

