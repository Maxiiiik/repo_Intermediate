#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>   

using namespace std;

const int TEAM_SIZE = 5;

class Hero
{
    int id;
    string name;
    int hp;
    int dmg;
public:
    Hero() 
    {

    }
    ~Hero() 
    {

    }
    Hero(int c_id, string c_name, int c_hp, int c_dmg)
    {
        this->id = c_id;
        this->name = c_name;
        this->hp = c_hp;
        this->dmg = c_dmg;
    }

    int get_id() 
    {
        return id;
    }
    string get_name()
    {
        return name;
    }
    int get_DMG()
    {
        return dmg;
    }
    int get_hp()
    {
        return hp;
    }
    friend ostream& operator << (ostream& out, const Hero& hero);
};

ostream& operator << (ostream& out, const Hero& hero) 
{
    out << "Name: " << hero.name << endl
        << "id: " << hero.id << endl
        << "HP: " << hero.hp << endl
        << "Damage: " << hero.dmg << endl;
    return out;
}

class Player 
{
    int id;
    string name;
    int rank;
public:
    Player()
    {

    }
    ~Player() 
    {

    }
    Player(int c_ind, string c_name, int c_rank)
    {
        this->id = c_ind;
        this->name = c_name;
        this->rank = c_rank;
    }
    string get_name() 
    {
        return name;
    }
    int get_id() 
    {
        return id;
    }
    int get_rank() 
    {
        return rank;
    }
    void edit_rank(int value)
    {
        rank += value;
    }
    friend ostream& operator<< (ostream& out, const Player& player);
};

ostream& operator<< (ostream& out, const Player& player)
{
    out << "Player name: " << player.name << endl
        << "Player id: " << player.id << endl
        << "Player rank: " << player.rank << endl;
    return out;
}

class P_H
{
    Player player;
    Hero hero;
public:
    P_H(Player c_p, Hero c_h)
    {
        this->player = c_p;
        this->hero = c_h;
    }
    int get_h_dmg() 
    {
        return hero.get_DMG();
    }
    int get_h_hp() 
    {
        return hero.get_DMG();
    }
    Player get_p()
    {
        return player;
    }
    friend ostream& operator<< (ostream& out, const P_H & p_h);
};

ostream& operator<< (ostream& out, const P_H& p_h)
{
    out << "Player: " << p_h.player << "Hero: " << p_h.hero;
    return out;
}

class Team
{
    string name;
    vector <P_H> team;
    int totalDMG;
    int totalHP;
public:
    Team()
    {

    }
    Team(string c_name, vector <P_H> c_team)
    {
        this->name = c_name;
        this->team = c_team;
        cal_Total_DMG();
        cal_Total_HP();
    }
    int cal_Total_DMG()
    {
        int sum = 0;
        for (int i = 0; i < team.size(); i++)
        {
            sum += team[i].get_h_dmg();
        }
        totalDMG = sum;
        return totalDMG;
    }
    int cal_Total_HP()
    {
        int sum = 0;
        for (int i = 0; i < team.size(); i++)
        {
            sum += team[i].get_h_hp();
        }
        totalHP = sum;
        return totalHP;
    }
    vector <P_H> get_team()
    {
        return team;
    }
    friend ostream& operator << (ostream& out, const Team& team);
};

ostream& operator << (ostream& out, const Team& team)
{
    out 
        << "\n\x1b[31mTeam Name: \x1b[0m" << team.name << endl
        << "\x1b[32mTeam total dmg: \x1b[0m" << team.totalDMG << endl
        << "\x1b[33mTeam total hp \x1b[0m" << team.totalHP << endl
        
        << endl;
    for (int i = 0; i < team.team.size(); i++)
    {
        out << team.team[i] << endl;
    }
    return out;
}

class H_manager
{
public:
    Hero create_h(int id, string name, int hp, int dmg) 
    {
        return Hero(id, name, hp, dmg);
    }
    Hero get_h_name(string name, vector<Hero> list) 
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].get_name() == name)
            {
                return list[i];
            }
            else
            {
                cout << "This hero does not exist" << endl;
            }
        }
    }
    Hero get_h_id(int Id, vector<Hero> list)
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].get_id() == Id)
            {
                return list[i];
            }
            else
            {
                cout << "This hero does not exist" << endl;
            }
        }
    }

    void delete_h(Hero hero)
    {
        hero.~Hero();
    }

    void show_h_info(Hero hero)
    {
        cout << hero;
    }
};

