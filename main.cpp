#include "Z.h"

using namespace std;
using namespace nm;

using namespace std;

int main()
{
    chek("jets.txt");
    chek("routes.txt");

    for(;;){
    cout << "Выберите:" << endl << "1.Управление самолетами 2. Управление маршрутами \nЛюбой другой ввод - выход" << endl;
    int choose;
    cin >> choose;
    switch(choose){
    case 1:{
        cout << "Выберите:\n 1.Вывести на экран информацию о всех самолетах 2. Поиск 3. Добавить самолет 4. Удалить самолет 5. Отправить самолет в рейс 6. Изменить время, проведенное в пути " << endl;
        int chose;
        cin >> chose;
        switch(chose){
        case 1:{
            display("jets.txt");
            break;
        }
        case 2:{
            searchJET();
            break;
        }
        case 3:{
            addJET();
            break;
        }
        case 4:{
            delJET();
            break;
        }
        case 5:{
            vylet();
            break;
        }
        case 6:{
            time();
            break;
        }

        default:{
                break;
        }
        }
        break;
        }
    case 2:{
        cout << "Выберите:\n1. Вывести на экран информацию о всех рейсах 2. Поиск 3. Добавить рейс 4. Удалить рейс" << endl;
        int chose;
        cin >> chose;
        switch(chose){
        case 1:{
            display("routes.txt");
            break;
        }
        case 2:{
            searchROU();
            break;
        }
        case 3:{
            addROU();
            break;
        }
        case 4:{
            delROU();
            break;
        }
        default:{
            break;
        }
        }
        break;
        }
        default:{
        return 0;
    }
    }
    }
}
