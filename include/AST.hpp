#pragma once

#include <memory>
#include <string>
#include <vector>

// Now we need to create our AST
// This tree will have Nodes
// Each node will know how to transpile itself into c++ code
// We will create a base Node and then Nodes like: PrintNode, VariableNodes...

class Node {
  public:
    virtual ~Node() = default;
    virtual std::string transpile() = 0;
};

// This will be te parent node that will hold on all of the chuld nodes
class ProgramNode : public Node {
  public:
    std::vector<std::unique_ptr<Node>> statements;

    std::string transpile() override {
        std::string output = "#include<iostream>\n#include<string>\nint main() {\n";

        // Now we can loop and transpile each Node
        for(const auto& stm : statements){
            output += "    " + stm->transpile() + "\n";
        }

        output += "return 0;\n}";

        return output;
    }
};

class PrintNode : public Node {
    public:
        PrintNode(std::string c, bool s): content(c), isString(s) {};
        std::string transpile() override {
            if(isString) return "std::cout<<\"" + content + "\" << std::endl;";
            return "std::cout<<" + content + " << std::endl;";
        }
    private:
        std::string content;
        bool isString;
}; 

class InputNode : public Node {
    public:
        InputNode(std::string name): varName(name) {};
        std::string transpile() override {
            return "std::cin>>" + varName + ";";
        }
    private:
        std::string varName;
}; 

class VarDeclNode : public Node {
    public:
        VarDeclNode(std::string c, std::string v): name(c), value(v) {}
        std::string transpile() override {
            bool isLikelyString = false;

            if(!value.empty() && !isdigit(value[0])){
                isLikelyString = true;
            }

            if(value == "\"\"" || value == "") {
                return "std::string " + name + ";"; // Better for empty Urdu strings
            }
            
            return "auto " + name + " = " + value + ";";
        }
    private:
        std::string name;
        std::string value;
};
