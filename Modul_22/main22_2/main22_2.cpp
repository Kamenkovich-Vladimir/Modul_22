#include <iostream>
#include <map>

int main()
{
	std::cout << "***************** Registration office *****************\n\n";

	std::multimap <std::string, int> queue;
	std::string last_name;
	int i = 0;
	while (true) {	//Лечим до последнего больного (выход из программы - очередь пуста)
		//Ожидаем поступления в очередь посетителя или команды Next
		std::cout << "To register in the queue, enter the last name of the visitor. To call the registry, enter the 'next' command.\n";
		std::cin >> last_name;
		if (last_name != "next") {
			queue.insert(std::pair<std::string,int> (last_name, i));
			i++;
		}
		else {
			std::map<std::string, int>::iterator it = queue.begin();
			if (it == queue.end()) {
				std::cout << "The queue is empty.Exit programm.\n\n";
				break;
			}
			else {
				std::cout << it->first << " is called to the registry.\n\n";
				queue.erase(it);
			}
		}
	}
}