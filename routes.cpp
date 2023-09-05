#include "crow_all.h"
#include <iostream>

void greet(const crow::request&, crow::response& res) {
    res.code = 200;
    res.write("Hello world!");
    res.end();
}

void add(const crow::request& req, crow::response& res) {
    try {
        // Parse JSON request body
        auto json = crow::json::load(req.body);
        if (!json) {
            throw std::runtime_error("Invalid JSON");
        }

        double first = json["first"].d();
        double second = json["second"].d();

        double result = first + second;

        crow::json::wvalue response;
        response["result"] = result;

        res.code = 200;
        res.write(crow::json::dump(response));
        res.end();
    } catch (const std::exception& e) {
        res.code = 400;
        res.write(e.what());
        res.end();
    }
}

void subtract(const crow::request& req, crow::response& res) {
    try {
        // Parse JSON request body
        auto json = crow::json::load(req.body);
        if (!json) {
            throw std::runtime_error("Invalid JSON");
        }

        double first = json["first"].d();
        double second = json["second"].d();

        double result = first - second;

        crow::json::wvalue response;
        response["result"] = result;

        res.code = 200;
        res.write(crow::json::dump(response));
        res.end();
    } catch (const std::exception& e) {
        res.code = 400;
        res.write(e.what());
        res.end();
    }
}