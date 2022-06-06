#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

ifstream in;
ofstream out;

void display_trace(string player)
{
	cout << "[START]                    " + player + "                    [FINISH]\tНачало\n";
}

void move_player(string player)
{
	string start = "[START]";
	string finish = "[FINISH]";
	int trace1 = 20;
	int trace2 = 20;

	for (int i = 0; i <= 1000; i++)
	{
		int random_direction = rand() % 2;

		if (i == 1000)
		{
			cout << "ты проиграл";
			break;
		}
		else
		{
			if (trace2 == 0) //проверка на победу (дошел до финиша)
			{
				cout << "ты выиграл за " << i << " попыток\n";
				in.open("records.txt");
				int value;
				in >> value;
				in.close();
				
				if (i < value)
				{
					out.open("records.txt");
					if (out.is_open())
					{
						out.write("", 0);
						out << i;
					}
					out.close();
					cout << "вы поставили новый рекорд: " << i;
				}
				break;

			}
			else //просто идет
			{
				if (trace1 == 0) //находится у старта (пропуск шага)
				{
					trace1++;
					trace2--;
				}
				else
				{
					if (random_direction == 0)
					{
						trace1--;
						trace2++;
					}
					else if (random_direction == 1)
					{
						trace1++;
						trace2--;
					}
					cout << start;
					for (int i = 0; i < trace1; i++)
					{
						cout << " ";
					}
					cout << player;
					for (int i = 0; i < trace2; i++)
					{
						cout << " ";
					}
					cout << finish << "\t" << i+1 << endl;
				}
			}
		}
	}
	
}

void game(string player)
{
	display_trace(player);
	move_player(player);
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(nullptr));

	cout << "Введите своего игрока: ";
	string player; cin >> player;

	game(player);



}


