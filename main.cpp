#include <iostream>
#include "crow.h"

using namespace crow;
using namespace std;

int main() {

    SimpleApp app;

    CROW_ROUTE(app , "/test").methods(crow::HTTPMethod::GET)([&](const crow::request&req)
    {
//        auto jsonData = crow::json::load(req.body);
////        std::cout << "Request Body: " << req.body << std::endl;
//        if (!jsonData) {
//            return crow::response(400, "Invalid JSON format");
//        }
        crow::json::wvalue response;

        response["Ahmed"] = 9;
        crow::response finalRes (200 , response);
        finalRes.add_header("Access-Control-Allow-Origin", "*");
        finalRes.add_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE");
        finalRes.add_header("Access-Control-Allow-Headers", "Content-Type");
        return finalRes;
    });

    CROW_ROUTE(app , "/GETName").methods(crow::HTTPMethod::POST)([&](const crow::request&req)
                                                             {
        auto jsonData = crow::json::load(req.body);
//        std::cout << "Request Body: " << req.body << std::endl;
        if (!jsonData) {
            return crow::response(400, "Invalid JSON format");
        }

        string name;
        if(jsonData.has("name"))
        {
            name = jsonData["name"].s();
        }
        crow::json::wvalue response;
        response["Name"] = "Your name = " + name;
        crow::response finalRes (200 , response);
        finalRes.add_header("Access-Control-Allow-Origin", "*");
        finalRes.add_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE");
        finalRes.add_header("Access-Control-Allow-Headers", "Content-Type");
        return finalRes;});

    app.port(8080).multithreaded().run();

    cout << "Hello, World!" << std::endl;
    return 0;
}
