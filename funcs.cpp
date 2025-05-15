ostream& operator<<(ostream& os, const nm::jets& Jets){
    os << Jets.model <<" "<< Jets.pilot << " " << Jets.range << " " << Jets.speed<< " "<<Jets.status<< " " <<Jets.time<<" "<< Jets.x<<" "<< Jets.y<<" "<< Jets.timeEnd;
    return os;
}

istream& operator>>(istream& is, nm::jets& Jets){
    is >> Jets.model >> Jets.pilot >> Jets.range >> Jets.speed>>Jets.status>>Jets.time>>Jets.x>>Jets.y>>Jets.timeEnd;
    return is;
}


void nm::chek(string a){
    ifstream f(a);
    f.open(a);
    if(!f.is_open()){
    cout << "Файл, необходимый для работы, не найден. Создается новый файл:"<<a<<" \n";
    ofstream f(a);
            if (f.is_open()){
                cout<< "Не удалось создать файл. Программа будет завершена"<<endl;
                exit(EXIT_FAILURE);
            } }
    f.close();
    }

void nm::display(string a){
    string line;
    ifstream f;
    f.open(a); // окрываем файл
    if(!f.is_open()) fatal();
    bool flag = true;
    int b=0;
    if(a=="jets.txt"){
        cout << "Модель самолета| Пилот| Путь | Км/ч | Статус  | В пути | Положение(х,у) | Оставшееся время полета" << endl;}
        else {
        cout << "Маршрут\t| Начало(x,y)\t| Конец(х,у)" << endl;}
        while (getline(f, line)) {
            for (char& t : line) {
                if (t == ' ') {
                    t = '\t';
                }
            }
            cout << b<<". "<<line << endl;
            flag = false;
            b++;
        }
        if(flag) cout << "Файл пуст" << endl;
    f.close();



}

void nm::searchJET(){
    cout << "Enter model of jet" << endl;
    string Model;
    cin >> Model;
    jets editable;
    ifstream f;
    f.open("jets.txt");
    if(!f.is_open()) fatal();
    while(f >> editable){
        if(editable.model == Model){
            cout << editable.model << " " << editable.pilot<< " " << editable.range << " " << editable.speed << " "<<editable.status<< " " <<editable.time <<" " <<editable.x<<" " <<editable.y <<" " <<editable.timeEnd<< endl;
        }
    }
    f.close();
}

void nm::addJET(){
    jets editable;
    cout << "Введите название самолета" << endl;
    cin >> editable.model;
    cout << "Введите имя пилота" << endl;
    cin >> editable.pilot;
    cout << "Введите скорость самолета" << endl;
    if (!(cin >> editable.speed)||(editable.speed<=0)) {
                cout << "Ошибка при вводе скорости" <<endl;
            return;}
    fstream f;
    editable.range = "no";
    editable.status = 0;
    editable.time = 0;
    editable.x=0;
    editable.y=0;
    editable.timeEnd=0;
    f.open("jets.txt", ios::app | ios::ate);
    if(!f.is_open()) fatal();
    f << editable.model << " " << editable.pilot << " " << editable.range << " " << editable.speed << " "<< editable.status << " " << editable.time <<" "<<editable.x<<" "<< editable.y<<" "<<editable.timeEnd<< endl;
    f.close();
}

void nm::delJET(){
    int i = arr_s("jets.txt");
    jets arr[i];
    array(i,"jets.txt", arr);

    int index;
    cout << "Введите индекс самолета" << endl;
    if (!(cin >> index)||(index<0)||(index>i)){
        cout<<"Некорректный ввод"<<endl;
        return;
    }
    ofstream fwrite;
    fwrite.open("jets.txt");
    if(!fwrite.is_open()) fatal();
    for(int n = 0; n < i; n++){
        if(n!=index){
            fwrite << arr[n].model << " " << arr[n].pilot << " " << arr[n].range << " " << arr[n].speed << " " << arr[n].status<< " " << arr[n].time<<" "<<arr[n].x<<" "<<arr[n].y<<" "<<arr[n].timeEnd<< endl;
        }
    }
    fwrite.close();

}

ostream& operator<<(ostream& os, const nm::routes& Routes){
    os << Routes.name << " " << Routes.startX << Routes.startY << " " << Routes.endX << Routes.endY;
    return os;
}

istream& operator>>(istream& is, nm::routes& Routes){
    is >> Routes.name >> Routes.startX >> Routes.startY >> Routes.endX >> Routes.endY;
    return is;
}

