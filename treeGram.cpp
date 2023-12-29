#include "treeGram.h"
#include <algorithm>
#include <chrono> // std::chrono::system_clock
#include <crow/middlewares/cors.h>
#include <cstddef>
#include <cstdlib>
#include <random>

treeGram::treeGram() {}
treeGram::~treeGram() {}
void treeGram::test() {
  cout << goFast.size() << endl;

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(std::begin(handels), std::end(handels),
               std::default_random_engine(seed));

  for (unsigned int i = 0; i < handels.size(); i++) {
    cout << handels[i] << endl;
    goFast.search(handels[i])->displayInfo();
  }
}
void treeGram::Deploy() {

    // Enable CORS
    crow::App<crow::CORSHandler> app;

    // Customize CORS
    auto& cors = app.get_middleware<crow::CORSHandler>();

    // clang-format off
    cors
      .global()
        .headers("X-Custom-Header", "Upgrade-Insecure-Requests")
        .methods("POST"_method, "GET"_method)
      .prefix("/cors")
        .origin("tree.almiraj.xyz")
      .prefix("/nocors")
        .ignore();
    // clang-format on

    CROW_ROUTE(app, "/")
    ([]() {
        return "Check Access-Control-Allow-Methods header";
    });

    CROW_ROUTE(app, "/cors")
    ([]() {
        return "Check Access-Control-Allow-Origin header";
    });

  CROW_ROUTE(app, "/add_user")
      .methods("POST"_method)([this](const crow::request &req) {
        auto x = crow::json::load(req.body);
        if (!x)
          return crow::response(400);
        this->addUser(x["name"].s(),x["phone"].s(),x["handel"].s(),x["age"].i());
        cout<<x["name"].s()<<" "<<x["phone"].s()<<" "<<x["handel"].s()<<" "<<x["age"].i()<<endl;
        std::ostringstream os;
        os << x;
        return crow::response{os.str()};
      });



  CROW_ROUTE(app, "/add_post")
      .methods("POST"_method)([this](const crow::request &req) {
        auto x = crow::json::load(req.body);
        if (!x)
          return crow::response(400);

        this->addPost(x["handel"].s(), x["content"].s());
        cout<<x["handel"].s()<<" "<<x["content"].s()<<endl;
        std::ostringstream os;
        os << x;
        return crow::response{os.str()};
      });
  

  CROW_ROUTE(app, "/add_like")
      .methods("POST"_method)([this](const crow::request &req) {
        auto x = crow::json::load(req.body);
        if (!x)
          return crow::response(400);

        this->addLikes(x["handel"].s(), x["id"].i(),1);
        cout<<x["handel"].s()<<" "<<x["id"].s()<<endl;
        std::ostringstream os;
        os << x;
        return crow::response{os.str()};
      });

  // Route handler for posts
  CROW_ROUTE(app, "/jsonfeed")
  ([this] {
    const int n = 10; // Set the number of posts
    std::vector<crow::json::wvalue> postsArray;

    for (int i = 0; i < n; ++i) {
      User *x = goFast.search(handels[i]);
      Activity z = x->activites[0];

      postsArray.push_back(
          crow::json::wvalue({{"id",0},
                              {"Handle", x->getHandel()},
                              {"User_Name", x->getName()},
                              {"Content", z.getContent()},
                              {"Photo", "NONE"},
                              {"likes", z.getLikes()},
                              {"views", z.getViews()},
                              {"Date", z.getDate()}}));
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(handels), std::end(handels),
                 std::default_random_engine(seed));
    return crow::json::wvalue({{"Posts", postsArray}});
  });
  // Route handler for profile
  CROW_ROUTE(app, "/jsonProfile/<string>")
  ([this](std::string Handle) {
    User *x = goFast.search(Handle);

    if (x == NULL)
      return crow::json::wvalue();
    std::vector<crow::json::wvalue> profilePostsArray;

    for (size_t i = 0; i < x->activites.getSize(); i++) {
      profilePostsArray.push_back(
          crow::json::wvalue({{"id", i},
                              {"Content", x->activites[i].getContent()},
                              {"Photo", "NONE"},
                              {"likes", x->activites[i].getLikes()},
                              {"views", x->activites[i].getViews()},
                              {"Date", x->activites[i].getDate()}}));
    }

    return crow::json::wvalue({{"name", x->getName()},
                               {"phone", x->getPhone()},
                               {"handel", x->getHandel()},
                               {"age", x->getAge()},
                               {"activites", profilePostsArray}});
    ;
  });

  app.port(18080).server_name("CrowCpp").multithreaded().run();
}

bool treeGram::addUser(string name, string phone, string handel, int age) {

  if (goFast.search(handel) == NULL) {
    cout << "added User :" << handel << endl;
    handels.push_back(handel);
    goFast.insert(name, phone, handel, age);
    return true;
  }

  return false;
}
bool treeGram::addPost(const string &handel, const string &content) {
  User *temp = goFast.search(handel);

  if (temp != NULL) {
    cout << "added Post for User :" << handel << endl
         << "Content" << content << endl;

    temp->addPost(content);
    return true;
  }
  return false;
}
bool treeGram::addLikes(const string &handel, size_t post_num, size_t Likes) {

  User *temp = goFast.search(handel);
  if (temp != NULL) {
    cout << "added likes for User :" << handel << endl
         << "post : " << post_num << " by " << Likes << endl;

    temp->addLikes(post_num, Likes);
    return true;
  }
  return false;
}
bool treeGram::addViews(const string &handel, size_t post_num, size_t Views) {
  User *temp = goFast.search(handel);
  if (temp != NULL) {
    cout << "added views for User :" << handel << endl
         << "post : " << post_num << " by " << Views << endl;
    temp->addViews(post_num, Views);
    return true;
  }
  return false;
}
