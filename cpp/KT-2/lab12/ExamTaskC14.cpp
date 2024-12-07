/*ExamTaskC14. �� ���� �������� �������� � �������� ������-������.
� ������ ������ ����������� ��� K ������ �� ��������, �� ������ ������ � ����� ����� N,
� ������ �� ����������� N ����� ����� ������ <���><����� ������><��� �������><����������������� �������(� �����)>
��� ������ �������������.
�������� ���� ����� � ��������� �� 2000 �� 2010, ��� ������� � � ��������� 10-99, ����������������� ������� � � ��������� 1-30.
��� ������� ����, � ������� ������ � ����� K ������� �����, ���������� �����,
� ������� ����������������� ������� ������� ������� ���� ���������� ��� ������� ����
(���� ����� ������� ���������, �� �������� ����� � ���������� �������; ������ � ������� ������������������ ������� �� ���������).
�������� � ������ ���� �������� �� ����� ������ � ��������� �������: ���, ����� ������, ����������������� ������� � ���� ������.
����������� �������� �� ����������� ������ ����. ���� ������ � ������� � ����� K �����������, �� ������� ������ "��� ������"*/
#include <iostream>
#include <ctime>

using namespace std;

struct Client {
	int year; // ���
	int month; // ����� ������
	int clientCode; // ��� �������
	int duration; // ����������������� �������
};

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int K;
	cout << "������� ��� ������� K � ��������� �� 10 �� 99: ";
	cin >> K;

	if (K < 10 || K > 99) {
		cout << "������������ ����!" << endl;
		return 1;
	}

	int N;
	cout << "������� ���������� ����� N: ";
	cin >> N;

	Client* clients = new Client[N];

	cout << "������ � �������� ������-������:" << endl;

	// ���������� ������� �������� ���������� ����������
	for (int i = 0; i < N; i++) {
		clients[i].year = 2000 + rand() % 11;
		clients[i].month = rand() % 12 + 1;
		clients[i].clientCode = 10 + rand() % 90;
		clients[i].duration = rand() % 30 + 1;

		cout << clients[i].year << " " << clients[i].month << " " << clients[i].clientCode << " " << clients[i].duration << endl;
	}

	// ���������� ������� �������� �� ����������� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (clients[j].year > clients[j + 1].year) {
				Client temp = clients[j];
				clients[j] = clients[j + 1];
				clients[j + 1] = temp;
			}
		}
	}

	// ����� ���������������� ������� ��������
	int minDuration = 31;
	int minMonth = 0;
	int year = 0;
	bool flag = false;

	for (int i = 0; i < N; i++) {
		if (clients[i].clientCode == K) {
			if (clients[i].year != year) {
				year = clients[i].year;
				minDuration = 31;
				minMonth = 0;
				flag = false;
			}
			if (clients[i].duration < minDuration && clients[i].duration != 0) {
				minDuration = clients[i].duration;
				minMonth = clients[i].month;
				flag = true;
			}
		}
	}

	if (flag) {
		cout << year << " " << minMonth << " " << minDuration << endl;
	}
	else {
		cout << "��� ������" << endl;
	}

	delete[] clients;

	return 0;
}