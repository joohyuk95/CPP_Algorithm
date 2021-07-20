// 입력받은 주민등록번호로부터 나이, 성별 추출

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "input resident registration number (ex. 123456-1234567)" << endl;;
    string registration_number;
    cin >> registration_number;
    
    int birth_year, male_digit, age;
    birth_year = stoi(registration_number) / 10000;
    male_digit = registration_number[7];

    string male;

    if (male_digit == '1' | male_digit == '3') {
        male = 'M';
        if (male_digit == '1') {
            age = 2019 - (1900 + birth_year) + 1;
        } else {
            age = 2019 - (2000 + birth_year) + 1;
        }
    } else {
        male = 'W';
        if (male_digit == '2') {
            age = 2019 - (1900 + birth_year) + 1;
        } else {
            age = 2019 - (2000 + birth_year) + 1;
        }
    }
    cout << age << ' ' << male << endl;

    return 0;
}