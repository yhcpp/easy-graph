#include "easy_graph/graph/node.h"
#include "easy_graph/graph/box.h"
#include "easy_graph/graph/graph_visitor.h"

EG_NS_BEGIN

Node::Node(const NodeId& id)
: id(id) {
}

Node::Node(const char* id)
: Node(NodeId(id)) {
}

Node::Node(const Box& box)
: id(box.getId()), box(&box) {
}

__DEF_EQUALS(Node)
{
	return id == rhs.id;
}

__DEF_COMP(Node)
{
	return id < rhs.id;
}

NodeId Node::getId() const {
	return id;
}

const Box* Node::getBox() const {
	return box;
}

bool Node::hasSubgraph() const {
	return !subgraphs.empty();
}

void Node::accept(GraphVisitor& visitor) const {
	std::for_each(subgraphs.begin(), subgraphs.end(),  [&visitor](auto graph){visitor.visit(*graph);});
}

EG_NS_END
