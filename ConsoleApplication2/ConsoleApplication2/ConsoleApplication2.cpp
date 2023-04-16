#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
//структура для хранения информации об игроке
struct Player {
    string name;
    string surname;
    string position;
    int assists;
    int yellow_cards;
    int red_cards;
    int games_played;
};

//функция для авторизации пользователя
int login() {
    int Admin = 1;
    string username, password;
    cout << "Введите имя пользователя: ";
    cin >> username;
    cout << "Введите пароль: ";
    cin >> password;
    //проверяем, существует ли пользователь с такими данными
    ifstream file("users.txt");
    string user, pass;
    while (file >> user >> pass) {
        if (username == "admin" && password == "7788") {
            cout << "Добро пожаловать, администратор" << endl;
            return Admin;
        }
        if (user == username && pass == password) {
            cout << "Добро пожаловать, " << username << "!" << endl;
            return Admin = 0;
        }
        else {
            return Admin = 3;
        }

    }
}
int count_lines_in_file() {
    ifstream file("players.txt");

    if (!file.is_open()) {
        cout << "Ошибка при открытии файла " << "players.txt" << endl;
        return -1;
    }

    string line;
    int line_count = 0;

    while (getline(file, line)) {
        line_count++;
    }

    file.close();
    return line_count;
}

