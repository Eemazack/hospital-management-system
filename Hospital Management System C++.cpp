#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> //for clear screen
#include <vector>

using namespace std;

class Patient
{

 protected :

    string name, gender, type, disease;
    string age, bill;


 public :

    void add_patient();
    void search_display_patient();
    void search_patient_name();
    void delete_patient();
    void edit_patient();
    void display_patient();
    void quit();


};

string convert(string str){ //(word to change)=convert(word to change)
    for(int i=0; i<str.length();i++){
        str[i]=toupper(str[i]);
    }
    return str;
}

void Patient::add_patient()
{

 ofstream newpatient("datapatient.txt", ios::app);
 system("cls");



    cout<< "Enter name :"<<endl;
    cin >> name;

    cout<< "Enter gender :"<<endl;
    cin >> gender;

    cout<< "Enter age :"<<endl;
    cin >> age;

    cout<< "Enter type (Ordinary/ emergency):"<<endl;
    cin >> type;

    cout<< "Enter disease :"<<endl;
    cin >> disease;

    cout<< "Enter bill :"<<endl;
    cin >> bill;

    name=convert(name);



    newpatient<<endl<< name<<'|'<<gender<<'|'<<age<<'|'<<type<<'|'<<disease<<'|'<<bill;
    newpatient.close();


}

void Patient::search_display_patient()
{
     int choice2;
     system ("CLS");

     cout << "1.Search Patient by name" << endl;
     cout << "2.Display all Patient" << endl;
     cout << "3.Exit Search & Display menu" << endl;

         cin >> choice2;

         {
            if (choice2==1)
                 search_patient_name();

            else if (choice2==2)
                 display_patient();

            else if (choice2==3)
                 {
                     cout << "You finished search data patient & display data patient"<< endl;
                 }

            else
                cout << "Invalid"<< endl;

            }


}

void Patient::search_patient_name()
{
     vector<string> name_list;
     vector<string> gender_list;
     vector<string> age_list;
     vector<string> type_list;
     vector<string> disease_list;
     vector<string> bill_list;

     string str;

    fstream patient_file;
    patient_file.open("datapatient.txt");

    while (!patient_file.eof())
        {
            getline(patient_file,name,'|');
            getline(patient_file,gender,'|');
            getline(patient_file,age,'|');

            getline(patient_file,type,'|');
            getline(patient_file,disease,'|');
            getline(patient_file,bill);

            name_list.push_back(name);
            type_list.push_back(gender);
            bill_list.push_back(age);
            age_list.push_back(type);
            gender_list.push_back(disease);
            disease_list.push_back(bill);
        }

        patient_file.close();

        system("CLS");
        cout << "Enter the patient's name: ";
        cin >> str;
        str =convert(str);


        for (int i=0; i<name_list.size(); i++)
        {


               if (name_list.at(i) == str)
                {
                cout<< "Search result for \"" << str <<"\" :" <<endl;
                cout<< "\nName : "<< name_list.at(i)<<endl;
                cout<< "Type(ordinary/emergency/outpatient/warded) : "<< type_list.at(i) <<endl;
                cout<< "Bill : RM"<< bill_list.at(i) <<endl;
                cout<< "Age : "<< age_list.at(i) <<endl;
                cout<< "Gender : "<< gender_list.at(i) <<endl;
                cout<< "Disease : "<< disease_list.at(i) <<endl;
                }

               else {cout << " ";}

        }


}

void Patient::delete_patient()
{

    system("cls");
    fstream patient;
    patient.open("datapatient.txt");


    vector <string> name_list;
    vector <string> gender_list;
    vector <string> age_list;
    vector <string> type_list;
    vector <string> disease_list;
    vector <string> bill_list;

    while(!patient.eof()){


        getline(patient,name,'|');
        getline(patient,gender,'|');
        getline(patient,age,'|');
        getline(patient,type,'|');
        getline(patient,disease,'|');
        getline(patient,bill);


        name_list.push_back(name);
        gender_list.push_back(gender);
        age_list.push_back(age);
        type_list.push_back(type);
        disease_list.push_back(disease);
        bill_list.push_back(bill);

    }

    patient.close();


    //to check all element inside vectors
    for(int i=0; i<name_list.size(); i++)
    {
        cout<<name_list.at(i) << "," <<type_list.at(i)<<"," <<bill_list.at(i)<<","<<age_list.at(i)<<","<<gender_list.at(i)<<","<<disease_list.at(i)<<endl;
    }

    vector<string> temp_name_list;
    vector<string> temp_gender_list;
    vector<string> temp_age_list;
    vector<string> temp_type_list;
    vector<string> temp_disease_list;
    vector<string> temp_bill_list;

    string todelete;

    cout<<"Choose patient's name that you want to delete: "<<endl;
    cin >> todelete;


    todelete=convert(todelete);

    for(int i=0; i<name_list.size(); i++)

    {
        if(name_list.at(i)!=todelete)
            {
            temp_name_list.push_back(name_list.at(i));
            temp_gender_list.push_back(gender_list.at(i));
            temp_age_list.push_back(age_list.at(i));
            temp_type_list.push_back(type_list.at(i));
            temp_disease_list.push_back(disease_list.at(i));
            temp_bill_list.push_back(bill_list.at(i));

            }

    }


    //delete old txt file

    if(remove("datapatient.txt") !=0)
        cout<<"\nError Deleting file\n";


    //store all item back into txt file
    for(int i=0; i<temp_name_list.size(); i++)
        {
        fstream newList;
        newList.open("datapatient.txt",ios::app);

        newList<< endl <<temp_name_list.at(i) << '|' << temp_gender_list.at(i)<<'|'<<temp_age_list.at(i)<<'|'<<temp_type_list.at(i)<<'|'<<temp_disease_list.at(i)<<'|'<<temp_bill_list.at(i);

        newList.close();
        }

    }

