#ifndef JSON_VALUE_HPP
#define JSON_VALUE_HPP

#include <chrono>
#include <string>
#include <unordered_map>
#include <vector>

#define NOT_IMPLEMENTED "NOT IMPLEMENTED"


namespace rx {

struct JSONPair;

// =====================================
//          JSON VALUE
// =====================================

struct JSONValue {

    virtual std::string toString() = 0;

    virtual ~JSONValue() = 0;
};

inline JSONValue::~JSONValue() {};




// =====================================
//          JSON VALUE <Number>
// =====================================

struct JSONValue_num : public JSONValue {

    JSONValue_num(double value, std::string str) : m_value(value), m_str(str) {};

    bool isInt() {return (asInt() - asDouble()) == 0;}

    int asInt() {return m_value;}

    double asDouble() {return m_value;}

    std::string asString() {return m_str;}


    std::string toString() override {
        return std::to_string(m_value);
    };

    ~JSONValue_num() {};

private:
    double m_value;
    std::string m_str;
};

// =====================================
//          JSON VALUE <STRING>
// =====================================

struct JSONValue_string : public JSONValue {
    JSONValue_string(std::string s) : m_value(s) {};

    std::string toString() override {
        return "\"" + m_value + "\"";
    };

    ~JSONValue_string() {};

private:
    std::string m_value;
};


// =====================================
//          JSON VALUE <DATE>
// =====================================



struct JSONValue_date : public JSONValue {

    JSONValue_date(std::chrono::year_month_day date) : m_date(date) {};

    std::string toString() override {
        return std::to_string(static_cast<int>(m_date.year())) 
        + "-" + std::to_string(static_cast<unsigned>(m_date.month())) 
        + "-" +  std::to_string(static_cast<unsigned>(m_date.day()));
    };

    ~JSONValue_date() {};


private:
    std::chrono::year_month_day m_date;
};

// =====================================
//          JSON VALUE <BOOL>
// =====================================


struct  JSONValue_bool : public JSONValue {

    JSONValue_bool(bool value) : m_value(value) {};

    std::string toString() override {
        return m_value ? "true" : "false";
    };

    ~JSONValue_bool() {};

private:
    bool m_value;
};

// =====================================
//          JSON VALUE <ARRAY>
// =====================================


struct  JSONValue_array : public JSONValue {

    JSONValue_array() {};

    std::string toString() override {
        std::string s = "[";
        for (JSONValue* v : m_array) {
            s += v->toString();
            if (v != m_array.back()) {
                s+=',';
            }
        }
        return s += ']';
    };

    ~JSONValue_array() {
        for(JSONValue* ptr : m_array) {
            delete ptr;
        }
    };

    void push(JSONValue* val) {
        m_array.push_back(val);
    }

private:
    std::vector<JSONValue*> m_array;
};

// =====================================
//          JSON PAIR 
// =====================================


struct JSONPair {

    JSONPair(std::string k, JSONValue* v) : m_key(k), m_value(v) {};

    ~JSONPair() {delete m_value;};

    std::string toString() {
        return "{" + m_key + ":" + m_value->toString() + "}";
    }

    std::string m_key;
    JSONValue* m_value;
};

// =====================================
//          JSON NODE
// =====================================

class JSONNode : public JSONValue {

public:
    JSONNode() : m_parent(nullptr) {};

    JSONNode(JSONValue* parent) : m_parent(parent) {};

    std::string toString() override {
        std::string s = "{\n";
        for(JSONPair* p : m_pairs) {
            s += "\t" + p->toString();
            if (p != m_pairs.back()) s+= ",\n";
           
        }

        return s+="\n}";
    };

    bool isRoot() {return m_parent == nullptr;}

    void push(JSONPair* pair) {
       m_pairs.push_back(pair);
    }

    ~JSONNode() {
        for (JSONPair* p : m_pairs) {
            delete p;
        }
    };

    

private:
    JSONValue* m_parent; 
    std::vector<JSONPair*> m_pairs;
    
};


} // end namespace

#endif