#include <QCoreApplication>
#include <iostream>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QList>
#define CLEAR_CONSOLE

class Animals{
public:

    virtual void animal_info() = 0;

};

class Cow : public Animals{
public:
    short c_number_of_legs;
    QString c_type_animal;
    QString c_animal_noise;
    Cow(short number_of_legs = 0, QString type_animal = 0, QString animal_noise = 0)
        : c_number_of_legs(number_of_legs), c_type_animal(type_animal), c_animal_noise(animal_noise)
    {

    }
    void animal_info(){
        qDebug()<<"Cow       "<<"Type: "<<c_type_animal<<"     "<<"Number of legs: "<< c_number_of_legs<<"       "<<"Noise: "<<c_animal_noise;

    }

};

class Sheep : public Animals{
public:
    short s_number_of_legs;
    QString s_type_animal;
    QString s_animal_noise;
    Sheep(short number_of_legs = 0, QString type_animal = 0, QString animal_noise = 0)
        : s_number_of_legs(number_of_legs), s_type_animal(type_animal), s_animal_noise(animal_noise)
    {

    }
    void animal_info(){
        qDebug()<<"Sheep     "<<"Type: "<<s_type_animal<<"     "<<"Number of legs: "<< s_number_of_legs<<"       "<<"Noise: "<<s_animal_noise;

    }

};

void waitForAnyKey(){
    std::fflush(NULL);
#ifdef _WIN32
    system("pause");
#else
    system("bash -c \'read -n 1 -s -r -p \"Click any button to clear console...\"\'");
#endif
}

void clearConsole(){
    std::fflush(NULL);
#ifdef _WIN32
    system("cls");
    #else
    system("clear");
#endif
}

class Pig : public Animals{
public:
    short p_number_of_legs;
    QString p_type_animal;
    QString p_animal_noise;
    Pig(short number_of_legs = 0, QString type_animal = 0, QString animal_noise = 0)
        : p_number_of_legs(number_of_legs), p_type_animal(type_animal), p_animal_noise(animal_noise)
    {

    }
    void animal_info(){
        qDebug()<<"Pig       "<<"Type: "<<p_type_animal<<"     "<<"Number of legs: "<< p_number_of_legs<<"       "<<"Noise: "<<p_animal_noise;

    }
};

class Chicken : public Animals{
public:
    short c_number_of_legs;
    QString c_type_animal;
    QString c_animal_noise;
    Chicken(short number_of_legs = 0, QString type_animal = 0, QString animal_noise = 0)
        : c_number_of_legs(number_of_legs), c_type_animal(type_animal), c_animal_noise(animal_noise)
    {

    }
    void animal_info(){
        qDebug()<<"Chicken   "<<"Type: "<<c_type_animal<<"     "<<"Number of legs: "<< c_number_of_legs<<"       "<<"Noise: "<<c_animal_noise;

    }
};

class Donkey : public Animals{
public:
    short d_number_of_legs;
    QString d_type_animal;
    QString d_animal_noise;
    Donkey(short number_of_legs = 0, QString type_animal = 0, QString animal_noise = 0)
        : d_number_of_legs(number_of_legs), d_type_animal(type_animal), d_animal_noise(animal_noise)
    {

    }

    void animal_info(){
        qDebug()<<"Donkey    "<<"Type: "<<d_type_animal<<"     "<<"Number of legs: "<< d_number_of_legs<<"       "<<"Noise: "<<d_animal_noise;

    }
};

bool ask_user(){
    QTextStream Qcout(stdout);
    QTextStream Qcin(stdin);
    int answer;
    QString exit_answer;
    qDebug()<<"Write down the number of animals(at least 3) or write 0 to skip ";
    Qcin>>answer;

    if(answer < 3 && answer != 0){
        do {
            qDebug()<<"Error! Try again";
            Qcin>>answer;

        } while (answer < 3 && answer != 0);
    }

    QList<Animals*> farm;
    QList<Animals*>::Iterator iterator;
    farm.push_back(new Cow(4, "Chordates", "Moo"));
    farm.push_back(new Sheep(4, "Chordates", "Baa"));
    farm.push_back(new Pig(4, "Chordates", "Oink"));
    farm.push_back(new Chicken(2, "Chordates", "Cluck-cluck"));
    farm.push_back(new Donkey(4, "Chordates", "Ee-haw"));

    answer = std::min(answer, farm.size());
    if (answer <= 0)
        answer = farm.size();
    for(auto it = farm.begin(); it != farm.end() && answer > 0; it++, --answer)
        (*it)->animal_info();
    qDebug()<<"Do you want to exit? Type Yes or No";
    Qcin>>exit_answer;
    if(exit_answer == "Yes"){
        return false;
    }
    else
    return true;
}

int main()
{
    while(ask_user()){
        waitForAnyKey();
        clearConsole();
    }

    return 0;
}


