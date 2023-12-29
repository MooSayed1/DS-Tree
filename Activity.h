
#include <cstddef>
#include <ctime>
#include <iostream>
#include <string>

class Activity {
private:
  std::string content;
  std::string pic;
  size_t likes;
  size_t views;
  time_t date;

public:
  // Constructor
  Activity() : content("NONE"), pic(NULL), likes(0), views(0) {
    std::time_t now = std::time(0);
    this->date = now;
  }
  Activity(std::string Content, std::string Pic)
      : content(Content), pic(Pic), likes(0), views(0) {
    std::time_t now = std::time(0);
    this->date = now;
  }
  // Copy constructor
  Activity(const Activity &other)
      : content(other.content), pic(other.pic), likes(other.likes),
        views(other.views), date(other.date) {}

  // Assignment operator overload
  Activity &operator=(const Activity &other) {
    if (this != &other) { // Check for self-assignment
      content = other.content;
      pic = other.pic;
      likes = other.likes;
      views = other.views;
      date = other.date;
    }
    return *this;
  }

  void addLikes(size_t Likes) { likes += Likes; }

  void addViews(size_t Views) { views += Views; }
  const std::string &getContent() const { return content; }
  const std::string &getPic() const { return content; }

  // Getter for likes
  size_t getLikes() const { return likes; }

  // Getter for views
  size_t getViews() const { return views; }

  // Getter for date
  time_t getDate() const { return date; }
  // Display post information
  void displayPost() {
    std::cout << "Content: " << content << std::endl;
    std::cout << "Likes: " << likes << std::endl;
    std::cout << "Views: " << views << std::endl;
    std::cout << "Date: " << date << std::endl;
  }
};
