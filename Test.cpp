#include"MyString.h"
int main()
{
	cout << "\t\tDAY LA CAC BO TEST EM LAY TU TRANG CPLUSPLUS.COM\n" << endl;

	cout << "\t\tDAY LA TEST KHOI TAO" << endl;
	MyString s0("Initial string");
	MyString s1;
	MyString s2(s0);
	MyString s3(s0, 8, 3);
	MyString s4("A character sequence");
	MyString s5("Another character sequence", 12);
	MyString s6a(10, 'x');
	MyString s6b(10, 42);    
	MyString s7(s0.begin(), s0.begin() + 7);
	std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
	std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
	std::cout << "\ns6b: " << s6b << "\ns7: " << s7 << '\n';

	cout << "\t\tDAY LA TEST PHUONG THUC INSERT" << endl;
	MyString str = "to be question";
	MyString str2 = "the ";
	MyString str3 = "or not to be";
	MyString::iterator it;
	str.insert(6, str2);                 // to be (the )question
	str.insert(6, str3, 3, 4);             // to be (not )the question
	str.insert(10, "that is cool", 8);    // to be not (that is )the question
	str.insert(10, "to be ");            // to be not (to be )that is the question
	str.insert(15, 1, ':');               // to be not to be(:) that is the question
	it = str.insert(str.begin() + 5, ','); // to be(,) not to be: that is the question
	str.insert(str.end(), 3, '.');       // to be, not to be: that is the question(...)
	str.insert(it + 2, str3.begin(), str3.begin() + 3); // (or )
	std::cout << str << '\n';

	cout << "\t\tDAY LA TEST PHUONG THUC REPLACE" << endl;
	MyString base = "this is a test string.";
	str2 = "n example";
	str3 = "sample phrase";
	MyString str4 = "useful.";

	// replace signatures used in the same order as described above:
	str = base;           // "this is a test string."
	str.replace(9, 5, str2);          // "this is an example string." (1)
	str.replace(19, 6, str3, 7, 6);     // "this is an example phrase." (2)
	str.replace(8, 10, "just a");     // "this is just a phrase."     (3)
	str.replace(8, 6, "a shorty", 7);  // "this is a short phrase."    (4)
	str.replace(22, 1, 3, '!');        // "this is a short phrase!!!"  (5)
	str.replace(str.begin(), str.end() - 3, str3);                    // "sample phrase!!!"      (1)
	str.replace(str.begin(), str.begin() + 6, "replace");             // "replace phrase!!!"     (3)
	str.replace(str.begin() + 8, str.begin() + 14, "is coolness", 7);    // "replace is cool!!!"    (4)
	str.replace(str.begin() + 12, str.end() - 4, 4, 'o');                // "replace is cooool!!!"  (5)
	str.replace(str.begin() + 11, str.end(), str4.begin(), str4.end());// "replace is useful."    (6)
	std::cout << str << '\n';

	cout << "\t\tDAY LA TEST PHUONG THUC ASSIGN" << endl;

	base = "The quick brown fox jumps over a lazy dog.";
	str.assign(base);
	std::cout << str << '\n';

	str.assign(base, 10, 9);
	std::cout << str << '\n';         // "brown fox"

	str.assign("pangrams are cool", 7);
	std::cout << str << '\n';         // "pangram"

	str.assign("c-string");
	std::cout << str << '\n';         // "c-string"

	str.assign(10, '*');
	std::cout << str << '\n';         // "**********"

	//str.assign<int>(10, 0x2D);
	//std::cout << str << '\n';         // "----------"

	str.assign(base.begin() + 16, base.end() - 12);// "fox jumps over"


	std::cout << str << '\n';

	cout << "\t\tDAY LA TEST PHUONG THUC COMPARE" << endl;
	MyString str1 = "green apple";
	str2 = "red apple";
	cout << str1 << endl;
	cout << str2 << endl;
	if (str1.compare(str2) != 0)
		std::cout << str1 << " is not " << str2 << '\n';

	if (str1.compare(6, 5, "apple") == 0)
		std::cout << "still, " << str1 << " is an apple\n";

	if (str2.compare(str2.size() - 5, 5, "apple") == 0)
		std::cout << "and " << str2 << " is also an apple\n";

	if (str1.compare(6, 5, str2, 4, 5) == 0)
		std::cout << "therefore, both are apples\n";

	cout << "\t\tDAY LA TEST TOAN TU OPERATOR + " << endl;
	MyString firstlevel("com");
	MyString secondlevel("cplusplus");
	MyString scheme("http://");
	MyString hostname;
	MyString url;

	hostname = "www." + secondlevel + '.' + firstlevel;
	url = scheme + hostname;

	std::cout << url << '\n';

	cout << "\t\tDAY LA TEST CAC PHUONG THUC ERASE" << endl;
	str = "This is an example sentence.";
	std::cout << str << '\n';
	// "This is an example sentence."
	str.erase(10, 8);                        //            ^^^^^^^^
	std::cout << str << '\n';
	// "This is an sentence."
	str.erase(str.begin() + 9);               //           ^
	std::cout << str << '\n';
	// "This is a sentence."
	str.erase(str.begin() + 5, str.end() - 9);  //       ^^^^^
	std::cout << str << '\n';

	cout << "\t\tDAY LA TEST CAC PHUONG THUC XUAT NHAP" << endl;
	cout << "Nhap bang getline: "; getline(cin, str);
	cout << "Xuat: " << str << endl;

	cout << "Nhap bang cin>>: "; cin >> str;
	cout << "Xuat: " << str << endl;
	system("pause");
	return 0;
}
