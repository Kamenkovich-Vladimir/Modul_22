#include <iostream>
#include <map>

std::map <char, int> create_map(std::string word) {
	std::map <char, int> mw;
	for (int i = 0; i < word.length(); i++) {
		mw[word[i]] = i;
	}
	return mw;
}

bool check_anagram(std::string first_word, std::string second_word) {
	std::map <char, int> mw1, mw2;
	if (first_word.length() == second_word.length()) {
		mw1 = create_map(first_word);
		mw2 = create_map(second_word);

		std::map<char, int>::iterator it1 = mw1.begin();
		std::map<char, int>::iterator it2 = mw2.begin();
		for (int i = 0; i < first_word.length(); i++) {
			if (it1->first != it2->first) {
				return false;
			}
		}
		return true;
	}
	else
		return false;
}
int main()
{
	std::cout << "***************** Registration office *****************\n\n";

	
	std::string first_word, second_word;
	std::cout << "Enter two words by space for checking: ";
	std::cin >> first_word >> second_word;
	
	if(check_anagram(first_word, second_word))
		std::cout << "True";
	else
		std::cout << "False";
}