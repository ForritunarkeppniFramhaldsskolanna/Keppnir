#include <iostream>
#include <string>
#include <cctype>

std::string convert(char c) {
    switch (c) {
        case 'Á': return "a";
        case 'á': return "a";
        case 'Ð': return "d";
        case 'ð': return "d";
        case 'É': return "e";
        case 'é': return "e";
        case 'Í': return "i";
        case 'í': return "i";
        case 'Ó': return "o";
        case 'ó': return "o";
        case 'Ú': return "u";
        case 'ú': return "u";
        case 'Ý': return "y";
        case 'ý': return "y";
        case 'Þ': return "th";
        case 'þ': return "th";
        case 'Æ': return "ae";
        case 'æ': return "ae";
        case 'Ö': return "o";
        case 'ö': return "o";
        default: return "";
    }
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::string result = "";
    for (char c : line) {
        if (std::isalnum(c)) {
            result += std::tolower(c);
        } else if (c == ' ') {
            continue;
        } else if (
             c == 'Á' || c == 'á' ||
             c == 'Ð' || c == 'ð' ||
             c == 'É' || c == 'é' ||
             c == 'Í' || c == 'í' ||
             c == 'Ó' || c == 'ó' ||
             c == 'Ú' || c == 'ú' ||
             c == 'Ý' || c == 'ý' ||
             c == 'Þ' || c == 'þ' ||
             c == 'Æ' || c == 'æ' ||
             c == 'Ö' || c == 'ö')
             {

            result += convert(c);
        }
    }

    result += ".is";
    std::cout << result << std::endl;

    return 0;
}
