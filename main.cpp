#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
using namespace std;
void sleep(std::chrono::duration<int> time)
{
  std::this_thread::sleep_for(time);
}
class Player
{
  private:
  string userName;
  int health;
  int meleeDamage;
  int rangedDamage;
  int damage;
  int specialAbilities;

public:
Player(string name,int value,int damage)
{
  SetPlayerName(name);
  SetHealth(value);
  SetMeleeDamage(damage);
  cout << name<<" is ready to fight \n\n";
}
  int const GetHealth()
  {
    return health;
  }
  void SetHealth(int value)
  {
    health = value;
  }
  int const GetMeleeDamage()
  {
    return meleeDamage;
  }
  void SetMeleeDamage(int damage)
  {
    meleeDamage = damage;
  }
  string const GetPlayerName()
  {
    return userName;
  }
  void SetPlayerName(string name)
  {
    userName = name;
  }
  int const GetRangedDamage()
{
  return rangedDamage;
}
void SetRangedDamage(int damage)
{
  rangedDamage = damage;
}
 void RandomizeRangedDamage()
{
  SetRangedDamage(5 + rand() % 9);
}
void PlayerStats()
{
  cout<< GetPlayerName() << ": Health = " << GetHealth()<<"\n";
  cout<< GetPlayerName() << ": Damage Power = " << GetMeleeDamage()<<"\n\n";
}

};

class Enemy
{
  private:
  string enemyName;
  int enemyHealth;
  int enemyDamage;
  int enemyRangedDamage;
  public:
  Enemy(string name,int value,int damage)
  {
    SetEnemyName(name);
    SetEnemyHealth(value);
    SetEnemyDamage(damage);
  }
  string const GetEnemyName()
  {
    return enemyName;
  }
  void SetEnemyName(string name)
  {
    enemyName = name;
  }
  int const GetEnemyHealth()
  {
    return enemyHealth;
  }
  void SetEnemyHealth(int value)
  {
    enemyHealth = value;
  }
  int const GetEnemyDamage()
  {
    return enemyDamage;
  }
  void SetEnemyDamage(int damage)
  {
    enemyDamage = damage;
  }
  int const GetEnemyRangedDamage()
{
  return enemyRangedDamage;
}
  void SetEnemyRangedDamage(int damage)
{
  enemyRangedDamage = damage;
}
  void RandomizeEnemyRangedDamage()
{
  SetEnemyRangedDamage(2 + rand() % 5);
}
  void RandomizeMurlocsRangedDamage()
{
  SetEnemyRangedDamage(6 + rand() % 5);
}

void EnemyStats()
{
  cout<< GetEnemyName() << ": Health = " << GetEnemyHealth()<<"\n";
  cout<< GetEnemyName() << ": Damage Power = " << GetEnemyDamage()<<"\n\n";
}
};

