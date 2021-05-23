#ifndef HF37ACE88_F726_4AA3_8599_ED7A888AA623
#define HF37ACE88_F726_4AA3_8599_ED7A888AA623

#include "easy_graph/eg.h"
#include "cmp_helper.h"
#include <string>

EG_NS_BEGIN

struct Node {
    explicit Node(const std::string& name);
    Node(const char* name);

    __DECL_COMP(Node);

    std::string getName() const;
    std::string getLayout() const;

private:
    std::string name;
};

EG_NS_END

#endif
