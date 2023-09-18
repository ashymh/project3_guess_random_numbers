#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


int main()
{
    int num;
    vector<int> numarr;
    vector<int> random_num;

    cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다." << endl;
    
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << "번째 번호를 입력하세요. : ";  // 숫자 입력
        cin >> num;

        if (num > 25 || num < 1) {
            cout << "잘못된 숫자입니다. 다시 입력해주세요." << endl; // 숫자 범위를 1~25로 제한
            i--;
        }
        else {
            bool overlap_num = false;
            for (int j = 0; j < i; j++) {
                if (numarr[j] == num) { //중복된 숫자 판단
                    cout << "이미 입력된 숫자입니다." << endl;
                    overlap_num = true;
                    i--; // 중복된 숫자일 경우 다시 입력 받기 위해 i를 감소시킴
                }
            }
            if (!overlap_num) {
                numarr.push_back(num); // 중복된 숫자가 아닐 경우 배열에 추가, 이후 6개의 숫자를 받을때까지 루프
            }
        }
    }
    cout << "\n-------------------------\n" << endl;

    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        int num2 = rand() % 25 + 1; // 무작위 숫자 범위 1~25로 제한
        bool overlap_num = false;

        for (int j = 0; j < i; j++) {
            if (random_num[j] == num2) {
                overlap_num = true; // 중복된 숫자가 나올 경우 다시 뽑기
                i--; 
            }
        }
        if (!overlap_num) {
            random_num.push_back(num2); //중복된 숫자가 아닐경우 배열의 추가.
        }
    }

    cout << "당첨번호 공개!! \n";

    for (int i = 0; i < 6; i++) {
        cout << random_num[i] << " "; 
    }
    cout << endl;

    int same = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (numarr[i] == random_num[j]) { //입력받은 숫자와 무작위 숫자 비교
                same++; // 숫자가 맞을때마다 1개씩 추가
            }
        }
    }

    int rank = 7;

    cout << "\n1 ~ 7등 까지 결과가 나올 수 있습니다." << endl;
    cout << "결과 : " << rank - same << "등 입니다!";
}

