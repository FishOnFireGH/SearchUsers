#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int NumberOfLines(); //����������� ���������� ������ ���� ������
void WriteWays(string *&Ways, int N); //������ ����� ��� ������ � ������ �����
void ShowMas(string *&Mas, int N); //����� ������� ����� �� �������
void AddingWayFile(string *&Ways, int &N, string NewWay); //���������� ���� � ����� 
void RemovingWayFile(string *&Ways, int &N, int DeleteWay); //�������� ���� � �����
void FindUser(string Ways[], int N, string login, string email, string numberPhone, string name); //������� ������ �������������
void Menu();
void MenuFind();
void ShowBuffer();