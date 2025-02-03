#include <iostream>
#include "crow.h"

using namespace crow;
using namespace std;

int main() {

    SimpleApp app;

    cout<<"Love you Nourrra - \n";
    CROW_ROUTE(app , "/test").methods(crow::HTTPMethod::GET)([&](const crow::request&req)
    {
//        auto jsonData = crow::json::load(req.body);
////        std::cout << "Request Body: " << req.body << std::endl;
//        if (!jsonData) {
//            return crow::response(400, "Invalid JSON format");
//        }
        crow::json::wvalue response;
        crow::response finalRes (200 , response);
        finalRes.add_header("Access-Control-Allow-Origin", "*");
        finalRes.add_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE");
        finalRes.add_header("Access-Control-Allow-Headers", "Content-Type");
        return finalRes;
    });

    app.port(8080).multithreaded().run();

    cout << "Hello, World!" << std::endl;
    return 0;
}
