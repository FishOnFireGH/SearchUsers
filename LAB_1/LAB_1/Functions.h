#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int NumberOfLines(); //определение количества файлов базы данных
void WriteWays(string *&Ways, int N); //запись путей баз данных в массив строк
void ShowMas(string *&Mas, int N); //вывод массива строк на консоль
void AddingWayFile(string *&Ways, int &N, string NewWay); //добавление пути к файлу 
void RemovingWayFile(string *&Ways, int &N, int DeleteWay); //удаление пути к файлу
void FindUser(string Ways[], int N, string login, string email, string numberPhone, string name); //Функция поиска пользователей
void Menu();
void MenuFind();
void ShowBuffer();