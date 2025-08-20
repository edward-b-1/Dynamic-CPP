
#include <print>
#include <>
#include <cstdint>
#include <vector>
#include <map>

struct BaseTag {

    uint64_t tag
}

struct Base {

    BaseTag base_tag;
    uint64_t data; // either holds data up to 64 bits wide, or a pointer to data
};

struct Int64 {

    Base base;
};


struct FunctionInstance {
    // possible extension, arguments have names so ordering does not matter (kwargs)
    // should functions arguments have names? or just an ordering?

    std::function function;
    std::map<std::string, Base*> function_arguments;

    void execute(std::map<std::string, Base*> function_arguments) {
        function(function_arguments)
    }
};

struct FunctionManager {

    std::map<std::string, std::vector<FunctionInstance>> functions;

    void registerFunction(std::string function_name, FunctionInstance function_instance) {
        if functions.contains(function_name) {
            functions[function_name].push_back(function_instance)
        }

        functions[function_name] = std::vector<FunctionInstance>(function_instance);
    }

                                                                        // ref ?
    void call(std::string_view function_name, std::map<std::string, *Base> &function_arguments) {
        if (!functions.contains(function_name)) {
            throw std::runtime_error("function name {function name} does not exist");
        }

        auto &function_instance_list = functions[function_name];

        for (const auto& function_instance: function_instance_list) {
            function_instance_function_arguments = function_instance.function_arguments;

            length_1 = function_arguments.size();
            length_2 = function_instance_function_arguments.size();

            if(length_1 != length_2) {
                continue;
            }

            // TODO: what about duplicated names?
            name_does_not_match = false;
            for (const auto& function_argument: function_arguments) {
                function_argument_name = function_argument.first;

                if (!function_instance_function_arguments.contains(function_argument_name)) {
                    name_does_not_match = true;
                    break;
                }
            }

            if (name_does_not_match == true) {
                continue;
            }

            // if get to here, function arguments have same length and names all match
        }

        function_instance.execute(function_arguments)
    }
};


int main() {



    return 0;
}