//функция для регистрации нового пользователя
void registerUser() {
    string username, password;
    cout << "Введите имя пользователя: ";
    cin >> username;
    cout << "Введите пароль: ";
    cin >> password;
    //добавляем пользователя в файл с пользователями
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    cout << "Пользователь успешно зарегистрирован." << endl;
}
//функция для добавления новой карточки игрока
void addPlayer() {
    Player player;
    cout << "Введите имя игрока: ";
    cin >> player.name;
    cout << "Введите фамилию игрока: ";
    cin >> player.surname;
    cout << "Введите позицию игрока: ";
    cin >> player.position;
    cout << "Введите количество голевых передач игрока: ";
    cin >> player.assists;
    cout << "Введите количество желтых карточек игрока: ";
    cin >> player.yellow_cards;
    cout << "Введите количество красных карточек игрока: ";
    cin >> player.red_cards;
    cout << "Введите количество сыгранных матчей игроком: ";
    cin >> player.games_played;
    //открываем файл с игроками для добавления новой информации
    ofstream file("players.txt", ios::app);
    file << player.name << " " << player.surname << " " << player.position << " "
        << player.assists << " " << player.yellow_cards << " "
        << player.red_cards << " " << player.games_played << endl;
    cout << "Информация о игроке успешно добавлена." << endl;
}
void PlayersOutput() {
    ifstream file("players.txt");
    string line;
    int line_count = 0;
    Player player;
    while (getline(file, line)) {
        string firstWord;
        istringstream ss(line);
        ss >> firstWord;
        cout << "Игрок " << line_count + 1 << ": " << firstWord << " ";
        ss >> firstWord;
        cout << firstWord << endl;
        line_count++;
    }
    file.close();
}
void FindPlayer(int numplayer) {
    string pl;
    cout << "Введите имя игрока: ";
    cin >> pl;
    ifstream file("players.txt");
    string line;
    int line_count = 0;
    Player player;
    while (getline(file, line)) {
        string firstWord;
        istringstream ss(line);
        ss >> firstWord;
        for (int i = 0; i < numplayer; i++) {
            if (pl == firstWord) {
                cout << "Игрок " << ": " << firstWord << " ";
                ss >> firstWord;
                cout << firstWord << endl;
            }
        }
    }
}
void FindPass(int numplayer) {
    string pl;
    cout << "Введите имя игрока: ";
    cin >> pl;
    ifstream file("players.txt");
    string line;
    int line_count = 0;
    Player player;
    while (getline(file, line)) {
        string firstWord;
        istringstream ss(line);
        ss >> firstWord;
        for (int i = 0; i < numplayer; i++) {
            if (pl == firstWord) {
                ss >> firstWord;
                ss >> firstWord;
                ss >> firstWord;
                cout << "Количество голевых передач игрока: " << firstWord << endl;

            }
        }
    }
}
void FindCard(int numplayer) {
    string pl;
    cout << "Введите имя игрока: ";
    cin >> pl;
    ifstream file("players.txt");
    string line;
    int line_count = 0;
    Player player;
    while (getline(file, line)) {
        string firstWord;
        istringstream ss(line);
        ss >> firstWord;
        for (int i = 0; i < numplayer; i++) {
            if (pl == firstWord) {
                ss >> firstWord;
                ss >> firstWord;
                ss >> firstWord;
                ss >> firstWord;
                cout << "Желтых карточек: " << firstWord << endl;
                ss >> firstWord;
                cout << "Красных карточек: " << firstWord << endl;
            }
        }
    }
}
void FindMatch(int numplayer) {
    string pl;
    cout << "Введите имя игрока: ";
    cin >> pl;
    ifstream file("players.txt");
    string line;
    int line_count = 0;
    Player player;
    while (getline(file, line)) {
        string firstWord;
        istringstream ss(line);
        ss >> firstWord;
        for (int i = 0; i < numplayer; i++) {
            if (pl == firstWord) {
                ss >> firstWord;
                ss >> firstWord;
                ss >> firstWord;
                ss >> firstWord;
                ss >> firstWord;
                ss >> firstWord;
                cout << "Количество сыгранных матчей: " << firstWord << endl;
            }
        }
    }
}
void num(int numpl) {
    cout << "Всего в команде " << numpl << " игроков";
}
void SortPlayersByAssists() {
    ifstream file("players.txt");
    if (!file.is_open()) {
        cout << "Ошибка при открытии файла players.txt" << endl;
        return;
    }
    // считываем данные об игроках из файла в массив структур Player
    const int MAX_PLAYERS = 100;
    Player players[MAX_PLAYERS];
    int player_count = 0;
    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        ss >> players[player_count].name >> players[player_count].surname >> players[player_count].position
            >> players[player_count].assists >> players[player_count].yellow_cards >> players[player_count].red_cards
            >> players[player_count].games_played;
        player_count++;
    }
    file.close();

    // сортируем игроков по количеству голевых передач
    for (int i = 0; i < player_count - 1; i++) {
        for (int j = 0; j < player_count - i - 1; j++) {
            if (players[j].assists < players[j + 1].assists) {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // выводим отсортированный список игроков
    cout << "Список игроков, отсортированный по количеству голевых передач:" << endl;
    for (int i = 0; i < player_count; i++) {
        cout << i + 1 << ". " << players[i].name << " " << players[i].surname << ", " << players[i].assists << " голевых передач" << endl;
    }
}
void SortPlayersYellow_cards() {
    ifstream file("players.txt");
    if (!file.is_open()) {
        cout << "Ошибка при открытии файла players.txt" << endl;
        return;
    }
    // считываем данные об игроках из файла в массив структур Player
    const int MAX_PLAYERS = 100;
    Player players[MAX_PLAYERS];
    int player_count = 0;
    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        ss >> players[player_count].name >> players[player_count].surname >> players[player_count].position
            >> players[player_count].assists >> players[player_count].yellow_cards >> players[player_count].red_cards
            >> players[player_count].games_played;
        player_count++;
    }
    file.close();

    // сортируем игроков по количеству голевых передач
    for (int i = 0; i < player_count - 1; i++) {
        for (int j = 0; j < player_count - i - 1; j++) {
            if (players[j].yellow_cards < players[j + 1].yellow_cards) {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // выводим отсортированный список игроков
    cout << "Список игроков, отсортированный по количеству желтых карт:" << endl;
    for (int i = 0; i < player_count; i++) {
        cout << i + 1 << ". " << players[i].name << " " << players[i].surname << ", " << players[i].yellow_cards << " желтых карт" << endl;
    }
}
void SortPlayersRed_cards() {
    ifstream file("players.txt");
    if (!file.is_open()) {
        cout << "Ошибка при открытии файла players.txt" << endl;
        return;
    }
    // считываем данные об игроках из файла в массив структур Player
    const int MAX_PLAYERS = 100;
    Player players[MAX_PLAYERS];
    int player_count = 0;
    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        ss >> players[player_count].name >> players[player_count].surname >> players[player_count].position
            >> players[player_count].assists >> players[player_count].yellow_cards >> players[player_count].red_cards
            >> players[player_count].games_played;
        player_count++;
    }
    file.close();

    // сортируем игроков по количеству голевых передач
    for (int i = 0; i < player_count - 1; i++) {
        for (int j = 0; j < player_count - i - 1; j++) {
            if (players[j].red_cards < players[j + 1].red_cards) {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
    // выводим отсортированный список игроков
    cout << "Список игроков, отсортированный по количеству красных карт:" << endl;
    for (int i = 0; i < player_count; i++) {
        cout << i + 1 << ". " << players[i].name << " " << players[i].surname << ", " << players[i].red_cards << " красных карт" << endl;
    }
}

int main() {
    setlocale(0, "RU");
    int isAdmin = 0;
    int choice;
    bool enter = false;
    int numPlayers = count_lines_in_file();
    while (enter == false) {
        cout << "1. Зарегистрироваться\n";
        cout << "2. Войти\n";
        cin >> choice;
        switch (choice) {
        case 1:
            registerUser();
            enter = true;
            break;
        case 2:
            isAdmin = login();
            if (isAdmin == 3) {
                cout << endl << "========== Такого пользователя нет в базе данных ==========" << endl;
                return 0;
            }
            enter = true;
            break;
        default:
            cout << "Неправильный ввод. Выберите номер 1 или 2.\n";
        }
    }
    while (true) {
        cout << "========== Управление футбольной командой ==========\n";
        cout << "1. Просмотреть всех игроков\n";
        if (isAdmin == 1) {
            cout << "2. Создать новую карточку игрока\n";
        }
        cout << "3. Сортировать игроков по количеству забитых голов\n";
        cout << "4. Сортировать игроков по количеству желтых карточек\n";
        cout << "5. Сортировать игроков по количеству красных карточек\n";
        cout << "6. Просмотреть матчи игрока\n";
        cout << "7. Просмотреть количество голевых передач игрока\n";
        cout << "8. Просмотреть карточки игрока\n";
        cout << "9. Просмотреть количество игроков в команде\n";
        cout << "10. Поиск игрока по имени\n";
        cout << "12. Просмотр информации об игроке\n";
        cout << "13. Выход\n";
        cout << "Введите номер команды (1-13): ";
        cin >> choice;
        switch (choice) {
        case 1:
            PlayersOutput();
            break;
        case 2:
            if (isAdmin) {
                addPlayer();
            }
            else {
                cout << "Вы должны войти в режим администратора, чтобы использовать эту функцию.\n";
            }
            break;
        case 3:
            SortPlayersByAssists();
            break;
        case 4:
            SortPlayersYellow_cards();
            break;
        case 5:
            SortPlayersRed_cards();
            break;
        case 6:
            FindMatch(numPlayers);
            break;
        case 7:
            FindPass(numPlayers);
            break;
        case 8:
            FindCard(numPlayers);
            break;
        case 9:
            num(numPlayers);
            break;
        case 10:
            FindPlayer(numPlayers);
            break;
        case 11:

            break;
        case 12:

            break;
        case 13:
            return 0;
        default:
            cout << "Некорректный номер команды. Пожалуйста, введите номер от 1 до 13.\n";
        }

        cout << endl;
    }
}