#include "Functions.h"


int NumberOfLines()
{
	ifstream Test("WaysFiles.txt");

	string ch;
	int size = 0;
	while (!Test.eof())
	{
		getline(Test, ch);
		size++;
	}
	//size--;
	Test.close();
	return size;
}

void WriteWays(string *&Ways, int N)
{
	ifstream WaysFiles;
	WaysFiles.open("WaysFiles.txt");

	/*if (!WaysFiles.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
	}*/

	int n = 0;
	while (!WaysFiles.eof())
	{
		string str = "";
		getline(WaysFiles, str);
		Ways[n] = str;
		//cout << Ways[n] << endl;
		n++;
	}

	WaysFiles.close();
}

void ShowMas(string *&Mas, int N)
{
	for (int i = 0; i < N; i++)
	{			
		cout << i << ". " << Mas[i] << endl;
	}
}

void AddingWayFile(string *&Ways, int &N, string NewWay)
{
	string *newWays = new string[N + 1];
	for (int i = 0; i < N; i++)
	{
		newWays[i] = Ways[i];
	}

	newWays[N] = NewWay;
	N++;

	delete[] Ways;

	Ways = newWays;

	//добавили в массив, но не добавили в файл

	ofstream Test;
	Test.open("WaysFiles.txt", ofstream::app);// открываем файл при помощи 'app' для добавления данных

	Test << endl << NewWay;

	Test.close();
}

void RemovingWayFile(string*& Ways, int& N, int DeleteWay)
{
	N--;
	string* newWays = new string[N];
	for (int i = 0; i < DeleteWay; i++)
	{
		newWays[i] = Ways[i];
	}

	for (int i = DeleteWay + 1; i < N + 1; i++)
	{
		newWays[i - 1] = Ways[i];
	}

	
	delete[] Ways;
	Ways = newWays;

	ofstream Test;
	Test.open("WaysFiles.txt");// удаляем файл и создаём такой же, но без удалённоё строки


	for (int i = 0; i < N - 1; i++)
	{
		Test << Ways[i] << endl;
	}
	Test << Ways[N - 1];

	Test.close();
}

void FindUser(string Ways[], int N, string login, string email, string numberPhone, string name)
{
	setlocale(LC_ALL, "ru");
	//locale::global(locale("ru_RU.UTF-8"));


	char delimiter = ',';

	//ShowMas(Ways, N);

	ofstream Buffer;// сюда сохраняем результаты поиска
	Buffer.open("Buffer.txt", ofstream::app);


	cout << 0 << endl;

	for (int i = 0; i < N; i++)
	{
		string wildberries_id, phone_number, wildberries_name;
		string	wildberries_comment, wildberries_email, wildberries_lat;
		string	wildberries_lon, wildberries_address, wildberries_geohash, old_id;
		string	wildberries_seq_pn_count, wildberries_seq_pn_geo_count;
		ifstream Way;
		Way.open(Ways[i]);
		
	/*	if (!Way.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
		}
		else
		{
			cout << "Файл открыт!" << endl;
		}

		system("pause");*/

		while (!Way.eof())
		{
			getline(Way, wildberries_id, delimiter);
			getline(Way, phone_number, delimiter);
			getline(Way, wildberries_name, delimiter);
			getline(Way, wildberries_comment, delimiter);
			getline(Way, wildberries_email, delimiter);
			getline(Way, wildberries_lat, delimiter);
			getline(Way, wildberries_lon, delimiter);
			delimiter = '"';
			getline(Way, wildberries_address, delimiter);
			getline(Way, wildberries_address, delimiter);
			delimiter = ',';
			getline(Way, wildberries_geohash, delimiter);
			getline(Way, wildberries_geohash, delimiter);
			getline(Way, old_id, delimiter);
			getline(Way, wildberries_seq_pn_count, delimiter);
			getline(Way, wildberries_seq_pn_geo_count);

			if (wildberries_id == login || wildberries_email == email || phone_number == numberPhone || wildberries_name == name)
			{
				Buffer << "============================================" << endl;
				Buffer << "wildberries_id: " << wildberries_id << endl;
				Buffer << "phone_number: " << phone_number << endl;
				Buffer << "wildberries_name: " << wildberries_name << endl;
				Buffer << "wildberries_comment: " << wildberries_comment << endl;
				Buffer << "wildberries_email: " << wildberries_email << endl;
				Buffer << "wildberries_lat: " << wildberries_lat << endl;
				Buffer << "wildberries_lon: " << wildberries_lon << endl;
				Buffer << "wildberries_address: " << wildberries_address << endl;
				Buffer << "wildberries_geohash: " << wildberries_geohash << endl;
				Buffer << "old_id: " << old_id << endl;
				Buffer << "wildberries_seq_pn_count: " << wildberries_seq_pn_count << endl;
				Buffer << "wildberries_seq_pn_geo_count: " << wildberries_seq_pn_geo_count << endl << endl;
			}
		}
		
		system("cls");
		cout << "Просмотрено: " << ((100 / N) * (i + 1)) << "%" << endl;

		Way.close();
	}

	Buffer.close();
}

void ShowBuffer()
{
	setlocale(LC_ALL, "ru");
	locale::global(locale("ru_RU.UTF-8"));

	ifstream Buffer;
	Buffer.open("Buffer.txt");

	if (!Buffer.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
	}

	string buffer;

	while (!Buffer.eof())
	{
		buffer = "";
		getline(Buffer, buffer);
		cout << buffer << endl;
	}

	Buffer.close();
}