void level6(Player *p)
{
    cout <<"Wola...!!!! Warrior " <<p->GetPlayerName()<<" you doing great...!!\n\n";sleep(1s);
    cout <<"Now It's Time ....now you have all the power which will help to defaet...'Murlocs'!!\n\n";sleep(1s);
    cout <<"But the battle with 'Murlocs' is not gonna easy...  \n\n";sleep(1s);
    cout <<"You have to visit at 'Titan', Where you find the Biggest Monster 'Murlocs....' \n\n"; 
    cout <<"Press Enter To visit 'Titan'... ";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout <<"\nLook there is 'Murlocs', I think he is waiting for you..!\n\n";sleep(1s);
    cout <<"Because you killed most of monster enemy of 'Murlocs' \n\n";
    cout <<"Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout <<"\nohh Look 'Murlocs' coming towards you.Be Ready Warrior use all your weapon at a right time...\n\n";
    cout <<"Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<"Fight Begins !!!\n\n";
    Enemy  *e1 = new Enemy("Murlocs",200,20);
    p->PlayerStats();
    e1->EnemyStats();
    cout <<"Press Enter To Fight... ";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(true) 
    { 
      if ( p->GetHealth() <= 0 )  //  lose
      {
      p->PlayerStats();
      e1->EnemyStats();
      sleep(2s);
      cout << p->GetPlayerName() <<" died...\n";
      cout << p->GetPlayerName() << " lose the battle";
      break;
      }  //  end
      else if ( e1->GetEnemyHealth() <= 0 )  //  win
      {
      sleep(2s);   
      cout<<"\nFight Result: \n";  
      p->PlayerStats();
      e1->EnemyStats(); 
      cout << "Hurry!!"<< p->GetPlayerName() << " defeated the Biggest Monster 'Murlocs'!!\n\n";sleep(1s);
      cout << "You are Great Warrior "<< p->GetPlayerName() <<".\n\n";sleep(1s);
      cout << p->GetPlayerName() <<" you save the world from Biggest Monster 'Murlocs' with your bravery\n";
      cout << "\n";
      break;
      }  
    p->RandomizeRangedDamage();
    e1->RandomizeMurlocsRangedDamage();
    e1->SetEnemyHealth(e1->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    p->SetHealth(p->GetHealth() - (e1->GetEnemyDamage() + e1->GetEnemyRangedDamage()));
    }
    cout << "Press Enter To Further Journey!!!! ... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("clear");
    delete e1;
    delete p;
    exit(1);
}

void level5(Player *p)
{
    cout <<"Wola...!!!! Warrior " <<p->GetPlayerName()<<" you doing great...!!\n\n";sleep(1s);
    cout <<"But this power will don't help you to defeat 'Murlocs'!!\n\n";sleep(1s);
    cout <<"you need a special bow which is created by Alatanias 'Mr. Hawkeye'.. \n\n";sleep(1s);
    cout <<"You have to visit Atlanias \n\n"; 
    cout <<"Press Enter To visit Atlanias... ";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout <<"Look you found Atlanias cave..!\n\n";sleep(1s);
    cout << p->GetPlayerName() <<" look there is 'Mr. Hawkeye' Bow called 'Recurve Bow' \n\n";
    cout <<"Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout <<"\nohh Look there are 4 Guards, who are are Guarding the 'Recurve Bow'...\n\n";
    cout <<"Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Enemy  *e1 = new Enemy("G1",50,10);
    Enemy  *e2 = new Enemy("G2",50,10);
    Enemy  *e3 = new Enemy("G3",50,10);
    Enemy  *e4 = new Enemy("G4",50,10);
    p->PlayerStats();
    e1->EnemyStats();
    e2->EnemyStats();
    e3->EnemyStats();
    e4->EnemyStats();
    cout<<"Fight Begins !!!\n\n";
    cout <<"Press Enter To Fight ...";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(true) 
    { 
      if ( p->GetHealth() <= 0 )  //  lose
      {
      p->PlayerStats();
      e1->EnemyStats();
      e2->EnemyStats();
      e3->EnemyStats();
      e4->EnemyStats();
      sleep(2s);
      cout << p->GetPlayerName() <<" died...\n\n";
      cout << p->GetPlayerName() << " lose the battle\n\n";
      break;
      }  //  end
      else if ( e1->GetEnemyHealth() <= 0 && e2->GetEnemyHealth()<=0 && e3->GetEnemyHealth() <= 0 && e4->GetEnemyHealth()<=0)  //  win
      {
      sleep(2s);   
      cout<<"\nFight Result: \n"; 
      p->PlayerStats();
      e1->EnemyStats();
      e2->EnemyStats();
      e3->EnemyStats();
      e4->EnemyStats(); 
      cout << "Hurry!!"<< p->GetPlayerName()<< " defeated the all 4 Guards..G1,G2,G3,G4!!\n\n";sleep(1s);
      cout << "Hurry!! You Got Your Special 'Recurve Bow.\n\n";
      cout << "Press Enter To Collect 'Recurve Bow'  ...";
      cin.get();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      p->SetMeleeDamage(35);
      cout << "'Recurve Bow' added your Damage power, Now your Damage Power is: "<<p->GetMeleeDamage()<<".\n\n";sleep(1s);
      cout << "'Recurve Bow' will help you to defeat Murlocs.\n\n";sleep(1s);
      break;
      }  
    p->RandomizeRangedDamage();
    e1->RandomizeEnemyRangedDamage();
    e2->RandomizeEnemyRangedDamage();
    e3->RandomizeEnemyRangedDamage();
    e4->RandomizeEnemyRangedDamage();
    e1->SetEnemyHealth(e1->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    e2->SetEnemyHealth(e2->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    e3->SetEnemyHealth(e3->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    e4->SetEnemyHealth(e4->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    p->SetHealth(p->GetHealth() - ((e1->GetEnemyDamage() + e2->GetEnemyDamage()
    + e3->GetEnemyDamage() + e4->GetEnemyDamage()) + (e1->GetEnemyRangedDamage()
    + e2->GetEnemyRangedDamage()
    + e3->GetEnemyRangedDamage()
    + e4->GetEnemyRangedDamage())));
   }
    cout << "Press Enter To Further Journey!!!! ... ";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("clear");
    delete e1;
    delete e2;
    delete e3;
    delete e4;
    level6(p);
}

void level4(Player *p)
{
    cout  << "ohhh you heavily injured in fight with 'Dora Milaje'..!\n\n";sleep(1s);
    cout << "You need a First Aid !!\n\n";sleep(1s);
    cout  << "Take this Ayurvedic Medicine you feel better and also get some boost in you health\n\n";sleep(1s);
    cout << "Press Enter To take Medicine... ";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    p->SetHealth(p->GetHealth()+50);
    cout<< "your Health = " << p->GetHealth()<<"\n\n";sleep(1s);
    cout  << "ohh your Health is too low to fight with 'Murlocs'..!\n\n";sleep(1s);
    cout << p->GetPlayerName() <<" you need to get more energy to your body,you must to go 'Zaltan'. In 'Zaltan' their is health up bar called 'Z1 Bar',It will power up your body...\n\n";
    cout << "Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     cout << "\nohh Look there is 'Skrulls'.'F01' and 'L01' are Guarding the 'Z1 Bar'...\n\n";
    cout << "Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Enemy  *e1 = new Enemy("F01",50,7);
    Enemy  *e2 = new Enemy("L01",50,7);
    p->PlayerStats();
    e1->EnemyStats();
    e2->EnemyStats();
    cout<< "Fight Begins !!!\n\n";
    cout << "Press Enter To Fight ...";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(true) 
    { 
      if ( p->GetHealth() <= 0 )  //  lose
      {
      p->PlayerStats();
      e1->EnemyStats();
      e2->EnemyStats();
      sleep(2s);
      cout << p->GetPlayerName() <<" died...\n\n";
      cout << p->GetPlayerName() << " lose the battle\n\n";
      break;
      }  //  end
      else if ( e1->GetEnemyHealth() <= 0 && e2->GetEnemyHealth()<=0)  //  win
      {
      sleep(2s);   
      cout<<"\nFight Result: \n";  
      p->PlayerStats();
      e1->EnemyStats();
      e2->EnemyStats();
      cout << "Hurry!!"<< p->GetPlayerName()<< " defeated the " << e1->GetEnemyName()<< " & " << e2->GetEnemyName()<< "!!\n\n";sleep(1s);
      cout << "Hurry!! You Got Your Special 'Z1 Bar',It will boost your energy\n\n";
      cout << "Press Enter To eat bar ...";
      cin.get();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      p->SetHealth(p->GetHealth()+200);
      cout<< "\nLook 'Z1 Bar' boosting your Health!! \n"<< "Now "<<p->GetPlayerName() <<"'s Health : "<< p->GetHealth()<<"\n\n";sleep(1s);
      cout << "Look what you got for Defeating "<<e1->GetEnemyName()<< " & " << e2->GetEnemyName()<< "\n\n";sleep(1s);
      cout << "Press Enter To View Reward ...";
      cin.get();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout<<"Hurryy you got Iron Armour, which build by legendary 'Sir Downey Jr.'\n\n";
      break;
      }  
    p->RandomizeRangedDamage();
    e1->RandomizeEnemyRangedDamage();
    e2->RandomizeEnemyRangedDamage();
    e1->SetEnemyHealth(e1->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    e2->SetEnemyHealth(e2->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    p->SetHealth(p->GetHealth() - ((e1->GetEnemyDamage() + e2->GetEnemyDamage()) + (e1->GetEnemyRangedDamage()
    + e2->GetEnemyRangedDamage())));
   }
    cout << "Press Enter To Further Journey!!!! ... ";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("clear");
    delete e1;
    delete e2;
    level5(p);
}
void level3(Player *p)
{
    cout  << "Further Journey Will be more harder..!\n\n";sleep(1s); 
    cout  << "You need a special 'Vibranuim Shield' for Upcoming journey!!\n\n";sleep(1s); 
    cout << "Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\nYou need to visit 'Wakanda'to get your 'Vibranuim Shield'...\n\n";sleep(1s);
    cout << "Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\nohh Look there are 3 'Dora Milaje' 'kay','may','lay' are Guarding the 'Shield'...\n\n";sleep(2s);
    cout << "'Dora Milaje' 'kay','may','lay' are powerful soldier of 'Murlocs'...\n\n";sleep(2s);
    cout << "You have to defeat 'kay','may' and 'lay' to get your 'Vibranuim Shield'\n\n";sleep(1s);
    Enemy  *e1 = new Enemy("kay",60,10);
    Enemy  *e2 = new Enemy("may",60,10);
    Enemy  *e3 = new Enemy("lay",60,10);
    p->SetMeleeDamage(20);
    p->SetHealth(p->GetHealth()+100);
    p->PlayerStats();
    e1->EnemyStats();
    e2->EnemyStats();
    e3->EnemyStats();
    cout<< "Fight Begins !!!\n\n";
    cout << "Press Enter To Fight ...";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     while(true) 
    { 
      if ( p->GetHealth() <= 0 )  //  lose
      {
      p->PlayerStats();
      e1->EnemyStats();
      e2->EnemyStats();
      e3->EnemyStats();
      sleep(2s);
      cout << p->GetPlayerName() <<" died...\n\n";
      cout << p->GetPlayerName() << " lose the battle\n\n";
      break;
      }  //  end
      else if ( e1->GetEnemyHealth() <= 0 && e2->GetEnemyHealth()<=0 && e3->GetEnemyHealth()<=0)  //  win
      {
      sleep(2s);  
      cout<<"\nFight Result: \n";    
      p->PlayerStats();
      e1->EnemyStats();
      e2->EnemyStats();
      e3->EnemyStats();
      //sleep(2s);  
      cout << "Hurry!!"<< p->GetPlayerName()<< " defeated the " << e1->GetEnemyName()<< " , " << e2->GetEnemyName()<< " & " <<e3->GetEnemyName()<< "!!\n\n";sleep(1s);
      cout << "Look what you get form Defeating "<<e1->GetEnemyName()<< ", " << e2->GetEnemyName()<< " & " <<e3->GetEnemyName()<< "\n\n";
      cout << "Hurry!! You Got Your Special 'Vibranuim Shield',It will help you on further Journey\n\n";
      break;
      }  
    p->RandomizeRangedDamage();
    e1->RandomizeEnemyRangedDamage();
    e2->RandomizeEnemyRangedDamage();
    e3->RandomizeEnemyRangedDamage();
    e1->SetEnemyHealth(e1->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    e2->SetEnemyHealth(e2->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    e3->SetEnemyHealth(e3->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    p->SetHealth(p->GetHealth() - ((e1->GetEnemyDamage() + e2->GetEnemyDamage() + e3->GetEnemyDamage()) + (e1->GetEnemyRangedDamage()
    + e2->GetEnemyRangedDamage() + e3->GetEnemyRangedDamage())));
   }
    cout << "Press Enter To Further Journey!!!! ... ";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("clear");
    delete e1;
    delete e2;
    delete e3;
    level4(p);

}
void level2(Player *p)
{
    cout  << "Further Journey Will be more hard..!\n\n";sleep(1s); 
    cout  << "You need a special sword for Upcoming journey!!\n\n";
    cout << "Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\nYou need to visit 'Nowhere'to get your Sword Warrior...\n\n";sleep(1s);
    cout << "Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\nohh Look there are 2 Monster 'Akka' and 'Bakka' are Guarding the 'Sword'...\n\n";sleep(2s);
    cout << "You have to defeat 'Akka' and 'Bakka' to get your Sword\n\n";sleep(1s);
    Enemy  *e1 = new Enemy("Akka",70,10);
    Enemy  *e2 = new Enemy("Bakka",70,10);
    p->PlayerStats();
    e1->EnemyStats();
    e2->EnemyStats();
    cout<< "Fight Begins !!!\n\n";
    cout << "Press Enter To Fight ...";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(true) 
    { 
      if ( p->GetHealth() <= 0 )  //  lose
      {
      p->PlayerStats();
      e1->EnemyStats();
      e2->EnemyStats();
      sleep(2s);
      cout << p->GetPlayerName() <<" died...\n\n";
      cout << p->GetPlayerName() << " lose the battle\n\n";
      break;
      }  //  end

      else if ( e1->GetEnemyHealth() <= 0 && e2->GetEnemyHealth())  //  win
      {
      sleep(2s);   
      cout<<"\nFight Result: \n";    
      p->PlayerStats();
      e1->EnemyStats();
      e2->EnemyStats();  
      cout << "Hurry!!"<< p->GetPlayerName()<< " defeated the " << e1->GetEnemyName()<< " & " << e2->GetEnemyName()<<"!!\n\n";sleep(1s);
      cout << "Look what you got for Defeating "<<e1->GetEnemyName()<< " & " << e2->GetEnemyName()<<"\n\n";
      cout << "Hurry!! You Got Your Special Sword 'Mjolnir',It will help you on further Journey\n\n";sleep(2s);
      cout << "You can continue your journey.\n\n";sleep(0s);
      break;
      }  
    p->RandomizeRangedDamage();
    e1->RandomizeEnemyRangedDamage();
    e2->RandomizeEnemyRangedDamage();
    e1->SetEnemyHealth(e1->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    e2->SetEnemyHealth(e2->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    p->SetHealth(p->GetHealth() - ((e1->GetEnemyDamage()+ e1->GetEnemyRangedDamage()) + (e2->GetEnemyDamage() - e2->GetEnemyRangedDamage())));
   }
    cout << "Press Enter To Further Journey!!!! ... ";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("clear");
    delete e1;
    delete e2;
    level3(p);
}
void level1()
{
    cout  << "Welcome to Jumanji!\n\n";
    string userName;
    cout << "Press Enter To Continue... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\nPlease Enter Player's Name- ";
    cin >> userName;
    cout << "\n";
    cout << "You are Exellent Warrior.\n\n";sleep(2s);
    cout << "Your journey begins " << userName << "!\n\n";sleep(2s);
    cout << userName <<" you have to save this world from Murlocs.\n\n";sleep(2s);
    cout << "Go Ahead Warrior "<< userName <<"\n\n";sleep(2s);
    cout << "You notice a Murcolos's gang member near to the river...\n\n";sleep(1s);
    Player *p = new Player(userName,200,10);
    Enemy  *e = new Enemy("cartos",100,10);
    p->PlayerStats();
    e->EnemyStats();
    cout<< "Fight Begins !!!\n\n";
    cout << "Press Enter To Fight ...";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(true) 
    { 
      if ( p->GetHealth() <= 0 )  //  lose
      {
      p->PlayerStats();
      e->EnemyStats();
      sleep(2s);
      cout << p->GetPlayerName() <<" died...\n";
      cout << p->GetPlayerName() << " lose the battle";
      break;
      }  //  end
      else if ( e->GetEnemyHealth() <= 0 )  //  win
      {
      sleep(2s);   
      cout<<"\nFight Result: \n";  
      p->PlayerStats();
      e->EnemyStats(); 
      cout << "Hurry!!"<< p->GetPlayerName()<< " defeated the Cartos!\n\n";sleep(1s);
      cout << "You can continue your journey.\n\n";sleep(1s);
      cout << "Look what you got for Defeating Cartos\n\n";
      cout << "Hurry!! You Got Map for further Journey,It will help to find Murlocs\n\n";
      break;
      }  
    p->RandomizeRangedDamage();
    e->RandomizeEnemyRangedDamage();
    e->SetEnemyHealth(e->GetEnemyHealth() - (p->GetRangedDamage() + p->GetMeleeDamage()));
    p->SetHealth(p->GetHealth() - e->GetEnemyDamage());
    }
    cout << "Press Enter To Further Journey!!!! ... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("clear");
    delete e;
    level2(p); 
}

void GameStart()
{
  level1();
}

int main() {

srand (time(NULL));
GameStart();
  
}