#include <QCoreApplication>
#include <iostream>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QList>
#define CLEAR_CONSOLE
class Animals{
public:
    short number_of_legs;
    short answer;
    QString type_animal;
    QString animal_noise;
    void ask_user(){
        QTextStream Qcout(stdout);
        QTextStream Qcin(stdin);
        qDebug()<<"Write down the number of animals(at least 3) or write 0 to skip ";
        Qcin>>answer;
        if(answer < 3 && answer != 0){
            do {
                qDebug()<<"Error! Try again";
                Qcin>>answer;
                if(answer > 3 || answer == 0){
                    return;
                }
            } while (answer < 3 && answer != 0);
        }





    }
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
};

class Pig : public Animals{
public:
    short p_number_of_legs;
    QString p_type_animal;
    QString p_animal_noise;
    Pig(short number_of_legs = 0, QString type_animal = 0, QString animal_noise = 0)
        : p_number_of_legs(number_of_legs), p_type_animal(type_animal), p_animal_noise(animal_noise)
    {

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
        QTextStream Qcout(stdout);
        Qcout<<"Donkey   "<<"Type: "<<d_type_animal<<"     "<<"Number of legs: "<< d_number_of_legs<<"       "<<"Noise: "<<d_animal_noise;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Animals test;
    QTextStream Qcout(stdout);
    Cow animal_cow(4, "Chordates", "Moo");
    Sheep animal_sheep(4, "Chordates", "Baa");
    Pig animal_pig(4, "Chordates", "Oink");
    Chicken animal_chicken(2, "Chordates", "Cluck-cluck");
    Donkey animal_donkey(4, "Chordates", "Hee-haw");
    test.ask_user();
    //animal_donkey.animal_info();
    QList<Animals> farm;
    farm.append(animal_chicken);
    farm.append(animal_cow);
    farm.append(animal_sheep);
    farm.append(animal_pig);
    farm.append(animal_donkey);
    if(test.answer == 0){
        for(int i = 0; i < test.answer; ++i){
            farm.at(i);
            Qcout<<i;
        }
    }
    return a.exec();
}


