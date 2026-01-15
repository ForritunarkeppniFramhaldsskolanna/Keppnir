#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int n, l, t;
    std::cin >> n >> l >> t;
    std::cin.ignore(); 

    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<std::string> words;
    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }

    int max_chars_per_line = l * t;
    std::vector<std::string> output_lines;
    std::string current_line;
    int current_line_length = 0;

    for (int i = 0; i < n; ++i) {
        int word_length = words[i].length();
        
        if (i == 0) {
            if (word_length > max_chars_per_line)
            {
                std::cout << "/ff" << std::endl;
                return 0;
            }
            current_line = words[i];
            current_line_length = word_length;
        } else {
            if (current_line_length + 1 + word_length <= max_chars_per_line) {
                current_line += " " + words[i];
                current_line_length += 1 + word_length;
            } else {
                output_lines.push_back(current_line);
                current_line = words[i];
                current_line_length = word_length;
                if(word_length > max_chars_per_line)
                {
                    std::cout << "/ff" << std::endl;
                    return 0;
                }
            }
        }
    }
    output_lines.push_back(current_line);
    
    int total_chars = 0;
    for(const auto &each_line : output_lines)
    {
        total_chars += each_line.size() +1;
    }
    
    int words_total_length= 0;
    for(const auto& each_word : words)
    {
        words_total_length += each_word.size();
    }

     if(words_total_length + (int)words.size() -1 > (int) output_lines.size() * max_chars_per_line)
     {
          std::cout << "/ff" << std::endl;
           return 0;
     }

    for (const auto& line : output_lines) {
        std::cout << line << std::endl;
    }

    return 0;
}
