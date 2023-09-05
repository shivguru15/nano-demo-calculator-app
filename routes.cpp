#include "crow_all.h"

crow::response greet()
{
    return crow::response{"Hello world!"}; // Return a greeting
}

crow::response add(const crow::request &req)
{
    try {
        auto input = crow::json::load(req.body);

        if (!input) {
            throw std::runtime_error("Invalid JSON input");
        }

        double first = input["first"].d();
        double second = input["second"].d();

        double result = first + second;

        crow::json::wvalue response;
        response["result"] = result;

        return crow::response{crow::json::dump(response)};
    } catch (const std::exception &e){
        return crow::response(400, e.what());
    }
}

crow::response subtract(const crow::request &req)
{
    try {
        auto input = crow::json::load(req.body);

        if (!input) {
            throw std::runtime_error("Invalid JSON input");
        }

        double first = input["first"].d();
        double second = input["second"].d();

        double result = first - second;

        crow::json::wvalue response;
        response["result"] = result;

        return crow::response{crow::json::dump(response)};
    } catch (const std::exception &e) {
        return crow::response(400, e.what());
    }
}


