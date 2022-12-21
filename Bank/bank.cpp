#include <iostream>
#include <vector>

using namespace std;

struct User
{
public:
    User(){}
    User(string username, string password, string card, int money);
    int id = 0;
    string username = "";
    string password = "";
    string card = "";
    int money = 0;
};

User::User(string username, string password, string card, int money)
{
    this->username = username;
    this->password = password;
    this->card = card;
    this->money = money;

}

vector<User> getUsers();
User getUserByUsername(string username);
void updateUser();
User login(string username, string password);
void bankWorker(User user);
void handlerBank();
void printMenu();
void withdrawMoney(User user);
void putMoney(User user);

int main()
{
    while(true){
        handlerBank();
    }

    return 0;
}

void handlerBank(){
    string username;
    string password;
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    User user = login(username, password);
    if(user.username == "")
    {
        return;
    }

    bankWorker(user);
}


User login(string username, string password)
{
    User user = getUserByUsername(username);
    if(user.username == "")
    {
        return User();
    }

    if(user.password != password)
    {
        return User();
    }

    return user;
}

User getUserByUsername(string username)
{
    vector<User> users = getUsers();
    for(int i = 0; i < (int)users.size() ;i++)
    {
        if(users[i].username == username)
        {
            return users[i];
        }
    }

    return User();
}

vector<User> getUsers()
{
    vector<User> users{
        User(
           "Luciel",
           "12345",
           "2341234234",
           1000
        ),
        User(
           "Kevin",
           "qwerty",
           "3802398423",
           102342
        ),
        User(
           "Paul",
           "39021",
           "5647203420",
           1200
        )
    };

    return users;
}

void bankWorker(User user)
{
    while(true)
    {
        int action;
        printMenu();
        cin >> action;

        switch(action)
        {
            case 1:
                withdrawMoney(user);
                break;
            case 2:
                putMoney(user);
                break;
            case 3:
                return;
        }
    }

}

void printMenu()
{
    cout << "Choose action: " << endl
         << "1 - withdraw money" << endl
         << "2 - put money in" << endl
         << "3 - exit" << endl
         << ">> ";

}

void withdrawMoney(User user)
{
    cout << "WITHDROW MONEY ACTION" << endl;
}

void putMoney(User user)
{
    cout << "PUT MONEY ACTION" << endl;
}

void updateUsers(User oldData, User newData)
{
    cout << "UPDATE USER" << endl;
}