void Patient::edit_patient()
{
    vector<string> name_list;
    vector<string> gender_list;
    vector<string> age_list;
    vector<string> type_list;
    vector<string> disease_list;
    vector<string> bill_list;


    fstream patient_file;
    patient_file.open("datapatient.txt");


    while(!patient_file.eof()){

        getline(patient_file,name,'|');
        getline(patient_file,gender,'|');
        getline(patient_file,age,'|');
        getline(patient_file,type,'|');
        getline(patient_file,disease,'|');
        getline(patient_file,bill);


        name_list.push_back(name);
        gender_list.push_back(gender);
        age_list.push_back(age);
        type_list.push_back(type);
        disease_list.push_back(disease);
        bill_list.push_back(bill);
    }

    patient_file.close();



        string namesearch;
        cout<<endl<< "Enter the patient name to search : ";
        cin >> namesearch;

        namesearch=convert(namesearch);

        system("cls");


        for(int i=0; i<name_list.size(); i++)

        {
            if(name_list.at(i)==namesearch)
              {

                cout<< "Search result for \"" << namesearch <<"\" :" <<endl;
                cout<< endl << " name : "<< name_list.at(i)<<endl;
                cout<< "Gender : "<< gender_list.at(i) <<endl;
                cout<< "Age: "<<age_list.at(i)<<endl;
                cout<< "Disease : "<<disease_list.at(i)<<endl;
                cout<< "Type(ordinary/emergency) : "<< type_list.at(i) <<endl;
                cout<< "Bill : RM"<< bill_list.at(i) <<endl;
                cout<< "-----------------------------------" << endl;


                     int choose;

                     cout<< "What to update?"<<endl;
                     cout<< "1) Update Type "<<endl;
                     cout<< "2) Update Bill "<<endl;
                     cout<< "3) Update Disease"<<endl;

                     cout<< endl << "Choose a number to update: ";
                     cin>> choose;


        if (choose==1)
            {
               string up_type;
               cout<<"Enter type to update (emergency/ordinary): ";
               cin>> up_type;
               type_list.at(i)=up_type;
            }

        else if (choose==2)
            {
               string up_bill;
               cout<<"Enter bill to update : ";
               cin>> up_bill;
               bill_list.at(i)=up_bill;
            }

        if (choose==3)
            {
               string up_disease;
               cout<<"Enter disease to update : ";
               cin>> up_disease;
               disease_list.at(i)=up_disease;
            }

            }
        }


        remove("datapatient.txt");


        for(int i=0; i<name_list.size(); i++)
            {
              fstream newList;
              newList.open("datapatient.txt",ios::app);

              newList <<endl <<name_list.at(i)<<'|'<< gender_list.at(i)<<'|'<<age_list.at(i)<<'|'<<type_list.at(i)<<'|'<<disease_list.at(i)<<'|'<<bill_list.at(i);
        // tambah lg data lain

              newList.close();
             }


}

void Patient::display_patient()
{
    fstream patient;
    patient.open("datapatient.txt");
    system("cls");

    int i=1;
    while (!patient.eof())
    {
        getline(patient,name,'|');
        getline(patient,gender,'|');
        getline(patient,age,'|');
        getline(patient,type,'|');
        getline(patient,disease,'|');
        getline(patient,bill);

        cout<< endl;
        cout<< "============"<<endl;
        cout<< "Patient #"<< i<<endl;
        cout<< "============"<<endl;
        cout<< "Name : "<<name<<endl;
        cout<< "Gender : "<< gender <<endl;
        cout<< "Age : "<< age <<endl;
        cout<< "Type(ordinary/emergency) : "<< type <<endl;
        cout<< "Disease : "<< disease <<endl;
        cout<< "Bill : RM"<< bill <<endl;

        cout<<endl;
        i++;
    }



    }

 void Patient::quit()
 {
     system ("CLS");
     cout << "Thank you & Have a nice day " << endl;
     system ("pause");

 }

 string menuPatient(string choicePatient)
{


   system ("cls");



       Patient p;
       cout << " Welcome to the Hospital Cheras "<<endl;
       cout << "--------------------------------"<<endl;
       cout << "1.Add data of new patient" << endl;
       cout << "2.Search Patient data" << endl;
       cout << "3.Delete Patient data" << endl;
       cout << "4.Edit Patient data" << endl;
       cout << "---------------------------------"<< endl;
       cout << " ENTER NUMBER : ";

       cin >> choicePatient;
       return choicePatient;




       }

int main()

 {
     Patient p;

     string option;
     int cont;

     do
        {
          option = menuPatient(option);


        if (option == "1")
             p.add_patient();

        else if (option == "2")
            p.search_display_patient();

        else if (option == "3")
            p.delete_patient();

        else if (option == "4")
            p.edit_patient();


        else {
              cout << "Invalid"<<endl;
             }

             cout << "-----------------------------"<< endl;
             cout << "Do you want to continue? : "<<endl;
             cout << endl;
             cout << "PRESS 1 TO CONTINUE" << endl;
             cout << "PRESS ANY KEY TO EXIT"<< endl;
             cin >> cont;

        }while (cont == 1 );
          p.quit();


    }
