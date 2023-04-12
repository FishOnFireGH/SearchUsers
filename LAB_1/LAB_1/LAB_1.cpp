#include "Functions.h"


int ActionMenu, ActionMenuFind;
void Menu()
{
	setlocale(LC_ALL, "ru");

	cout << "\t\tЗдравствуйте!" << endl;
	cout << "\tВас приветствует LvumbaCorporation." << endl;
	cout << "\t\tЧто вы хотите сделать?" << endl;
	cout << "==================================================" << endl;
	cout << "[1] - Узнать, в скольких файлах содержатся данные?" << endl;
	cout << "[2] - Показать путь ко всем файлам базы данных" << endl;
	cout << "[3] - Удалить путь к файлу базы данных" << endl;
	cout << "[4] - Добавить путь к файлу базы данных" << endl;
	cout << "[5] - Поиск пользователей" << endl;
	cout << "[6] - Очистка буфера" << endl;
	cout << "[7] - Посмотреть содержимое буфера" << endl;
	cout << "==================================================" << endl;
	cout << "[121] - Выйти из программы" << endl << endl;
	cout << "ВАШЕ ДЕЙСТВИЕ -> ";
	cin >> ActionMenu;
}


void MenuFind()
{
	setlocale(LC_ALL, "ru");

	cout << "Укажите, по каким параметрам вы хотите искать пользователей" << endl;
	cout << "===========================================================" << endl;
	cout << "[0] - Показать параметры поиска" << endl;
	cout << "[1] - Указать искомый логин" << endl;
	cout << "[2] - Указать искомую почту" << endl;
	cout << "[3] - Указать искомый номер телефона" << endl;
	cout << "[4] - Указать искомое имя пользователя" << endl;
	cout << "[5] - Начать поиск" << endl;
	cout << "[6] - Вернуться в основное меню" << endl;
	cout << "===========================================================" << endl;
	cout << "" << endl;
	cout << "ВАШЕ ДЕЙСТВИЕ -> ";
	cin >> ActionMenuFind;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	//locale::global(locale("ru_RU.UTF-8"));

	int N; //размер массива
	N = NumberOfLines();
	string *Ways = new string[N];
	string NewWay;
	//////////////////////////////////////////////////////////////
	string login = "(Введите сами)", email = "(Введите сами)", numberPhone = "(Введите сами)", name = "(Введите сами)";
	//////////////////////////////////////////////////////////////
	char Answer;
	int DeleteWay;
	ofstream Buffer;

	Menu();

	while (ActionMenu != 121)
	{
		switch (ActionMenu)
		{
		case 1:
			system("cls"); // очистка консоли

			cout << "Файлов базы данных: " << N << endl;

			system("pause"); // задержка консоли
			system("cls"); // очистка консоли

			Menu();
			break;
		case 2:
			system("cls"); // очистка консоли

			WriteWays(Ways, N);
			ShowMas(Ways, N);
			cout << endl;

			system("pause"); // задержка консоли
			system("cls"); // очистка консоли

			Menu();
			break;
		case 3:
			system("cls"); // очистка консоли

			WriteWays(Ways, N);
			ShowMas(Ways, N);
			cout << endl;
			cout << "Введите номер строки файла, который желаете удалить из базы: ";
			cin >> DeleteWay;
			cout << endl;
			system("cls"); // очистка консоли

			RemovingWayFile(Ways, N, DeleteWay);
			ShowMas(Ways, N);
			cout << endl;
			//cout << "Желаете продолжить удаление? [y/n]: ";
			//cin >> Answer;
			cout << endl;

			system("pause"); // задержка консоли
			system("cls"); // очистка консоли

			Menu();
			break;
		case 4:
			system("cls"); // очистка консоли

			WriteWays(Ways, N);
			cout << "Введите путь к новому файлу базы данных:" << endl;
			cout << "(Без пробелов, если они есть в пути - уберите!)" << endl;
			cout << "NewWay$: ";
			cin >> NewWay;
			AddingWayFile(Ways, N, NewWay);

			system("cls"); // очистка консоли

			cout << "Результат положительный:" << endl;
			ShowMas(Ways, N);
			cout << endl;

			system("pause"); // задержка консоли
			system("cls"); // очистка консоли

			Menu();
			break;
		case 5: //***ПОИСК ПОЛЬЗОВАТЕЛЕЙ
			system("cls"); // очистка консоли

			WriteWays(Ways, N);

			
			MenuFind();


			while (ActionMenuFind != 6)
			{
				switch (ActionMenuFind)
				{
				case 0:
					system("cls"); // очистка консоли

					cout << "Данные, по которым будет производиться поиск: " << endl << endl;
					cout << "login$: " << login << endl;
					cout << "email$: " << email << endl;
					cout << "numberPhone$: " << numberPhone << endl;
					cout << "name: " << name << endl << endl;

					system("pause"); // задержка консоли
					system("cls"); // очистка консоли

					MenuFind();
					break;
				case 1:
					cout << "login$: ";
					cin >> login;

					system("cls"); // очистка консоли

					MenuFind();
					break;
				case 2:
					cout << "email$: ";
					cin >> email;

					system("cls"); // очистка консоли
					MenuFind();
					break;
				case 3:
					cout << "numberPhone$: ";
					cin >> numberPhone;

					system("cls"); // очистка консоли
					MenuFind();
					break;
				case 4:
					cout << "name$: " << endl;
					name = "";
					cout << "\tФамилия: ";
					cin >> NewWay;
					name = name + NewWay + " ";
					cout << "\tИмя: ";
					cin >> NewWay;
					name = name + NewWay + " ";
					cout << "\tОтчество: ";
					cin >> NewWay;
					name = name + NewWay;

					system("cls"); // очистка консоли

					MenuFind();
					break;
				case 5:
					system("cls"); // очистка консоли

					FindUser(Ways, N, login, email, numberPhone, name);//Функция поиска пользователей
					system("cls"); // очистка консоли
					cout << "Просмотрено: " << 100  << "%" << endl;

					system("pause"); // задержка консоли
					system("cls"); // очистка консоли

					cout << "Результаты ваших поисков: " << endl;
					ShowBuffer();

					system("pause"); // задержка консоли
					system("cls"); // очистка консоли

					MenuFind();
					break;
				default:
					cout << endl << "Ну поздравляю, вы ввели неправильную команду" << endl;
					cout << "\tПожалуйста, повторите попытку" << endl << endl;
					system("pause"); // задержка консоли
					system("cls"); // очистка консоли

					MenuFind();

					break;
				}
			}

			system("pause"); // задержка консоли
			system("cls"); // очистка консоли

			Menu();
			break;//***ПОИСК ПОЛЬЗОВАТЕЛЕЙ
		case 6:
			Buffer.open("Buffer.txt");
			cout << "Очистка буфера прошла успешно" << endl;

			system("pause"); // задержка консоли
			system("cls"); // очистка консоли

			Menu();
			break;
		case 7:
			system("cls"); // очистка консоли

			cout << "Результаты ваших поисков: " << endl;
			ShowBuffer();

			system("pause"); // задержка консоли
			system("cls"); // очистка консоли

			Menu();
			break;

		default:
			cout << endl << "Ну поздравляю, вы ввели неправильную команду" << endl;
			cout << "\tПожалуйста, повторите попытку" << endl << endl;
			system("pause"); // задержка консоли
			system("cls"); // очистка консоли

			Menu();
			break;
		}
	}
	

	delete[] Ways;
	return 0;
}


/*
* .eof - конец файла
* .is_open - проверка открытия файла
* .get - посимвольное чтение файла
* getline(откуда считываем, куда записываем, разделитель) - позволяет считывать строки вместе с пробелами
* .getline - 
*/

/*	if (Answer == 'y')
	{
		RemovingWayFile(Ways, N, DeleteWay);
	}
	else if (Answer == 'n')
	{

	}
	else
	{
		cout << "Ответ неверный, повторите попытку";
	}*/