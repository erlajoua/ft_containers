#include "Vector.hpp"
#include "Iterator.hpp"


void print_intvc(ft::Vector<int> &vc)
{
	std::cout << "Vector contains :";
	for (size_t i = 0; i < vc.size() ; i++)
		std::cout << " " << vc[i];
	std::cout << '\n';
}

int main(void)
{

	//@constructors
	
	std::cout << "=== CONSTRUCTORS ===" << '\n';

	std::cout << "\nCase 1: (empty)\n";
	ft::Vector<int> empty;
	std::cout << "-> Size = " << empty.size() << '\n';
	std::cout << "-> Capacity = " << empty.capacity() << '\n';
	std::cout << "-> Is empty = " << empty.empty() << '\n';
	print_intvc(empty);

	std::cout << "\nCase 2: (7, 5)\n";
	ft::Vector<int> one(7, 5);
	std::cout << "-> Size = " << one.size() << '\n';
	std::cout << "-> Capacity = " << one.capacity() << '\n';
	std::cout << "-> Is empty = " << one.empty() << '\n';
	print_intvc(one);

	std::cout << "\nCase 3: (begin, end) of last vector\n";
	ft::Vector<int> two(one.begin(), one.end());
	std::cout << "-> Size = " << two.size() << '\n';
	std::cout << "-> Capacity = " << two.capacity() << '\n';
	std::cout << "-> Is empty = " << two.empty() << '\n';
	print_intvc(two);

	
	//@iterator , @begin , @end, @push_back

	std::cout << "\n=== ITERATOR, BEGIN, END ===\n\n";
	ft::Vector<int> test1;

	test1.push_back(45);
	test1.push_back(47);
	test1.push_back(41);
	test1.push_back(666);
	test1.push_back(667);
	print_intvc(test1);

	//@at

	std::cout << "=== AT ===" << '\n';
	std::cout << "* Test out of range! *\n";
	ft::Vector<int> test2(10);

	for (unsigned i = 0; i< test2.size(); i++)
		test2.at(i) = i;
	try
	{
		std::cout << test2.at(42) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print_intvc(test2);

	//@front, @back

	std::cout << "\n=== FRONT, BACK ===\n\n";
	std::cout << "-> Front = " << test2.front() << '\n';
	std::cout << "-> Back = " << test2.back() << '\n';

	//@capacity

	std::cout << "\n=== CAPACITY ===\n\n";
	std::cout << "-> Capacity (vect1) = " << test1.capacity() << '\n';
	std::cout << "-> Capacity (vect2) = " << test2.capacity() << '\n';

	//@clear, @empty

	std::cout << "\n=== CLEAR, EMPTY ===\n\n";
	std::cout << "-> Empty = " << test2.empty() << '\n';
	test2.clear();
	std::cout << "-> Empty = " << test2.empty() << '\n';
	print_intvc(test2);

	//@erase

	std::cout << "\n=== ERASE ===\n\n";
	print_intvc(test1);
	std::cout << "* Erase! *\n";
	test1.erase(test1.begin(), test1.begin() + 2);
	print_intvc(test1);

	//@insert (3 ways)

	std::cout << "\n=== INSERT ===\n\n";
	ft::Vector<int> myvector(3, 100);
	std::cout << "* New vector contains 3 values of 100 *\n";
	print_intvc(myvector);
	ft::Vector<int>::iterator it;
	it = myvector.begin();
	std::cout << "* Insert from the begin, the value 200 *\n";
	it = myvector.insert(it, 200);
	print_intvc(myvector);
	it = myvector.begin();
	std::cout << "* Insert from the begin, 2 values of 300 *\n";
	myvector.insert(it, 2, 300); //@1
	print_intvc(myvector);
	it = myvector.begin();
	ft::Vector<int> anothervector(2, 400);
	std::cout << "* Creating another vector that contains 2 values of 400 *\n";
	std::cout << "* Insert from the begin+2, the value begin, to end of the another vector *\n";
	myvector.insert(it + 2, anothervector.begin(), anothervector.end()); //@2
	print_intvc(myvector);
	int myarray [] = {501, 502, 503};
	std::cout << "* Creating an array of integers, values {501, 502, 503} *\n";
	std::cout << "* Insert from the begin, the first value of the array, until the first+3th value *\n";
	myvector.insert(myvector.begin(), myarray, myarray + 3);
	print_intvc(myvector);

	//@rbegin, @rend

	std::cout << "\n=== RBEGIN, REND ===\n\n";
	std::cout << "-> Iteration reverse on the vector :";
	for (ft::Vector<int>::reverse_iterator rit = myvector.rbegin(); rit != myvector.rend(); rit++)
		std::cout << " " << *rit;
	std::cout << '\n';

	//@max_size

	std::cout << "\n=== MAX_SIZE ===\n\n";
	std::cout << "-> Max size = " << myvector.max_size() << '\n';
	std::cout << "-> Max size = " << test1.max_size() << '\n';
	std::cout << "-> Max size = " << test2.max_size() << '\n';

	//@operator=, @operator[], @push_back, @pop_back

	std::cout << "\n=== OPERATOR '=', '[]', POP/PUSH_BACK ===\n\n";

	ft::Vector<int> Foo(4, 17);
	ft::Vector<int> Fuu;
	ft::Vector<int> Bar(6, 67);

	Foo = Bar;
	Fuu = Foo;
	print_intvc(Foo);
	print_intvc(Fuu);
	std::cout << "* Push_back (667) *\n";
	Fuu.push_back(667);
	print_intvc(Fuu);
	std::cout << "* Pop_back X3 *\n";
	Fuu.pop_back();
	Fuu.pop_back();
	Fuu.pop_back();
	print_intvc(Fuu);
	Fuu[0] = -666;
	Fuu[2] = -667;
	print_intvc(Fuu);

	//@capacity, @reserve, @resize

	std::cout << "\n=== RESERVE, RESIZE ===\n\n";
	ft::Vector<int> bigcap(20);
	print_intvc(bigcap);
	std::cout << "-> Capacity = " << bigcap.capacity() << '\n';
	std::cout << "* Reserve! (4242) *\n";
	bigcap.reserve(4242);
	std::cout << "-> Capacity = " << bigcap.capacity() << '\n';
	print_intvc(bigcap);
	std::cout << "* Resize ! (30) *\n";
	bigcap.resize(30);
	std::cout << "-> Size = " << bigcap.size() << '\n';
	print_intvc(bigcap);
	std::cout << "* Resize ! (5) *\n";
	bigcap.resize(5);
	std::cout << "-> Size = " << bigcap.size() << '\n';
	print_intvc(bigcap);

	//@swap

	std::cout << "\n=== SWAP ===\n\n";

	std::cout << "\n1) ";
	print_intvc(myvector);
	std::cout << "   Size = " << myvector.size() << '\n';
	std::cout << "   Capacity = " << myvector.capacity() << '\n';
	std::cout << "\n2) ";
	print_intvc(test1);
	std::cout << "   Size = " << test1.size() << '\n';
	std::cout << "   Capacity = " << test1.capacity() << '\n';
	ft::Vector<int>::iterator itera = myvector.begin();
	std::cout << "   Pointer before swap = " << *itera << '\n';

	std::cout << "\n* Swap! *\n\n";
	myvector.swap(test1);


	std::cout << "\n1) ";
	print_intvc(myvector);
	std::cout << "   Size = " << myvector.size() << '\n';
	std::cout << "   Capacity = " << myvector.capacity() << '\n';
	std::cout << "\n2) ";
	print_intvc(test1);
	std::cout << "   Size = " << test1.size() << '\n';
	std::cout << "   Capacity = " << test1.capacity() << '\n';
	std::cout << "   Pointer after swap = " << *itera << '\n';
	return (0);
}
