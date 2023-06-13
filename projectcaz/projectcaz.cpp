#include <iostream>
#include <vector>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
void rules();
void cazino(int counter)
{
    string playerName;
    int balance; // Баланс
    int bidAmount; // Сумма ставки
    int guessednum; // Угаданное вами число
    int hiddennum; // Загаданное компьютером число
    char choice; // Для продолжения игры
    srand(time(0));
    cout << "Добро пожаловать в казино, в этом казино вас разведут, как лоха\n";
    rules();
    cout << "Введите ваш никнейм для казино (на английском): ";
    SetConsoleTextAttribute(hand, 9);
    getline(cin, playerName);
    SetConsoleTextAttribute(hand, 2);
    cout << "\nНапишите ваш стартовый баланс для начала игры: $";
    cin >> balance;
    do
    {
        system("cls");
        if (counter <= 2 && counter >= -2)
        {
            counter == 0;
        }
        cout << counter << endl;
        cout << "\nВаш баланс на данный момент составляет: " << balance << "$\n";
        do
        {
            cout << playerName << ", введите вашу ставку в рублях: ";
            cin >> bidAmount;
            if (bidAmount > balance)
            {
                SetConsoleTextAttribute(hand, 4);
                cout << "Ваш баланс меньше, чем ваша ставка!\n" << "\n";
                SetConsoleTextAttribute(hand, 2);
                cout << "Введите вашу ставку заново: ";
                cin >> bidAmount;
                while (bidAmount > balance)
                {
                    SetConsoleTextAttribute(hand, 4);
                    cout << "Ваш баланс меньше, чем ваша ставка!\n" << "\n";
                    SetConsoleTextAttribute(hand, 2);
                    cout << "Введите вашу ставку заново: ";
                    cin >> bidAmount;
                }
            }
            else
            {
                cout << "Ставка принята!\n";
            }
        }//
        while (bidAmount > balance);
        do
        {
            SetConsoleTextAttribute(hand, 5);
            cout << "Отгадайте 1 число (напоминаем что числа могут быть только от 1 до 5): ";
            SetConsoleTextAttribute(hand, 2);
            cin >> guessednum;
            if (guessednum <= 0 || guessednum > 5)
            {
                SetConsoleTextAttribute(hand, 4);
                cout << "\nЧисло должно быть от 1 до 5\n" << "Введите еще раз: ";
            }
        } while (guessednum <= 0 || guessednum > 5);
        hiddennum = rand() % 5 + 1;
        SetConsoleTextAttribute(hand, 2);
        if (hiddennum == guessednum)
        {
            cout << "\nВы выйграли!!! Вы получили выйгрыш $" << bidAmount * 2 << "\n";
            balance = balance + bidAmount * 2;
            counter == 0;
        }
        else
        {
            SetConsoleTextAttribute(hand, 4);
            cout << "К сожалению вы не угадали 1 число." << "\n";
            counter += 1;
        }
        SetConsoleTextAttribute(hand, 5);
        cout << "Число которое было загадано это " << hiddennum << "\n";
        SetConsoleTextAttribute(hand, 2);
        cout << "\n" << playerName << ", ваш баланс составляет $" << balance << "\n";
        //
        while (bidAmount > balance);
        do
        {
            SetConsoleTextAttribute(hand, 5);
            cout << "Отгадайте 2 число (напоминаем что числа могут быть только от 1 до 5): ";
            SetConsoleTextAttribute(hand, 2);
            cin >> guessednum;
            if (guessednum <= 0 || guessednum > 5)
            {
                SetConsoleTextAttribute(hand, 4);
                cout << "\nЧисло должно быть от 1 до 5\n" << "Введите еще раз: ";
            }
        } while (guessednum <= 0 || guessednum > 5);
        hiddennum = rand() % 5 + 1;
        SetConsoleTextAttribute(hand, 2);
        if (hiddennum == guessednum && counter == 1)
        {
            cout << "\nВы выйграли!!! Вы получили выйгрыш $" << bidAmount * 2 << "\n";
            balance = balance + bidAmount * 2;
        }
        else
        {
            if (hiddennum == guessednum && counter == 0)
            {

                cout << "\nВы выйграли!!! Вы получили выйгрыш $" << bidAmount * 5 << "\n";
                balance = balance + bidAmount * 5;
            }
            else
            {
                SetConsoleTextAttribute(hand, 4);
                cout << "К сожалению вы не угадали второе число." << "\n";
                counter += 1;
            }
        }
        SetConsoleTextAttribute(hand, 5);
        cout << "Число которое было загадано это " << hiddennum << "\n";
        SetConsoleTextAttribute(hand, 2);
        cout << "\n" << playerName << ", ваш баланс составляет $" << balance << "\n";
        //
        while (bidAmount > balance);
        do
        {
            SetConsoleTextAttribute(hand, 5);
            cout << "Отгадайте 3 число (напоминаем что числа могут быть только от 1 до 5): ";
            SetConsoleTextAttribute(hand, 2);
            cin >> guessednum;
            if (guessednum <= 0 || guessednum > 5)
            {
                SetConsoleTextAttribute(hand, 4);
                cout << "\nЧисло должно быть от 1 до 5\n" << "Введите еще раз: ";
            }
        } while (guessednum <= 0 || guessednum > 5);
        hiddennum = rand() % 5 + 1;
        SetConsoleTextAttribute(hand, 2);
        if (hiddennum == guessednum && counter == 2)
        {
            cout << "\nВы выйграли!!! Вы получили выйгрыш $" << bidAmount * 2 << "\n";
            balance = balance + bidAmount * 2;
        }
        else
        {
            if (hiddennum == guessednum && counter == 1)
            {
                cout << "\nВы выйграли!!! Вы получили выйгрыш $" << bidAmount * 5 << "\n";
                balance = balance + bidAmount * 5;
            }
            else
            {
                if (hiddennum == guessednum && counter == 0)
                {
                    cout << "\nВы выйграли!!! Вы получили выйгрыш $" << bidAmount * 2 << "\n";
                    balance = balance + bidAmount * 10;
                }
                else if (hiddennum != guessednum && counter == 2)
                {
                    SetConsoleTextAttribute(hand, 4);
                    cout << "К сожалению вы проиграли. Ваш пройгрыш составил: $" << bidAmount << "\n";
                    balance = balance - bidAmount;
                }
            }
        }
        SetConsoleTextAttribute(hand, 5);
        cout << "Число которое было загадано это " << hiddennum << "\n";
        SetConsoleTextAttribute(hand, 2);
        cout << "\n" << playerName << ", ваш баланс составляет $" << balance << "\n";
        if (balance == 0)
        {
            SetConsoleTextAttribute(hand, 4);
            cout << "У вас нет денег, чтобы продолжить игру ";
            break;
        }
        SetConsoleTextAttribute(hand, 2);
        cout << "\nХотите сыграть снова(y/n)? ";
        cin >> choice;
        counter = 0;
    } while (choice == 'Y' || choice == 'y');
    cout << "\nСпасибо за игру. Ваш баланс составляет: $ " << balance << "\n";
}
void main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleTextAttribute(hand, 2);
    int counter = 0; // Счётчик поражений
    cazino(counter);
}
void rules()
{
    system("cls");
    cout << "\nПравила казино таковы: \n";
    cout << "1. Вам нужно угадать хотя бы одно из трёх чисел от 1 до 5\n";
    cout << "2. Если угадали 1 число, то ваша ставка увеличивается в 2 раза\n";
    cout << "3. Если угадали 2 числа, то ваша ставка увеличивается в 5 раз\n";
    cout << "4. Если угадали 3 числа, то ваша ставка увеличивается в 10 раз\n";
    cout << "5. Если вы не угадали ни одного числа, то ваша ставка вычитается от вашего баланса\n";
    cout << "6. Игра не является мошеннической схемой (а может и является), деньги на ваш баланс не возвращаются\n";
    cout << "Удачной игры!\n";
}