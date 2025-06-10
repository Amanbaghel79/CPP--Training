#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Interface
class interface {
public:
    virtual void add(interface*) = 0;
    virtual void show_details() = 0;
    virtual ~interface() {}
};

// Leaf
class file : public interface {
    string name;
public:
    file(string s) : name(s) {}
    void add(interface* ptr) override {
        // Leaf nodes do not add anything
    }
    void show_details() override {
        cout << "  - File name: " << name << endl;
    }
};

// Composite
class folder : public interface {
    string name;
    vector<interface*> vc;
public:
    folder(string s) : name(s) {}
    
    void add(interface* ptr) override {
        vc.push_back(ptr);
    }

    void show_details() override {
        cout << "+ Folder name: " << name << endl;
        for (auto it : vc) {
            it->show_details();
        }
    }

    ~folder() {
        for (auto it : vc) {
            delete it; // free memory
        }
    }
};

int main() {
    string s = "atxt";
    interface* a = new file(s);
    interface* b = new file(string("btxt"));
    interface* c = new file(string("ctxt"));

    folder* alpha = new folder("alpha");
    alpha->add(a);
    alpha->add(b);

    folder* desktop = new folder("desktop");
    desktop->add(alpha);
    desktop->add(c);

    desktop->show_details();

    delete desktop; // this will automatically delete all children
    return 0;
}