void nm::searchROU(){
    cout << "Enter name of route" << endl;
    string name;
    cin >> name;
    routes editable;
    ifstream f;
    f.open("routes.txt");
    if(!f.is_open()) fatal();
    while(f >> editable){
        if(editable.name == name){
            cout << editable.name << " " << editable.startX << " " << editable.startY << " " << editable.endX << " " << editable.endY << endl;
        }
    }
    f.close();
}

void nm::addROU(){
    cout << "Введите название маршрута" << endl;
    routes editable;
    cin >> editable.name;
    cout << "Введите координату начала по х" << endl;
    if (!(cin >> editable.startX)){
        cout<<"Некорректный ввод"<<endl;
        return;
    }
    cout << "Введите координату начала по у" << endl;
    if (!(cin >> editable.startY)){
        cout<<"Некорректный ввод"<<endl;
        return;
    }
    cout << "Введите координату конца по х" << endl;
    if (!(cin >> editable.endX)){
        cout<<"Некорректный ввод"<<endl;
        return;
    }
    cout << "Введите координату конца по у" << endl;
    if (!(cin >> editable.endY)){
        cout<<"Некорректный ввод"<<endl;
        return;
    }
    fstream f;
    f.open("routes.txt", ios::app | ios::ate);
    if(!f.is_open()) fatal();
    f << editable.name << " " << editable.startX << " " << editable.startY << " " << editable.endX << " " << editable.endY << endl;
    f.close();
}

void nm::delROU(){
    int i = arr_s("routes.txt");
    routes arr[i];
    array(i,"routes.txt", arr);

    int index;
    cout << "Введите индекс маршрута" << endl;
    if (!(cin >> index)||(index<0)||(index>i)){
        cout<<"Некорректный ввод"<<endl;
        return;
    }
    ofstream fwrite;
    fwrite.open("routes.txt");
    if(!fwrite.is_open()) fatal();
    for(int n = 0; n < i; n++){
        if((n!=index)){
            fwrite << arr[n].name << " " << arr[n].startX << " " << arr[n].startY << " " << arr[n].endX << " " << arr[n].endY << endl;
        }
    }
    fwrite.close();
}
int nm::arr_s(string f_name){
        string line;
    int i = 0;
    ifstream fread;
    fread.open(f_name);
    if(!fread.is_open()) fatal();
    while(getline(fread, line)){
        i++;
    }
    fread.close();
    return i;
}

void nm::array(int i, string f_name, routes*arr){
    ifstream fread;
    fread.open(f_name);
    if(!fread.is_open()) fatal();
    routes editable;
    for(int n = 0; n < i; n++){
        fread >> editable;
        arr[n] = editable;
    }
    fread.close();

}

void nm::array(int i, string f_name, jets*arr){
    ifstream fread;
    fread.open(f_name);
    if(!fread.is_open()) fatal();
    jets editable;
    for(int n = 0; n < i; n++){
        fread >> editable;
        arr[n] = editable;
    }
    fread.close();

}
void nm::fatal(){
        cout<< "Ошибка открытия файла. Программа будет завершена"<<endl;
        exit(EXIT_FAILURE);}

void nm::vylet(){
    int j = arr_s("routes.txt");
    routes arr1[j];
    array(j,"routes.txt", arr1);

    int i = arr_s("jets.txt");
    jets arr[i];
    array(i,"jets.txt", arr);

    cout<< "Введите индекс желаемого маршрута для вылета"<<endl;
    int a;
    if (!(cin >> a)||(a<0)||(a>j)) {
            cout << "Данного маршрута не существует" <<endl;
            return;
        }

    cout<<"Введите индекс свободного самолета, отправляемого в путь"<<endl;
    int index;
    if (!(cin >> index)||(index<0)||(index>i)) {
            cout << "Данного самолета не существует" <<endl;
            return;
        }
    if(arr[index].status) {
    cout<< "Данный самолет уже находится в рейсе" <<endl;
    return;
    }
    else {
        arr[index].status=1;
        arr[index].range=arr1[a].name;
        arr[index].x=arr1[a].startX;
        arr[index].y=arr1[a].startY;
        int c=sqrt(pow(arr1[a].startX-arr1[a].endX,2)+pow(arr1[a].startY-arr1[a].endY,2));
        arr[index].timeEnd= c/arr[index].speed;
    }
    ofstream fwrite;
    fwrite.open("jets.txt");
    if(!fwrite.is_open()) fatal();
    for(int n = 0; n < i; n++){
            fwrite << arr[n].model << " " << arr[n].pilot << " " << arr[n].range << " " << arr[n].speed << " " << arr[n].status<< " " << arr[n].time<<" "<< arr[n].x<<" "<<arr[n].y<<" "<<arr[n].timeEnd<< endl;
        }
    fwrite.close();
}
