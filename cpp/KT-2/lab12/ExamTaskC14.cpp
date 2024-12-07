/*ExamTaskC14. Ќа вход подаютс€ сведени€ о клиентах фитнес-центра.
¬ первой строке указываетс€ код K одного из клиентов, во второй строке Ч целое число N,
а кажда€ из последующих N строк имеет формат <√од><Ќомер мес€ца>< од клиента><ѕродолжительность зан€тий(в часах)>
¬се данные целочисленные.
«начение года лежит в диапазоне от 2000 до 2010, код клиента Ч в диапазоне 10-99, продолжительность зан€тий Ч в диапазоне 1-30.
ƒл€ каждого года, в котором клиент с кодом K посещал центр, определить мес€ц,
в котором продолжительность зан€тий данного клиента была наименьшей дл€ данного года
(если таких мес€цев несколько, то выбирать мес€ц с наибольшим номером; мес€цы с нулевой продолжительностью зан€тий не учитывать).
—ведени€ о каждом годе выводить на новой строке в следующем пор€дке: год, номер мес€ца, продолжительность зан€тий в этом мес€це.
”пор€дочить сведени€ по возрастанию номера года. ≈сли данные о клиенте с кодом K отсутствуют, то вывести строку "Ќет данных"*/
#include <iostream>
#include <ctime>

using namespace std;

struct Client {
	int year; // год
	int month; // номер мес€ца
	int clientCode; // код клиента
	int duration; // продолжительность зан€тий
};

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int K;
	cout << "¬ведите код клиента K в диапазоне от 10 до 99: ";
	cin >> K;

	if (K < 10 || K > 99) {
		cout << "Ќекорректный ввод!" << endl;
		return 1;
	}

	int N;
	cout << "¬ведите количество строк N: ";
	cin >> N;

	Client* clients = new Client[N];

	cout << "ƒанные о клиентах фитнес-центра:" << endl;

	// «аполнение массива структур случайными значени€ми
	for (int i = 0; i < N; i++) {
		clients[i].year = 2000 + rand() % 11;
		clients[i].month = rand() % 12 + 1;
		clients[i].clientCode = 10 + rand() % 90;
		clients[i].duration = rand() % 30 + 1;

		cout << clients[i].year << " " << clients[i].month << " " << clients[i].clientCode << " " << clients[i].duration << endl;
	}

	// —ортировка массива структур по возрастанию года
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (clients[j].year > clients[j + 1].year) {
				Client temp = clients[j];
				clients[j] = clients[j + 1];
				clients[j + 1] = temp;
			}
		}
	}

	// ¬ывод отсортированного массива структур
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
		cout << "Ќет данных" << endl;
	}

	delete[] clients;

	return 0;
}