class P_manager
{
public:

    Player create_p(int id, string name, int rank) 
    {
        return Player(id, name, rank);
    }

    Player get_p_name(string name, vector<Player> list) 
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].get_name() == name)
            {
                return list[i];
            }
            else
            {
                cout << "This hero does not exist" << endl;
            }
        }
    }

    Player get_p_id(int id, vector<Player> list) 
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].get_id() == id)
            {
                return list[i];
            }
            else
            {
                cout << "This hero does not exist" << endl;
            }
        }
    }

    void delete_p(Player player)
    {
        player.~Player();
    }

    void player_info(Player player) 
    {
        cout << player;
    }
};

class Team_manager
{
public:
    Team New_team(string c_name, vector <P_H> c_team)
    {
        return Team(c_name, c_team);
    }
    void get_team_information(Team team)
    {
        cout << team;
    }
};

class Session 
{
    time_t start_time;
    Team first;
    Team second;
    Team win;
public:
    Session(Team c_first, Team c_second)
    {
        auto end = chrono::system_clock::now();
        start_time = chrono::system_clock::to_time_t(end);
        first = c_first;
        second = c_second;
    }
    void Cal_Win()
    {
        int first_HP = first.cal_Total_HP() - second.cal_Total_DMG();
        int second_HP = second.cal_Total_HP() - first.cal_Total_DMG();
        if (first_HP > second_HP)
        {
            win = first;
            for (int i = 0; i < TEAM_SIZE; i++)
            {
                first.get_team()[i].get_p().edit_rank(25);
                second.get_team()[i].get_p().edit_rank(-25);
            }
        }
        else
        {
            win = second;
            for (int i = 0; i < TEAM_SIZE; i++)
            {
                second.get_team()[i].get_p().edit_rank(25);
                first.get_team()[i].get_p().edit_rank(-25);
            }
        }
    }
    friend ostream& operator<< (ostream& out, const Session& hero);
};

ostream& operator << (ostream& out, const Session& session) 
{
    
    out << "\x1b[36mTime: \x1b[0m" << ctime(&session.start_time) << endl
        << "\x1b[36mFirst Team: \x1b[0m" << session.first << endl
        << "\x1b[36mSecond Team: \x1b[0m" << session.second << endl
        << "\x1b[36mWinner:\x1b[0m" << session.win << endl;
    
    return out;
}

class G_manager
{
public:
    vector <Session> g_session;
    void Perfotm_g_session(vector<P_H> first_T, vector<P_H> second_T, vector<Player> player, vector<Hero> hero)
    {
        Team_manager team_m;
        vector<Player>* ptr_p = new vector<Player>;
        vector<Hero>* ptr_h = new vector<Hero>;
        ptr_p = &player;
        ptr_h = &hero;
        first_T = random_T(ptr_p, ptr_h);
        second_T = random_T(ptr_p, ptr_h);
        Team first = team_m.New_team("first", first_T);
        Team second = team_m.New_team("second", second_T);
        Session session(first, second);
        session.Cal_Win();
        g_session.emplace_back(session);
        cout << session;
    }
    vector<P_H> random_T(vector<Player>* player, vector<Hero>* hero)
    {
        vector<P_H> team;
        for (int i = 0; i < TEAM_SIZE; i++)
        {
            int rand_p = rand() % player[0].size();
            int rand_h = rand() % player[0].size();
            P_H cell((*player)[rand_p], (*hero)[rand_h]);
            team.emplace_back(cell);
            auto ite_p = (*player).cbegin();
            (*player).erase(ite_p + rand_p);
            auto ite_h = (*hero).cbegin();
            (*hero).erase(ite_h + rand_h);
        }
        return team;
    }
    void print_game()
    {
        for (int i = 0; i < g_session.size(); i++)
        {
            cout << g_session[i] << endl;
        }
    }
};

int  print_menu() 
{
    int choise;
    cout << "what do you want to do??" << endl;
    cout << "[1] ------> Play" << endl;
    cout << "[2] ------> History Sessions " << endl;
    cout << "[3] ------> Add or Remove Players" << endl;
    cout << "[4] ------> Add or Remove Heroes" << endl;
    cout << "[5] ------> Exit" << endl;
    cin >> choise;
    system("cls");
    return choise;
}

