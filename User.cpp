#include "User.h"

void User::displayInfo() {
  cout << "Name: " << name << "\nPhone: " << phone << "\nAge: " << age << endl;
  if (!this->activites.isEmpty()) {
    for (size_t i =0 ; i<activites.getSize(); i++) {
    cout<<"i = "<<i<<endl;
    this->activites[i].displayPost();
    }
  
  }
  else {
    cout<<"No posts"<<endl;
  }
}

string User::getName() const { return this->name; }
string User::getPhone() const { return this->phone; }
string User::getHandel() const { return this->handel; }
size_t User::getAge() const { return this->age; }



User::User() : name("UNKOWN"), phone("UNKOWN"), handel(""), age(0) {}

User::User(string name, string phone, string handel, int age,string pfp,string banner)
    : name(name), phone(phone), handel(handel), age(age) ,pfp(pfp),banner(banner){}
void User::addPost(const string &content,const string &pic) {
  this->activites.enqueue(Activity(content,pic));
}
void User::addLikes(size_t post_num, size_t Likes) {

  this->activites[post_num].addLikes(Likes);
}
void User::addViews(size_t post_num, size_t Views) {
  this->activites[post_num].addViews(Views);
}


