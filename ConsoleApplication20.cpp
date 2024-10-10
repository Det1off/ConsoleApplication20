#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функция для отображения текущего состояния игры
void display(const string& word, const vector<char>& guessedLetters) {
    for (char c : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
            cout << c << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << "\n";
}

// Функция для проверки, выиграл ли игрок
bool hasWon(const string& word, const vector<char>& guessedLetters) {
    for (char c : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), c) == guessedLetters.end()) {
            return false;
        }
    }
    return true;
}

// Основная функция игры
int main() {
    setlocale(0, "ru");

    string word = "colaider"; // Слово для угадывания
    vector<char> guessedLetters; // Буквы, которые угадал игрок
    int attempts = 6; // Количество попыток

    cout << "Добро пожаловать в игру 'Виселица'!" << "\n";

    while (attempts > 0) {
        display(word, guessedLetters);
        cout << "У вас осталось попыток: " << attempts << "\n";
        cout << "Введите букву: ";

        char guess;
        cin >> guess;

        // Проверка, была ли буква уже угадана
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "Вы уже угадали эту букву!" << "\n";
            continue;
        }

        guessedLetters.push_back(guess); // Добавляем букву в список угаданных

        // Проверка, есть ли буква в слове
        if (word.find(guess) == string::npos) {
            attempts--; // Уменьшаем количество попыток
            cout << "Нет такой буквы!" << "\n";
        }

        if (hasWon(word, guessedLetters)) {
            cout << "Поздравляем! Вы угадали слово: " << word << "\n";
            break;
        }
    }

    if (attempts == 0) {
        cout << "Вы проиграли! Слово было: " << word << "\n";
    }

    return 0;
}