int main()
{
    int choise;
    string choice;

    vector<Player> player;
    vector<Hero> hero;

    vector<Player> lobi_p;
    lobi_p.reserve(10);
    lobi_p.emplace_back(1, "1.Player", 100);
    lobi_p.emplace_back(2, "2.Player", 100);
    lobi_p.emplace_back(3, "3.Player", 100);
    lobi_p.emplace_back(4, "4.Player", 100);
    lobi_p.emplace_back(5, "5.Player", 100);
    lobi_p.emplace_back(6, "6.Player", 100);
    lobi_p.emplace_back(7, "7.Player", 100);
    lobi_p.emplace_back(8, "8.Player", 100);
    lobi_p.emplace_back(9, "9.Player", 100);
    lobi_p.emplace_back(10,"10.Player", 100);

    vector<Hero> lobi_h;
    lobi_h.reserve(10);
    lobi_h.emplace_back(1, "1.Hero", 1, 11);
    lobi_h.emplace_back(2, "2.Hero", 2, 12);
    lobi_h.emplace_back(3, "3.Hero", 3, 13);
    lobi_h.emplace_back(4, "4.Hero", 4, 14);
    lobi_h.emplace_back(5, "5.Hero", 5, 15);
    lobi_h.emplace_back(6, "6.Hero", 16, 6);
    lobi_h.emplace_back(7, "7.Hero", 17, 7);
    lobi_h.emplace_back(8, "8.Hero", 18, 8);
    lobi_h.emplace_back(9, "9.Hero", 19, 9);
    lobi_h.emplace_back(10,"10.Hero", 20, 10);

    G_manager g_manager;
    P_manager p_manager;
    H_manager h_manager;
    vector<P_H>first;
    vector<P_H>second;

    do 
    {
        choise = print_menu();
        switch (choise) 
        {
        case 1:
            g_manager.Perfotm_g_session(first, second, lobi_p, lobi_h);
            system("pause");
            break;
        case 2:
            g_manager.print_game();
            system("pause");
            break;
        case 3:
            cout << "Add [a] or Remove [r]" << endl;
            cin >> choice;
            if (choice == "add" || choice == "a" || choice == "Add")
            {
                int id;
                string name;
                int rank;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Rank: ";
                cin >> rank;
                cout << "Enter ID: ";
                cin >> id;
                player.emplace_back(p_manager.create_p(id, name, rank));
            }
            else if (choice == "r" || choice == "remove" || choice == "Remove")
            {
                if (player.size() == 0)
                {
                    cout << "List Empty" << endl;
                }
                else
                {
                    int id;
                    cout << "List:" << endl;
                    for (int i = 0; i < player.size(); i++)
                    {
                        cout << "[" << i << "]" << player[i] << endl;
                    }
                    cout << "Enter id " << endl;
                    cin >> id;
                    if (id >= 0 && id < player.size())
                    {
                        p_manager.delete_p(player[id]);
                    }
                }
            }
            break;

        case 4:
            cout << "Add[a] or Remove[r]" << endl;
            cin >> choice;
            if (choice == "a" || choice == "add" || choice == "Add")
            {
                int id;
                string name;
                int hp;
                int dmg;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter HP: ";
                cin >> hp;
                cout << "Enter dmg: ";
                cin >> dmg;
                cout << "Enter ID: ";
                cin >> id;
                hero.emplace_back(h_manager.create_h(id, name, hp, dmg));
            }
            else if (choice == "r" || choice == "remove" || choice == "Remove")
            {
                if (hero.size() == 0)
                {
                    cout << "List Empty" << endl;
                }
                else
                {
                    int id;
                    cout << "List:" << endl;
                    for (int i = 0; i < hero.size(); i++)
                    {
                        cout << "[" << i << "]" << hero[i] << endl;
                    }
                    cout << "Enter Id " << endl;
                    cin >> id;
                    if (id >= 0 && id < hero.size())
                    {
                        h_manager.delete_h(hero[id]);
                    }
                }
            }
            break;
        case 5:
            cout << "Bye......!" << endl;
            break;
        default:
            cout << "WRONG CHOICE!!!!" << endl;
        }
    } while (choise != 5);
}