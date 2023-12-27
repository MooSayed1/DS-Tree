
#include <cstddef>
#include <iostream>
#include <string>
#include <ctime>

class Activity {
private:
    std::string content;
    size_t likes;
    size_t views;
    std::string date;

public:
    // Constructor
    Activity() : likes(0), views(0) {
        std::time_t now = std::time(0);
        this->date = std::ctime(&now);
    }
    Activity(std::string Content):content(Content),likes(0),views(0) {
        std::time_t now = std::time(0);
        this->date = std::ctime(&now);
    }

    void addLikes(size_t Likes ){
        likes+=Likes;
    }
    
    void addViews(size_t Views ){
        views+=Views;
    }
        const std::string& getContent() const {
        return content;
    }

    // Getter for likes
    size_t getLikes() const {
        return likes;
    }

    // Getter for views
    size_t getViews() const {
        return views;
    }

    // Getter for date
    const std::string& getDate() const {
        return date;
    }
    // Display post information
    void displayPost() {
        std::cout << "Content: " << content << std::endl;
        std::cout << "Likes: " << likes << std::endl;
        std::cout << "Views: " << views << std::endl;
        std::cout << "Date: " << date << std::endl;
    }
};
