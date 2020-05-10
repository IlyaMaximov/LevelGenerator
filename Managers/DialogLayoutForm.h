#ifndef LEVELGENERATOR_DIALOGLAYOUTFORM_H
#define LEVELGENERATOR_DIALOGLAYOUTFORM_H

#include <iostream>
#include <cstdarg>
#include "../GeomObjects/MessangeBox.h"
#include "../GeomObjects/Button.h"

class DialogLayoutForm {
public:

    explicit DialogLayoutForm(sf::Vector2f size):
        size_(size) {

        if (!font_.loadFromFile("arial.ttf")) {
            throw std::runtime_error("It is not possible to load the font");
        }
    };

    using DialogRow = std::vector<WindowObj*>;

    sf::Vector2f getSize() const {
        return size_;
    }

    void addQuestion(std::string&& request_text, MessageBox* response) {
        auto request = new MessageBox(nullptr, MessageBoxType::NonEditable, std::move(request_text));
        dialog_rows_.push_back({request, response});
    }

    void addChoiceQuestion(std::string&& question_text, int n, ...) {
        auto request = new MessageBox(nullptr, MessageBoxType::NonEditable, std::move(question_text));
        dialog_rows_.push_back({request});
        va_list args_list;
        va_start(args_list, n);
        for (int i = 0; i < n; ++i) {
            dialog_rows_.back().push_back(va_arg(args_list, Button*));
        }
        va_end(args_list);
    }

    void addWidget(WindowObj* widget) {
        dialog_rows_.push_back({widget});
    }

private:
    sf::Vector2f size_;
    sf::Font font_;
    std::vector<DialogRow> dialog_rows_;
};


#endif //LEVELGENERATOR_DIALOGLAYOUTFORM_H
