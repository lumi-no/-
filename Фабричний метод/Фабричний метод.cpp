#include <iostream>
#include <memory>


class Button {
public:
    virtual void render() const = 0;
    virtual ~Button() = default;
};


class WindowsButton : public Button {
public:
    void render() const override {
        std::cout << "Rendering Windows Button" << std::endl;
    }
};


class MacOSButton : public Button {
public:
    void render() const override {
        std::cout << "Rendering macOS Button" << std::endl;
    }
};


class Dialog {
public:
    virtual std::shared_ptr<Button> createButton() const = 0; 
    virtual ~Dialog() = default;

    void renderDialog() const {
        auto button = createButton();
        button->render();
    }
};


class WindowsDialog : public Dialog {
public:
    std::shared_ptr<Button> createButton() const override {
        return std::make_shared<WindowsButton>();
    }
};


class MacOSDialog : public Dialog {
public:
    std::shared_ptr<Button> createButton() const override {
        return std::make_shared<MacOSButton>();
    }
};

int main() {
  
    std::shared_ptr<Dialog> dialog;

    std::string osType = "Windows"; 

    if (osType == "Windows") {
        dialog = std::make_shared<WindowsDialog>();
    }
    else if (osType == "MacOS") {
        dialog = std::make_shared<MacOSDialog>();
    }

    if (dialog) {
        dialog->renderDialog(); 
    }
    else {
        std::cout << "Unknown OS type!" << std::endl;
    }

    return 0;
}
